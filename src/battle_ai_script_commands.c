#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_ai_script_commands.h"
#include "battle_factory.h"
#include "battle_setup.h"
#include "boss_battles.h"
#include "data.h"
#include "event_data.h"
#include "item.h"
#include "pokemon.h"
#include "random.h"
#include "recorded_battle.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/battle_ai.h"
#include "constants/battle_move_effects.h"
#include "constants/boss_battles.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"

#include "data/probable_moves.h"

#define __DEBUG_AI__ DEBUG
#if __DEBUG_AI__
    #include "string_util.h"
    #include "menu.h"
#endif

#define AI_ACTION_DONE          0x0001
#define AI_ACTION_FLEE          0x0002
#define AI_ACTION_WATCH         0x0004
#define AI_ACTION_DO_NOT_ATTACK 0x0008
#define AI_ACTION_UNK5          0x0010
#define AI_ACTION_UNK6          0x0020
#define AI_ACTION_UNK7          0x0040
#define AI_ACTION_UNK8          0x0080

#define AI_THINKING_STRUCT ((struct AI_ThinkingStruct *)(gBattleResources->ai))
#define BATTLE_HISTORY ((struct BattleHistory *)(gBattleResources->battleHistory))
#define HISTORY_INDEX(opponentId) ((GetBattlerSide(opponentId) == B_SIDE_PLAYER ? 0 : PARTY_SIZE) + gBattlerPartyIndexes[opponentId])
#define FOES_MOVE_HISTORY(opponentId) (BATTLE_HISTORY->_usedMoves[HISTORY_INDEX(opponentId)].moves)
#define FOES_OBSERVED_ABILITY(opponentId) (BATTLE_HISTORY->_abilities[HISTORY_INDEX(opponentId)])
#define FOES_OBSERVED_ITEM_EFFECT(opponentId) (BATTLE_HISTORY->_itemEffects[HISTORY_INDEX(opponentId)])
#define AI_CAN_ESTIMATE_DAMAGE(move) (gBattleMoves[move].power > 1 || (gBattleMoves[move].power == 1 && gBattleMoves[move].effect != EFFECT_OHKO && move != MOVE_COUNTER && move != MOVE_MIRROR_COAT && move != MOVE_BIDE))
#define PROTECT_WONT_FAIL_FOR(battlerId) ((   gLastResultingMoves[battlerId] != MOVE_PROTECT \
                                           && gLastResultingMoves[battlerId] != MOVE_DETECT  \
                                           && gLastResultingMoves[battlerId] != MOVE_ENDURE) \
                                         || gDisableStructs[battlerId].protectUses == 0)
#define FIRST_IS_LEECH_SEEDING_SECOND(idfirst, idsecond) ((gStatuses3[idsecond] & STATUS3_LEECHSEED) && (gStatuses3[idsecond] & STATUS3_LEECHSEED_BATTLER) == idfirst)
#define NOT_EXPECTED_TO_SLEEP_DURING_NEXT_TURN(battlerId) (!(gBattleMons[battlerId].status1 & STATUS1_SLEEP) || (gBattleMons[battlerId].status1 & STATUS1_SLEEP) == 5)
#define EXPECTED_TO_SLEEP_DURING_NEXT_TURN(battlerId) (!NOT_EXPECTED_TO_SLEEP_DURING_NEXT_TURN(battlerId))

#define SWITCH_IF_THERE_IS_A_SUITABLE_MON(criterion) {                       \
    u8 bestMonFound = GetMostSuitableMonToSwitchInto(criterion);             \
    if (bestMonFound != PARTY_SIZE)                                          \
    {                                                                        \
        *(gBattleStruct->AI_monToSwitchIntoId + sBattler_AI) = bestMonFound; \
        return AI_CHOICE_SWITCH;                                             \
    }}

// AI states
enum
{
    AIState_SettingUp,
    AIState_Processing,
    AIState_FinishedProcessing,
    AIState_DoNotProcess
};

/*
gAIScriptPtr is a pointer to the next battle AI cmd command to read.
when a command finishes processing, gAIScriptPtr is incremented by
the number of bytes that the current command had reserved for arguments
in order to read the next command correctly. refer to battle_ai_scripts.s for the
AI scripts.
*/

extern const u8 *const gBattleAI_ScriptsTable[];

static u8 ChooseMoveOrAction_Singles(void);
static u8 ChooseMoveOrAction_Doubles(void);
static void BattleAI_DoAIProcessing(void);
static void AIStackPushVar(const u8 *);
static bool8 AIStackPop(void);

static void Cmd_if_random_less_than(void);
static void Cmd_if_random_greater_than(void);
static void Cmd_if_random_equal(void);
static void Cmd_if_random_not_equal(void);
static void Cmd_score(void);
static void Cmd_if_hp_less_than(void);
static void Cmd_if_hp_more_than(void);
static void Cmd_if_hp_equal(void);
static void Cmd_if_hp_not_equal(void);
static void Cmd_if_status(void);
static void Cmd_if_not_status(void);
static void Cmd_if_status2(void);
static void Cmd_if_not_status2(void);
static void Cmd_if_status3(void);
static void Cmd_if_not_status3(void);
static void Cmd_if_side_affecting(void);
static void Cmd_if_not_side_affecting(void);
static void Cmd_if_less_than(void);
static void Cmd_if_more_than(void);
static void Cmd_if_equal(void);
static void Cmd_if_not_equal(void);
static void Cmd_if_less_than_ptr(void);
static void Cmd_if_more_than_ptr(void);
static void Cmd_if_equal_ptr(void);
static void Cmd_if_not_equal_ptr(void);
static void Cmd_if_move(void);
static void Cmd_if_not_move(void);
static void Cmd_if_in_bytes(void);
static void Cmd_if_not_in_bytes(void);
static void Cmd_if_in_hwords(void);
static void Cmd_if_not_in_hwords(void);
static void Cmd_if_user_has_attacking_non_ineffective_move(void);
static void Cmd_if_user_has_no_attacking_non_ineffective_moves(void);
static void Cmd_get_turn_count(void);
static void Cmd_get_type(void);
static void Cmd_get_considered_move_power(void);
static void Cmd_get_how_powerful_move_is(void);
static void Cmd_get_last_used_battler_move(void);
static void Cmd_if_equal_(void);
static void Cmd_if_not_equal_(void);
static void Cmd_if_user_goes(void);
static void Cmd_if_user_doesnt_go(void);
static void Cmd_nullsub_2A(void);
static void Cmd_nullsub_2B(void);
static void Cmd_count_usable_party_mons(void);
static void Cmd_get_considered_move(void);
static void Cmd_get_considered_move_effect(void);
static void Cmd_get_ability(void);
static void Cmd_get_highest_type_effectiveness(void);
static void Cmd_if_type_effectiveness(void);
static void Cmd_nullsub_32(void);
static void Cmd_nullsub_33(void);
static void Cmd_if_status_in_party(void);
static void Cmd_if_status_not_in_party(void);
static void Cmd_get_weather(void);
static void Cmd_if_effect(void);
static void Cmd_if_not_effect(void);
static void Cmd_if_stat_level_less_than(void);
static void Cmd_if_stat_level_more_than(void);
static void Cmd_if_stat_level_equal(void);
static void Cmd_if_stat_level_not_equal(void);
static void Cmd_if_can_faint_with_threshold(void);
static void Cmd_if_cant_faint(void);
static void Cmd_if_has_move(void);
static void Cmd_if_doesnt_have_move(void);
static void Cmd_if_has_move_with_effect(void);
static void Cmd_if_doesnt_have_move_with_effect(void);
static void Cmd_if_any_move_disabled_or_encored(void);
static void Cmd_if_curr_move_disabled_or_encored(void);
static void Cmd_flee(void);
static void Cmd_if_random_safari_flee(void);
static void Cmd_watch(void);
static void Cmd_get_hold_effect(void);
static void Cmd_get_gender(void);
static void Cmd_is_first_turn_for(void);
static void Cmd_get_stockpile_count(void);
static void Cmd_is_double_battle(void);
static void Cmd_get_used_held_item(void);
static void Cmd_get_move_type_from_result(void);
static void Cmd_get_move_power_from_result(void);
static void Cmd_get_move_effect_from_result(void);
static void Cmd_get_protect_count(void);
static void Cmd_nullsub_52(void);
static void Cmd_nullsub_53(void);
static void Cmd_nullsub_54(void);
static void Cmd_nullsub_55(void);
static void Cmd_nullsub_56(void);
static void Cmd_nullsub_57(void);
static void Cmd_call(void);
static void Cmd_goto(void);
static void Cmd_end(void);
static void Cmd_if_level_cond(void);
static void Cmd_if_target_taunted(void);
static void Cmd_if_target_not_taunted(void);
static void Cmd_check_ability(void);
static void Cmd_if_type(void);
static void Cmd_if_target_is_ally(void);
static void Cmd_if_flash_fired(void);
static void Cmd_if_holds_item(void);
static void Cmd_get_hazards_count(void);
static void Cmd_get_curr_dmg_hp_percent(void);
static void Cmd_if_hp_condition(void);
static void Cmd_if_accuracy_less_than(void);
static void Cmd_if_not_expected_to_sleep(void);
static void Cmd_if_receiving_wish(void);
static void Cmd_if_target_wont_attack_due_to_truant(void);
static void Cmd_if_trick_fails_in_this_type_of_battle(void);
static void Cmd_calculate_nhko(void);
static void Cmd_if_next_turn_target_might_use_move_with_effect(void);
static void Cmd_if_battler_absent(void);
static void Cmd_get_possible_categories_of_foes_attacks(void);
static void Cmd_if_perish_song_not_about_to_trigger(void);
static void Cmd_if_high_change_to_break_sub_and_keep_hitting(void);
static void Cmd_if_user_has_revealed_move(void);
static void Cmd_if_has_non_ineffective_move_with_effect(void);
static void Cmd_if_doesnt_have_non_ineffective_move_with_effect(void);
static void Cmd_if_move_is_contactless(void);
static void Cmd_if_target_will_be_faster_after_this_effect(void);
static void Cmd_get_weather_at_the_end_of_turn(void);

// ewram
EWRAM_DATA const u8 *gAIScriptPtr = NULL;
EWRAM_DATA static u8 sBattler_AI = 0;

// const rom data
typedef void (*BattleAICmdFunc)(void);

static const BattleAICmdFunc sBattleAICmdTable[] =
{
    Cmd_if_random_less_than,                        // 0x0
    Cmd_if_random_greater_than,                     // 0x1
    Cmd_if_random_equal,                            // 0x2
    Cmd_if_random_not_equal,                        // 0x3
    Cmd_score,                                      // 0x4
    Cmd_if_hp_less_than,                            // 0x5
    Cmd_if_hp_more_than,                            // 0x6
    Cmd_if_hp_equal,                                // 0x7
    Cmd_if_hp_not_equal,                            // 0x8
    Cmd_if_status,                                  // 0x9
    Cmd_if_not_status,                              // 0xA
    Cmd_if_status2,                                 // 0xB
    Cmd_if_not_status2,                             // 0xC
    Cmd_if_status3,                                 // 0xD
    Cmd_if_not_status3,                             // 0xE
    Cmd_if_side_affecting,                          // 0xF
    Cmd_if_not_side_affecting,                      // 0x10
    Cmd_if_less_than,                               // 0x11
    Cmd_if_more_than,                               // 0x12
    Cmd_if_equal,                                   // 0x13
    Cmd_if_not_equal,                               // 0x14
    Cmd_if_less_than_ptr,                           // 0x15
    Cmd_if_more_than_ptr,                           // 0x16
    Cmd_if_equal_ptr,                               // 0x17
    Cmd_if_not_equal_ptr,                           // 0x18
    Cmd_if_move,                                    // 0x19
    Cmd_if_not_move,                                // 0x1A
    Cmd_if_in_bytes,                                // 0x1B
    Cmd_if_not_in_bytes,                            // 0x1C
    Cmd_if_in_hwords,                               // 0x1D
    Cmd_if_not_in_hwords,                           // 0x1E
    Cmd_if_user_has_attacking_non_ineffective_move, // 0x1F
    Cmd_if_user_has_no_attacking_non_ineffective_moves, // 0x20
    Cmd_get_turn_count,                             // 0x21
    Cmd_get_type,                                   // 0x22
    Cmd_get_considered_move_power,                  // 0x23
    Cmd_get_how_powerful_move_is,                   // 0x24
    Cmd_get_last_used_battler_move,                 // 0x25
    Cmd_if_equal_,                                  // 0x26
    Cmd_if_not_equal_,                              // 0x27
    Cmd_if_user_goes,                               // 0x28
    Cmd_if_user_doesnt_go,                          // 0x29
    Cmd_nullsub_2A,                                 // 0x2A
    Cmd_nullsub_2B,                                 // 0x2B
    Cmd_count_usable_party_mons,                    // 0x2C
    Cmd_get_considered_move,                        // 0x2D
    Cmd_get_considered_move_effect,                 // 0x2E
    Cmd_get_ability,                                // 0x2F
    Cmd_get_highest_type_effectiveness,             // 0x30
    Cmd_if_type_effectiveness,                      // 0x31
    Cmd_nullsub_32,                                 // 0x32
    Cmd_nullsub_33,                                 // 0x33
    Cmd_if_status_in_party,                         // 0x34
    Cmd_if_status_not_in_party,                     // 0x35
    Cmd_get_weather,                                // 0x36
    Cmd_if_effect,                                  // 0x37
    Cmd_if_not_effect,                              // 0x38
    Cmd_if_stat_level_less_than,                    // 0x39
    Cmd_if_stat_level_more_than,                    // 0x3A
    Cmd_if_stat_level_equal,                        // 0x3B
    Cmd_if_stat_level_not_equal,                    // 0x3C
    Cmd_if_can_faint_with_threshold,                // 0x3D
    Cmd_if_cant_faint,                              // 0x3E
    Cmd_if_has_move,                                // 0x3F
    Cmd_if_doesnt_have_move,                        // 0x40
    Cmd_if_has_move_with_effect,                    // 0x41
    Cmd_if_doesnt_have_move_with_effect,            // 0x42
    Cmd_if_any_move_disabled_or_encored,            // 0x43
    Cmd_if_curr_move_disabled_or_encored,           // 0x44
    Cmd_flee,                                       // 0x45
    Cmd_if_random_safari_flee,                      // 0x46
    Cmd_watch,                                      // 0x47
    Cmd_get_hold_effect,                            // 0x48
    Cmd_get_gender,                                 // 0x49
    Cmd_is_first_turn_for,                          // 0x4A
    Cmd_get_stockpile_count,                        // 0x4B
    Cmd_is_double_battle,                           // 0x4C
    Cmd_get_used_held_item,                         // 0x4D
    Cmd_get_move_type_from_result,                  // 0x4E
    Cmd_get_move_power_from_result,                 // 0x4F
    Cmd_get_move_effect_from_result,                // 0x50
    Cmd_get_protect_count,                          // 0x51
    Cmd_nullsub_52,                                 // 0x52
    Cmd_nullsub_53,                                 // 0x53
    Cmd_nullsub_54,                                 // 0x54
    Cmd_nullsub_55,                                 // 0x55
    Cmd_nullsub_56,                                 // 0x56
    Cmd_nullsub_57,                                 // 0x57
    Cmd_call,                                       // 0x58
    Cmd_goto,                                       // 0x59
    Cmd_end,                                        // 0x5A
    Cmd_if_level_cond,                              // 0x5B
    Cmd_if_target_taunted,                          // 0x5C
    Cmd_if_target_not_taunted,                      // 0x5D
    Cmd_if_target_is_ally,                          // 0x5E
    Cmd_if_type,                                    // 0x5F
    Cmd_check_ability,                              // 0x60
    Cmd_if_flash_fired,                             // 0x61
    Cmd_if_holds_item,                              // 0x62
    Cmd_get_hazards_count,                          // 0x63
    Cmd_get_curr_dmg_hp_percent,                    // 0x64
    Cmd_if_hp_condition,                            // 0x65
    Cmd_if_accuracy_less_than,                      // 0x66
    Cmd_if_not_expected_to_sleep,                   // 0x67
    Cmd_if_receiving_wish,                          // 0x68
    Cmd_if_target_wont_attack_due_to_truant,                // 0x69
    Cmd_if_trick_fails_in_this_type_of_battle,              // 0x6A
    Cmd_calculate_nhko,                                     // 0x6B
    Cmd_if_next_turn_target_might_use_move_with_effect,     // 0x6C
    Cmd_if_battler_absent,                                  // 0x6D
    Cmd_get_possible_categories_of_foes_attacks,            // 0x6E
    Cmd_if_perish_song_not_about_to_trigger,                // 0x6F
    Cmd_if_high_change_to_break_sub_and_keep_hitting,       // 0x70
    Cmd_if_user_has_revealed_move,                          // 0x71
    Cmd_if_has_non_ineffective_move_with_effect,            // 0x72
    Cmd_if_doesnt_have_non_ineffective_move_with_effect,    // 0x73
    Cmd_if_move_is_contactless,                             // 0x74
    Cmd_if_target_will_be_faster_after_this_effect,         // 0x75
    Cmd_get_weather_at_the_end_of_turn,                     // 0x76
};

static const u16 sDiscouragedPowerfulMoveEffects[] =
{
    EFFECT_EXPLOSION,
    EFFECT_DREAM_EATER,
    EFFECT_RAZOR_WIND,
    EFFECT_SKY_ATTACK,
    EFFECT_RECHARGE,
    EFFECT_SKULL_BASH,
    EFFECT_SOLARBEAM,
    EFFECT_SPIT_UP,
    EFFECT_SUPERPOWER,
    EFFECT_PRESENT,
    EFFECT_OVERHEAT,
    0xFFFF
};

static const u16 sDamagingMovesMostlyUnaffectedByStatDrops[] =
{
    MOVE_BIND,
	MOVE_WRAP,
	MOVE_WHIRLPOOL, 
	MOVE_FIRE_SPIN, 
	MOVE_CLAMP, 
	MOVE_ENDEAVOR, 
	MOVE_GUILLOTINE, 
	MOVE_FISSURE, 
	MOVE_SHEER_COLD, 
	MOVE_HORN_DRILL, 
	MOVE_COUNTER, 
	MOVE_MIRROR_COAT, 
	MOVE_SEISMIC_TOSS, 
	MOVE_NIGHT_SHADE, 
	MOVE_RAPID_SPIN, 
	MOVE_SONIC_BOOM, 
	MOVE_DRAGON_RAGE, 
	MOVE_BIDE,
	MOVE_PSYWAVE,
	MOVE_SUPER_FANG,
	MOVE_HOLA_REINA,
    0xFFFF
};

// code
void BattleAI_HandleItemUseBeforeAISetup(u8 defaultScoreMoves)
{
    s32 i;
    u8 *data = (u8 *)BATTLE_HISTORY;

    for (i = 0; i < sizeof(struct BattleHistory); i++)
        data[i] = 0;

    // Items are allowed to use in ONLY trainer battles.
    if ((gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        && !(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_SAFARI | BATTLE_TYPE_BATTLE_TOWER
                               | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_SECRET_BASE | BATTLE_TYPE_FRONTIER
                               | BATTLE_TYPE_INGAME_PARTNER | BATTLE_TYPE_x2000000)
            )
       )
    {
        for (i = 0; i < MAX_TRAINER_ITEMS; i++)
        {
            if (gTrainers[gTrainerBattleOpponent_A].items[i] != 0)
            {
                BATTLE_HISTORY->trainerItems[BATTLE_HISTORY->itemsNo] = gTrainers[gTrainerBattleOpponent_A].items[i];
                BATTLE_HISTORY->itemsNo++;
            }
        }
    }

    BattleAI_SetupAIData(defaultScoreMoves);
}

void BattleAI_SetupAIData(u8 defaultScoreMoves)
{
    s32 i;
    u8 *data = (u8 *)AI_THINKING_STRUCT;
    u8 moveLimitations;

    // Clear AI data.
    for (i = 0; i < sizeof(struct AI_ThinkingStruct); i++)
        data[i] = 0;

    // Conditional score reset, unlike Ruby.
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (defaultScoreMoves & 1)
            AI_THINKING_STRUCT->score[i] = 100;
        else
            AI_THINKING_STRUCT->score[i] = 0;

        defaultScoreMoves >>= 1;
    }

    sBattler_AI = gActiveBattler;
    moveLimitations = CheckMoveLimitations(sBattler_AI, 0, 0xFF);

    // Ignore moves that aren't possible to use.
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBitTable[i] & moveLimitations)
            AI_THINKING_STRUCT->score[i] = 0;

        AI_THINKING_STRUCT->simulatedRNG[i] = 100 - (Random() % 16);
    }

    gBattleResources->AI_ScriptsStack->size = 0;

    // Decide a random target battlerId in doubles.
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        gBattlerTarget = (Random() & BIT_FLANK) + (GetBattlerSide(sBattler_AI) ^ BIT_SIDE);
        if (gAbsentBattlerFlags & gBitTable[gBattlerTarget])
            gBattlerTarget ^= BIT_FLANK;
    }
    // There's only one choice in single battles.
    else
    {
        gBattlerTarget = sBattler_AI ^ BIT_SIDE;
    }

    // Choose proper trainer ai scripts.
    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        AI_THINKING_STRUCT->aiFlags = GetAiScriptsInRecordedBattle();
    else if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
        AI_THINKING_STRUCT->aiFlags = AI_SCRIPT_SAFARI;
    else if (gBattleTypeFlags & BATTLE_TYPE_ROAMER)
        AI_THINKING_STRUCT->aiFlags = AI_SCRIPT_ROAMING;
    else if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
        AI_THINKING_STRUCT->aiFlags = AI_SCRIPT_FIRST_BATTLE;
    else if (gBossBattleFlags & BATTLE_TYPE_TOTEM)
        AI_THINKING_STRUCT->aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_HP_AWARE;
    else if (gBattleTypeFlags & BATTLE_TYPE_FACTORY)
        AI_THINKING_STRUCT->aiFlags = GetAiScriptsInBattleFactory();
    else if (gBattleTypeFlags & (BATTLE_TYPE_FRONTIER | BATTLE_TYPE_EREADER_TRAINER | BATTLE_TYPE_TRAINER_HILL | BATTLE_TYPE_SECRET_BASE))
        AI_THINKING_STRUCT->aiFlags = AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_HP_AWARE;
    else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        AI_THINKING_STRUCT->aiFlags = gTrainers[gTrainerBattleOpponent_A].aiFlags | gTrainers[gTrainerBattleOpponent_B].aiFlags;
    else
       AI_THINKING_STRUCT->aiFlags = gTrainers[gTrainerBattleOpponent_A].aiFlags;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        AI_THINKING_STRUCT->aiFlags |= AI_SCRIPT_DOUBLE_BATTLE; // act smart in doubles and don't attack your partner
}

u8 BattleAI_ChooseMoveOrAction(void)
{
    u16 savedCurrentMove = gCurrentMove;
    u8 ret;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        ret = ChooseMoveOrAction_Singles();
    else
        ret = ChooseMoveOrAction_Doubles();

    gCurrentMove = savedCurrentMove;
    return ret;
}

bool32 IsTruantMonVulnerable(u32 battlerAI, u32 opposingBattler, bool8 opposingBattlerHasToAttackAfterSwitchin)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u32 move = FOES_MOVE_HISTORY(opposingBattler)[i];

        if (
            (
             (gBattleMons[opposingBattler].status2 & (STATUS2_RECHARGE | STATUS2_MULTIPLETURNS) && !(gStatuses3[opposingBattler] & STATUS3_SEMI_INVULNERABLE && gBattleMoves[move].effect == EFFECT_SEMI_INVULNERABLE)
             ) 
             || 
             (gDisableStructs[opposingBattler].encoreTimer && gDisableStructs[opposingBattler].encoredMove != move)
            )
            && !gDisableStructs[battlerAI].truantCounter
            && !opposingBattlerHasToAttackAfterSwitchin
           )
            continue; // si el rival está ocupado con otro movimiento y no toca holgazanear, no nos preocupa de momento que el rival tenga este movimiento

        switch(gBattleMoves[move].effect)
        {
            case EFFECT_SUBSTITUTE:
                if (gBattleMons[opposingBattler].hp <= gBattleMons[opposingBattler].maxHP / 4)
                    break; // si no tiene PS para meter sub, no nos preocupa

                if (GetWhoStrikesFirst(battlerAI, opposingBattler, TRUE) == 0
                    && !gDisableStructs[battlerAI].truantCounter
                    && !opposingBattlerHasToAttackAfterSwitchin
                   )
                    break; // si nos da tiempo a atacar antes de que ponga sub, no nos preocupa por el momento

                return TRUE;

            case EFFECT_PROTECT:
                if ((gLastResultingMoves[opposingBattler] == MOVE_PROTECT || gLastResultingMoves[opposingBattler] == MOVE_DETECT || gLastResultingMoves[opposingBattler] == MOVE_ENDURE)
                    && gDisableStructs[opposingBattler].protectUses >= 2
                    && !gDisableStructs[battlerAI].truantCounter
                    && !opposingBattlerHasToAttackAfterSwitchin)
                    break; // si el rival se protegió dos o más veces seguidas, se la juega a que la próxima probablemente falle

                return TRUE;

            case EFFECT_SEMI_INVULNERABLE:
                /*
                  Hay cuatro factores a tener en cuenta:
                   - A: Si el poke de la IA es más lento.
                   - B: Si el rival ya está en una etapa semiinvulnerable en este momento.
                   - C: Si en el próximo ataque toca holgazanear.
                   - D: Si el rival tendrá un turno más para atacar (por estar considerando un cambio).
                  
                  C y D no pueden darse a la vez.
                  
                  La lógica seguida es la siguiente:
                   - B, C, D falsos. En este caso, el poke con Truant será frenado si es más lento, pero podrá atacar si no.
                   - C, D falsos, B verdadero. Se le da la vuelta al anterior escenario si el rival está en una etapa semiinvulnerable: el poke con Truant podrá atacar (aguantando un golpe) si es más lento, pero será bloqueado si es más rápido.
                   - D falso, C verdadero: si B es falso, el rival puede aprovechar la ventaja que tiene para ponerse en el escenario que le interese (usando el movimiento de semiinvulnerabilidad si el poke de la IA es más lento, no usándolo ahora sino en el siguiente turno si es más rápido), mientras que si es verdadero es como el caso con B, C, D falsos.
                   - D verdadero (C falso), ...:
                       + B verdadero. Entonces al siguiente turno será como el caso con B, C, D falso.
                       + B falso. Si el rival no tira el mov de semiinvulnerabilidad en el cambio, entonces es como el escenario con B, C, D falso. Si lo hace, entonces es al revés. Haremos que la IA asuma que no lo hace: si sí lo hace y no conviene puede rectificar al siguiente turno (además la IA podrá escoger un poke que aguante bien el golpe si lo hay), pero si asume lo contrario y no lo hace puede ser menos cómodo rectificar.

                   El siguiente código recorre estos escenarios en orden inverso.
                */
                #define TRUANT_MON_IS_SLOWER (GetWhoStrikesFirst(battlerAI, opposingBattler, TRUE) == 1)
                if (opposingBattlerHasToAttackAfterSwitchin) // D
                { // Si D, entonces el poke con Truant corre peligro cuando es más lento
                    if (TRUANT_MON_IS_SLOWER)
                        return TRUE;
                }
                else if (gDisableStructs[battlerAI].truantCounter) // C
                { // Si C y no D, el poke con Truant corre peligro excepto si es más rápido y el rival está en una etapa semiinvulnerable
                    if (!(gStatuses3[opposingBattler] & STATUS3_SEMI_INVULNERABLE) || TRUANT_MON_IS_SLOWER)
                        return TRUE;
                }
                else if (gStatuses3[opposingBattler] & STATUS3_SEMI_INVULNERABLE) // B
                { // Si B, no C y no D, corre peligro si es más rápido
                    if (!TRUANT_MON_IS_SLOWER)
                        return TRUE;
                }
                else if (TRUANT_MON_IS_SLOWER) // A
                    return TRUE; // corre peligro si es más lento
                #undef TRUANT_MON_IS_SLOWER
                break;
        }
    }
    return FALSE;
}

// Determina si un cierto ataque se está viendo afectado por bajadas de stats ofensivos
bool8 IsMoveSignificantlyAffectedByStatDrops(u16 move)
{
    s32 i;
    u8 type = gBattleMoves[move].type;
    u8 power = gBattleMoves[move].power;

    if (move == MOVE_HIDDEN_POWER || move == MOVE_MONADO_POWER)
    {
        struct Pokemon *monAttacker;
        if (GetBattlerSide(sBattler_AI) == B_SIDE_PLAYER)
            monAttacker = &gPlayerParty[gBattlerPartyIndexes[sBattler_AI]];
        else
            monAttacker = &gEnemyParty[gBattlerPartyIndexes[sBattler_AI]];

        type = monAttacker->box.hpType;
    }
    else if (move == MOVE_WEATHER_BALL && WEATHER_HAS_EFFECT)
    {
        if (gBattleWeather & WEATHER_RAIN_ANY)
            type = TYPE_WATER;
        else if (gBattleWeather & WEATHER_SANDSTORM_ANY)
            type = TYPE_ROCK;
        else if (gBattleWeather & WEATHER_SUN_ANY)
            type = TYPE_FIRE;
        else if (gBattleWeather & WEATHER_HAIL_ANY)
            type = TYPE_ICE;
    }
    if (power == 0)
        return FALSE; // Mov de estado; en general no se ve afectado (hay excepciones como Nature Power, Metronome, Mirror Move...)
    for (i = 0; sDamagingMovesMostlyUnaffectedByStatDrops[i] != 0xFFFF; i++)
    {
        if (move == sDamagingMovesMostlyUnaffectedByStatDrops[i])
            return FALSE; // Aunque sea un mov de daño, no está entre los que se ven muy afectados
    }
    // Devuelve TRUE si tiene bajado el stat en la categoría del ataque
    return AreAttackingStatsLowered(IS_TYPE_PHYSICAL(type) ? 0 : 1);
}

// Determina si un cierto ataque se está viendo afectado por bajadas de Precisión
bool8 IsMoveSignificantlyAffectedByAccuracyDrops(u16 move)
{
    if (gBattleMoves[move].accuracy == 0 && move != MOVE_MIRROR_MOVE && move != MOVE_METRONOME && move != MOVE_SLEEP_TALK && move != MOVE_ASSIST)
        return FALSE;  // no le afecta la posible bajada en Precisión
    // Lock-On, Mind Reader
    if (gStatuses3[gBattlerTarget] & STATUS3_ALWAYS_HITS && gDisableStructs[gBattlerTarget].battlerWithSureHit == sBattler_AI)
        return FALSE;
    // No Guard
    if (gBattleMons[gBattlerTarget].ability == ABILITY_NO_GUARD || gBattleMons[sBattler_AI].ability == ABILITY_NO_GUARD)
        return FALSE;
    return IsAccuracyLowered(-3); // se considera bajada a partir de -3
}

bool8 sBattler_AIisLosingHPDueToWeather(bool8 ignoreLeftoversAndIngrain)
{
    return (WEATHER_HAS_EFFECT
            && (gWishFutureKnock.weatherDuration != 1 || (gBattleWeather & (WEATHER_RAIN_PERMANENT | WEATHER_SANDSTORM_PERMANENT | WEATHER_SUN_PERMANENT | WEATHER_HAIL_PERMANENT)))
            && gBattleMons[sBattler_AI].ability != ABILITY_OVERCOAT
            && (ignoreLeftoversAndIngrain || (
                      gBattleMons[sBattler_AI].item != ITEM_LEFTOVERS // Restos compensa el clima
                  && !(gStatuses3[sBattler_AI] & STATUS3_ROOTED)      // Arraigo ídem
                ))
            && (
                ( // la IA pierde PS por arena
                 (gBattleWeather & WEATHER_SANDSTORM_ANY)
                 && !IS_BATTLER_OF_TYPE(sBattler_AI, TYPE_GROUND)
                 && !IS_BATTLER_OF_TYPE(sBattler_AI, TYPE_ROCK)
                 && !IS_BATTLER_OF_TYPE(sBattler_AI, TYPE_STEEL)
                 && gBattleMons[sBattler_AI].ability != ABILITY_SAND_VEIL
                 && gBattleMons[sBattler_AI].ability != ABILITY_SAND_RUSH
                 && gBattleMons[sBattler_AI].ability != ABILITY_SAND_FORCE
                )
              ||
                ( // la IA pierde PS por granizo
                 (gBattleWeather & WEATHER_HAIL_ANY)
                 && !IS_BATTLER_OF_TYPE(sBattler_AI, TYPE_ICE)
                 && gBattleMons[sBattler_AI].ability != ABILITY_SNOW_CLOAK
                 && gBattleMons[sBattler_AI].ability != ABILITY_ICE_BODY
                 && gBattleMons[sBattler_AI].ability != ABILITY_SLUSH_RUSH
                )
               )
           );
}

void CalculategBattleMoveDamageFromgCurrentMove(u8 attackerId, u8 targetId, u8 simulatedRng)
{
    gDynamicBasePower = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gMoveResultFlags = 0;
    gCritMultiplier = 1;
    AI_CalcDmg(attackerId, targetId);

	if (gBattleMoveDamage != 0 && simulatedRng)
    {
        gBattleMoveDamage = gBattleMoveDamage * simulatedRng / 100;
        if (gBattleMoveDamage == 0)
            gBattleMoveDamage = 1; // Salvo inmunidad, el daño siempre es al menos 1
    }
}

s32 CalculateDamageFromMove(u8 attackerId, u8 targetId, u16 move, u8 simulatedRng)
{
    s32 savedgBattleMoveDamage = gBattleMoveDamage;
    u16 savedCurrentMove = gCurrentMove;
    s32 damage;

    gCurrentMove = move;
    CalculategBattleMoveDamageFromgCurrentMove(attackerId, targetId, simulatedRng);
    damage = gBattleMoveDamage;

    gCurrentMove = savedCurrentMove;
    gBattleMoveDamage = savedgBattleMoveDamage;

    return damage;
}

s32 CalculatenHKOFromgCurrentMove(u8 attackerId, u8 targetId, u8 simulatedRng, s32 best_nhko)
{
    s32 n;
    s32 divisor = 1, adder = 0;
    s32 targetHP = gBattleMons[targetId].hp;

    CalculategBattleMoveDamageFromgCurrentMove(attackerId, targetId, simulatedRng);

    // Si tiene sustituto, considera que tiene que bajar más PS.
    // Los PS que se añaden son el daño que provoca por el número de golpes
    // necesarios para eliminar el sustituto; de forma que tras ese número
    // de golpes queden los PS actuales del poke
    if (gBattleMoveDamage > 0 && (gBattleMons[targetId].status2 & STATUS2_SUBSTITUTE) && gDisableStructs[targetId].substituteHP > 0)
        targetHP += gBattleMoveDamage*(1 + (gDisableStructs[targetId].substituteHP-1)/gBattleMoveDamage);

    // Multiplica por 2 si es un mov de dos turnos, y resta un turno si está ejecutándose
    switch (gBattleMoves[gCurrentMove].effect) {
        case EFFECT_SOLARBEAM:
            if (WEATHER_HAS_EFFECT && (gBattleWeather & WEATHER_SUN_ANY)) break;
        case EFFECT_RAZOR_WIND:
        case EFFECT_SKY_ATTACK:
        case EFFECT_SKULL_BASH:
        case EFFECT_SEMI_INVULNERABLE:
            divisor = 2;
            if ((gBattleMons[attackerId].status2 & STATUS2_MULTIPLETURNS) && gCurrentMove == gLastMoves[attackerId])
                adder = 1;
    }

    for (n = 1; n < best_nhko; n++)
        if (targetHP <= ((n+adder)/divisor) * gBattleMoveDamage)
            return n;

    return best_nhko;
}

// Asume que el poke de la IA es un Shedinja
bool32 OurShedinjaIsVulnerable(u32 battlerAI, u32 opposingBattler, u16 consideredMove)
{
    s32 i, j, known_moves = 0;
    const u8 moveLimitations = CheckMoveLimitations(opposingBattler, 0, MOVE_LIMITATION_CHOICE-1);
    const u16 savedCurrentMove = gCurrentMove;
    s8 priorityNeededToAttackShedinja = -10; // Se ignoran movimientos con prioridad menor que esta porque Shedinja hará KO antes

    // Si Shedinja elige protegerse, no hace falta huir,
    // excepto si el rival puede meter clima o si está confuso (que se comprueba a continuación)
    bool8 shedinjaIsSafeUnlessWeather = gBattleMoves[consideredMove].effect == EFFECT_PROTECT && PROTECT_WONT_FAIL_FOR(battlerAI);

    // Si Shedinja está confuso, claramente corre peligro: puede atacarse a sí mismo
    if (gBattleMons[battlerAI].status2 & STATUS2_CONFUSION)
        return TRUE;

    // Si Shedinja hace KO con el ataque elegido antes de que ataque el rival, no hace falta huir
    if (AI_CAN_ESTIMATE_DAMAGE(consideredMove) && !(gStatuses3[opposingBattler] & STATUS3_SEMI_INVULNERABLE))
    {
        bool8 canKO;
      
        gCurrentMove = consideredMove;
        canKO = CalculatenHKOFromgCurrentMove(battlerAI, opposingBattler, 85, 5) == 1;
        gCurrentMove = savedCurrentMove;
        if (canKO)
            priorityNeededToAttackShedinja = gBattleMoves[consideredMove].priority + ((GetWhoStrikesFirst(battlerAI, opposingBattler, TRUE) == 0) ? 1 : 0);
    }

    // Si Shedinja tiene un sustituto de alguna forma, no hace falta huir, excepto si el rival puede meter clima
    if (!shedinjaIsSafeUnlessWeather && (gBattleMons[battlerAI].status2 & STATUS2_SUBSTITUTE) && gDisableStructs[gBattlerTarget].substituteHP)
        shedinjaIsSafeUnlessWeather = TRUE;

   if (priorityNeededToAttackShedinja > 0 && shedinjaIsSafeUnlessWeather)
      return FALSE; // tiene sub y el rival no tendrá tiempo ni de poner clima

    // Si el oponente va a escoger Struggle, Shedinja tiene que huir, pues será dañado
    if (moveLimitations == 0xF && priorityNeededToAttackShedinja <= 0 && !shedinjaIsSafeUnlessWeather)
        return TRUE;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        gCurrentMove = FOES_MOVE_HISTORY(opposingBattler)[i];

        if (!gCurrentMove)
            continue;

        known_moves += 1;

        if (gBattleMoves[gCurrentMove].priority < priorityNeededToAttackShedinja)
            continue; // Nos da igual el movimiento si Shedinja hace OHKO antes

        // Comprueba que puede usar el movimiento
        for (j = 0; j < MAX_MON_MOVES; j++)
            if (gCurrentMove == gBattleMons[opposingBattler].moves[j] && !(gBitTable[j] & moveLimitations))
                break;
        if (j == MAX_MON_MOVES)
            continue; // No puede usar el movimiento por el momento; se ignora

        if ((gBattleMons[opposingBattler].status2 & STATUS2_MULTIPLETURNS) && gCurrentMove != gLastMoves[opposingBattler])
            continue; // Está en un ataque multiturno distinto de este; se ignora

        // Si le hace daño a Shedinja, hora de huir
        if (AI_CAN_ESTIMATE_DAMAGE(gCurrentMove) && !shedinjaIsSafeUnlessWeather)
        {
            CalculategBattleMoveDamageFromgCurrentMove(opposingBattler, battlerAI, 0);
            if (gBattleMoveDamage > 0)
            {
                gCurrentMove = savedCurrentMove;
                return TRUE;
            }
        }
			
        // Movimientos con los siguientes efectos también requieren huir
        switch (gBattleMoves[gCurrentMove].effect)
        {
            case EFFECT_TOXIC:
            case EFFECT_POISON:
            case EFFECT_WILL_O_WISP:
                if ((gBattleMons[battlerAI].status1 & STATUS1_PARALYSIS) || ((gBattleMons[battlerAI].status1 & (STATUS1_SLEEP | STATUS1_FREEZE)) && (gBattleMoves[consideredMove].priority < 0 || (gBattleMoves[consideredMove].priority == 0 && GetWhoStrikesFirst(battlerAI, opposingBattler, TRUE) != 0))))
                    break; // Le da igual recibir status si está paralizado o durmiendo (o congelado, por si lo está por alguna razón loca). En el caso de dormir, si Shedinja ataca antes y despierta no estará durmiendo
                goto _SKIP_CONFUSE_MOVES;
            case EFFECT_CONFUSE:
            case EFFECT_TEETER_DANCE:
            case EFFECT_SWAGGER:
            case EFFECT_FLATTER:
                if (priorityNeededToAttackShedinja > 0)
                    break; // si Shedinja es más rápido, le da igual que lo confundan, ya huirá en el siguiente turno si eso
            _SKIP_CONFUSE_MOVES:
            case EFFECT_LEECH_SEED:
                if (shedinjaIsSafeUnlessWeather)
                    break; // Shedinja se protege de los anteriores si tira Protect o tiene sub, pero no de lo siguiente:
            case EFFECT_SANDSTORM:
            case EFFECT_HAIL:
                gCurrentMove = savedCurrentMove;
                return TRUE;
        }
    }

    gCurrentMove = savedCurrentMove;

    if (known_moves < 4 && priorityNeededToAttackShedinja <= 0 && !shedinjaIsSafeUnlessWeather)
    {
        u8 opponent_types[2] = {gBattleMons[opposingBattler].type1, gBattleMons[opposingBattler].type2};
        if (gBattleMons[battlerAI].ability != ABILITY_WONDER_GUARD)
            return TRUE; // probablemente pueda atacar a Shedinja con cualquier cosa

        // Comprueba si alguno de los STAB del rival es muy eficaz. Asume que no le ha cambiado el tipo a Shedinja
        for (i = 0; i < 2; i++)
            switch (opponent_types[i])
            {
                case TYPE_FIRE:
                case TYPE_FLYING:
                case TYPE_ROCK:
                case TYPE_GHOST:
                case TYPE_DARK:
                    return TRUE;
            }
    }

    return FALSE;
}

bool8 AICanSwitchAssumingEnoughPokemon(void)
{
    return !(ABILITY_ON_OPPOSING_FIELD(sBattler_AI, ABILITY_SHADOW_TAG) && (!IS_BATTLER_OF_TYPE(sBattler_AI, TYPE_GHOST) && gBattleMons[sBattler_AI].ability != ABILITY_SHADOW_TAG))
            && !(ABILITY_ON_OPPOSING_FIELD(sBattler_AI, ABILITY_ARENA_TRAP) && (!IS_BATTLER_OF_TYPE(sBattler_AI, TYPE_FLYING) && !IS_BATTLER_OF_TYPE(sBattler_AI, TYPE_GHOST) && gBattleMons[sBattler_AI].ability != ABILITY_LEVITATE))
            && !(AbilityBattleEffects(ABILITYEFFECT_CHECK_FIELD_EXCEPT_BATTLER, sBattler_AI, ABILITY_MAGNET_PULL, 0, 0) && IS_BATTLER_OF_TYPE(sBattler_AI, TYPE_STEEL))
            && !(gBattleMons[sBattler_AI].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION) && !IS_BATTLER_OF_TYPE(sBattler_AI, TYPE_GHOST))
            && !(gStatuses3[sBattler_AI] & STATUS3_ROOTED && !IS_BATTLER_OF_TYPE(sBattler_AI, TYPE_GHOST))
            && !(gBattleTypeFlags & (BATTLE_TYPE_ARENA | BATTLE_TYPE_PALACE))
            && FlagGet(FLAG_RYU_RANDOMBATTLECCMETRO) != 1;
}

bool8 gBattlerTargetKnowsMoveWithEffect(u8 effect)
{
    s32 i;
    u8 moveLimitations = CheckMoveLimitations(gBattlerTarget, 0, MOVE_LIMITATION_PP);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (FOES_MOVE_HISTORY(gBattlerTarget)[i] && gBattleMoves[FOES_MOVE_HISTORY(gBattlerTarget)[i]].effect == effect)
        {
            s32 j;
            for (j = 0; j < MAX_MON_MOVES; j++)
                if (FOES_MOVE_HISTORY(gBattlerTarget)[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
                    break;
            if (j != MAX_MON_MOVES)
                break;
        }
    }
    return i != MAX_MON_MOVES;
}

// Mejor que usar la función de arriba 6 veces
bool8 gBattlerTargetKnows50HPRecoveryMove()
{
    s32 i, j;
    u8 moveLimitations = CheckMoveLimitations(gBattlerTarget, 0, MOVE_LIMITATION_PP);
    for (i = 0; i < MAX_MON_MOVES; i++)
        if (FOES_MOVE_HISTORY(gBattlerTarget)[i])
            switch(gBattleMoves[FOES_MOVE_HISTORY(gBattlerTarget)[i]].effect)
            {
                case EFFECT_RESTORE_HP:
                case EFFECT_SOFTBOILED:
                case EFFECT_MORNING_SUN:
                case EFFECT_MOONLIGHT:
                case EFFECT_SHORE_UP:
                case EFFECT_SYNTHESIS:
                    for (j = 0; j < MAX_MON_MOVES; j++)
                        if (FOES_MOVE_HISTORY(gBattlerTarget)[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
                            return TRUE;
            }
    return FALSE;
}

#define STORED_AI_MEMORY (BATTLE_HISTORY->switchMemory[sBattler_AI & BIT_SIDE])
static u8 ChooseMoveOrAction_Singles(void)
{
    u8 currentMoveArray[MAX_MON_MOVES];
    u8 consideredMoveArray[MAX_MON_MOVES];
    u8 numOfBestMoves;
    s32 i;
	u32 flags = AI_THINKING_STRUCT->aiFlags;

    struct AI_MemoryStruct memory = STORED_AI_MEMORY;
    ((u8*) &STORED_AI_MEMORY)[0] = 0; // se reinicia por si se decide cambiar

    RecordLastUsedMoveByTarget();

    while (flags != 0)
    {
        if (flags & 1)
        {
            AI_THINKING_STRUCT->aiState = AIState_SettingUp;
            BattleAI_DoAIProcessing();
        }
        flags >>= 1;
        AI_THINKING_STRUCT->aiLogicId++;
        AI_THINKING_STRUCT->movesetIndex = 0;
    }

    // Check special AI actions.
    if (AI_THINKING_STRUCT->aiAction & AI_ACTION_FLEE)
        return AI_CHOICE_FLEE;
    if (AI_THINKING_STRUCT->aiAction & AI_ACTION_WATCH)
        return AI_CHOICE_WATCH;
	
#if __DEBUG_AI__
    {
        int k;
        for (k = 0; k < 4; k++) {
            u8 numerico[6+4] = {EXT_CTRL_CODE_BEGIN, EXT_CTRL_CODE_COLOR, TEXT_COLOR_GREEN, EXT_CTRL_CODE_BEGIN, EXT_CTRL_CODE_SHADOW, TEXT_COLOR_LIGHT_GREEN};
            ConvertIntToDecimalStringN(numerico+6, AI_THINKING_STRUCT->score[k], STR_CONV_MODE_RIGHT_ALIGN, 3);
            AddTextPrinterParameterized(1, 0, numerico, 49 + 16*k, 18, 0, NULL);
        }
    }
#endif

        // Consider switching if your mon with truant is bodied by Protect spam.
        // Or can be exploited by semi invulnerable moves (such as Fly).
        // Or its ability is actually not Truant.
		if (gBattleMons[sBattler_AI].ability == ABILITY_TRUANT
            && (IsTruantMonVulnerable(sBattler_AI, gBattlerTarget, FALSE)
                || (GetAbilityBySpecies(gBattleMons[sBattler_AI].species, gBattleMons[sBattler_AI].abilityNum) != ABILITY_TRUANT
                  && gDisableStructs[sBattler_AI].truantCounter
                   )
               )
			&& AICanSwitchAssumingEnoughPokemon())
            SWITCH_IF_THERE_IS_A_SUITABLE_MON(gDisableStructs[sBattler_AI].truantCounter ? NOT_CHANGING_IS_UNACCEPTABLE : NOT_CHANGING_IS_ACCEPTABLE);


// Consider switching if all moves are worthless to use.
    if (AI_THINKING_STRUCT->aiFlags & (AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_PREFER_BATON_PASS)
        && !(
             // no cambia si tiene Evasión a +6 o el rival no puede hacerle nada
             // y el rival está intoxicado o maldito
             ((gBattleMons[gBattlerTarget].status1 & STATUS1_TOXIC_POISON) || (gBattleMons[gBattlerTarget].status2 & STATUS2_CURSED))
          && (gBattleMons[sBattler_AI].statStages[STAT_EVASION] == 12 || CalculateNHKO(gBattlerTarget, sBattler_AI, FALSE, MOVE_NONE, TRUE, FALSE) >= 5)
            )
        && !(
             // Tampoco cambia si el rival está atrapado y afectado por Perish Song (y no está a punto de saltar)
             // o atrapado y puede agotar sus PP
             (((gStatuses3[gBattlerTarget] & STATUS3_PERISH_SONG)
                && gDisableStructs[gBattlerTarget].perishSongTimer != 0)
              || gBattleMons[sBattler_AI].item == ITEM_LEPPA_BERRY)
          && (gBattleMons[gBattlerTarget].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
            )
		&& AICanSwitchAssumingEnoughPokemon())
    {
        s32 cap = AI_THINKING_STRUCT->aiFlags & (AI_SCRIPT_CHECK_VIABILITY) ? 95 : 93;
        s32 i_2;
        bool8 notChangingIsAcceptable = TRUE;
	if (gBattleMons[sBattler_AI].hp < gBattleMons[sBattler_AI].maxHP / 2 && (Random() & 1))
           cap -= 3;
		for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (AI_THINKING_STRUCT->score[i] > cap && gBattleMons[sBattler_AI].moves[i] != MOVE_SLEEP_TALK)
                break;
        }
        for (i_2 = 0; i_2 < MAX_MON_MOVES; i_2++)
            if (AI_THINKING_STRUCT->score[i_2] > cap - 2 && gBattleMons[sBattler_AI].moves[i_2] != MOVE_SLEEP_TALK)
                break;

        if (i_2 == MAX_MON_MOVES)
            notChangingIsAcceptable = FALSE;

        if (i == MAX_MON_MOVES)
            SWITCH_IF_THERE_IS_A_SUITABLE_MON(notChangingIsAcceptable ? NOT_CHANGING_IS_ACCEPTABLE : NOT_CHANGING_IS_UNACCEPTABLE);
    }

    numOfBestMoves = 1;
    currentMoveArray[0] = AI_THINKING_STRUCT->score[0];
    consideredMoveArray[0] = 0;

    for (i = 1; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[sBattler_AI].moves[i] != MOVE_NONE)
        {
            // In ruby, the order of these if statements is reversed.
            if (currentMoveArray[0] == AI_THINKING_STRUCT->score[i])
            {
                currentMoveArray[numOfBestMoves] = AI_THINKING_STRUCT->score[i];
                consideredMoveArray[numOfBestMoves++] = i;
            }
            if (currentMoveArray[0] < AI_THINKING_STRUCT->score[i])
            {
                numOfBestMoves = 1;
                currentMoveArray[0] = AI_THINKING_STRUCT->score[i];
                consideredMoveArray[0] = i;
            }
        }
    }
    {
        // Escoge cambiar si ha elegido un mov de daño directo de un stat bajado
        u8 chosenMovePos;
		u16 move;
        chosenMovePos = consideredMoveArray[Random() % numOfBestMoves];
        move = gBattleMons[sBattler_AI].moves[chosenMovePos];
        if (IsMoveSignificantlyAffectedByStatDrops(move)
			&& currentMoveArray[0] <= 101 // no cambia si el movimiento alcanza los 102 puntos (probable KO)
			&& AICanSwitchAssumingEnoughPokemon())
            SWITCH_IF_THERE_IS_A_SUITABLE_MON(NOT_CHANGING_IS_UNACCEPTABLE);

	if (IsMoveSignificantlyAffectedByAccuracyDrops(move)
            && currentMoveArray[0] <= 101 // no cambia si el movimiento alcanza los 102 puntos (probable KO con precisión suficiente)
            && AICanSwitchAssumingEnoughPokemon())
            SWITCH_IF_THERE_IS_A_SUITABLE_MON(NOT_CHANGING_IS_UNACCEPTABLE);

		// Si nuestro Shedinja es vulnerable, a salir por patas
        if (gBattleMons[sBattler_AI].species == SPECIES_SHEDINJA
            && OurShedinjaIsVulnerable(sBattler_AI, gBattlerTarget, move)
            && AICanSwitchAssumingEnoughPokemon())
            SWITCH_IF_THERE_IS_A_SUITABLE_MON(NOT_CHANGING_IS_UNACCEPTABLE);

		// Considera cambiar si corre peligro ante el rival y hay opciones mejores por ahí
        if (!(
              // no cambia si tiene Evasión alta y el rival está intoxicado o maldito,
              // o si tiene un sustituto o es FEAR,
              // o va a protegerse o usar Endure (y no tiene status que quite PS o entorpezca actuar)
              gBattleMons[sBattler_AI].statStages[STAT_EVASION]
                       >= 9    // +3 o más, +2 si el rival está enamorado o confuso, +1 si ambas
                       - (gBattleMons[gBattlerTarget].status2 & STATUS2_CONFUSION ? 1 : 0)
                       - (gBattleMons[gBattlerTarget].status2 & STATUS2_INFATUATION ? 1 : 0)
           && ((gBattleMons[gBattlerTarget].status1 & STATUS1_TOXIC_POISON) || (gBattleMons[gBattlerTarget].status2 & STATUS2_CURSED))
             )
            && !(gBattleMons[sBattler_AI].status2 & STATUS2_SUBSTITUTE)
            && !(
                 (gBattleMoves[move].effect == EFFECT_PROTECT
                  || (gBattleMoves[move].effect == EFFECT_ENDURE && !(gBattleMons[sBattler_AI].status1 & (STATUS1_PSN_ANY | STATUS1_BURN)))
                 )
                 && PROTECT_WONT_FAIL_FOR(sBattler_AI) // si ya lo usó el turno anterior, mejor pensar en cambiar
                 && !(gBattleMons[sBattler_AI].status1 & (STATUS1_TOXIC_POISON | STATUS1_PARALYSIS | STATUS1_FREEZE))
                 && !(gBattleMons[sBattler_AI].status2 & (STATUS2_CURSED | STATUS2_INFATUATION | STATUS2_CONFUSION))
                 && !(gStatuses3[sBattler_AI] & STATUS3_LEECHSEED)
                )
            && !(gBattleMons[sBattler_AI].level <= 2) // probable FEAR
            && AICanSwitchAssumingEnoughPokemon())
        {
            bool8 directDamageAttack = gBattleMoves[move].power > 0;
            bool8 ignoreFocusPunch = directDamageAttack && 
                   (gBattleMoves[move].accuracy == 0
                    || (gBattleMoves[move].accuracy >= 80 && ((gBattleMons[sBattler_AI].ability == ABILITY_KEEN_EYE 
					|| gBattleMons[gBattlerTarget].statStages[STAT_EVASION] < 9) && gBattleMons[sBattler_AI].statStages[STAT_ACC] > 4))
                    || (WEATHER_HAS_EFFECT && (((gBattleWeather & WEATHER_RAIN_ANY) && gBattleMoves[move].effect == EFFECT_THUNDER) || ((gBattleWeather & WEATHER_HAIL_ANY) && move == MOVE_BLIZZARD)))
                   );
            u8 nhko_taken = CalculateNHKO(gBattlerTarget, sBattler_AI, FALSE, MOVE_NONE, FALSE, ignoreFocusPunch);
            bool8 ai_is_faster = gBattleMoves[move].effect == EFFECT_QUICK_ATTACK || gBattleMoves[move].effect == EFFECT_MIDELE_POWER // se excluye Fake Out porque solo puede usarse un turno
              || (GetWhoStrikesFirst(sBattler_AI, gBattlerTarget, TRUE) == 0
                  && !(nhko_taken == 1 && gBattleMoves[move].priority < 0)); // sí, Focus Punch tiene -3
            u8 attacks_until_ko = nhko_taken - (ai_is_faster ? 0 : 1);

            if ((gStatuses3[sBattler_AI] & STATUS3_PERISH_SONG) && gDisableStructs[sBattler_AI].perishSongTimer + 1 < attacks_until_ko)
                attacks_until_ko = 1 + gDisableStructs[sBattler_AI].perishSongTimer;

            if (gBattleMons[sBattler_AI].ability == ABILITY_TRUANT)
                attacks_until_ko = (attacks_until_ko + (gDisableStructs[sBattler_AI].truantCounter ? 0 : 1))/2;

            if (attacks_until_ko > 1 && gBattleMoves[move].effect == EFFECT_EXPLOSION)
                attacks_until_ko = 1;

            if (attacks_until_ko > 1 && (gStatuses3[sBattler_AI] & STATUS3_YAWN))
                attacks_until_ko -= 1; // probablemente más

            if (
                 (attacks_until_ko == 0 && move != MOVE_FAKE_OUT) // Si recibe OHKO y es más lento, considera cambiar
              || (attacks_until_ko <= 2
                  // También cambia si escoge un ataque que hace poco daño o que tiene
                  // pocos puntos y va a ser el último o penúltimo que le dé tiempo a ejecutar
                  // (si es último, poco daño es peor que 2HKO y pocos puntos es menos de 99;
                  //  si es penúltimo, poco daño es peor que 4HKO (que 3HKO si está paralizado,
                  //   congelado, durmiendo, intoxicado, confuso, maldito o enamorado, o si el rival
                  //   tiene menos de 2/3 de los PS, puede curarse o nos usa Leech Seed)
                  //  y pocos puntos es menos de 97)
                  && !(move == MOVE_FAKE_OUT && currentMoveArray[0] > 101) // si es Fake Out y hará retroceder o es KO, la IA lo usa sin problemas
                  && (
                        move == MOVE_SLEEP_TALK
                     || currentMoveArray[0] <= 100 - 2*attacks_until_ko
                     ||
                       (directDamageAttack && AI_CAN_ESTIMATE_DAMAGE(move)
                        && CalculateNHKO(sBattler_AI, gBattlerTarget, TRUE, move, FALSE, FALSE) >= 2*attacks_until_ko + ((attacks_until_ko == 2 && (gBattleMons[gBattlerTarget].hp * 3 < 2 * gBattleMons[gBattlerTarget].maxHP || FIRST_IS_LEECH_SEEDING_SECOND(gBattlerTarget, sBattler_AI) || EXPECTED_TO_SLEEP_DURING_NEXT_TURN(sBattler_AI) || gBattleMons[sBattler_AI].status1 & (STATUS1_TOXIC_POISON | STATUS1_FREEZE | STATUS1_PARALYSIS) || gBattleMons[sBattler_AI].status2 & (STATUS2_CONFUSION | STATUS2_INFATUATION | STATUS2_CURSED) || gBattlerTargetKnows50HPRecoveryMove() || gBattlerTargetKnowsMoveWithEffect(EFFECT_REST))) ? 0 : 1)
                       )
                     )
                 )
              || (nhko_taken == 1                                        // También cambia si recibe OHKO
                  && move == MOVE_SUBSTITUTE                             // y va a tirar sub por segunda vez
                  && gLastResultingMoves[sBattler_AI] == MOVE_SUBSTITUTE // (para evitar spamearlo)
                  && gBattleMons[sBattler_AI].item != ITEM_LIECHI_BERRY  // y no tiene una pinch berry
                  && gBattleMons[sBattler_AI].item != ITEM_PETAYA_BERRY
                  && gBattleMons[sBattler_AI].item != ITEM_SALAC_BERRY
                  && !(gBattleMons[gBattlerTarget].status1 & STATUS1_TOXIC_POISON) // y el rival no palma PS
                  && !(gBattleMons[gBattlerTarget].status2 & STATUS2_CURSED)
                  && !(   // ni el poke de la IA se está recuperando con Leech Seed al rival junto con Restos
                          FIRST_IS_LEECH_SEEDING_SECOND(sBattler_AI, gBattlerTarget)
                       && gBattleMons[sBattler_AI].item == ITEM_LEFTOVERS)
                      )
               )
                SWITCH_IF_THERE_IS_A_SUITABLE_MON(NOT_CHANGING_IS_ACCEPTABLE);
        }
        // El poke lleva muchos turnos intoxicado, mejor cambiar
        #define _AI_CURRENT_TOXIC_TURNS_ ((gBattleMons[sBattler_AI].status1 & 0xF00) >> 8)
        if (gBattleMons[sBattler_AI].status1 & STATUS1_TOXIC_POISON
            && (
                _AI_CURRENT_TOXIC_TURNS_ >= 4 // lleva al menos 4 turnos de daño y por tanto va a perder más de un 25% (al menos un 31,25%) de sus PS
                || (_AI_CURRENT_TOXIC_TURNS_ == 3 // 3 turnos de daño también es mucho en los siguientes supuestos
                    && (
                           (gBattleMons[sBattler_AI].status2 & STATUS2_CURSED) // estar maldito
                        || (gStatuses3[sBattler_AI] & STATUS3_LEECHSEED)       // tener Leech Seed
                        || sBattler_AIisLosingHPDueToWeather(FALSE)            // ser dañado por clima y no tener Restos
                        || ((gBattleMons[sBattler_AI].item != ITEM_LEFTOVERS || sBattler_AIisLosingHPDueToWeather(TRUE)) && (Random()%2)) // o, en caso de no tener Restos o ser dañado por clima pero sí tener Restos, un 50% de cambiar
                       )
                   )
               )
            && (currentMoveArray[0] <= 101 // y no escoge un movimiento que alcance los 102 puntos (probable KO)
             // Los siguientes movimientos casi nunca tiene sentido usarlos
             // estando intoxicado en un estado avanzado
             || gBattleMoves[move].effect == EFFECT_RESTORE_HP
             || gBattleMoves[move].effect == EFFECT_SOFTBOILED
             || gBattleMoves[move].effect == EFFECT_MOONLIGHT
             || gBattleMoves[move].effect == EFFECT_MORNING_SUN
             || gBattleMoves[move].effect == EFFECT_SYNTHESIS
             || gBattleMoves[move].effect == EFFECT_SHORE_UP
               )
            && AICanSwitchAssumingEnoughPokemon())
            {
                bool8 convenient_move = FALSE; // TRUE si en el mov hace que no sea relevante el estar intoxicado
                switch (gBattleMoves[move].effect) {
                    case EFFECT_REFRESH:
                    case EFFECT_HEAL_BELL:
                    case EFFECT_REST:
                    case EFFECT_EXPLOSION:
                    case EFFECT_DESTINY_BOND:
                    case EFFECT_GRUDGE:
                    case EFFECT_MEMENTO:
                    case EFFECT_BATON_PASS:
                        convenient_move = TRUE;
                }
             if (!convenient_move)
                SWITCH_IF_THERE_IS_A_SUITABLE_MON(NOT_CHANGING_IS_UNACCEPTABLE);
            }

        // Si toca esperar un turno por Truant y cuando pueda atacar no espera hacer OHKO,
        // la IA mira si puede hacer un buen cambio en lugar de atacar
        if (gBattleMons[sBattler_AI].ability == ABILITY_TRUANT
            && gDisableStructs[sBattler_AI].truantCounter
            && (currentMoveArray[0] < 103 || gBattleMons[gBattlerTarget].status2 & STATUS2_SUBSTITUTE) // el movimiento elegido no es muy bueno o el rival tiene un sustituto
            && !( // no tiene Evasión subida vs un rival intoxicado o maldito
                 gBattleMons[sBattler_AI].statStages[STAT_EVASION] >= 10 // +4 o más
                 && ((gBattleMons[gBattlerTarget].status1 & STATUS1_TOXIC_POISON) || (gBattleMons[gBattlerTarget].status2 & STATUS2_CURSED))
                )
            && !( // no pasa a la vez: tener sub, que el rival esté recargando (Hyper Beam...) y ser más rápido
                 (gBattleMons[sBattler_AI].status2 & STATUS2_SUBSTITUTE) && (gBattleMons[gBattlerTarget].status2 & STATUS2_RECHARGE) && GetWhoStrikesFirst(sBattler_AI, gBattlerTarget, TRUE) == 0
                )
            && AICanSwitchAssumingEnoughPokemon()
           )
                SWITCH_IF_THERE_IS_A_SUITABLE_MON(NOT_CHANGING_IS_ACCEPTABLE);

        // La IA puede considerar repetir su último movimiento si observa que el rival está cambiando.
        // Para darse cuenta de ello, se mantiene cierta información en memoria
        if ((!memory.opponentChanged && memory.enoughPointsDifference) || gDisableStructs[sBattler_AI].isFirstTurn)
            ((u8*) &memory)[0] = 0;
        else if (!PROTECT_WONT_FAIL_FOR(gBattlerTarget)) // si el rival se protegió con éxito
        {
            u8 lastMoveAux = memory.lastMoveIndex;
            memory.lastMoveIndex = memory.secondLastMoveIndex;
            memory.secondLastMoveIndex = lastMoveAux;
            if (!memory.switchesDetected)
                memory.enoughPointsDifference = 0;
        }
        else if (!gDisableStructs[gBattlerTarget].isFirstTurn)
            ((u8*) &memory)[0] = 0;
        else
        {
            // Es posible que el oponente haya cambiado por Relevo y siendo el
            // segundo en atacar, en cuyo caso no habría que contarlo como cambio
            memory.opponentChanged = 1;
            if (memory.triedToPredictSwitches)
                memory.enoughPointsDifference = 0;
        }

        memory.triedToPredictSwitches = 0;

        if (memory.opponentChanged)
        {
            if (AI_THINKING_STRUCT->score[chosenMovePos]
                  - AI_THINKING_STRUCT->score[memory.lastMoveIndex]
                  >= 6) // el nuevo movimiento supera en al menos 6 puntos el anterior
            {
                bool8 previous_turn_had_switches_detected = memory.switchesDetected;
                memory.switchesDetected = memory.enoughPointsDifference && memory.secondLastMoveIndex == chosenMovePos;
                memory.secondLastMoveIndex = memory.lastMoveIndex;
                memory.lastMoveIndex = chosenMovePos;
                memory.enoughPointsDifference = 1;

                if (memory.switchesDetected && (Random()%2))
                {
                    // La IA ha detectado que el rival está cambiando y va a considerar
                    // repetir ataque si a la IA no le conviene perder el tiempo
                    // y el movimiento anterior puede ser ejecutado
                    u16 previous_move = gBattleMons[sBattler_AI].moves[memory.secondLastMoveIndex];
                    bool8 doNotRepeat = FALSE;

                    // Si el rival ya no puede cambiar, no hace falta repetir
                    // Podría descartar el cambio erróneamente en caso de Baton Pass de rival más rápido
                    if (!IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_GHOST) &&
                        (
                            (gBattleMons[sBattler_AI].ability == ABILITY_SHADOW_TAG && !ABILITY_ON_OPPOSING_FIELD(sBattler_AI, ABILITY_SHADOW_TAG))
                         || (gBattleMons[sBattler_AI].ability == ABILITY_ARENA_TRAP && !IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_FLYING) && gBattleMons[gBattlerTarget].ability != ABILITY_LEVITATE)
                         || (gBattleMons[sBattler_AI].ability == ABILITY_MAGNET_PULL && IS_BATTLER_OF_TYPE(gBattlerTarget, TYPE_STEEL))
                         || (gBattleMons[gBattlerTarget].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
                        )
                       )
                        doNotRepeat = TRUE;
                    
                    if (!doNotRepeat)
                        switch(gBattleMoves[previous_move].target)
                        {
                            case MOVE_TARGET_DEPENDS:
                            case MOVE_TARGET_USER:
                            case MOVE_TARGET_OPPONENTS_FIELD:
                                doNotRepeat = TRUE;
                        }
                    
                    if (!doNotRepeat)
                        switch(gBattleMoves[previous_move].effect)
                        {
                            case EFFECT_DISABLE:
                            case EFFECT_ENCORE:
                            case EFFECT_SKILL_SWAP:
                            case EFFECT_HEAL_PULSE:
                                doNotRepeat = TRUE;
                        }

                    if (!doNotRepeat && AI_THINKING_STRUCT->score[memory.lastMoveIndex] > 40
                     && (
                         (previous_turn_had_switches_detected && (Random()%5)) // tiene un 10% de jugársela si lleva más de un turno seguido aunque no pase nada de lo siguiente
                      || (gBattleMons[sBattler_AI].status1 & (STATUS1_PSN_ANY | STATUS1_BURN))
                      || (gBattleMons[sBattler_AI].status2 & STATUS2_CURSED)
                      || (gStatuses3[sBattler_AI] & STATUS3_LEECHSEED)
                      || sBattler_AIisLosingHPDueToWeather(FALSE)
                      || gBattleMons[sBattler_AI].pp[chosenMovePos] < 8 // la IA empieza a tener pocos PP
                        )
                    )
                    {
                        // La IA va a probar a repetir movimiento
                        chosenMovePos = memory.secondLastMoveIndex;
                        memory.triedToPredictSwitches = 1;
                    }
                }
            }  
            else // esto incluye que lastMoveIndex == chosenMovePos
            {
                memory.lastMoveIndex = chosenMovePos;
                memory.enoughPointsDifference = 0;
                memory.opponentChanged = 0;
                memory.switchesDetected = 0;
            }
        }
        else
        {
            memory.lastMoveIndex = chosenMovePos;
            memory.switchesDetected = 0;
        }

        STORED_AI_MEMORY = memory;
        return chosenMovePos;
    }
}

static u8 ChooseMoveOrAction_Doubles(void)
{
    s32 i;
    s32 j;
    s32 scriptsToRun;
    s16 bestMovePointsForTarget[MAX_BATTLERS_COUNT];
    s8 mostViableTargetsArray[MAX_BATTLERS_COUNT];
    u8 actionOrMoveIndex[MAX_BATTLERS_COUNT];
    u8 mostViableMovesScores[MAX_MON_MOVES];
    u8 mostViableMovesIndices[MAX_MON_MOVES];
    s32 mostViableTargetsNo;
    s32 mostViableMovesNo;
    s16 mostMovePoints;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        if (i == sBattler_AI || gBattleMons[i].hp == 0 || (gAbsentBattlerFlags & gBitTable[i]))
        {
            actionOrMoveIndex[i] = 0xFF;
            bestMovePointsForTarget[i] = -1;
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_PALACE)
                BattleAI_SetupAIData(gBattleStruct->field_92 >> 4);
            else
                BattleAI_SetupAIData(0xF);

            gBattlerTarget = i;

            if ((i & BIT_SIDE) != (sBattler_AI & BIT_SIDE))
                RecordLastUsedMoveByTarget();

            AI_THINKING_STRUCT->aiLogicId = 0;
            AI_THINKING_STRUCT->movesetIndex = 0;
            scriptsToRun = AI_THINKING_STRUCT->aiFlags;
            while (scriptsToRun != 0)
            {
                if (scriptsToRun & 1)
                {
                    AI_THINKING_STRUCT->aiState = AIState_SettingUp;
                    BattleAI_DoAIProcessing();
                }
                scriptsToRun >>= 1;
                AI_THINKING_STRUCT->aiLogicId++;
                AI_THINKING_STRUCT->movesetIndex = 0;
            }

            if (AI_THINKING_STRUCT->aiAction & AI_ACTION_FLEE)
            {
                actionOrMoveIndex[i] = AI_CHOICE_FLEE;
            }
            else if (AI_THINKING_STRUCT->aiAction & AI_ACTION_WATCH)
            {
                actionOrMoveIndex[i] = AI_CHOICE_WATCH;
            }
            else
            {
#if __DEBUG_AI__
                    int k;
                    if (i != (sBattler_AI ^ BIT_FLANK)) for (k = 0; k < 4; k++) {
                        u8 numerico[6+4] = {EXT_CTRL_CODE_BEGIN, EXT_CTRL_CODE_COLOR, TEXT_COLOR_GREEN, EXT_CTRL_CODE_BEGIN, EXT_CTRL_CODE_SHADOW, TEXT_COLOR_LIGHT_GREEN};
                        ConvertIntToDecimalStringN(numerico+6, AI_THINKING_STRUCT->score[k], STR_CONV_MODE_RIGHT_ALIGN, 3);
                        AddTextPrinterParameterized(1, 0, numerico, 48 + 16*k + i/2, 4 + 7*i, 0, NULL);
                    }
#endif
                mostViableMovesScores[0] = AI_THINKING_STRUCT->score[0];
                mostViableMovesIndices[0] = 0;
                mostViableMovesNo = 1;
                for (j = 1; j < MAX_MON_MOVES; j++)
                {
                    if (gBattleMons[sBattler_AI].moves[j] != 0)
                    {
                        if (mostViableMovesScores[0] == AI_THINKING_STRUCT->score[j])
                        {
                            mostViableMovesScores[mostViableMovesNo] = AI_THINKING_STRUCT->score[j];
                            mostViableMovesIndices[mostViableMovesNo] = j;
                            mostViableMovesNo++;
                        }
                        if (mostViableMovesScores[0] < AI_THINKING_STRUCT->score[j])
                        {
                            mostViableMovesScores[0] = AI_THINKING_STRUCT->score[j];
                            mostViableMovesIndices[0] = j;
                            mostViableMovesNo = 1;
                        }
                    }
                }
                actionOrMoveIndex[i] = mostViableMovesIndices[Random() % mostViableMovesNo];
                bestMovePointsForTarget[i] = mostViableMovesScores[0];

                // Don't use a move against ally if it has less than 100 points.
                if (i == (sBattler_AI ^ BIT_FLANK) && bestMovePointsForTarget[i] < 100)
                {
                    bestMovePointsForTarget[i] = -1;
                    mostViableMovesScores[0] = mostViableMovesScores[0]; // Needed to match.
                }
            }
        }
    }

    mostMovePoints = bestMovePointsForTarget[0];
    mostViableTargetsArray[0] = 0;
    mostViableTargetsNo = 1;

    for (i = 1; i < MAX_BATTLERS_COUNT; i++)
    {
        if (mostMovePoints == bestMovePointsForTarget[i])
        {
            mostViableTargetsArray[mostViableTargetsNo] = i;
            mostViableTargetsNo++;
        }
        if (mostMovePoints < bestMovePointsForTarget[i])
        {
            mostMovePoints = bestMovePointsForTarget[i];
            mostViableTargetsArray[0] = i;
            mostViableTargetsNo = 1;
        }
    }

    gBattlerTarget = mostViableTargetsArray[Random() % mostViableTargetsNo];

    // Consider switching if your mon with truant is bodied by Protect spam.
    // Or can be exploited by semi invulnerable moves (such as Fly).
    // Or its ability is actually not Truant.
    if (gBattleMons[sBattler_AI].ability == ABILITY_TRUANT
        && GET_BATTLER_SIDE(sBattler_AI) != GET_BATTLER_SIDE(gBattlerTarget)
        && actionOrMoveIndex[gBattlerTarget] != AI_CHOICE_FLEE
        && actionOrMoveIndex[gBattlerTarget] != AI_CHOICE_WATCH
        && ((IsTruantMonVulnerable(sBattler_AI, gBattlerTarget, FALSE)
            && (gBattleMons[gBattlerTarget ^ BIT_FLANK].hp == 0 || IsTruantMonVulnerable(sBattler_AI, gBattlerTarget ^ BIT_FLANK, FALSE)) // no puede atacar al otro porque no hay otro o por lo mismo
            )
            || (GetAbilityBySpecies(gBattleMons[sBattler_AI].species, gBattleMons[sBattler_AI].abilityNum) != ABILITY_TRUANT
              && gDisableStructs[sBattler_AI].truantCounter
               )
           )
        && AICanSwitchAssumingEnoughPokemon())
        SWITCH_IF_THERE_IS_A_SUITABLE_MON(gDisableStructs[sBattler_AI].truantCounter ? NOT_CHANGING_IS_UNACCEPTABLE : NOT_CHANGING_IS_ACCEPTABLE);
    return actionOrMoveIndex[gBattlerTarget];
}

static void BattleAI_DoAIProcessing(void)
{
    while (AI_THINKING_STRUCT->aiState != AIState_FinishedProcessing)
    {
        switch (AI_THINKING_STRUCT->aiState)
        {
            case AIState_DoNotProcess: // Needed to match.
                break;
            case AIState_SettingUp:
                gAIScriptPtr = gBattleAI_ScriptsTable[AI_THINKING_STRUCT->aiLogicId]; // set AI ptr to logic ID.
                if (gBattleMons[sBattler_AI].pp[AI_THINKING_STRUCT->movesetIndex] == 0)
                {
                    AI_THINKING_STRUCT->moveConsidered = 0;
                }
                else
                {
                    AI_THINKING_STRUCT->moveConsidered = gBattleMons[sBattler_AI].moves[AI_THINKING_STRUCT->movesetIndex];
                }
                AI_THINKING_STRUCT->aiState++;
                break;
            case AIState_Processing:
                if (AI_THINKING_STRUCT->moveConsidered != 0)
                {
                    sBattleAICmdTable[*gAIScriptPtr](); // Run AI command.
                }
                else
                {
                    AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] = 0;
                    AI_THINKING_STRUCT->aiAction |= AI_ACTION_DONE;
                }
                if (AI_THINKING_STRUCT->aiAction & AI_ACTION_DONE)
                {
                   AI_THINKING_STRUCT->movesetIndex++;

                    if (AI_THINKING_STRUCT->movesetIndex < MAX_MON_MOVES && !(AI_THINKING_STRUCT->aiAction & AI_ACTION_DO_NOT_ATTACK))
                        AI_THINKING_STRUCT->aiState = AIState_SettingUp;
                    else
                        AI_THINKING_STRUCT->aiState++;

                    AI_THINKING_STRUCT->aiAction &= ~(AI_ACTION_DONE);
                }
                break;
        }
    }
}

void RecordLastUsedMoveByTarget(void)
{
    s32 i;

    if (gLastMoves[gBattlerTarget] == 0xFFFF || gLastMoves[gBattlerTarget] == MOVE_NONE)
        return;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (FOES_MOVE_HISTORY(gBattlerTarget)[i] == gLastMoves[gBattlerTarget])
            break;
        if (FOES_MOVE_HISTORY(gBattlerTarget)[i] != gLastMoves[gBattlerTarget]  // HACK: This redundant condition is a hack to make the asm match.
         && FOES_MOVE_HISTORY(gBattlerTarget)[i] == MOVE_NONE)
        {
            FOES_MOVE_HISTORY(gBattlerTarget)[i] = gLastMoves[gBattlerTarget];
            break;
        }
    }
}

void ClearBattlerMoveHistory(u8 battlerId)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
        FOES_MOVE_HISTORY(battlerId)[i] = MOVE_NONE;
}

void RecordAbilityBattle(u8 battlerId, u8 abilityId)
{
    FOES_OBSERVED_ABILITY(battlerId) = abilityId;
}

void ClearBattlerAbilityHistory(u8 battlerId)
{
    FOES_OBSERVED_ABILITY(battlerId) = ABILITY_NONE;
}

void CopyBattlerHistoryForTransformedMon(u8 transformUser, u8 transformTarget)
{
    s32 i;
    // Si se transforma en un compañero, el rival solo tiene acceso a los movimientos que ha visto,
    // mientras que si lo hace en un oponente, el rival sabe sus movimientos
    if (GetBattlerSide(transformTarget) == GetBattlerSide(transformUser)) {
        FOES_OBSERVED_ABILITY(transformUser) = FOES_OBSERVED_ABILITY(transformTarget);
        
        for (i = 0; i < MAX_MON_MOVES; i++)
            FOES_MOVE_HISTORY(transformUser)[i] = FOES_MOVE_HISTORY(transformTarget)[i];
    }
    else {
        FOES_OBSERVED_ABILITY(transformUser) = gBattleMons[transformTarget].ability;
        
        for (i = 0; i < MAX_MON_MOVES; i++)
            FOES_MOVE_HISTORY(transformUser)[i] = gBattleMons[transformTarget].moves[i];
    }
}

void LearnBattlerHistoryFromTransformedMon(u8 transformUser, u8 transformTarget)
{
    s32 i;

    // No aporta ninguna información si el poke se transforma en un compañero
    if (GetBattlerSide(transformUser) == GetBattlerSide(transformTarget))
        return;

    FOES_OBSERVED_ABILITY(transformTarget) = gBattleMons[transformTarget].ability;
        
    for (i = 0; i < MAX_MON_MOVES; i++)
     {
        FOES_MOVE_HISTORY(transformTarget)[i] = gBattleMons[transformTarget].moves[i];
        // Chapuza para que la IA sepa que conoce todos los movimientos:
        // se repite el primer movimiento en los huecos si el rival no tiene 4 movimientos
        if (gBattleMons[transformTarget].moves[i] == MOVE_NONE)
            FOES_MOVE_HISTORY(transformTarget)[i] = gBattleMons[transformTarget].moves[0];
    }
}

void RecordItemEffectBattle(u8 battlerId, u8 itemEffect)
{
    FOES_OBSERVED_ITEM_EFFECT(battlerId) = itemEffect;
}

void ClearBattlerItemEffectHistory(u8 battlerId)
{
    FOES_OBSERVED_ITEM_EFFECT(battlerId) = 0;
}

// La IA toma nota de que, a lo largo del turno, hubo algún cambio obligado
// (por KO o por Roar/Whirlwind) en alguno de los equipos
// También se usa en caso de transformación
void AI_MarkForcedChange(void)
{
    s32 i;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        for (i = 0; i < 2; i++)
        {
            BATTLE_HISTORY->switchMemory[i].opponentChanged = 0;
            BATTLE_HISTORY->switchMemory[i].enoughPointsDifference = 1;
        }
}

static void Cmd_if_random_less_than(void)
{
    u16 random = Random();

    if (random % 256 < gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_random_greater_than(void)
{
    u16 random = Random();

    if (random % 256 > gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_random_equal(void)
{
    u16 random = Random();

    if (random % 256 == gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_random_not_equal(void)
{
    u16 random = Random();

    if (random % 256 != gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_score(void)
{
    AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] += gAIScriptPtr[1]; // Add the result to the array of the move consider's score.

    if (AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] < 0) // If the score is negative, flatten it to 0.
        AI_THINKING_STRUCT->score[AI_THINKING_STRUCT->movesetIndex] = 0;

    gAIScriptPtr += 2; // AI return.
}

static void Cmd_if_hp_condition(void)
{
    switch (gAIScriptPtr[1])
    {
    case TARGET_HAS_1_HP: // comprueba si el rival tiene 1 PS
        if (gBattleMons[gBattlerTarget].hp == 1)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case USER_HAS_1_HP: // comprueba si la IA tiene 1 PS
        if (gBattleMons[sBattler_AI].hp == 1)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case TARGET_HAS_1_MAX_HP: // comprueba si el rival tiene 1 como PS máximos
        if (gBattleMons[gBattlerTarget].maxHP == 1)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case TARGET_WITH_LEFTIES_WONT_LOSE_HP_IF_WE_USE_ENDEAVOR: // comprueba si el rival tiene, como máximo, los PS que tiene el usuario más lo que el rival obtendría por Restos
        if (gBattleMons[gBattlerTarget].hp <= gBattleMons[sBattler_AI].hp + gBattleMons[gBattlerTarget].maxHP / 16)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case TARGET_CANNOT_USE_SUB: // comprueba si el rival no tiene PS como para usar Sustituto
        if (gBattleMons[gBattlerTarget].hp <= gBattleMons[gBattlerTarget].maxHP / 4)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case USER_CANNOT_USE_SUB: // comprueba si la IA no tiene PS como para usar Sustituto
        if (gBattleMons[sBattler_AI].hp <= gBattleMons[sBattler_AI].maxHP / 4)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case USER_CANNOT_USE_BELLY_DRUM: // comprueba si la IA no tiene PS como para usar Tambor
        if (gBattleMons[sBattler_AI].hp <= gBattleMons[sBattler_AI].maxHP / 2)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    }
}

static void Cmd_if_hp_less_than(void)
{
    u16 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if ((u32)(100 * gBattleMons[battlerId].hp / gBattleMons[battlerId].maxHP) < gAIScriptPtr[2])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_hp_more_than(void)
{
    u16 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if ((u32)(100 * gBattleMons[battlerId].hp / gBattleMons[battlerId].maxHP) > gAIScriptPtr[2])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_hp_equal(void)
{
    u16 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if ((u32)(100 * gBattleMons[battlerId].hp / gBattleMons[battlerId].maxHP) == gAIScriptPtr[2])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_hp_not_equal(void)
{
    u16 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if ((u32)(100 * gBattleMons[battlerId].hp / gBattleMons[battlerId].maxHP) != gAIScriptPtr[2])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_status(void)
{
    u16 battlerId;
    u32 status;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    status = T1_READ_32(gAIScriptPtr + 2);

    if (gBattleMons[battlerId].status1 & status)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_not_status(void)
{
    u16 battlerId;
    u32 status;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    status = T1_READ_32(gAIScriptPtr + 2);

    if (!(gBattleMons[battlerId].status1 & status))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_status2(void)
{
    u16 battlerId;
    u32 status;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    status = T1_READ_32(gAIScriptPtr + 2);

    if ((gBattleMons[battlerId].status2 & status))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_not_status2(void)
{
    u16 battlerId;
    u32 status;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    status = T1_READ_32(gAIScriptPtr + 2);

    if (!(gBattleMons[battlerId].status2 & status))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_status3(void)
{
    u16 battlerId;
    u32 status;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    status = T1_READ_32(gAIScriptPtr + 2);

    if (gStatuses3[battlerId] & status)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_not_status3(void)
{
    u16 battlerId;
    u32 status;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    status = T1_READ_32(gAIScriptPtr + 2);

    if (!(gStatuses3[battlerId] & status))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_side_affecting(void)
{
    u16 battlerId;
    u32 side, status;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    side = GET_BATTLER_SIDE(battlerId);
    status = T1_READ_32(gAIScriptPtr + 2);

    if (gSideStatuses[side] & status)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_not_side_affecting(void)
{
    u16 battlerId;
    u32 side, status;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    side = GET_BATTLER_SIDE(battlerId);
    status = T1_READ_32(gAIScriptPtr + 2);

    if (!(gSideStatuses[side] & status))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
    else
        gAIScriptPtr += 10;
}

static void Cmd_if_less_than(void)
{
    if (AI_THINKING_STRUCT->funcResult < gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_more_than(void)
{
    if (AI_THINKING_STRUCT->funcResult > gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_equal(void)
{
    if (AI_THINKING_STRUCT->funcResult == gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_not_equal(void)
{
    if (AI_THINKING_STRUCT->funcResult != gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_less_than_ptr(void)
{
    const u8 *value = T1_READ_PTR(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult < *value)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void Cmd_if_more_than_ptr(void)
{
    const u8 *value = T1_READ_PTR(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult > *value)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void Cmd_if_equal_ptr(void)
{
    const u8 *value = T1_READ_PTR(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult == *value)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void Cmd_if_not_equal_ptr(void)
{
    const u8 *value = T1_READ_PTR(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->funcResult != *value)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
    else
        gAIScriptPtr += 9;
}

static void Cmd_if_move(void)
{
    u16 move = T1_READ_16(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->moveConsidered == move)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_not_move(void)
{
    u16 move = T1_READ_16(gAIScriptPtr + 1);

    if (AI_THINKING_STRUCT->moveConsidered != move)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_if_in_bytes(void)
{
    const u8 *ptr = T1_READ_PTR(gAIScriptPtr + 1);

    while (*ptr != 0xFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
            return;
        }
        ptr++;
    }
    gAIScriptPtr += 9;
}

static void Cmd_if_not_in_bytes(void)
{
    const u8 *ptr = T1_READ_PTR(gAIScriptPtr + 1);

    while (*ptr != 0xFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr += 9;
            return;
        }
        ptr++;
    }
    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
}

static void Cmd_if_in_hwords(void)
{
    const u16 *ptr = (const u16 *)T1_READ_PTR(gAIScriptPtr + 1);

    while (*ptr != 0xFFFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
            return;
        }
        ptr++;
    }
    gAIScriptPtr += 9;
}

static void Cmd_if_not_in_hwords(void)
{
    const u16 *ptr = (const u16 *)T1_READ_PTR(gAIScriptPtr + 1);

    while (*ptr != 0xFFFF)
    {
        if (AI_THINKING_STRUCT->funcResult == *ptr)
        {
            gAIScriptPtr += 9;
            return;
        }
        ptr++;
    }
    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 5);
}

static void Cmd_if_user_has_attacking_non_ineffective_move(void)
{
    s32 i;
    u8 moveLimitations = CheckMoveLimitations(sBattler_AI, 0, MOVE_LIMITATION_PP);

    for (i = 0; i < MAX_MON_MOVES; i++)
        if (gBattleMons[sBattler_AI].moves[i] != 0
            && !(gBitTable[i] & moveLimitations)
            && gBattleMoves[gBattleMons[sBattler_AI].moves[i]].power != 0
            && CalculateDamageFromMove(sBattler_AI, gBattlerTarget, gBattleMons[sBattler_AI].moves[i], 0) > 0
           )
            break;

    if (i == MAX_MON_MOVES)
        gAIScriptPtr += 5;
    else
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
}

static void Cmd_if_user_has_no_attacking_non_ineffective_moves(void)
{
    s32 i;
    u8 moveLimitations = CheckMoveLimitations(sBattler_AI, 0, MOVE_LIMITATION_PP);

    for (i = 0; i < MAX_MON_MOVES; i++)
        if (gBattleMons[sBattler_AI].moves[i] != 0
            && !(gBitTable[i] & moveLimitations)
            && gBattleMoves[gBattleMons[sBattler_AI].moves[i]].power != 0
            && CalculateDamageFromMove(sBattler_AI, gBattlerTarget, gBattleMons[sBattler_AI].moves[i], 0) > 0
           )
            break;

    if (i != MAX_MON_MOVES)
        gAIScriptPtr += 5;
    else
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
}

static void Cmd_get_turn_count(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleResults.battleTurnCounter;
    gAIScriptPtr += 1;
}

static void Cmd_get_type(void)
{
    u8 typeVar = gAIScriptPtr[1];

    switch (typeVar)
    {
    case AI_TYPE1_USER: // AI user primary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[sBattler_AI].type1;
        break;
    case AI_TYPE1_TARGET: // target primary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBattlerTarget].type1;
        break;
    case AI_TYPE2_USER: // AI user secondary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[sBattler_AI].type2;
        break;
    case AI_TYPE2_TARGET: // target secondary type
        AI_THINKING_STRUCT->funcResult = gBattleMons[gBattlerTarget].type2;
        break;
    case AI_TYPE_MOVE: // type of move being pointed to
        AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].type;
        break;
    }
    gAIScriptPtr += 2;
}

static u8 BattleAI_GetWantedBattler(u8 wantedBattler)
{
    switch (wantedBattler)
    {
    case AI_USER:
        return sBattler_AI;
    case AI_TARGET:
    default:
        return gBattlerTarget;
    case AI_USER_PARTNER:
        return sBattler_AI ^ BIT_FLANK;
    case AI_TARGET_PARTNER:
        return gBattlerTarget ^ BIT_FLANK;
    }
}

static void Cmd_if_type(void)
{
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if (IS_BATTLER_OF_TYPE(battlerId, gAIScriptPtr[2]))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    else
        gAIScriptPtr += 7;
}

static void Cmd_get_considered_move_power(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power;
    gAIScriptPtr += 1;
}

static void Cmd_get_how_powerful_move_is(void)
{
    s32 i, checkedMove;
    s32 moveDmgs[MAX_MON_MOVES];
	bool8 isDiscouraged = FALSE;
    u16 effect = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect;

    if (effect == EFFECT_SOLARBEAM && (gBattleWeather & WEATHER_SUN_ANY))
        effect = EFFECT_HIT;   // Si hay sol, Rayo Solar se comporta como un movimiento estándar

    for (i = 0; sDiscouragedPowerfulMoveEffects[i] != 0xFFFF; i++)
    {
	if (effect == sDiscouragedPowerfulMoveEffects[i]) {
            isDiscouraged = TRUE;
            break;
	}
    }

    if (AI_CAN_ESTIMATE_DAMAGE(AI_THINKING_STRUCT->moveConsidered))
    {
        gDynamicBasePower = 0;
        *(&gBattleStruct->dynamicMoveType) = 0;
        gBattleScripting.dmgMultiplier = 1;
        gMoveResultFlags = 0;
        gCritMultiplier = 1;

        for (checkedMove = 0; checkedMove < MAX_MON_MOVES; checkedMove++)
        {
			     effect = gBattleMoves[gBattleMons[sBattler_AI].moves[checkedMove]].effect;
            if (effect == EFFECT_SOLARBEAM && (gBattleWeather & WEATHER_SUN_ANY))
                effect = EFFECT_HIT;   // Si hay sol, Rayo Solar se comporta como un movimiento estándar
			
             for (i = 0; sDiscouragedPowerfulMoveEffects[i] != 0xFFFF; i++)
            {
                if (effect == sDiscouragedPowerfulMoveEffects[i])
                    break;
            }

            if (gBattleMons[sBattler_AI].moves[checkedMove] != MOVE_NONE
                && (sDiscouragedPowerfulMoveEffects[i] == 0xFFFF || checkedMove == AI_THINKING_STRUCT->movesetIndex)
                && AI_CAN_ESTIMATE_DAMAGE(gBattleMons[sBattler_AI].moves[checkedMove]))
            {
                gCurrentMove = gBattleMons[sBattler_AI].moves[checkedMove];
                AI_CalcDmg(sBattler_AI, gBattlerTarget);
                moveDmgs[checkedMove] = gBattleMoveDamage * AI_THINKING_STRUCT->simulatedRNG[checkedMove] / 100;
            }
            else
            {
                moveDmgs[checkedMove] = 0;
            }
        }

        for (checkedMove = 0; checkedMove < MAX_MON_MOVES; checkedMove++)
        {
            if (moveDmgs[checkedMove] > moveDmgs[AI_THINKING_STRUCT->movesetIndex])
                break;
        }

        if (checkedMove == MAX_MON_MOVES && moveDmgs[AI_THINKING_STRUCT->movesetIndex] > 0)
            AI_THINKING_STRUCT->funcResult = isDiscouraged ? MOVE_POWER_DISCOURAGED : MOVE_MOST_POWERFUL; // Is the most powerful.
        else
			AI_THINKING_STRUCT->funcResult = isDiscouraged ? MOVE_POWER_DISCOURAGED_AND_NOT_MOST_POWERFUL : MOVE_NOT_MOST_POWERFUL; // Not the most powerful.
    }
    else
    {
        AI_THINKING_STRUCT->funcResult = MOVE_HAS_ZERO_OR_UNPREDICTABLE_POWER; // Highly discouraged in terms of power.
    }

    gAIScriptPtr++;
}

static void Cmd_get_last_used_battler_move(void)
{
    if (gAIScriptPtr[1] == AI_USER)
        AI_THINKING_STRUCT->funcResult = gLastMoves[sBattler_AI];
    else
        AI_THINKING_STRUCT->funcResult = gLastMoves[gBattlerTarget];

    if (AI_THINKING_STRUCT->funcResult == 0xFFFF) // se quedó sin atacar por confusión, entre otras cosas
        AI_THINKING_STRUCT->funcResult = MOVE_NONE;
		gAIScriptPtr += 2;
}

static void Cmd_if_equal_(void) // Same as if_equal.
{
    if (gAIScriptPtr[1] == AI_THINKING_STRUCT->funcResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_not_equal_(void) // Same as if_not_equal.
{
    if (gAIScriptPtr[1] != AI_THINKING_STRUCT->funcResult)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_user_goes(void)
{
    if (GetWhoStrikesFirst(sBattler_AI, gBattlerTarget, TRUE) == gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_user_doesnt_go(void)
{
    if (GetWhoStrikesFirst(sBattler_AI, gBattlerTarget, TRUE) != gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_nullsub_2A(void)
{
}

static void Cmd_nullsub_2B(void)
{
}

static void Cmd_count_usable_party_mons(void)
{
    u8 battlerId;
    u8 battlerOnField1, battlerOnField2;
    struct Pokemon *party;
    s32 i;

    AI_THINKING_STRUCT->funcResult = 0;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if (GetBattlerSide(battlerId) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        u32 position;
        battlerOnField1 = gBattlerPartyIndexes[battlerId];
        position = GetBattlerPosition(battlerId) ^ BIT_FLANK;
        battlerOnField2 = gBattlerPartyIndexes[GetBattlerAtPosition(position)];
    }
    else // In singles there's only one battlerId by side.
    {
        battlerOnField1 = gBattlerPartyIndexes[battlerId];
        battlerOnField2 = gBattlerPartyIndexes[battlerId];
    }

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i != battlerOnField1 && i != battlerOnField2
         && GetMonData(&party[i], MON_DATA_HP) != 0
         && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
         && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
        {
            AI_THINKING_STRUCT->funcResult++;
        }
    }

    gAIScriptPtr += 2;
}

static void Cmd_get_considered_move(void)
{
    AI_THINKING_STRUCT->funcResult = AI_THINKING_STRUCT->moveConsidered;
    gAIScriptPtr += 1;
}

static void Cmd_get_considered_move_effect(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect;
    gAIScriptPtr += 1;
}

static void Cmd_get_ability(void)
{
    u8 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

	if ((sBattler_AI | BIT_FLANK) != (battlerId | BIT_FLANK))
    {
        if (FOES_OBSERVED_ABILITY(battlerId) != 0)
        {
            AI_THINKING_STRUCT->funcResult = FOES_OBSERVED_ABILITY(battlerId);
            gAIScriptPtr += 2;
            return;
        }

        // abilities that prevent fleeing.
        if (gBattleMons[battlerId].ability == ABILITY_SHADOW_TAG
        || gBattleMons[battlerId].ability == ABILITY_MAGNET_PULL
        || gBattleMons[battlerId].ability == ABILITY_ARENA_TRAP)
        {
            AI_THINKING_STRUCT->funcResult = gBattleMons[battlerId].ability;
            gAIScriptPtr += 2;
            return;
        }

        if (gBaseStats[gBattleMons[battlerId].species].abilities[0] != ABILITY_NONE)
        {
            if (gBaseStats[gBattleMons[battlerId].species].abilities[1] != ABILITY_NONE)
            {
                // AI has no knowledge of opponent, so it guesses which ability.
                if (Random() & 1)
                    AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[battlerId].species].abilities[0];
                else
                    AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[battlerId].species].abilities[1];
            }
            else
            {
                AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[battlerId].species].abilities[0]; // It's definitely ability 1.
            }
        }
        else
        {
            AI_THINKING_STRUCT->funcResult = gBaseStats[gBattleMons[battlerId].species].abilities[1]; // AI can't actually reach this part since no pokemon has ability 2 and no ability 1.
        }
    }
    else
    {
        // The AI knows its own ability.
        AI_THINKING_STRUCT->funcResult = gBattleMons[battlerId].ability;
    }

    gAIScriptPtr += 2;
}

static void Cmd_check_ability(void)
{
    u32 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u32 ability = gAIScriptPtr[2];

    if (gAIScriptPtr[1] == AI_TARGET || gAIScriptPtr[1] == AI_TARGET_PARTNER)
    {
        if (FOES_OBSERVED_ABILITY(battlerId) != ABILITY_NONE)
        {
            ability = FOES_OBSERVED_ABILITY(battlerId);
            AI_THINKING_STRUCT->funcResult = ability;
        }
        // Abilities that prevent fleeing.
        else if (gBattleMons[battlerId].ability == ABILITY_SHADOW_TAG
        || gBattleMons[battlerId].ability == ABILITY_MAGNET_PULL
        || gBattleMons[battlerId].ability == ABILITY_ARENA_TRAP)
        {
            ability = gBattleMons[battlerId].ability;
        }
        else if (gBaseStats[gBattleMons[battlerId].species].abilities[0] != ABILITY_NONE)
        {
            if (gBaseStats[gBattleMons[battlerId].species].abilities[1] != ABILITY_NONE && gBaseStats[gBattleMons[battlerId].species].abilities[1] != gBaseStats[gBattleMons[battlerId].species].abilities[0])
            {
                u8 abilityDummyVariable = ability; // Needed to match.
                if (gBaseStats[gBattleMons[battlerId].species].abilities[0] != abilityDummyVariable
                && gBaseStats[gBattleMons[battlerId].species].abilities[1] != abilityDummyVariable)
                {
                    ability = gBaseStats[gBattleMons[battlerId].species].abilities[0];
                }
                else
                {
                    ability = ABILITY_NONE;
                }
            }
            else
            {
                ability = gBaseStats[gBattleMons[battlerId].species].abilities[0];
            }
        }
        else
        {
            ability = gBaseStats[gBattleMons[battlerId].species].abilities[1]; // AI can't actually reach this part since no pokemon has ability 2 and no ability 1.
        }
    }
    else
    {
        // The AI knows its own or partner's ability.
        ability = gBattleMons[battlerId].ability;
    }

    if (ability == 0)
        AI_THINKING_STRUCT->funcResult = 2; // Unable to answer.
    else if (ability == gAIScriptPtr[2])
        AI_THINKING_STRUCT->funcResult = 1; // Pokemon has the ability we wanted to check.
    else
        AI_THINKING_STRUCT->funcResult = 0; // Pokemon doesn't have the ability we wanted to check.

    gAIScriptPtr += 3;
}

static void Cmd_get_highest_type_effectiveness(void)
{
    s32 i;
    u8 *dynamicMoveType;

    gDynamicBasePower = 0;
    dynamicMoveType = &gBattleStruct->dynamicMoveType;
    *dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gMoveResultFlags = 0;
    gCritMultiplier = 1;
    AI_THINKING_STRUCT->funcResult = 0;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        gBattleMoveDamage = 40;
        gCurrentMove = gBattleMons[sBattler_AI].moves[i];

        if (gCurrentMove != MOVE_NONE)
        {
            TypeCalc(gCurrentMove, sBattler_AI, gBattlerTarget);

            if (gBattleMoveDamage == 120) // Super effective STAB.
                gBattleMoveDamage = AI_EFFECTIVENESS_x2;
            if (gBattleMoveDamage == 240)
                gBattleMoveDamage = AI_EFFECTIVENESS_x4;
			if (gBattleMoveDamage == 320) // x4 y Adaptable
				gBattleMoveDamage = AI_EFFECTIVENESS_x4;
            if (gBattleMoveDamage == 30) // Not very effective STAB.
                gBattleMoveDamage = AI_EFFECTIVENESS_x0_5;
            if (gBattleMoveDamage == 15)
                gBattleMoveDamage = AI_EFFECTIVENESS_x0_25;

            if (gMoveResultFlags & MOVE_RESULT_DOESNT_AFFECT_FOE)
                gBattleMoveDamage = AI_EFFECTIVENESS_x0;

            if (AI_THINKING_STRUCT->funcResult < gBattleMoveDamage)
                AI_THINKING_STRUCT->funcResult = gBattleMoveDamage;
        }
    }

    gAIScriptPtr += 1;
}

static void Cmd_if_type_effectiveness(void)
{
    u8 damageVar;
	u8 flags;

    gDynamicBasePower = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gCritMultiplier = 1;

    gBattleMoveDamage = AI_EFFECTIVENESS_x1;
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;

    flags = TypeCalc(gCurrentMove, sBattler_AI, gBattlerTarget);

    if (gBattleMoveDamage == 120) // Super effective STAB.
        gBattleMoveDamage = AI_EFFECTIVENESS_x2;
    if (gBattleMoveDamage == 240)
        gBattleMoveDamage = AI_EFFECTIVENESS_x4;
	if (gBattleMoveDamage == 320) // x4 y Adaptable
        gBattleMoveDamage = AI_EFFECTIVENESS_x4;
    if (gBattleMoveDamage == 30) // Not very effective STAB.
        gBattleMoveDamage = AI_EFFECTIVENESS_x0_5;
    if (gBattleMoveDamage == 15)
        gBattleMoveDamage = AI_EFFECTIVENESS_x0_25;

    if (flags & MOVE_RESULT_DOESNT_AFFECT_FOE)
        gBattleMoveDamage = AI_EFFECTIVENESS_x0;

    // Store gBattleMoveDamage in a u8 variable because gAIScriptPtr[1] is a u8.
    damageVar = gBattleMoveDamage;

    if (damageVar == gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_nullsub_32(void)
{
}

static void Cmd_nullsub_33(void)
{
}

// Comprueba si hay pokémon en el equipo del pokémon indicado
// con el status indicado, excluyendo al propio pokémon indicado
static void Cmd_if_status_in_party(void)
{
    struct Pokemon *party;
    s32 i;
    u32 statusToCompareTo;
    u8 battlerId;
	u8 battlerOnField;

    switch (gAIScriptPtr[1])
    {
    case AI_USER:
        battlerId = sBattler_AI;
        break;
    default:
        battlerId = gBattlerTarget;
        break;
    }

    party = (GetBattlerSide(battlerId) == B_SIDE_PLAYER) ? gPlayerParty : gEnemyParty;
	battlerOnField = gBattlerPartyIndexes[battlerId];

    statusToCompareTo = T1_READ_32(gAIScriptPtr + 2);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
        u16 hp = GetMonData(&party[i], MON_DATA_HP);
        u32 status = GetMonData(&party[i], MON_DATA_STATUS);

		if (i != battlerOnField && species != SPECIES_NONE && species != SPECIES_EGG && hp != 0 && (status & statusToCompareTo))
        {
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
            return;
        }
    }

    gAIScriptPtr += 10;
}

static void Cmd_if_status_not_in_party(void)
{
    struct Pokemon *party;
    s32 i;
    u32 statusToCompareTo;
    u8 battlerId;
	u8 battlerOnField;

    switch(gAIScriptPtr[1])
    {
    case 1:
        battlerId = sBattler_AI;
        break;
    default:
        battlerId = gBattlerTarget;
        break;
    }

    party = (GetBattlerSide(battlerId) == B_SIDE_PLAYER) ? gPlayerParty : gEnemyParty;
	battlerOnField = gBattlerPartyIndexes[battlerId];

    statusToCompareTo = T1_READ_32(gAIScriptPtr + 2);

    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
        u16 hp = GetMonData(&party[i], MON_DATA_HP);
        u32 status = GetMonData(&party[i], MON_DATA_STATUS);

		if (i != battlerOnField && species != SPECIES_NONE && species != SPECIES_EGG && hp != 0 && (status & statusToCompareTo))
        {
            gAIScriptPtr += 10;
            return;
        }
    }

    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 6);
}

static void Cmd_get_weather(void)
{
	AI_THINKING_STRUCT->funcResult = AI_WEATHER_NONE;

    if (gBattleWeather & WEATHER_RAIN_ANY)
        AI_THINKING_STRUCT->funcResult = AI_WEATHER_RAIN;
    if (gBattleWeather & WEATHER_SANDSTORM_ANY)
        AI_THINKING_STRUCT->funcResult = AI_WEATHER_SANDSTORM;
    if (gBattleWeather & WEATHER_SUN_ANY)
        AI_THINKING_STRUCT->funcResult = AI_WEATHER_SUN;
    if (gBattleWeather & WEATHER_HAIL_ANY)
        AI_THINKING_STRUCT->funcResult = AI_WEATHER_HAIL;

    gAIScriptPtr += 1;
}

static void Cmd_if_effect(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect == gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_not_effect(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect != gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_stat_level_less_than(void)
{
    u32 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if (gBattleMons[battlerId].statStages[gAIScriptPtr[2]] < gAIScriptPtr[3])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void Cmd_if_stat_level_more_than(void)
{
    u32 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if (gBattleMons[battlerId].statStages[gAIScriptPtr[2]] > gAIScriptPtr[3])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void Cmd_if_stat_level_equal(void)
{
    u32 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if (gBattleMons[battlerId].statStages[gAIScriptPtr[2]] == gAIScriptPtr[3])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void Cmd_if_stat_level_not_equal(void)
{
    u32 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if (gBattleMons[battlerId].statStages[gAIScriptPtr[2]] != gAIScriptPtr[3])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void Cmd_if_can_faint_with_threshold(void)
{
    u8 threshold;
    u8 threshold_arg = gAIScriptPtr[1];
    u16 target_damage = gBattleMons[gBattlerTarget].hp;
    if ((gBattleMons[gBattlerTarget].status2 & STATUS2_SUBSTITUTE) && gDisableStructs[gBattlerTarget].substituteHP)
        target_damage = gDisableStructs[gBattlerTarget].substituteHP;

    if (!AI_CAN_ESTIMATE_DAMAGE(AI_THINKING_STRUCT->moveConsidered))
    {
        gAIScriptPtr += 6;
        return;
    }

    switch(threshold_arg) {
        case AI_FAINT_THRESHOLD_PESSIMISTIC:
            threshold = 85;
            break;
        case AI_FAINT_THRESHOLD_OPTIMISTIC:
            threshold = 100;
            break;
        default: // AI_FAINT_THRESHOLD_RANDOM
            threshold = AI_THINKING_STRUCT->simulatedRNG[AI_THINKING_STRUCT->movesetIndex];
    }

    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;
    CalculategBattleMoveDamageFromgCurrentMove(sBattler_AI, gBattlerTarget, threshold);

    if (target_damage <= gBattleMoveDamage)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_if_cant_faint(void)
{
    if (!AI_CAN_ESTIMATE_DAMAGE(AI_THINKING_STRUCT->moveConsidered))
    {
        gAIScriptPtr += 5;
        return;
    }

    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;
    CalculategBattleMoveDamageFromgCurrentMove(sBattler_AI, gBattlerTarget, AI_THINKING_STRUCT->simulatedRNG[AI_THINKING_STRUCT->movesetIndex]);

    if (gBattleMons[gBattlerTarget].hp > gBattleMoveDamage)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_if_has_move(void)
{
    s32 i;
    const u16 *movePtr = (u16 *)(gAIScriptPtr + 2);
	u8 moveLimitations;

    switch (gAIScriptPtr[1])
    {
    case AI_USER:
        moveLimitations = CheckMoveLimitations(sBattler_AI, 0, MOVE_LIMITATION_PP);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[sBattler_AI].moves[i] == *movePtr && !(gBitTable[i] & moveLimitations))
                break;
        }
        if (i == MAX_MON_MOVES)
            gAIScriptPtr += 8;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
        break;
    case AI_USER_PARTNER:
        moveLimitations = CheckMoveLimitations(sBattler_AI ^ BIT_FLANK, 0, MOVE_LIMITATION_PP);
        if (gBattleMons[sBattler_AI ^ BIT_FLANK].hp == 0)
        {
            gAIScriptPtr += 8;
            break;
        }
        else
        {
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                if (gBattleMons[sBattler_AI ^ BIT_FLANK].moves[i] == *movePtr && !(gBitTable[i] & moveLimitations))
                    break;
            }
        }
        if (i == MAX_MON_MOVES)
            gAIScriptPtr += 8;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        moveLimitations = CheckMoveLimitations(gBattlerTarget, 0, MOVE_LIMITATION_PP);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (FOES_MOVE_HISTORY(gBattlerTarget)[i] == *movePtr)
            {
                s32 j;
                for (j = 0; j < MAX_MON_MOVES; j++)
                    if (FOES_MOVE_HISTORY(gBattlerTarget)[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
                        break;
                if (j != MAX_MON_MOVES)
                    break;
            }
        }
        if (i == MAX_MON_MOVES)
            gAIScriptPtr += 8;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
        break;
    }
}

static void Cmd_if_doesnt_have_move(void)
{
    s32 i;
    const u16 *movePtr = (u16 *)(gAIScriptPtr + 2);
    u8 moveLimitations;

    switch(gAIScriptPtr[1])
    {
    case AI_USER:
    case AI_USER_PARTNER: // UB: no separate check for user partner.
        moveLimitations = CheckMoveLimitations(sBattler_AI, 0, MOVE_LIMITATION_PP);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[sBattler_AI].moves[i] == *movePtr && !(gBitTable[i] & moveLimitations))
                break;
        }
        if (i != MAX_MON_MOVES)
            gAIScriptPtr += 8;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        moveLimitations = CheckMoveLimitations(gBattlerTarget, 0, MOVE_LIMITATION_PP);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (FOES_MOVE_HISTORY(gBattlerTarget)[i] == *movePtr)
            {
                s32 j;
                for (j = 0; j < MAX_MON_MOVES; j++)
                    if (FOES_MOVE_HISTORY(gBattlerTarget)[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
                        break;
                if (j != MAX_MON_MOVES)
                    break;
            }
        }
        if (i != MAX_MON_MOVES)
            gAIScriptPtr += 8;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
        break;
    }
}

static void Cmd_if_has_move_with_effect(void)
{
    s32 i;
    u8 moveLimitations;

    switch (gAIScriptPtr[1])
    {
    case AI_USER:
    case AI_USER_PARTNER:
        moveLimitations = CheckMoveLimitations(sBattler_AI, 0, MOVE_LIMITATION_PP);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[sBattler_AI].moves[i] != 0 && gBattleMoves[gBattleMons[sBattler_AI].moves[i]].effect == gAIScriptPtr[2] && !(gBitTable[i] & moveLimitations))
                break;
        }
        if (i == MAX_MON_MOVES)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        moveLimitations = CheckMoveLimitations(gBattlerTarget, 0, MOVE_LIMITATION_PP);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (FOES_MOVE_HISTORY(gBattlerTarget)[i] && gBattleMoves[FOES_MOVE_HISTORY(gBattlerTarget)[i]].effect == gAIScriptPtr[2])
            {
                s32 j;
                for (j = 0; j < MAX_MON_MOVES; j++)
                    if (FOES_MOVE_HISTORY(gBattlerTarget)[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
                        break;
                if (j != MAX_MON_MOVES)
                    break;
            }
        }
        if (i == MAX_MON_MOVES)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        break;
    }
}

static void Cmd_if_doesnt_have_move_with_effect(void)
{
    s32 i;
    u8 moveLimitations;

    switch (gAIScriptPtr[1])
    {
    case AI_USER:
    case AI_USER_PARTNER:
        moveLimitations = CheckMoveLimitations(sBattler_AI, 0, MOVE_LIMITATION_PP);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if(gBattleMons[sBattler_AI].moves[i] != 0 && gBattleMoves[gBattleMons[sBattler_AI].moves[i]].effect == gAIScriptPtr[2] && !(gBitTable[i] & moveLimitations))
                break;
        }
        if (i != MAX_MON_MOVES)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        moveLimitations = CheckMoveLimitations(gBattlerTarget, 0, MOVE_LIMITATION_PP);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (FOES_MOVE_HISTORY(gBattlerTarget)[i] && gBattleMoves[FOES_MOVE_HISTORY(gBattlerTarget)[i]].effect == gAIScriptPtr[2])
            {
                s32 j;
                for (j = 0; j < MAX_MON_MOVES; j++)
                    if (FOES_MOVE_HISTORY(gBattlerTarget)[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
                        break;
                if (j != MAX_MON_MOVES)
                    break;
            }
        }
        if (i != MAX_MON_MOVES)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        break;
    }
}

static void Cmd_if_any_move_disabled_or_encored(void)
{
    u8 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if (gAIScriptPtr[2] == 0)
    {
        if (gDisableStructs[battlerId].disabledMove == MOVE_NONE)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
    }
    else if (gAIScriptPtr[2] != 1)
    {
        gAIScriptPtr += 7;
    }
    else
    {
        if (gDisableStructs[battlerId].encoredMove != MOVE_NONE)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        else
            gAIScriptPtr += 7;
    }
}

static void Cmd_if_curr_move_disabled_or_encored(void)
{
    switch (gAIScriptPtr[1])
    {
    case 0:
        if (gDisableStructs[sBattler_AI].disabledMove == AI_THINKING_STRUCT->moveConsidered)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case 1:
        if (gDisableStructs[sBattler_AI].encoredMove == AI_THINKING_STRUCT->moveConsidered)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    default:
        gAIScriptPtr += 6;
        break;
    }
}

static void Cmd_flee(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_FLEE | AI_ACTION_DO_NOT_ATTACK);
}

static void Cmd_if_random_safari_flee(void)
{
    u8 safariFleeRate = gBattleStruct->safariEscapeFactor * 5; // Safari flee rate, from 0-20.

    if ((u8)(Random() % 100) < safariFleeRate)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_watch(void)
{
    AI_THINKING_STRUCT->aiAction |= (AI_ACTION_DONE | AI_ACTION_WATCH | AI_ACTION_DO_NOT_ATTACK);
}

static void Cmd_get_hold_effect(void)
{
    u8 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    AI_THINKING_STRUCT->funcResult = ItemId_GetHoldEffect(gBattleMons[battlerId].item);

    gAIScriptPtr += 2;
}

static void Cmd_if_holds_item(void)
{
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
	u16 item, var1, var2;

    if ((battlerId & BIT_SIDE) == (sBattler_AI & BIT_SIDE))
        item = gBattleMons[battlerId].item;
    else
        item = FOES_OBSERVED_ITEM_EFFECT(battlerId);

    var2 = gAIScriptPtr[2];
    var1 = gAIScriptPtr[3];
	var1 <<= 8;

    if ((var1 | var2) == item)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 4);
    else
        gAIScriptPtr += 8;
}

static void Cmd_get_gender(void)
{
    u8 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    AI_THINKING_STRUCT->funcResult = GetGenderFromSpeciesAndPersonality(gBattleMons[battlerId].species, gBattleMons[battlerId].personality);

    gAIScriptPtr += 2;
}

static void Cmd_is_first_turn_for(void)
{
    u8 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[battlerId].isFirstTurn;

    gAIScriptPtr += 2;
}

static void Cmd_get_stockpile_count(void)
{
    u8 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    AI_THINKING_STRUCT->funcResult = gDisableStructs[battlerId].stockpileCounter;

    gAIScriptPtr += 2;
}

static void Cmd_is_double_battle(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleTypeFlags & BATTLE_TYPE_DOUBLE;

    gAIScriptPtr += 1;
}

static void Cmd_get_used_held_item(void)
{
    u8 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    // This is likely a leftover from Ruby's code and its ugly ewram access.
    #ifdef NONMATCHING
        AI_THINKING_STRUCT->funcResult = gBattleStruct->usedHeldItems[battlerId];
    #else
        AI_THINKING_STRUCT->funcResult = *(u8*)((u8*)(gBattleStruct) + offsetof(struct BattleStruct, usedHeldItems) + (battlerId * 2));
    #endif // NONMATCHING

    gAIScriptPtr += 2;
}

static void Cmd_get_move_type_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].type;

    gAIScriptPtr += 1;
}

static void Cmd_get_move_power_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].power;

    gAIScriptPtr += 1;
}

static void Cmd_get_move_effect_from_result(void)
{
    AI_THINKING_STRUCT->funcResult = gBattleMoves[AI_THINKING_STRUCT->funcResult].effect;

    gAIScriptPtr += 1;
}

static void Cmd_get_protect_count(void)
{
    u8 battlerId;
    u16 lastMove;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    lastMove = gLastResultingMoves[battlerId];
    if (lastMove != MOVE_PROTECT && lastMove != MOVE_DETECT && lastMove != MOVE_ENDURE)
        AI_THINKING_STRUCT->funcResult = 0; // Si el último movimiento usado no fue uno de estos, no van a fallar estos movimientos
    else
        AI_THINKING_STRUCT->funcResult = gDisableStructs[battlerId].protectUses;

    gAIScriptPtr += 2;
}

static void Cmd_nullsub_52(void)
{
}

static void Cmd_nullsub_53(void)
{
}

static void Cmd_nullsub_54(void)
{
}

static void Cmd_nullsub_55(void)
{
}

static void Cmd_nullsub_56(void)
{
}

static void Cmd_nullsub_57(void)
{
}

static void Cmd_call(void)
{
    AIStackPushVar(gAIScriptPtr + 5);
    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
}

static void Cmd_goto(void)
{
    gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
}

static void Cmd_end(void)
{
    if (AIStackPop() == 0)
        AI_THINKING_STRUCT->aiAction |= AI_ACTION_DONE;
}

static void Cmd_if_level_cond(void)
{
    switch (gAIScriptPtr[1])
    {
    case AI_LEVEL_IS_GREATER_THAN_TARGETS:
        if (gBattleMons[sBattler_AI].level > gBattleMons[gBattlerTarget].level)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case AI_LEVEL_IS_LESS_THAN_TARGETS:
        if (gBattleMons[sBattler_AI].level < gBattleMons[gBattlerTarget].level)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case AI_LEVEL_IS_EQUAL_TO_TARGETS:
        if (gBattleMons[sBattler_AI].level == gBattleMons[gBattlerTarget].level)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case AI_LEVEL_IS_AT_MOST_2:
        if (gBattleMons[sBattler_AI].level <= 2)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    }
}

static void Cmd_if_target_taunted(void)
{
    if (gDisableStructs[gBattlerTarget].tauntTimer != 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_if_target_not_taunted(void)
{
    if (gDisableStructs[gBattlerTarget].tauntTimer == 0)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_if_target_is_ally(void)
{
    if ((sBattler_AI & BIT_SIDE) == (gBattlerTarget & BIT_SIDE))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_if_flash_fired(void)
{
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if (gBattleResources->flags->flags[battlerId] & RESOURCE_FLAG_FLASH_FIRE)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void AIStackPushVar(const u8 *var)
{
    gBattleResources->AI_ScriptsStack->ptr[gBattleResources->AI_ScriptsStack->size++] = var;
}

static void AIStackPushVar_cursor(void)
{
    gBattleResources->AI_ScriptsStack->ptr[gBattleResources->AI_ScriptsStack->size++] = gAIScriptPtr;
}

static bool8 AIStackPop(void)
{
    if (gBattleResources->AI_ScriptsStack->size != 0)
    {
        --gBattleResources->AI_ScriptsStack->size;
        gAIScriptPtr = gBattleResources->AI_ScriptsStack->ptr[gBattleResources->AI_ScriptsStack->size];
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static void Cmd_get_hazards_count(void)
{
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);
    u8 side = GetBattlerSide(battlerId);

    switch (T1_READ_16(gAIScriptPtr + 2))
    {
    case EFFECT_SPIKES:
        AI_THINKING_STRUCT->funcResult = gSideTimers[side].spikesAmount;
        break;
    }

    gAIScriptPtr += 4;
}

static void Cmd_get_curr_dmg_hp_percent(void)
{
    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;
    CalculategBattleMoveDamageFromgCurrentMove(sBattler_AI, gBattlerTarget, AI_THINKING_STRUCT->simulatedRNG[AI_THINKING_STRUCT->movesetIndex]);
    
	gBattleResources->ai->funcResult = (gBattleMoveDamage * 100) / gBattleMons[gBattlerTarget].maxHP;
	gAIScriptPtr++;
}

static void Cmd_if_accuracy_less_than(void)
{
    u8 type, finalAcc, evasion;
    s8 buff;
    u16 move = AI_THINKING_STRUCT->moveConsidered;
    u16 accuracy = gBattleMoves[move].accuracy;

    gAIScriptPtr += 6; // asume que la precisión no es menor (no salta) hasta que se observe lo contrario
    if (accuracy == 0)
        return;
    // Comprueba distintas situaciones en las que los movs no fallan o pierden precisión
    // Se ignoran algunas cosas porque afectan por igual a todos los movimientos
    // o porque la IA no las sabe (Sand Veil, BrightPowder...)

    // Lock-On, Mind Reader
    if (gStatuses3[gBattlerTarget] & STATUS3_ALWAYS_HITS && gDisableStructs[gBattlerTarget].battlerWithSureHit == sBattler_AI)
        return;
    // No Guard
    if (gBattleMons[gBattlerTarget].ability == ABILITY_NO_GUARD || gBattleMons[sBattler_AI].ability == ABILITY_NO_GUARD)
        return;

    // ataques que cambian de precisión en clima
    if (WEATHER_HAS_EFFECT) {
        if (gBattleMoves[move].effect == EFFECT_THUNDER) {
            if (gBattleWeather & WEATHER_RAIN_ANY)
                return;
            if (gBattleWeather & WEATHER_SUN_ANY)
                accuracy = 50;
        }
        else if ((gBattleWeather & WEATHER_HAIL_ANY) && move == MOVE_BLIZZARD)
            return;
    }

    // Comprueba cambios de stats en Precisión y Evasión
    evasion = gBattleMons[gBattlerTarget].statStages[STAT_EVASION];
    if (gBattleMons[sBattler_AI].ability == ABILITY_KEEN_EYE && evasion > 6)
        evasion = 6;

 if (gBattleMons[gBattlerTarget].status2 & STATUS2_FORESIGHT)
    {
        u8 acc = gBattleMons[sBattler_AI].statStages[STAT_ACC];
        buff = acc; // ignora la Evasión del rival (sí, aunque sea negativa)
    }
    else
    {
        u8 acc = gBattleMons[sBattler_AI].statStages[STAT_ACC];
        buff = acc + 6 - evasion;
    }

    if (buff < 0)   buff = 0;
    if (buff > 0xC) buff = 0xC;

    // Solo se tiene en cuenta una menor precisión si estamos comparando con precisión 100
    if (sAccuracyStageRatios[buff].dividend >= sAccuracyStageRatios[buff].divisor || gAIScriptPtr[1] == 100)
        accuracy = (sAccuracyStageRatios[buff].dividend * accuracy) / sAccuracyStageRatios[buff].divisor;

    if (gBattleMons[sBattler_AI].ability == ABILITY_COMPOUND_EYES)
        accuracy = (accuracy * 13) / 10;
    GET_MOVE_TYPE(move, type);
    if (gBattleMons[sBattler_AI].ability == ABILITY_HUSTLE && IS_TYPE_PHYSICAL(type) && gBattleMoves[move].power > 0)
        accuracy = (accuracy * 4) / 5;

    // Determina si la precisión es menor que la pedida
    finalAcc = (u8) accuracy;
    if (accuracy < 0x100 && finalAcc < gAIScriptPtr[1])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
}

static void Cmd_if_not_expected_to_sleep(void)
{
    if (NOT_EXPECTED_TO_SLEEP_DURING_NEXT_TURN(sBattler_AI))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_if_receiving_wish(void)
{
    u16 battlerId;

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

    if (gWishFutureKnock.wishCounter[battlerId])
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

// Salta si, en el próximo turno, el rival no podrá atacar debido a Truant
static void Cmd_if_target_wont_attack_due_to_truant(void)
{
    if (gBattleMons[gBattlerTarget].ability == ABILITY_TRUANT && gDisableStructs[gBattlerTarget].truantCounter)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_if_trick_fails_in_this_type_of_battle(void)
{
    // No one can swap items in regular trainer battles
    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL
        || gBossBattleFlags != BATTLE_TYPE_NORMAL
        || !(!(gBattleTypeFlags & BATTLE_TYPE_TRAINER) 
        ||  FlagGet(FLAG_RYU_RANDOMBATTLECC) == 1 
        || (gBattleTypeFlags & (BATTLE_TYPE_LINK
                                  | BATTLE_TYPE_EREADER_TRAINER
                                  | BATTLE_TYPE_FRONTIER
                                  | BATTLE_TYPE_SECRET_BASE
                                  | BATTLE_TYPE_x2000000))))
    {
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    }
    else
        gAIScriptPtr += 5;
}

// Calcula el mejor nHKO que puede hacerle un poke a otro
// Se calcula de forma notablemente distinta según si el poke en cuestión es conocido por la IA o no
// consideredMove puede ser MOVE_NONE para que evalúe todos los movimientos
// (todos los movimientos conocidos y esperados, si no se conocen los movimientos del atacante)
s32 CalculateNHKO(u16 attackerId, u16 targetId, bool8 attackerIsCurrentAI, u16 consideredMove, bool8 assumeWorstCaseScenario, bool8 ignoreFocusPunch)
{
    const u16 * movePointer;
	bool8 check_only_considered_move = (consideredMove != MOVE_NONE);
    s32 i;
    s32 best_nhko = 5;     // todo lo que sea peor que 4HKO se lee como 5HKO (incluso daño 0)
	u16 savedCurrentMove = gCurrentMove;
 
    if (check_only_considered_move)
        movePointer = &consideredMove;
    else if (attackerIsCurrentAI)
        movePointer = gBattleMons[attackerId].moves;
    else
        movePointer = FOES_MOVE_HISTORY(attackerId);
 
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (!movePointer[i] || !AI_CAN_ESTIMATE_DAMAGE(movePointer[i]))
            continue;  // se ignora el movimiento

        if (!check_only_considered_move && (gBattleMoves[movePointer[i]].effect == EFFECT_EXPLOSION || (ignoreFocusPunch && movePointer[i] == MOVE_FOCUS_PUNCH)))
            continue;

        if (!check_only_considered_move)
        {
			u8 moveLimitations = CheckMoveLimitations(attackerId, 0, MOVE_LIMITATION_CHOICE-1);
            s32 j;
            for (j = 0; j < MAX_MON_MOVES; j++)
			if (movePointer[i] == gBattleMons[attackerId].moves[j] && !(gBitTable[j] & moveLimitations))
                    break;
            if (j == MAX_MON_MOVES)
                continue; // No puede usar el movimiento por el momento; se ignora

			if ((gBattleMons[attackerId].status2 & STATUS2_MULTIPLETURNS) && movePointer[i] != gLastMoves[attackerId])
                continue; // Está en un ataque multiturno distinto de este; se ignora
		}

        gCurrentMove = movePointer[i];
		best_nhko = CalculatenHKOFromgCurrentMove(attackerId, targetId, (assumeWorstCaseScenario || (!attackerIsCurrentAI && check_only_considered_move)) ? 0 : (AI_THINKING_STRUCT->simulatedRNG[check_only_considered_move ? AI_THINKING_STRUCT->movesetIndex : i]), best_nhko);

        if (check_only_considered_move || best_nhko == 1)
            break; // solo se mira el movimiento pensado, y no se sigue mirando si es OHKO
    }

    // Si el atacante es el oponente, no se conocen todos sus movs y no da OHKO,
    // la IA puede asumir que los STAB estándar (de precisión alta)
    // y ataques típicos de la especie pueden ser los movs que faltan
    // siempre que esté en condiciones de usar un ataque nuevo
    if (!attackerIsCurrentAI && !check_only_considered_move && best_nhko > 1
        && gDisableStructs[attackerId].encoredMove == MOVE_NONE
        && !(gBattleMons[attackerId].status2 & (STATUS2_RECHARGE | STATUS2_MULTIPLETURNS))
        && gBattleMons[attackerId].species != SPECIES_DITTO
        && gBattleMons[attackerId].species != SPECIES_WOBBUFFET
        && gBattleMons[attackerId].species != SPECIES_WYNAUT
        && !(gBattleMons[attackerId].species == SPECIES_UNOWN && movePointer[0] == MOVE_HIDDEN_POWER))
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
            if (!movePointer[i]) // hay un ataque no conocido
                break;
        
        if (i != MAX_MON_MOVES) // algún ataque no se conoce
        {
            s32 type_i;
			u8 opponent_types[2] = {gBaseStats[gBattleMons[attackerId].species].type1, gBaseStats[gBattleMons[attackerId].species].type2};
            s16 standard_moves[] = {
                [TYPE_NORMAL] = MOVE_EGG_BOMB,       // prácticamente la misma potencia que Return/Frustration al máximo
                [TYPE_FIGHTING] = MOVE_SKY_UPPERCUT, // los movs más potentes son más arriesgados
                [TYPE_FLYING] = MOVE_DRILL_PECK,
                [TYPE_POISON] = MOVE_SLUDGE_BOMB,
                [TYPE_GROUND] = MOVE_EARTHQUAKE,
                [TYPE_ROCK] = MOVE_ROCK_SLIDE,       // se considera arriesgado Stone Edge
                [TYPE_BUG] = MOVE_X_SCISSOR,
                [TYPE_GHOST] = MOVE_SHADOW_BALL,
                [TYPE_STEEL] = MOVE_IRON_HEAD,
                [TYPE_FIRE] = MOVE_FLAMETHROWER,
                [TYPE_WATER] = MOVE_SURF,
                [TYPE_GRASS] = MOVE_ENERGY_BALL,
                [TYPE_ELECTRIC] = MOVE_THUNDERBOLT,
                [TYPE_PSYCHIC] = MOVE_PSYCHIC,
                [TYPE_ICE] = MOVE_ICE_BEAM,
                [TYPE_DRAGON] = MOVE_DRAGON_CLAW,
                [TYPE_DARK] = MOVE_CRUNCH,
                [TYPE_FAIRY] = MOVE_MOONBLAST,
            };

            if (opponent_types[1] == opponent_types[0])
                opponent_types[1] = TYPE_NONE;

            for (type_i = 0; type_i < 2 && opponent_types[type_i] != TYPE_NONE; type_i++)
            {
                u8 stab_type = opponent_types[type_i];

                // Comprueba que no se conoce un ataque de ese tipo (de potencia mayor que 40) en el rival
                for (i = 0; i < MAX_MON_MOVES; i++)
                    if (movePointer[i] && gBattleMoves[movePointer[i]].type == stab_type && gBattleMoves[movePointer[i]].power > 40)
                        break;
                if (i == MAX_MON_MOVES)
                {
                    // Procede a considerar un ataque STAB estándar de este tipo
                    gCurrentMove = standard_moves[stab_type];
                    best_nhko = CalculatenHKOFromgCurrentMove(attackerId, targetId, 0, best_nhko);
                    if (best_nhko == 1)
                        break; // el presunto ataque STAB es OHKO: no hace falta comprobar el otro tipo STAB si lo hay
                }
            }
			
			// Si sigue sin ser OHKO, la IA tiene una cierta probabilidad de considerar los
            // movimientos típicos de la especie del poke rival.
            // Lo hace casi seguramente (31/32) si se exige a la IA ser pesimista
            // (por ejemplo, para asegurarse del todo de que puede hincharse a boosts),
            // lo hace con probabilidad muy alta (7/8) si el rival acaba de entrar pero
            // el poke de la IA no (es decir, el rival entró sabiendo el poke de la IA)
            // ya que si entró será por algo, y lo hace a veces (1/2) en el resto de casos
            if (best_nhko > 1 && Random() % (assumeWorstCaseScenario ? 32 : ((gDisableStructs[attackerId].isFirstTurn && !(gDisableStructs[targetId].isFirstTurn)) ? 8 : 2)) != 0)
            {
                const u16 * probable_moves = sProbablePowerfulOrNonSTABMoves[gBattleMons[attackerId].species];
                s32 move_i;

                // Evalúa cada uno de los ataques probables de la especie
                for (move_i = 0; move_i < MAX_PROBABLE_MOVES && probable_moves[move_i] != MOVE_NONE; move_i++)
                {
                    gCurrentMove = probable_moves[move_i];
                    best_nhko = CalculatenHKOFromgCurrentMove(attackerId, targetId, 0, best_nhko);
                    if (best_nhko == 1)
                        break; // el presunto ataque es OHKO, no hace falta seguir mirando
                }
            }
        }
    }
		gCurrentMove = savedCurrentMove;
    if (((gBattleMons[attackerId].status2 & STATUS2_RECHARGE) || gDisableStructs[attackerId].truantCounter) && best_nhko < 5)
        best_nhko += 1;
    return best_nhko;
}

static void Cmd_calculate_nhko(void)
{
    u16 attackerId, targetId;
    bool8 attackerIsCurrentAI = (gAIScriptPtr[1] & (~AI_NHKO_PESSIMISTIC)) == AI_USER;
    u16 consideredMove = MOVE_NONE;
    bool8 assumeWorstCaseScenario = gAIScriptPtr[1] & AI_NHKO_PESSIMISTIC;
	bool8 ignoreFocusPunch = attackerIsCurrentAI || AI_CAN_ESTIMATE_DAMAGE(AI_THINKING_STRUCT->moveConsidered);

    if (attackerIsCurrentAI)
    {
        attackerId = sBattler_AI;
        targetId = gBattlerTarget;
        // Si la IA está considerando un movimiento de daño, se evalúa solo ese.
        // En caso contrario, se consideran todos los (demás) movimientos que conoce
        if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power != 0)
            consideredMove = AI_THINKING_STRUCT->moveConsidered;
    }
    else
    {
        attackerId = gBattlerTarget;
        targetId = sBattler_AI;
    }

    // Calcula el nHKO y lo guarda en funcResult, con lo que se puede consultar su valor
    // usando comandos de la IA como if_equal, if_less_than, etc
	AI_THINKING_STRUCT->funcResult = CalculateNHKO(attackerId, targetId, attackerIsCurrentAI, consideredMove, assumeWorstCaseScenario, ignoreFocusPunch);
    gAIScriptPtr += 2;
}

static void Cmd_if_next_turn_target_might_use_move_with_effect(void)
{
    s32 i;
    u8 moveLimitations = CheckMoveLimitations(gBattlerTarget, 0, MOVE_LIMITATION_CHOICE-1);
    u8 effect = *(gAIScriptPtr + 1);
    bool8 allMovesKnown = TRUE; // se cambiará a FALSE si no es cierto

    gAIScriptPtr += 6; // será sobreescrito si el objetivo sí podrá usar un movimiento con el efecto

    if (effect == AI_LAST_EFFECT_BY_TARGET)
    {
        if (gLastMoves[gBattlerTarget] == MOVE_NONE || gLastMoves[gBattlerTarget] == 0xFFFF)
            return;
        effect = gBattleMoves[gLastMoves[gBattlerTarget]].effect;
    }

    if (gBattleMons[gBattlerTarget].status2 & STATUS2_RECHARGE)
        return; // estará descansando por Hiperrayo o similar

    if (gBattleMons[gBattlerTarget].status2 & STATUS2_MULTIPLETURNS)
        return; // está en un ataque multiturno. (Se asume que no se está preguntando por ese mismo ataque multiturno)

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (!FOES_MOVE_HISTORY(gBattlerTarget)[i])
            allMovesKnown = FALSE;
        else if (gBattleMoves[FOES_MOVE_HISTORY(gBattlerTarget)[i]].effect == effect)
        {
            s32 j;
            for (j = 0; j < MAX_MON_MOVES; j++)
                if (FOES_MOVE_HISTORY(gBattlerTarget)[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
                    break;
            if (j != MAX_MON_MOVES)
                break;
        }
    }

    // Si el rival es un Smeargle que nos ha hecho Lock-On, es muy evidente lo que va a pasar.
    // La IA asumirá que está a punto de recibir un movimiento OHKO compatible
    // salvo si ya conoce los movimientos que puede usar y no es posible tal cosa,
    // o si la habilidad del mon de la IA es Sturdy, o Wonder Guard en un Shedinja,
    // o la diferencia de niveles impide que funcione el movimiento OHKO
    if (i == MAX_MON_MOVES
        && effect == EFFECT_OHKO
        && !allMovesKnown
        && (gStatuses3[sBattler_AI] & STATUS3_ALWAYS_HITS)
        && gDisableStructs[sBattler_AI].battlerWithSureHit == gBattlerTarget
        && gBattleMons[gBattlerTarget].species == SPECIES_SMEARGLE
        && gBattleMons[sBattler_AI].level <= gBattleMons[gBattlerTarget].level
        && gBattleMons[sBattler_AI].ability != ABILITY_STURDY
        && !(gBattleMons[sBattler_AI].ability == ABILITY_WONDER_GUARD
             && gBattleMons[sBattler_AI].species == SPECIES_SHEDINJA
            ))
            i = 0; // se asume que OHKO al canto

    if (i != MAX_MON_MOVES)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr - 4);
}

static void Cmd_if_battler_absent(void)
{
    u32 battler = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if (!IsBattlerAlive(battler))
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
    else
        gAIScriptPtr += 6;
}

static void Cmd_get_possible_categories_of_foes_attacks(void)
{
    s32 i, j;
    bool8 physical_move_known = FALSE;
    bool8 special_move_known = FALSE;
    bool8 all_moves_known = TRUE;
    u8 result;
    
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u16 move = FOES_MOVE_HISTORY(gBattlerTarget)[i];
        if (!move)
            all_moves_known = FALSE;
        else if (AI_CAN_ESTIMATE_DAMAGE(move)) // hay mov de daño y no es Counter/Mirror Coat/Bide/OHKO
        {
            u8 moveLimitations = CheckMoveLimitations(gBattlerTarget, 0, MOVE_LIMITATION_CHOICE-1);
            u8 type = gBattleMoves[move].type;

            for (j = 0; j < MAX_MON_MOVES; j++)
                      if (move == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
                    break;
            if (j == MAX_MON_MOVES)
                continue; // No puede usar el movimiento por el momento; se ignora

                  if ((gBattleMons[gBattlerTarget].status2 & STATUS2_MULTIPLETURNS) && move != gLastMoves[gBattlerTarget])
                continue; // Está en un ataque multiturno distinto de este; se ignora

            // Comprueba el tipo
			if (move == MOVE_HIDDEN_POWER || move == MOVE_MONADO_POWER)
            {
                struct Pokemon *monAttacker;
                if (GetBattlerSide(gBattlerTarget) == B_SIDE_PLAYER)
                    monAttacker = &gPlayerParty[gBattlerPartyIndexes[gBattlerTarget]];
                else
                    monAttacker = &gEnemyParty[gBattlerPartyIndexes[gBattlerTarget]];

                type = monAttacker->box.hpType;
            }
            else if (move == MOVE_WEATHER_BALL && WEATHER_HAS_EFFECT)
            {
                if (gBattleWeather & WEATHER_RAIN_ANY)
                    type = TYPE_WATER;
                else if (gBattleWeather & WEATHER_SANDSTORM_ANY)
                    type = TYPE_ROCK;
                else if (gBattleWeather & WEATHER_SUN_ANY)
                    type = TYPE_FIRE;
                else if (gBattleWeather & WEATHER_HAIL_ANY)
                    type = TYPE_ICE;
            }

            // Comprueba que el poke de la IA no es inmune al tipo del movimiento
            gCurrentMove = move;
            CalculategBattleMoveDamageFromgCurrentMove(gBattlerTarget, sBattler_AI, 0);
            if (gBattleMoveDamage == 0)
                continue;

            // Lee la categoría del tipo
            if (IS_TYPE_PHYSICAL(type))
                physical_move_known = TRUE;
            else
                special_move_known = TRUE;
            }
    }
    
    if (physical_move_known)
    {
        if (special_move_known)
            result = AI_BOTH_PHYSICAL_AND_SPECIAL;
        else if (all_moves_known)
            result = AI_PHYSICAL_ONLY;
        else
            result = AI_ONLY_PHYSICAL_KNOWN;
    }
    else if (special_move_known)
    {
        if (all_moves_known)
            result = AI_SPECIAL_ONLY;
        else
		result = AI_ONLY_SPECIAL_KNOWN;
    }
    else if (all_moves_known || gBattleMons[gBattlerTarget].species == SPECIES_WOBBUFFET || gBattleMons[gBattlerTarget].species == SPECIES_WYNAUT)
        result = AI_NO_DAMAGING_MOVES;
    else
    {
        u16 base_attack = gBaseStats[gBattleMons[gBattlerTarget].species].baseAttack;
        u16 base_sp_attack = gBaseStats[gBattleMons[gBattlerTarget].species].baseSpAttack;
        if (base_attack * 4 < base_sp_attack * 3 && base_attack < 100)
            result = AI_UNKNOWN_CATEGORIES_PROBABLY_SPECIAL;
        else if (base_sp_attack * 4 < base_attack * 3 && base_sp_attack < 100)
            result = AI_UNKNOWN_CATEGORIES_PROBABLY_PHYSICAL;
        else
            result = AI_UNKNOWN_CATEGORIES;
    }

    gBattleResources->ai->funcResult = result;
    gAIScriptPtr++;
}

static void Cmd_if_perish_song_not_about_to_trigger(void)
{
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if ((gStatuses3[battlerId] & STATUS3_PERISH_SONG) && gDisableStructs[battlerId].perishSongTimer == 0)
        gAIScriptPtr += 6;
    else
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
}

static void Cmd_if_high_change_to_break_sub_and_keep_hitting(void)
{
    u16 move = AI_THINKING_STRUCT->moveConsidered;
    u16 effect = gBattleMoves[move].effect;
    u16 target_damage = gDisableStructs[gBattlerTarget].substituteHP;

    gAIScriptPtr += 5; // luego se deshace si hay que saltar

    if (!AI_CAN_ESTIMATE_DAMAGE(move) || !(gBattleMons[gBattlerTarget].status2 & STATUS2_SUBSTITUTE) || !gDisableStructs[gBattlerTarget].substituteHP)
        return;

    switch (effect)
    {
        case EFFECT_MULTI_HIT:
        case EFFECT_TWINEEDLE:
        case EFFECT_DOUBLE_HIT:
        case EFFECT_TRIPLE_KICK:
            break;
        default:
            return;
    }

    gCurrentMove = move;
    CalculategBattleMoveDamageFromgCurrentMove(sBattler_AI, gBattlerTarget, AI_THINKING_STRUCT->simulatedRNG[AI_THINKING_STRUCT->movesetIndex]);

    switch (effect)
    {
        case EFFECT_MULTI_HIT: // mira si 2 golpes bastan para romper el sub
            gBattleMoveDamage = (gBattleMoveDamage / 3) * 2;
            break;
        case EFFECT_TWINEEDLE:
        case EFFECT_DOUBLE_HIT: // mira si el primer golpe rompe el sub
        case EFFECT_TRIPLE_KICK: // mira si los dos primeros golpes rompen el sub
            gBattleMoveDamage /= 2;
            break;
    }

    if (target_damage <= gBattleMoveDamage)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr - 4);
}

static void Cmd_if_user_has_revealed_move(void)
{
    s32 i;
    u16 move = T1_READ_16(gAIScriptPtr + 1);

    for (i = 0; i < MAX_MON_MOVES; i++)
        //if (FOES_MOVE_HISTORY(sBattler_AI)[i] == move) // esto serviría si se registrasen los ataques que va usando la IA, pero no es el caso en general
        // Lo siguiente puede fallar si el rival ha visto el movimiento de otra forma (Transform)
        // o si tiene 10 o menos PP máximos y se recuperó con Leppa Berry
        if (gBattleMons[sBattler_AI].moves[i] == move && gBattleMons[sBattler_AI].pp[i] < CalculatePPWithBonus(move, gBattleMons[sBattler_AI].ppBonuses, i))
            break;

    if (i == MAX_MON_MOVES)
        gAIScriptPtr += 7;
    else
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
}

static void Cmd_if_has_non_ineffective_move_with_effect(void)
{
    s32 i;
    u8 moveLimitations;

    switch (gAIScriptPtr[1])
    {
    case AI_USER:
    case AI_USER_PARTNER:
        if (gAIScriptPtr[2] == EFFECT_OHKO && (gBattleMons[sBattler_AI].level < gBattleMons[gBattlerTarget].level || gBattleMons[gBattlerTarget].ability == ABILITY_STURDY))
        {
            gAIScriptPtr += 7;
            break;
        }
            
        moveLimitations = CheckMoveLimitations(sBattler_AI, 0, MOVE_LIMITATION_PP);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[sBattler_AI].moves[i] != 0 && gBattleMoves[gBattleMons[sBattler_AI].moves[i]].effect == gAIScriptPtr[2]
                && !(gBitTable[i] & moveLimitations) && CalculateDamageFromMove(sBattler_AI, gBattlerTarget, gBattleMons[sBattler_AI].moves[i], 0) > 0)
                break;
        }
        if (i == MAX_MON_MOVES)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        if (gAIScriptPtr[2] == EFFECT_OHKO && (gBattleMons[gBattlerTarget].level < gBattleMons[sBattler_AI].level || gBattleMons[sBattler_AI].ability == ABILITY_STURDY))
        {
            gAIScriptPtr += 7;
            break;
        }

        moveLimitations = CheckMoveLimitations(gBattlerTarget, 0, MOVE_LIMITATION_PP);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (FOES_MOVE_HISTORY(gBattlerTarget)[i] && gBattleMoves[FOES_MOVE_HISTORY(gBattlerTarget)[i]].effect == gAIScriptPtr[2])
            {
                s32 j;
                for (j = 0; j < MAX_MON_MOVES; j++)
                    if (FOES_MOVE_HISTORY(gBattlerTarget)[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
                        break;
                if (j != MAX_MON_MOVES && CalculateDamageFromMove(gBattlerTarget, sBattler_AI, gBattleMons[gBattlerTarget].moves[j], 0) > 0)
                    break;
            }
        }
        if (i == MAX_MON_MOVES)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        break;
    }
}

static void Cmd_if_doesnt_have_non_ineffective_move_with_effect(void)
{
    s32 i;
    u8 moveLimitations;

    switch (gAIScriptPtr[1])
    {
    case AI_USER:
    case AI_USER_PARTNER:
        if (gAIScriptPtr[2] == EFFECT_OHKO && (gBattleMons[sBattler_AI].level < gBattleMons[gBattlerTarget].level || gBattleMons[gBattlerTarget].ability == ABILITY_STURDY))
        {
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
            break;
        }
        moveLimitations = CheckMoveLimitations(sBattler_AI, 0, MOVE_LIMITATION_PP);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (gBattleMons[sBattler_AI].moves[i] != 0 && gBattleMoves[gBattleMons[sBattler_AI].moves[i]].effect == gAIScriptPtr[2]
                && !(gBitTable[i] & moveLimitations) && CalculateDamageFromMove(sBattler_AI, gBattlerTarget, gBattleMons[sBattler_AI].moves[i], 0) > 0)
                break;
        }
        if (i != MAX_MON_MOVES)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        break;
    case AI_TARGET:
    case AI_TARGET_PARTNER:
        if (gAIScriptPtr[2] == EFFECT_OHKO && (gBattleMons[gBattlerTarget].level < gBattleMons[sBattler_AI].level || gBattleMons[sBattler_AI].ability == ABILITY_STURDY))
        {
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
            break;
        }

        moveLimitations = CheckMoveLimitations(gBattlerTarget, 0, MOVE_LIMITATION_PP);
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (FOES_MOVE_HISTORY(gBattlerTarget)[i] && gBattleMoves[FOES_MOVE_HISTORY(gBattlerTarget)[i]].effect == gAIScriptPtr[2])
            {
                s32 j;
                for (j = 0; j < MAX_MON_MOVES; j++)
                    if (FOES_MOVE_HISTORY(gBattlerTarget)[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
                        break;
                if (j != MAX_MON_MOVES && CalculateDamageFromMove(gBattlerTarget, sBattler_AI, gBattleMons[gBattlerTarget].moves[j], 0) > 0)
                    break;
            }
        }
        if (i != MAX_MON_MOVES)
            gAIScriptPtr += 7;
        else
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 3);
        break;
    }
}

static void Cmd_if_move_is_contactless(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].flags & FLAG_MAKES_CONTACT)
        gAIScriptPtr += 5;
    else
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
}

static void Cmd_if_target_will_be_faster_after_this_effect(void)
{
    bool8 target_will_be_faster;
    const s8 aiSpeedStage     = gBattleMons[sBattler_AI].statStages[STAT_SPEED],
             targetSpeedStage = gBattleMons[gBattlerTarget].statStages[STAT_SPEED];
    const u16 weather = gBattleWeather;
    const u32 aiStatus1     = gBattleMons[sBattler_AI].status1,
              targetStatus1 = gBattleMons[gBattlerTarget].status1;

    // Simula el efecto de cambio de Velocidad por el ataque en cuestión.
    // Asume que se ejecuta con éxito (no hay fallo ni inmunidad) y nada impide el efecto
    // (sustituto, Neblina, Clear Body, White Smoke o Shield Dust) excepto estar a +6 o -6.
    // Ignora movimientos que podrían bajar Velocidad pero de forma no garantizada
    switch(gBattleMoves[AI_THINKING_STRUCT->moveConsidered].effect)
    {
        case EFFECT_CURSE:
            if (!IS_BATTLER_OF_TYPE(sBattler_AI, TYPE_GHOST) && aiSpeedStage != 0)
                gBattleMons[sBattler_AI].statStages[STAT_SPEED] -= 1;
            break;
        case EFFECT_SPEED_UP:
        case EFFECT_DRAGON_DANCE:
        case EFFECT_QUIVER_DANCE:
        case EFFECT_RAPID_SPIN:
        case EFFECT_MIDELE_POWER:
            if (aiSpeedStage != 12)
                gBattleMons[sBattler_AI].statStages[STAT_SPEED] += 1;
            break;
        case EFFECT_SPEED_UP_2:
            if (aiSpeedStage <= 10)
                gBattleMons[sBattler_AI].statStages[STAT_SPEED] += 2;
            else
                gBattleMons[sBattler_AI].statStages[STAT_SPEED] = 12;
            break;
        case EFFECT_SPEED_DOWN_HIT:
            if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].secondaryEffectChance != 100)
                break;
            // continúa si tiene 100% de bajar Velocidad
        case EFFECT_SPEED_DOWN:
            if (aiSpeedStage != 0)
                gBattleMons[gBattlerTarget].statStages[STAT_SPEED] -= 1;
            break;
        case EFFECT_SPEED_DOWN_2:
            if (targetSpeedStage >= 2)
                gBattleMons[gBattlerTarget].statStages[STAT_SPEED] -= 2;
            else
                gBattleMons[gBattlerTarget].statStages[STAT_SPEED] = 0;
            break;
        case EFFECT_HAZE:
            gBattleMons[sBattler_AI].statStages[STAT_SPEED] = gBattleMons[gBattlerTarget].statStages[STAT_SPEED] = 6;
            break;
        case EFFECT_RAIN_DANCE:
            gBattleWeather = WEATHER_RAIN_ANY;
            break;
        case EFFECT_SUNNY_DAY:
            gBattleWeather = WEATHER_SUN_ANY;
            break;
        case EFFECT_SANDSTORM:
            gBattleWeather = WEATHER_SANDSTORM_ANY;
            break;
        case EFFECT_HAIL:
            gBattleWeather = WEATHER_HAIL_ANY;
            break;
        case EFFECT_REFRESH:
        case EFFECT_HEAL_BELL:
            if (aiStatus1 & STATUS1_PARALYSIS)
                gBattleMons[sBattler_AI].status1 &= ~(STATUS1_PARALYSIS);
            break;
        case EFFECT_PARALYZE:
            if (!targetStatus1)
                gBattleMons[gBattlerTarget].status1 = STATUS1_PARALYSIS;
            break;
    }

    // Tiene en cuenta habilidades también, como Speed Boost o Gooey.
    // La adivina si es la única habilidad posible del rival, pero no por ejemplo en Yanmega
    if (gBattleMons[sBattler_AI].ability == ABILITY_SPEED_BOOST && gBattleMons[sBattler_AI].statStages[STAT_SPEED] != 12)
        gBattleMons[sBattler_AI].statStages[STAT_SPEED] += 1;

    if ((FOES_OBSERVED_ABILITY(gBattlerTarget) == ABILITY_SPEED_BOOST || (FOES_OBSERVED_ABILITY(gBattlerTarget) == ABILITY_NONE && GetAbilityBySpecies(gBattleMons[gBattlerTarget].species, 0) == ABILITY_SPEED_BOOST && (GetAbilityBySpecies(gBattleMons[gBattlerTarget].species, 1) == ABILITY_SPEED_BOOST || GetAbilityBySpecies(gBattleMons[gBattlerTarget].species, 1) == ABILITY_NONE))) && gBattleMons[gBattlerTarget].statStages[STAT_SPEED] != 12)
        gBattleMons[gBattlerTarget].statStages[STAT_SPEED] += 1;

    if ((gBattleMoves[AI_THINKING_STRUCT->moveConsidered].flags & FLAG_MAKES_CONTACT) && (
             FOES_OBSERVED_ABILITY(gBattlerTarget) == ABILITY_GOOEY
         || (FOES_OBSERVED_ABILITY(gBattlerTarget) == ABILITY_NONE && GetAbilityBySpecies(gBattleMons[gBattlerTarget].species, 0) == ABILITY_GOOEY && (GetAbilityBySpecies(gBattleMons[gBattlerTarget].species, 1) == ABILITY_GOOEY || GetAbilityBySpecies(gBattleMons[gBattlerTarget].species, 1) == ABILITY_NONE))
         || FOES_OBSERVED_ABILITY(gBattlerTarget) == ABILITY_TANGLING_HAIR
         || (FOES_OBSERVED_ABILITY(gBattlerTarget) == ABILITY_NONE && GetAbilityBySpecies(gBattleMons[gBattlerTarget].species, 0) == ABILITY_TANGLING_HAIR && (GetAbilityBySpecies(gBattleMons[gBattlerTarget].species, 1) == ABILITY_TANGLING_HAIR || GetAbilityBySpecies(gBattleMons[gBattlerTarget].species, 1) == ABILITY_NONE))
        ) && gBattleMons[sBattler_AI].statStages[STAT_SPEED] != 0)
        gBattleMons[sBattler_AI].statStages[STAT_SPEED] -= 1;

    target_will_be_faster = GetWhoStrikesFirst(sBattler_AI, gBattlerTarget, TRUE) != 0;

    gBattleMons[sBattler_AI].statStages[STAT_SPEED] = aiSpeedStage;
    gBattleMons[gBattlerTarget].statStages[STAT_SPEED] = targetSpeedStage;
    gBattleMons[sBattler_AI].status1 = aiStatus1;
    gBattleMons[gBattlerTarget].status1 = targetStatus1;
    gBattleWeather = weather;

    if (target_will_be_faster)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_get_weather_at_the_end_of_turn(void)
{
	AI_THINKING_STRUCT->funcResult = AI_WEATHER_NONE;

    if (gWishFutureKnock.weatherDuration != 1 || (gBattleWeather & (WEATHER_RAIN_PERMANENT | WEATHER_SANDSTORM_PERMANENT | WEATHER_SUN_PERMANENT | WEATHER_HAIL_PERMANENT)))
    {
        if (gBattleWeather & WEATHER_RAIN_ANY)
            AI_THINKING_STRUCT->funcResult = AI_WEATHER_RAIN;
        if (gBattleWeather & WEATHER_SANDSTORM_ANY)
            AI_THINKING_STRUCT->funcResult = AI_WEATHER_SANDSTORM;
        if (gBattleWeather & WEATHER_SUN_ANY)
            AI_THINKING_STRUCT->funcResult = AI_WEATHER_SUN;
        if (gBattleWeather & WEATHER_HAIL_ANY)
            AI_THINKING_STRUCT->funcResult = AI_WEATHER_HAIL;
    }

    gAIScriptPtr += 1;
}

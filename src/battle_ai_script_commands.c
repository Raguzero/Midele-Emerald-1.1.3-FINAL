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
#include "constants/moves.h"
#include "constants/species.h"
#include "sound.h"

#define __DEBUG_AI__ 1
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
static void RecordLastUsedMoveByTarget(void);
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
static void Cmd_if_user_has_attacking_move(void);
static void Cmd_if_user_has_no_attacking_moves(void);
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
static void Cmd_if_can_faint(void);
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
static void Cmd_is_of_type(void);
static void Cmd_if_target_is_ally(void);
static void Cmd_if_flash_fired(void);
static void Cmd_if_holds_item(void);
static void Cmd_get_hazards_count(void);
static void Cmd_get_curr_dmg_hp_percent(void);
static void Cmd_if_fear_hp_condition(void);
static void Cmd_if_accuracy_less_than(void);
static void Cmd_if_not_expected_to_sleep(void);
static void Cmd_if_receiving_wish(void);
static void Cmd_if_target_wont_attack_due_to_truant(void);
static void Cmd_if_trick_fails_in_this_type_of_battle(void);
static void Cmd_calculate_nhko(void);
static void Cmd_if_next_turn_target_might_use_move_with_effect(void);

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
    Cmd_if_user_has_attacking_move,                 // 0x1F
    Cmd_if_user_has_no_attacking_moves,             // 0x20
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
    Cmd_if_can_faint,                               // 0x3D
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
    Cmd_is_of_type,                                 // 0x5F
    Cmd_check_ability,                              // 0x60
    Cmd_if_flash_fired,                             // 0x61
    Cmd_if_holds_item,                              // 0x62
    Cmd_get_hazards_count,                          // 0x63
    Cmd_get_curr_dmg_hp_percent,                    // 0x64
    Cmd_if_fear_hp_condition,                       // 0x65
	Cmd_if_accuracy_less_than,                      // 0x66
	Cmd_if_not_expected_to_sleep,                   // 0x67
    Cmd_if_receiving_wish,                          // 0x68
	Cmd_if_target_wont_attack_due_to_truant,        // 0x69
	Cmd_if_trick_fails_in_this_type_of_battle,        // 0x6A
	Cmd_calculate_nhko,        // 0x6B
	Cmd_if_next_turn_target_might_use_move_with_effect,        // 0x6C
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
    EFFECT_FOCUS_PUNCH,
    EFFECT_SUPERPOWER,
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

    moveLimitations = CheckMoveLimitations(gActiveBattler, 0, 0xFF);

    // Ignore moves that aren't possible to use.
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBitTable[i] & moveLimitations)
            AI_THINKING_STRUCT->score[i] = 0;

        AI_THINKING_STRUCT->simulatedRNG[i] = 100 - (Random() % 16);
    }

    gBattleResources->AI_ScriptsStack->size = 0;
    sBattler_AI = gActiveBattler;

    // Decide a random target battlerId in doubles.
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        gBattlerTarget = (Random() & BIT_FLANK) + (GetBattlerSide(gActiveBattler) ^ BIT_SIDE);
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

bool32 IsTruantMonVulnerable(u32 battlerAI, u32 opposingBattler)
{
    int i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u32 move = gBattleResources->battleHistory->usedMoves[opposingBattler].moves[i];
        if (gBattleMoves[move].effect == EFFECT_PROTECT && move != MOVE_ENDURE)
            return TRUE;
		if (gBattleMoves[move].effect == EFFECT_SUBSTITUTE
			&& gBattleMons[opposingBattler].hp > gBattleMons[opposingBattler].maxHP / 4 // tiene PS para meter sub
			&& ((gBattleMons[opposingBattler].status2 & STATUS2_SUBSTITUTE)    // ya tiene sub
			|| GetWhoStrikesFirst(battlerAI, opposingBattler, TRUE) == 1)) // o es más rápido
            return TRUE;
		 if (gBattleMoves[move].effect == EFFECT_SEMI_INVULNERABLE && GetWhoStrikesFirst(battlerAI, opposingBattler, TRUE) == 1)
            return TRUE;
    }
    return FALSE;
}

// Determina si un cierto ataque se está viendo afectado por bajadas de stats ofensivos
bool8 IsMoveSignificantlyAffectedByStatDrops(u16 move)
{
    s32 i;
    u8 type = gBattleMoves[move].type;
    u8 power = gBattleMoves[move].power;

    if (move == MOVE_HIDDEN_POWER)
    {
        struct Pokemon *monAttacker;
        if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
            monAttacker = &gPlayerParty[gBattlerPartyIndexes[gActiveBattler]];
        else
            monAttacker = &gEnemyParty[gBattlerPartyIndexes[gActiveBattler]];

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

void CalculategBattleMoveDamageFromgCurrentMove(u8 attackerId, u8 targetId, u8 simulatedRng)
{
    gDynamicBasePower = 0;
    gBattleStruct->dynamicMoveType = 0;
    gBattleScripting.dmgMultiplier = 1;
    gMoveResultFlags = 0;
    gCritMultiplier = 1;
    AI_CalcDmg(attackerId, targetId);

    if (simulatedRng)
        gBattleMoveDamage = gBattleMoveDamage * simulatedRng / 100;
}

s32 CalculatenHKOFromgCurrentMove(u8 attackerId, u8 targetId, u8 simulatedRng, s32 best_nhko)
{
    s32 n;

    CalculategBattleMoveDamageFromgCurrentMove(attackerId, targetId, simulatedRng);

    // Moves always do at least 1 damage.
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    for (n = 1; n < best_nhko; n++)
        if (gBattleMons[targetId].hp <= n * gBattleMoveDamage)
            return n;

    return best_nhko;
}

bool8 AICanSwitchAssumingEnoughPokemon(void)
{
    return !(ABILITY_ON_OPPOSING_FIELD(sBattler_AI, ABILITY_SHADOW_TAG) && (gBattleMons[sBattler_AI].type1 != TYPE_GHOST && gBattleMons[sBattler_AI].type2 != TYPE_GHOST && gBattleMons[sBattler_AI].ability != ABILITY_SHADOW_TAG))
            && !(ABILITY_ON_OPPOSING_FIELD(sBattler_AI, ABILITY_ARENA_TRAP) && (gBattleMons[sBattler_AI].type1 != TYPE_FLYING && gBattleMons[sBattler_AI].type2 != TYPE_FLYING && gBattleMons[sBattler_AI].type1 != TYPE_GHOST && gBattleMons[sBattler_AI].type2 != TYPE_GHOST && gBattleMons[sBattler_AI].ability != ABILITY_LEVITATE))
            && !(ABILITY_ON_FIELD2(ABILITY_MAGNET_PULL) && (gBattleMons[sBattler_AI].type1 == TYPE_STEEL || gBattleMons[sBattler_AI].type2 == TYPE_STEEL))
            && !(gBattleMons[sBattler_AI].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION) && (gBattleMons[sBattler_AI].type1 != TYPE_GHOST && gBattleMons[sBattler_AI].type2 != TYPE_GHOST))
            && !(gStatuses3[sBattler_AI] & STATUS3_ROOTED && (gBattleMons[sBattler_AI].type1 != TYPE_GHOST && gBattleMons[sBattler_AI].type2 != TYPE_GHOST))
            && !(gBattleTypeFlags & (BATTLE_TYPE_ARENA | BATTLE_TYPE_PALACE));
}

static u8 ChooseMoveOrAction_Singles(void)
{
    u8 currentMoveArray[MAX_MON_MOVES];
    u8 consideredMoveArray[MAX_MON_MOVES];
    u8 numOfBestMoves;
    s32 i;
	u32 flags = AI_THINKING_STRUCT->aiFlags;

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
// Consider switching if all moves are worthless to use.
    if (AI_THINKING_STRUCT->aiFlags & (AI_SCRIPT_CHECK_VIABILITY | AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_PREFER_BATON_PASS)
		&& AICanSwitchAssumingEnoughPokemon())
    {
        s32 cap = AI_THINKING_STRUCT->aiFlags & (AI_SCRIPT_CHECK_VIABILITY) ? 95 : 93;
	if (gBattleMons[sBattler_AI].hp < gBattleMons[sBattler_AI].maxHP / 2 && (Random() & 1))
           cap -= 3;
		for (i = 0; i < MAX_MON_MOVES; i++)
        {
            if (AI_THINKING_STRUCT->score[i] > cap)
                break;
        }

        gActiveBattler = sBattler_AI;
        if (i == MAX_MON_MOVES && GetMostSuitableMonToSwitchInto() != PARTY_SIZE)
        {
            AI_THINKING_STRUCT->switchMon = TRUE;
            return AI_CHOICE_SWITCH;
        }
    }
	
	   // Consider switching if your mon with truant is bodied by Protect spam.
        // Or is using a double turn semi invulnerable move(such as Fly) and is faster.
        // Or its ability is actually not Truant.
		if (gBattleMons[sBattler_AI].ability == ABILITY_TRUANT
            && (GetAbilityBySpecies(gBattleMons[sBattler_AI].species, gBattleMons[sBattler_AI].abilityNum) != ABILITY_TRUANT
            || IsTruantMonVulnerable(sBattler_AI, gBattlerTarget))
            && gDisableStructs[sBattler_AI].truantCounter
			&& AICanSwitchAssumingEnoughPokemon())
            if (GetMostSuitableMonToSwitchInto() != PARTY_SIZE)
            {
                AI_THINKING_STRUCT->switchMon = TRUE;
                return AI_CHOICE_SWITCH;
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
            if (GetMostSuitableMonToSwitchInto() != PARTY_SIZE)
            {
                AI_THINKING_STRUCT->switchMon = TRUE;
                return AI_CHOICE_SWITCH;
            }
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
        if (i == sBattler_AI || gBattleMons[i].hp == 0)
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
    // Or is using a double turn semi invulnerable move(such as Fly) and is faster.
    // Or its ability is actually not Truant.
    if (gBattleMons[sBattler_AI].ability == ABILITY_TRUANT
        && GET_BATTLER_SIDE(sBattler_AI) != GET_BATTLER_SIDE(gBattlerTarget)
        && actionOrMoveIndex[gBattlerTarget] != AI_CHOICE_FLEE
        && actionOrMoveIndex[gBattlerTarget] != AI_CHOICE_WATCH
        && (GetAbilityBySpecies(gBattleMons[sBattler_AI].species, gBattleMons[sBattler_AI].abilityNum) != ABILITY_TRUANT
              || (IsTruantMonVulnerable(sBattler_AI, gBattlerTarget)
                  && (gBattleMons[gBattlerTarget ^ BIT_FLANK].hp == 0 || IsTruantMonVulnerable(sBattler_AI, gBattlerTarget ^ BIT_FLANK))))
        && gDisableStructs[sBattler_AI].truantCounter
        && AICanSwitchAssumingEnoughPokemon())
        if (GetMostSuitableMonToSwitchInto() != PARTY_SIZE)
        {
            AI_THINKING_STRUCT->switchMon = TRUE;
            return AI_CHOICE_SWITCH;
        }
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

static void RecordLastUsedMoveByTarget(void)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] == gLastMoves[gBattlerTarget])
            break;
        if (BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] != gLastMoves[gBattlerTarget]  // HACK: This redundant condition is a hack to make the asm match.
         && BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] == MOVE_NONE)
        {
            BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] = gLastMoves[gBattlerTarget];
            break;
        }
    }
}

void ClearBattlerMoveHistory(u8 battlerId)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
        BATTLE_HISTORY->usedMoves[battlerId].moves[i] = MOVE_NONE;
}

void RecordAbilityBattle(u8 battlerId, u8 abilityId)
{
    BATTLE_HISTORY->abilities[battlerId] = abilityId;
}

void ClearBattlerAbilityHistory(u8 battlerId)
{
    BATTLE_HISTORY->abilities[battlerId] = ABILITY_NONE;
}

void RecordItemEffectBattle(u8 battlerId, u8 itemEffect)
{
    BATTLE_HISTORY->itemEffects[battlerId] = itemEffect;
}

void ClearBattlerItemEffectHistory(u8 battlerId)
{
    BATTLE_HISTORY->itemEffects[battlerId] = 0;
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

static void Cmd_if_fear_hp_condition(void)
{
    switch (gAIScriptPtr[1])
    {
    case 0: // comprueba si el rival tiene 1 PS
        if (gBattleMons[gBattlerTarget].hp == 1)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case 1: // comprueba si el rival tiene, como máximo, los PS que tiene el usuario más lo que el rival obtendría por Restos
        if (gBattleMons[gBattlerTarget].hp <= gBattleMons[sBattler_AI].hp + gBattleMons[gBattlerTarget].maxHP / 16)
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

static void Cmd_if_user_has_attacking_move(void)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[sBattler_AI].moves[i] != 0
            && gBattleMoves[gBattleMons[sBattler_AI].moves[i]].power != 0)
            break;
    }

    if (i == MAX_MON_MOVES)
        gAIScriptPtr += 5;
    else
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
}

static void Cmd_if_user_has_no_attacking_moves(void)
{
    s32 i;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMons[sBattler_AI].moves[i] != 0
         && gBattleMoves[gBattleMons[sBattler_AI].moves[i]].power != 0)
            break;
    }

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

static void Cmd_is_of_type(void)
{
    u8 battlerId = BattleAI_GetWantedBattler(gAIScriptPtr[1]);

    if (IS_BATTLER_OF_TYPE(battlerId, gAIScriptPtr[2]))
        AI_THINKING_STRUCT->funcResult = TRUE;
    else
        AI_THINKING_STRUCT->funcResult = FALSE;

    gAIScriptPtr += 3;
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

    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power > 1)
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
                && gBattleMoves[gBattleMons[sBattler_AI].moves[checkedMove]].power > 1)
            {
                gCurrentMove = gBattleMons[sBattler_AI].moves[checkedMove];
                AI_CalcDmg(sBattler_AI, gBattlerTarget);
                moveDmgs[checkedMove] = gBattleMoveDamage * AI_THINKING_STRUCT->simulatedRNG[checkedMove] / 100;
                if (moveDmgs[checkedMove] == 0)
                    moveDmgs[checkedMove] = 1;
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

        if (checkedMove == MAX_MON_MOVES)
            AI_THINKING_STRUCT->funcResult = isDiscouraged ? MOVE_POWER_DISCOURAGED : MOVE_MOST_POWERFUL; // Is the most powerful.
        else
			AI_THINKING_STRUCT->funcResult = isDiscouraged ? MOVE_POWER_DISCOURAGED_AND_NOT_MOST_POWERFUL : MOVE_NOT_MOST_POWERFUL; // Not the most powerful.
    }
    else
    {
        AI_THINKING_STRUCT->funcResult = 0; // Highly discouraged in terms of power.
    }

    gAIScriptPtr++;
}

static void Cmd_get_last_used_battler_move(void)
{
    if (gAIScriptPtr[1] == AI_USER)
        AI_THINKING_STRUCT->funcResult = gLastMoves[sBattler_AI];
    else
        AI_THINKING_STRUCT->funcResult = gLastMoves[gBattlerTarget];

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

	if ((gActiveBattler | BIT_FLANK) != (battlerId | BIT_FLANK))
    {
        if (BATTLE_HISTORY->abilities[battlerId] != 0)
        {
            AI_THINKING_STRUCT->funcResult = BATTLE_HISTORY->abilities[battlerId];
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
        if (BATTLE_HISTORY->abilities[battlerId] != ABILITY_NONE)
        {
            ability = BATTLE_HISTORY->abilities[battlerId];
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

static void Cmd_if_can_faint(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power < 2)
    {
        gAIScriptPtr += 5;
        return;
    }

    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;
    CalculategBattleMoveDamageFromgCurrentMove(sBattler_AI, gBattlerTarget, AI_THINKING_STRUCT->simulatedRNG[AI_THINKING_STRUCT->movesetIndex]);

    // Moves always do at least 1 damage.
    if (gBattleMoveDamage == 0)
        gBattleMoveDamage = 1;

    if (gBattleMons[gBattlerTarget].hp <= gBattleMoveDamage)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 1);
    else
        gAIScriptPtr += 5;
}

static void Cmd_if_cant_faint(void)
{
    if (gBattleMoves[AI_THINKING_STRUCT->moveConsidered].power < 2)
    {
        gAIScriptPtr += 5;
        return;
    }

    gCurrentMove = AI_THINKING_STRUCT->moveConsidered;
    CalculategBattleMoveDamageFromgCurrentMove(sBattler_AI, gBattlerTarget, AI_THINKING_STRUCT->simulatedRNG[AI_THINKING_STRUCT->movesetIndex]);

    // This macro is missing the damage 0 = 1 assumption.

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
            if (BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] == *movePtr)
            {
                s32 j;
                for (j = 0; j < MAX_MON_MOVES; j++)
                    if (BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
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
            if (BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] == *movePtr)
            {
                s32 j;
                for (j = 0; j < MAX_MON_MOVES; j++)
                    if (BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
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
            if (BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] && gBattleMoves[BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i]].effect == gAIScriptPtr[2])
            {
                s32 j;
                for (j = 0; j < MAX_MON_MOVES; j++)
                    if (BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
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
            if (BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] && gBattleMoves[BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i]].effect == gAIScriptPtr[2])
            {
                s32 j;
                for (j = 0; j < MAX_MON_MOVES; j++)
                    if (BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
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
        if (gDisableStructs[gActiveBattler].disabledMove == AI_THINKING_STRUCT->moveConsidered)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case 1:
        if (gDisableStructs[gActiveBattler].encoredMove == AI_THINKING_STRUCT->moveConsidered)
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

    if (gActiveBattler != battlerId)
        AI_THINKING_STRUCT->funcResult = ItemId_GetHoldEffect(BATTLE_HISTORY->itemEffects[battlerId]);
    else
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
        item = BATTLE_HISTORY->itemEffects[battlerId];

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

    if (gAIScriptPtr[1] == AI_USER)
        battlerId = sBattler_AI;
    else
        battlerId = gBattlerTarget;

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
    case 0: // greater than
        if (gBattleMons[sBattler_AI].level > gBattleMons[gBattlerTarget].level)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case 1: // less than
        if (gBattleMons[sBattler_AI].level < gBattleMons[gBattlerTarget].level)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case 2: // equal
        if (gBattleMons[sBattler_AI].level == gBattleMons[gBattlerTarget].level)
            gAIScriptPtr = T1_READ_PTR(gAIScriptPtr + 2);
        else
            gAIScriptPtr += 6;
        break;
    case 3: // AI level is 2 or less
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
    if (!(gBattleMons[AI_USER].status1 & STATUS1_SLEEP) || (gBattleMons[AI_USER].status1 & STATUS1_SLEEP) == 5)
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

static void Cmd_calculate_nhko(void)
{
    u16 attackerId, targetId;
    u16 * movePointer;
    bool8 attacker_is_user;
    s32 i;
    s32 best_nhko = 5;     // todo lo que sea peor que 4HKO se lee como 5HKO (incluso daño 0)

    if (gAIScriptPtr[1] == AI_USER)
    {
        attackerId = sBattler_AI;
        targetId = gBattlerTarget;
		movePointer = &AI_THINKING_STRUCT->moveConsidered;
        attacker_is_user = TRUE;
    }
    else
    {
        attackerId = gBattlerTarget;
        targetId = sBattler_AI;
        movePointer = BATTLE_HISTORY->usedMoves[gBattlerTarget].moves;
        attacker_is_user = FALSE;
    }
    
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (!movePointer[i] || gBattleMoves[movePointer[i]].power < 2)
            continue;  // se ignora el movimiento

        if (!attacker_is_user)
        {
            u8 moveLimitations = CheckMoveLimitations(gBattlerTarget, 0, MOVE_LIMITATION_CHOICE-1);
            s32 j;
            for (j = 0; j < MAX_MON_MOVES; j++)
                if (movePointer[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
                    break;
            if (j == MAX_MON_MOVES)
                continue; // No puede usar el movimiento por el momento; se ignora
        }

        gCurrentMove = movePointer[i];
        best_nhko = CalculatenHKOFromgCurrentMove(attackerId, targetId, attacker_is_user ? AI_THINKING_STRUCT->simulatedRNG[AI_THINKING_STRUCT->movesetIndex] : 0, best_nhko);

        if (attacker_is_user || best_nhko == 1)
            break; // solo se mira el movimiento pensado, y no se sigue mirando si es OHKO
    }

    // Si el atacante es el oponente, no se conocen todos sus movs y no da OHKO,
    // la IA asume que los STAB estándar (de precisión alta) pueden ser los movs que faltan
	// siempre que la IA esté en condiciones de usar un ataque nuevo
		if (!attacker_is_user && best_nhko > 1
        && gDisableStructs[attackerId].encoredMove == MOVE_NONE
        && !(gBattleMons[attackerId].status2 & (STATUS2_RECHARGE | STATUS2_MULTIPLETURNS)))
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
            if (!movePointer[i]) // hay un ataque no conocido
                break;
        
        if (i != MAX_MON_MOVES) // algún ataque no se conoce
        {
            s32 type_i;
            u8 opponent_types[2] = {gBattleMons[gBattlerTarget].type1, gBattleMons[gBattlerTarget].type2};
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
        }
    }
    
    if (((gBattleMons[attackerId].status2 & STATUS2_RECHARGE) || gDisableStructs[attackerId].truantCounter) && best_nhko < 5)
        best_nhko += 1;

    AI_THINKING_STRUCT->funcResult = best_nhko;
    gAIScriptPtr += 2;
}

static void Cmd_if_next_turn_target_might_use_move_with_effect(void)
{
    s32 i;
    u8 moveLimitations = CheckMoveLimitations(gBattlerTarget, 0, MOVE_LIMITATION_CHOICE-1);

    gAIScriptPtr += 6; // será sobreescrito si el objetivo sí podrá usar un movimiento con el efecto

    if (gBattleMons[gBattlerTarget].status2 & STATUS2_RECHARGE)
        return; // estará descansando por Hiperrayo o similar

    if (gBattleMons[gBattlerTarget].status2 & STATUS2_MULTIPLETURNS)
        return; // está en un ataque multiturno. (Se asume que no se está preguntando por ese mismo ataque multiturno)

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] && gBattleMoves[BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i]].effect == *(gAIScriptPtr - 5))
        {
            s32 j;
            for (j = 0; j < MAX_MON_MOVES; j++)
                if (BATTLE_HISTORY->usedMoves[gBattlerTarget].moves[i] == gBattleMons[gBattlerTarget].moves[j] && !(gBitTable[j] & moveLimitations))
                    break;
            if (j != MAX_MON_MOVES)
                break;
        }
    }

    if (i != MAX_MON_MOVES)
        gAIScriptPtr = T1_READ_PTR(gAIScriptPtr - 4);
}

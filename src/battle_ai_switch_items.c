#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_ai_script_commands.h"
#include "event_data.h"
#include "pokemon.h"
#include "random.h"
#include "util.h"
#include "constants/abilities.h"
#include "constants/item_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/battle_move_effects.h"
#include "constants/species.h"

#define ALL_MONS_FILTERED 0x3F
#define STATUS2_KEPT_BY_SUBSTITUTE (STATUS2_CONFUSION | STATUS2_FOCUS_ENERGY | STATUS2_SUBSTITUTE | STATUS2_ESCAPE_PREVENTION | STATUS2_CURSED)

// this file's functions
static bool8 HasSuperEffectiveMoveAgainstOpponents(bool8 noRng);
static bool8 FindMonWithFlagsAndSuperEffective(u8 flags, u8 moduloPercent);
static bool8 ShouldUseItem(void);

// Determina si la IA decidió un cambio tras evaluar los movimientos disponibles
// (criterios de cambio en battle_ai_script_commands.c)
static bool8 ASwitchWasDecidedAfterConsideringAvailableMoves(void)
{
    if (*(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) != PARTY_SIZE)
    {
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    else
        return FALSE;
}

static bool8 ShouldSwitchIfForcedToUseStruggle(void)
{
    if (CheckMoveLimitations(gActiveBattler, 0, 0xFF) == 0xF // no hay movimientos disponibles (es lo que se usa en AreAllMovesUnusable en battle_util.c)
        && gBattleMons[GetBattlerAtPosition(BATTLE_OPPOSITE(GetBattlerPosition(gActiveBattler)))].hp > 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    return FALSE;
}

static bool8 ShouldSwitchIfPerishSong(void)
{
    if (gStatuses3[gActiveBattler] & STATUS3_PERISH_SONG
        && gDisableStructs[gActiveBattler].perishSongTimer == 0)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool8 NonDamagingMoveIsGoodAgainstWonderGuardOpponent(u16 move, u8 opposingBattler)
{
        switch(gBattleMoves[move].effect) {
            case EFFECT_TOXIC:
                return gBattleMons[opposingBattler].species == SPECIES_SHEDINJA && !(gBattleMons[opposingBattler].status1 & STATUS1_ANY);
            case EFFECT_WILL_O_WISP:
            case EFFECT_POISON:
                if ((gBattleMons[opposingBattler].status1 & STATUS1_ANY)) break;
                // fall through
            case EFFECT_SANDSTORM:
            case EFFECT_HAIL:
            case EFFECT_LEECH_SEED:
            case EFFECT_CONFUSE:
            case EFFECT_TEETER_DANCE:
            case EFFECT_SWAGGER:
            case EFFECT_FLATTER:
                return gBattleMons[opposingBattler].species == SPECIES_SHEDINJA && gBattleMons[opposingBattler].hp == 1;
        }
    return FALSE;
}

static bool8 ShouldSwitchIfWonderGuard(void)
{
    u8 opposingPosition;
    u8 opposingBattler;
    u8 moveFlags;
    s32 i, j;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party = NULL;
    u16 move;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
        return FALSE;

    opposingPosition = BATTLE_OPPOSITE(GetBattlerPosition(gActiveBattler));

    if (gBattleMons[GetBattlerAtPosition(opposingPosition)].ability != ABILITY_WONDER_GUARD)
        return FALSE;

    if (CheckMoveLimitations(gActiveBattler, 0, 0xFF) == 0xF && gBattleMons[GetBattlerAtPosition(opposingPosition)].hp == 1)
        return FALSE; // va a caer por Struggle

    // Check if Pokemon has a super effective move.
    for (opposingBattler = GetBattlerAtPosition(opposingPosition), i = 0; i < MAX_MON_MOVES; i++)
    {
        move = gBattleMons[gActiveBattler].moves[i];
        if (move == MOVE_NONE)
            continue;

       if (NonDamagingMoveIsGoodAgainstWonderGuardOpponent(move, opposingBattler))
           return FALSE;

        moveFlags = AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability);
        if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            return FALSE;
    }

    // Get party information.
    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBattler & BIT_FLANK) == B_FLANK_LEFT)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    // Si lo hay, mete un poke que meta clima para eliminar al Shedinja rival
    if (gBattleMons[GetBattlerAtPosition(opposingPosition)].species == SPECIES_SHEDINJA)
        for (i = firstId; i < lastId; i++)
        {
            u16 species;
            u8 monAbility;
            if (GetMonData(&party[i], MON_DATA_HP) == 0)
                continue;
            if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_NONE)
                continue;
            if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_EGG)
                continue;
            if (i == gBattlerPartyIndexes[gActiveBattler])
                continue;

            species = GetMonData(&party[i], MON_DATA_SPECIES);
            if (GetMonData(&party[i], MON_DATA_ABILITY_NUM) != 0)
                monAbility = gBaseStats[species].abilities[1];
            else
                monAbility = gBaseStats[species].abilities[0];
            if (monAbility == ABILITY_SAND_STREAM || monAbility == ABILITY_SNOW_WARNING)
            {
                *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = i;
                BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
                return TRUE;
            }
        }

    // Find a Pokemon in the party that has a super effective move.
    for (i = firstId; i < lastId; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[gActiveBattler])
            continue;

        GetMonData(&party[i], MON_DATA_SPECIES); // Unused return value.
        GetMonData(&party[i], MON_DATA_ABILITY_NUM); // Unused return value.

        for (opposingBattler = GetBattlerAtPosition(opposingPosition), j = 0; j < MAX_MON_MOVES; j++)
        {
			bool8 usefulMove = FALSE;
            move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
            if (move == MOVE_NONE)
                continue;
		
       if (NonDamagingMoveIsGoodAgainstWonderGuardOpponent(move, opposingBattler))
           usefulMove = TRUE;

            if (!usefulMove && gBattleMoves[move].power > 0)
            {

            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability);
				if ((moveFlags & MOVE_RESULT_SUPER_EFFECTIVE) && !(moveFlags & MOVE_RESULT_DOESNT_AFFECT_FOE))
                    usefulMove = TRUE;
            }

            if (usefulMove && Random() % 3 < 2)
            {
                // We found a mon.
                *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = i;
                BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
                return TRUE;
            }
        }
    }

    return FALSE; // There is not a single Pokemon in the party that has a super effective move against a mon with Wonder Guard.
}

static bool8 HasMove(u16 move)
{
    s32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
        if (move == gBattleMons[gActiveBattler].moves[i])
            return TRUE;

    return FALSE;
}

static bool8 FindMonThatAbsorbsOpponentsMove(void)
{
    u8 battlerIn1, battlerIn2;
	u8 moveType;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i;

    if (HasSuperEffectiveMoveAgainstOpponents(TRUE) && Random() % 3 != 0)
        return FALSE;
    if (gLastLandedMoves[gActiveBattler] == 0)
        return FALSE;
    if (gLastLandedMoves[gActiveBattler] == 0xFFFF)
        return FALSE;
    if (gBattleMoves[gLastLandedMoves[gActiveBattler]].power == 0)
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)));
    }
    else
    {
        battlerIn1 = gActiveBattler;
        battlerIn2 = gActiveBattler;
    }

	moveType = gBattleMoves[gLastLandedMoves[gActiveBattler]].type;

    // Comprueba que el tipo del movimiento no es ya absorbido por el poke actual
    switch(moveType)
    {
        case TYPE_FIRE:
            if (gBattleMons[gActiveBattler].ability == ABILITY_FLASH_FIRE)
                return FALSE;
            break;
        case TYPE_WATER:
            if (gBattleMons[gActiveBattler].ability == ABILITY_WATER_ABSORB || gBattleMons[gActiveBattler].ability == ABILITY_DRY_SKIN)
                return FALSE;
            break;
        case TYPE_ELECTRIC:
            if (gBattleMons[gActiveBattler].ability == ABILITY_MOTOR_DRIVE || gBattleMons[gActiveBattler].ability == ABILITY_VOLT_ABSORB || gBattleMons[gActiveBattler].ability == ABILITY_LIGHTNING_ROD)
                return FALSE;
            break;
        default:
            return FALSE; // no hay habilidad que absorba este tipo
    }

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBattler & BIT_FLANK) == B_FLANK_LEFT)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        u16 species;
        u8 monAbility;

        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            continue;

        species = GetMonData(&party[i], MON_DATA_SPECIES);
        if (GetMonData(&party[i], MON_DATA_ABILITY_NUM) != 0)
            monAbility = gBaseStats[species].abilities[1];
        else
            monAbility = gBaseStats[species].abilities[0];

        if (Random() & 1)
        {
            bool8 found = FALSE;
            switch(moveType)
            {
                case TYPE_FIRE:
                    if (monAbility == ABILITY_FLASH_FIRE)
                        found = TRUE;
                    break;
                case TYPE_WATER:
                    if (monAbility == ABILITY_WATER_ABSORB || monAbility == ABILITY_DRY_SKIN)
                        found = TRUE;
                    break;
                case TYPE_ELECTRIC:
                    if (monAbility == ABILITY_MOTOR_DRIVE || monAbility == ABILITY_VOLT_ABSORB || monAbility == ABILITY_LIGHTNING_ROD)
                        found = TRUE;
                    break;
            };
            if (found)
            {
                // we found a mon.
                *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = i;
                BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
                return TRUE;
            }
        }
    }

    return FALSE;
}

static bool8 ShouldSwitchIfNaturalCure(void)
{
    if (!(gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP))
        return FALSE;
    if (gBattleMons[gActiveBattler].ability != ABILITY_NATURAL_CURE)
        return FALSE;
    if (gBattleMons[gActiveBattler].hp < gBattleMons[gActiveBattler].maxHP / 2)
        return FALSE;

    if ((gLastLandedMoves[gActiveBattler] == 0 || gLastLandedMoves[gActiveBattler] == 0xFFFF) && Random() & 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }
    else if (gBattleMoves[gLastLandedMoves[gActiveBattler]].power == 0 && Random() & 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }

    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_DOESNT_AFFECT_FOE, 1))
        return TRUE;
    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_NOT_VERY_EFFECTIVE, 1))
        return TRUE;

    if (Random() & 1)
    {
        *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
        BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
        return TRUE;
    }

    return FALSE;
}

static bool8 HasSuperEffectiveMoveAgainstOpponents(bool8 noRng)
{
    u8 opposingPosition;
    u8 opposingBattler;
    s32 i;
    u8 moveFlags;
    u16 move;

    opposingPosition = BATTLE_OPPOSITE(GetBattlerPosition(gActiveBattler));
    opposingBattler = GetBattlerAtPosition(opposingPosition);

    if (!(gAbsentBattlerFlags & gBitTable[opposingBattler]))
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            move = gBattleMons[gActiveBattler].moves[i];
            if (move == MOVE_NONE)
                continue;

            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability);
            if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            {
                if (noRng)
                    return TRUE;
                if (Random() % 10 != 0)
                    return TRUE;
            }
        }
    }
    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
        return FALSE;

    opposingBattler = GetBattlerAtPosition(BATTLE_PARTNER(opposingPosition));

    if (!(gAbsentBattlerFlags & gBitTable[opposingBattler]))
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
        {
            move = gBattleMons[gActiveBattler].moves[i];
            if (move == MOVE_NONE)
                continue;

            moveFlags = AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability);
            if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE)
            {
                if (noRng)
                    return TRUE;
                if (Random() % 10 != 0)
                    return TRUE;
            }
        }
    }

    return FALSE;
}

static bool8 AreStatsRaised(void)
{
    u8 buffedStatsValue = 0;
    s32 i;

    for (i = 0; i < NUM_BATTLE_STATS; i++)
    {
        if (gBattleMons[gActiveBattler].statStages[i] > 6)
            buffedStatsValue += gBattleMons[gActiveBattler].statStages[i] - 6;
    }

    return (buffedStatsValue > 3);
}

// AI should switch if it's become setup fodder and has something better to switch to
bool8 AreAttackingStatsLowered(u8 category)
{
    // Considera cambiar si elige un ataque físico y tiene -2 o menos de Ataque,
    // o si elige un ataque especial y tiene -2 o menos de Ataque Especial
    // En el resto de casos, descarta el cambio por bajada de stats
    // (se asume que solo se llama a esta función si el ataque es de daño directo)
    if ((category == 0 && gBattleMons[gActiveBattler].statStages[MON_DATA_ATK - MON_DATA_MAX_HP] >= 6 - 1)
     || (category == 1 && gBattleMons[gActiveBattler].statStages[MON_DATA_SPATK - MON_DATA_MAX_HP] >= 6 - 1))
        return FALSE;

    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_DOESNT_AFFECT_FOE, 1))
        return TRUE;
    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_NOT_VERY_EFFECTIVE, 1))
        return TRUE;

    *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
    BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
    return TRUE;
}

// AI should switch if it's become blind and has something better to switch to
bool8 IsAccuracyLowered(s8 threshold)
{
    // Considera cambiar si su precisión es, al menos, la indicada en threshold
    if (gBattleMons[gActiveBattler].statStages[STAT_ACC] > 6 + threshold)
        return FALSE;

    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_DOESNT_AFFECT_FOE, 1))
        return TRUE;
    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_NOT_VERY_EFFECTIVE, 1))
        return TRUE;

    *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = PARTY_SIZE;
    BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
    return TRUE;
}

static bool8 FindMonWithFlagsAndSuperEffective(u8 flags, u8 moduloPercent)
{
    u8 battlerIn1, battlerIn2;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i, j;
    u16 move;
    u8 moveFlags;

    if (gLastLandedMoves[gActiveBattler] == 0)
        return FALSE;
    if (gLastLandedMoves[gActiveBattler] == 0xFFFF)
        return FALSE;
    if (gLastHitBy[gActiveBattler] == 0xFF)
        return FALSE;
    if (gBattleMoves[gLastLandedMoves[gActiveBattler]].power == 0)
        return FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)))])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(BATTLE_PARTNER(GetBattlerPosition(gActiveBattler)));
    }
    else
    {
        battlerIn1 = gActiveBattler;
        battlerIn2 = gActiveBattler;
    }

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBattler & BIT_FLANK) == 0)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        u16 species;
        u8 monAbility;

        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            continue;

        species = GetMonData(&party[i], MON_DATA_SPECIES);
        if (GetMonData(&party[i], MON_DATA_ABILITY_NUM) != 0)
            monAbility = gBaseStats[species].abilities[1];
        else
            monAbility = gBaseStats[species].abilities[0];

        moveFlags = AI_TypeCalc(gLastLandedMoves[gActiveBattler], species, monAbility);
        if (moveFlags & flags)
        {
            battlerIn1 = gLastHitBy[gActiveBattler];

            for (j = 0; j < MAX_MON_MOVES; j++)
            {
                move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
                if (move == 0)
                    continue;

                moveFlags = AI_TypeCalc(move, gBattleMons[battlerIn1].species, gBattleMons[battlerIn1].ability);
                if (moveFlags & MOVE_RESULT_SUPER_EFFECTIVE && Random() % moduloPercent == 0)
                {
                    *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = i;
                    BtlController_EmitTwoReturnValues(1, B_ACTION_SWITCH, 0);
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

static bool8 ShouldSwitch(void)
{
    u8 battlerIn1, battlerIn2;
    u8 *activeBattlerPtr; // Needed to match.
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i;
    s32 availableToSwitch;

    if (gBattleMons[*(activeBattlerPtr = &gActiveBattler)].status2 & (STATUS2_WRAPPED | STATUS2_ESCAPE_PREVENTION))
	{
		if (!IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_GHOST))
			return FALSE;
	}
    if (gStatuses3[gActiveBattler] & STATUS3_ROOTED)
	{
		if (!IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_GHOST))
        return FALSE;
	}
    if (ABILITY_ON_OPPOSING_FIELD(gActiveBattler, ABILITY_SHADOW_TAG))
    {
        if (!IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_GHOST) && (gBattleMons[gActiveBattler].ability != ABILITY_SHADOW_TAG))
            return FALSE;
    }
    if (ABILITY_ON_OPPOSING_FIELD(gActiveBattler, ABILITY_ARENA_TRAP))
    {
        if (!IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_FLYING) && !IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_GHOST) && (gBattleMons[gActiveBattler].ability != ABILITY_LEVITATE))
			return FALSE;
    }
    if (ABILITY_ON_FIELD2(ABILITY_MAGNET_PULL))
    {
        if (IS_BATTLER_OF_TYPE(gActiveBattler, TYPE_STEEL))
            return FALSE;
    }
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        return FALSE;

    if (FlagGet(FLAG_RYU_RANDOMBATTLECCMETRO) == 1)
        return FALSE;

    availableToSwitch = 0;
    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = *activeBattlerPtr;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(GetBattlerPosition(*activeBattlerPtr) ^ BIT_FLANK)])
            battlerIn2 = *activeBattlerPtr;
        else
            battlerIn2 = GetBattlerAtPosition(GetBattlerPosition(*activeBattlerPtr) ^ BIT_FLANK);
    }
    else
    {
        battlerIn1 = *activeBattlerPtr;
        battlerIn2 = *activeBattlerPtr;
    }

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBattler & BIT_FLANK) == B_FLANK_LEFT)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = firstId; i < lastId; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP) == 0)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_NONE)
            continue;
        if (GetMonData(&party[i], MON_DATA_SPECIES2) == SPECIES_EGG)
            continue;
        if (i == gBattlerPartyIndexes[battlerIn1])
            continue;
        if (i == gBattlerPartyIndexes[battlerIn2])
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
            continue;
        if (i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            continue;

        availableToSwitch++;
    }

    if (availableToSwitch == 0)
        return FALSE;

    // Si se decidió un cambio tras evaluar los movimientos, se marcará y se hará ahora
    // (usando los criterios de battle_ai_script_commands.c)
    if (ASwitchWasDecidedAfterConsideringAvailableMoves())
        return TRUE;

    // Los siguientes criterios se evalúan antes que los movimientos disponibles
    if (ShouldSwitchIfPerishSong())
        return TRUE;
    if (ShouldSwitchIfForcedToUseStruggle())
        return TRUE;
	if (HasMove(MOVE_BATON_PASS))
        return FALSE; // los supuestos de cambio a continuación aplican igual con Baton Pass, por lo que el cambio es mejor con Baton Pass
    if (ShouldSwitchIfWonderGuard())
        return TRUE;
/*    if (FindMonThatAbsorbsOpponentsMove())
        return TRUE; */
    if (ShouldSwitchIfNaturalCure())
        return TRUE;
/*	if (gBattleMons[gActiveBattler].species == SPECIES_REGIGIGAS)
		return FALSE;
    if (HasSuperEffectiveMoveAgainstOpponents(FALSE))
        return FALSE;
    if (AreStatsRaised())
        return FALSE;
    if (FindMonWithFlagsAndSuperEffective(MOVE_RESULT_DOESNT_AFFECT_FOE, 2)
        || FindMonWithFlagsAndSuperEffective(MOVE_RESULT_NOT_VERY_EFFECTIVE, 3))
        return TRUE; */

    return FALSE;
}

void AI_TrySwitchOrUseItem(void)
{
    struct Pokemon *party;
    u8 battlerIn1, battlerIn2;
    s32 firstId;
    s32 lastId; // + 1
    u8 battlerIdentity = GetBattlerPosition(gActiveBattler);

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
    {
        if (ShouldSwitch())
        {
            if (*(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) == PARTY_SIZE)
            {
                s32 monToSwitchId = GetMostSuitableMonToSwitchInto(NOT_CHANGING_IS_UNACCEPTABLE);
                if (monToSwitchId == PARTY_SIZE)
                {
                    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
                    {
                        battlerIn1 = GetBattlerAtPosition(battlerIdentity);
                        battlerIn2 = battlerIn1;
                    }
                    else
                    {
                        battlerIn1 = GetBattlerAtPosition(battlerIdentity);
                        battlerIn2 = GetBattlerAtPosition(battlerIdentity ^ BIT_FLANK);
                    }

                    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
                    {
                        if ((gActiveBattler & BIT_FLANK) == B_FLANK_LEFT)
                            firstId = 0, lastId = 3;
                        else
                            firstId = 3, lastId = 6;
                    }
                    else
                    {
                        firstId = 0, lastId = 6;
                    }

                    for (monToSwitchId = firstId; monToSwitchId < lastId; monToSwitchId++)
                    {
                        if (GetMonData(&party[monToSwitchId], MON_DATA_HP) == 0)
                            continue;
                        if (monToSwitchId == gBattlerPartyIndexes[battlerIn1])
                            continue;
                        if (monToSwitchId == gBattlerPartyIndexes[battlerIn2])
                            continue;
                        if (monToSwitchId == *(gBattleStruct->monToSwitchIntoId + battlerIn1))
                            continue;
                        if (monToSwitchId == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
                            continue;

                        break;
                    }
                }

                *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler) = monToSwitchId;
            }

            *(gBattleStruct->monToSwitchIntoId + gActiveBattler) = *(gBattleStruct->AI_monToSwitchIntoId + gActiveBattler);
            return;
        }
        else if (ShouldUseItem())
        {
            return;
        }
    }

    BtlController_EmitTwoReturnValues(1, B_ACTION_USE_MOVE, (gActiveBattler ^ BIT_SIDE) << 8);
}

static void ModulateByTypeEffectiveness(u8 atkType, u8 defType1, u8 defType2, u8 *var)
{
    s32 i = 0;

    while (TYPE_EFFECT_ATK_TYPE(i) != TYPE_ENDTABLE)
    {
        if (TYPE_EFFECT_ATK_TYPE(i) == TYPE_FORESIGHT)
        {
            i += 3;
            continue;
        }
        else if (TYPE_EFFECT_ATK_TYPE(i) == atkType)
        {
            // Check type1.
            if (TYPE_EFFECT_DEF_TYPE(i) == defType1)
                *var = (*var * TYPE_EFFECT_MULTIPLIER(i)) / 10;
            // Check type2.
            if (TYPE_EFFECT_DEF_TYPE(i) == defType2 && defType1 != defType2)
                *var = (*var * TYPE_EFFECT_MULTIPLIER(i)) / 10;
        }
        i += 3;
    }
}

static u32 GetBestMonDefensive(struct Pokemon *party, s32 firstId, s32 lastId, u8 invalidMons, u32 opposingBattler)
{
    s32 i, bits = 0;
    u16 chosenSpecies;

    while (bits != ALL_MONS_FILTERED) // All mons were checked.
    {
        u8 bestDmg = 255;
        s32 bestMonId = PARTY_SIZE;
        // Find the mon whose type is the most suitable defensively.
        for (i = firstId; i < lastId; i++)
        {
            if (!(gBitTable[i] & invalidMons) && !(gBitTable[i] & bits))
            {
                u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
                u8 typeDmg  = 20;
                u8 typeDmg2 = 20;

                u8 defType1 = gBaseStats[species].type1;
                u8 defType2 = gBaseStats[species].type2;
                u8 atkType1 = gBattleMons[opposingBattler].type1;
                u8 atkType2 = gBattleMons[opposingBattler].type2;

                ModulateByTypeEffectiveness(atkType1, defType1, defType2, &typeDmg);

                if (atkType2 != atkType1)
                {
                    ModulateByTypeEffectiveness(atkType2, defType1, defType2, &typeDmg2);
                    if (typeDmg < typeDmg2)
                        typeDmg = typeDmg2;
                }
                if (bestDmg > typeDmg)
                {
                    bestDmg = typeDmg;
                    bestMonId = i;
                }
            }
        }

        // Make sure player's last attack won't be SE, as they're probably going to use it again.
		if (bestMonId != PARTY_SIZE)
        {
            u16 move = gLastLandedMoves[gActiveBattler];
            chosenSpecies = GetMonData(&party[bestMonId], MON_DATA_SPECIES);

            if (move != MOVE_NONE && gBattleMoves[move].power != 0)
            {
                u8 monAbility;
                if (GetMonData(&party[bestMonId], MON_DATA_ABILITY_NUM) != 0)
                    monAbility = gBaseStats[chosenSpecies].abilities[1];
                else
                    monAbility = gBaseStats[chosenSpecies].abilities[0];

                if (AI_TypeCalc(move, chosenSpecies, monAbility) & MOVE_RESULT_SUPER_EFFECTIVE)
                {
                    bits |= gBitTable[bestMonId];
                }
            }
        }

        // Ok, we know the mon has the right typing but does it have at least one super effective move?
        if (bestMonId != PARTY_SIZE && bits != gBitTable[bestMonId])
        {
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                u16 move = GetMonData(&party[bestMonId], MON_DATA_MOVE1 + i);
				if (move != MOVE_NONE && gBattleMoves[move].power != 0 && AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability) & MOVE_RESULT_SUPER_EFFECTIVE)
                    break;
            }

            if (i != MAX_MON_MOVES)
                return bestMonId; // Has both the typing and at least one super effective move.

            bits |= gBitTable[bestMonId]; // Sorry buddy, we want something better.
        }
        else
        {
            bits = ALL_MONS_FILTERED; // No viable mon to switch.
        }
    }

    return PARTY_SIZE;
}

static u32 GetBestMonOffensive(struct Pokemon *party, s32 firstId, s32 lastId, u8 invalidMons, u32 opposingBattler)
{
    s32 i = 0;
    u8 bestMonId;
	u8 bestDmg;
    u16 move;

	while (invalidMons != ALL_MONS_FILTERED) // All mons are invalid.
    {
        bestDmg = 0;
        bestMonId = 6;
        // Find the mon whose type is the most suitable offensively.
        for (i = firstId; i < lastId; i++)
        {
            u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
            if (!(gBitTable[i] & invalidMons))
            {
                u8 typeDmg  = 20;
                u8 typeDmg2 = 20;

                u8 atkType1 = gBaseStats[species].type1;
                u8 atkType2 = gBaseStats[species].type2;
                u8 defType1 = gBattleMons[opposingBattler].type1;
                u8 defType2 = gBattleMons[opposingBattler].type2;

                ModulateByTypeEffectiveness(atkType1, defType1, defType2, &typeDmg);

                if (atkType2 != atkType1)
                {
                    ModulateByTypeEffectiveness(atkType2, defType1, defType2, &typeDmg2);
                    if (typeDmg < typeDmg2)
                        typeDmg = typeDmg2;
                }
                if (bestDmg < typeDmg)
                {
                    bestDmg = typeDmg;
                    bestMonId = i;
                }
            }
            else
            {
                invalidMons |= gBitTable[i];
            }
        }

        // Ok, we know the mon has the right typing but does it have at least one super effective move?
        if (bestMonId != PARTY_SIZE)
        {
            for (i = 0; i < MAX_MON_MOVES; i++)
            {
                move = GetMonData(&party[bestMonId], MON_DATA_MOVE1 + i);
				if (move != MOVE_NONE && gBattleMoves[move].power != 0 && AI_TypeCalc(move, gBattleMons[opposingBattler].species, gBattleMons[opposingBattler].ability) & MOVE_RESULT_SUPER_EFFECTIVE)
                    break;
            }

            if (i != MAX_MON_MOVES)
                return bestMonId; // Has both the typing and at least one super effective move.

            invalidMons |= gBitTable[bestMonId]; // Sorry buddy, we want something better.
        }
        else
        {
            invalidMons = ALL_MONS_FILTERED; // No viable mon to switch.
        }
    }
    return PARTY_SIZE;
}

void PrepareDisableStructForSwitchIn(u32 battler, const struct DisableStruct * disableStructCopy)
{
    s32 i;
    u8 * ptr;

    ptr = (u8 *)&gDisableStructs[battler];
    for (i = 0; i < sizeof(struct DisableStruct); i++)
        ptr[i] = 0;

    if (gBattleMoves[gCurrentMove].effect == EFFECT_BATON_PASS)
    {
        gDisableStructs[battler].substituteHP = disableStructCopy->substituteHP;
        gDisableStructs[battler].battlerWithSureHit = disableStructCopy->battlerWithSureHit;
        gDisableStructs[battler].perishSongTimer = disableStructCopy->perishSongTimer;
        gDisableStructs[battler].perishSongTimerStartValue = disableStructCopy->perishSongTimerStartValue;
        gDisableStructs[battler].battlerPreventingEscape = disableStructCopy->battlerPreventingEscape;
    }

    gDisableStructs[battler].isFirstTurn = 0; // 0 en lugar de 2 (que se pone para que al turno siguiente baje a 1) para que la IA no asuma que puede tirar alegremente Sorpresa
}

// Evalúa si quedan pokes sin filtrar
u8 MonsLeft(u8 bits)
{
    return bits != ALL_MONS_FILTERED;
}
// Evalúa si quedó un solo poke sin filtrar
u8 OnlyOneMonLeft(u8 bits)
{
    u32 b = (~bits) & ALL_MONS_FILTERED;
    // Esencialmente, mira rápido si el número es una potencia de 2
    // La única posibilidad de que un número binario sea potencia de 2
    // es que al restarle 1 su dígito líder pase de 1 a 0
	return b && !(b & (b-1));
}

// Devuelve el único poke que no ha sido filtrado.
// Asume que un solo poke quedó sin filtrar (véase OnlyOneMonLeft)
s32 GetUnfilteredMon(u8 bits)
{
    s32 i;

    for (i = 0; i < PARTY_SIZE; i++)
        if (bits == ((~gBitTable[i]) & ALL_MONS_FILTERED))
            return i;

    return PARTY_SIZE; // no debería suceder
}

bool8 HasYetToAttack(u32 battler)
{
    s32 i;

    if (*(&gBattleStruct->field_91) & gBitTable[battler])
        return FALSE;

    if (gBattleCommunication[gActiveBattler] == 3 || gBattleCommunication[gActiveBattler] == 2)
        return TRUE; // La IA todavía está pendiente de escoger acción

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE) && gBattleMons[gActiveBattler].hp == 0)
        return FALSE; // En individual, el turno se acaba si hay un KO

    for (i = gCurrentTurnActionNumber + 1; i < gBattlersCount; i++)
		
	if (gBattlerByTurnOrder[i] == battler && gActionsByTurnOrder[i] != B_ACTION_CANCEL_PARTNER && gActionsByTurnOrder[i] != B_ACTION_TRY_FINISH) // B_ACTION_CANCEL_PARTNER es igual a B_ACTION_FINISHED
            return TRUE;

    return FALSE;
}

void TransformIfImposter(u32 battler, u32 opposingBattler)
{
    s32 i;
    u8 *battleMonAttacker, *battleMonTarget;

    if (gBattleMons[battler].ability != ABILITY_IMPOSTER
      || gBattleMons[opposingBattler].hp == 0
      || (gBattleMons[opposingBattler].status2 & (STATUS2_TRANSFORMED | STATUS2_SUBSTITUTE))
      || (gStatuses3[opposingBattler] & STATUS3_SEMI_INVULNERABLE)
    )
        return; // no hay transformación

    gBattleMons[battler].status2 |= STATUS2_TRANSFORMED;
    gDisableStructs[battler].transformedMonPersonality = gBattleMons[opposingBattler].personality;

    battleMonAttacker = (u8*)(&gBattleMons[battler]);
    battleMonTarget = (u8*)(&gBattleMons[opposingBattler]);

    for (i = 0; i < offsetof(struct BattlePokemon, pp); i++)
        battleMonAttacker[i] = battleMonTarget[i];

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
		u16 known_move = gBattleResources->battleHistory->_usedMoves[(GetBattlerSide(opposingBattler) == B_SIDE_PLAYER ? 0 : PARTY_SIZE) + gBattlerPartyIndexes[opposingBattler]].moves[i];
        gBattleMons[battler].moves[i] = known_move; // puede ser MOVE_NONE cuando no conozca los movimientos
    }

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (gBattleMoves[gBattleMons[battler].moves[i]].pp < 5)
            gBattleMons[battler].pp[i] = gBattleMoves[gBattleMons[battler].moves[i]].pp;
        else
            gBattleMons[battler].pp[i] = 5;
    }
}

// Determina si un poke es vulnerable a Intimidate
bool8 VulnerableToIntimidate(u32 battler)
{
    if (gBattleMons[battler].statStages[STAT_ATK] == 0)
        return FALSE; // no puede bajar de -6

    if (gBattleMons[battler].status2 & STATUS2_SUBSTITUTE)
        return FALSE; // sub

    if (gSideTimers[GET_BATTLER_SIDE(battler)].mistTimer)
        return FALSE; // Neblina

    switch(gBattleMons[battler].ability) {
        case ABILITY_CLEAR_BODY:
        case ABILITY_HYPER_CUTTER:
        case ABILITY_WHITE_SMOKE:
        case ABILITY_SCRAPPY:
        case ABILITY_INNER_FOCUS:
        case ABILITY_OBLIVIOUS:
        case ABILITY_OWN_TEMPO:
            return FALSE;
    }
    return TRUE;
}

bool8 KnowsSomeRecoveryMove(u32 opposingBattler)
{
    u16 * move_history = gBattleResources->battleHistory->_usedMoves[(GetBattlerSide(opposingBattler) == B_SIDE_PLAYER ? 0 : PARTY_SIZE) + gBattlerPartyIndexes[opposingBattler]].moves;
    u8 moveLimitations = CheckMoveLimitations(opposingBattler, 0, MOVE_LIMITATION_CHOICE-1);
    u16 move;
    s32 i, j;

    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        move = gBattleMons[opposingBattler].moves[i];
        if (move && !(gBitTable[i] & moveLimitations) &&
           (
            gBattleMoves[move].effect == EFFECT_RESTORE_HP
         || gBattleMoves[move].effect == EFFECT_SOFTBOILED
         || gBattleMoves[move].effect == EFFECT_MORNING_SUN
         || gBattleMoves[move].effect == EFFECT_MOONLIGHT
         || gBattleMoves[move].effect == EFFECT_SHORE_UP
         || gBattleMoves[move].effect == EFFECT_SYNTHESIS
         || gBattleMoves[move].effect == EFFECT_REST
           ))
            for (j = 0; j < MAX_MON_MOVES; j++)
                if (move_history[j] == move)
                    return TRUE;
    }
    return FALSE;
}

#define IGNORE_REFLECT_AND_LIGHT_SCREEN_IF_ABOUT_TO_FINISH(targets_side) \
{                                                                        \
  if ((gSideStatuses[targets_side] & SIDE_STATUS_REFLECT)                \
      && gSideTimers[targets_side].reflectTimer == 1)                    \
    gSideStatuses[targets_side] &= ~SIDE_STATUS_REFLECT;                 \
  if ((gSideStatuses[targets_side] & SIDE_STATUS_LIGHTSCREEN)            \
      && gSideTimers[targets_side].lightscreenTimer == 1)                \
    gSideStatuses[targets_side] &= ~SIDE_STATUS_LIGHTSCREEN;             \
}

#define SET_WEATHER(ability) {              \
  if (ability == ABILITY_DRIZZLE)           \
    gBattleWeather = WEATHER_RAIN_ANY;      \
  if (ability == ABILITY_SAND_STREAM)       \
    gBattleWeather = WEATHER_SANDSTORM_ANY; \
  if (ability == ABILITY_DROUGHT)           \
    gBattleWeather = WEATHER_SUN_ANY;       \
  if (ability == ABILITY_SNOW_WARNING)      \
    gBattleWeather = WEATHER_HAIL_ANY;      \
}

#define IGNORE_WEATHER_IF_ABOUT_TO_FINISH() { \
  if (gWishFutureKnock.weatherDuration == 1 && !(gBattleWeather & (WEATHER_RAIN_PERMANENT | WEATHER_SANDSTORM_PERMANENT | WEATHER_SUN_PERMANENT | WEATHER_HAIL_PERMANENT))) gBattleWeather = 0; \
}

#define NHKO_FASTER(i)            (nhko[i][0])
#define NHKO_GIVEN(i)             (nhko[i][1])
#define NHKO_TAKEN(i)             (nhko[i][2])
#define NHKO_OVERCOMES_RECOVER(i) (nhko[i][3])

// Prepara una tabla con tres entradas para cada poke del equipo:
// si es más rápido que el rival, qué nHKO le hace al rival, qué nHKO espera
// recibir del rival y si le quita un 56.25% de los PS con algún ataque
void PrepareNHKOTable(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 nhko[][4])
{
    if (MonsLeft(filteredMons))
    {
        s32 i;
        struct BattlePokemon currentMon = gBattleMons[gActiveBattler];
		struct DisableStruct disableStructCopy = gDisableStructs[gActiveBattler];
        u16 partyIndex = gBattlerPartyIndexes[gActiveBattler];
        const u16 AISideStatuses = gSideStatuses[GetBattlerSide(gActiveBattler)];
        const u16 oppositeSideStatuses = gSideStatuses[GetBattlerSide(opposingBattler)];
        const u16 weather = gBattleWeather;
        const bool8 opponentHasYetToAttack = HasYetToAttack(opposingBattler);
        const u32 newStatus2 = (gCurrentMove == MOVE_BATON_PASS ? (currentMon.status2 & STATUS2_KEPT_BY_SUBSTITUTE) : 0);

        IGNORE_REFLECT_AND_LIGHT_SCREEN_IF_ABOUT_TO_FINISH(GetBattlerSide(opposingBattler));
        if (!opponentHasYetToAttack)
            IGNORE_REFLECT_AND_LIGHT_SCREEN_IF_ABOUT_TO_FINISH(GetBattlerSide(gActiveBattler));

        for (i = firstId; i < lastId; i++)
            if (!(gBitTable[i] & filteredMons))
            {
                bool8 intimidateApplies;

                PokemonToBattleMon(&party[i], &gBattleMons[gActiveBattler], gCurrentMove == MOVE_BATON_PASS);
                gBattleMons[gActiveBattler].status2 = newStatus2;
                gBattlerPartyIndexes[gActiveBattler] = i;
                intimidateApplies = gBattleMons[gActiveBattler].ability == ABILITY_INTIMIDATE && VulnerableToIntimidate(opposingBattler);
                if (intimidateApplies)
                gBattleMons[opposingBattler].statStages[STAT_ATK] -= 1;
				PrepareDisableStructForSwitchIn(gActiveBattler, &disableStructCopy);
				TransformIfImposter(gActiveBattler, opposingBattler);
                SET_WEATHER(gBattleMons[gActiveBattler].ability);

                // Guarda en la primera posición un 1 si es más rápido que el rival.
                // Guarda en la segunda posición el nHKO que le hace al rival,
                // y en la tercera el que espera recibir del rival
                if (!opponentHasYetToAttack) IGNORE_WEATHER_IF_ABOUT_TO_FINISH();
                NHKO_TAKEN(i) = CalculateNHKO(opposingBattler, gActiveBattler, FALSE, MOVE_NONE, FALSE, TRUE);
                if (opponentHasYetToAttack) IGNORE_WEATHER_IF_ABOUT_TO_FINISH();

                NHKO_FASTER(i) = ((GetWhoStrikesFirst(gActiveBattler, opposingBattler, TRUE) == 0) ? 1 : 0);

                NHKO_GIVEN(i) = CalculateNHKO(gActiveBattler, opposingBattler, TRUE, MOVE_NONE, FALSE, TRUE);

                {
                    // Guarda en la cuarta posición si le haría OHKO al rival con un 56,25% de los PS
                    // (o 2HKO si tiene sub)
                    u16 current_opponent_hp = gBattleMons[opposingBattler].hp;
                    bool8 hasSub = (gBattleMons[opposingBattler].status2 & STATUS2_SUBSTITUTE) && gDisableStructs[opposingBattler].substituteHP > 0;

                    gBattleMons[opposingBattler].hp = (gBattleMons[opposingBattler].maxHP * 9) / 16 + 1;
                    NHKO_OVERCOMES_RECOVER(i) = (CalculateNHKO(gActiveBattler, opposingBattler, TRUE, MOVE_NONE, FALSE, TRUE) == (hasSub ? 2 : 1)) ? 1 : 0;
                    gBattleMons[opposingBattler].hp = current_opponent_hp;
                }

			   if (intimidateApplies)
               gBattleMons[opposingBattler].statStages[STAT_ATK] += 1;

          gBattleWeather = weather;
			}
        
        gBattleMons[gActiveBattler] = currentMon;
		gDisableStructs[gActiveBattler] = disableStructCopy;
        gBattlerPartyIndexes[gActiveBattler] = partyIndex;
        gSideStatuses[GetBattlerSide(gActiveBattler)] = AISideStatuses;
        gSideStatuses[GetBattlerSide(opposingBattler)] = oppositeSideStatuses;
    }
}

// Evita meter un poke antes de que ataque el rival cuando puede recibir KO
// en el cambio simplemente repitiendo el último ataque que lanzó al actual poke de la IA
// (si es que este estaba presente cuando se eligió tal ataque)
u8 FilterSwitchInsThatMightGetKOedBeforeEndOfTurn(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 a[][4])
{
    u16 move = gLastMoves[opposingBattler];
    u8 moveLimitations;
    s32 i;

    if (!HasYetToAttack(opposingBattler) || move == MOVE_NONE || move == 0xFFFF || gBattleMoves[move].power == 0 || gDisableStructs[gActiveBattler].isFirstTurn != 0)
        return filteredMons;

    // Comprueba que el rival seguir usando el movimiento
    moveLimitations = CheckMoveLimitations(opposingBattler, 0, MOVE_LIMITATION_CHOICE-1);
    for (i = 0; i < MAX_MON_MOVES; i++)
        if (gBattleMons[opposingBattler].moves[i] == move && !(gBitTable[i] & moveLimitations))
            break;

    if (i != MAX_MON_MOVES)
    {
        u8 nhko;
        struct BattlePokemon currentMon = gBattleMons[gActiveBattler];
        struct DisableStruct disableStructCopy = gDisableStructs[gActiveBattler];
        u16 partyIndex = gBattlerPartyIndexes[gActiveBattler];
    	const u16 weather = gBattleWeather;
        const u32 newStatus2 = (gCurrentMove == MOVE_BATON_PASS ? (currentMon.status2 & STATUS2_KEPT_BY_SUBSTITUTE) : 0);

        for (i = firstId; i < lastId; i++)
            if (!(gBitTable[i] & filteredMons))
            {
                bool8 intimidateApplies;

                PokemonToBattleMon(&party[i], &gBattleMons[gActiveBattler], gCurrentMove == MOVE_BATON_PASS);
                gBattleMons[gActiveBattler].status2 = newStatus2;
                gBattlerPartyIndexes[gActiveBattler] = i;
                intimidateApplies = gBattleMons[gActiveBattler].ability == ABILITY_INTIMIDATE && VulnerableToIntimidate(opposingBattler);
                if (intimidateApplies)
                    gBattleMons[opposingBattler].statStages[STAT_ATK] -= 1;

                PrepareDisableStructForSwitchIn(gActiveBattler, &disableStructCopy);
                TransformIfImposter(gActiveBattler, opposingBattler);
                SET_WEATHER(gBattleMons[gActiveBattler].ability);

                nhko = CalculateNHKO(opposingBattler, gActiveBattler, FALSE, move, FALSE, FALSE);
				
		// si recibe OHKO o, siendo más lento, 2HKO, queda descartado
                if (nhko == 1 || (nhko == 2 && GetWhoStrikesFirst(gActiveBattler, opposingBattler, TRUE) != 0))
                    filteredMons |= gBitTable[i];

                if (intimidateApplies)
                    gBattleMons[opposingBattler].statStages[STAT_ATK] += 1;

                gBattleWeather = weather;
            }

        gBattleMons[gActiveBattler] = currentMon;
        gDisableStructs[gActiveBattler] = disableStructCopy;
        gBattlerPartyIndexes[gActiveBattler] = partyIndex;
    }

    return filteredMons;
}

// Evita meter un poke si recibe un OHKO de algún movimiento de prioridad del rival,
// salvo si puede hacerle OHKO antes con otro movimiento de prioridad
u8 FilterFragileMonsAgainstPriority(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 a[][4])
{
    u16 move;
    u16 opponent_priority_moves[4] = {0, 0, 0, 0};
    u8 moveLimitations_ai, moveLimitations_opponent = CheckMoveLimitations(opposingBattler, 0, MOVE_LIMITATION_CHOICE-1);
    s32 i, move_i, move_j;
    bool8 skipMon;

    // Anota los movimientos de prioridad que conoce del rival y que el rival puede usar
    for (move_i = 0; move_i < MAX_MON_MOVES; move_i++)
    {
        move = gBattleMons[opposingBattler].moves[move_i];
        if (move && gBattleMoves[move].effect == EFFECT_QUICK_ATTACK && !(gBitTable[move_i] & moveLimitations_opponent))
            for (move_j = 0; move_j < MAX_MON_MOVES; move_j++)
                if (gBattleResources->battleHistory->_usedMoves[(GetBattlerSide(opposingBattler) == B_SIDE_PLAYER ? 0 : PARTY_SIZE) + gBattlerPartyIndexes[opposingBattler]].moves[move_j] == move)
                {
                    opponent_priority_moves[move_i] = move;
                    break;
                }
    }

    // Solo procede si conoce algún movimiento de prioridad del rival
    if (opponent_priority_moves[0] != 0 || opponent_priority_moves[1] != 0 || opponent_priority_moves[2] != 0 || opponent_priority_moves[3] != 0)
    {
        struct BattlePokemon currentMon = gBattleMons[gActiveBattler];
        struct DisableStruct disableStructCopy = gDisableStructs[gActiveBattler];
        u16 partyIndex = gBattlerPartyIndexes[gActiveBattler];
        const u16 AISideStatuses = gSideStatuses[GetBattlerSide(gActiveBattler)];
        const u16 oppositeSideStatuses = gSideStatuses[GetBattlerSide(opposingBattler)];
        const u16 weather = gBattleWeather;
        const u32 newStatus2 = (gCurrentMove == MOVE_BATON_PASS ? (currentMon.status2 & STATUS2_KEPT_BY_SUBSTITUTE) : 0);

        IGNORE_REFLECT_AND_LIGHT_SCREEN_IF_ABOUT_TO_FINISH(GetBattlerSide(opposingBattler));
        IGNORE_REFLECT_AND_LIGHT_SCREEN_IF_ABOUT_TO_FINISH(GetBattlerSide(gActiveBattler));

        for (i = firstId; i < lastId; i++)
            if (!(gBitTable[i] & filteredMons))
            {
                bool8 intimidateApplies;

                PokemonToBattleMon(&party[i], &gBattleMons[gActiveBattler], gCurrentMove == MOVE_BATON_PASS);
                gBattleMons[gActiveBattler].status2 = newStatus2;
                gBattlerPartyIndexes[gActiveBattler] = i;
                intimidateApplies = gBattleMons[gActiveBattler].ability == ABILITY_INTIMIDATE && VulnerableToIntimidate(opposingBattler);
                if (intimidateApplies)
                    gBattleMons[opposingBattler].statStages[STAT_ATK] -= 1;

                PrepareDisableStructForSwitchIn(gActiveBattler, &disableStructCopy);
                TransformIfImposter(gActiveBattler, opposingBattler);
                SET_WEATHER(gBattleMons[gActiveBattler].ability);
                IGNORE_WEATHER_IF_ABOUT_TO_FINISH();

                skipMon = FALSE;

                // Primero, comprueba que no le pueda meter KO al rival con prioridad antes
				moveLimitations_ai = CheckMoveLimitations(gActiveBattler, 0, 0xFF);
                for (move_i = 0; move_i < MAX_MON_MOVES && !skipMon; move_i++)
                {
                    move = gBattleMons[gActiveBattler].moves[move_i];
                    if (move && !(gBitTable[move_i] & moveLimitations_ai) && (
                        (gBattleMoves[move].effect == EFFECT_QUICK_ATTACK && GetWhoStrikesFirst(gActiveBattler, opposingBattler, TRUE) == 0) // es más rápido y tiene prioridad
                        || gBattleMoves[move].effect == EFFECT_FAKE_OUT // o tiene Fake Out
                      ) && CalculateNHKO(gActiveBattler, opposingBattler, TRUE, move, FALSE, FALSE) == 1)
                        skipMon = TRUE;
                }

                // Si recibe OHKO con un mov de prioridad, queda descartado
                if (!skipMon)
                    for (move_i = 0; move_i < MAX_MON_MOVES; move_i++)
                    {
                        move = opponent_priority_moves[move_i];
                        if (move && CalculateNHKO(opposingBattler, gActiveBattler, FALSE, move, FALSE, FALSE) == 1)
                        {
                            filteredMons |= gBitTable[i];
                            break;
                        }
                    }

                if (intimidateApplies)
                    gBattleMons[opposingBattler].statStages[STAT_ATK] += 1;

                gBattleWeather = weather;
            }

        gBattleMons[gActiveBattler] = currentMon;
        gDisableStructs[gActiveBattler] = disableStructCopy;
        gBattlerPartyIndexes[gActiveBattler] = partyIndex;
        gSideStatuses[GetBattlerSide(gActiveBattler)] = AISideStatuses;
        gSideStatuses[GetBattlerSide(opposingBattler)] = oppositeSideStatuses;
    }

    return filteredMons;
}

// Excluye los pokes con Imposter si, en caso de entrar, no se van a transformar
u8 FilterImposterIfUseless(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 a[][4])
{
    s32 i;
    // Imposter falla si el objetivo está debilitado, transformado,
    // con sustituto o en estado semiinvulnerable (por Dig, Fly, etc)
    if ((gBattleMons[opposingBattler].hp == 0
      || (gBattleMons[opposingBattler].status2 & (STATUS2_TRANSFORMED | STATUS2_SUBSTITUTE))
      || (gStatuses3[opposingBattler] & STATUS3_SEMI_INVULNERABLE)
    ))
        for (i = firstId; i < lastId; i++)
        {
            u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
            u8 ability;

            if (GetMonData(&party[i], MON_DATA_ABILITY_NUM) != 0)
                ability = gBaseStats[species].abilities[1];
            else
                ability = gBaseStats[species].abilities[0];

            if (ability == ABILITY_IMPOSTER)
                filteredMons |= gBitTable[i];
        }

    return filteredMons;
}

// Excluye los pokes con Truant si no pueden tocar al rival
u8 FilterTruantIfUseless(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 a[][4])
{
    u8 truantMons = 0, vulnerableTruantMons = 0;
    u16 species;
    u8 ability;
    s32 i;

    for (i = firstId; i < lastId; i++)
        if (!(gBitTable[i] & filteredMons))
        {
            species = GetMonData(&party[i], MON_DATA_SPECIES);
            if (GetMonData(&party[i], MON_DATA_ABILITY_NUM) != 0)
                ability = gBaseStats[species].abilities[1];
            else
                ability = gBaseStats[species].abilities[0];

            if (ability == ABILITY_TRUANT)
                truantMons |= gBitTable[i];
        }
    if (truantMons)
    {
        if (!HasYetToAttack(opposingBattler))
        {
            struct BattlePokemon currentMon = gBattleMons[gActiveBattler];
			struct DisableStruct disableStructCopy = gDisableStructs[gActiveBattler];
            u16 partyIndex = gBattlerPartyIndexes[gActiveBattler];
            const u32 newStatus2 = (gCurrentMove == MOVE_BATON_PASS ? (currentMon.status2 & STATUS2_KEPT_BY_SUBSTITUTE) : 0);
			for (i = firstId; i < lastId; i++)
                if ((gBitTable[i] & truantMons))
                {
                    PokemonToBattleMon(&party[i], &gBattleMons[gActiveBattler], gCurrentMove == MOVE_BATON_PASS);
                    gBattleMons[gActiveBattler].status2 = newStatus2;
                    gBattlerPartyIndexes[gActiveBattler] = i;
					PrepareDisableStructForSwitchIn(gActiveBattler, &disableStructCopy);

                    if (IsTruantMonVulnerable(gActiveBattler, opposingBattler))
                        vulnerableTruantMons |= gBitTable[i];
                }
            
            gBattleMons[gActiveBattler] = currentMon;
			gDisableStructs[gActiveBattler] = disableStructCopy;
            gBattlerPartyIndexes[gActiveBattler] = partyIndex;
        }
        else // Si el rival no ha atacado, podría anticiparse aunque sea más lento
        {
            u16 currentSpeed = gBattleMons[gActiveBattler].speed;
            gBattleMons[gActiveBattler].speed = 0;

            if (IsTruantMonVulnerable(gActiveBattler, opposingBattler))
                vulnerableTruantMons = truantMons;
            
            gBattleMons[gActiveBattler].speed = currentSpeed;
        }
    }
    return (filteredMons | vulnerableTruantMons);
}

// Excluye los Shedinja que corran peligro
u8 FilterShedinjaIfVulnerable(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 a[][4])
{
    u8 sheds = 0, vulnerableSheds = 0;
    u16 species;
    s32 i;

    for (i = firstId; i < lastId; i++)
        if (!(gBitTable[i] & filteredMons))
        {
            species = GetMonData(&party[i], MON_DATA_SPECIES);
            if (species == SPECIES_SHEDINJA)
                sheds |= gBitTable[i];
        }
    if (sheds && (gBattleWeather & (WEATHER_SANDSTORM_ANY | WEATHER_HAIL_ANY)) && !(!(gBattleWeather & (WEATHER_SANDSTORM_PERMANENT | WEATHER_HAIL_PERMANENT)) && gWishFutureKnock.weatherDuration == 1)) // si hay arena o granizo y no está a punto de acabar
        vulnerableSheds = sheds; // entonces todos los Shedinja son vulnerables
    else if (sheds)
    {
        struct BattlePokemon currentMon = gBattleMons[gActiveBattler];
		struct DisableStruct disableStructCopy = gDisableStructs[gActiveBattler];
        u16 partyIndex = gBattlerPartyIndexes[gActiveBattler];
				u16 savedCurrentMove = gCurrentMove;
        const u16 oppositeSideStatuses = gSideStatuses[GetBattlerSide(opposingBattler)];
        const u16 weather = gBattleWeather;
        const u32 newStatus2 = (gCurrentMove == MOVE_BATON_PASS ? (currentMon.status2 & STATUS2_KEPT_BY_SUBSTITUTE) : 0);

        IGNORE_REFLECT_AND_LIGHT_SCREEN_IF_ABOUT_TO_FINISH(GetBattlerSide(opposingBattler));
        IGNORE_WEATHER_IF_ABOUT_TO_FINISH();

        for (i = firstId; i < lastId; i++)
            if ((gBitTable[i] & sheds))
            {
                // Evita sacar a cada Shedinja si es vulnerable al rival,
                // excepto cuando puede darle KO (lo cual requiere que ya haya atacado)
                bool8 vulnerable = TRUE;
                s32 move_i;
                u16 move;
                PokemonToBattleMon(&party[i], &gBattleMons[gActiveBattler], gCurrentMove == MOVE_BATON_PASS);
                gBattleMons[gActiveBattler].status2 = newStatus2;
                gBattlerPartyIndexes[gActiveBattler] = i;
				PrepareDisableStructForSwitchIn(gActiveBattler, &disableStructCopy);

	if (HasYetToAttack(opposingBattler))
                    gBattleMons[gActiveBattler].speed = 0; // Si el rival no ha atacado, da igual la velocidad de Shedinja (salvo predicción)

                for (move_i = 0; vulnerable && move_i < MAX_MON_MOVES; move_i++) {
                    move = GetMonData(&party[i], MON_DATA_MOVE1 + move_i);
                    if (move != MOVE_NONE && gBattleMoves[move].effect != EFFECT_PROTECT && !OurShedinjaIsVulnerable(gActiveBattler, opposingBattler, move))
                        vulnerable = FALSE;
                }

                if (vulnerable)
                    vulnerableSheds |= gBitTable[i];
            }
        gCurrentMove = savedCurrentMove;
        gBattleMons[gActiveBattler] = currentMon;
		gDisableStructs[gActiveBattler] = disableStructCopy;
        gBattlerPartyIndexes[gActiveBattler] = partyIndex;
        gSideStatuses[GetBattlerSide(opposingBattler)] = oppositeSideStatuses;
        gBattleWeather = weather;
    }
    return (filteredMons | vulnerableSheds);
}

u8 FilterChoiceMonsWayTooWeak(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 nhko[][4])
{
    s32 i, j;
    u16 item, move;

    for (i = firstId; i < lastId; i++)
        if (!(gBitTable[i] & filteredMons))
        {
            item = GetMonData(&party[i], MON_DATA_HELD_ITEM);

            if (item == ITEM_CHOICE_BAND || item == ITEM_CHOICE_SPECS || item == ITEM_CHOICE_SCARF)
            {
                bool8 hasOHKOmove = FALSE;

                for (j = 0; !hasOHKOmove && j < MAX_MON_MOVES; j++)
                {
                    move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
                    if (move != MOVE_NONE && gBattleMoves[move].effect == EFFECT_OHKO)
                        hasOHKOmove = TRUE;
                }

                // Excluye al candidato en caso de 5HKO o peor, o de 4HKO siendo más lento
                if (!hasOHKOmove && NHKO_GIVEN(i) >= 4 && (NHKO_GIVEN(i) > 4 || !NHKO_FASTER(i)))
                    filteredMons |= gBitTable[i];
            }
        }

    return filteredMons;
}

u8 FilterChoiceMonsNotPowerfulEnough(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 nhko[][4])
{
    s32 i, j;
    u16 item, move;

    for (i = firstId; i < lastId; i++)
        if (!(gBitTable[i] & filteredMons))
        {
            item = GetMonData(&party[i], MON_DATA_HELD_ITEM);

            if (item == ITEM_CHOICE_BAND || item == ITEM_CHOICE_SPECS || item == ITEM_CHOICE_SCARF)
            {
                bool8 hasOHKOmove = FALSE;

                for (j = 0; !hasOHKOmove && j < MAX_MON_MOVES; j++)
                {
                    move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
                    if (move != MOVE_NONE && gBattleMoves[move].effect == EFFECT_OHKO)
                        hasOHKOmove = TRUE;
                }

                if (!hasOHKOmove && NHKO_GIVEN(i) > 2)
                    filteredMons |= gBitTable[i];
            }
        }

    return filteredMons;
}

u8 FilterOpponentCanBeTrappedAndDefeated(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 nhko[][4])
{
    s32 i;
    u8 min_opponent_attacks = HasYetToAttack(opposingBattler) ? 1 : 0;
    bool8 opponentIsGhost = IS_BATTLER_OF_TYPE(opposingBattler, TYPE_GHOST),
          opponentIsGrounded = !IS_BATTLER_OF_TYPE(opposingBattler, TYPE_FLYING) && gBattleMons[opposingBattler].ability != ABILITY_LEVITATE,
          opponentIsSteel = IS_BATTLER_OF_TYPE(opposingBattler, TYPE_STEEL);
    bool8 opponentHasPhazingMoves = FALSE;
    u16 * opponentHistory = gBattleResources->battleHistory->_usedMoves[(GetBattlerSide(opposingBattler) == B_SIDE_PLAYER ? 0 : PARTY_SIZE) + gBattlerPartyIndexes[opposingBattler]].moves;
    if (((gStatuses3[opposingBattler] & STATUS3_ROOTED) && !opponentIsGhost)
     || (gBattleTypeFlags & (BATTLE_TYPE_ARENA | BATTLE_TYPE_PALACE)))
        return filteredMons; // El rival ya está atrapado, no hace falta atraparlo

    for (i = 0; i < MAX_MON_MOVES && !opponentHasPhazingMoves; i++)
        if (opponentHistory[i] != MOVE_NONE && gBattleMoves[opponentHistory[i]].effect == EFFECT_ROAR)
            opponentHasPhazingMoves = TRUE;

    for (i = firstId; i < lastId; i++)
        if (!(gBitTable[i] & filteredMons))
        {
            u8 num_attacks_taken_until_KO = NHKO_GIVEN(i) - NHKO_FASTER(i) + min_opponent_attacks;
            u8 nhko_taken = NHKO_TAKEN(i);

            // Tiene que dar revenge kill, o hacer KO de sobra antes de recibirlo
            if (num_attacks_taken_until_KO > 0
             && !(num_attacks_taken_until_KO == 1 && nhko_taken >= 3 && !opponentHasPhazingMoves)
             && !(num_attacks_taken_until_KO == 2 && nhko_taken >= 5 && !opponentHasPhazingMoves))
                filteredMons |= gBitTable[i];
            else
            {
                u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
                u8 ability;

                if (GetMonData(&party[i], MON_DATA_ABILITY_NUM) != 0)
                    ability = gBaseStats[species].abilities[1];
                else
                    ability = gBaseStats[species].abilities[0];

                // Tiene que atrapar al rival
                if (!(ability == ABILITY_SHADOW_TAG && !opponentIsGhost && gBattleMons[opposingBattler].ability != ABILITY_SHADOW_TAG)
                 && !(ability == ABILITY_ARENA_TRAP && !opponentIsGhost && opponentIsGrounded)
                 && !(ability == ABILITY_MAGNET_PULL && opponentIsSteel))
                {
                    // También considera que el rival será atrapado si le da OHKO con Pursuit
                    bool8 canKOwithPursuit = FALSE;

                    if (NHKO_GIVEN(i) == 1 && (GetMonData(&party[i], MON_DATA_MOVE1) == MOVE_PURSUIT || GetMonData(&party[i], MON_DATA_MOVE2) == MOVE_PURSUIT || GetMonData(&party[i], MON_DATA_MOVE3) == MOVE_PURSUIT || GetMonData(&party[i], MON_DATA_MOVE4) == MOVE_PURSUIT))
                    {
                        u8 moveLimitations;
                        s32 move_i;
                        struct BattlePokemon currentMon = gBattleMons[gActiveBattler];
                        struct DisableStruct disableStructCopy = gDisableStructs[gActiveBattler];
                        u16 partyIndex = gBattlerPartyIndexes[gActiveBattler];
                        const u16 oppositeSideStatuses = gSideStatuses[GetBattlerSide(opposingBattler)];
                        const u16 weather = gBattleWeather;
                        const u32 newStatus2 = (gCurrentMove == MOVE_BATON_PASS ? (currentMon.status2 & STATUS2_KEPT_BY_SUBSTITUTE) : 0);

                        PokemonToBattleMon(&party[i], &gBattleMons[gActiveBattler], gCurrentMove == MOVE_BATON_PASS);
                        gBattleMons[gActiveBattler].status2 = newStatus2;
                        gBattlerPartyIndexes[gActiveBattler] = i;
                        PrepareDisableStructForSwitchIn(gActiveBattler, &disableStructCopy);

                        IGNORE_REFLECT_AND_LIGHT_SCREEN_IF_ABOUT_TO_FINISH(GetBattlerSide(opposingBattler));
                        SET_WEATHER(gBattleMons[gActiveBattler].ability);
                        IGNORE_WEATHER_IF_ABOUT_TO_FINISH();

                        moveLimitations = CheckMoveLimitations(gActiveBattler, 0, 0xFF);
                        if (CalculateNHKO(gActiveBattler, opposingBattler, TRUE, MOVE_PURSUIT, FALSE, FALSE) == 1)
                            for (move_i = 0; move_i < MAX_MON_MOVES && !canKOwithPursuit; move_i++)
                                if (gBattleMons[gActiveBattler].moves[move_i] == MOVE_PURSUIT && !(gBitTable[move_i] & moveLimitations))
                                    canKOwithPursuit = TRUE; // hace KO con Persecución y puede usarlo

                        gBattleMons[gActiveBattler] = currentMon;
                        gDisableStructs[gActiveBattler] = disableStructCopy;
                        gBattlerPartyIndexes[gActiveBattler] = partyIndex;
                        gSideStatuses[GetBattlerSide(opposingBattler)] = oppositeSideStatuses;
                        gBattleWeather = weather;
                    }
                    if (!canKOwithPursuit)
                        filteredMons |= gBitTable[i];
                }
             }
        }

    return filteredMons;
}

u8 FilterRevengeKill(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 nhko[][4])
{
    s32 i;

    if (!HasYetToAttack(opposingBattler)) // si el rival tiene que atacar, poco revenge kill se puede hacer
        for (i = firstId; i < lastId; i++)
            if (!(gBitTable[i] & filteredMons)
             && !(
                   NHKO_FASTER(i)     // tiene que ser más rápido
                && NHKO_GIVEN(i) == 1 // y dar OHKO
             ))
                filteredMons |= gBitTable[i];

    return filteredMons;
}

u8 FilterKOTaking1Hit(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 nhko[][4])
{
    s32 i;
    u8 min_opponent_attacks = HasYetToAttack(opposingBattler) ? 1 : 0;

    for (i = firstId; i < lastId; i++)
        if (!(gBitTable[i] & filteredMons))
        {
            // El número de ataques que va a recibir antes de hacer KO al rival es
            // el nHKO que le hace al rival, menos 1 si es más rápido,
            // más 1 si el rival todavía tiene que atacar
            u8 num_attacks_taken_until_KO = NHKO_GIVEN(i) - NHKO_FASTER(i) + min_opponent_attacks;
		
            u8 nhko_taken = NHKO_TAKEN(i);
            
            if (num_attacks_taken_until_KO > 0 && (num_attacks_taken_until_KO > 1 || nhko_taken < 3 || (!NHKO_OVERCOMES_RECOVER(i) && KnowsSomeRecoveryMove(opposingBattler))))
                filteredMons |= gBitTable[i];
        }

    return filteredMons;
}

u8 FilterKOTaking2Hits(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 nhko[][4])
{
    s32 i;
    u8 min_opponent_attacks = HasYetToAttack(opposingBattler) ? 1 : 0;

    for (i = firstId; i < lastId; i++)
        if (!(gBitTable[i] & filteredMons))
        {
            // El número de ataques que va a recibir antes de hacer KO al rival es
            // el nHKO que le hace al rival, menos 1 si es más rápido,
            // más 1 si el rival todavía tiene que atacar
            u8 num_attacks_taken_until_KO = NHKO_GIVEN(i) - NHKO_FASTER(i) + min_opponent_attacks;
            u8 nhko_taken = NHKO_TAKEN(i);
            
            if (num_attacks_taken_until_KO > 0 && ((!(num_attacks_taken_until_KO <= 1 && nhko_taken >= 3) && (num_attacks_taken_until_KO > 2 || nhko_taken < 5)) || (!NHKO_OVERCOMES_RECOVER(i) && KnowsSomeRecoveryMove(opposingBattler))))
                filteredMons |= gBitTable[i];
        }

    return filteredMons;
}

u8 FilterCanAttackWonderGuardOpponent(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 nhko[][4])
{
    s32 i;
    u8 monsWithoutDamagingWeather = 0;
    bool8 someMonHasDamagingWeather = FALSE;

    if (gBattleMons[opposingBattler].ability == ABILITY_WONDER_GUARD)
        for (i = firstId; i < lastId; i++)
            if (!(gBitTable[i] & filteredMons))
            {
                bool8 hasANonDamagingUsefulMove = FALSE;
                s32 j;
                u16 move;

                // Mira si puede meter un clima que dañe al rival
                if (gBattleMons[opposingBattler].hp == 1)
                {
                    u16 species = GetMonData(&party[i], MON_DATA_SPECIES);
                    u8 monAbility = gBaseStats[species].abilities[(GetMonData(&party[i], MON_DATA_ABILITY_NUM) != 0) ? 1 : 0];

                    if (monAbility == ABILITY_SAND_STREAM || monAbility == ABILITY_SNOW_WARNING)
                    {
                        someMonHasDamagingWeather = TRUE;
                        continue;
                    }
                    monsWithoutDamagingWeather |= gBitTable[i];
                }

                // Mira si le hace algo mejor que 5HKO (y por tanto le hace algo)
                if (NHKO_GIVEN(i) < 5)
                    continue;

                // Mira si puede dañar con algún movimiento que no sea de daño directo
                for (j = 0; !hasANonDamagingUsefulMove && j < MAX_MON_MOVES; j++)
                {
                    move = GetMonData(&party[i], MON_DATA_MOVE1 + j);
                    if (NonDamagingMoveIsGoodAgainstWonderGuardOpponent(move, opposingBattler))
                        hasANonDamagingUsefulMove = TRUE;
                }

                // Si ha llegado hasta aquí, es que no puede atacar salvo a lo sumo con movs que no sean de daño
                if (!hasANonDamagingUsefulMove)
                    filteredMons |= gBitTable[i];
            }

    // Si algún poke convoca clima y, si entra, causaría daño ese mismo turno, prefiere meter uno de esos
    if (someMonHasDamagingWeather && (gBattleMainFunc != BattleTurnPassed || gBattleStruct->turnCountersTracker < 7))
	// 7 es ENDTURN_SANDSTORM
        return filteredMons | monsWithoutDamagingWeather;

    return filteredMons;
}

u8 FilterTakesMostHits(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 nhko[][4])
{
    u8 max_hits_taken = 1;
    s32 i;

    // Calcula el nHKO menos malo que algún poke de la IA recibe del rival
    for (i = firstId; i < lastId; i++)
        if (!(gBitTable[i] & filteredMons) && NHKO_TAKEN(i) > max_hits_taken)
            max_hits_taken = NHKO_TAKEN(i);

    // Filtra los pokes que tienen un nHKO peor que el menos malo
    for (i = firstId; i < lastId; i++)
        if (!(gBitTable[i] & filteredMons) && NHKO_TAKEN(i) < max_hits_taken)
            filteredMons |= gBitTable[i];

    return filteredMons;
}

u8 FilterKOsInLessHits(struct Pokemon *party, s32 firstId, s32 lastId, u8 filteredMons, u32 opposingBattler, u8 nhko[][4])
{
    u8 min_hits_given = 5;
    s32 i;
	
	// Calcula el mejor nHKO que algún poke de la IA da al rival
    // Se resta 1 si el poke de la IA es más rápido (se evalúa igual dar 2HKO siendo más lento que 3HKO siendo más rápido)
    for (i = firstId; i < lastId; i++)
        if (!(gBitTable[i] & filteredMons) && (NHKO_GIVEN(i) - NHKO_FASTER(i)) < min_hits_given)
            min_hits_given = NHKO_GIVEN(i);

    // Filtra los pokes que tienen un nHKO peor
    for (i = firstId; i < lastId; i++)
        if (!(gBitTable[i] & filteredMons) && (NHKO_GIVEN(i) - NHKO_FASTER(i)) > min_hits_given)
            filteredMons |= gBitTable[i];

    return filteredMons;
}


u8 GetMostSuitableMonToSwitchInto(bool8 howTolerableIsNotChanging)
{
    u8 opposingBattler;
	s32 bestDmg;
    u8 bestMonId;
    u8 battlerIn1, battlerIn2;
    s32 firstId;
    s32 lastId; // + 1
    struct Pokemon *party;
    s32 i, j;
    u8 invalidMons;
    u8 filteredMons, newFilteredMons;
    u16 move;

    bool8 notChangingIsPossible = howTolerableIsNotChanging != NOT_CHANGING_IS_IMPOSSIBLE;
    bool8 notChangingIsAcceptable = howTolerableIsNotChanging == NOT_CHANGING_IS_ACCEPTABLE;

    if (*(gBattleStruct->monToSwitchIntoId + gActiveBattler) != PARTY_SIZE)
        return *(gBattleStruct->monToSwitchIntoId + gActiveBattler);
    if (gBattleTypeFlags & BATTLE_TYPE_ARENA)
        return gBattlerPartyIndexes[gActiveBattler] + 1;

    if (gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        battlerIn1 = gActiveBattler;
        if (gAbsentBattlerFlags & gBitTable[GetBattlerAtPosition(GetBattlerPosition(gActiveBattler) ^ BIT_FLANK)])
            battlerIn2 = gActiveBattler;
        else
            battlerIn2 = GetBattlerAtPosition(GetBattlerPosition(gActiveBattler) ^ BIT_FLANK);

        opposingBattler = gActiveBattler ^ BIT_SIDE ^ (Random() & BIT_FLANK);
        if (gAbsentBattlerFlags & gBitTable[opposingBattler])
            opposingBattler ^= BIT_FLANK;
    }
    else
    {
        opposingBattler = GetBattlerAtPosition(GetBattlerPosition(gActiveBattler) ^ BIT_SIDE);
        battlerIn1 = gActiveBattler;
        battlerIn2 = gActiveBattler;
    }

    if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_x800000))
    {
        if ((gActiveBattler & BIT_FLANK) == B_FLANK_LEFT)
            firstId = 0, lastId = 3;
        else
            firstId = 3, lastId = 6;
    }
    else
    {
        firstId = 0, lastId = 6;
    }

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    invalidMons = 0;
	
	// Get invalid slots ids.
    for (i = firstId; i < lastId; i++)
    {
        if (GetMonData(&party[i], MON_DATA_SPECIES) == SPECIES_NONE
             || GetMonData(&party[i], MON_DATA_HP) == 0
             || gBattlerPartyIndexes[battlerIn1] == i
             || gBattlerPartyIndexes[battlerIn2] == i
             || i == *(gBattleStruct->monToSwitchIntoId + battlerIn1)
             || i == *(gBattleStruct->monToSwitchIntoId + battlerIn2))
            invalidMons |= gBitTable[i];
    }
	
    if (firstId == 3)
        invalidMons |= 0x7;
    if (lastId == 3)
        invalidMons |= 0x38;
    {
        // Anota el último movimiento usado por el rival para actuar en consecuencia
        u8 gbt = gBattlerTarget;
        gBattlerTarget = opposingBattler;
        RecordLastUsedMoveByTarget();
        gBattlerTarget = gbt;
    }
    {
        u8 nhko[PARTY_SIZE][4];

        // Se aplican sucesivos filtros para excluir pokes que no conviene meter en este momento
        // Si un criterio elimina todos los pokes, entonces ese criterio se ignora (y por tanto deciden los criterios posteriores)
        filteredMons = invalidMons;
		
		// Aplica un criterio de filtrado.
        // No se permite que elimine todos los pokes a no ser que se pase una variable TRUE.
        #define APPLY_FILTER(filter, condition) {                                                          \
                if (MonsLeft(filteredMons) && (!OnlyOneMonLeft(filteredMons) || (condition))) {            \
                    newFilteredMons = filter(party, firstId, lastId, filteredMons, opposingBattler, nhko); \
                    if (MonsLeft(newFilteredMons) || (condition))                                          \
                        filteredMons = newFilteredMons;                                                    \
                }                                                                                          \
            }

        // Excluye a pokémon con Impostor si no se van a transformar, a Shedinja en
        // situación vulnerable y a pokémon con Truant cuando el rival los puede parar.
        // No se permitirá que esto deje sin opciones, excepto si se puede cambiar
        APPLY_FILTER(FilterImposterIfUseless, notChangingIsPossible);
        APPLY_FILTER(FilterShedinjaIfVulnerable, notChangingIsPossible);
        APPLY_FILTER(FilterTruantIfUseless, notChangingIsPossible);
		APPLY_FILTER(FilterSwitchInsThatMightGetKOedBeforeEndOfTurn, notChangingIsPossible);
        APPLY_FILTER(FilterFragileMonsAgainstPriority, notChangingIsAcceptable);

        // Calcula el nHKO que cada poke disponible hace y recibe del oponente
        // También almacena si cada poke es más rápido que el oponente
        PrepareNHKOTable(party, firstId, lastId, filteredMons, opposingBattler, nhko);

        APPLY_FILTER(FilterChoiceMonsWayTooWeak, notChangingIsPossible);
        APPLY_FILTER(FilterChoiceMonsNotPowerfulEnough, notChangingIsAcceptable);
        // Si los filtros eliminaron todas las opciones posibles o no se podía cambiar, no se cambia
        if (!MonsLeft(filteredMons))
            return PARTY_SIZE;
		
		// Este es el criterio nuclear para elegir al poke que sale:
        //  1.- Si hay pokes que pueden dar revenge kill, se saca uno de esos.
        //  2.- Si hay pokes que puedan eliminar al rival recibiendo un golpe
        //      que le quite menos de 1/3 de sus PS actuales, se saca uno de esos.
        //  3.- Si hay pokes que puedan eliminar al rival recibiendo dos golpes
        //      que le quiten menos de 1/5 de sus PS actuales, se saca uno de esos.
        //  4.- Se elige entre los pokes que más golpes aguanten.
        //  5.- Se elige entre los pokes que menos golpes requieran para eliminar al rival.
        // Si alguno de los tres primeros criterios filtra pokes y alguno de ellos
        // puede atrapar al rival, se elige entre aquellos que atrapen al rival
        APPLY_FILTER(FilterOpponentCanBeTrappedAndDefeated, FALSE);
		APPLY_FILTER(FilterRevengeKill, FALSE);
        APPLY_FILTER(FilterKOTaking1Hit, FALSE);
        APPLY_FILTER(FilterKOTaking2Hits, notChangingIsAcceptable);
        APPLY_FILTER(FilterCanAttackWonderGuardOpponent, FALSE);
        APPLY_FILTER(FilterTakesMostHits, FALSE);
        APPLY_FILTER(FilterKOsInLessHits, FALSE);
    }
	
    if (OnlyOneMonLeft(filteredMons))
    {
        bestMonId = GetUnfilteredMon(filteredMons);
        if (bestMonId != PARTY_SIZE && !(gBitTable[bestMonId] & filteredMons)) // no debería pasar, pero por si acaso
             return bestMonId;
    }
	
    bestMonId = GetBestMonDefensive(party, firstId, lastId, filteredMons, opposingBattler);
    if (bestMonId != PARTY_SIZE)
        return bestMonId;
	
    bestMonId = GetBestMonOffensive(party, firstId, lastId, filteredMons, opposingBattler);
    if (bestMonId != PARTY_SIZE)
        return bestMonId;

    if (MonsLeft(filteredMons))
    {
        // Si los criterios anteriores no han permitido seleccionar un solo poke,
        // se escoge al azar entre los que pasaron todos los filtros
        while (bestMonId == PARTY_SIZE || (gBitTable[bestMonId] & filteredMons))
            bestMonId = (Random() % (lastId - firstId)) + firstId;
    }

    return bestMonId;
}

static u8 GetAI_ItemType(u8 itemId, const u8 *itemEffect) // NOTE: should take u16 as item Id argument
{
    if (itemId == ITEM_FULL_RESTORE)
        return AI_ITEM_FULL_RESTORE;
    else if (itemEffect[4] & ITEM4_HEAL_HP)
        return AI_ITEM_HEAL_HP;
    else if (itemEffect[3] & ITEM3_STATUS_ALL)
        return AI_ITEM_CURE_CONDITION;
    else if (itemEffect[0] & (ITEM0_DIRE_HIT | ITEM0_X_ATTACK) || itemEffect[1] != 0 || itemEffect[2] != 0)
        return AI_ITEM_X_STAT;
    else if (itemEffect[3] & ITEM3_GUARD_SPEC)
        return AI_ITEM_GUARD_SPECS;
    else
        return AI_ITEM_NOT_RECOGNIZABLE;
}

static bool8 ShouldUseItem(void)
{
    struct Pokemon *party;
    s32 i;
    u8 validMons = 0;
    bool8 shouldUse = FALSE;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(gActiveBattler) == B_POSITION_PLAYER_RIGHT)
        return FALSE;

    if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER)
        party = gPlayerParty;
    else
        party = gEnemyParty;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&party[i], MON_DATA_HP) != 0
            && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_NONE
            && GetMonData(&party[i], MON_DATA_SPECIES2) != SPECIES_EGG)
        {
            validMons++;
        }
    }

    for (i = 0; i < MAX_TRAINER_ITEMS; i++)
    {
        u16 item;
        const u8 *itemEffects;
        u8 paramOffset;
        u8 battlerSide;

        if (i != 0 && validMons > (gBattleResources->battleHistory->itemsNo - i) + 1)
            continue;
        item = gBattleResources->battleHistory->trainerItems[i];
        if (item == ITEM_NONE)
            continue;
        if (gItemEffectTable[item - ITEM_POTION] == NULL)
            continue;

        if (item == ITEM_ENIGMA_BERRY)
            #ifndef FREE_ENIGMA_BERRY
            itemEffects = gSaveBlock1Ptr->enigmaBerry.itemEffect;
            #else
            itemEffects = 0;
            #endif
        else
            itemEffects = gItemEffectTable[item - ITEM_POTION];

        *(gBattleStruct->AI_itemType + gActiveBattler / 2) = GetAI_ItemType(item, itemEffects);

        switch (*(gBattleStruct->AI_itemType + gActiveBattler / 2))
        {
        case AI_ITEM_FULL_RESTORE:
            if (gBattleMons[gActiveBattler].hp >= gBattleMons[gActiveBattler].maxHP / 4)
                break;
            if (gBattleMons[gActiveBattler].hp == 0)
                break;
            shouldUse = TRUE;
            break;
        case AI_ITEM_HEAL_HP:
            paramOffset = GetItemEffectParamOffset(item, 4, 4);
            if (paramOffset == 0)
                break;
            if (gBattleMons[gActiveBattler].hp == 0)
                break;
            if (gBattleMons[gActiveBattler].hp < gBattleMons[gActiveBattler].maxHP / 4 || gBattleMons[gActiveBattler].maxHP - gBattleMons[gActiveBattler].hp > itemEffects[paramOffset])
                shouldUse = TRUE;
            break;
        case AI_ITEM_CURE_CONDITION:
            *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) = 0;
            if (itemEffects[3] & ITEM3_SLEEP && gBattleMons[gActiveBattler].status1 & STATUS1_SLEEP)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x20;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_POISON && (gBattleMons[gActiveBattler].status1 & STATUS1_POISON || gBattleMons[gActiveBattler].status1 & STATUS1_TOXIC_POISON))
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x10;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_BURN && gBattleMons[gActiveBattler].status1 & STATUS1_BURN)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x8;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_FREEZE && gBattleMons[gActiveBattler].status1 & STATUS1_FREEZE)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x4;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_PARALYSIS && gBattleMons[gActiveBattler].status1 & STATUS1_PARALYSIS)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x2;
                shouldUse = TRUE;
            }
            if (itemEffects[3] & ITEM3_CONFUSION && gBattleMons[gActiveBattler].status2 & STATUS2_CONFUSION)
            {
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x1;
                shouldUse = TRUE;
            }
            break;
        case AI_ITEM_X_STAT:
            *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) = 0;
            if (gDisableStructs[gActiveBattler].isFirstTurn == 0)
                break;
            if (itemEffects[0] & ITEM0_X_ATTACK)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x1;
            if (itemEffects[1] & ITEM1_X_DEFEND)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x2;
            if (itemEffects[1] & ITEM1_X_SPEED)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x4;
            if (itemEffects[2] & ITEM2_X_SPATK)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x8;
            if (itemEffects[2] & ITEM2_X_ACCURACY)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x20;
            if (itemEffects[0] & ITEM0_DIRE_HIT)
                *(gBattleStruct->AI_itemFlags + gActiveBattler / 2) |= 0x80;
            shouldUse = TRUE;
            break;
        case AI_ITEM_GUARD_SPECS:
            battlerSide = GetBattlerSide(gActiveBattler);
            if (gDisableStructs[gActiveBattler].isFirstTurn != 0 && gSideTimers[battlerSide].mistTimer == 0)
                shouldUse = TRUE;
            break;
        case AI_ITEM_NOT_RECOGNIZABLE:
            return FALSE;
        }

        if (shouldUse)
        {
            BtlController_EmitTwoReturnValues(1, B_ACTION_USE_ITEM, 0);
            *(gBattleStruct->chosenItem + (gActiveBattler / 2) * 2) = item;
            gBattleResources->battleHistory->trainerItems[i] = 0;
            return shouldUse;
        }
    }

    return FALSE;
}

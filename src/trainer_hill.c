#include "global.h"
#include "malloc.h"
#include "battle.h"
#include "battle_tower.h"
#include "battle_setup.h"
#include "ereader_helpers.h"
#include "event_data.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_message_box.h"
#include "international_string_util.h"
#include "item.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "script.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "trainer_hill.h"
#include "window.h"
#include "util.h"
#include "constants/battle_ai.h"
#include "constants/event_object_movement_constants.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "constants/layouts.h"
#include "constants/moves.h"
#include "constants/maps.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/easy_chat.h"
#include "constants/trainer_hill.h"

#define HILL_TAG_NORMAL 0
#define HILL_TAG_VARIETY 1
#define HILL_TAG_UNIQUE 2
#define HILL_TAG_EXPERT 3

#define HILL_MAX_TIME 215999 // 60 * 60 * 60 - 1

// EWRAM
struct TrHillStruct2
{
    u8 floorId;
    struct TrHillTag tag;
    struct TrHillFloor floors[NUM_TRAINER_HILL_FLOORS];
};

static EWRAM_DATA struct TrHillStruct2 *sHillData = NULL;
static EWRAM_DATA struct TrHillRoomTrainers *sRoomTrainers = NULL;
EWRAM_DATA u32 *gTrainerHillVBlankCounter = NULL;

// This file's functions.
static void TrainerHillStartChallenge(void);
static void GetOwnerState(void);
static void GiveChallengePrize(void);
static void CheckFinalTime(void);
static void TrainerHillResumeTimer(void);
static void TrainerHillSetPlayerLost(void);
static void TrainerHillGetChallengeStatus(void);
static void BufferChallengeTime(void);
static void GetAllFloorsUsed(void);
static void ClearVarResult(void);
static void IsTrainerHillChallengeActive(void);
static void ShowTrainerHillPostBattleText(void);
static void SetAllTrainerFlags(void);
static void GetGameSaved(void);
static void SetGameSaved(void);
static void ClearGameSaved(void);
static void GetChallengeWon(void);
static void TrainerHillSetTag(void);
static void SetUpDataStruct(void);
static void FreeDataStruct(void);
static void nullsub_2(void);
static void SetTimerValue(u32 *dst, u32 val);
static u32 GetTimerValue(u32 *src);
static void SetTrainerHillMonLevel(struct Pokemon *mon, u8 level);
static u16 GetPrizeItemId(void);

// const data
#include "data/battle_frontier/trainer_hill.h"

struct
{
    u8 trainerClass;
    u8 musicId;
} static const sTrainerClassesAndMusic[] =
{
    {TRAINER_CLASS_TEAM_AQUA, TRAINER_ENCOUNTER_MUSIC_AQUA},
    {TRAINER_CLASS_AQUA_ADMIN, TRAINER_ENCOUNTER_MUSIC_AQUA},
    {TRAINER_CLASS_AQUA_LEADER, TRAINER_ENCOUNTER_MUSIC_AQUA},
    {TRAINER_CLASS_AROMA_LADY, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_BATTLE_GIRL, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_SWIMMER_F, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_POKEFAN, TRAINER_ENCOUNTER_MUSIC_TWINS},
    {TRAINER_CLASS_DRAGON_TAMER, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_COOLTRAINER, TRAINER_ENCOUNTER_MUSIC_COOL},
    {TRAINER_CLASS_GUITARIST, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_SAILOR, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_TWINS, TRAINER_ENCOUNTER_MUSIC_TWINS},
    {TRAINER_CLASS_INTERVIEWER, TRAINER_ENCOUNTER_MUSIC_INTERVIEWER},
    {TRAINER_CLASS_RUIN_MANIAC, TRAINER_ENCOUNTER_MUSIC_HIKER},
    {TRAINER_CLASS_GENTLEMAN, TRAINER_ENCOUNTER_MUSIC_RICH},
    {TRAINER_CLASS_SWIMMER_M, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_POKEMANIAC, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_BLACK_BELT, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_OLD_COUPLE, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_BUG_MANIAC, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_CAMPER, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_KINDLER, TRAINER_ENCOUNTER_MUSIC_HIKER},
    {TRAINER_CLASS_TEAM_MAGMA, TRAINER_ENCOUNTER_MUSIC_MAGMA},
    {TRAINER_CLASS_MAGMA_ADMIN, TRAINER_ENCOUNTER_MUSIC_MAGMA},
    {TRAINER_CLASS_MAGMA_LEADER, TRAINER_ENCOUNTER_MUSIC_MAGMA},
    {TRAINER_CLASS_LASS, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_BUG_CATCHER, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_NINJA_BOY, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_RICH_BOY, TRAINER_ENCOUNTER_MUSIC_RICH},
    {TRAINER_CLASS_HEX_MANIAC, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_BEAUTY, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_LADY, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_PARASOL_LADY, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_PICNICKER, TRAINER_ENCOUNTER_MUSIC_GIRL},
    {TRAINER_CLASS_PKMN_BREEDER, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_COLLECTOR, TRAINER_ENCOUNTER_MUSIC_SUSPICIOUS},
    {TRAINER_CLASS_PKMN_RANGER, TRAINER_ENCOUNTER_MUSIC_COOL},
    {TRAINER_CLASS_PKMN_TRAINER_3, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_YOUNG_COUPLE, TRAINER_ENCOUNTER_MUSIC_GIRL},
    {TRAINER_CLASS_PSYCHIC, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_SR_AND_JR, TRAINER_ENCOUNTER_MUSIC_TWINS},
    {TRAINER_CLASS_ELITE_FOUR, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_YOUNGSTER, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_EXPERT, TRAINER_ENCOUNTER_MUSIC_INTENSE},
    {TRAINER_CLASS_TRIATHLETE, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_BIRD_KEEPER, TRAINER_ENCOUNTER_MUSIC_COOL},
    {TRAINER_CLASS_FISHERMAN, TRAINER_ENCOUNTER_MUSIC_HIKER},
    {TRAINER_CLASS_CHAMPION, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_TUBER_M, TRAINER_ENCOUNTER_MUSIC_MALE},
    {TRAINER_CLASS_TUBER_F, TRAINER_ENCOUNTER_MUSIC_GIRL},
    {TRAINER_CLASS_SIS_AND_BRO, TRAINER_ENCOUNTER_MUSIC_SWIMMER},
    {TRAINER_CLASS_HIKER, TRAINER_ENCOUNTER_MUSIC_HIKER},
    {TRAINER_CLASS_LEADER, TRAINER_ENCOUNTER_MUSIC_FEMALE},
    {TRAINER_CLASS_SCHOOL_KID, TRAINER_ENCOUNTER_MUSIC_MALE},
};

static const u16 sPrizeListRareCandy1[]  = {ITEM_RARE_CANDY,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListLuxuryBall1[] = {ITEM_LUXURY_BALL,      ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListMaxRevive1[]  = {ITEM_MAX_REVIVE,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListMaxEther1[]   = {ITEM_MAX_ETHER,        ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListElixir1[]     = {ITEM_ELIXIR,           ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListRoar[]        = {ITEM_TM05_ROAR,        ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListSludgeBomb[]  = {ITEM_TM36_SLUDGE_BOMB, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListToxic[]       = {ITEM_TM06_TOXIC,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListSunnyDay[]    = {ITEM_TM11_SUNNY_DAY,   ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListEarthQuake[]  = {ITEM_TM26_EARTHQUAKE,  ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};

static const u16 sPrizeListRareCandy2[]  = {ITEM_RARE_CANDY,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListLuxuryBall2[] = {ITEM_LUXURY_BALL,      ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListMaxRevive2[]  = {ITEM_MAX_REVIVE,       ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListMaxEther2[]   = {ITEM_MAX_ETHER,        ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListElixir2[]     = {ITEM_ELIXIR,           ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListBrickBreak[]  = {ITEM_TM31_BRICK_BREAK, ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListTorment[]     = {ITEM_TM41_TORMENT,     ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListSkillSwap[]   = {ITEM_TM48_SKILL_SWAP,  ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListGigaSwap[]    = {ITEM_TM19_GIGA_DRAIN,  ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};
static const u16 sPrizeListAttract[]     = {ITEM_TM45_ATTRACT,     ITEM_ETHER, ITEM_MAX_POTION, ITEM_REVIVE, ITEM_FLUFFY_TAIL, ITEM_GREAT_BALL};

static const u16 *const sPrizeLists1[NUM_TRAINER_HILL_PRIZE_LISTS] =
{
	sPrizeListRareCandy1,
	sPrizeListLuxuryBall1,
	sPrizeListMaxRevive1,
	sPrizeListMaxEther1,
	sPrizeListElixir1,
	sPrizeListRoar,
	sPrizeListSludgeBomb,
	sPrizeListToxic,
	sPrizeListSunnyDay,
	sPrizeListEarthQuake
};

static const u16 *const sPrizeLists2[NUM_TRAINER_HILL_PRIZE_LISTS] =
{
	sPrizeListRareCandy2,
	sPrizeListLuxuryBall2,
	sPrizeListMaxRevive2,
	sPrizeListMaxEther2,
	sPrizeListElixir2,
	sPrizeListBrickBreak,
	sPrizeListTorment,
	sPrizeListSkillSwap,
	sPrizeListGigaSwap,
	sPrizeListAttract
};

static const u16 *const *const sPrizeListSets[] =
{
    sPrizeLists1,
    sPrizeLists2
};

static const u16 sUnknown_0862A5D4[] = INCBIN_U16("graphics/pokenav/862A5D4.gbapal");
static const u8 sRecordWinColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GREY, TEXT_COLOR_LIGHT_GREY};

static const struct TrHillTag *const sDataPerTag[] =
{
    &sDataTagNormal,
    &sDataTagVariety,
    &sDataTagUnique,
    &sDataTagExpert,
};

// Unused.
static const u8 *const sFloorStrings[] =
{
    gText_TrainerHill1F,
    gText_TrainerHill2F,
    gText_TrainerHill3F,
    gText_TrainerHill4F,
};

static void (* const sHillFunctions[])(void) =
{
    [TRAINER_HILL_FUNC_START]                 = TrainerHillStartChallenge,
    [TRAINER_HILL_FUNC_GET_OWNER_STATE]       = GetOwnerState,
    [TRAINER_HILL_FUNC_GIVE_PRIZE]            = GiveChallengePrize,
    [TRAINER_HILL_FUNC_CHECK_FINAL_TIME]      = CheckFinalTime,
    [TRAINER_HILL_FUNC_RESUME_TIMER]          = TrainerHillResumeTimer,
    [TRAINER_HILL_FUNC_SET_LOST]              = TrainerHillSetPlayerLost,
    [TRAINER_HILL_FUNC_GET_CHALLENGE_STATUS]  = TrainerHillGetChallengeStatus,
    [TRAINER_HILL_FUNC_GET_CHALLENGE_TIME]    = BufferChallengeTime,
    [TRAINER_HILL_FUNC_GET_ALL_FLOORS_USED]   = GetAllFloorsUsed,
    [TRAINER_HILL_FUNC_CLEAR_RESULT]          = ClearVarResult,
    [TRAINER_HILL_FUNC_IN_CHALLENGE]          = IsTrainerHillChallengeActive,
    [TRAINER_HILL_FUNC_POST_BATTLE_TEXT]      = ShowTrainerHillPostBattleText,
    [TRAINER_HILL_FUNC_SET_ALL_TRAINER_FLAGS] = SetAllTrainerFlags,
    [TRAINER_HILL_FUNC_GET_GAME_SAVED]        = GetGameSaved,
    [TRAINER_HILL_FUNC_SET_GAME_SAVED]        = SetGameSaved,
    [TRAINER_HILL_FUNC_CLEAR_GAME_SAVED]      = ClearGameSaved,
    [TRAINER_HILL_FUNC_GET_WON]               = GetChallengeWon,
    [TRAINER_HILL_FUNC_SET_TAG]               = TrainerHillSetTag,
};

static const u8 *const sTagMatchStrings[] =
{
    gText_NormalTagMatch,
    gText_VarietyTagMatch,
    gText_UniqueTagMatch,
    gText_ExpertTagMatch,
};

static const struct EventObjectTemplate sTrainerEventObjectTemplate =
{
    .graphicsId = EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL,
    .elevation = 3,
    .movementType = MOVEMENT_TYPE_LOOK_AROUND,
    .movementRangeX = 1,
    .movementRangeY = 1,
    .trainerType = 1,
};

static const u32 sNextFloorMapNum[NUM_TRAINER_HILL_FLOORS] = 
{
    MAP_NUM(TRAINER_HILL_2F), 
    MAP_NUM(TRAINER_HILL_3F), 
    MAP_NUM(TRAINER_HILL_4F), 
    MAP_NUM(TRAINER_HILL_ROOF)
};
static const u8 sTrainerPartySlots[][PARTY_SIZE / 2] = 
{
    {0, 1, 2}, 
    {3, 4, 5}
};

// code
void CallTrainerHillFunction(void)
{
    SetUpDataStruct();
    sHillFunctions[gSpecialVar_0x8004]();
    FreeDataStruct();
}

void ResetTrainerHillResults(void)
{
    s32 i;

    gSaveBlock2Ptr->frontier.savedGame = 0;
    gSaveBlock2Ptr->frontier.unk_EF9 = 0;
    #ifndef FREE_TRAINER_HILL
    gSaveBlock1Ptr->trainerHill.bestTime = 0;
    for (i = 0; i < 4; i++)
        SetTimerValue(&gSaveBlock1Ptr->trainerHillTimes[i], HILL_MAX_TIME);
    #endif
}

static u8 GetFloorId(void)
{
    return gMapHeader.mapLayoutId - LAYOUT_TRAINER_HILL_1F;
}

u8 GetTrainerHillOpponentClass(u16 trainerId)
{
    u8 id = trainerId - 1;

    return gFacilityClassToTrainerClass[sRoomTrainers->facilityClass[id]];
}

void GetTrainerHillTrainerName(u8 *dst, u16 trainerId)
{
    s32 i;
    u8 id = trainerId - 1;

    for (i = 0; i < HILL_TRAINER_NAME_LENGTH; i++)
        dst[i] = sRoomTrainers->name[id][i];
}

u8 GetTrainerHillTrainerFrontSpriteId(u16 trainerId)
{
    u8 id, facilityClass;

    SetUpDataStruct();
    id = trainerId - 1;
    facilityClass = sHillData->floors[sHillData->floorId].trainers[id].facilityClass;
    FreeDataStruct();

    return gFacilityClassToPicIndex[facilityClass];
}

void InitTrainerHillBattleStruct(void)
{
    s32 i, j;

    SetUpDataStruct();
    sRoomTrainers = AllocZeroed(sizeof(*sRoomTrainers));

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < HILL_TRAINER_NAME_LENGTH; j++)
        {
            sRoomTrainers->name[i][j] = sHillData->floors[sHillData->floorId].trainers[i].name[j];
        }
        sRoomTrainers->facilityClass[i] = sHillData->floors[sHillData->floorId].trainers[i].facilityClass;
    }
    #ifndef FREE_TRAINER_HILL
    SetTrainerHillVBlankCounter(&gSaveBlock1Ptr->trainerHill.timer);
    #endif
    FreeDataStruct();
}

void FreeTrainerHillBattleStruct(void)
{
    if (sRoomTrainers != NULL)
        FREE_AND_SET_NULL(sRoomTrainers);
}

static void SetUpDataStruct(void)
{
    #ifndef FREE_TRAINER_HILL
    if (sHillData == NULL)
    {
        sHillData = AllocZeroed(sizeof(*sHillData));
        sHillData->floorId = gMapHeader.mapLayoutId - LAYOUT_TRAINER_HILL_1F;
        CpuCopy32(sDataPerTag[gSaveBlock1Ptr->trainerHill.tag], &sHillData->tag, sizeof(sHillData->tag) + 4 * sizeof(struct TrHillFloor));
        nullsub_2();
    }
    #endif
}

static void FreeDataStruct(void)
{
    if (sHillData != NULL)
        FREE_AND_SET_NULL(sHillData);
}

void CopyTrainerHillTrainerText(u8 which, u16 trainerId)
{
    u8 id, floorId;

    SetUpDataStruct();
    floorId = GetFloorId();
    id = trainerId - 1;

    switch (which)
    {
    case TRAINER_HILL_TEXT_INTRO:
        FrontierSpeechToString(sHillData->floors[floorId].trainers[id].speechBefore);
        break;
    case TRAINER_HILL_TEXT_PLAYER_LOST:
        FrontierSpeechToString(sHillData->floors[floorId].trainers[id].speechWin);
        break;
    case TRAINER_HILL_TEXT_PLAYER_WON:
        FrontierSpeechToString(sHillData->floors[floorId].trainers[id].speechLose);
        break;
    case TRAINER_HILL_TEXT_AFTER:
        FrontierSpeechToString(sHillData->floors[floorId].trainers[id].speechAfter);
        break;
    }

    FreeDataStruct();
}

static void TrainerHillStartChallenge(void)
{
    nullsub_2();
    #ifndef FREE_TRAINER_HILL
    if (!ReadTrainerHillAndValidate())
        gSaveBlock1Ptr->trainerHill.field_3D6E_0f = 1;
    else
        gSaveBlock1Ptr->trainerHill.field_3D6E_0f = 0;

    gSaveBlock1Ptr->trainerHill.unk_3D6C = 0;
    SetTrainerHillVBlankCounter(&gSaveBlock1Ptr->trainerHill.timer);
    gSaveBlock1Ptr->trainerHill.timer = 0;
    gSaveBlock1Ptr->trainerHill.spokeToOwner = 0;
    gSaveBlock1Ptr->trainerHill.checkedFinalTime = 0;
    gSaveBlock1Ptr->trainerHill.maybeECardScanDuringChallenge = 0;
    gSaveBlock2Ptr->frontier.trainerFlags = 0;
    gBattleOutcome = 0;
    gSaveBlock1Ptr->trainerHill.receivedPrize = 0;
    #endif
}

static void GetOwnerState(void)
{
    #ifndef FREE_TRAINER_HILL
    ClearTrainerHillVBlankCounter();
    gSpecialVar_Result = 0;
    if (gSaveBlock1Ptr->trainerHill.spokeToOwner)
        gSpecialVar_Result++;
    if (gSaveBlock1Ptr->trainerHill.receivedPrize && gSaveBlock1Ptr->trainerHill.checkedFinalTime)
        gSpecialVar_Result++;

    gSaveBlock1Ptr->trainerHill.spokeToOwner = TRUE;
    #endif
}

static void GiveChallengePrize(void)
{
    #ifndef FREE_TRAINER_HILL
    u16 itemId = GetPrizeItemId();

    if (sHillData->tag.numFloors != NUM_TRAINER_HILL_FLOORS || gSaveBlock1Ptr->trainerHill.receivedPrize)
    {
        gSpecialVar_Result = 2;
    }
    else if (AddBagItem(itemId, 1) == TRUE)
    {
        CopyItemName(itemId, gStringVar2);
        gSaveBlock1Ptr->trainerHill.receivedPrize = TRUE;
        gSaveBlock2Ptr->frontier.unk_EF9 = 0;
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }
    #endif
}

// If bestTime > timer, the challenge was completed faster and its a new record
// Otherwise the owner says it was a slow time and to complete it faster next time
static void CheckFinalTime(void)
{
    #ifndef FREE_TRAINER_HILL
    if (gSaveBlock1Ptr->trainerHill.checkedFinalTime)
    {
        gSpecialVar_Result = 2;
    }
    else if (GetTimerValue(&gSaveBlock1Ptr->trainerHill.bestTime) > gSaveBlock1Ptr->trainerHill.timer)
    {
        SetTimerValue(&gSaveBlock1Ptr->trainerHill.bestTime, gSaveBlock1Ptr->trainerHill.timer);
        gSaveBlock1Ptr->trainerHillTimes[gSaveBlock1Ptr->trainerHill.tag] = gSaveBlock1Ptr->trainerHill.bestTime;
        gSpecialVar_Result = 0;
    }
    else
    {
        gSpecialVar_Result = 1;
    }

    gSaveBlock1Ptr->trainerHill.checkedFinalTime = TRUE;
    #endif
}

static void TrainerHillResumeTimer(void)
{
    #ifndef FREE_TRAINER_HILL
    if (!gSaveBlock1Ptr->trainerHill.spokeToOwner)
    {
        if (gSaveBlock1Ptr->trainerHill.timer >= HILL_MAX_TIME)
            gSaveBlock1Ptr->trainerHill.timer = HILL_MAX_TIME;
        else
            SetTrainerHillVBlankCounter(&gSaveBlock1Ptr->trainerHill.timer);
    }
    #endif
}

static void TrainerHillSetPlayerLost(void)
{
    #ifndef FREE_TRAINER_HILL
    gSaveBlock1Ptr->trainerHill.hasLost = TRUE;
    #endif
}

static void TrainerHillGetChallengeStatus(void)
{
    #ifndef FREE_TRAINER_HILL
    if (gSaveBlock1Ptr->trainerHill.hasLost)
    {
        // The player lost their last match.
        gSaveBlock1Ptr->trainerHill.hasLost = FALSE;
        gSpecialVar_Result = TRAINER_HILL_PLAYER_STATUS_LOST;
    }
    else if (gSaveBlock1Ptr->trainerHill.maybeECardScanDuringChallenge)
    {
        // Unreachable code. Something relating to eCards?
        gSaveBlock1Ptr->trainerHill.maybeECardScanDuringChallenge = 0;
        gSpecialVar_Result = TRAINER_HILL_PLAYER_STATUS_ECARD_SCANNED;
    }
    else
    {
        // Continue playing.
        gSpecialVar_Result = TRAINER_HILL_PLAYER_STATUS_NORMAL;
    }
    #endif
}

static void BufferChallengeTime(void)
{
    s32 total, minutes, secondsWhole, secondsFraction;

    #ifndef FREE_TRAINER_HILL
    total = gSaveBlock1Ptr->trainerHill.timer;
    if (total >= HILL_MAX_TIME)
        total = HILL_MAX_TIME;

    minutes = total / (60 * 60);
    total %= (60 * 60);
    secondsWhole = total / 60;
    total %= 60;
    secondsFraction = (total * 168) / 100;

    ConvertIntToDecimalStringN(gStringVar1, minutes, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar2, secondsWhole, STR_CONV_MODE_RIGHT_ALIGN, 2);
    ConvertIntToDecimalStringN(gStringVar3, secondsFraction, STR_CONV_MODE_LEADING_ZEROS, 2);
    #endif
}

// Returns TRUE if all 4 floors are used
// Returns FALSE otherwise, and buffers the number of floors used
// The only time fewer than all 4 floors are used is for the JP-exclusive E-Reader and Default modes
static void GetAllFloorsUsed(void)
{
    SetUpDataStruct();
    if (sHillData->tag.numFloors != NUM_TRAINER_HILL_FLOORS)
    {
        ConvertIntToDecimalStringN(gStringVar1, sHillData->tag.numFloors, STR_CONV_MODE_LEFT_ALIGN, 1);
        gSpecialVar_Result = FALSE;
    }
    else
    {
        gSpecialVar_Result = TRUE;
    }

    FreeDataStruct();
}

// May have been dummied. Every time this is called a conditional for var result occurs afterwards
static void ClearVarResult(void)
{
    SetUpDataStruct();
    gSpecialVar_Result = 0;
    FreeDataStruct();
}

bool8 InTrainerHillChallenge(void)
{
    #ifndef FREE_TRAINER_HILL
    if (VarGet(VAR_TRAINER_HILL_IS_ACTIVE) == 0)
        return FALSE;
    else if (gSaveBlock1Ptr->trainerHill.spokeToOwner)
        return FALSE;
    else if (GetCurrentTrainerHillMapId() != 0)
        return TRUE;
    else
        return FALSE;
    #endif
}

static void IsTrainerHillChallengeActive(void)
{
    if (!InTrainerHillChallenge())
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
}

void nullsub_129(void)
{

}

static void nullsub_2(void)
{

}

void PrintOnTrainerHillRecordsWindow(void)
{
    s32 i, x, y;
    u32 total, minutes, secondsWhole, secondsFraction;

    #ifndef FREE_TRAINER_HILL
    SetUpDataStruct();
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    x = GetStringCenterAlignXOffset(1, gText_TimeBoard, 0xD0);
    AddTextPrinterParameterized3(0, 1, x, 2, sRecordWinColors, TEXT_SPEED_FF, gText_TimeBoard);

    y = 18;
    for (i = 0; i < 4; i++)
    {
        AddTextPrinterParameterized3(0, 1, 0, y, sRecordWinColors, TEXT_SPEED_FF, sTagMatchStrings[i]);
        y += 15;
        total = GetTimerValue(&gSaveBlock1Ptr->trainerHillTimes[i]);
        minutes = total / (60 * 60);
        total %= (60 * 60);
        ConvertIntToDecimalStringN(gStringVar1, minutes, STR_CONV_MODE_RIGHT_ALIGN, 2);
        secondsWhole = total / 60;
        total %= 60;
        ConvertIntToDecimalStringN(gStringVar2, secondsWhole, STR_CONV_MODE_RIGHT_ALIGN, 2);
        secondsFraction = (total * 168) / 100;
        ConvertIntToDecimalStringN(gStringVar3, secondsFraction, STR_CONV_MODE_LEADING_ZEROS, 2);
        StringExpandPlaceholders(StringCopy(gStringVar4, gText_TimeCleared), gText_XMinYDotZSec);
        x = GetStringRightAlignXOffset(1, gStringVar4, 0xD0);
        AddTextPrinterParameterized3(0, 1, x, y, sRecordWinColors, TEXT_SPEED_FF, gStringVar4);
        y += 17;
    }

    PutWindowTilemap(0);
    CopyWindowToVram(0, 3);
    FreeDataStruct();
    #endif
}

// Leftover from Fire Red / Leaf Green as in these games,
// the timer had to be xored by the encryption key in Sav2.
static u32 GetTimerValue(u32 *src)
{
    return *src;
}

static void SetTimerValue(u32 *dst, u32 val)
{
    *dst = val;
}

void LoadTrainerHillEventObjectTemplates(void)
{
    u8 i, floorId;
    struct EventObjectTemplate *eventTemplates = gSaveBlock1Ptr->eventObjectTemplates;

    if (!LoadTrainerHillFloorEventObjectScripts())
        return;

    SetUpDataStruct();
    for (i = 0; i < 2; i++)
        gSaveBlock2Ptr->frontier.trainerIds[i] = 0xFFFF;
    CpuFill32(0, gSaveBlock1Ptr->eventObjectTemplates, sizeof(gSaveBlock1Ptr->eventObjectTemplates));

    floorId = GetFloorId();
    for (i = 0; i < 2; i++)
    {
        u8 bits;

        eventTemplates[i] = sTrainerEventObjectTemplate;
        eventTemplates[i].localId = i + 1;
        eventTemplates[i].graphicsId = FacilityClassToGraphicsId(sHillData->floors[floorId].trainers[i].facilityClass);
        eventTemplates[i].x = sHillData->floors[floorId].display.coords[i] & 0xF;
        eventTemplates[i].y = ((sHillData->floors[floorId].display.coords[i] >> 4) & 0xF) + 5;
        bits = i << 2;
        eventTemplates[i].movementType = ((sHillData->floors[floorId].display.direction >> bits) & 0xF) + MOVEMENT_TYPE_FACE_UP;
        eventTemplates[i].trainerRange_berryTreeId = (sHillData->floors[floorId].display.range >> bits) & 0xF;
        eventTemplates[i].script = TrainerHill_EventScript_TrainerBattle;
        gSaveBlock2Ptr->frontier.trainerIds[i] = i + 1;
    }

    FreeDataStruct();
}

bool32 LoadTrainerHillFloorEventObjectScripts(void)
{
    SetUpDataStruct();
    // Something may have been dummied here
    FreeDataStruct();
    return TRUE;
}

// Functionally equivalent.
#ifdef NONMATCHING
static u32 sub_81D5F58(u8 floorId, u32 bit, u32 arg2, u32 arg3)
{
    u32 var0, var1, var2, var3;

    var0 = (sHillData->floors[floorId].display.unk3A0[arg2] >> (15 - bit)) & 1;
    var1 = sHillData->floors[floorId].display.data[arg2 * arg3 + bit];
    var3 = 0x200;
    var2 = 0x3000;

    return ((var0 << 10) | var2) | (var1 | var3);
}
#else
NAKED
static u32 sub_81D5F58(u8 floorId, u32 bit, u32 arg2, u32 arg3)
{
    asm_unified("\n\
    push {r4,r5,lr}\n\
	lsls r0, 24\n\
	lsrs r0, 24\n\
	ldr r4, =sHillData\n\
	ldr r4, [r4]\n\
	mov r12, r4\n\
	lsls r4, r2, 1\n\
	lsls r5, r0, 4\n\
	subs r5, r0\n\
	lsls r5, 3\n\
	subs r5, r0\n\
	lsls r5, 3\n\
	adds r4, r5\n\
	movs r0, 0xE8\n\
	lsls r0, 2\n\
	add r0, r12\n\
	adds r0, r4\n\
	ldrh r0, [r0]\n\
	movs r4, 0xF\n\
	subs r4, r1\n\
	asrs r0, r4\n\
	movs r4, 0x1\n\
	ands r0, r4\n\
	muls r2, r3\n\
	adds r2, r1\n\
	adds r2, r5\n\
	movs r1, 0xA8\n\
	lsls r1, 2\n\
	add r1, r12\n\
	adds r1, r2\n\
	ldrb r1, [r1]\n\
	movs r2, 0x80\n\
	lsls r2, 2\n\
	adds r3, r2, 0\n\
	movs r2, 0xC0\n\
	lsls r2, 6\n\
	lsls r0, 10\n\
	orrs r0, r2\n\
	orrs r1, r3\n\
	orrs r0, r1\n\
	pop {r4,r5}\n\
	pop {r1}\n\
	bx r1\n\
	.pool");
}
#endif // NONMATCHING

void GenerateTrainerHillFloorLayout(u16 *mapArg)
{
    s32 i, j;
    u16 *src, *dst;
    u8 mapId = GetCurrentTrainerHillMapId();

    if (mapId == TRAINER_HILL_ENTRANCE)
    {
        InitMapFromSavedGame();
        return;
    }

    SetUpDataStruct();
    if (mapId == TRAINER_HILL_ROOF)
    {
        InitMapFromSavedGame();
        FreeDataStruct();
        return;
    }

    mapId = GetFloorId();
    src = gMapHeader.mapLayout->map;
    gBackupMapLayout.map = mapArg;
    gBackupMapLayout.width = 31;
    gBackupMapLayout.height = 35;
    dst = mapArg + 224;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 16; j++)
            dst[j] = src[j];
        dst += 31;
        src += 16;
    }

    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 16; j++)
            dst[j] = sub_81D5F58(mapId, j, i, 0x10);
        dst += 31;
    }

    RunOnLoadMapScript();
    FreeDataStruct();
}

bool32 InTrainerHill(void)
{
    bool32 ret;

    if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_1F
        || gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_2F
        || gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_3F
        || gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_4F)
        ret = TRUE;
    else
        ret = FALSE;

    return ret;
}

u8 GetCurrentTrainerHillMapId(void)
{
    u8 mapId;

    if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_1F)
        mapId = TRAINER_HILL_1F;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_2F)
        mapId = TRAINER_HILL_2F;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_3F)
        mapId = TRAINER_HILL_3F;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_4F)
        mapId = TRAINER_HILL_4F;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_ROOF)
        mapId = TRAINER_HILL_ROOF;
    else if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_ENTRANCE)
        mapId = TRAINER_HILL_ENTRANCE;
    else
        mapId = 0;

    return mapId;
}

// Unused
static bool32 OnTrainerHillRoof(void)
{
    bool32 onRoof;

    if (gMapHeader.mapLayoutId == LAYOUT_TRAINER_HILL_ROOF)
        onRoof = TRUE;
    else
        onRoof = FALSE;

    return onRoof;
}

const struct WarpEvent* SetWarpDestinationTrainerHill4F(void)
{
    const struct MapHeader *header = Overworld_GetMapHeaderByGroupAndId(MAP_GROUP(TRAINER_HILL_4F), MAP_NUM(TRAINER_HILL_4F));

    return &header->events->warps[1];
}

// For warping from the roof in challenges where the 4F is not the final challenge floor
// This would only occur in the JP-exclusive Default and E-Reader challenges
const struct WarpEvent* SetWarpDestinationTrainerHillFinalFloor(u8 warpEventId)
{
    u8 numFloors;
    const struct MapHeader *header;

    if (warpEventId == 1)
        return &gMapHeader.events->warps[1];

    numFloors = GetNumFloorsInTrainerHillChallenge();
    if (numFloors == 0 || numFloors > NUM_TRAINER_HILL_FLOORS)
        numFloors = NUM_TRAINER_HILL_FLOORS;

    header = Overworld_GetMapHeaderByGroupAndId(MAP_GROUP(TRAINER_HILL_4F), sNextFloorMapNum[numFloors - 1]);
    return &header->events->warps[0];
}

u16 LocalIdToHillTrainerId(u8 localId)
{
    return gSaveBlock2Ptr->frontier.trainerIds[localId - 1];
}

bool8 GetHillTrainerFlag(u8 eventObjectId)
{
    u32 floorId = GetFloorId() * 2;
    u8 bitId = gEventObjects[eventObjectId].localId - 1 + floorId;

    return gSaveBlock2Ptr->frontier.trainerFlags & gBitTable[bitId];
}

void SetHillTrainerFlag(void)
{
    u8 i;
    u8 floorId = GetFloorId() * 2;

    for (i = 0; i < 2; i++)
    {
        if (gSaveBlock2Ptr->frontier.trainerIds[i] == gTrainerBattleOpponent_A)
        {
            gSaveBlock2Ptr->frontier.trainerFlags |= gBitTable[floorId + i];
            break;
        }
    }

    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
    {
        for (i = 0; i < 2; i++)
        {
            if (gSaveBlock2Ptr->frontier.trainerIds[i] == gTrainerBattleOpponent_B)
            {
                gSaveBlock2Ptr->frontier.trainerFlags |= gBitTable[floorId + i];
                break;
            }
        }
    }
}

const u8 *GetTrainerHillTrainerScript(void)
{
    return TrainerHill_EventScript_TrainerBattle;
}

static void ShowTrainerHillPostBattleText(void)
{
    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_AFTER, gSpecialVar_LastTalked);
    sub_80982B8();
}

static void CreateNPCTrainerHillParty(u16 trainerId, u8 firstMonId)
{
    u8 trId, level;
    s32 i, floorId, partySlot;

    if (trainerId == 0 || trainerId > 2)
        return;

    trId = trainerId - 1;
    SetUpDataStruct();
    level = GetHighestLevelInPlayerParty();
    floorId = GetFloorId();
    for (i = firstMonId, partySlot = 0; i < firstMonId + 3; i++, partySlot++)
    {
        u8 id = sTrainerPartySlots[trId][partySlot];
        struct Pokemon *mon = &gEnemyParty[i];

        CreateBattleTowerMon(mon, &sHillData->floors[floorId].trainers[trId].mons[id]);
        SetTrainerHillMonLevel(mon, level);
    }

    FreeDataStruct();
}

void FillHillTrainerParty(void)
{
    ZeroEnemyPartyMons();
    CreateNPCTrainerHillParty(gTrainerBattleOpponent_A, 0);
}

void FillHillTrainersParties(void)
{
    ZeroEnemyPartyMons();
    CreateNPCTrainerHillParty(gTrainerBattleOpponent_A, 0);
    CreateNPCTrainerHillParty(gTrainerBattleOpponent_B, 3);
}

// This function is unused, but my best guess is
// it was supposed to return AI scripts for trainer
// hill trainers.
u32 GetTrainerHillAIFlags(void)
{
    return (AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY);
}

u8 GetTrainerEncounterMusicIdInTrainerHill(u16 trainerId)
{
    s32 i;
    u8 trId, facilityClass;

    SetUpDataStruct();
    trId = trainerId - 1;
    facilityClass = sHillData->floors[sHillData->floorId].trainers[trId].facilityClass;
    FreeDataStruct();

    for (i = 0; i < ARRAY_COUNT(sTrainerClassesAndMusic); i++)
    {
        if (sTrainerClassesAndMusic[i].trainerClass == gFacilityClassToTrainerClass[facilityClass])
            return sTrainerClassesAndMusic[i].musicId;
    }

    return 0;
}

static void SetTrainerHillMonLevel(struct Pokemon *mon, u8 level)
{
    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u32 exp = gExperienceTables[gBaseStats[species].growthRate][level];

    SetMonData(mon, MON_DATA_EXP, &exp);
    SetMonData(mon, MON_DATA_LEVEL, &level);
    CalculateMonStats(mon);
}

u8 GetNumFloorsInTrainerHillChallenge(void)
{
    u8 floors;

    SetUpDataStruct();
    floors = sHillData->tag.numFloors;
    FreeDataStruct();

    return floors;
}

static void SetAllTrainerFlags(void)
{
    gSaveBlock2Ptr->frontier.trainerFlags = 0xFF;
}

// Palette never loaded, sub_81D6534 always FALSE
void sub_81D64C0(void)
{
    if (sub_81D6534() == TRUE)
        LoadPalette(sUnknown_0862A5D4, 0x70, 0x20);
}

static void GetGameSaved(void)
{
    gSpecialVar_Result = gSaveBlock2Ptr->frontier.savedGame;
}

static void SetGameSaved(void)
{
    gSaveBlock2Ptr->frontier.savedGame = TRUE;
}

static void ClearGameSaved(void)
{
    gSaveBlock2Ptr->frontier.savedGame = FALSE;
}

// Always FALSE
bool32 sub_81D6534(void)
{
    if (!InTrainerHillChallenge() || GetCurrentTrainerHillMapId() == TRAINER_HILL_ENTRANCE)
        return FALSE;

    ClearVarResult();
    if (gSpecialVar_Result == 0)
        return FALSE;
    else
        return TRUE;
}

static void GetChallengeWon(void)
{
    #ifndef FREE_TRAINER_HILL
    if (gSaveBlock1Ptr->trainerHill.hasLost)
        gSpecialVar_Result = FALSE;
    else
        gSpecialVar_Result = TRUE;
    #endif
}

static void TrainerHillSetTag(void)
{
    #ifndef FREE_TRAINER_HILL
    gSaveBlock1Ptr->trainerHill.tag = gSpecialVar_0x8005;
    gSaveBlock1Ptr->trainerHill.bestTime = gSaveBlock1Ptr->trainerHillTimes[gSpecialVar_0x8005];
    #endif
}

static u8 GetPrizeListId(bool8 maxTrainers)
{
    u8 prizeListId, i, modBy;

    prizeListId = 0;
    for (i = 0; i < NUM_TRAINER_HILL_FLOORS; i++)
    {
        prizeListId ^= sHillData->floors[i].trainerNum1 & 0x1F;
        prizeListId ^= sHillData->floors[i].trainerNum2 & 0x1F;
    }

    // Not possible to win TMs with fewer than 8 trainers
    if (maxTrainers)
        modBy = NUM_TRAINER_HILL_PRIZE_LISTS;
    else
        modBy = NUM_TRAINER_HILL_PRIZE_LISTS / 2;

    prizeListId %= modBy;
    return prizeListId;
}

static u16 GetPrizeItemId(void)
{
    u8 i;
    const u16 *prizeList;
    s32 var = 0, prizeListSetId, minutes, id;

    for (i = 0; i < NUM_TRAINER_HILL_FLOORS; i++)
    {
        var += sHillData->floors[i].trainerNum1;
        var += sHillData->floors[i].trainerNum2;
    }

    prizeListSetId = var / 256;
    prizeListSetId %= 2;
    if (FlagGet(FLAG_SYS_GAME_CLEAR) && sHillData->tag.numTrainers == NUM_TRAINER_HILL_TRAINERS)
        i = GetPrizeListId(TRUE);
    else
        i = GetPrizeListId(FALSE);

    #ifndef FREE_TRAINER_HILL
    if (gSaveBlock1Ptr->trainerHill.tag == HILL_TAG_EXPERT)
        i = (i + 1) % NUM_TRAINER_HILL_PRIZE_LISTS;

    prizeList = sPrizeListSets[prizeListSetId][i];
    minutes = (signed)(gSaveBlock1Ptr->trainerHill.timer) / (60 * 60);
    if (minutes < 12)
        id = 0;
    else if (minutes < 13)
        id = 1;
    else if (minutes < 14)
        id = 2;
    else if (minutes < 16)
        id = 3;
    else if (minutes < 18)
        id = 4;
    else
        id = 5;
    #endif

    return prizeList[id];
}

#include "global.h"
#include "event_data.h"
#include "midele_misc_scripts.h"
#include "string_util.h"
#include "strings.h"
#include "constants/random_battle.h"

static void IncrementVictories(u16 victoriesVar, u16 maxVictoriesVar);
static void ResetVictories(u16 victoriesVar);

const u8 *const gSpecialNames[] = {
    gText_NameMidele,
    gText_NameMideleUppercase
};


void BufferRandomBattleVictories(void)
{
    u16 victoriesIndividual, maxVictoriesIndividual, victoriesDoubles, maxVictoriesDoubles;
    u16 option = gSpecialVar_0x8008;
    switch (option)
    {
        case SHOW_VICTORIES_NORMAL:
            victoriesIndividual    = VarGet(VAR_VICTORIES_NORMAL_INDIVIDUAL);
            maxVictoriesIndividual = VarGet(VAR_MAX_VICTORIES_NORMAL_INDIVIDUAL);
            victoriesDoubles       = VarGet(VAR_VICTORIES_NORMAL_DOUBLES);
            maxVictoriesDoubles    = VarGet(VAR_MAX_VICTORIES_NORMAL_DOUBLES);
            break;
        case SHOW_VICTORIES_CC:
            victoriesIndividual    = VarGet(VAR_VICTORIES_CC_INDIVIDUAL);
            maxVictoriesIndividual = VarGet(VAR_MAX_VICTORIES_CC_INDIVIDUAL);
            victoriesDoubles       = VarGet(VAR_VICTORIES_CC_DOUBLES);
            maxVictoriesDoubles    = VarGet(VAR_MAX_VICTORIES_CC_DOUBLES);
            break;
    }
    
    ConvertUIntToDecimalStringN(gStringVar1, victoriesIndividual, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertUIntToDecimalStringN(gStringVar2, maxVictoriesIndividual, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertUIntToDecimalStringN(gStringVar3, victoriesDoubles, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertUIntToDecimalStringN(gStringVar5, maxVictoriesDoubles, STR_CONV_MODE_LEFT_ALIGN, 3);
}

void UpdateRandomBattleVictories(void)
{
    u16 victoriesVar, maxVictoriesVar;
    u16 operation = gSpecialVar_0x800A;
    u16 option = gSpecialVar_0x800B;

    switch (option)
    {
    case UPDATE_VICTORIES_NORMAL_INDIVIDUAL:
        victoriesVar = VAR_VICTORIES_NORMAL_INDIVIDUAL;
        maxVictoriesVar = VAR_MAX_VICTORIES_NORMAL_INDIVIDUAL;
        break;
    case UPDATE_VICTORIES_NORMAL_DOUBLES:
        victoriesVar = VAR_VICTORIES_NORMAL_DOUBLES;
        maxVictoriesVar = VAR_MAX_VICTORIES_NORMAL_DOUBLES;
        break;
    case UPDATE_VICTORIES_CC_INDIVIDUAL:
        victoriesVar = VAR_VICTORIES_CC_INDIVIDUAL;
        maxVictoriesVar = VAR_MAX_VICTORIES_CC_INDIVIDUAL;
        break;
    case UPDATE_VICTORIES_CC_DOUBLES:
        victoriesVar = VAR_VICTORIES_CC_DOUBLES;
        maxVictoriesVar = VAR_MAX_VICTORIES_CC_DOUBLES;
        break;
    }

    switch (operation)
    {
        case UPDATE_VICTORIES_OP_INCREMENT:
            IncrementVictories(victoriesVar, maxVictoriesVar);
            break;
        case UPDATE_VICTORIES_OP_RESET:
            ResetVictories(victoriesVar);
            break;
    }
}

bool8 PlayerHasSpecialNickname(void)
{
    u8 i;
    bool8 hasSpecialNickname = FALSE;
    for (i = 0; i < ARRAY_COUNT(gSpecialNames); i++)
    {
        if (StringCompare(gSaveBlock2Ptr->playerName, gSpecialNames[i]) == 0)
        {
            hasSpecialNickname = TRUE;
            break;
        }
    }
    
    return hasSpecialNickname;
    
}

static void IncrementVictories(u16 victoriesVar, u16 maxVictoriesVar)
{
    u16 currentVictories, currentMaxVictories;
    
    // Increment victories in 1 and update max victories
    currentVictories = VarGet(victoriesVar) + 1;
    currentMaxVictories = VarGet(maxVictoriesVar);
    VarSet(victoriesVar, currentVictories);
    if (currentVictories > currentMaxVictories)
    {
        VarSet(maxVictoriesVar, currentVictories);
    }
}

static void ResetVictories(u16 victoriesVar)
{
    VarSet(victoriesVar, 0);
}

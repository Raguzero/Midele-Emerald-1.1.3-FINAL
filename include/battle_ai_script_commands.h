#ifndef GUARD_BATTLE_AI_SCRIPT_COMMANDS_H
#define GUARD_BATTLE_AI_SCRIPT_COMMANDS_H

// return values for BattleAI_ChooseMoveOrAction
// 0 - 3 are move idx
#define AI_CHOICE_FLEE 4
#define AI_CHOICE_WATCH 5
#define AI_CHOICE_SWITCH 7

void BattleAI_HandleItemUseBeforeAISetup(u8 defaultScoreMoves);
void BattleAI_SetupAIData(u8 defaultScoreMoves);
u8 BattleAI_ChooseMoveOrAction(void);
void ClearBattlerMoveHistory(u8 battlerId);
void RecordAbilityBattle(u8 battlerId, u8 abilityId);
void ClearBattlerAbilityHistory(u8 battlerId);
void CopyBattlerHistoryForTransformedMon(u8 transformUser, u8 transformTarget);
void LearnBattlerHistoryFromTransformedMon(u8 transformUser, u8 transformTarget);
void RecordItemEffectBattle(u8 battlerId, u8 itemEffect);
void ClearBattlerItemEffectHistory(u8 battlerId);

bool32 OurShedinjaIsVulnerable(u32 battlerAI, u32 opposingBattler, u16 consideredMove);
bool32 IsTruantMonVulnerable(u32 battlerAI, u32 opposingBattler);
s32 CalculateNHKO(u16 attackerId, u16 targetId, bool8 attackerIsCurrentAI, u16 consideredMove, bool8 assumeWorstCaseScenario, bool8 ignoreFocusPunch);

#endif // GUARD_BATTLE_AI_SCRIPT_COMMANDS_H

#ifndef GUARD_BATTLE_AI_SWITCH_ITEMS_H
#define GUARD_BATTLE_AI_SWITCH_ITEMS_H

enum
{
    AI_ITEM_FULL_RESTORE = 1,
    AI_ITEM_HEAL_HP,
    AI_ITEM_CURE_CONDITION,
    AI_ITEM_X_STAT,
    AI_ITEM_GUARD_SPECS,
    AI_ITEM_NOT_RECOGNIZABLE
};

void AI_TrySwitchOrUseItem(void);
u8 GetMostSuitableMonToSwitchInto(u8 howTolerableIsNotChanging);
bool8 AreAttackingStatsLowered(u8 category);
bool8 IsAccuracyLowered(s8 threshold);

// arguments for GetMostSuitableMonToSwitchInto
#define NOT_CHANGING_IS_IMPOSSIBLE 0
#define NOT_CHANGING_IS_UNACCEPTABLE 1
#define NOT_CHANGING_IS_ACCEPTABLE 2

#endif // GUARD_BATTLE_AI_SWITCH_ITEMS_H

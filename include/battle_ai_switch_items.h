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
u8 GetMostSuitableMonToSwitchInto(bool8 notChangingIsPossible, bool8 notChangingIsAcceptable);
u8 GetMostSuitableMonToSwitchInto_NotChangingIsImpossible(void);
u8 GetMostSuitableMonToSwitchInto_NotChangingIsUnacceptable(void);
u8 GetMostSuitableMonToSwitchInto_NotChangingIsAcceptable(void);
bool8 AreAttackingStatsLowered(u8 category);

#endif // GUARD_BATTLE_AI_SWITCH_ITEMS_H

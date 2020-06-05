const struct Boss gBosses[] =
{
    [BOSS_CORONA] =
    {
        .name = gBossNameCorona,
        .level = 100,
        .hp = 600,
        .attack = 1,
        .defense = 200,
        .spAttack = 250,
        .spDefense = 400,
        .speed = 5,
        .item = ITEM_LEFTOVERS,
        .moves = {MOVE_TOXIC, MOVE_PAIN_SPLIT, MOVE_SLUDGE_BOMB, MOVE_THUNDER},
        .ability = ABILITY_DRIZZLE,
        .type1 = TYPE_POISON,
        .type2 = TYPE_GHOST,
    }
};

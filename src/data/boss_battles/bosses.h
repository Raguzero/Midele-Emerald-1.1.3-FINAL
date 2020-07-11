const struct Boss gBosses[] =
{
    [BOSS_CORONA] =
    {
        .name = gBossNameCorona,
        .level = 100,
        .hpType = TYPE_FIRE,
        .hp = 600,
        .attack = 1,
        .defense = 200,
        .spAttack = 250,
        .spDefense = 400,
        .speed = 5,
        .item = ITEM_LEFTOVERS,
        .moves = {MOVE_TOXIC, MOVE_HIDDEN_POWER, MOVE_SLUDGE_BOMB, MOVE_THUNDER},
        .ability = ABILITY_DRIZZLE,
        .type1 = TYPE_POISON,
        .type2 = TYPE_GHOST,
    },
    [BOSS_YETI] =
    {
        .name = gBossNameYeti,
        .level = 1,
        .hp = 1,
        .attack = 1,
        .defense = 200,
        .spAttack = 250,
        .spDefense = 400,
        .speed = 5,
        .item = ITEM_LEFTOVERS,
        .moves = {MOVE_BLIZZARD, MOVE_HAIL, MOVE_ICE_BEAM, MOVE_EARTHQUAKE},
        .ability = ABILITY_THICK_FAT,
        .type1 = TYPE_ICE,
        .type2 = TYPE_ICE,
    }
};

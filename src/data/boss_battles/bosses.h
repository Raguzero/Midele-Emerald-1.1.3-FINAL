const struct Boss gBosses[] =
{
    [BOSS_CORONA] =
    {
        .name = gBossNameCorona,
        .level = 50,
        .hp = 340,
        .attack = 180,
        .defense = 200,
        .spAttack = 180,
        .spDefense = 400,
        .speed = 5,
        .item = ITEM_LEFTOVERS,
        .moves = {MOVE_TOXIC, MOVE_SLUDGE_BOMB, MOVE_SURF, MOVE_THUNDER},
        .ability = ABILITY_DRIZZLE,
        .type1 = TYPE_POISON,
        .type2 = TYPE_GHOST,
    },
    [BOSS_YETI] =
    {
        .name = gBossNameYeti,
        .level = 45,
        .hp = 300,
        .attack = 150,
        .defense = 300,
        .spAttack = 100,
        .spDefense = 150,
        .speed = 80,
        .item = ITEM_LEFTOVERS,
        .moves = {MOVE_BLIZZARD, MOVE_BRICK_BREAK, MOVE_ROCK_SLIDE, MOVE_EARTHQUAKE},
        .ability = ABILITY_THICK_FAT,
        .type1 = TYPE_ICE,
        .type2 = TYPE_ICE,
    }
};

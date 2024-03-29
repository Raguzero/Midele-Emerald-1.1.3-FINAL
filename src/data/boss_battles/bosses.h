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
    },
    [BOSS_MASUDA] =
    {
        .name = gBossNameMasuda,
        .level = 50,
        .hp = 600,
        .attack = 257, // Equivalente a 150 BST, 31 IV, 255 EV, LVL 50, NATURE FAVORABLE
        .defense = 189, // Equivalente a 120 BST, 31 IV, 255 EV, LVL 50, NATURE FAVORABLE
        .spAttack = 10,
        .spDefense = 167, // Equivalente a 100 BST, 31 IV, 255 EV, LVL 50, NATURE FAVORABLE
        .speed = 156, // Equivalente a 90 BST, 31 IV, 255 EV, LVL 50, NATURE FAVORABLE
        .item = ITEM_SITRUS_BERRY,
        .moves = {MOVE_PAY_DAY, MOVE_SHADOW_BALL, MOVE_REVENGE, MOVE_GLARE},
        .ability = ABILITY_ADAPTABILITY,
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_GHOST,
    },
    [BOSS_TITAN] =
    {
        .name = gBossNameTitan,
        .level = 80,
        .hp = 999,
        .attack = 352, // Equivalente a 150 BST, 31 IV, 255 EV, LVL 80, NATURE FAVORABLE
        .defense = 224, // Equivalente a 90 BST, 31 IV, 255 EV, LVL 80, NATURE NEUTRAL
        .spAttack = 240, // Equivalente a 100 BST, 31 IV, 255 EV, LVL 80, NATURE NEUTRAL
        .spDefense = 202, // Equivalente a 90 BST, 31 IV, 255 EV, LVL 80, NATURE UNFAVORABLE
        .speed = 136, // Equivalente a 60 BST, 31 IV, 128 EV, LVL 80, NATURE UNFAVORABLE
        .item = ITEM_NEVER_MELT_ICE,
        .moves = {MOVE_SEISMIC_PUNCH, MOVE_CURSE, MOVE_CRUNCH, MOVE_ICE_BEAM},
        .ability = ABILITY_STRONG_JAW, // Para CRUNCH
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,
    }
};

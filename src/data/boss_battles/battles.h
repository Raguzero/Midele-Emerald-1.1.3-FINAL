const struct BossBattle gBossBattles[] = {
    [BOSS_BATTLE_TOTEM_SUDOWOODO_DEBUG] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .weather = (WEATHER_RAIN_TEMPORARY | WEATHER_RAIN_PERMANENT), // ver Battle Weather flags en include/constants/battle.h
        .boss = TOTEM_SUDOWOODO_DEBUG,
    },
    [BOSS_BATTLE_CORONA] =
    {
        .battleType = BATTLE_TYPE_BOSS,
        .music = JENOVA,
        .boss = BOSS_CORONA,
    },
    [BOSS_BATTLE_TOTEM_WINTASS] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .boss = TOTEM_WINTASS,
    },
    [BOSS_BATTLE_TOTEM_TOXTRICITY] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .boss = TOTEM_TOXTRICITY,
    },
    [BOSS_BATTLE_TOTEM_COFAGRIGUS] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .boss = TOTEM_COFAGRIGUS,
    },
    [BOSS_BATTLE_TOTEM_CENTISKORCH] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .boss = TOTEM_CENTISKORCH,
    },
    [BOSS_BATTLE_TOTEM_MEGA_GLALIE] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .weather = (WEATHER_HAIL_TEMPORARY | WEATHER_HAIL_PERMANENT), // ver Battle Weather flags en include/constants/battle.h
        .boss = TOTEM_MEGA_GLALIE,
    },
    [BOSS_BATTLE_TOTEM_TYPHLOSION] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .weather = (WEATHER_SUN_TEMPORARY | WEATHER_SUN_PERMANENT), // ver Battle Weather flags en include/constants/battle.h
        .boss = TOTEM_TYPHLOSION,
    },
};

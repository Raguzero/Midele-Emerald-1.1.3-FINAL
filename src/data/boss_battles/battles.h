const struct BossBattle gBossBattles[] = {
    [BOSS_BATTLE_TOTEM_SUDOWOODO_DEBUG] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .weather = WEATHER_SNOW, // ver WEATHER_* flags en include/constants/weather.h
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
        .weather = WEATHER_SNOW, // ver WEATHER_* flags en include/constants/weather.h
        .boss = TOTEM_MEGA_GLALIE,
    },
    [BOSS_BATTLE_TOTEM_MEGA_CAMERUPT] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .weather = WEATHER_DROUGHT, // ver WEATHER_* flags en include/constants/weather.h
        .boss = TOTEM_MEGA_CAMERUPT,
    },
    [BOSS_BATTLE_TOTEM_MEGA_ABSOL] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .boss = TOTEM_MEGA_ABSOL,
    },
    [BOSS_BATTLE_TOTEM_PROBOPASS] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .boss = TOTEM_PROBOPASS,
    },
    [BOSS_BATTLE_TOTEM_RHYPERIOR] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .boss = TOTEM_RHYPERIOR,
    },
    [BOSS_BATTLE_TOTEM_TYRANITAR] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .weather = WEATHER_SANDSTORM, // ver WEATHER_* flags en include/constants/weather.h
        .boss = TOTEM_TYRANITAR,
    },
    [BOSS_BATTLE_TOTEM_PRIMARINA] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .boss = TOTEM_PRIMARINA,
    },
    [BOSS_BATTLE_MASUDA] =
    {
        .battleType = BATTLE_TYPE_BOSS,
        .music = JENOVA,
        .boss = BOSS_MASUDA,
    },
    [BOSS_BATTLE_TOTEM_SAPPHIRE] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .weather = WEATHER_RAIN, // ver WEATHER_* flags en include/constants/weather.h
        .boss = TOTEM_SAPPHIRE,
    }
};

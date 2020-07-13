const struct BossBattle gBossBattles[] = {
    [BOSS_BATTLE_TOTEM_SUDOWOODO_DEBUG] =
    {
        .battleType = BATTLE_TYPE_TOTEM,
        .music = MUS_RG_VS_LAST,
        .boss = TOTEM_SUDOWOODO_DEBUG,
    },
    [BOSS_BATTLE_CORONA_DEBUG] =
    {
        .battleType = BATTLE_TYPE_BOSS,
        .music = FF6BOSS,
        .boss = BOSS_CORONA,
    },
    [BOSS_BATTLE_YETI] =
    {
        .battleType = BATTLE_TYPE_BOSS,
        .music = FF6BOSS,
        .boss = BOSS_YETI,
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
};

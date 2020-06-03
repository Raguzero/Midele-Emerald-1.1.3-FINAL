const u8 gBossNameKefka[] = _("KEFKA");
const u32 gBossPalette_Corona[] = INCBIN_U32("graphics/bosses/kefka/normal.gbapal.lz");
const u32 gBossFrontPic_Corona[] = INCBIN_U32("graphics/bosses/kefka/front.4bpp.lz");

const struct CompressedSpriteSheet gBossFrontPicTable[] =
{
    [BOSS_KEFKA] = {gBossFrontPic_Corona, 0x800, SPECIES_NONE},
};

const struct CompressedSpritePalette gBossPaletteTable[] =
{
    [BOSS_KEFKA] = {gBossPalette_Corona, SPECIES_NONE},
};

const struct BossBattle gBossBattles[] = {
    [BOSS_BATTLE_KEFKA] =
    {
        .battleType = BATTLE_TYPE_BOSS,
        .music = FF6BOSS,
        .boss = BOSS_KEFKA,
    }
};

// TODO MIDELE - SET MAX HP
const struct Boss gBosses[] =
{
    [BOSS_KEFKA] =
    {
        .name = gBossNameKefka,
        .level = 69,
        .hp = 555,
        .attack = 400,
        .defense = 500,
        .spAttack = 200,
        .spDefense = 120,
        .speed = 1,
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_TIMID,
        .moves = {MOVE_FRUSTRATION, MOVE_SHADOW_BALL, MOVE_BRICK_BREAK, MOVE_THUNDER_WAVE},
        .ability = ABILITY_DRIZZLE,
        .type1 = TYPE_FIRE,
        .type2 = TYPE_GHOST,
    }
};

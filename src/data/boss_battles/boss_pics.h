const u32 gBossPalette_Corona[] = INCBIN_U32("graphics/bosses/corona/normal.gbapal.lz");
const u32 gBossFrontPic_Corona[] = INCBIN_U32("graphics/bosses/corona/front.4bpp.lz");
const u32 gBossPalette_Yeti[] = INCBIN_U32("graphics/bosses/yeti/normal.gbapal.lz");
const u32 gBossFrontPic_Yeti[] = INCBIN_U32("graphics/bosses/yeti/front.4bpp.lz");

const struct CompressedSpriteSheet gBossFrontPicTable[] =
{
    [BOSS_CORONA] = {gBossFrontPic_Corona, 0x800, SPECIES_NONE},
    [BOSS_YETI] = {gBossFrontPic_Yeti, 0x800, SPECIES_NONE},
};

const struct CompressedSpritePalette gBossPaletteTable[] =
{
    [BOSS_CORONA] = {gBossPalette_Corona, SPECIES_NONE},
    [BOSS_YETI] = {gBossPalette_Yeti, SPECIES_NONE},
};

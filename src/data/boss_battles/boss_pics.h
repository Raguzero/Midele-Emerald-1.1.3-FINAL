const u32 gBossPalette_Corona[] = INCBIN_U32("graphics/bosses/corona/normal.gbapal.lz");
const u32 gBossFrontPic_Corona[] = INCBIN_U32("graphics/bosses/corona/front.4bpp.lz");
const u32 gBossPalette_Yeti[] = INCBIN_U32("graphics/bosses/yeti/normal.gbapal.lz");
const u32 gBossFrontPic_Yeti[] = INCBIN_U32("graphics/bosses/yeti/front.4bpp.lz");
const u32 gBossPalette_Masuda[] = INCBIN_U32("graphics/bosses/masuda/normal.gbapal.lz");
const u32 gBossFrontPic_Masuda[] = INCBIN_U32("graphics/bosses/masuda/front.4bpp.lz");
const u32 gBossPalette_Titan[] = INCBIN_U32("graphics/bosses/titan/normal.gbapal.lz");
const u32 gBossFrontPic_Titan[] = INCBIN_U32("graphics/bosses/titan/front.4bpp.lz");

const struct CompressedSpriteSheet gBossFrontPicTable[] =
{
    [BOSS_CORONA] = {gBossFrontPic_Corona, 0x800, SPECIES_NONE},
    [BOSS_YETI] = {gBossFrontPic_Yeti, 0x800, SPECIES_NONE},
    [BOSS_MASUDA] = {gBossFrontPic_Masuda   , 0x800, SPECIES_NONE},
    [BOSS_TITAN] = {gBossFrontPic_Titan   , 0x800, SPECIES_NONE},
};

const struct CompressedSpritePalette gBossPaletteTable[] =
{
    [BOSS_CORONA] = {gBossPalette_Corona, SPECIES_NONE},
    [BOSS_YETI] = {gBossPalette_Yeti, SPECIES_NONE},
    [BOSS_MASUDA] = {gBossPalette_Masuda, SPECIES_NONE},
    [BOSS_TITAN] = {gBossPalette_Titan, SPECIES_NONE},
};

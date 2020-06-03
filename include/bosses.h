#define BATTLE_TYPE_BOSS  23
#define BATTLE_TYPE_TOTEM 12

#define BOSS_BATTLE_KEFKA 23
#define BOSS_KEFKA 23

struct TotemMon
{
    u16 species;
    u8 statBoosts[8];
};

struct Boss
{
    const u8 *name;
    u8 level;
    u16 hp;
    u16 attack;
    u16 defense;
    u16 spAttack;
    u16 spDefense;
    u16 speed;
    u8 item;
    u8 expYield;
    u8 nature;
    u16 moves[4];
    u8 ability;
    u8 type1;
    u8 type2;
};

struct BossBattle {
    u8 battleType;
    u16 music;
    union {
        struct TotemMon mon;
        u8 bossId;
    } boss;
};

extern const struct BossBattle gBossBattles[];

extern const struct Boss gBosses[];

extern const struct CompressedSpriteSheet gBossFrontPicTable[];
extern const struct CompressedSpritePalette gBossPaletteTable[];

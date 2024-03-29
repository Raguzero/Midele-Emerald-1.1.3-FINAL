#ifndef GUARD_BOSS_BATTLES_H
#define GUARD_BOSS_BATTLES_H

/*
  Estructura de datos boss battle.
    music: Música que sonará en combate (songs.h)
    battleType: tipo de boss battle (constants/boss_battles.h)
    weather: clima que aparecerá durante el combate.
    boss: totemId indica el ID del Pokémon Totem en caso de que la battleType sea BATTLE_TYPE_TOTEM,
          bossId indica el ID del BOSS en caso de que la battleType sea BATTLE_TYPE_BOSS.
*/
struct BossBattle {
    u16 music;
    u8 battleType;
    u8 weather;
    union {
        u8 totemId;
        u8 bossId;
    } boss;
};

/*
  Estructura de datos de los bosses.
*/
struct Boss
{
    u8 level;
    u8 type1;
    u8 type2;
    u8 ability;
    u8 hpType;
    u16 hp;
    u16 attack;
    u16 defense;
    u16 spAttack;
    u16 spDefense;
    u16 speed;
    u16 item;
    u16 moves[MAX_MON_MOVES];
    const u8 *name;
};

/*
    Estructura de datos de los Pokémon Totem.
    minLevel: nivel mínimo del combate.
    statBoosts: Incremento de los stats en este orden: HP, ATK, DEF, SPD, SPATK, SPDEF, ACC, EVA.
                Los valores de boost van desde 0 (-6) hasta 12 (+6).
    evs: Los EVs, en este orden: HP, ATK, DEF, SPD, SPATK, SPDEF.
*/
struct TotemMon
{
    u8 minLevel;
    u8 nature;
    u8 abilityNumber;
    u8 hpType;
    u8 statBoosts[NUM_BATTLE_STATS];
    u8 evs[NUM_STATS];
    u16 species;
    u16 item;
    u16 moves[MAX_MON_MOVES];
};


extern const struct BossBattle gBossBattles[];
extern const struct Boss gBosses[];
extern const struct TotemMon gTotemMons[];
extern const struct CompressedSpriteSheet gBossFrontPicTable[];
extern const struct CompressedSpritePalette gBossPaletteTable[];

#endif // GUARD_BOSS_BATTLES_H

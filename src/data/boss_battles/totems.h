const struct TotemMon gTotemMons[] =
{
    [TOTEM_SUDOWOODO_DEBUG] =
    {
        .species = SPECIES_SUDOWOODO,
        .minLevel = 30,
        .hpType = TYPE_GRASS,
        .moves = {MOVE_HIDDEN_POWER, MOVE_NASTY_PLOT, MOVE_ACID_ARMOR, MOVE_AGILITY},
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_CALM,
        .abilityNumber = 0,
        .statBoosts = {6, 6, 6, 12, 10, 8, 0, 2}, 
        .evs = {252, 0, 0, 252, 0, 0},
    },
	[TOTEM_TOXTRICITY] =
    {
        .species = SPECIES_TOXTRICITY_LK,
        .minLevel = 30,
        .moves = {MOVE_THUNDERBOLT, MOVE_HYPER_VOICE, MOVE_FIRE_PUNCH, MOVE_SLUDGE_BOMB},
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_NAIVE,
        .abilityNumber = 0, // PUNK ROCK
        .statBoosts = {6, 6, 8, 6, 6, 8, 6, 6}, // HP, ATK, DEF, SPEED, SATK, SDEF, PRECISION, EVASION
        .evs = {252, 100, 56, 100, 56, 56},
    },
	[TOTEM_COFAGRIGUS] =
    {
        .species = SPECIES_COFAGRIGUS,
        .minLevel = 30,
        .moves = {MOVE_SHADOW_BALL, MOVE_SPITE, MOVE_SHOCK_WAVE, MOVE_WILL_O_WISP},
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_QUIET,
        .abilityNumber = 0, // MUMMY
        .statBoosts = {6, 7, 6, 6, 7, 6, 6, 6}, // HP, ATK, DEF, SPEED, SATK, SDEF, PRECISION, EVASION
        .evs = {252, 100, 56, 100, 56, 56},
    },
	[TOTEM_CENTISKORCH] =
    {
        .species = SPECIES_CENTISKORCH,
        .minLevel = 23,
        .moves = {MOVE_FLAME_WHEEL, MOVE_SOLAR_BEAM, MOVE_SMOKESCREEN, MOVE_BITE},
        .item = ITEM_NONE,
        .nature = NATURE_QUIET,
        .abilityNumber = 0, // FLASH FIRE
        .statBoosts = {6, 6, 7, 6, 6, 7, 6, 6}, // HP, ATK, DEF, SPEED, SATK, SDEF, PRECISION, EVASION
        .evs = {252, 0, 56, 100, 56, 56},
    },
    [TOTEM_WINTASS] =
    {
        .species = SPECIES_WINTASS,
        .minLevel = 33,
        .moves = {MOVE_BLIZZARD, MOVE_MACH_PUNCH, MOVE_ROCK_BLAST, MOVE_MUD_SHOT},
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_ADAMANT,
        .abilityNumber = 1, // TECHNICIAN
        .statBoosts = {6, 6, 8, 6, 6, 8, 6, 6}, // HP, ATK, DEF, SPEED, SATK, SDEF, PRECISION, EVASION
        .evs = {252, 152, 56, 56, 56, 106},
    },
    [TOTEM_MEGA_GLALIE] =
    {
        .species = SPECIES_MEGA_GLALIE,
        .minLevel = 80,
        .moves = {MOVE_BLIZZARD, MOVE_EARTHQUAKE, MOVE_WATER_PULSE, MOVE_CRUNCH},
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_QUIET,
        .abilityNumber = 1, // ICE BODY
        .statBoosts = {6, 7, 9, 6, 6, 9, 6, 6}, // HP, ATK, DEF, SPEED, SATK, SDEF, PRECISION, EVASION
        .evs = {252, 252, 252, 252, 252, 252},
    },
	[TOTEM_MEGA_CAMERUPT] =
    {
        .species = SPECIES_MEGA_CAMERUPT,
        .minLevel = 70,
        .moves = {MOVE_SOLAR_BEAM, MOVE_EARTHQUAKE, MOVE_FIRE_BLAST, MOVE_WILL_O_WISP},
        .item = ITEM_CHARCOAL,
        .nature = NATURE_QUIET,
        .abilityNumber = 0, // SHEER_FORCE
        .statBoosts = {6, 6, 12, 6, 6, 12, 6, 6}, // HP, ATK, DEF, SPEED, SATK, SDEF, PRECISION, EVASION
        .evs = {252, 252, 252, 252, 252, 252},
    },
    [TOTEM_MEGA_ABSOL] =
    {
        .species = SPECIES_MEGA_ABSOL,
        .minLevel = 40,
        .moves = {MOVE_SLASH, MOVE_FOCUS_ENERGY, MOVE_KNOCK_OFF, MOVE_X_SCISSOR},
        .item = ITEM_SCOPE_LENS,
        .nature = NATURE_JOLLY,
        .abilityNumber = 1, // SUPER LUCK
        .statBoosts = {6, 6, 8, 6, 6, 8, 6, 6}, // HP, ATK, DEF, SPEED, SATK, SDEF, PRECISION, EVASION
        .evs = {252, 0, 252, 0, 252, 0},
    },
    [TOTEM_PROBOPASS] =
    {
        .species = SPECIES_PROBOPASS,
        .minLevel = 13,
        .moves = {MOVE_TAUNT, MOVE_ROCK_THROW, MOVE_SANDSTORM, MOVE_MUD_SLAP},
        .item = ITEM_NONE,
        .nature = NATURE_HARDY,
        .abilityNumber = 0, // STURDY
        .statBoosts = {6, 6, 6, 7, 6, 6, 6, 6}, // HP, ATK, DEF, SPEED, SATK, SDEF, PRECISION, EVASION
        .evs = {252, 0, 0, 0, 0, 0},
    },
    [TOTEM_RHYPERIOR] =
    {
        .species = SPECIES_RHYPERIOR,
        .minLevel = 38,
        .moves = {MOVE_FLAMETHROWER, MOVE_ANCIENT_POWER, MOVE_THUNDER_PUNCH, MOVE_DRILL_RUN},
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_SASSY,
        .abilityNumber = 1, // SOLID ROCK
        .statBoosts = {6, 6, 6, 6, 12, 8, 6, 6}, // HP, ATK, DEF, SPEED, SATK, SDEF, PRECISION, EVASION
        .evs = {252, 0, 0, 0, 252, 252},
    },
    [TOTEM_TYRANITAR] =
    {
        .species = SPECIES_TYRANITAR,
        .minLevel = 85,
        .moves = {MOVE_CRUNCH, MOVE_EARTHQUAKE, MOVE_ROCK_SLIDE, MOVE_FIRE_BLAST},
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_BRAVE,
        .abilityNumber = 0, // SANDS STREAM
        .statBoosts = {6, 6, 7, 12, 7, 7, 8, 6}, // HP, ATK, DEF, SPEED, SATK, SDEF, PRECISION, EVASION
        .evs = {252, 252, 252, 252, 252, 252},
    },
    [TOTEM_PRIMARINA] =
    {
        .species = SPECIES_PRIMARINA,
        .minLevel = 45,
        .moves = {MOVE_WHIRLPOOL, MOVE_DAZZLING_GLEAM, MOVE_TOXIC, MOVE_ENERGY_BALL},
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_CALM,
        .abilityNumber = 1, // CUTE CHARM
        .statBoosts = {6, 6, 7, 6, 6, 7, 6, 6},  // HP, ATK, DEF, SPEED, SATK, SDEF, PRECISION, EVASION
        .evs = {252, 0, 252, 0, 252, 0},
    },
    [TOTEM_SAPPHIRE] =
    {
        .species = SPECIES_DARK_PIKACHU,
        .minLevel = 75,
        .moves = {MOVE_THUNDER, MOVE_SURF, MOVE_BRUTAL_BALL, MOVE_CONFUSE_RAY},
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_MODEST,
        .abilityNumber = 0, // INTIMIDATE
        .statBoosts = {6, 6, 8, 6, 6, 8, 6, 6}, // HP, ATK, DEF, SPEED, SATK, SDEF, PRECISION, EVASION
        .evs = {252, 252, 252, 252, 252, 252},
    }
};

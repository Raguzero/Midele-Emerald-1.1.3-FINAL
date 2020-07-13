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
        .moves = {MOVE_OVERDRIVE, MOVE_HYPER_VOICE, MOVE_FIRE_PUNCH, MOVE_SLUDGE_BOMB},
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_NAIVE,
        .abilityNumber = 0,
        .statBoosts = {6, 6, 8, 6, 6, 8, 6, 6},
        .evs = {252, 100, 56, 100, 56, 56},
    },
	[TOTEM_COFAGRIGUS] = 
    {
        .species = SPECIES_COFAGRIGUS,
        .minLevel = 30,
        .moves = {MOVE_SHADOW_BALL, MOVE_REVENGE, MOVE_PSYCHIC, MOVE_WILL_O_WISP},
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_BRAVE,
        .abilityNumber = 0,
        .statBoosts = {6, 8, 8, 6, 8, 8, 6, 6},
        .evs = {252, 100, 56, 100, 56, 56},
    }
};

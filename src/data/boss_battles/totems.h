const struct TotemMon gTotemMons[] = 
{
    [TOTEM_SUDOWOODO_DEBUG] = 
    {
        .species = SPECIES_SUDOWOODO,
        .level = 100,
        .hpType = TYPE_GRASS,
        .moves = {MOVE_HIDDEN_POWER, MOVE_NASTY_PLOT, MOVE_ACID_ARMOR, MOVE_AGILITY},
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_CALM,
        .abilityNumber = 0,
        .statBoosts = {6, 6, 6, 12, 10, 8, 0, 2},
        .evs = {252, 0, 0, 252, 0, 0},
    },
	[TOTEM_MANECTRIC] = 
    {
        .species = SPECIES_MANECTRIC,
        .level = 30,
        .moves = {MOVE_THUNDER, MOVE_FLAMETHROWER, MOVE_HIDDEN_POWER, MOVE_CRUNCH},
        .item = ITEM_LEFTOVERS,
        .nature = NATURE_TIMID,
		.hpType = TYPE_ICE,
        .abilityNumber = 0,
        .statBoosts = {6, 6, 8, 6, 6, 8, 6, 6},
        .evs = {100, 56, 56, 56, 56, 56},
    }
};

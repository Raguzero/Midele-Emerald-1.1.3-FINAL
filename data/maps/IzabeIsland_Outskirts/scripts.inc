IzabeIsland_Outskirts_MapScripts::
	.byte 0

IzabeIsland_Town_EventScript_ItemOutskirts_SilverPowder::
	finditem ITEM_SILVER_POWDER
	end

IzabeIsland_Town_EventScript_ItemOutskirts_SharpBeak::
	finditem ITEM_SHARP_BEAK
	end

IzabeIsland_Town_EventScript_ItemOutskirts_KingsRock::
	finditem ITEM_KINGS_ROCK
	end

IzabeIsland_Town_EventScript_ItemOutskirts_TwistedSpoon::
	finditem ITEM_TWISTED_SPOON
	end

IzabeIsland_Town_EventScript_ItemOutskirts_BlackBelt::
	finditem ITEM_BLACK_BELT
	end

IzabeIsland_Outskirts_EventScript_Camper::
	trainerbattle_single TRAINER_IZABE_CAMPER, IzabeIsland_Outskirts_Text_CamperIntro, IzabeIsland_Outskirts_Text_CamperDefeat
	msgbox IzabeIsland_Outskirts_Text_CamperPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_CamperIntro::
	.string "$"

IzabeIsland_Outskirts_Text_CamperDefeat::
	.string "$"

IzabeIsland_Outskirts_Text_CamperPostBattle::
	.string "$"

IzabeIsland_Outskirts_EventScript_Hiker::
	trainerbattle_single TRAINER_IZABE_HIKER, IzabeIsland_Outskirts_Text_HikerIntro, IzabeIsland_Outskirts_Text_HikerDefeat
	msgbox IzabeIsland_Outskirts_Text_HikerPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_HikerIntro::
	.string "$"

IzabeIsland_Outskirts_Text_HikerDefeat::
	.string "$"

IzabeIsland_Outskirts_Text_HikerPostBattle::
	.string "$"

IzabeIsland_Outskirts_EventScript_HexManiac::
	trainerbattle_single TRAINER_IZABE_HEXMANIAC, IzabeIsland_Outskirts_Text_HexManiacIntro, IzabeIsland_Outskirts_Text_HexManiacDefeat
	msgbox IzabeIsland_Outskirts_Text_HexManiacPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_HexManiacIntro::
	.string "$"

IzabeIsland_Outskirts_Text_HexManiacDefeat::
	.string "$"

IzabeIsland_Outskirts_Text_HexManiacPostBattle::
	.string "$"

IzabeIsland_Outskirts_EventScript_Fisherman::
	trainerbattle_single TRAINER_IZABE_FISHERMAN, IzabeIsland_Outskirts_Text_FishermanIntro, IzabeIsland_Outskirts_Text_FishermanDefeat
	msgbox IzabeIsland_Outskirts_Text_FishermanPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_FishermanIntro::
	.string "$"

IzabeIsland_Outskirts_Text_FishermanDefeat::
	.string "$"

IzabeIsland_Outskirts_Text_FishermanPostBattle::
	.string "$"

IzabeIsland_Outskirts_EventScript_Pokemaniac::
	trainerbattle_single TRAINER_IZABE_POKEMANIAC, IzabeIsland_Outskirts_Text_PokemaniacIntro, IzabeIsland_Outskirts_Text_PokemaniacDefeat
	msgbox IzabeIsland_Outskirts_Text_PokemaniacPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_PokemaniacIntro::
	.string "$"

IzabeIsland_Outskirts_Text_PokemaniacDefeat::
	.string "$"

IzabeIsland_Outskirts_Text_PokemaniacPostBattle::
	.string "$"

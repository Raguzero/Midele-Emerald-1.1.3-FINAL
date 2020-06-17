IzabeIsland_Outskirts_MapScripts::
	.byte 0

IzabeIsland_Town_EventScript_ItemOutskirts1::
	finditem ITEM_G_PROTEIN
	end

IzabeIsland_Town_EventScript_ItemOutskirts2::
	finditem ITEM_G_ZINC
	end

IzabeIsland_Town_EventScript_ItemOutskirts3::
	finditem ITEM_G_IRON
	end

IzabeIsland_Town_EventScript_ItemOutskirts4::
	finditem ITEM_G_CARBOS
	end

IzabeIsland_Town_EventScript_ItemOutskirts5::
	finditem ITEM_G_HP_UP
	end

IzabeIsland_Outskirts_EventScript_Camper::
	trainerbattle_single TRAINER_DEBUG, IzabeIsland_Outskirts_Text_CamperIntro, IzabeIsland_Outskirts_Text_CamperDefeat
	msgbox IzabeIsland_Outskirts_Text_CamperPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_CamperIntro::
	.string "$"

IzabeIsland_Outskirts_Text_CamperDefeat::
	.string "$"

IzabeIsland_Outskirts_Text_CamperPostBattle::
	.string "$"

IzabeIsland_Outskirts_EventScript_Hiker::
	trainerbattle_single TRAINER_DEBUG, IzabeIsland_Outskirts_Text_HikerIntro, IzabeIsland_Outskirts_Text_HikerDefeat
	msgbox IzabeIsland_Outskirts_Text_HikerPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_HikerIntro::
	.string "$"

IzabeIsland_Outskirts_Text_HikerDefeat::
	.string "$"

IzabeIsland_Outskirts_Text_HikerPostBattle::
	.string "$"

IzabeIsland_Outskirts_EventScript_HexManiac::
	trainerbattle_single TRAINER_DEBUG, IzabeIsland_Outskirts_Text_HexManiacIntro, IzabeIsland_Outskirts_Text_HexManiacDefeat
	msgbox IzabeIsland_Outskirts_Text_HexManiacPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_HexManiacIntro::
	.string "$"

IzabeIsland_Outskirts_Text_HexManiacDefeat::
	.string "$"

IzabeIsland_Outskirts_Text_HexManiacPostBattle::
	.string "$"

IzabeIsland_Outskirts_EventScript_Fisherman::
	trainerbattle_single TRAINER_DEBUG, IzabeIsland_Outskirts_Text_FishermanIntro, IzabeIsland_Outskirts_Text_FishermanDefeat
	msgbox IzabeIsland_Outskirts_Text_FishermanPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_FishermanIntro::
	.string "$"

IzabeIsland_Outskirts_Text_FishermanDefeat::
	.string "$"

IzabeIsland_Outskirts_Text_FishermanPostBattle::
	.string "$"

IzabeIsland_Outskirts_EventScript_Pokemaniac::
	trainerbattle_single TRAINER_DEBUG, IzabeIsland_Outskirts_Text_PokemaniacIntro, IzabeIsland_Outskirts_Text_PokemaniacDefeat
	msgbox IzabeIsland_Outskirts_Text_PokemaniacPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_PokemaniacIntro::
	.string "$"

IzabeIsland_Outskirts_Text_PokemaniacDefeat::
	.string "$"

IzabeIsland_Outskirts_Text_PokemaniacPostBattle::
	.string "$"

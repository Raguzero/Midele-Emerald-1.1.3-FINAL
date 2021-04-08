IzabeIsland_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IzabeIsland_PokemonCenter_1F_OnTransition

	.byte 0

IzabeIsland_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_IZABE_ISLAND_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

IzabeIsland_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

IzabeIsland_PokemonCenter_1F_EventScript_Fisherman::
	msgbox IzabeIsland_PokemonCenter_1F_Text_Fisherman, MSGBOX_NPC
	end

IzabeIsland_PokemonCenter_1F_Text_Fisherman::
	.string "Dicen que las estatuas de la isla están\n"
	.string "relacionadas con la cueva de las\l"
	.string "afueras de la ciudad.$"

Micolandia_PokemonCenter1F_MapScripts:: @ 820DABF
	map_script MAP_SCRIPT_ON_TRANSITION, Micolandia_PokemonCenter1F_OnTransition

	.byte 0

Micolandia_PokemonCenter1F_OnTransition: @ 820DACA
	setrespawn HEAL_LOCATION_MICOLANDIA
	call Common_EventScript_UpdateBrineyLocation
	end

@ VAR_0x800B is the Nurse's object event id
Micolandia_PokemonCenter1F_EventScript_Nurse:: @ 820DAD3
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Micolandia_PokemonCenter1F_EventScript_LeagueGuard::
	msgbox Micolandia_PokemonCenter1F_EventScript_LeagueGuard_Text_0, MSGBOX_NPC
	return


Micolandia_PokemonCenter1F_EventScript_LeagueGuard_Text_0:
	.string "Lo siento, no puedes pasar por aquí.\p"
	.string "Sin embargo, entrenador... no te rindas.\n"
	.string "Algún día podrás.$"


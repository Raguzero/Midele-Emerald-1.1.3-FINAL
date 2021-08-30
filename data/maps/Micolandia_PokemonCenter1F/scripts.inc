Micolandia_PokemonCenter1F_MapScripts:: @ 820DABF
	map_script MAP_SCRIPT_ON_TRANSITION, Micolandia_PokemonCenter1F_OnTransition

	.byte 0

Micolandia_PokemonCenter1F_OnTransition: @ 820DACA
	setrespawn HEAL_LOCATION_MICOLANDIA
	call Common_EventScript_UpdateBrineyLocation
	end
	
Micolandia_PokemonCenter1F_EventScript_NPCPhrases::
	lock
	faceplayer
	msgbox Micolandia_PokemonCenter1F_Text_Phrases, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Micolandia_PokemonCenter1F_EventScript_NPCPhrases2
	release
	end

Micolandia_PokemonCenter1F_EventScript_NPCPhrases2::
	msgbox Micolandia_PokemonCenter1F_Text_Phrases2, MSGBOX_NPC
	release
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
	
Micolandia_PokemonCenter1F_Text_Phrases:
	.string "Hola, tengo información confidencial\n"
	.string "sobre ciertas frases que puedes\l"
	.string "decirle a la BERRY MASTER de ROUTE 123\l"
	.string "para conseguir bayas exclusivas.\l"

	.string "¿Quieres que te diga las frases?$"
	
Micolandia_PokemonCenter1F_Text_Phrases2:	
	.string "Bien, estas son las frases:\p"
	.string "GREAT BATTLE\p"
	.string "CHALLENGE CONTEST\p"
	.string "OVERWHELMING LATIAS\p"
	.string "COOL LATIOS\p"
	.string "SUPER HUSTLE\p"
	
	.string "Pero ten en cuenta que las frases de\n"
	.string "LATIOS y LATIAS no podrás usarlas\l"
	.string "hasta que al menos los registres\l"
	.string "en la POKéDEX como vistos.$"
	

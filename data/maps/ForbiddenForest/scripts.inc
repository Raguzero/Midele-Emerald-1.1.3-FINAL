ForbiddenForest_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ForbiddenForest_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, ForbiddenForest_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, ForbiddenForest_OnLoad
	.byte 0
	
ForbiddenForest_OnResume: 
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ForbiddenForest_EventScript_TryRemoveCelebi
	end
	
ForbiddenForest_OnTransition:
	setflag FLAG_LANDMARK_FORBIDDEN_FOREST
	call_if_unset FLAG_CAUGHT_CELEBI, ForbiddenForest_EventScript_TryShowCelebi
	end
	
ForbiddenForest_OnLoad:
	call_if_unset FLAG_FORBIDDEN_FOREST_CELEBI_ENTRANCE, ForbiddenForest_Script_Close
	end
	
ForbiddenForest_EventScript_Celebi_Sign::
	lockall
	msgbox ForbiddenForest_Text_Celebi, MSGBOX_SIGN
	specialvar VAR_RESULT, CheckJirachiMewinTeam
	compare VAR_RESULT, TRUE
	goto_if_eq ForbiddenForest_EventScript_Celebi_Sign2
	end

ForbiddenForest_EventScript_Celebi_Sign2::
	setmetatile 19, 12, METATILE_General_Grass, 0
	setmetatile 19, 13, METATILE_General_Grass, 0
	setmetatile 19, 14, METATILE_General_Grass, 0
	setmetatile 19, 15, METATILE_General_Grass, 0
	setmetatile 20, 12, METATILE_General_Grass, 0
	setmetatile 20, 13, METATILE_General_Grass, 0
	setmetatile 20, 14, METATILE_General_Grass, 0
	setmetatile 20, 15, METATILE_General_Grass, 0
	special DrawWholeMapView
	setflag FLAG_FORBIDDEN_FOREST_CELEBI_ENTRANCE
	msgbox ForbiddenForest_Text_Celebi2, MSGBOX_SIGN
	releaseall
	end
	
ForbiddenForest_Script_Close::
	setmetatile 19, 12, METATILE_General_Grass_TreeUp, 1
	setmetatile 19, 13, 0x016, 1
	setmetatile 19, 14, METATILE_General_Grass_TreeUp, 1
	setmetatile 19, 15, 0x016, 1
	setmetatile 20, 12, METATILE_General_Grass_TreeUp, 1
	setmetatile 20, 13, 0x016, 1
	setmetatile 20, 14, METATILE_General_Grass_TreeUp, 1
	setmetatile 20, 15, 0x016, 1
	return

ForbiddenForest_EventScript_TryRemoveCelebi::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject 1
	return

ForbiddenForest_EventScript_HideCelebi::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_CELEBI
	return

ForbiddenForest_EventScript_TryShowCelebi::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_CELEBI, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_CELEBI
	return

ForbiddenForest_EventScript_Celebi::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CELEBI, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_CELEBI, 60, ITEM_LUM_BERRY
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ForbiddenForest_EventScript_DefeatedCelebi
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq ForbiddenForest_EventScript_RanFromCelebi
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq ForbiddenForest_EventScript_RanFromCelebi
	setflag FLAG_CAUGHT_CELEBI
	release
	end

ForbiddenForest_EventScript_DefeatedCelebi:: 
	setflag FLAG_DEFEATED_CELEBI
	goto Common_EventScript_RemoveStaticPokemon
	end

ForbiddenForest_EventScript_RanFromCelebi:: 
	setvar VAR_0x8004, SPECIES_CELEBI
	goto Common_EventScript_LegendaryFlewAway
	end
	
ForbiddenForest_EventScript_Ezecuter::  
	trainerbattle_single TRAINER_FORBIDDENFOREST_EZECUTER, ForbiddenForest_Text_EzecuterIntro, ForbiddenForest_Text_EzecuterDefeat
	msgbox ForbiddenForest_Text_EzecuterPostBattle, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_EventScript_Kefky::
	trainerbattle_single TRAINER_KEFKY, Kefky_AntesBatalla, Kefky_MensajeDerrota
	msgbox Kefky_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end

ForbiddenForest_EventScript_ElPrincipe::
	trainerbattle_double TRAINER_ELPRINCIPE, ElPrincipe_AntesBatalla, ElPrincipe_MensajeDerrota, ElPrincipe_Text_MasdeunPokemon
	msgbox ElPrincipe_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_Text_Celebi:
	.string "El cartel se ha deteriorado\n"
	.string "por el paso del tiempo y solo\l"
	.string "se puede leer lo siguiente:\p"
	
	.string "El ca..no sol. s. .br.r.\n"
	.string "c.n l.s mi.tic.s M.W y\p"
	.string "JI...HI\n$"
	
ForbiddenForest_Text_Celebi2:
	.string "El camino se ha abierto.$"

ForbiddenForest_Text_EzecuterIntro: 
	.string "Dicen que por aquí se esconde.\n"
	.string "un Pokémon legendario.$"

ForbiddenForest_Text_EzecuterDefeat: 
	.string "¡¡¡Eres bochornoso!!!$"

ForbiddenForest_Text_EzecuterPostBattle: 
	.string "Eres totalmente bochornoso.$"
	
Kefky_AntesBatalla: 
	.string "Yo solo uso un Pokémon si es mono.$"

Kefky_MensajeDerrota: 
	.string "¿A que eran monos?$"
 
Kefky_DespuesDeBatalla:
	.string "Me he vestido de mujer por perder\n"
	.string "una apuesta, pero soy un tío.$"

ElPrincipe_AntesBatalla: 
	.string "¡Por fin he ideado la estrategia\n"
	.string "definitiva que me llevará a lo\l"
	.string "más alto del firmamento!\p"
	
	.string "Ten en cuenta que esto será una\n"
	.string "BATALLA DOBLE.\p"

	.string "Te mostraré la estrategia de mi\n"
	.string "fenomenal equipo.\p"
	
	.string "La genuina estrategia de la...\n"
	.string "FLOR DEL FIRMAMENTO.$"

ElPrincipe_MensajeDerrota: 
	.string "¡IMPOSIBLE!\p"
	
	.string "La estrategia de la FLOR DEL\n"
	.string "FIRMAMENTO... con los 4 climas\l"
	.string "ha sido desarmada...\p"

	.string "No puedes saber que tipo de\n"
	.string "WEATHER BALL usa mi ROSERADE\l"
	.string "contra ti...\p"

	.string "Debería haberte puesto contra\n"
	.string "las cuerdas solo por eso...\p"

	.string "¡No lo entiendo!$"
 
ElPrincipe_DespuesDeBatalla:
	.string "Mirad, os quiero explicar cómo\n" 
	.string "funciona este equipo ya que no lo\l" 
	.string "voy a usar...\p"
	
	.string "Da igual a quien saque primero\n" 
	.string "la clave es sacar primero siempre\l"
	.string "a ROSERADE.\p"
	
	.string "Si saco a TYRANITAR con ROSERADE,\n" 
	.string "hago WEATHER BALL de tipo-roca sin\l" 
	.string "esperar a que TYRANITAR haga\l" 
	.string "SANDSTORM.\p" 
	
	.string "Si saco a JOLTEON, que es más rápido\n" 
	.string "que ROSERADE, hace RAIN DANCE y\l" 
	.string "ROSERADE WEATHER BALL del tipo-agua.\p"

	.string "Si uso SUNNY DAY, entonces mi\n" 
	.string "ROSERADE usará WEATHER BALL del\l"
	.string "tipo-fuego.\p" 	
	
	.string "Y por último lo puedo sacar también\n"
	.string "con ABOMASNOW, que no hace falta que\l" 
	.string "haga nada para que se ponga a granizar\l" 
	.string "y ROSERADE hace WEATHER BALL del\l"
	.string "tipo-hielo.\p"
	
	.string "...\p"
	
	.string "¿Qué 4 climas en un equipo de BATALLA\n"
	.string "DOBLES es una estupidez?\p"
	
	.string "...\p"
	
	.string "¿Y qué no puedo depender solo de mi\n"
	.string "ROSERADE para que toda la estrategia\l" 
	.string "funcione de forma óptima?\p"
	
	.string "¿Estás intentando decir que mi equipo es\n"
	.string "es malisimo y que lo rehaga de 0?\p"
	
	.string "¡No te mofes de mí, lo que pasa es que\n"
	.string "no tienes imaginación!$"
	
ElPrincipe_Text_MasdeunPokemon: // BATALLA DOBLE
	.string "Así que solo llevas un Pokémon?\n"
	.string "No puedo luchar contigo, entonces.\p"

	.string "Mi estrategia de la FLOR DEL FIRMAMENTO.\n"
	.string "solo brilla en BATALLA DOBLE$"

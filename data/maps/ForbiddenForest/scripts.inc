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
	
Kefky_AntesBatalla: 
	.string "Yo solo uso un Pokémon si es mono.$"

Kefky_MensajeDerrota: 
	.string "¿A que eran monos?$"
 
Kefky_DespuesDeBatalla:
	.string "Me he vestido de mujer por perder\n"
	.string "una apuesta, pero soy un tío.$"
	
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

ForbiddenForest_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ForbiddenForest_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, ForbiddenForest_OnTransition
	.byte 0
	
ForbiddenForest_OnResume: 
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ForbiddenForest_EventScript_TryRemoveCelebi
	end
	
ForbiddenForest_OnTransition:
	setflag FLAG_LANDMARK_FORBIDDEN_FOREST
	call_if_unset FLAG_CAUGHT_CELEBI, ForbiddenForest_EventScript_TryShowCelebi
	end
	
ForbiddenForest_EventScript_Celebi_Sign::
	msgbox ForbiddenForest_Text_Celebi, MSGBOX_SIGN
	end

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
	special StartRegiBattle
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
	
ForbiddenForest_EventScript_Barny::  @ ESTO ES COPYPASTE DE OTRO ENTRENADOR, YA SE CAMBIARÁ
	trainerbattle_single TRAINER_BARNY, ForbiddenForest_Text_BarnyIntro, ForbiddenForest_Text_BarnyDefeat
	msgbox ForbiddenForest_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_Text_Celebi:
	.string "El cartel se ha deteriorado\n"
	.string "por el paso del tiempo y solo\l"
	.string "se puede leer lo siguiente:\p"
	
	.string "El ca..no sol. s. .br.r.\n"
	.string "c.n l.s mi.tic.s M.W y\p"
	.string "JI...HI\n$"

ForbiddenForest_Text_BarnyIntro: 
	.string "I'm a FISHERMAN, but also a TRAINER.\n"
	.string "I'm raising the POKéMON I caught.$"

ForbiddenForest_Text_BarnyDefeat: 
	.string "I thought I was doing okay in my\n"
	.string "training…$"

ForbiddenForest_Text_BarnyPostBattle: 
	.string "I couldn't win by training POKéMON\n"
	.string "while I fished…\p"
	.string "Was I doing things in half measures?$"

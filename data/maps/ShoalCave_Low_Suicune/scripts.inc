ShoalCave_Low_Suicune_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ShoalCave_Low_Suicune_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_Low_Suicune_OnTransition
	.byte 0
	
ShoalCave_Low_Suicune_OnResume: @ 8238FC3
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ShoalCave_Low_Suicune_EventScript_TryRemoveSuicune
	end

ShoalCave_Low_Suicune_EventScript_TryRemoveSuicune:: @ 8238FCD
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

ShoalCave_Low_Suicune_OnTransition: @ 8238FE1
	//setflag FLAG_LANDMARK_ANCIENT_TOMB
	call_if_unset FLAG_CAUGHT_SUICUNE, ShoalCave_Low_Suicune_EventScript_TryShowSuicune
	end

ShoalCave_Low_Suicune_EventScript_TryShowSuicune:: @ 8238FEE
	goto_if_set FLAG_DEFEATED_SUICUNE, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_SUICUNE
	return
	
ShoalCave_Low_Suicune_EventScript_Suicune::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SUICUNE, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_SUICUNE, 60, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartLegendDogsBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ShoalCave_Low_Suicune_EventScript_DefeatedSuicune
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq ShoalCave_Low_Suicune_EventScript_RanFromSuicune
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq ShoalCave_Low_Suicune_EventScript_RanFromSuicune
	setflag FLAG_CAUGHT_SUICUNE
	release
	end

ShoalCave_Low_Suicune_EventScript_DefeatedSuicune:: @ 82390A1
	setflag FLAG_DEFEATED_SUICUNE
	goto Common_EventScript_RemoveStaticPokemon
	end

ShoalCave_Low_Suicune_EventScript_RanFromSuicune:: @ 82390AA
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryFlewAway
	end
	
ShoalCave_Hiker::
	msgbox ShoalCave_Low_Suicune_Hiker_Text, MSGBOX_NPC
	end

ShoalCave_Low_Suicune_Hiker_Text::
	.string "You shall not pass.\n"
	.string "It is dangerous to go\p"
	.string "alone.$"
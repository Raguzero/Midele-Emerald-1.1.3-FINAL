Route134_MapScripts:: @ 81F7644
	map_script MAP_SCRIPT_ON_RESUME, Route134_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route134_OnTransition
	.byte 0

Route134_OnResume: @ 81F764A
	setdivewarp MAP_UNDERWATER_ROUTE134, 255, 8, 6
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route134_EventScript_TryRemoveArticuno
	end
	
Route134_OnTransition:
	call_if_unset FLAG_CAUGHT_ARTICUNO, Route134_EventScript_TryShowArticuno
	end

Route134_EventScript_Jack:: @ 81F7653
	trainerbattle_single TRAINER_JACK, Route134_Text_JackIntro, Route134_Text_JackDefeat
	msgbox Route134_Text_JackPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Laurel:: @ 81F766A
	trainerbattle_single TRAINER_LAUREL, Route134_Text_LaurelIntro, Route134_Text_LaurelDefeat
	msgbox Route134_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Alex:: @ 81F7681
	trainerbattle_single TRAINER_ALEX, Route134_Text_AlexIntro, Route134_Text_AlexDefeat
	msgbox Route134_Text_AlexPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Aaron:: @ 81F7698
	trainerbattle_single TRAINER_AARON, Route134_Text_AaronIntro, Route134_Text_AaronDefeat
	msgbox Route134_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Hitoshi:: @ 81F76AF
	trainerbattle_single TRAINER_HITOSHI, Route134_Text_HitoshiIntro, Route134_Text_HitoshiDefeat
	msgbox Route134_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Hudson:: @ 81F76C6
	trainerbattle_single TRAINER_HUDSON, Route134_Text_HudsonIntro, Route134_Text_HudsonDefeat
	msgbox Route134_Text_HudsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Reyna:: @ 81F76DD
	trainerbattle_single TRAINER_REYNA, Route134_Text_ReynaIntro, Route134_Text_ReynaDefeat
	msgbox Route134_Text_ReynaPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Marley:: @ 81F76F4
	trainerbattle_single TRAINER_MARLEY, Route134_Text_MarleyIntro, Route134_Text_MarleyDefeat
	msgbox Route134_Text_MarleyPostBattle, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_Kelvin:: @ 81F770B
	trainerbattle_single TRAINER_KELVIN, Route134_Text_KelvinIntro, Route134_Text_KelvinDefeat
	msgbox Route134_Text_KelvinPostBattle, MSGBOX_AUTOCLOSE
	end
	
Route134_EventScript_TryRemoveArticuno::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject 12
	return

Route134_EventScript_HideArticuno::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_ARTICUNO
	return

Route134_EventScript_TryShowArticuno::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_ARTICUNO, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_ARTICUNO
	return

Route134_EventScript_Articuno::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ARTICUNO, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_ARTICUNO, 60, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Route134_EventScript_DefeatedArticuno
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Route134_EventScript_RanFromArticuno
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Route134_EventScript_RanFromArticuno
	setflag FLAG_CAUGHT_ARTICUNO
	release
	end

Route134_EventScript_DefeatedArticuno:: 
	setflag FLAG_DEFEATED_ARTICUNO
	goto Common_EventScript_RemoveStaticPokemon
	end

Route134_EventScript_RanFromArticuno:: 
	setvar VAR_0x8004, SPECIES_ARTICUNO
	goto Common_EventScript_LegendaryFlewAway
	end



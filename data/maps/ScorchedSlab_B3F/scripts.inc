ScorchedSlab_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ScorchedSlab_B3F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_B3F_OnTransition
	.byte 0
	
ScorchedSlab_B3F_OnResume: @ 8238FC3
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ScorchedSlab_B3F_EventScript_TryRemoveEntei
	end

ScorchedSlab_B3F_EventScript_TryRemoveEntei:: @ 8238FCD
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

ScorchedSlab_B3F_OnTransition: @ 8238FE1
	call_if_unset FLAG_CAUGHT_ENTEI, ScorchedSlab_B3F_EventScript_TryShowEntei
	end

ScorchedSlab_B3F_EventScript_TryShowEntei:: @ 8238FEE
	goto_if_set FLAG_DEFEATED_ENTEI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_ENTEI
	return
	
ScorchedSlab_B3F_EventScript_Entei::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ENTEI, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_ENTEI, 60, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartLegendDogsBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ScorchedSlab_B3F_EventScript_DefeatedEntei
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq ScorchedSlab_B3F_EventScript_RanFromEntei
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq ScorchedSlab_B3F_EventScript_RanFromEntei
	setflag FLAG_CAUGHT_ENTEI
	release
	end

ScorchedSlab_B3F_EventScript_DefeatedEntei:: @ 82390A1
	setflag FLAG_DEFEATED_ENTEI
	goto Common_EventScript_RemoveStaticPokemon
	end

ScorchedSlab_B3F_EventScript_RanFromEntei:: @ 82390AA
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryFlewAway
	end
	
ScorchedSlab_Hiker::
	msgbox ScorchedSlab_B3F_Hiker_Text, MSGBOX_NPC
	end

ScorchedSlab_B3F_Hiker_Text::
	.string "You shall not pass.\n"
	.string "It is dangerous to go\p"
	.string "alone.$"

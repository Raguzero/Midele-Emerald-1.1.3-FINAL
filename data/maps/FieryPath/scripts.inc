FieryPath_MapScripts:: @ 8230F24
	map_script MAP_SCRIPT_ON_RESUME, FieryPath_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
	.byte 0

FieryPath_OnTransition: @ 8230F2A
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
	setflag FLAG_LANDMARK_FIERY_PATH
	call_if_unset FLAG_CAUGHT_MOLTRES, Fiery_Path_EventScript_TryShowMoltres
	end
	
FieryPath_OnResume: 
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Fiery_Path_EventScript_TryRemoveMoltres
	end
	
    @ Combate contra totem.
Fiery_Path_EventScript_Totem:: @ 8237725
	lockall
	playmoncry SPECIES_CENTISKORCH, 2
	delay 40
	waitmoncry
	msgbox Fiery_Path_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_CENTISKORCH
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 9
	setflag FLAG_TOTEM_FIERYPATH
    msgbox Fiery_Path_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.	

FieryPath_EventScript_MoveScottToFallarbor:: @ 8230F37
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	return
	
Fiery_Path_EventScript_TryRemoveMoltres::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject 10
	return

Fiery_Path_EventScript_HideMoltres::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_MOLTRES
	return

Fiery_Path_EventScript_TryShowMoltres::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_MOLTRES, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_MOLTRES
	return

Fiery_Path_EventScript_Moltres::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MOLTRES, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_MOLTRES, 60, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Fiery_Path_EventScript_DefeatedMoltres
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Fiery_Path_EventScript_RanFromMoltres
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Fiery_Path_EventScript_RanFromMoltres
	setflag FLAG_CAUGHT_MOLTRES
	release
	end

Fiery_Path_EventScript_DefeatedMoltres:: 
	setflag FLAG_DEFEATED_MOLTRES
	goto Common_EventScript_RemoveStaticPokemon
	end

Fiery_Path_EventScript_RanFromMoltres:: 
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end

Fiery_Path_Text_Totemaparece:
	.string "CENTISKORCH, the Totem Pokémon of\n" 
	.string "Fiery Path, has appeared!$"
	
Fiery_Path_Text_Totemderrotado:
	.string "CENTISKORCH disappeared...$"


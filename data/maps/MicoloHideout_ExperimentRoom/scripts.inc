MicoloHideout_ExperimentRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MicoloHideout_ExperimentRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MicoloHideout_ExperimentRoom_OnTransition
	.byte 0
	
MicoloHideout_ExperimentRoom_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MicoloHideout_ExperimentRoom_EventScript_TryRemoveMewtwo
	end

MicoloHideout_ExperimentRoom_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MicoloHideout_ExperimentRoom_OnTransition:
	call_if_unset FLAG_CAUGHT_MEWTWO, MicoloHideout_ExperimentRoom_EventScript_TryShowMewtwo
	end

MicoloHideout_ExperimentRoom_EventScript_TryShowMewtwo::
	goto_if_set FLAG_DEFEATED_MEWTWO, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MEWTWO
	return
	
MicoloHideout_ExperimentRoom_EventScript_Mewtwo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEWTWO, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_MEWTWO, 70, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartLegendDogsBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_DefeatedMewtwo
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_RanFromMewtwo
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_RanFromMewtwo
	setflag FLAG_CAUGHT_MEWTWO
	release
	end

MicoloHideout_ExperimentRoom_EventScript_DefeatedMewtwo::
	setflag FLAG_DEFEATED_MEWTWO
	goto Common_EventScript_RemoveStaticPokemon
	end

MicoloHideout_ExperimentRoom_EventScript_RanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	end

MicoloHideout_ExperimentRoom_EventScript_LegendaryMachine::
	lock
	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineUse, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineEnd
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineNoRoom

	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineEnd
	
	special IsSelectedMonLegendary
	compare VAR_RESULT, FALSE
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineNotLegendary
	playse SE_TK_WARPIN
	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineReceivedMon, MSGBOX_DEFAULT
	waitse
	giveEgg VAR_0x8005
MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineEnd:
	release
	end

MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineNoRoom:
	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineNoRoom, MSGBOX_DEFAULT
	release
	end

MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineNotLegendary:
	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineNotLegendary, MSGBOX_DEFAULT
	release
	end

MicoloHideout_ExperimentRoom_Text_LegendaryMachineUse:
	.string "Hay un programa abierto en el PC.\p"
	.string "“Programa de crianza de legendarios\n"
	.string "100% legal n.n”\p"
	.string "¿Lo utilizas?$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineChooseMon:
	.string "Elige un POKéMON legendario.$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineReceivedMon:
	.string "¡Has obtenido un HUEVO de legendario!$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineNoRoom:
	.string "No tienes espacio en el equipo.$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineNotLegendary:
	.string "El POKéMON que has elegido no es un\n"
	.string "POKéMON legendario.$"

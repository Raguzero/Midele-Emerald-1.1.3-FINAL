OldaleRuins_MapScripts:: @ 8238E2A
	map_script MAP_SCRIPT_ON_RESUME, OldaleRuins_OnResume
	map_script MAP_SCRIPT_ON_LOAD, OldaleRuins_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleRuins_OnTransition
	.byte 0

OldaleRuins_OnResume: @ 8238E3A
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, OldaleRuins_EventScript_TryRemoveRegidrago
	end

OldaleRuins_EventScript_TryRemoveRegidrago:: @ 8238E44
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

OldaleRuins_OnLoad: @ 8238E58
	call_if_unset FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED, OldaleRuins_EventScript_HideRegiEntrance
	end

OldaleRuins_EventScript_HideRegiEntrance:: @ 8238E62
	setmetatile 7, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 8, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 9, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	return

OldaleRuins_OnTransition: @ 8238E99
	call_if_unset FLAG_CAUGHT_REGIDRAGO, OldaleRuins_EventScript_TryShowRegidrago
	end

OldaleRuins_EventScript_TryShowRegidrago:: @ 8238EAB
	goto_if_set FLAG_DEFEATED_REGIDRAGO, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_REGIDRAGO
	return

OldaleRuins_EventScript_OpenRegiEntrance:: @ 8238EAF
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, 1
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, 1
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, 0
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, 1
	special DrawWholeMapView
	playse SE_BAN
	setflag FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED
	end

OldaleRuins_EventScript_CaveEntranceMiddle:: @ 8238EEF
	lockall
	goto_if_set FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED, OldaleRuins_EventScript_BigHoleInWall
	goto OldaleRuins_EventScript_CloseBrailleMsg
	end

OldaleRuins_EventScript_BigHoleInWall:: @ 8238F13
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

OldaleRuins_EventScript_CaveEntranceSide:: @ 8238F1D
	lockall
	braillemessage IslandCave_Braille_RunLapAroundWall
	goto_if_set FLAG_SYS_BRAILLE_REGIDRAGO_COMPLETED, OldaleRuins_EventScript_CloseBrailleMsg
	goto OldaleRuins_EventScript_CloseBrailleMsg
	end

OldaleRuins_EventScript_CloseBrailleMsg:: @ 8238F41
	waitbuttonpress
	closebraillemessage
	releaseall
	end

OldaleRuins_EventScript_Regidrago:: @ 8238F58
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WOOLOO, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_WOOLOO, 40, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq OldaleRuins_EventScript_DefeatedRegidrago
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq OldaleRuins_EventScript_RanFromRegidrago
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq OldaleRuins_EventScript_RanFromRegidrago
	setflag FLAG_CAUGHT_REGIDRAGO
	release
	end

OldaleRuins_EventScript_DefeatedRegidrago:: @ 8238F9F
	setflag FLAG_DEFEATED_REGIDRAGO
	goto Common_EventScript_RemoveStaticPokemon
	end

OldaleRuins_EventScript_RanFromRegidrago:: @ 8238FA8
	setvar VAR_0x8004, SPECIES_WOOLOO
	goto Common_EventScript_LegendaryFlewAway
	end

MauvilleRuins_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MauvilleRuins_OnResume
	map_script MAP_SCRIPT_ON_LOAD, MauvilleRuins_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleRuins_OnTransition
	.byte 0

MauvilleRuins_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MauvilleRuins_EventScript_TryRemoveRegieleki
	end

MauvilleRuins_EventScript_TryRemoveRegieleki:: 
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MauvilleRuins_OnLoad:
	call_if_unset FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, MauvilleRuins_EventScript_HideRegiEntrance
	end

MauvilleRuins_EventScript_HideRegiEntrance:: 
	setmetatile 7, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 8, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 9, 19, METATILE_Cave_EntranceCover, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	setmetatile 9, 20, METATILE_Cave_SealedChamberBraille_Mid, 1
	return

MauvilleRuins_OnTransition: 
	setflag FLAG_LANDMARK_MAUVILLE_RUINS
	call_if_unset FLAG_CAUGHT_REGIELEKI, MauvilleRuins_EventScript_TryShowRegieleki
	end

MauvilleRuins_EventScript_TryShowRegieleki:: 
	goto_if_set FLAG_DEFEATED_REGIELEKI, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_REGIELEKI
	return

MauvilleRuins_EventScript_OpenRegiEntrance:: 
	setmetatile 7, 19, METATILE_Cave_SealedChamberEntrance_TopLeft, 1
	setmetatile 8, 19, METATILE_Cave_SealedChamberEntrance_TopMid, 1
	setmetatile 9, 19, METATILE_Cave_SealedChamberEntrance_TopRight, 1
	setmetatile 7, 20, METATILE_Cave_SealedChamberEntrance_BottomLeft, 1
	setmetatile 8, 20, METATILE_Cave_SealedChamberEntrance_BottomMid, 0
	setmetatile 9, 20, METATILE_Cave_SealedChamberEntrance_BottomRight, 1
	special DrawWholeMapView
	playse SE_BAN
	setflag FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED
	return

MauvilleRuins_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, MauvilleRuins_EventScript_BigHoleInWall
	braillemessage MauvilleRuins_Braille_RegielekiPuzzle
	waitbuttonpress
	closebraillemessage
	specialvar VAR_RESULT, CheckRegielekiPuzzle
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleRuins_EventScript_CaveEntranceMiddle_End
	call MauvilleRuins_EventScript_OpenRegiEntrance
MauvilleRuins_EventScript_CaveEntranceMiddle_End:
	releaseall
	end

MauvilleRuins_EventScript_BigHoleInWall:: 
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

MauvilleRuins_EventScript_CaveEntranceSide::
	lockall
	braillemessage MauvilleRuins_Braille_RegielekiPuzzle
	goto_if_set FLAG_SYS_BRAILLE_REGIELEKI_COMPLETED, MauvilleRuins_EventScript_CloseBrailleMsg
	braillemessage MauvilleRuins_Braille_RegielekiPuzzle
	waitbuttonpress
	closebraillemessage
	specialvar VAR_RESULT, CheckRegielekiPuzzle
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleRuins_EventScript_CaveEntranceSide_End
	call MauvilleRuins_EventScript_OpenRegiEntrance
MauvilleRuins_EventScript_CaveEntranceSide_End:
	releaseall
	end

MauvilleRuins_EventScript_CloseBrailleMsg::
	waitbuttonpress
	closebraillemessage
	releaseall
	end

MauvilleRuins_EventScript_Regieleki::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIELEKI, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 40, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MauvilleRuins_EventScript_DefeatedRegieleki
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq MauvilleRuins_EventScript_RanFromRegieleki
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq MauvilleRuins_EventScript_RanFromRegieleki
	setflag FLAG_CAUGHT_REGIELEKI
	release
	end

MauvilleRuins_EventScript_DefeatedRegieleki::
	setflag FLAG_DEFEATED_REGIELEKI
	goto Common_EventScript_RemoveStaticPokemon
	end

MauvilleRuins_EventScript_RanFromRegieleki:: 
	setvar VAR_0x8004, SPECIES_REGIELEKI
	goto Common_EventScript_LegendaryFlewAway
	end


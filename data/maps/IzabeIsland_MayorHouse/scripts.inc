IzabeIsland_MayorHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IzabeIsland_MayorHouse_OnTransition
	.byte 0

IzabeIsland_MayorHouse_OnTransition::
	compare VAR_IZABE_ISLAND_STATE, 0
	call_if_eq IzabeIsland_MayorHouse_EventScript_SetGuardBlockingDoor
	compare VAR_IZABE_ISLAND_STATE, 1
	call_if_eq IzabeIsland_MayorHouse_EventScript_SetGuardUnblockingDoor
	end

IzabeIsland_MayorHouse_EventScript_SetGuardBlockingDoor::
	setobjectxyperm 6, 6, 2
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
	return

IzabeIsland_MayorHouse_EventScript_SetGuardUnblockingDoor::
	setobjectxyperm 6, 5, 2
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
	return

IzabeIsland_MayorHouse_EventScript_Guard::
	compare VAR_IZABE_ISLAND_STATE, 0
	goto_if_eq IzabeIsland_MayorHouse_EventScript_Guard_AskForHelp
	compare VAR_IZABE_ISLAND_STATE, 1
	goto_if_eq IzabeIsland_MayorHouse_EventScript_Guard_ThanksForHelp
	end

IzabeIsland_MayorHouse_EventScript_Mayor::
	compare VAR_IZABE_ISLAND_STATE, 0
	goto_if_eq IzabeIsland_MayorHouse_EventScript_Mayor_AskForBattle
	compare VAR_IZABE_ISLAND_STATE, 1
	goto_if_eq IzabeIsland_MayorHouse_EventScript_Mayor_RememberPetition
	compare VAR_IZABE_ISLAND_STATE, 2
	goto_if_eq IzabeIsland_MayorHouse_EventScript_Mayor_GiveItem
	end

@ TODO: crear combate
IzabeIsland_MayorHouse_EventScript_Mayor_AskForBattle::
	lockall
	faceplayer
	msgbox IzabeIsland_MayorHouse_Text_Mayor_ExplainSituation, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_DEBUG, IzabeIsland_MayorHouse_Text_Mayor_BattleDefeated
	
	msgbox IzabeIsland_MayorHouse_Text_Mayor_AskForCooperation, MSGBOX_NPC
	setvar VAR_IZABE_ISLAND_STATE, 1
	applymovement 6, IzabeIsland_Movement_MoveGuardLeft
	waitmovement 0
	releaseall
	end

IzabeIsland_Movement_MoveGuardLeft::
	walk_left
	face_right
	step_end

IzabeIsland_MayorHouse_EventScript_Mayor_RememberPetition::
	lock
	faceplayer
	msgbox IzabeIsland_MayorHouse_Text_Mayor_AskForCooperation, MSGBOX_NPC
	release
	end

IzabeIsland_MayorHouse_EventScript_Mayor_GiveItem::
	end

IzabeIsland_MayorHouse_EventScript_Guard_AskForHelp::
	lock
	faceplayer
	msgbox IzabeIsland_MayorHouse_Text_Guard_AskForHelp, MSGBOX_NPC
	release
	end

IzabeIsland_MayorHouse_EventScript_Guard_ThanksForHelp::
	lock
	faceplayer
	msgbox IzabeIsland_MayorHouse_Text_Guard_ThanksForHelp, MSGBOX_NPC
	release
	end

IzabeIsland_MayorHouse_EventScript_OldWoman::
	msgbox IzabeIsland_MayorHouse_Text_OldWoman, MSGBOX_NPC
	end

IzabeIsland_MayorHouse_EventScript_GameBoyKid::
	msgbox IzabeIsland_MayorHouse_Text_GameBoyKid, MSGBOX_NPC
	end

IzabeIsland_MayorHouse_EventScript_FatMan1::
	msgbox IzabeIsland_MayorHouse_Text_FatMan1, MSGBOX_NPC
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	end

IzabeIsland_MayorHouse_EventScript_FatMan2::
	msgbox IzabeIsland_MayorHouse_Text_FatMan2, MSGBOX_NPC
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	end

IzabeIsland_MayorHouse_EventScript_FatMan3::
	msgbox IzabeIsland_MayorHouse_Text_FatMan3, MSGBOX_NPC
	applymovement 3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	end

IzabeIsland_MayorHouse_Text_Guard_AskForHelp::
	.string "Ask for help$"

IzabeIsland_MayorHouse_Text_Guard_ThanksForHelp::
	.string "Thank you for help$"

IzabeIsland_MayorHouse_Text_Mayor_ExplainSituation::
	.string "Hello, explain situation$"

IzabeIsland_MayorHouse_Text_Mayor_BattleIntro::
	.string "Battle begin$"

IzabeIsland_MayorHouse_Text_Mayor_BattleDefeated::
	.string "Battle end$"

IzabeIsland_MayorHouse_Text_Mayor_AskForCooperation::
	.string "Go there, please.$"

IzabeIsland_MayorHouse_Text_OldWoman::
	.string "Ay... este nieto mío siempre está con la\n"
	.string "maquinita. Vale que en esta isla no hay\l"
	.string "mucho que hacer, pero...\p"
	.string "En fin, la juventud...$"

IzabeIsland_MayorHouse_Text_GameBoyKid::
	.string "Jugar en las afueras del pueblo es muy\n"
	.string "aburrido, está lleno de entrenadores...\p"
	.string "Prefiero quedarme aquí jugando a mis\n"
	.string "videojuegos favoritos.$"

IzabeIsland_MayorHouse_Text_FatMan1::
	.string "¿Qué? No molestes, estamos jugando a\n"
	.string "WAIFUS & DRAGONS, 12ª edición.$"

IzabeIsland_MayorHouse_Text_FatMan2::
	.string "¿Qué? ¿Un 1 otra vez? Este dado está\n"
	.string "trucado, maldita sea...$"

IzabeIsland_MayorHouse_Text_FatMan3::
	.string "Zzz...\p"
	.string "Parece que se ha quedado dormido...$"

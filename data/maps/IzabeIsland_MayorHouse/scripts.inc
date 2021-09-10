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
	compare VAR_IZABE_ISLAND_STATE, 2
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

IzabeIsland_MayorHouse_EventScript_Mayor_AskForBattle::
	lockall
	faceplayer
	msgbox IzabeIsland_MayorHouse_Text_Mayor_ExplainSituation, MSGBOX_NPC
  closemessage
  faceplayer
  msgbox IzabeIsland_MayorHouse_Text_Mayor_AreYouPrepared, MSGBOX_YESNO
  compare VAR_RESULT, NO
  goto_if_eq IzabeIsland_MayorHouse_Event_Mayor_YouAreNotPrepared
	trainerbattle_no_intro TRAINER_IZABE_MAYOR, IzabeIsland_MayorHouse_Text_Mayor_BattleDefeated
	msgbox IzabeIsland_MayorHouse_Text_Mayor_AskForCooperation, MSGBOX_NPC
	setvar VAR_IZABE_ISLAND_STATE, 1
	applymovement 6, IzabeIsland_Movement_MoveGuardLeft
	waitmovement 0
	releaseall
	end

IzabeIsland_MayorHouse_Event_Mayor_YouAreNotPrepared:
  msgbox IzabeIsland_MayorHouse_Text_Mayor_YouAreNotPrepared, MSGBOX_NPC
  releaseall
  end

IzabeIsland_Movement_MoveGuardLeft::
	walk_left
	face_right
	step_end

IzabeIsland_MayorHouse_EventScript_Mayor_RememberPetition::
	msgbox IzabeIsland_MayorHouse_Text_Mayor_AskForCooperation, MSGBOX_NPC
	end

IzabeIsland_MayorHouse_EventScript_Mayor_GiveItem::
	msgbox IzabeIsland_MayorHouse_Text_Mayor_TakeYourReward, MSGBOX_NPC
	end

IzabeIsland_MayorHouse_EventScript_Guard_AskForHelp::
	msgbox IzabeIsland_MayorHouse_Text_Guard_AskForHelp, MSGBOX_NPC
	end

IzabeIsland_MayorHouse_EventScript_Guard_ThanksForHelp::
	msgbox IzabeIsland_MayorHouse_Text_Guard_ThanksForHelp, MSGBOX_NPC
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
	.string "Hola, ¿has venido en respuesta a la\n"
	.string "petición de nuestro ALCALDE?\p"
	.string "Si quieres pasar por aquí, tendrás que\n"
	.string "hablar con él. Es el hombre que está en\l"
	.string "esa mesa de allí, a la derecha.$"

IzabeIsland_MayorHouse_Text_Guard_ThanksForHelp::
	.string "Gracias por la ayuda. Cruzando esta\n"
	.string "puerta llegarás a las afueras de la\l"
	.string "ciudad. Ten cuidado, encontrarás toda\p"
	.string "clase de entrenadores y POKéMON\n"
	.string "merodeando por la zona.$"

IzabeIsland_MayorHouse_Text_Mayor_ExplainSituation::
	.string "Oh, no eres de por aquí...\n"
  .string "¿Ah, has venido a ayudar?\p"
  .string "Soy GARM, el alcalde de IZABE.\n"
  .string "Antes de nada me gustaría ponerte a\l"
  .string "prueba.$"

IzabeIsland_MayorHouse_Text_Mayor_AreYouPrepared::
  .string "¿Estás listo?$"

IzabeIsland_MayorHouse_Text_Mayor_YouAreNotPrepared::
  .string "Pues oc. Noob.$"

IzabeIsland_MayorHouse_Text_Mayor_BattleDefeated::
	.string "Pues oc.$"

IzabeIsland_MayorHouse_Text_Mayor_AskForCooperation::
	.string "Verás, resulta que alguien se ha perdido\n"
  .string "en las afueras del pueblo. Lo cual\l"
  .string "no sería un problema... si no fuera\l"
  .string "porque dicen que esa persona fue vista\l"
  .string "merodeando cerca de la cueva del oeste.\p"
  .string "Esa cueva es bastante inhóspita y\n"
  .string "últimamente ha habido rumores de\l"
  .string "extraños avistamientos...\p"
  .string "Por eso me gustaría que un entrenador\n"
  .string "como tú fuese a investigar el asunto.\p"
  .string "El guardia de la salida te dejará pasar.\n"
  .string "Te deseo suerte.$"

IzabeIsland_MayorHouse_Text_Mayor_TakeYourReward::
	.string "Gracias por ayudar a LAVENDER. Te daría\n"
  .string "algo, pero con la recompensa de\l"
  .string "LAVENDER debería ser suficiente.\p"
  .string "¿Cómo? ¿Que aún así quieres algo?\p"
  .string "Pues oc.$"


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

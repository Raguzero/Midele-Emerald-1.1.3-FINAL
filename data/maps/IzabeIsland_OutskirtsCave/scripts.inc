IzabeIsland_OutskirtsCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IzabeIsland_OutskirtsCave_OnTransition
	.byte 0

IzabeIsland_OutskirtsCave_OnTransition::
	compare VAR_IZABE_ISLAND_STATE, 2
	call_if_eq IzabeIsland_OutskirtsCave_EventScript_HideLavender
	end

IzabeIsland_OutskirtsCave_EventScript_HideLavender::
	removeobject 2
	end

IzabeIsland_OutskirtsCave_EventScript_Titan::
	lockall
	setvar VAR_0x8004, BOSS_BATTLE_CORONA_DEBUG
	special CreateBossBattleMon
	special BattleSetup_StartBossBattle
	waitstate
	setvar VAR_LAST_TALKED, 1
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	call_if_eq LittlerootTown_DebugRoom_Script_CombateGanado
	releaseall
	end

IzabeIsland_OutskirtsCave_EventScript_Lavender::
	lockall
	faceplayer
	msgbox IzabeIsland_OutskirtsCave_Text_Lavender_ExplainSituation, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_IZABE_LAVENDER, IzabeIsland_OutskirtsCave_Text_Lavender_BattleDefeated

	msgbox IzabeIsland_OutskirtsCave_Text_Lavender_TryGiveItem, MSGBOX_DEFAULT
	giveitem ITEM_HM02
	setflag FLAG_RECEIVED_HM02
	setvar VAR_IZABE_ISLAND_STATE, 2
	
	applymovement 2, IzabeIsland_OutskirtsCave_Movement_LavenderSpin
	waitmovement 0
	playse SE_W153
	applymovement 2, IzabeIsland_OutskirtsCave_Movement_LavenderJumpAway
	waitmovement 0
	removeobject 2
	releaseall
	end

IzabeIsland_OutskirtsCave_Movement_LavenderSpin:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

IzabeIsland_OutskirtsCave_Movement_LavenderJumpAway:
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end

IzabeIsland_OutskirtsCave_Text_Lavender_ExplainSituation::
	.string "¿Eh? ¿Quién eres? ¿Que GOOSES te dijo \n"
	.string "que fueras a buscarme porque pensaba\l"
	.string "que me había perdido? En fin...\p"
	.string "Solo había venido aquí a investigar,\n"
	.string "supongo que me entretuve demasiado.\p"
	.string "Por cierto, intuyo habrás visto a ese\n"
	.string "gigante... tengo información sobre él.\p"
	.string "¿Cómo? ¿Que quieres saberla? Bueno, si\n"
	.string "me derrotas te la diré.$"

IzabeIsland_OutskirtsCave_Text_Lavender_BattleDefeated::
	.string "Vaya... buen hax...\n"
	.string "Te odio.$"

IzabeIsland_OutskirtsCave_Text_Lavender_TryGiveItem::
	.string "Esos gigantes han sido creados por\n"
	.string "MICOLO, el científico legendario.\p"
	.string "MICOLO solía vivir en esta ISLA,\n"
	.string "pero un día desapareció.\p"
	.string "Sin embargo, parece que MICOLO ha vuelto\n"
	.string "a la región. Deberías tener cuidado...\p"
	.string "Cambiando de tema, gracias por ayudar a\n"
	.string "GOOSES, te daré algo por las molestias.\p"
	.string "¡Hasta la vista!$"

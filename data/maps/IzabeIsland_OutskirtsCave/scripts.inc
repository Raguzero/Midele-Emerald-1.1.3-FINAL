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
	.string "$"

IzabeIsland_OutskirtsCave_Text_Lavender_BattleDefeated::
	.string "$"

IzabeIsland_OutskirtsCave_Text_Lavender_TryGiveItem::
	.string "$"

IzabeIsland_OutskirtsCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IzabeIsland_OutskirtsCave_OnTransition
	.byte 0

IzabeIsland_OutskirtsCave_OnTransition::
	compare VAR_IZABE_ISLAND_STATE, 2
	call_if_eq IzabeIsland_OutskirtsCave_EventScript_HideLavender
	end

IzabeIsland_OutskirtsCave_EventScript_HideLavender::
	end

IzabeIsland_OutskirtsCave_EventScript_Lavender::
	lockall
	faceplayer
	msgbox IzabeIsland_OutskirtsCave_Text_Lavender_ExplainSituation, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_DEBUG, IzabeIsland_OutskirtsCave_Text_Lavender_BattleDefeated

	@ Here give item
	msgbox IzabeIsland_OutskirtsCave_Text_Lavender_TryGiveItem, MSGBOX_DEFAULT
	giveitem ITEM_LUCKY_EGG
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_RECEIVED_IZABE_ITEM_LAVENDER
	
	setvar VAR_IZABE_ISLAND_STATE, 2
	removeobject 2
	releaseall
	end

IzabeIsland_OutskirtsCave_Text_Lavender_ExplainSituation::
	.string "$"

IzabeIsland_OutskirtsCave_Text_Lavender_BattleDefeated::
	.string "$"

IzabeIsland_OutskirtsCave_Text_Lavender_TryGiveItem::
	.string "$"

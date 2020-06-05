IzabeIsland_House2_MapScripts::
	.byte 0

@ TODO: Añadir objeto y diálogo
IzabeIsland_House2_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_IZABE_ITEM_1, IzabeIsland_House2_EventScript_AlreadyReceivedItem
	msgbox IzabeIsland_House2_Text_GiveItem, MSGBOX_DEFAULT
	giveitem ITEM_LUCKY_EGG
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_RECEIVED_IZABE_ITEM_1
	release 
	end

IzabeIsland_House2_EventScript_AlreadyReceivedItem::
	msgbox IzabeIsland_House2_Text_AlreadyReceivedItem, MSGBOX_DEFAULT
	release
	end

IzabeIsland_House2_Text_GiveItem::
	.string "Take this item!$"

IzabeIsland_House2_Text_AlreadyReceivedItem::
	.string "Did you like the item?$"

LilycoveCity_MoveDeletersHouse_MapScripts:: @ 821EA0A
	.byte 0

LilycoveCity_PinkPetalHouse_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LILYCOVE_ITEM_PINK_PETAL, LilycoveCity_PinkPetalHouse_EventScript_AlreadyReceivedItem
	msgbox LilycoveCity_PinkPetalHouse_Text_GiveItem, MSGBOX_DEFAULT
	giveitem ITEM_PINK_PETAL
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_RECEIVED_LILYCOVE_ITEM_PINK_PETAL
	release 
	end

LilycoveCity_PinkPetalHouse_EventScript_AlreadyReceivedItem::
	msgbox LilycoveCity_PinkPetalHouse_Text_AlreadyReceivedItem, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PinkPetalHouse_Text_GiveItem::
	.string "Do you like FAIRY-type Pokémon?\p"
	
	.string "If so, you will be interested in this.$"

LilycoveCity_PinkPetalHouse_Text_AlreadyReceivedItem::
	.string "That PINK PETAL I gave you, intensifies\n"
	.string "the power of FAIRY-type moves by 20%.$"

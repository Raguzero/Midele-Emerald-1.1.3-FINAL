IzabeIsland_House2_MapScripts::
	.byte 0

IzabeIsland_House2_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, IzabeIsland_House2_EventScript_NotStrong
	goto_if_set FLAG_RECEIVED_IZABE_ITEM_LUCKY_EGG, IzabeIsland_House2_EventScript_AlreadyReceivedItem
	msgbox IzabeIsland_House2_Text_GiveItem, MSGBOX_DEFAULT
	giveitem ITEM_LUCKY_EGG
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_RECEIVED_IZABE_ITEM_LUCKY_EGG
	release 
	end

IzabeIsland_House2_EventScript_AlreadyReceivedItem::
	msgbox IzabeIsland_House2_Text_AlreadyReceivedItem, MSGBOX_DEFAULT
	release
	end

IzabeIsland_House2_EventScript_NotStrong::
	msgbox IzabeIsland_House2_Text_NotStrong, MSGBOX_DEFAULT
	release
	end

IzabeIsland_House2_Text_GiveItem::
	.string "Ver crecer a tus POKéMON es algo muy\n"
	.string "bonito...\p"
	.string "Sin embargo, ¿no hay ocasiones en las\n"
	.string "que te gustaría que tus POKéMON\l"
	.string "creciesen más rápido?\p"
	.string "En ese caso, esto te interesará.$"

IzabeIsland_House2_Text_AlreadyReceivedItem::
	.string "El POKéMON que lleve equipado LUCKY EGG\n"
	.string "ganará mucha más experiencia.$"

IzabeIsland_House2_Text_NotStrong::
	.string "Mmm... Tus POKéMON...\p"
	.string "Todavía no. Vuelve cuando seas más\n"
	.string "fuerte y te regalaré algo.$"

IzabeIsland_Harbor_MapScripts::
	.byte 0

@ TODO: NPC especial, añadir texto
IzabeIsland_Harbor_EventScript_GoBack::
	msgbox IzabeIslandHarbor_Text_AskGoBack, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq IzabeIsland_Harbor_EventScript_Bye

	msgbox IzabeIslandHarbor_Text_GoBack, MSGBOX_DEFAULT
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 22, 11
	waitstate
	end

IzabeIsland_Harbor_EventScript_Bye::
	msgbox IzabeIslandHarbor_Text_Bye, MSGBOX_NPC
	end

IzabeIslandHarbor_Text_AskGoBack::
	.string "Go back?$"
	
IzabeIslandHarbor_Text_Bye::
	.string "Bye$"
	
IzabeIslandHarbor_Text_GoBack::
	.string "Let's go back$"

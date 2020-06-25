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
	.string "¿Quieres volver a SLATEPORT CITY?$"
	
IzabeIslandHarbor_Text_Bye::
	.string "¿Miedo de las olas? He visto micropagos\n"
	.string "más grandes que eso, piratilla.$"
	
IzabeIslandHarbor_Text_GoBack::
	.string "Todos a bordo del TERROR DEL DLC.\n"
	.string "¡Hora de hundir algunos DENUVO!$"

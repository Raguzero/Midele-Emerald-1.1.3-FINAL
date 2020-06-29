SootopolisCity_MysteryEventsHouse_1F_MapScripts:: @ 8227953
	.byte 0

SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer::
	lock
	faceplayer
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_MideleEVReducer_Greeting, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_NoChange
	
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_MideleEVReducer_ChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_NoChange
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_NoEgg
	
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_MideleEVReducer_ChooseStat, MSGBOX_DEFAULT
	multichoicegrid 0, 0, MULTI_MIDELE_EV_STATS, 2, 0
	switch VAR_RESULT
	case 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_HP
	case 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_ATK
	case 2, SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_DEF
	case 3, SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_SPATK
	case 4, SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_SPDEF
	case 5, SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_SPEED
	case 6, SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_NoChange
	case MULTI_B_PRESSED, SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_NoChange
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_HP::
	setvar VAR_0x8005, MON_DATA_HP_EV
	goto SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_Apply
SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_ATK::
	setvar VAR_0x8005, MON_DATA_ATK_EV
	goto SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_Apply
SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_DEF::
	setvar VAR_0x8005, MON_DATA_DEF_EV
	goto SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_Apply
SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_SPATK::
	setvar VAR_0x8005, MON_DATA_SPATK_EV
	goto SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_Apply
SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_SPDEF::
	setvar VAR_0x8005, MON_DATA_SPDEF_EV
	goto SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_Apply
SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_SPEED::
	setvar VAR_0x8005, MON_DATA_SPEED_EV
	goto SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_Apply

SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_Apply::
	special MideleResetSelectedMonEVs
	playfanfare MUS_ME_WASURE
	waitfanfare
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_MideleEVReducer_Done, MSGBOX_DEFAULT
	goto SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_NoChange
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_NoChange::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_MideleEVReducer_NoChange
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_MideleEVReducer_NoEgg::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_MideleEVReducer_NoEgg
	release
	end

SootopolisCity_MysteryEventsHouse_1F_Text_MideleEVReducer_Greeting::
	.string "Los puntos de esfuerzo definen el viaje\n"
	.string "de un entrenador y sus POKéMON.\p"
	.string "Sin embargo, hay veces en las que uno\n"
	.string "prefiere que todo volviese a empezar de\l"
	.string "cero...\p"
	.string "Yo puedo reiniciar los EVs de tus\n"
	.string "POKéMON... ¿te interesa?$"

SootopolisCity_MysteryEventsHouse_1F_Text_MideleEVReducer_ChooseMon::
	.string "Elige un POKéMON.$"

SootopolisCity_MysteryEventsHouse_1F_Text_MideleEVReducer_ChooseStat::
	.string "Elige la estadística cuyos EVs quieres\n"
	.string "que establezca a cero.$"

SootopolisCity_MysteryEventsHouse_1F_Text_MideleEVReducer_Done::
	.string "Los puntos de esfuerzo de tu POKéMON\n"
	.string "han sido reiniciados con éxito, jeje.$"

SootopolisCity_MysteryEventsHouse_1F_Text_MideleEVReducer_NoChange::
	.string "Vuelve cuando quieras.$"

SootopolisCity_MysteryEventsHouse_1F_Text_MideleEVReducer_NoEgg::
	.string "No puedo modificar los puntos de\n"
	.string "esfuerzo de un HUEVO.$"

SootopolisCity_MysteryEventsHouse_B1F_Text_MatchEndedUpDraw: @ 8227D40
	.string "The match ended up a draw.$"

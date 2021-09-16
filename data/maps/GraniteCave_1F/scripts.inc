GraniteCave_1F_MapScripts:: @ 822DA5D
	.byte 0

GraniteCave_1F_EventScript_Hiker:: @ 822DA5E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM05, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM05
	setflag FLAG_RECEIVED_HM05
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash:: @ 822DA8A
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end
	
GraniteCave_EventScript_JZombie::  
	trainerbattle_single TRAINER_GRANITECAVE_JZOMBIE, GraniteCave_Text_JZombieIntro, GraniteCave_Text_JZombieDefeat
	msgbox GraniteCave_Text_JZombiePostBattle, MSGBOX_AUTOCLOSE
	end
	
GraniteCave_EventScript_Addri::  
	trainerbattle_single TRAINER_ADDRI, GraniteCave_Text_AddriIntro, GraniteCave_Text_AddriDefeat
	msgbox GraniteCave_Text_AddriPostBattle, MSGBOX_AUTOCLOSE
	end
	
    @ Combate contra totem.
GraniteCave_1F_EventScript_Totem::
	lockall
	msgbox DesafiarTotem_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GraniteCave_1F_EventScript_Totem2
	releaseall
	end

GraniteCave_1F_EventScript_Totem2::
	playmoncry SPECIES_PROBOPASS, 2
	delay 40
	waitmoncry
	msgbox GraniteCave_1F_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_PROBOPASS
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 4
	setflag FLAG_TOTEM_GRANITECAVE
    msgbox GraniteCave_1F_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.	

GraniteCave_Text_JZombieIntro: 
	.string "¡KALOS SUR es real y existe!\p"

	.string "Está claro que GF nos lo está\n"
	.string "ocultando en el mapa, usando nubes.\p"

	.string "¡Nos toma por idiotas!$"

GraniteCave_Text_JZombieDefeat: 
	.string "Buen polvo...$"

GraniteCave_Text_JZombiePostBattle: 
	.string "Mira, chaval o chavala, me da igual\n"
	.string "lo que tengas entre tus piernas.\p"
	
	.string "¡KALOS SUR existe, y algún día te lo\n"
	.string "demostraré! ¡NADIE SE RIE DE MÍ!\p"
	
	.string "No te voy a permitir que desbarates\n"
	.string "mis teorias ni que las insultes.\p"

	.string "Ya descubriré donde vives, ya...\p"
	
	.string "En cuanto sepa donde vives...\n"
	.string "iré a por ti.\p"
	
	.string "Te vas a llevar tan tremenda paliza\n"
	.string "que haré que tus familiares te visiten\l"
	.string "en tu entierro.\p"
	
	.string "¡TE VAS A CAGAR!$"
	
GraniteCave_Text_AddriIntro: 
	.string "8D 8D 8D 8D 8D\n"
	.string "¡Ya no tengo vigilado n.n!$"

GraniteCave_Text_AddriDefeat: 
	.string "boi a avlar con melcor de todo esto$"

GraniteCave_Text_AddriPostBattle: 
	.string "La MAFIA PxP se ha desintegrado.\n"
	.string "¡Ya no volverán a hacerme chops! n.n$"

GraniteCave_1F_Text_GetsDarkAheadHereYouGo: @ 822DA94
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "STEVEN, I think it was.\p"
	.string "He knew how to use FLASH, so he ought\n"
	.string "to be all right, but…\p"
	.string "Well, for us HIKERS, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Here you go, I'll pass this on to you.$"

GraniteCave_1F_Text_ExplainFlash: @ 822DBB7
	.string "Teach that hidden move FLASH to\n"
	.string "a POKéMON and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from DEWFORD's POKéMON GYM.$"
	
GraniteCave_1F_Text_Totemaparece:
	.string "PROBOPASS, the TOTEM POKéMON of\n"
	.string "GRANITE CAVE has appeared!$"
	
GraniteCave_1F_Text_Totemderrotado:
	.string "PROBOPASS disappeared...$"
	
DesafiarTotem_Text:
	.string "Una extraña estatua bloquea el paso, si\n"
	.string "la tocas, se convertirá en un POKéMON\l"
	.string "muy poderoso que se adecuará al máximo\l"
	.string "nivel de tu equipo.\p"
	.string "¿Todo listo para este desafío?$"

MicoloHideout_ExperimentRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MicoloHideout_ExperimentRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MicoloHideout_ExperimentRoom_OnTransition
	.byte 0
	
MicoloHideout_ExperimentRoom_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MicoloHideout_ExperimentRoom_EventScript_TryRemoveMewtwo
	end

MicoloHideout_ExperimentRoom_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

MicoloHideout_ExperimentRoom_OnTransition:
	call_if_unset FLAG_CAUGHT_MEWTWO, MicoloHideout_ExperimentRoom_EventScript_TryShowMewtwo
	end

MicoloHideout_ExperimentRoom_EventScript_TryShowMewtwo::
	goto_if_set FLAG_DEFEATED_MEWTWO, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MEWTWO
	return
	
MicoloHideout_ExperimentRoom_EventScript_Mewtwo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEWTWO, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_MEWTWO, 70, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartLegendDogsBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_DefeatedMewtwo
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_RanFromMewtwo
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_RanFromMewtwo
	setflag FLAG_CAUGHT_MEWTWO
	release
	end

MicoloHideout_ExperimentRoom_EventScript_DefeatedMewtwo::
	setflag FLAG_DEFEATED_MEWTWO
	goto Common_EventScript_RemoveStaticPokemon
	end

MicoloHideout_ExperimentRoom_EventScript_RanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	end

MicoloHideout_ExperimentRoom_EventScript_LegendaryMachine::
	lock
	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineUse, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineEnd
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineNoRoom

	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineEnd
	
	special IsSelectedMonLegendary
	compare VAR_RESULT, FALSE
	goto_if_eq MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineNotLegendary
	playse SE_TK_WARPIN
	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineReceivedMon, MSGBOX_DEFAULT
	waitse
	giveEgg VAR_0x8005
MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineEnd:
	release
	end

MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineNoRoom:
	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineNoRoom, MSGBOX_DEFAULT
	release
	end

MicoloHideout_ExperimentRoom_EventScript_LegendaryMachineNotLegendary:
	msgbox MicoloHideout_ExperimentRoom_Text_LegendaryMachineNotLegendary, MSGBOX_DEFAULT
	release
	end
	
MicoloHideout_ExperimentRoom_EventScript_Javisoto2::  
	trainerbattle_single TRAINER_JAVISITO_POSTGAME, MicoloHideout_ExperimentRoom_Text_Javisoto2Intro, MicoloHideout_ExperimentRoom_Text_Javisoto2Defeat
	msgbox MicoloHideout_ExperimentRoom_Text_Javisoto2PostBattle, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_ExperimentRoom_EventScript_Uta::  
	trainerbattle_single TRAINER_UTALAWEA, MicoloHideout_ExperimentRoom_Text_UtaIntro, MicoloHideout_ExperimentRoom_Text_UtaDefeat
	msgbox MicoloHideout_ExperimentRoom_Text_UtaPostBattle, MSGBOX_AUTOCLOSE
	end

MicoloHideout_ExperimentRoom_Text_Javisoto2Intro: 
	.string "Buenas, ¿cuando haran el evento de\n" 
	.string "la Flauta Azur y del Floette Eterno?\p" 
	
	.string "Aun estoy esperando estos eventos.$"

MicoloHideout_ExperimentRoom_Text_Javisoto2Defeat: 
	.string "Y algo me dice que aun tengo que\n" 
	.string "esperar mas.$"

MicoloHideout_ExperimentRoom_Text_Javisoto2PostBattle: 
	.string "Supongo que no puedo esperar mucho\n" 
	.string "de aquellos que arruinaron Pokemon\l" 
	.string "y monetizaron los shinys, y todos\l"
	.string "sabemos que tambien arruinaran Sinnoh.$"
	
MicoloHideout_ExperimentRoom_Text_UtaIntro: 
	.string "No deberías molestarte en combatir.\n"
	.string "Ya sé como acabará.$"

MicoloHideout_ExperimentRoom_Text_UtaDefeat: 
	.string "Me cago en tu puta madre.$"

MicoloHideout_ExperimentRoom_Text_UtaPostBattle: 
	.string "El resultado fue el que esperaba.\n"
	.string "Lo planeé desde el principio.$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineUse:
	.string "Hay un programa abierto en el PC.\p"
	.string "“Programa de crianza de legendarios\n"
	.string "100% legal n.n”\p"
	.string "¿Lo utilizas?$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineChooseMon:
	.string "Elige un POKéMON legendario.$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineReceivedMon:
	.string "¡Has obtenido un HUEVO de legendario!$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineNoRoom:
	.string "No tienes espacio en el equipo.$"

MicoloHideout_ExperimentRoom_Text_LegendaryMachineNotLegendary:
	.string "El POKéMON que has elegido no es un\n"
	.string "POKéMON legendario.$"

MicoloHideout_ExperimentRoom_Experiment1::
	msgbox MicoloHideout_ExperimentRoom_Experiment1_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Experiment2::
	msgbox MicoloHideout_ExperimentRoom_Experiment2_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Experiment3::
	msgbox MicoloHideout_ExperimentRoom_Experiment3_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Experiment4::
	msgbox MicoloHideout_ExperimentRoom_Experiment4_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Experiment5::
	msgbox MicoloHideout_ExperimentRoom_Experiment5_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Experiment6::
	msgbox MicoloHideout_ExperimentRoom_Experiment6_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Experiment7::
	msgbox MicoloHideout_ExperimentRoom_Experiment7_Text_0, MSGBOX_SIGN
	return


MicoloHideout_ExperimentRoom_Scientist1::
	msgbox MicoloHideout_ExperimentRoom_Scientist1_Text_0, MSGBOX_NPC
	return


MicoloHideout_ExperimentRoom_Scientist2::
	msgbox MicoloHideout_ExperimentRoom_Scientist2_Text_0, MSGBOX_NPC
	return


MicoloHideout_ExperimentRoom_Scientist3::
	msgbox MicoloHideout_ExperimentRoom_Scientist3_Text_0, MSGBOX_NPC
	return


MicoloHideout_ExperimentRoom_Experiment1_Text_0:
	.string "EXPERIMENTO FALLIDO N1$"

MicoloHideout_ExperimentRoom_Experiment2_Text_0:
	.string "EXPERIMENTO FALLIDO N2$"

MicoloHideout_ExperimentRoom_Experiment3_Text_0:
	.string "EXPERIMENTO FALLIDO N3$"

MicoloHideout_ExperimentRoom_Experiment4_Text_0:
	.string "CLON N1: GROUDON$"

MicoloHideout_ExperimentRoom_Experiment5_Text_0:
	.string "CLON N2: KYOGRE$"

MicoloHideout_ExperimentRoom_Experiment6_Text_0:
	.string "CLON N3: RAYQUAZA$"

MicoloHideout_ExperimentRoom_Experiment7_Text_0:
	.string "CLON DE MEW N12$"

MicoloHideout_ExperimentRoom_Scientist1_Text_0:
	.string "¿Q-quién eres? ¿Cómo has llegado hasta\n"
	.string "aquí?\p"
	.string "N-no me hagas nada, yo solo sigo las\n"
	.string "órdenes de MICOLO...\p"
	.string "Mira, hagamos un trato. Si me dejas en\n"
	.string "paz, te dejaré utilizar ese PC de ahí.\p"
	.string "Es la última creación de MICOLO, con él\n"
	.string "podrás criar POKéMON legendarios...$"

MicoloHideout_ExperimentRoom_Scientist2_Text_0:
	.string "¿Que qué hay en esa sala de ahí? Es\n"
	.string "donde hemos almacenado a todos los\l"
	.string "clones de MEW y MEWTWO fallidos.\p"
	.string "Quizás quede alguno vivo, pero ya no\n"
	.string "nos sirven de nada, haz lo que quieras\l"
	.string "con ellos.$"

MicoloHideout_ExperimentRoom_Scientist3_Text_0:
	.string "No sé quién eres, pero no te\n"
	.string "recomendaría continuar por la sala de\l"
	.string "la derecha.\p"
	.string "En esa sala se encuentra el POKéMON que\n"
	.string "A.VADER trajo de su viaje a la RUTA\l"
	.string "110... REGIELEKI, creo que se llamaba.\l"
	.string "Es extremadamente peligroso, apenas\l"
	.string "hemos podido contenerlo.\p"
    .string "Dicen que A.VADER se lo quitó en la cara\n"
	.string "a un entrenador muy PALLASO.$"
	

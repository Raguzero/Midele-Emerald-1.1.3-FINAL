GymSanty2_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, GymSanty2_OnResume
	map_script MAP_SCRIPT_ON_LOAD, GymSanty2_OnLoad
    .byte 0
	
GymSanty2_OnLoad:
	compare VAR_FUEGO_GYM_SANTY, 0
	goto_if_eq GymSanty2_Script_Close
	compare VAR_FUEGO_GYM_SANTY, 1
	goto_if_eq GymSanty2_Script_Close
	compare VAR_FUEGO_GYM_SANTY, 2
	goto_if_eq GymSanty2_Script_Close
	compare VAR_FUEGO_GYM_SANTY, 3
	goto_if_eq GymSanty2_Script_Close
	end

GymSanty2_OnResume:
    setstepcallback STEP_CB_ASH
    end
	
GymSanty2_Script_Close::
	setmetatile 28, 11, 0x04E, 1
	return

GymSanty2_EventScript_Sign::
	msgbox GymSanty2_Text_Sign, MSGBOX_SIGN
	end
	
GymSanty2_EventScript_Farol1::
	lock
	faceplayer
	goto_if_set FLAG_FAROL1_GYM_SANTY, GymSanty2_EventScript_FarolEncendida2
	msgbox GymSanty2_Text_EncenderFarol, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymSanty2_EventScript_FarolEncendida
	release
	end
GymSanty2_EventScript_FarolEncendida:
	msgbox GymSanty2_Text_FarolEncendida, MSGBOX_DEFAULT
	addvar VAR_FUEGO_GYM_SANTY, 1
	setflag FLAG_FAROL1_GYM_SANTY
	compare VAR_FUEGO_GYM_SANTY, 4
	goto_if_eq GymSanty2_EventScript_FarolesEncendidos
	release
	end
	
GymSanty2_EventScript_Farol2::
	lock
	faceplayer
	goto_if_set FLAG_FAROL2_GYM_SANTY, GymSanty2_EventScript_FarolEncendida2
	msgbox GymSanty2_Text_EncenderFarol, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymSanty2_EventScript_Farol2Encendida
	release
	end
GymSanty2_EventScript_Farol2Encendida:
	msgbox GymSanty2_Text_FarolEncendida, MSGBOX_DEFAULT
	addvar VAR_FUEGO_GYM_SANTY, 1
	setflag FLAG_FAROL2_GYM_SANTY
	compare VAR_FUEGO_GYM_SANTY, 4
	goto_if_eq GymSanty2_EventScript_FarolesEncendidos
	release
	end
	
GymSanty2_EventScript_Farol3::
	lock
	faceplayer
	goto_if_set FLAG_FAROL3_GYM_SANTY, GymSanty2_EventScript_FarolEncendida2
	msgbox GymSanty2_Text_EncenderFarol, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymSanty2_EventScript_Farol3Encendida
	release
	end
GymSanty2_EventScript_Farol3Encendida:
	msgbox GymSanty2_Text_FarolEncendida, MSGBOX_DEFAULT
	addvar VAR_FUEGO_GYM_SANTY, 1
	setflag FLAG_FAROL3_GYM_SANTY
	compare VAR_FUEGO_GYM_SANTY, 4
	goto_if_eq GymSanty2_EventScript_FarolesEncendidos
	release
	end
	
GymSanty2_EventScript_Farol4::
	lock
	faceplayer
	goto_if_set FLAG_FAROL4_GYM_SANTY, GymSanty2_EventScript_FarolEncendida2
	msgbox GymSanty2_Text_EncenderFarol, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymSanty2_EventScript_Farol4Encendida
	release
	end
GymSanty2_EventScript_Farol4Encendida:
	msgbox GymSanty2_Text_FarolEncendida, MSGBOX_DEFAULT
	addvar VAR_FUEGO_GYM_SANTY, 1
	setflag FLAG_FAROL4_GYM_SANTY
	compare VAR_FUEGO_GYM_SANTY, 4
	goto_if_eq GymSanty2_EventScript_FarolesEncendidos
	release
	end

GymSanty2_EventScript_FarolEncendida2:
	msgbox GymSanty2_Text_FarolEncendida2, MSGBOX_DEFAULT
	release
	end

GymSanty2_EventScript_FarolesEncendidos::
	setmetatile 28, 11, METATILE_General_Grass, 0
	special DrawWholeMapView
	msgbox GymSanty2_Text_CaminoAbierto, MSGBOX_SIGN
	releaseall
	end
	
    @ Combate contra totem.
GymSanty2_EventScript_Totem::
	lockall
	playmoncry SPECIES_TYPHLOSION, 2
	delay 40
	waitmoncry
	msgbox GymSanty2_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_TYPHLOSION
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 1
	setflag FLAG_TOTEM_GYMSANTY
    msgbox GymSanty2_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.	
	
GymSanty2_EventScript_Entropia::
	trainerbattle_single TRAINER_ENTROPIA, Entropia_AntesBatalla, Entropia_MensajeDerrota
	msgbox Entropia_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
GymSanty2_EventScript_RedKrow::
	trainerbattle_single TRAINER_RED_KROW, RedKrow_AntesBatalla, RedKrow_MensajeDerrota
	msgbox RedKrow_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
Entropia_AntesBatalla: 
	.string "Amore, ¿sabías que estamos en la\n"
    .string "piscis season?\p"

    .string "El amor está en el aire, las feromon...\p"

    .string "¿Cómo? ¿No crees en el horóscopo?\p"

    .string "¡No puedes decirme eso y quedarte\n"
    .string "tan tranquilo!\p"

    .string "Eso va a cambiar cuando te pateé el culo\n"
	.string "Hm.$"
	
Entropia_MensajeDerrota: 
	.string "Paso.$"
	
Entropia_DespuesDeBatalla:
	.string "¿Es así como te han enseñado\n"
	.string "a tratar a las brujas?\p"

	.string "Anyways, so... Si hay algo que te\n"
	.string "inquieta, te atormenta o te\l"
	.string "perturba, siempre puedes volver\l"
	.string "aquí y te diré lo que los astro te\l"
	.string "deparan...\p"

	.string "O puede hablar con un tal Alpha\n"
	.string "que seguramente esté por algún\l"
	.string "lugar de aquí fagoteando.\l"
	.string "¡Besis de fresi!$"
	
RedKrow_AntesBatalla: 
    .string "No hace falta que digas nada,\n"
    .string "solo con verte ya estoy entrando\l"
    .string "en calor.\p"
	
	.string "Federico, prepárate que vamos\n" 
	.string "a erupcionar.$"
	
RedKrow_MensajeDerrota: 
    .string "¡Por favor, no me pegues!\n"
    .string "...\l"
    .string "...\p"
    .string "O bueno, si quieres pégame.\n"
    .string "...\l"
    .string "...\p"
    .string "¿No? Oh.\n"
    .string "¿Y si te pagara me pegarías?$"
	
RedKrow_DespuesDeBatalla:
    .string "Si quieres que repitamos, creéme, por mí\n"
    .string "encantado, pero deja por lo menos que\l"
    .string "vaya a limpiarme la cara primero.$"

GymSanty2_Text_Sign:
	.string "ENCIENDE LOS CUATRO FAROLES\n"
	.string "Y EL CAMINO SE ABRIRÁ$"
	
GymSanty2_Text_EncenderFarol:
	.string "¿Quieres encender el farol?$"
	
GymSanty2_Text_FarolEncendida:
	.string "Has encendido el farol.$"
	
GymSanty2_Text_FarolEncendida2:
	.string "El fuego arde en el farol.$"

GymSanty2_Text_CaminoAbierto:
	.string "Han sido encendidos los 4 faroles.\p"

	.string "El camino hacia la siguiente sala\n"
	.string "ha sido desbloqueado.$"
	
GymSanty2_Text_Totemaparece:
	.string "TYPHLOSION, the Totem Pokémon\n"
	.string "has appeared!$"
	
GymSanty2_Text_Totemderrotado:
	.string "TYPHLOSION disappeared...$"

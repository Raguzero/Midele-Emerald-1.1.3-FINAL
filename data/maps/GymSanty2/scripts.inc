GymSanty2_MapScripts::
    map_script MAP_SCRIPT_ON_RESUME, GymSanty2_OnResume
    .byte 0

GymSanty2_OnResume:
    setstepcallback STEP_CB_ASH
    end
	
    @ Combate contra totem.
GymSanty2_EventScript_Totem::
	lockall
	playmoncry SPECIES_INFERNAPE, 2
	delay 40
	waitmoncry
	msgbox Fiery_Path_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_CENTISKORCH
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 9
	setflag FLAG_TOTEM_GYMSANTY
    msgbox Fiery_Path_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.	
	
GymSanty2_EventScript_Entropia::
	trainerbattle_single TRAINER_ENTROPIA, Entropia_AntesBatalla, Entropia_MensajeDerrota
	msgbox Entropia_DespuesDeBatalla, MSGBOX_AUTOCLOSE
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

GymSanty2_EventScript_Sign::
	msgbox GymSanty2_Text_Sign, MSGBOX_SIGN
	end
	
GymSanty2_Text_Sign:
	.string "ENCIENDE LAS CUATRO ANTORCHAS\n"
	.string "Y EL CAMINO SE ABRIRÁ$"

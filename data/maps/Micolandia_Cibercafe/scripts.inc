Micolandia_Cibercafe_MapScripts::
	.byte 0

Cibercafe_PCBatalla::
	msgbox PC_Batalla, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PC_NoBatalla
	msgbox PC_ChooseEnemy, MSGBOX_DEFAULT
	multichoicegrid 0, 0, MULTI_CIBERCAFE_BATALLA, 3, 0
	switch VAR_RESULT
	case 0, PC_BatalllaBROCK
	case 1, PC_BatalllaMISTY
	case 2, PC_BatalllaLTSURGE
	case 3, PC_BatalllaERIKA
	case 4, PC_BatalllaSABRINA
	case 5, PC_BatalllaKOGA
	case 6, PC_BatalllaBLAINE
	case 7, PC_BatalllaGIOVANNI
	case 8, PC_BatalllaLORELEI
	case 9, PC_BatalllaBRUNO
	case 10, PC_BatalllaAGATHA
	case 11, PC_BatalllaLANCE
	case 12, PC_BatalllaBLUE
	case 13, PC_BatalllaRED
	case 14, PC_BatalllaLEAF
	case 15, PC_NoBatalla
	case MULTI_B_PRESSED, PC_NoBatalla
	end
	
PC_BatalllaBROCK::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_BROCK
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaMISTY::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_MISTY
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaLTSURGE::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_LTSURGE
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaERIKA::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_ERIKA
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaSABRINA::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_SABRINA
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaKOGA::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_KOGA
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaBLAINE::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_BLAINE
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaGIOVANNI::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_GIOVANNI
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaLORELEI::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_LORELEI
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaBRUNO::
	special HealPlayerParty
		setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_BRUNO
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaAGATHA::
	special HealPlayerParty
    setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_AGATHA
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaLANCE::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_LANCE
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaBLUE::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_BLUE
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaRED::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_RED2
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_BatalllaLEAF::
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_LEAF2
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
	
PC_NoBatalla::
	msgbox PC_NoBatalla_Text
	release
	end
	
PC_Roto::
	msgbox PC_Roto_Text
	release
	end

PC_BatallaFinWIN::
    special HealPlayerParty
    msgbox PC_Enhorabuena
    special PCBatallaGivePrize
    compare VAR_RESULT, 0
    goto_if_eq PC_BatallaFin_FinRandomPrize
    giveitem VAR_RESULT
    compare VAR_RESULT, FALSE
    call_if_eq PC_Batalla_Script_RandomPrize1_BagFull
    closemessage
PC_BatallaFin_FinRandomPrize::
    release
    end

PC_Batalla_Script_RandomPrize1_BagFull::
    call Common_EventScript_BagIsFull
    msgbox Script_RandomPrize1_Text_NoRoomForThis, MSGBOX_DEFAULT
    return
	
PC_BatallaFinLOSS::
	special HealPlayerParty
	msgbox PC_Perder
	closemessage
	release
	end
	
PC_BatallaFinDRAW::
	special HealPlayerParty
	msgbox PC_Perder
	closemessage
	release
	end
	
Micolandia_Cibercafe_Dueno_Script::
	msgbox Micolandia_Cibercafe_Dueno_Text, MSGBOX_NPC
	end
	
Micolandia_Cibercafe_NPC1::
	msgbox Micolandia_Cibercafe_NPC1_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_NPC2::
	msgbox Micolandia_Cibercafe_NPC2_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_NPC3::
	msgbox Micolandia_Cibercafe_NPC3_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_NPC4::
	msgbox Micolandia_Cibercafe_NPC4_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_NPC5y7::
	msgbox Micolandia_Cibercafe_NPC5y7_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_NPC6::
	msgbox Micolandia_Cibercafe_NPC6_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_Dueno_Text:
	.string "¡Te doy la bienvenida al\n" 
	.string "CIBERCAFE BATALLA!\p"
	
	.string "Elige un PC para combatir con\n"
	.string "simulaciones de entrenadores de\l" 
	.string "otras regiones. Estos entrenadores\l"
	.string "se adecuarán al nivel máximo de tu\l"
	.string "equipo, así que tenlo en cuenta.\p"
	
	.string "Puedes ganar dinero, experiencia y\n"
	.string "premios si vences en estas batallas.\p"
	
	.string "¡Buena suerte!$"
	
PC_Enhorabuena:
	.string "Ganaste, te llevas este premio.$"

PC_Perder:
	.string "No siempre se gana.\n"
	.string "Vuelve cuando quieras.$"

PC_Batalla:
	.string "Bienvenido al servidor.\n"
	.string "¿Quieres realizar una batalla?$"
	
PC_NoBatalla_Text:
	.string "Vuelve cuando quieras.$"
	
PC_Roto_Text:
	.string "Parece que no funciona.$"
	
PC_ChooseEnemy:
	.string "Elige un contrincante.$"
	
Micolandia_Cibercafe_NPC1_Text:
	.string "¡Qué dificil es este simulador!$"
	
Micolandia_Cibercafe_NPC2_Text:
	.string "¡Esto me servirá como entrenamiento\n"
	.string "para afrontar el desafío de la MICOLIGA!$"
	
Micolandia_Cibercafe_NPC3_Text:
	.string "¡Genial! ¡Vencí a RED y conseguí un\n"
	.string "LUCKY EGG!$"
	
Micolandia_Cibercafe_NPC4_Text:
	.string "¡Noooooo! ¡LANCE es demasiado fuerte!$"
	
Micolandia_Cibercafe_NPC5y7_Text:
	.string "...$"
	
Micolandia_Cibercafe_NPC6_Text:
	.string "¡Que vicio esto! ¡Estoy consiguiendo\n"
	.string "muchos objetos útiles!$"

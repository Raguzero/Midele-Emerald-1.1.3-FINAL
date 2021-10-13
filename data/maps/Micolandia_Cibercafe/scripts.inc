Micolandia_Cibercafe_MapScripts::
	.byte 0

Cibercafe_PCBatalla::
	msgbox PC_Batalla, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PC_NoBatalla
	multichoicegrid 0, 0, MULTI_LISTAS_CIBERCAFE, 2, 0
	switch VAR_RESULT
	case 0, PC_LISTA1
	case 1, PC_LISTA2
	case 2, PC_NoBatalla
	case MULTI_B_PRESSED, PC_NoBatalla
	end

PC_LISTA1::
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
	case 8, PC_NoBatalla
	case MULTI_B_PRESSED, PC_NoBatalla
	end

PC_LISTA2::
	msgbox PC_ChooseEnemy, MSGBOX_DEFAULT
	multichoicegrid 0, 0, MULTI_CIBERCAFE_BATALLA_2, 3, 0
	switch VAR_RESULT
	case 0, PC_BatalllaLORELEI
	case 1, PC_BatalllaBRUNO
	case 2, PC_BatalllaAGATHA
	case 3, PC_BatalllaLANCE
	case 4, PC_BatalllaBLUE
	case 5, PC_BatalllaRED
	case 6, PC_BatalllaLEAF
	case 7, PC_BatalllaCHERYL
	case 8, PC_NoBatalla
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
	
PC_BatalllaCHERYL::
	msgbox PC_BatallaMODO_Text, MSGBOX_DEFAULT
	closemessage
PC_BatalllaCHERYL_CONTINUE::
	msgbox PC_BatallaMODO_Text2, MSGBOX_DEFAULT
	multichoicegrid 0, 0, MULTI_CIBERCAFE_BATALLA_MODOS_ESPECIALES, 3, 0
	switch VAR_RESULT
	case 0, PC_BatalllaModoNormal
	case 1, PC_BatalllaModoFarmeo
	case 2, PC_NoBatalla
	case MULTI_B_PRESSED, PC_NoBatalla
	end
PC_BatalllaModoNormal::
	msgbox PC_BatallaConfirmarModoNormal, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PC_BatalllaCHERYL_CONTINUE
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_CHERYL
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinLOSS
	end
PC_BatalllaModoFarmeo::
	msgbox PC_BatallaConfirmarModoFarmeo, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PC_BatalllaCHERYL_CONTINUE
	special HealPlayerParty
	setvar VAR_0x8004, SPECIAL_CIBERCAFE
    setvar VAR_0x8005, 0
	setvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_CHERYL_2
    special DoSpecialTrainerBattle
    waitstate
	compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq PC_BatallaFinFarmeo
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq PC_BatallaFinFarmeo
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq PC_BatallaFinFarmeo
	end
	
PC_NoBatalla::
	msgbox PC_NoBatalla_Text
	release
	end
	
PC_Roto::
	msgbox PC_Roto_Text
	release
	end
	
PC_BatallaFinFarmeo::
    special HealPlayerParty
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
	
Micolandia_Cibercafe_NPC5::
	msgbox Micolandia_Cibercafe_NPC5_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_NPC6::
	msgbox Micolandia_Cibercafe_NPC6_Text, MSGBOX_SIGN
	end
	
Micolandia_Cibercafe_NPC7::
	msgbox Micolandia_Cibercafe_NPC7_Text, MSGBOX_SIGN
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
	
Micolandia_Cibercafe_NPC5_Text:
	.string "¡El Modo Farmeo de CHERYL es GENIAL!\n"
	.string "¡Con solo equiparles a mis POKéMON Nv1\l"
	.string "con un LUCKY EGG puedo hacer que suban\l"
	.string "de nivel a una velocidad asombrosa!\p"
	
	.string "Ojalá tuviese un POKéMON intercambiado.\n"
	.string "Se dice que estos POKéMON suben de\l"
	.string "nivel mucho más rápido.\p"
	.string "¿Cuanta Experiencia podrían conseguir?\n"
	.string "¿¿¿¿60000???? ¡¡MENUDA LOCURA!!$"

Micolandia_Cibercafe_NPC7_Text:
	.string "...$"
	
Micolandia_Cibercafe_NPC6_Text:
	.string "¡Qué vicio esto! ¡Estoy consiguiendo\n"
	.string "muchos objetos útiles!$"
	
PC_BatallaMODO_Text:
	.string "Esta entrenadora es especial. Puedes\n"
	.string "elegir entre Modo Normal y Modo Farmeo.\p"
	
	.string "El Modo Normal no tiene ninguna\n"
	.string "particularidad, mientras que el Modo\l"
	.string "Farmeo es la mejor forma de entrenar\l"
	.string "a POKéMON con niveles muy bajos.$"
	
PC_BatallaMODO_Text2:
	.string "¿Cuál modo de batalla eliges?$"
	
PC_BatallaConfirmarModoNormal:
	.string "¿Eliges el Modo Normal?$"

PC_BatallaConfirmarModoFarmeo:
	.string "¿Eliges el Modo Farmeo?$"

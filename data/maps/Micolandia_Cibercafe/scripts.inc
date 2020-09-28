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
	case 8, PC_BatalllaBROCK
	case 9, PC_BatalllaBROCK
	case 10, PC_BatalllaBROCK
	case 11, PC_BatalllaBROCK
	case 12, PC_BatalllaBROCK
	case 13, PC_BatalllaBROCK
	case 14, PC_BatalllaBROCK
	case 15, PC_BatalllaBROCK
	case 16, PC_BatalllaBROCK
	case 17, PC_NoBatalla
	case MULTI_B_PRESSED, PC_NoBatalla
	end
	
PC_BatalllaBROCK::
	trainerbattle_no_intro TRAINER_BROCK, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_BatalllaMISTY::
	trainerbattle_no_intro TRAINER_MISTY, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_BatalllaLTSURGE::
	trainerbattle_no_intro TRAINER_LTSURGE, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_BatalllaERIKA::
	trainerbattle_no_intro TRAINER_ERIKA, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_BatalllaSABRINA::
	trainerbattle_no_intro TRAINER_SABRINA, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_BatalllaKOGA::
	trainerbattle_no_intro TRAINER_KOGA, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_BatalllaBLAINE::
	trainerbattle_no_intro TRAINER_BLAINE, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_BatalllaGIOVANNI::
	trainerbattle_no_intro TRAINER_GIOVANNI, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_NoBatalla::
	msgbox PC_NoBatalla_Text
	release
	end

PC_Batalla:
	.string "Bienvenido al servidor\n"
	.string "¿Quieres realizar una batalla?$"
	
PC_NoBatalla_Text:
	.string "Vuelve cuando quieras.$"
	
PC_ChooseEnemy:
	.string "Elige un contrincante.$"


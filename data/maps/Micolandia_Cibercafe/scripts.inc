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
	
PC_BatalllaLORELEI::
	trainerbattle_no_intro TRAINER_LORELEI, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_BatalllaBRUNO::
	trainerbattle_no_intro TRAINER_BRUNO, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_BatalllaAGATHA::
	trainerbattle_no_intro TRAINER_AGATHA, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_BatalllaLANCE::
	trainerbattle_no_intro TRAINER_LANCE, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_BatalllaBLUE::
	trainerbattle_no_intro TRAINER_BLUE, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_BatalllaRED::
	trainerbattle_no_intro TRAINER_RED2, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_BatalllaLEAF::
	trainerbattle_no_intro TRAINER_LEAF2, SlateportCity_Harbor_Text_IzabeSailorDefeated
	end
	
PC_NoBatalla::
	msgbox PC_NoBatalla_Text
	release
	end
	
PC_Roto::
	msgbox PC_Roto_Text
	release
	end

PC_Batalla:
	.string "Bienvenido al servidor\n"
	.string "¿Quieres realizar una batalla?$"
	
PC_NoBatalla_Text:
	.string "Vuelve cuando quieras.$"
	
PC_Roto_Text:
	.string "Parece que no funciona.$"
	
PC_ChooseEnemy:
	.string "Elige un contrincante.$"


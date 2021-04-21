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
	
GymSanty2_EventScript_Sign::
	msgbox GymSanty2_Text_Sign, MSGBOX_SIGN
	end
	
GymSanty2_Text_Sign:
	.string "ENCIENDE LAS CUATRO ANTORCHAS\n"
	.string "Y EL CAMINO SE ABRIRÁ$"

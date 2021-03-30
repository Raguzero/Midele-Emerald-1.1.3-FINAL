GymSanty2_MapScripts::
	.byte 0
	
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
	setflag FLAG_TOTEM_FIERYPATH
    msgbox Fiery_Path_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.	

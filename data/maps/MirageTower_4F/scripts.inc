MirageTower_4F_MapScripts:: @ 823AD47
	.byte 0

MirageTower_4F_EventScript_RootFossil:: @ 823AD48
	lock
	faceplayer
	giveitem ITEM_ROOT_FOSSIL
	compare VAR_RESULT, FALSE
	call_if_eq MirageTower_4F_EventScript_BagFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject 1
	delay 30
	end

MirageTower_4F_EventScript_ClawFossil:: @ 823AD89
	lock
	faceplayer
	giveitem ITEM_CLAW_FOSSIL
	compare VAR_RESULT, FALSE
	call_if_eq MirageTower_4F_EventScript_BagFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	removeobject 2
	delay 30
	end
	
MirageTower_4F_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	closemessage
	end

    @ Combate contra totem.
MirageTower_4F_EventScript_Totem::
	lockall
	msgbox DesafiarTotem_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MirageTower_4F_EventScript_Totem2
	releaseall
	end	

MirageTower_4F_EventScript_Totem2::	
	playmoncry SPECIES_COFAGRIGUS, 2
	delay 40
	waitmoncry
	msgbox MirageTower_4F_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_COFAGRIGUS
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 4
	setflag FLAG_TOTEM_MIRAGETOWER
    msgbox MirageTower_4F_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.	
	
MirageTower_4F_Text_Totemaparece:
	.string "COFAGRIGUS, the TOTEM POKéMON of\n" 
	.string "MIRAGE TOWER, has appeared!$"
	
MirageTower_4F_Text_Totemderrotado:
	.string "COFAGRIGUS disappeared...$"



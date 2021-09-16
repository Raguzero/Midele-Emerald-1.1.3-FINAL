MtPyre_6F_MapScripts:: @ 8231D3A
	.byte 0

MtPyre_6F_EventScript_Valerie:: @ 8231D3B
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie:: @ 8231D67
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie:: @ 8231D86
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric:: @ 8231D9D
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end
	
    @ Combate contra totem.
MtPyre_6F_EventScript_Totem::
	lockall
	msgbox DesafiarTotem_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MtPyre_6F_EventScript_Totem2
	releaseall
	end		

MtPyre_6F_EventScript_Totem2::	
	playmoncry SPECIES_MEGA_ABSOL, 2
	delay 40
	waitmoncry
	msgbox MtPyre_6F_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_MEGA_ABSOL
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 4
	setflag FLAG_TOTEM_MTPYRE
    msgbox MtPyre_6F_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.	

MtPyre_6F_Text_ValerieIntro: @ 8231DB4
	.string "When I'm here…\n"
	.string "A curious power flows into me…$"

MtPyre_6F_Text_ValerieDefeat: @ 8231DE2
	.string "The power is ebbing away…$"

MtPyre_6F_Text_ValeriePostBattle: @ 8231DFC
	.string "Perhaps the power is from the spirits\n"
	.string "of POKéMON in fitful sleep here…$"

MtPyre_6F_Text_ValerieRegister: @ 8231E43
	.string "Fufufu… I lost the match, but…\n"
	.string "I have this little ability…\p"
	.string "Without ever laying my hands on\n"
	.string "your POKéNAV… Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro: @ 8231EB3
	.string "Behind you…\n"
	.string "What is it…$"

MtPyre_6F_Text_ValerieRematchDefeat: @ 8231ECB
	.string "Something faded away…$"

MtPyre_6F_Text_ValeriePostRematch: @ 8231EE1
	.string "The POKéMON at rest here…\n"
	.string "Sometimes, they play…$"

MtPyre_6F_Text_CedricIntro: @ 8231F11
	.string "Have you lost your bearings?\n"
	.string "Have no fear for I am here!$"

MtPyre_6F_Text_CedricDefeat: @ 8231F4A
	.string "Weren't you lost?$"

MtPyre_6F_Text_CedricPostBattle: @ 8231F5C
	.string "I had this feeling that a lost TRAINER\n"
	.string "would be panicked and easy to beat.\p"
	.string "It's dirty and I won't try it again…$"
	
MtPyre_6F_Text_Totemaparece:
	.string "M-ABSOL, the TOTEM POKéMON of\n"
	.string "MT PYRE, has appeared!$"
	
MtPyre_6F_Text_Totemderrotado:
	.string "M-ABSOL disappeared...$"

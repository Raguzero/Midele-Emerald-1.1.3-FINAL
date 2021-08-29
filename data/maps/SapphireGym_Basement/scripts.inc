SapphireGym_Basement_MapScripts::
	.byte 0

SapphireGym_Basement_EventScript_Titan::
	lockall
	msgbox TitanIntro_Text, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SapphireGym_Basement_EventScript_TitanNoFight
	msgbox TitanIntro_Text_DeAcuerdo, MSGBOX_DEFAULT
	setvar VAR_0x8004, BOSS_BATTLE_TITAN
	special CreateBossBattleMon
	special BattleSetup_StartBossBattle
	waitstate
	setvar VAR_LAST_TALKED, 1
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	call_if_eq SapphireGym_Basement_EventScript_TitanDefeated
	releaseall
	end

SapphireGym_Basement_EventScript_TitanNoFight:
	msgbox TitanIntro_Text_Desacuerdo, MSGBOX_DEFAULT
	releaseall
	end

SapphireGym_Basement_EventScript_TitanDefeated::
	message SapphireGym2_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_DEFEATED_SAPPH_GYM
	setflag FLAG_DEFEATED_BOSS_TITAN
	removeobject 1
	releaseall
	end
TitanIntro_Text:
	.string "...\n"
	.string "...\p"
	.string "La gente de Ymir...\p"
	.string "...$"

TitanIntro_Text_DeAcuerdo:
	.string "...\n"
	.string "Ymir...\p"
	.string "... saludos.$"

TitanIntro_Text_Desacuerdo:
    .string "...\n"
    .string "... uuuughhh...$"

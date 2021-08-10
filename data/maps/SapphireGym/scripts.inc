SapphireGym_MapScripts::
map_script MAP_SCRIPT_ON_LOAD, SapphireGym_MapScripts_OnLoad
	.byte 0

SapphireGym_MapScripts_OnLoad:
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4

	compare VAR_STATE_SAPPH_GYM, 0
	call_if_eq SapphireGym_MapScripts_OnLoad_CloseFirstPuzzlePath

	compare VAR_STATE_SAPPH_GYM, 1
	call_if_le SapphireGym_MapScripts_OnLoad_CloseSecondPuzzlePath

	compare VAR_STATE_SAPPH_GYM, 4
	call_if_ge SapphireGym_MapScripts_OnLoad_CloseFourthPuzzlePath

	compare VAR_STATE_SAPPH_GYM, 5
	call_if_eq SapphireGym_MapScripts_OnLoad_OpenFourthPuzzlePath

	checktrainerflag TRAINER_SAPPH_GYM_1
	call_if_eq SapphireGym_MapScripts_OnLoad_DisableFirstPuzzleGirlTrigger
	checktrainerflag TRAINER_SAPPH_GYM_2
	call_if_eq SapphireGym_MapScripts_OnLoad_DisableSecondPuzzleGirlTrigger
	checktrainerflag TRAINER_SAPPH_GYM_3
	call_if_eq SapphireGym_MapScripts_OnLoad_DisableThirdPuzzleGirlTrigger
	return

SapphireGym_OpenFirsPuzzlePath:
	setmetatile 30, 34, 0x2C1, 0
	setmetatile 30, 35, 0x2C1, 0
	setmetatile 30, 36, 0x2C1, 0
	setmetatile 30, 37, 0x2C1, 0
	return

SapphireGym_MapScripts_OnLoad_CloseFirstPuzzlePath:
	setmetatile 30, 34, 0x222, 1
	setmetatile 30, 35, 0x22A, 1
	setmetatile 30, 36, 0x232, 1
	setmetatile 30, 37, 0x23A, 1
	return

SapphireGym_OpenSecondPuzzlePath:
	setmetatile 22, 19, 0x2C1, 0
	return

SapphireGym_MapScripts_OnLoad_CloseSecondPuzzlePath:
	setmetatile 22, 19, 0x237, 1
	return

SapphireGym_MapScripts_OnLoad_CloseFourthPuzzlePath:
	setvar VAR_TEMP_3, 1
	return

SapphireGym_MapScripts_OnLoad_OpenFourthPuzzlePath:
	setvar VAR_TEMP_3, 1
	setobjectxyperm 5, 18, 6
	return
	

SapphireGym_MapScripts_OnLoad_DisableFirstPuzzleGirlTrigger:
	setvar VAR_TEMP_0, 1
	return

SapphireGym_MapScripts_OnLoad_DisableSecondPuzzleGirlTrigger:
	setvar VAR_TEMP_1, 1
	return

SapphireGym_MapScripts_OnLoad_DisableThirdPuzzleGirlTrigger:
	setvar VAR_TEMP_2, 1
	return

SapphireGym_Trigger_Warp::
	warp MAP_SAPPHIRE_GYM, 5, 1, 10
	waitstate
	end

SapphireGym_Trigger_FightFirstPuzzleGirl::
	lock
	applymovement 3, SapphireGym_Movement_MoveFirstPuzzleGirl
	waitmovement 0
	trainerbattle_single TRAINER_SAPPH_GYM_1, SapphireGym_Text_FirstPuzzleGirlIntro, SapphireGym_Text_FirstPuzzleGirlLose, SapphireGym_EventScript_FirstPuzzleGirlDefeated, NO_MUSIC
	release
	end

SapphireGym_Trigger_FightSecondPuzzleGirl::
	lock
	applymovement 1, SapphireGym_Movement_MoveSecondPuzzleGirl
	waitmovement 0
	trainerbattle_single TRAINER_SAPPH_GYM_2, SapphireGym_Text_SecondPuzzleGirlIntro, SapphireGym_Text_SecondPuzzleGirlLose, SapphireGym_EventScript_SecondPuzzleGirlDefeated, NO_MUSIC
	release
	end

SapphireGym_Trigger_FightThirdPuzzleGirl::
	lock
	applymovement 6, SapphireGym_Movement_MoveThirdPuzzleGirl
	waitmovement 0
	trainerbattle_single TRAINER_SAPPH_GYM_3, SapphireGym_Text_ThirdPuzzleGirlIntro, SapphireGym_Text_ThirdPuzzleGirlLose, SapphireGym_EventScript_ThirdPuzzleGirlDefeated, NO_MUSIC
	release
	end

SapphireGym_Trigger_FourthPuzzle::
	lock
	msgbox SapphireGym_Text_FourthPuzzle_Explain, MSGBOX_NPC
	call SapphireGym_EventScript_ExecuteFourthPuzzle
	msgbox SapphireGym_Text_FourthPuzzle_GuessWhoFailed, MSGBOX_NPC
	multichoicegrid 0, 0, MULTI_SAPPHGYM_SECOND_PUZZLE_ANSWERS, 1, 1
	compare VAR_RESULT, 0
	goto_if_ne SapphireGym_EventScript_FourthPuzzle_FightRandom
	msgbox SapphireGym_Text_YouWonFourthPuzzle, MSGBOX_NPC
SapphireGym_EventScript_FourthPuzzle_EndPuzzle:
	fadedefaultbgm
	clearflag FLAG_RANDOMBATTLE_GYMGOOSES
	clearflag FLAG_RANDOMBATTLE_GYMSAPPH	  
	setvar VAR_STATE_SAPPH_GYM, 4
	setvar VAR_TEMP_3, 1
	release
	end

SapphireGym_EventScript_FourthPuzzle_FightRandom:
	msgbox SapphireGym_Text_YouFailed, MSGBOX_NPC
	setflag FLAG_RANDOMBATTLE_GYMGOOSES
	setflag FLAG_RANDOMBATTLE_GYMSAPPH
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq SapphireGym_EventScript_LossPuzzle_AndLossRandomBattle
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq SapphireGym_EventScript_FourthPuzzle_EndPuzzle
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq SapphireGym_EventScript_LossPuzzle_AndLossRandomBattle
    compare VAR_RESULT, B_OUTCOME_FORFEITED
    call_if_eq SapphireGym_EventScript_LossPuzzle_AndLossRandomBattle
	end

SapphireGym_EventScript_FirstPuzzleGirlDefeated:
	msgbox SapphireGym_Text_FirstPuzzleGirlDefeated, MSGBOX_NPC
	applymovement 3, SapphireGym_Movement_MoveFirstPuzzleGirlToOrigin
	waitmovement 0
	setvar VAR_TEMP_0, 1
	end

SapphireGym_EventScript_SecondPuzzleGirlDefeated:
	msgbox SapphireGym_Text_SecondPuzzleGirlDefeated, MSGBOX_NPC
	applymovement 1, SapphireGym_Movement_MoveSecondPuzzleGirlToOrigin
	waitmovement 0
	setvar VAR_TEMP_1, 1
	end

SapphireGym_EventScript_ThirdPuzzleGirlDefeated:
	msgbox SapphireGym_Text_ThirdPuzzleGirlDefeated, MSGBOX_NPC
	applymovement 6, SapphireGym_Movement_MoveThirdPuzzleGirlToOrigin
	waitmovement 0
	setvar VAR_TEMP_2, 1
	end

SapphireGym_EventScript_ExecuteFourthPuzzle:
	playbgm MUS_TEST3, 0
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideZigzagoon
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HidePoochyena
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideKirlia
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideMew
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideZigzagoon
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HidePoochyena
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideKirlia
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideMew
	return

SapphireGym_EventScript_ExecuteFourthPuzzle_HideZigzagoon:
	setobjectxy 17, 17, 7
	addobject 17
	playse SE_W100
	waitse
	applymovement 17, SapphireGym_Movement_ExecuteFourthPuzzle_HideZigzagoon
	waitmovement 0
	removeobject 17
	return

SapphireGym_EventScript_ExecuteFourthPuzzle_HidePoochyena:
	setobjectxy 18, 21, 7
	addobject 18
	playse SE_W100
	waitse
	applymovement 18, SapphireGym_Movement_ExecuteFourthPuzzle_HidePoochyena
	waitmovement 0
	removeobject 18
	return

SapphireGym_EventScript_ExecuteFourthPuzzle_HideKirlia:
	setobjectxy 20, 21, 9
	addobject 20
	playse SE_W100
	waitse
	applymovement 20, SapphireGym_Movement_ExecuteFourthPuzzle_HideKirlia
	waitmovement 0
	removeobject 20
	return

SapphireGym_EventScript_ExecuteFourthPuzzle_HideMew:
	setobjectxy 19, 17, 9
	addobject 19
	playse SE_W100
	waitse
	applymovement 19, SapphireGym_Movement_ExecuteFourthPuzzle_HideMew
	waitmovement 0
	removeobject 19
	return


SapphireGym_EventScript_GymExplanation::
	lock
	checktrainerflag TRAINER_SAPPH
	goto_if_eq SapphireGym_EventScript_GymExplanation_DefeatedSapph
	msgbox SapphireGym_Text_GymExplanation, MSGBOX_NPC
	release
	end

SapphireGym_EventScript_GymExplanation_DefeatedSapph:
	msgbox SapphireGym_Text_GymExplanation_DefeatedSapph, MSGBOX_NPC
	release
	end


SapphireGym_EventScript_FirstPuzzle::
	lock
	compare VAR_STATE_SAPPH_GYM, 0
	goto_if_eq SapphireGym_EventScript_FirstPuzzle_Explain
	msgbox SapphireGym_Text_FirstPuzzle_Done, MSGBOX_NPC
	release
	end

SapphireGym_EventScript_FirstPuzzle_Explain:
	msgbox SapphireGym_Text_FirstPuzzle_Explain, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, NO
	goto_if_eq SapphireGym_EventScript_FirstPuzzle_Decline
	applymovement EVENT_OBJ_ID_PLAYER, SapphireGym_Movement_FirstPuzzle_MovePlayer
	waitmovement 0
	call SapphireGym_EventScript_ExecutePuzzle
	msgbox SapphireGym_Text_FirstPuzzle_GuessWhoFailed, MSGBOX_NPC
	multichoicegrid 0, 0, MULTI_SAPPHGYM_FIRST_PUZZLE_ANSWERS, 1, 1
	compare VAR_RESULT, 0
	goto_if_ne SapphireGym_EventScript_FirstPuzzle_FightRandom
	msgbox SapphireGym_Text_YouWon, MSGBOX_NPC
SapphireGym_EventScript_FirstPuzzle_EndPuzzle:
	fadedefaultbgm
	clearflag FLAG_RANDOMBATTLE_GYMGOOSES
	clearflag FLAG_RANDOMBATTLE_GYMSAPPH
	call SapphireGym_EventScript_FirstPuzzle_OpenPath
	setvar VAR_STATE_SAPPH_GYM, 1
	release
	end

SapphireGym_EventScript_LossPuzzle_AndLossRandomBattle:
	fadedefaultbgm
	special HealPlayerParty
	clearflag FLAG_RANDOMBATTLE_GYMGOOSES
	clearflag FLAG_RANDOMBATTLE_GYMSAPPH
	warp MAP_SAPPHIRE_GYM, 0, 0, 0
	closemessage
	release
	end

SapphireGym_EventScript_FirstPuzzle_Decline:
	msgbox SapphireGym_Text_FirstPuzzle_Decline, MSGBOX_NPC
	release
	end

SapphireGym_EventScript_ExecutePuzzle:
	call SapphireGym_EventScript_ShowZigzagoon
	call SapphireGym_EventScript_ShowPoochyena
	call SapphireGym_EventScript_ShowMew
	call SapphireGym_EventScript_StartFirstPuzzle
	call SapphireGym_EventScript_HideZigzagoon
	call SapphireGym_EventScript_HidePoochyena
	call SapphireGym_EventScript_HideMew
	return

SapphireGym_EventScript_FirstPuzzle_FightRandom:
	msgbox SapphireGym_Text_YouFailed, MSGBOX_NPC
	setflag FLAG_RANDOMBATTLE_GYMGOOSES
	setflag FLAG_RANDOMBATTLE_GYMSAPPH
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq SapphireGym_EventScript_LossPuzzle_AndLossRandomBattle
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq SapphireGym_EventScript_FirstPuzzle_EndPuzzle
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq SapphireGym_EventScript_LossPuzzle_AndLossRandomBattle
    compare VAR_RESULT, B_OUTCOME_FORFEITED
    call_if_eq SapphireGym_EventScript_LossPuzzle_AndLossRandomBattle
	end

SapphireGym_EventScript_ShowZigzagoon:
	msgbox SapphireGym_Text_ShowZigzagoon, MSGBOX_NPC
	addobject 9
	applymovement 9, SapphireGym_Movement_FirstPuzzleShowMon
	waitmovement 0
	playmoncry SPECIES_ZIGZAGOON, 2
	waitmoncry
	return

SapphireGym_EventScript_ShowPoochyena:
	msgbox SapphireGym_Text_ShowPoochyena, MSGBOX_NPC
	addobject 8
	applymovement 8, SapphireGym_Movement_FirstPuzzleShowMon
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, 2
	waitmoncry
	return

SapphireGym_EventScript_ShowMew:
	msgbox SapphireGym_Text_ShowMew, MSGBOX_NPC
	addobject 7
	applymovement 7, SapphireGym_Movement_FirstPuzzleShowMon
	waitmovement 0
	playmoncry SPECIES_MEW, 2
	waitmoncry
	return

SapphireGym_EventScript_HideZigzagoon:
	playmoncry SPECIES_ZIGZAGOON, 2
	waitmoncry
	applymovement 9, SapphireGym_Movement_FirstPuzzleHideMon
	waitmovement 0
	removeobject 9
	return

SapphireGym_EventScript_HidePoochyena:
	playmoncry SPECIES_POOCHYENA, 2
	waitmoncry
	applymovement 8, SapphireGym_Movement_FirstPuzzleHideMon
	waitmovement 0
	removeobject 8
	return

SapphireGym_EventScript_HideMew:
	playmoncry SPECIES_MEW, 2
	waitmoncry
	applymovement 7, SapphireGym_Movement_FirstPuzzleHideMon
	waitmovement 0
	removeobject 7
	return

SapphireGym_EventScript_StartFirstPuzzle:
	playbgm MUS_TEST3, 0
	call SapphireGym_EventScript_StartFirstPuzzle_Iteration0
	call SapphireGym_EventScript_StartFirstPuzzle_Iteration1
	call SapphireGym_EventScript_StartFirstPuzzle_Iteration2
	call SapphireGym_EventScript_StartFirstPuzzle_Iteration3
	call SapphireGym_EventScript_StartFirstPuzzle_Iteration4
	
	return


SapphireGym_EventScript_SecondPuzzle::
	lock
	compare VAR_STATE_SAPPH_GYM, 1
	goto_if_eq SapphireGym_EventScript_SecondPuzzle_Explain
	msgbox SapphireGym_Text_SecondPuzzle_Done, MSGBOX_NPC
	release
	end

SapphireGym_EventScript_SecondPuzzle_Explain:
	msgbox SapphireGym_Text_SecondPuzzle_Explain, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, NO
	goto_if_eq SapphireGym_EventScript_SecondPuzzle_Decline
	applymovement EVENT_OBJ_ID_PLAYER, SapphireGym_Movement_SecondPuzzle_MovePlayer
	waitmovement 0
	call SapphireGym_EventScript_ExecuteSecondPuzzle
	msgbox SapphireGym_Text_SecondPuzzle_GuessWhoFailed, MSGBOX_NPC
	multichoicegrid 0, 0, MULTI_SAPPHGYM_SECOND_PUZZLE_ANSWERS, 1, 1
	compare VAR_RESULT, 0
	goto_if_ne SapphireGym_EventScript_SecondPuzzle_FightRandom
	msgbox SapphireGym_Text_YouWonSecondPuzzle, MSGBOX_NPC
SapphireGym_EventScript_SecondPuzzle_EndPuzzle:
	fadedefaultbgm
	clearflag FLAG_RANDOMBATTLE_GYMGOOSES
	clearflag FLAG_RANDOMBATTLE_GYMSAPPH	  
	call SapphireGym_EventScript_SecondPuzzle_OpenPath
	setvar VAR_STATE_SAPPH_GYM, 2
	release
	end

SapphireGym_EventScript_SecondPuzzle_Decline:
	msgbox SapphireGym_Text_SecondPuzzle_Decline, MSGBOX_NPC
	release
	end

SapphireGym_EventScript_SecondPuzzle_FightRandom:
	msgbox SapphireGym_Text_YouFailed, MSGBOX_NPC
	setflag FLAG_RANDOMBATTLE_GYMGOOSES
	setflag FLAG_RANDOMBATTLE_GYMSAPPH
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq SapphireGym_EventScript_LossPuzzle_AndLossRandomBattle
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq SapphireGym_EventScript_SecondPuzzle_EndPuzzle
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq SapphireGym_EventScript_LossPuzzle_AndLossRandomBattle
    compare VAR_RESULT, B_OUTCOME_FORFEITED
    call_if_eq SapphireGym_EventScript_LossPuzzle_AndLossRandomBattle
	end

SapphireGym_EventScript_ExecuteSecondPuzzle:
	call SapphireGym_EventScript_ShowZigzagoon2
	call SapphireGym_EventScript_ShowPoochyena2
	call SapphireGym_EventScript_ShowMew2
	call SapphireGym_EventScript_ShowKirlia
	call SapphireGym_EventScript_StartSecondPuzzle
	call SapphireGym_EventScript_MakePCEmitSounds
	call SapphireGym_EventScript_HideMondsAndMakeGirlReturn
	return

SapphireGym_EventScript_ShowZigzagoon2:
	msgbox SapphireGym_Text_ShowZigzagoon2, MSGBOX_NPC
	addobject 10
	applymovement 10, SapphireGym_Movement_SecondPuzzleShowMon1
	waitmovement 0
	playmoncry SPECIES_ZIGZAGOON, 2
	waitmoncry
	return

SapphireGym_EventScript_ShowPoochyena2:
	msgbox SapphireGym_Text_ShowPoochyena2, MSGBOX_NPC
	addobject 11
	applymovement 11, SapphireGym_Movement_SecondPuzzleShowMon2
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, 2
	waitmoncry
	return

SapphireGym_EventScript_ShowMew2:
	msgbox SapphireGym_Text_ShowMew2, MSGBOX_NPC
	addobject 12
	applymovement 12, SapphireGym_Movement_SecondPuzzleShowMon3
	waitmovement 0
	playmoncry SPECIES_MEW, 2
	waitmoncry
	return

SapphireGym_EventScript_ShowKirlia:
	msgbox SapphireGym_Text_ShowKirlia, MSGBOX_NPC
	addobject 13
	applymovement 13, SapphireGym_Movement_SecondPuzzleShowMon4
	waitmovement 0
	playmoncry SPECIES_KIRLIA, 2
	waitmoncry
	return

SapphireGym_EventScript_StartSecondPuzzle:
	playbgm MUS_TEST3, 0
	call SapphireGym_EventScript_StartSecondPuzzle_Iteration0
	call SapphireGym_EventScript_StartSecondPuzzle_Iteration1
	call SapphireGym_EventScript_StartSecondPuzzle_Iteration2
	call SapphireGym_EventScript_StartSecondPuzzle_Iteration3
	call SapphireGym_EventScript_StartSecondPuzzle_Iteration4
	return

SapphireGym_EventScript_MakePCEmitSounds:
	msgbox SapphireGym_Text_SecondPuzzlePowerOnPCs, MSGBOX_NPC
	applymovement 1, SapphireGym_Movement_GoToFirstPC
	waitmovement 0
	msgbox SapphireGym_Text_FirstPC, MSGBOX_NPC
	playse SE_PC_LOGIN
	waitse
	playmoncry SPECIES_MEW, 2
	waitmoncry
	applymovement 1, SapphireGym_Movement_GoToSecondtPC
	waitmovement 0
	msgbox SapphireGym_Text_SecondPC, MSGBOX_NPC
	playse SE_PC_LOGIN
	waitse
	playmoncry SPECIES_KIRLIA, 2
	waitmoncry
	applymovement 1, SapphireGym_Movement_GoToThirdPC
	waitmovement 0
	msgbox SapphireGym_Text_ThirdPC, MSGBOX_NPC
	playse SE_PC_LOGIN
	waitse
	playmoncry SPECIES_ZIGZAGOON, 2
	waitmoncry
	return

SapphireGym_EventScript_HideMondsAndMakeGirlReturn:
	applymovement 12, SapphireGym_Movement_SecondPuzzleHideMon1
	waitmovement 0
	removeobject 12
	applymovement 13, SapphireGym_Movement_SecondPuzzleHideMon2
	waitmovement 0
	removeobject 13
	applymovement 10, SapphireGym_Movement_SecondPuzzleHideMon3
	waitmovement 0
	removeobject 10
	applymovement 11, SapphireGym_Movement_SecondPuzzleHideMon4
	waitmovement 0
	removeobject 11
	applymovement 1, SapphireGym_Movement_SecondPuzzleGirlReturnAfterPC
	waitmovement 0
	
	return


SapphireGym_EventScript_ThirdPuzzleGirl::
	lock
	checktrainerflag TRAINER_SAPPH_GYM_3
	goto_if_ne SapphireGym_EventScript_ThirdPuzzleGirl_Sleep
	faceplayer
	msgbox SapphireGym_Text_ThirdPuzzleGirl_YouBeatPuzzle, MSGBOX_NPC
	release
	end

SapphireGym_EventScript_ThirdPuzzleGirl_Sleep:
	msgbox SapphireGym_Text_ThirdPuzzleGirl_Sleep, MSGBOX_NPC
	release
	end

SapphireGym_EventScript_ThirdPuzzleZigza::
	lock
	faceplayer
	msgbox SapphireGym_Text_ThirdPuzzleZigza, MSGBOX_NPC
	call SapphireGym_EventScript_StartThirdPuzzle
	msgbox SapphireGym_Text_ThirdPuzzle_GuessWhoFailed, MSGBOX_NPC
	multichoicegrid 0, 0, MULTI_SAPPHGYM_SECOND_PUZZLE_ANSWERS, 1, 1
	compare VAR_RESULT, 0
	goto_if_ne SapphireGym_EventScript_ThirdPuzzle_FightRandom
	msgbox SapphireGym_Text_YouWonThirdPuzzle, MSGBOX_NPC
SapphireGym_EventScript_ThirdPuzzle_EndPuzzle:
	fadedefaultbgm
	clearflag FLAG_RANDOMBATTLE_GYMGOOSES
	clearflag FLAG_RANDOMBATTLE_GYMSAPPH	  
	call SapphireGym_EventScript_ThirdPuzzle_OpenPath
	setvar VAR_STATE_SAPPH_GYM, 3
	release
	end

SapphireGym_EventScript_StartThirdPuzzle:
	playbgm MUS_TEST3, 0
	call SapphireGym_EventScript_PositionThirdPuzzleMons
	call SapphireGym_EventScript_ExecuteThirdPuzzle
	call SapphireGym_EventScript_HideThirdPuzzleMons
	return

SapphireGym_EventScript_PositionThirdPuzzleMons:
	call SapphireGym_EventScript_PositionKirlia3
	call SapphireGym_EventScript_PositionPoochyena3
	call SapphireGym_EventScript_PositionMew3
	return

SapphireGym_EventScript_PositionKirlia3:
	addobject 14
	applymovement 14, SapphireGym_Movement_PositionKirlia3
	waitmovement 0
	playmoncry SPECIES_KIRLIA, 2
	waitmoncry
	return

SapphireGym_EventScript_PositionPoochyena3:
	addobject 15
	applymovement 15, SapphireGym_Movement_PositionPoochyena3
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, 2
	waitmoncry
	return

SapphireGym_EventScript_PositionMew3:
	addobject 16
	applymovement 16, SapphireGym_Movement_PositionMew3
	waitmovement 0
	playmoncry SPECIES_MEW, 2
	waitmoncry
	return

SapphireGym_EventScript_ExecuteThirdPuzzle:
	call SapphireGym_EventScript_StartThirdPuzzle_Iteration0
	call SapphireGym_EventScript_StartThirdPuzzle_Iteration1
	call SapphireGym_EventScript_StartThirdPuzzle_Iteration2
	return

SapphireGym_EventScript_HideThirdPuzzleMons:
	call SapphireGym_EventScript_HideKirlia3
	call SapphireGym_EventScript_HidePoochyena3
	call SapphireGym_EventScript_HideMew3
	return

SapphireGym_EventScript_HideKirlia3:
	playmoncry SPECIES_KIRLIA, 2
	waitmoncry
	applymovement 14, SapphireGym_Movement_HideKirlia3
	waitmovement 0
	removeobject 14
	return

SapphireGym_EventScript_HidePoochyena3:
	playmoncry SPECIES_POOCHYENA, 2
	waitmoncry
	applymovement 15, SapphireGym_Movement_HidePoochyena3
	waitmovement 0
	removeobject 15
	return

SapphireGym_EventScript_HideMew3:
	playmoncry SPECIES_MEW, 2
	waitmoncry
	applymovement 16, SapphireGym_Movement_HideMew3
	waitmovement 0
	removeobject 16
	return

SapphireGym_EventScript_StartThirdPuzzle_Iteration0:
	msgbox SapphireGym_Text_ThirdPuzzleIteration0, MSGBOX_NPC

	playmoncry SPECIES_MEW, 2
	waitmoncry
	applymovement 16, SapphireGym_Movement_ThirdPuzzleIteration0
	waitmovement 0
	playmoncry SPECIES_KIRLIA, 2
	waitmoncry
	applymovement 14, SapphireGym_Movement_ThirdPuzzleIteration0
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, 2
	waitmoncry
	applymovement 15, SapphireGym_Movement_ThirdPuzzleIteration0
	waitmovement 0
	return

SapphireGym_EventScript_ThirdPuzzle_FightRandom:
	msgbox SapphireGym_Text_YouFailed, MSGBOX_NPC
	setflag FLAG_RANDOMBATTLE_GYMGOOSES
	setflag FLAG_RANDOMBATTLE_GYMSAPPH
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq SapphireGym_EventScript_LossPuzzle_AndLossRandomBattle
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq SapphireGym_EventScript_ThirdPuzzle_EndPuzzle
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq SapphireGym_EventScript_LossPuzzle_AndLossRandomBattle
    compare VAR_RESULT, B_OUTCOME_FORFEITED
    call_if_eq SapphireGym_EventScript_LossPuzzle_AndLossRandomBattle
	end

SapphireGym_EventScript_ThirdPuzzle_OpenPath:
	applymovement 4, SapphireGym_Movement_ThirdPuzzle_OpenPath
	waitmovement 0
	removeobject 4
	return

SapphireGym_EventScript_FourthPuzzleGirl::
	lock
	faceplayer
	compare VAR_STATE_SAPPH_GYM, 5
	goto_if_eq SapphireGym_EventScript_FourthPuzzleGirl_Defeated
	trainerbattle_single TRAINER_SAPPH_GYM_4, SapphireGym_Text_FourthPuzzleGirlIntro, SapphireGym_Text_FourthPuzzleGirlLose, SapphireGym_EventScript_FourthPuzzleGirl_Defeat, NO_MUSIC
	release
	end

SapphireGym_EventScript_FourthPuzzleGirl_Defeated:
	msgbox SapphireGym_Text_FourthPuzzleGirl_Defeated, MSGBOX_NPC
	release
	end

SapphireGym_EventScript_FourthPuzzleGirl_Defeat:
	setvar VAR_STATE_SAPPH_GYM, 5
	msgbox SapphireGym_Text_FourthPuzzleGirl_Defeated, MSGBOX_NPC
	applymovement 5, Common_Movement_WalkUp
	waitmovement 0
	removeobject 5
	setobjectxyperm 5, 18, 6
	release
	end

SapphireGym_Movement_ThirdPuzzleIteration0:
	face_right
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	step_end

SapphireGym_Text_ThirdPuzzleIteration0:
	.string "TEXTO ITERACION 1$"

SapphireGym_EventScript_StartThirdPuzzle_Iteration1:
	msgbox SapphireGym_Text_ThirdPuzzleIteration1, MSGBOX_NPC

	playmoncry SPECIES_POOCHYENA, 2
	waitmoncry
	applymovement 15, SapphireGym_Movement_ThirdPuzzleIteration1
	waitmovement 0
	playmoncry SPECIES_KIRLIA, 2
	waitmoncry
	applymovement 14, SapphireGym_Movement_ThirdPuzzleIteration1
	waitmovement 0
	playmoncry SPECIES_MEW, 2
	waitmoncry
	applymovement 16, SapphireGym_Movement_ThirdPuzzleIteration1
	waitmovement 0
	return

SapphireGym_Movement_ThirdPuzzleIteration1:
	face_up
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	step_end

SapphireGym_Text_ThirdPuzzleIteration1:
	.string "TEXTO ITERACION 2$"

SapphireGym_EventScript_StartThirdPuzzle_Iteration2:
	msgbox SapphireGym_Text_ThirdPuzzleIteration2, MSGBOX_NPC

	playmoncry SPECIES_KIRLIA, 2
	waitmoncry
	applymovement 14, SapphireGym_Movement_ThirdPuzzleIteration2
	waitmovement 0
	playmoncry SPECIES_MEW, 2
	waitmoncry
	applymovement 16, SapphireGym_Movement_ThirdPuzzleIteration2
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, 2
	waitmoncry
	applymovement 15, SapphireGym_Movement_ThirdPuzzleIteration2
	waitmovement 0
	return

SapphireGym_Movement_ThirdPuzzleIteration2:
	face_up
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	step_end

SapphireGym_Text_ThirdPuzzleIteration2:
	.string "TEXTO ITERACION 3$"



SapphireGym_EventScript_StartSecondPuzzle_Iteration0:
	msgbox SapphireGym_Text_SecondPuzzleIteration0, MSGBOX_NPC

	playmoncry SPECIES_KIRLIA, 2
	waitmoncry
	applymovement 13, SapphireGym_Movement_SecondPuzzleIteration0
	waitmovement 0
	playmoncry SPECIES_MEW, 2
	waitmoncry
	applymovement 12, SapphireGym_Movement_SecondPuzzleIteration0
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, 2
	waitmoncry
	applymovement 11, SapphireGym_Movement_SecondPuzzleIteration0
	waitmovement 0
	playmoncry SPECIES_ZIGZAGOON, 2
	waitmoncry
	applymovement 10, SapphireGym_Movement_SecondPuzzleIteration0
	waitmovement 0
	return

SapphireGym_Movement_SecondPuzzleIteration0:
	face_up
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	step_end

SapphireGym_Text_SecondPuzzleIteration0:
	.string "TEXTO ITERACION 1$"

SapphireGym_EventScript_StartSecondPuzzle_Iteration1:
	msgbox SapphireGym_Text_SecondPuzzleIteration1, MSGBOX_NPC

	playmoncry SPECIES_ZIGZAGOON, 2
	waitmoncry
	applymovement 10, SapphireGym_Movement_SecondPuzzleIteration1
	waitmovement 0
	playmoncry SPECIES_MEW, 2
	waitmoncry
	applymovement 12, SapphireGym_Movement_SecondPuzzleIteration1
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, 2
	waitmoncry
	applymovement 11, SapphireGym_Movement_SecondPuzzleIteration1
	waitmovement 0
	playmoncry SPECIES_KIRLIA, 2
	waitmoncry
	applymovement 13, SapphireGym_Movement_SecondPuzzleIteration1
	waitmovement 0
	return

SapphireGym_Movement_SecondPuzzleIteration1:
	face_left
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	step_end

SapphireGym_Text_SecondPuzzleIteration1:
	.string "TEXTO ITERACION 2$"

SapphireGym_EventScript_StartSecondPuzzle_Iteration2:
	msgbox SapphireGym_Text_SecondPuzzleIteration2, MSGBOX_NPC

	playmoncry SPECIES_MEW, 2
	waitmoncry
	applymovement 12, SapphireGym_Movement_SecondPuzzleIteration2
	waitmovement 0
	playmoncry SPECIES_ZIGZAGOON, 2
	waitmoncry
	applymovement 10, SapphireGym_Movement_SecondPuzzleIteration2
	waitmovement 0
	playmoncry SPECIES_KIRLIA, 2
	waitmoncry
	applymovement 13, SapphireGym_Movement_SecondPuzzleIteration2
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, 2
	waitmoncry
	applymovement 11, SapphireGym_Movement_SecondPuzzleIteration2
	waitmovement 0
	return

SapphireGym_Movement_SecondPuzzleIteration2:
	face_up
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_down
	delay_16
	step_end

SapphireGym_Text_SecondPuzzleIteration2:
	.string "TEXTO ITERACION 3$"

SapphireGym_EventScript_StartSecondPuzzle_Iteration3:
	msgbox SapphireGym_Text_SecondPuzzleIteration3, MSGBOX_NPC

	playmoncry SPECIES_MEW, 2
	waitmoncry
	applymovement 12, SapphireGym_Movement_SecondPuzzleIteration3
	waitmovement 0
	playmoncry SPECIES_KIRLIA, 2
	waitmoncry
	applymovement 13, SapphireGym_Movement_SecondPuzzleIteration3
	waitmovement 0
	playmoncry SPECIES_ZIGZAGOON, 2
	waitmoncry
	applymovement 10, SapphireGym_Movement_SecondPuzzleIteration3
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, 2
	waitmoncry
	applymovement 11, SapphireGym_Movement_SecondPuzzleIteration3
	waitmovement 0
	return

SapphireGym_Movement_SecondPuzzleIteration3:
	face_left
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	step_end

SapphireGym_Text_SecondPuzzleIteration3:
	.string "TEXTO ITERACION 4$"

SapphireGym_EventScript_StartSecondPuzzle_Iteration4:
	msgbox SapphireGym_Text_SecondPuzzleIteration4, MSGBOX_NPC

	playmoncry SPECIES_KIRLIA, 2
	waitmoncry
	applymovement 13, SapphireGym_Movement_SecondPuzzleIteration4
	waitmovement 0
	playmoncry SPECIES_POOCHYENA, 2
	waitmoncry
	applymovement 11, SapphireGym_Movement_SecondPuzzleIteration4
	waitmovement 0
	playmoncry SPECIES_ZIGZAGOON, 2
	waitmoncry
	applymovement 10, SapphireGym_Movement_SecondPuzzleIteration4
	waitmovement 0
	playmoncry SPECIES_MEW, 2
	waitmoncry
	applymovement 12, SapphireGym_Movement_SecondPuzzleIteration4
	waitmovement 0
	return

SapphireGym_Movement_SecondPuzzleIteration4:
	face_left
	delay_16
	face_up
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_up
	delay_16
	face_down
	delay_16
	face_up
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	face_down
	delay_16
	face_left
	delay_16
	step_end

SapphireGym_Text_SecondPuzzleIteration4:
	.string "TEXTO ITERACION 5$"



SapphireGym_EventScript_StartFirstPuzzle_Iteration0:
	msgbox SapphireGym_Text_Iteration0, MSGBOX_NPC

	applymovement 9, SapphireGym_Movement_Iteration0
	waitmovement 0
	applymovement 7, SapphireGym_Movement_Iteration0
	waitmovement 0
	applymovement 8, SapphireGym_Movement_Iteration0
	waitmovement 0

	return

SapphireGym_Movement_Iteration0:
	face_right
	delay_4
	face_left
	delay_4
	face_up
	delay_4
	face_right
	delay_4
	walk_right
	delay_4
	walk_up
	delay_4
	face_up
	delay_4
	face_right
	delay_4
	walk_left
	delay_4
	walk_left
	delay_4
	face_down
	delay_4
	face_left
	delay_4
	walk_right
	delay_4
	walk_down
	delay_4
	face_down
	delay_4
	delay_16
	delay_4
	step_end

SapphireGym_Text_Iteration0:
	.string "TEXTO ITERACION 1$"

SapphireGym_EventScript_StartFirstPuzzle_Iteration1:
	msgbox SapphireGym_Text_Iteration1, MSGBOX_NPC

	applymovement 7, SapphireGym_Movement_Iteration1
	waitmovement 0
	applymovement 8, SapphireGym_Movement_Iteration1
	waitmovement 0
	applymovement 9, SapphireGym_Movement_Iteration1
	waitmovement 0

	return

SapphireGym_Movement_Iteration1:
	walk_left
	delay_4
	face_right
	delay_4
	walk_right
	delay_4
	walk_down
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	walk_right
	delay_4
	face_left
	delay_4
	walk_up
	delay_4
	face_left
	delay_4
	face_up
	delay_4
	face_down
	delay_4
	walk_left
	delay_4
	face_down
	delay_4
	delay_16
	delay_4
	step_end

SapphireGym_Text_Iteration1:
	.string "TEXTO ITERACION 2$"

SapphireGym_EventScript_StartFirstPuzzle_Iteration2:
	msgbox SapphireGym_Text_Iteration2, MSGBOX_NPC

	applymovement 7, SapphireGym_Movement_Iteration2
	waitmovement 0
	applymovement 9, SapphireGym_Movement_Iteration2
	waitmovement 0
	applymovement 8, SapphireGym_Movement_Iteration2
	waitmovement 0

	return

SapphireGym_Movement_Iteration2:
	face_right
	delay_4
	face_up
	delay_4
	walk_up
	delay_4
	face_up
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	walk_left
	delay_4
	walk_down
	delay_4
	face_left
	delay_4
	walk_up
	delay_4
	face_up
	delay_4
	walk_right
	delay_4
	walk_down
	delay_4
	face_down
	delay_4
	delay_16
	delay_4
	step_end

SapphireGym_Text_Iteration2:
	.string "TEXTO ITERACION 3$"

SapphireGym_EventScript_StartFirstPuzzle_Iteration3:
	msgbox SapphireGym_Text_Iteration3, MSGBOX_NPC

	applymovement 7, SapphireGym_Movement_Iteration3
	waitmovement 0
	applymovement 8, SapphireGym_Movement_Iteration3
	waitmovement 0
	applymovement 9, SapphireGym_Movement_Iteration3
	waitmovement 0

	return

SapphireGym_Movement_Iteration3:
	face_down
	delay_4
	face_up
	delay_4
	walk_right
	delay_4
	walk_down
	delay_4
	walk_up
	delay_4
	walk_left
	delay_4
	face_up
	delay_4
	walk_down
	delay_4
	walk_up
	delay_4
	face_up
	delay_4
	walk_left
	delay_4
	face_right
	delay_4
	walk_right
	delay_4
	face_down
	delay_4
	delay_16
	delay_4
	step_end

SapphireGym_Text_Iteration3:
	.string "TEXTO ITERACION 4$"

SapphireGym_EventScript_StartFirstPuzzle_Iteration4:
	msgbox SapphireGym_Text_Iteration4, MSGBOX_NPC

	applymovement 9, SapphireGym_Movement_Iteration4
	waitmovement 0
	applymovement 7, SapphireGym_Movement_Iteration4
	waitmovement 0
	applymovement 8, SapphireGym_Movement_Iteration4
	waitmovement 0

	return

SapphireGym_Movement_Iteration4:
	face_up
	delay_4
	face_down
	delay_4
	walk_up
	delay_4
	walk_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	walk_left
	delay_4
	walk_right
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	walk_left
	delay_4
	walk_down
	delay_4
	face_down
	delay_4
	delay_16
	delay_4
	step_end

SapphireGym_Text_Iteration4:
	.string "TEXTO ITERACION 5$"



SapphireGym_EventScript_FirstPuzzle_OpenPath:
	playse SE_W153
	waitse
	special DoSealedChamberShakingEffect1
	waitstate
	delay 40
	playse SE_DOOR
	delay 40
	call SapphireGym_OpenFirsPuzzlePath
	playse(SE_RG_W_DOOR)
	special DrawWholeMapView
	return

SapphireGym_EventScript_SecondPuzzle_OpenPath:
	playse SE_W153
	waitse
	special DoSealedChamberShakingEffect1
	waitstate
	delay 40
	playse SE_DOOR
	delay 40
	call SapphireGym_OpenSecondPuzzlePath
	playse(SE_RG_W_DOOR)
	special DrawWholeMapView
	return


SapphireGym_Movement_FirstPuzzle_MovePlayer:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

SapphireGym_Movement_FirstPuzzleShowMon:
	walk_down
	walk_down
	walk_down
	delay_4
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	step_end

SapphireGym_Movement_FirstPuzzleHideMon:
	walk_up
	walk_up
	walk_up
	step_end

SapphireGym_Movement_MoveFirstPuzzleGirl:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SapphireGym_Movement_MoveFirstPuzzleGirlToOrigin:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_down
	step_end

SapphireGym_Movement_SecondPuzzle_MovePlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	face_up
	step_end

SapphireGym_Movement_SecondPuzzleShowMon1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end

SapphireGym_Movement_SecondPuzzleShowMon2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_down
	step_end

SapphireGym_Movement_SecondPuzzleShowMon3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

SapphireGym_Movement_SecondPuzzleShowMon4:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	face_down
	step_end

SapphireGym_Movement_SecondPuzzleHideMon1:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SapphireGym_Movement_SecondPuzzleHideMon2:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SapphireGym_Movement_SecondPuzzleHideMon3:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SapphireGym_Movement_SecondPuzzleHideMon4:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SapphireGym_Movement_GoToFirstPC:
	walk_down
	walk_right
	face_up
	step_end

SapphireGym_Movement_GoToSecondtPC:
	walk_right
	face_up
	step_end

SapphireGym_Movement_GoToThirdPC:
	walk_right
	face_up
	step_end

SapphireGym_Movement_SecondPuzzleGirlReturnAfterPC:
	walk_left
	walk_left
	walk_left
	walk_up
	face_down
	step_end

SapphireGym_Movement_MoveSecondPuzzleGirl:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

SapphireGym_Movement_MoveSecondPuzzleGirlToOrigin:
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_down
	step_end

SapphireGym_Movement_PositionKirlia3:
	walk_down
	walk_down
	walk_left
	face_down
	step_end

SapphireGym_Movement_PositionPoochyena3:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	face_down
	step_end

SapphireGym_Movement_PositionMew3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SapphireGym_Movement_HideKirlia3:
	walk_right
	walk_up
	walk_up
	step_end

SapphireGym_Movement_HidePoochyena3:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SapphireGym_Movement_HideMew3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SapphireGym_Movement_ThirdPuzzle_OpenPath:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SapphireGym_Movement_MoveThirdPuzzleGirl:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

SapphireGym_Movement_MoveThirdPuzzleGirlToOrigin:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end

SapphireGym_Movement_ExecuteFourthPuzzle_HideZigzagoon:
	walk_left
	walk_up
	step_end

SapphireGym_Movement_ExecuteFourthPuzzle_HidePoochyena:
	walk_right
	walk_up
	step_end

SapphireGym_Movement_ExecuteFourthPuzzle_HideMew:
	walk_left
	walk_down
	step_end

SapphireGym_Movement_ExecuteFourthPuzzle_HideKirlia:
	walk_right
	walk_down
	step_end

SapphireGym_Text_GymExplanation:
	.string "TEXTO EXPLICAR GYM$"

SapphireGym_Text_GymExplanation_DefeatedSapph:
	.string "TEXTO DERROTASTE A SAPPH$"

SapphireGym_Text_FirstPuzzle_Explain:
	.string "TEXTO EXPLICAR PRIMER PUZZLE$"

SapphireGym_Text_FirstPuzzle_Done:
	.string "TEXTO COMPLETASTE EL PRIMER PUZZLE$"

SapphireGym_Text_FirstPuzzle_Decline:
	.string "TEXTO VUELVE CUANDO QUIERAS$"

SapphireGym_Text_ShowZigzagoon:
	.string "TEXTO ESTE ES ZIGZA$"

SapphireGym_Text_ShowPoochyena:
	.string "TEXTO ESTE ES POOCHY$"

SapphireGym_Text_ShowMew:
	.string "TEXTO ESTE ES MEW$"

SapphireGym_Text_FirstPuzzle_GuessWhoFailed:
	.string "TEXTO QUIEN SE EQUIVOCÓ?$"

SapphireGym_Text_YouFailed:
	.string "TEXTO FALLASTE LUCHA RAND$"

SapphireGym_Text_YouWon:
	.string "TEXTO GANASTE TE JODES$"

SapphireGym_Text_FirstPuzzleGirlIntro:
	.string "TEXTO FPG INTRO$"

SapphireGym_Text_FirstPuzzleGirlLose:
	.string "TEXTO FPG LOSE$"

SapphireGym_Text_FirstPuzzleGirlDefeated:
	.string "TEXTO FPG DEFEATED$"

SapphireGym_Text_SecondPuzzle_Done:
	.string "TEXTO COMPLETASTE EL 2DO PUZZLE$"

SapphireGym_Text_SecondPuzzle_Decline:
	.string "TEXTO VUELVE CUANDO QUIERAS$"

SapphireGym_Text_SecondPuzzle_Explain:
	.string "TEXTO EXPLICA 2ND PLZUEL$"

SapphireGym_Text_SecondPuzzle_GuessWhoFailed:
	.string "TEXTO ADIVINA 2D PUZLE$"

SapphireGym_Text_YouWonSecondPuzzle:
	.string "GANASTE TE JODES 2DO PUZLE$"

SapphireGym_Text_ShowZigzagoon2:
	.string "TEXTO ZIGZA$"

SapphireGym_Text_ShowPoochyena2:
	.string "TEXTO pch$"

SapphireGym_Text_ShowMew2:
	.string "TEXTO MEW$"

SapphireGym_Text_ShowKirlia:
	.string "TEXTO KRLLL$"

SapphireGym_Text_SecondPuzzlePowerOnPCs:
	.string "TEXTO VOY A ENENDER LO SPC$"

SapphireGym_Text_FirstPC:
	.string "1 PC$"

SapphireGym_Text_SecondPC:
	.string "2 PC$"

SapphireGym_Text_ThirdPC:
	.string "3 PC$"

SapphireGym_Text_SecondPuzzleGirlIntro:
	.string "HOLA LUCHA SPG$"

SapphireGym_Text_SecondPuzzleGirlLose:
	.string "SPG LOSE$"

SapphireGym_Text_SecondPuzzleGirlDefeated:
	.string "SPG DEFEATED$"

SapphireGym_Text_ThirdPuzzleGirl_Sleep:
	.string "Z Z Z Z Z SZ$"

SapphireGym_Text_ThirdPuzzleZigza:
	.string "ZIGZA START$"

SapphireGym_Text_ThirdPuzzle_GuessWhoFailed:
	.string "TEXTO ZIGZA ADIVINA$"

SapphireGym_Text_YouWonThirdPuzzle:
	.string "YOU WON ZIGZA$"

SapphireGym_Text_ThirdPuzzleGirl_YouBeatPuzzle:
	.string "YOU BEAT PUZLE TEXT 3$"

SapphireGym_Text_ThirdPuzzleGirlIntro:
	.string "TPG INTRO$"

SapphireGym_Text_ThirdPuzzleGirlLose:
	.string "TPG LOSE$"

SapphireGym_Text_ThirdPuzzleGirlDefeated:
	.string "TPG DEFEAT$"

SapphireGym_Text_FourthPuzzle_Explain:
	.string "EXPLAIN FOURTH PUZZLE$"

SapphireGym_Text_FourthPuzzle_GuessWhoFailed:
	.string "GUESS FOURTH PUZZLE$"

SapphireGym_Text_YouWonFourthPuzzle:
	.string "YOU WON FOURTH PUZZLE$"

SapphireGym_Text_FourthPuzzleGirlIntro:
	.string "FPG INTRO$"

SapphireGym_Text_FourthPuzzleGirlLose:
	.string "FPG LOSE$"

SapphireGym_Text_FourthPuzzleGirl_Defeated:
	.string "FPG DEFEATED$"

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
	setmetatile 22, 19, 0x2DA, 0
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
    playse SE_PIN
    applymovement 3, Common_Movement_ExclamationMark
    waitmovement 0
	applymovement 3, SapphireGym_Movement_MoveFirstPuzzleGirl
	waitmovement 0
	trainerbattle_single TRAINER_SAPPH_GYM_1, SapphireGym_Text_FirstPuzzleGirlIntro, SapphireGym_Text_FirstPuzzleGirlLose, SapphireGym_EventScript_FirstPuzzleGirlDefeated, NO_MUSIC
	release
	end

SapphireGym_Trigger_FightSecondPuzzleGirl::
	lock
    playse SE_PIN
    applymovement 1, Common_Movement_ExclamationMark
    waitmovement 0
	applymovement 1, SapphireGym_Movement_MoveSecondPuzzleGirl
	waitmovement 0
	trainerbattle_single TRAINER_SAPPH_GYM_2, SapphireGym_Text_SecondPuzzleGirlIntro, SapphireGym_Text_SecondPuzzleGirlLose, SapphireGym_EventScript_SecondPuzzleGirlDefeated, NO_MUSIC
	release
	end

SapphireGym_Trigger_FightThirdPuzzleGirl::
	lock
    playse SE_PIN
    applymovement 6, Common_Movement_ExclamationMark
    waitmovement 0
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
	compare VAR_RESULT, 3
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

SapphireGym_EventScript_PC::
    msgbox SapphireGym_Text_PC, MSGBOX_SIGN
    end

SapphireGym_Text_PC:
	.string "Hay abierto un archivo...\p"
	.string "“Investigación sobre el monstruo del\n"
	.string "sótano.”\p"
	.string "“El monstruo del sótano es muy\n"
	.string "poderoso pero, tras varios\l"
	.string "acercamientos hemos conseguido\l"
	.string "obtener la siguiente información:”\p"
	.string "“TIPO: LUCHA\n"
	.string "HP: MÁXIMO\p"
	.string "ATTACK: MUY ALTO\n"
	.string "DEFENSE: ALTO\p"
	.string "SP. ATTACK: ALTO\n"
	.string "SP. DEFENSE: MEDIO\p"
	.string "SPEED: MUY BAJO\n"
	.string "HABILIDAD: STRONG JAW\p"
	.string "Parece conocer algunos de los\n"
	.string "movimientos creados por MICOLO...”$"

SapphireGym_EventScript_FourthPuzzle_FightRandom:
	msgbox SapphireGym_Text_YouFailedFourthPuzzle, MSGBOX_NPC
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
	call SapphireGym_EventScript_StartFourthPuzzle_Iteration0
	call SapphireGym_EventScript_StartFourthPuzzle_Iteration1
	call SapphireGym_EventScript_StartFourthPuzzle_Iteration2
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

SapphireGym_EventScript_StartFourthPuzzle_Iteration0:
	msgbox SapphireGym_Text_FourthPuzzleIteration0, MSGBOX_NPC

	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideMew
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HidePoochyena
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideZigzagoon
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideKirlia
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HidePoochyena
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideKirlia
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideMew
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideMew
	return

SapphireGym_Text_FourthPuzzleIteration0:
	.string "¡Primera iteración!$"

SapphireGym_EventScript_StartFourthPuzzle_Iteration1:
	msgbox SapphireGym_Text_FourthPuzzleIteration1, MSGBOX_NPC

	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideMew
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideKirlia
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideKirlia
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideKirlia
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HidePoochyena
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideKirlia
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideKirlia
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideZigzagoon
	return

SapphireGym_Text_FourthPuzzleIteration1:
	.string "¡Segunda iteración!$"

SapphireGym_EventScript_StartFourthPuzzle_Iteration2:
	msgbox SapphireGym_Text_FourthPuzzleIteration2, MSGBOX_NPC

	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideZigzagoon
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideMew
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideZigzagoon
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideZigzagoon
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HidePoochyena
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideZigzagoon
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideKirlia
	call SapphireGym_EventScript_ExecuteFourthPuzzle_HideMew
	return

SapphireGym_Text_FourthPuzzleIteration2:
	.string "¡Tercera iteración!$"



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
	compare VAR_RESULT, 1
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
	playbgm MUS_TEST3, 0
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
	call SapphireGym_EventScript_StartFirstPuzzle_Iteration0
	call SapphireGym_EventScript_StartFirstPuzzle_Iteration1
	call SapphireGym_EventScript_StartFirstPuzzle_Iteration2
	
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
	msgbox SapphireGym_Text_YouFailedSecondPuzzle, MSGBOX_NPC
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
	msgbox SapphireGym_Text_ThirdPuzzleGirl_Awaken, MSGBOX_NPC
	release
	end

SapphireGym_EventScript_ThirdPuzzleGirl_Sleep:
	msgbox SapphireGym_Text_ThirdPuzzleGirl_Sleep, MSGBOX_NPC
	release
	end

SapphireGym_EventScript_ThirdPuzzleZigza::
	lock
	faceplayer
	msgbox SapphireGym_Text_ThirdPuzzleZigza, MSGBOX_YESNO
    compare VAR_RESULT, NO
    goto_if_eq SapphireGym_EventScript_ThirdPuzzleZigzaNo
	closemessage
	call SapphireGym_EventScript_StartThirdPuzzle
	msgbox SapphireGym_Text_ThirdPuzzle_GuessWhoFailed, MSGBOX_NPC
	multichoicegrid 0, 0, MULTI_SAPPHGYM_SECOND_PUZZLE_ANSWERS, 1, 1
	compare VAR_RESULT, 1
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

SapphireGym_EventScript_ThirdPuzzleZigzaNo:
    msgbox SapphireGym_Text_ThirdPuzzleZigzaNo, MSGBOX_NPC
    release
    end

SapphireGym_Text_ThirdPuzzleZigzaNo:
    .string "¿Ziig?$"

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
	msgbox SapphireGym_Text_YouFailedThirdPuzzle, MSGBOX_NPC
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
	.string "¡ZIGZAAAA!$"

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
	.string "¡ZIGZAAAAA!$"

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
	.string "¡ZIGZAAA!$"



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
	.string "¡Primera iteración!$"

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
	applymovement 13, SapphireGym_Movement_SecondPuzzleIteration1Failed
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

SapphireGym_Movement_SecondPuzzleIteration1Failed:
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
	walk_up
	delay_16
	walk_right
	delay_16
	walk_left
	delay_16
	walk_down
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
	.string "¡Segunda iteración!$"

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
	.string "¡Tercera iteración!$"


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
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	walk_up
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	walk_down
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SapphireGym_Text_Iteration0:
	.string "Pon atención. Ellos se moverán uno\n"
	.string "después del otro. El primero, hará unos\l"
	.string "movimientos, luego el segundo imitará\l"
	.string "esos movimientos, y a continuación el\l"
	.string "tercero, también imitará los\l"
	.string "movimientos del anterior, después de\l"
	.string "todo es una coreografía, ¿entiendes?\p"
	.string "Debes poner mucha atención a sus\n"
	.string "movimientos. Una vez que los 3 hayan\l"
	.string "danzado, volverán a comenzar y así un\l"
	.string "par de veces.\p"
	.string "Finalmente yo te haré una pregunta y tú\n"
	.string "debes contestarla correctamente para\l"
	.string "que te permita pasar.\p"
	.string "Muy bien, ¡que comience la función!$"

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
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	walk_down
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	walk_up
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SapphireGym_Text_Iteration1:
	.string "¡Segunda iteración!$"

SapphireGym_EventScript_StartFirstPuzzle_Iteration2:
	msgbox SapphireGym_Text_Iteration2, MSGBOX_NPC

	applymovement 7, SapphireGym_Movement_Iteration2
	waitmovement 0
	// Se equivoca ZIGZAGOON
	applymovement 9, SapphireGym_Movement_Iteration2Failed
	waitmovement 0
	applymovement 8, SapphireGym_Movement_Iteration2
	waitmovement 0

	return

SapphireGym_Movement_Iteration2:
	face_right
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	walk_up
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	walk_down
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	walk_up
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	walk_down
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SapphireGym_Movement_Iteration2Failed:
	face_right
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	walk_up
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	walk_left
	delay_16
	delay_16
	walk_down
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	walk_up
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	walk_down
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

SapphireGym_Text_Iteration2:
	.string "¡Tercera iteración!$"


SapphireGym_EventScript_FirstPuzzle_OpenPath:
	playse SE_W153
	waitse
	special DoSealedChamberShakingEffect1
	waitstate
	delay 40
	playse SE_DOOR
	delay 40
	call SapphireGym_OpenFirsPuzzlePath
	playse SE_RG_W_DOOR
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
	
SapphireGym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_DEFEATED_BOSS_TITAN, SapphireGym_EventScript_GymStatueCertified
	goto SapphireGym_EventScript_GymStatue
	end

SapphireGym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_DEFEATED_BOSS_TITAN, SapphireGym_EventScript_GymStatueCertified
	goto SapphireGym_EventScript_GymStatue
	end

SapphireGym_EventScript_GymStatueCertified::
	msgbox SapphireGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SapphireGym_EventScript_GymStatue::
	msgbox SapphireGym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SapphireGym_Text_GymExplanation:
	.string "Saludos, visitante, te doy la\n"
	.string "bienvenida. Supongo que viniste a ver\l"
	.string "el espectáculo de las idols.\n"
	.string "...\p"
	.string "Oh, entiendo, pero no te preocupes, te\n"
	.string "explicaré.\p"
	.string "Este es un gimnasio compuesto por\n"
	.string "idols. Ellas aman la música y sobretodo\l"
	.string "les gusta armar coreografías, así que\l"
	.string "si quieres que te dejen pasar, primero\l"
	.string "tendrás que demostrarles que tienes\l"
	.string "talento. Quien sabe, quizás te pongan a\l"
	.string "prueba, je, je.\p"
	.string "En cualquier caso, si logras llegar al\n"
	.string "final, podrás conocer a SAPPHIRE, la\l"
	.string "líder de este gimnasio, aunque la\l"
	.string "verdad no sé si ella esté dispuesta a\l"
	.string "recibirte sabes, ha estado muy ocupada\l"
	.string "últimamente. Al parecer, algo muy grave\l"
	.string "está sucediendo al final del gimnasio y\l"
	.string "andan todas con los nervios de punta.\p"
	.string "Claro que si pudieras ver que está\n"
	.string "sucediendo, y lograras tranquilizarlas,\l"
	.string "te lo agradecería.$"

SapphireGym_Text_GymExplanation_DefeatedSapph:
	.string "Muchas gracias, lograste tranquilizar a\n"
	.string "las idols, eres increíble. Esa medalla\l"
	.string "te queda muy bien.$"

SapphireGym_Text_FirstPuzzle_Explain:
	.string "Algo extraño está sucediendo al final\n"
	.string "del gimnasio y la líder SAPPHIRE ha\l"
	.string "cancelado los espectáculos mientras\l"
	.string "no se soluciona ese problema. Qué\l"
	.string "desgracia, pero no importa,\l"
	.string "aprovecharé este tiempo para ensayar\l"
	.string "mis coreografías, así que tendré que\l"
	.string "pedirte que te retires.\p"
	.string "...\p"
	.string "¿Cómo?, ¿insistes en querer pasar?\n"
	.string "Está bien, te dejaré pasar, pero sólo si\l"
	.string "antes me ayudas con algo. Te explico.\p"
	.string "Le he enseñado unos movimientos de\n"
	.string "baile a mis POKéMON. Cuando ellos\l"
	.string "salgan de detrás de esas cortinas\l"
	.string "harán una coreografía y tú tendrás\l"
	.string "que poner mucha atención.\p"
	.string "Cuando acabe la coreografía, yo te haré\n"
	.string "una pregunta y tú deberás contestar\l"
	.string "correctamente.\p"
	.string "Espero que hayas entendido.\n"
	.string "¿Empezamos?$"

SapphireGym_Text_FirstPuzzle_Decline:
	.string "¡Entonces no me hagas perder el tiempo\n"
	.string "y vete a casa!$"

SapphireGym_Text_ShowZigzagoon:
	.string "Bien, comencemos.\p"
	.string "Primero, te presento a ¡ZIGZAGOON!$"

SapphireGym_Text_ShowPoochyena:
	.string "Y este es ¡POOCHYENA!$"

SapphireGym_Text_ShowMew:
    .string "A continuación, tenemos a ¡MEW!$"

SapphireGym_Text_FirstPuzzle_GuessWhoFailed:
	.string "Responde esta pregunta. ¿Cual de ellos\n"
	.string "se equivocó imitando al anterior?$"

SapphireGym_Text_YouFailed:
	.string "Si serás, ¡has fallado! No tienes\n"
	.string "talento para esto, así que recibirás un\l"
	.string "castigo.\p"
	.string "¡Guardia! ¡Enséñele la salida!$"

SapphireGym_Text_YouWon:
	.string "¡Correcto! ¡Veo que tienes muy buen ojo\n"
	.string "para esto! ¡Deberías intentar la\l"
	.string "coreografía!\p"
SapphireGym_Text_FirstPuzzle_Done:
	.string "En fin, puedes pasar, pero ten cuidado.\n"
	.string "Las demás idols quizás también quieran\l"
	.string "ponerte a prueba.$"

SapphireGym_Text_FirstPuzzleGirlIntro:
	.string "¡Espera un momento! ¡Lo pensé mejor y\n"
	.string "me parece que eso ha sido demasiado\l"
	.string "fácil! ¡En guardia!$"

SapphireGym_Text_FirstPuzzleGirlLose:
	.string "¡Al menos soy mejor que tú armando\n"
	.string "coreografías!$"

SapphireGym_Text_FirstPuzzleGirlDefeated:
	.string "Mm... quizás sí tienes talento musical.\n"
	.string "Adelante.$"

SapphireGym_Text_SecondPuzzle_Decline:
	.string "Está bien, cuando tengas todo\n" 
	.string "listo, regresa.\l"
	.string "Aquí te espero.$"

SapphireGym_Text_SecondPuzzle_Explain:
	.string "Ah... hola. Esto... ¿eres un fan? Oh,\n"
	.string "discúlpame, es que estoy algo nerviosa.\l"
	.string "Algo terrible ha sucedido y el\l"
	.string "espectáculo ha sido suspendido. Creo\l"
	.string "que tiene que ver con el incidente al\l"
	.string "final del gimnasio.\p"
	.string "...\p"
	.string "¿Cómo? ¿Quieres saber que incidente es\n"
	.string "ese? Lo siento, SAPPHIRE me dijo que no\l"
	.string "hablara de esto con nadie de afuera,\l"
	.string "pero puedes ir y preguntarle tú\l"
	.string "directamente. Claro que antes necesito\l"
	.string "que me ayudes con algo. Si me ayudas te\l"
	.string "dejaré pasar, ¿vale? Te explico. Me\l"
	.string "pidieron que ayudara con una\l"
	.string "coreografía, pero como no se me da bien\l"
	.string "improvisar, registré algunos datos en\l"
	.string "estos PCs para que no se me olvidaran.\l"
	.string "Así que mientras yo reviso los PCs,\l"
	.string "quiero que tú por favor, pongas\l"
	.string "atención a mis POKéMON. Ellos bailarán,\l"
	.string "uno tras uno, imitando al anterior.\l"
	.string "Cuando acaben, te haré una pregunta.\l"
	.string "Si contestas correctamente,\l"
	.string "te dejaré pasar. ¿De acuerdo?$"

SapphireGym_Text_SecondPuzzle_GuessWhoFailed:
	.string "Pregunta, ¿cuál grito no está\n"
	.string "registrado en ningún PC?$"

SapphireGym_Text_YouWonSecondPuzzle:
	.string "Tienes razón. Muchas gracias, me has\n"
	.string "ayudado.\p" 
SapphireGym_Text_SecondPuzzle_Done:
    .string "Puedes pasar si quieres, pero\n"
	.string "ten cuidado.$"

SapphireGym_Text_YouFailedSecondPuzzle:
	.string "Ay no, fallaste. Que desgracia. ¡¿Eh?!...\n"
	.string "¡Oye, detrás de ti! ¡Un fan furioso te\l"
	.string "quiere atacar!$"

SapphireGym_Text_ShowZigzagoon2:
    .string "Comencemos. Este es ZIGZAGOON.$"

SapphireGym_Text_ShowPoochyena2:
	.string "El segundo es POOCHYENA.$"

SapphireGym_Text_ShowMew2:
	.string "A continuación, MEW.$"

SapphireGym_Text_ShowKirlia:
	.string "Y finalmente, KIRLIA.$"

SapphireGym_Text_SecondPuzzlePowerOnPCs:
	.string "Muy bien, eso es todo. Ahora yo voy a\n"
	.string "encender los PCs. Pon mucha atención.$"

SapphireGym_Text_FirstPC:
	.string "¡Enciendo el primer PC!$"

SapphireGym_Text_SecondPC:
	.string "¡Enciendo el segundo PC!$"

SapphireGym_Text_ThirdPC:
	.string "¡Enciendo el tercer PC!$"

SapphireGym_Text_SecondPuzzleGirlIntro:
	.string "Oye, espera. ¿Me podrías ayudar con\n"
	.string "algo más?$"

SapphireGym_Text_SecondPuzzleGirlLose:
	.string "Vale, me volviste a ayudar.$"

SapphireGym_Text_SecondPuzzleGirlDefeated:
	.string "Este gimnasio es muy acogedor, me\n"
	.string "siento a gusto aquí.$"

SapphireGym_Text_ThirdPuzzleGirl_Sleep:
	.string "Zzz...$"

SapphireGym_Text_ThirdPuzzleZigza:
SapphireGym_Text_ThirdPuzzleGirl_YouBeatPuzzle:
	.string "Zigzaa...\n"
	.string "...\p"
	.string "...\n"
	.string "...\p"
	.string "Zigzaa...$"

SapphireGym_Text_ThirdPuzzle_GuessWhoFailed:
	.string "¿Zigza... Zigzagoooon...?$"

SapphireGym_Text_YouFailedThirdPuzzle:
    .string "Zig...$"

SapphireGym_Text_YouWonThirdPuzzle:
	.string "¡ZIGZAGOON!$"

SapphireGym_Text_ThirdPuzzleGirlIntro:
	.string "Ajum... ¡oye! ¡Me quedé dormida!\n"
	.string "Ay, ¡¿cómo se te ocurre hacer la prueba\l"
	.string "sin mí?!$"

SapphireGym_Text_ThirdPuzzleGirlLose:
	.string "No creas que esto es todo.$"

SapphireGym_Text_ThirdPuzzleGirlDefeated:
SapphireGym_Text_ThirdPuzzleGirl_Awaken:
	.string "Como el espectáculo se suspendió, ando\n"
	.string "un poco deprimida...\p"
	.string "... y me quedé dormida a causa de eso.\n"
	.string "Como sea, yo creo que lo del incidente\l"
	.string "del gimnasio son sólo patrañas.$"


SapphireGym_Text_FourthPuzzle_Explain:
	.string "Te doy la bienvenida. Como te habrás\n"
	.string "dado cuenta las tres chicas de antes\l"
	.string "te pusieron a prueba.\p"
	.string "Habiéndose suspendido el espectáculo\n"
	.string "de idols, no nos queda más remedio que\l"
	.string "armar otro espectáculo, con los\l"
	.string "aspirantes que creen que pueden\l"
	.string "atravesar este gimnasio.\p"
	.string "Desgraciadamente, lo del incidente de\n"
	.string "este gimnasio no es mentira. Algo\l"
	.string "terrible ha sucedido al final del\l"
	.string "gimnasio que nos tiene muy asustadas.\p"
	.string "...\p"
	.string "Si esa... cosa... sigue ahí, no sé que\n"
	.string "vamos a hacer... ains...\p"
	.string "¿Quieres verlo? No te\n"
	.string "dejaré pasar a menos que me\l"
	.string "demuestres que eres capaz de\l"
	.string "afrontar el desafío. Así es, aquí\l"
	.string "comienza tu prueba.$"

SapphireGym_Text_FourthPuzzle_GuessWhoFailed:
	.string "Dime, ¿cuál es el POKéMON que más veces\n"
	.string "se arrojó al vacío?$"

SapphireGym_Text_YouWonFourthPuzzle:
	.string "¡Está correcto! Tus sentidos están\n"
	.string "despiertos, así que puedes pasar.$"

SapphireGym_Text_YouFailedFourthPuzzle:
	.string "Incorrecto. Si aún quieres pasar, no\n"
	.string "tengo opción.\p"
	.string "¡Activar holograma!$"

SapphireGym_Text_FourthPuzzleGirlIntro:
	.string "¡Esta será la verdadera prueba musical!$"

SapphireGym_Text_FourthPuzzleGirlLose:
	.string "It's a Project Diva!$"

SapphireGym_Text_FourthPuzzleGirl_Defeated:
	.string "Siguiendo derecho por aquí,\n"
	.string "encontrarás a la líder SAPPHIRE y\l"
	.string "también conocerás la verdad sobre\l"
	.string "este gimnasio, pero antes, una prueba\l"
	.string "más tendrás que superar.\p"
	.string "Ten mucho cuidado, algo terrible está\n"
	.string "sucediendo. Dicen que el incidente del\l"
	.string "gimnasio está relacionado con ese tal\l"
	.string "MICOLO al que todos adoran por estas\l"
	.string "zonas.\p"
	.string "Pero ese no es mi asunto. Nosotras las\n"
	.string "idols estamos aquí sólo porque fuimos\l"
	.string "invocadas por la líder SAPPHIRE, el\l"
	.string "resto no nos incumbe.$"
	
SapphireGym_Text_GymStatue:
    .string "POKEMON GYM Nº2\n"
    .string "LEADER: SAPPHIRE\l"
    .string "“TEMÁTICA: BURBUJA RÍTMICA”$"

SapphireGym_Text_GymStatueCertified:
    .string "POKEMON GYM Nº2\n"
    .string "LEADER: SAPPHIRE\l"
    .string "“TEMÁTICA: BURBUJA RÍTMICA”\p"

    .string "SAPPHIRE'S CERTIFIED TRAINERS:\n"
    .string "{PLAYER}$"


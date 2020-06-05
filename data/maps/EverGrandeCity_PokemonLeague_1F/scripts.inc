EverGrandeCity_PokemonLeague_1F_MapScripts:: @ 82295D2
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonLeague_1F_OnTransition: @ 82295DD
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_2
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor:: @ 82295ED
	setobjectxyperm 3, 9, 2
	setobjectxyperm 4, 10, 2
	return

@ VAR_0x800B is the Nurse's object event id
EverGrandeCity_PokemonLeague_1F_EventScript_Nurse:: @ 82295FC
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_Clerk:: @ 822960A
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EverGrandeCity_PokemonLeague_1F_Pokemart: @ 8229624
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

@ The door guards only check for FLAG_BADGE06_GET because Winonas badge is the only one that can be skipped
@ Its assumed the player has the remaining badges
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard:: @ 8229636
	lockall
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GoForth
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 11
	call_if_ge EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight
	compare VAR_TEMP_0, 8
	call_if_le EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft
	message EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
	waitmessage
	delay 120
	goto_if_unset FLAG_BADGE06_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	closemessage
	applymovement 3, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
	applymovement 4, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
	waitmovement 0
	delay 10
	playfanfare MUS_ME_BACHI
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
	waitmessage
	waitfanfare
	closemessage
	copyobjectxytoperm 3
	copyobjectxytoperm 4
	setflag FLAG_ENTERED_ELITE_FOUR
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight:: @ 8229698
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft:: @ 82296A3
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges:: @ 82296AE
	playse SE_HAZURE
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GoForth:: @ 82296BB
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight: @ 82296DA
	walk_down
	walk_left
	walk_in_place_fastest_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft: @ 82296DE
	walk_down
	walk_right
	walk_in_place_fastest_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay: @ 82296E2
	walk_left
	walk_in_place_fastest_down
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay: @ 82296E5
	walk_right
	walk_in_place_fastest_down
	step_end
	
Ryu_StartRandomBattle::
	special HealPlayerParty
	setflag FLAG_RYU_RANDOMBATTLE
	msgbox StartingRandomBattleMsg
	//cleartrainerflag TRAINER_RANDOM_PARTY
	//trainerbattle_single TRAINER_RANDOM_PARTY, BF_battleintro, BF_battledefeat, BF_RandomBattleCleanup
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq BF_RandomBattleCleanupDRAW
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq BF_RandomBattleCleanupWIN
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq BF_RandomBattleCleanupLOSS
	end

StartingRandomBattleMsg:
	.string "Starting Random Battle...$"

BF_RandomBattleCleanupWIN::
	special HealPlayerParty
	msgbox Enhorabuena, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Ryu_StartRandomBattle
	clearflag FLAG_RYU_RANDOMBATTLE
	release
	end
	
BF_RandomBattleCleanupLOSS::
	special HealPlayerParty
	msgbox BattleAgain, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Ryu_StartRandomBattle
	clearflag FLAG_RYU_RANDOMBATTLE
	release
	end
	
BF_RandomBattleCleanupDRAW::
	special HealPlayerParty
	msgbox Empate, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Ryu_StartRandomBattle
	clearflag FLAG_RYU_RANDOMBATTLE
	release
	end
	
BF_NoBattle::
	msgbox BF_NoBattleMsg
	closemessage
	release
	end
	
Ryu_StartRandomBattleCC::
    special SavePlayerParty
	setflag FLAG_RYU_RANDOMBATTLECC
	msgbox StartingRandomBattleMsg
	//cleartrainerflag TRAINER_RANDOM_PARTY
	//trainerbattle_single TRAINER_RANDOM_PARTY, BF_battleintro, BF_battledefeat, BF_RandomBattleCleanupCC
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq BF_RandomBattleCleanupDRAWCC
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq BF_RandomBattleCleanupWINCC
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq BF_RandomBattleCleanupLOSSCC
	end

BF_RandomBattleCleanupWINCC::
	special LoadPlayerParty
	msgbox Enhorabuena, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Ryu_StartRandomBattleCC
	clearflag FLAG_RYU_RANDOMBATTLECC
	release
	end
	
BF_RandomBattleCleanupLOSSCC::
	special LoadPlayerParty
	msgbox BattleAgain, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Ryu_StartRandomBattleCC
	clearflag FLAG_RYU_RANDOMBATTLECC
	release
	end
	
BF_RandomBattleCleanupDRAWCC::
	special LoadPlayerParty
	msgbox Empate, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Ryu_StartRandomBattleCC
	clearflag FLAG_RYU_RANDOMBATTLECC
	release
	end
	
BF_NoBattleCC::
	msgbox BF_NoBattleMsg
	closemessage
	release
	end

BattleAgain:
	.string "Would you like to battle again?$"
	
Enhorabuena:
	.string "Ganaste, te llevas este premio$"
	
Empate:
	.string "Hemos empatado ¿Repetimos?$"
	
BF_NoBattleMsg:
    .string "Very well. Talk with me again if\n"
    .string "you change your mind!$"

BF_Starting:
    .string "Hold on... Let me put your party\n"
    .string "aside...\p"
    .string "... ... ... ...\n"
    .string "... ... ... ...\p"
    .string "There. All set... Here we go!$"

BF_RandomIntro:
    .string "Selene: Hi! I like to do random\n"
    .string "battles.\p"
    .string "Would you like to battle with me?$"

BF_battleintro:
	.string "I will try my very hardest to win!$"
	
BF_battledefeat:
	.string "Good fight.\nLet's do it again!$"

EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges: @ 82296E8
	.string "Beyond this point, only those TRAINERS\n"
	.string "who have collected all the GYM BADGES\l"
	.string "are permitted to enter.\p"
	.string "TRAINER, let us confirm that you have\n"
	.string "all the GYM BADGES.$"

EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges: @ 8229787
	.string "You haven't obtained all the BADGES.\p"
	.string "If you're bound for the POKéMON\n"
	.string "LEAGUE, you must return with them.$"

EverGrandeCity_PokemonLeague_1F_Text_GoForth: @ 82297EF
	.string "TRAINER! Believe in yourself and your\n"
	.string "POKéMON, and go forth!$"


LilycoveCity_MapScripts:: @ 81E2B3C
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition: @ 81E2B47
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad: @ 81E2B61
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles:: @ 81E2B6B
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, 1
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, 1
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, 1
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, 1
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, 1
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, 1
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, 1
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, 1
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, 1
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, 1
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, 1
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, 1
	return

LilycoveCity_EventScript_BerryGentleman:: @ 81E2BD8
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry:: @ 81E2C18
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3:: @ 81E2C22
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl:: @ 81E2C2B
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone:: @ 81E2C40
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy:: @ 81E2C4A
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2:: @ 81E2C53
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone:: @ 81E2C68
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2:: @ 81E2C72
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone:: @ 81E2C87
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2:: @ 81E2C91
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1:: @ 81E2C9A
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF:: @ 81E2CA3
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2:: @ 81E2CAC
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone:: @ 81E2CC1
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1:: @ 81E2CCB
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan:: @ 81E2CD4
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1:: @ 81E2CDD
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement 20, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1:: @ 81E2CEE
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement 19, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign:: @ 81E2CFF
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign:: @ 81E2D08
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign:: @ 81E2D11
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign:: @ 81E2D1A
	lockall
	specialvar VAR_0x8004, CountPlayerContestPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings:: @ 81E2D3A
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign:: @ 81E2D44
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady:: @ 81E2D58
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign:: @ 81E2D62
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign:: @ 81E2D6B
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt:: @ 81E2D7D
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer:: @ 81E2DB0
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1:: @ 81E2DBA
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2:: @ 81E2DC3
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3:: @ 81E2DCC
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4:: @ 81E2DD5
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end
	
LilycoveCity_EventScript_RivalTrigger0:: @ 81E0DF3
	lockall
	applymovement 17, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement 17, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 17, Common_Movement_Delay48
	waitmovement 0
	applymovement 17, LilycoveCity_Movement_RivalApproachPlayer0
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	goto LilycoveCity_EventScript_Rival
	
LilycoveCity_EventScript_RivalTrigger1:: @ 81E0DF3
	lockall
	applymovement 17, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	playse SE_PIN
	applymovement 17, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 17, Common_Movement_Delay48
	waitmovement 0
	applymovement 17, LilycoveCity_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	goto LilycoveCity_EventScript_Rival
	
LilycoveCity_Movement_RivalApproachPlayer0: @ 81E120E
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down	
	step_end
	
LilycoveCity_Movement_RivalApproachPlayer1: @ 81E120E
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

LilycoveCity_EventScript_Rival:: @ 81E2DDE
	lock
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LilycoveCity_EventScript_May
	compare VAR_RESULT, FEMALE
	goto_if_eq LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May:: @ 81E2DF8
	playbgm MUS_GIRL_SUP, 1
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattle:: @ 81E2E51
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_Brendan:: @ 81E2E6B
	playbgm MUS_BOY_SUP, 1
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattle:: @ 81E2EC4
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BattleMayTreecko:: @ 81E2EDE
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic:: @ 81E2EEE
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip:: @ 81E2EFE
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko:: @ 81E2F0E
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic:: @ 81E2F1E
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip:: @ 81E2F2E
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay:: @ 81E2F3E
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalGivesUpgradeAndFliesAway
	end

LilycoveCity_EventScript_DefeatedBrendan:: @ 81E2FAA
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalGivesUpgradeAndFliesAway
	end

LilycoveCity_EventScript_RivalGivesUpgradeAndFliesAway:
	msgbox LilycoveCity_Text_RivalUpgradeMusicPlayer, MSGBOX_DEFAULT
	playse SE_TK_KASYA
	delay 10
	playfanfare MUS_FANFA4
	msgbox IzabeIsland_OutskirtsCave_Text_Lavender_MusicPlayerUpgraded, MSGBOX_DEFAULT
	waitfanfare
	setvar VAR_MUSIC_PLAYER, MUSIC_PLAYER_STATE_LILYCOVE
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_RivalFlyAway:: @ 81E3006
	closemessage
	applymovement 17, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject 17
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	setvar VAR_RIVAL_LILYCOVE_CITY, 1
	release
	end

LilycoveCity_EventScript_SchoolKidM:: @ 81E302D
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq LilycoveCity_EventScript_KnowAboutBerryBlender
	compare VAR_RESULT, NO
	call_if_eq LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end
	
LilycoveCity_EventScript_MelkorHouseSign::
	msgbox LilycoveCity_Text_MelkorHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_KnowAboutBerryBlender:: @ 81E304F
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender:: @ 81E3058
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle: @ 81E3061
	.string "{RIVAL}: Oh, hey?\n"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
	.string "I bought a whole bunch of DOLLS and\n"
	.string "POSTERS.\p"
	.string "Of course, I've also caught a lot of\n"
	.string "POKéMON, and I'm raising them\l"
	.string "properly, too.\p"
	.string "Actually, I'm more worried if you're\n"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
	.string "I'll battle with you, so you can show\n"
	.string "me your POKéMON, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayWontBeBeaten: @ 81E3234
	.string "The POKéMON I raised won't be\n"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat: @ 81E3275
	.string "… … … … … … … …\p"
	.string "I remember the battle I had with you,\n"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
	.string "That battle helped you become this\n"
	.string "strong, {PLAYER}{KUN}, didn't it?$"

LilycoveCity_Text_MayGoingBackToLittleroot: @ 81E32FB
	.string "{RIVAL}: I'm thinking of going back to\n"
	.string "LITTLEROOT soon.\p"
	.string "I've caught a decent group of POKéMON,\n"
	.string "and my POKéDEX is coming along, so\l"
	.string "I'm going home to show my dad.$"

LilycoveCity_Text_BrendanShoppingLetsBattle: @ 81E3608
	.string "{RIVAL}: Oh, hey, it's {PLAYER}.\p"
	.string "I'm running an errand for my dad.\n"
	.string "No, I'm not buying any DOLLS.\p"
	.string "Anyways, it's been a while.\p"
	.string "Want to have a battle to see who's been\n"
	.string "raising POKéMON better?$"

LilycoveCity_Text_BrendanWontBeBeaten: @ 81E373C
	.string "Aww, but you know I'm not\n"
	.string "going to lose to no {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat: @ 81E3777
	.string "Humph…\n"
	.string "You've done a lot of raising.\p"
	.string "That stings a bit--I had a head start\n"
	.string "on you as a TRAINER…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot: @ 81E37D7
	.string "{RIVAL}: I…\n"
	.string "I plan on going home to LITTLEROOT.\p"
	.string "You know I'm helping out my dad on his\n"
	.string "POKéDEX. It's coming together pretty\l"
	.string "decently, so I should go show him.$"

LilycoveCity_Text_MovedLootIntoHideoutToday: @ 81E3B2C
	.string "Fufufu…\p"
	.string "We moved more loot into our secret\n"
	.string "HIDEOUT today…\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"

LilycoveCity_Text_ChanceToDoBigThings: @ 81E3B95
	.string "I'm just a GRUNT, so I don't know what\n"
	.string "the BOSS is thinking…\p"
	.string "But being on TEAM AQUA, I know I'll get\n"
	.string "the chance to do big things!\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"

LilycoveCity_Text_DontGoNearCaveInCove: @ 81E3C46
	.string "Hey, you!\p"
	.string "Don't go near the cave in the cove!\p"
	.string "Why? You don't need a reason why!\n"
	.string "I'm an adult, so you just listen to me!$"

LilycoveCity_Text_IfWorldBecomesOurs: @ 81E3CBE
	.string "If this whole wide world becomes ours,\n"
	.string "TEAM AQUA's, it will be a happier\l"
	.string "place for POKéMON, too.$"

LilycoveCity_Text_WailmerLeapOutOfWater: @ 81E3D1F
	.string "There! WAILMER!\n"
	.string "Leap out of the water now!$"

LilycoveCity_Text_GetLostMessingUpTraining: @ 81E3D4A
	.string "Hunh? What do you want?\p"
	.string "You're messing up our training,\n"
	.string "so can you, like, get lost?$"

LilycoveCity_Text_ContestHallInTown: @ 81E3D9E
	.string "There's a POKéMON CONTEST HALL\n"
	.string "right in this here town. \p"
	.string "That means well-raised POKéMON will\n"
	.string "come from all over the country.\p"
	.string "My heart swells with excitement!$"

LilycoveCity_Text_StrangeCaveInCove: @ 81E3E3C
	.string "Have you seen that strange cave in\n"
	.string "the cove at the edge of town?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs: @ 81E3E7D
	.string "I'm going to teach my POKéMON some new\n"
	.string "moves for entering a CONTEST.\p"
	.string "So, I'm going to see the MOVE DELETER\n"
	.string "and make it forget HM moves.$"

LilycoveCity_Text_ImFromKanto: @ 81E3F05
	.string "I came from KANTO.\p"
	.string "The HOENN region is beautiful with\n"
	.string "all its water and verdant nature.\p"
	.string "Hunh? Wait a second…\p"
	.string "Could there be rare POKéMON that live\n"
	.string "only in this area?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer: @ 81E3FAB
	.string "TEAM AQUA's been training their\n"
	.string "WAILMER in the cove.\p"
	.string "We SAILORS can't get our boats out\n"
	.string "to sea with them in the way!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut: @ 81E4020
	.string "Ahoy, did you know?\p"
	.string "Someone punted TEAM AQUA out of\n"
	.string "the way for us!\p"
	.string "That got the WAILMER out of the cove,\n"
	.string "so we can get our boats out again.$"

LilycoveCity_Text_SomeoneStoleMyPokemon: @ 81E40AD
	.string "I was taking a relaxing snooze at the\n"
	.string "seaside inn to the sound of waves…\p"
	.string "When someone stole my POKéMON!\p"
	.string "Who's the abductor?\n"
	.string "TEAM AQUA? Is it TEAM AQUA?$"

LilycoveCity_Text_MissingPokemonCameBack: @ 81E4145
	.string "My missing POKéMON…\n"
	.string "It came back without me noticing!$"

LilycoveCity_Text_ImArtDealer: @ 81E417B
	.string "I'm an ART DEALER.\p"
	.string "I am a buyer and seller of fine art,\n"
	.string "especially paintings.\p"
	.string "I've heard that the MUSEUM here has\n"
	.string "magnificent works on exhibit…$"

LilycoveCity_Text_SeaRemainsForeverYoung: @ 81E420B
	.string "Even as we grow old and wrinkled,\n"
	.string "the sea remains forever young with\l"
	.string "the vivid brilliance of life…\p"
	.string "Fwohoho fwohohohoho…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed: @ 81E4283
	.string "It was sixty years ago that my husband\n"
	.string "proposed to me here.\l"
	.string "The sea remains as beautiful as ever.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern: @ 81E42FC
	.string "Hm, you know of the peculiar cavern\n"
	.string "in this cove?\p"
	.string "That had been a natural formation,\n"
	.string "but then that TEAM AQUA lot came\l"
	.string "along and made their renovations.\p"
	.string "They call themselves\n"
	.string "the “nature-loving TEAM AQUA”!\p"
	.string "But what they do and what they say\n"
	.string "don't match at all!$"

LilycoveCity_Text_TeamAquaLotGoneForGood: @ 81E43FF
	.string "That cave in the cove…\p"
	.string "I didn't notice it right away,\n"
	.string "but it's completely empty now.\p"
	.string "That TEAM AQUA lot, they must\n"
	.string "have gone away for good.$"

LilycoveCity_Text_CitySign: @ 81E448B
	.string "LILYCOVE CITY\p"
	.string "“Where the land ends and the\n"
	.string "sea begins.”$"

LilycoveCity_Text_ContestHallSign: @ 81E44C3
	.string "POKéMON CONTEST HALL\n"
	.string "“The gathering place for TRAINERS!”$"

LilycoveCity_Text_MotelSign: @ 81E44FC
	.string "COVE LILY MOTEL\p"
	.string "“Remember us as COVE LILY of\n"
	.string "LILYCOVE.”$"

LilycoveCity_Text_MuseumSign: @ 81E4534
	.string "LILYCOVE MUSEUM\p"
	.string "“POKéMON Masterpiece Collection\n"
	.string "on exhibit!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit: @ 81E4571
	.string "LILYCOVE MUSEUM\p"
	.string "“{PLAYER}'s POKéMON Collection\n"
	.string "on exhibit!”$"

LilycoveCity_Text_HarborSignUnderConstruction: @ 81E45A7
	.string "LILYCOVE CITY HARBOR\p"
	.string "“The ferry S.S. TIDAL is under\n"
	.string "construction in SLATEPORT CITY.\p"
	.string "“Service is scheduled to begin\n"
	.string "shortly.”$"

LilycoveCity_Text_HarborSign: @ 81E4624
	.string "LILYCOVE CITY HARBOR\p"
	.string "“Enjoy a delightful cruise on\n"
	.string "the ferry S.S. TIDAL.”$"

LilycoveCity_Text_TrainerFanClubSign: @ 81E466E
	.string "POKéMON TRAINER FAN CLUB\p"
	.string "The names of TRAINERS are scribbled\n"
	.string "all over the sign…$"

LilycoveCity_Text_DepartmentStoreSign: @ 81E46BE
	.string "LILYCOVE DEPARTMENT STORE\p"
	.string "“Overflowing with great merchandise\n"
	.string "and excitement!\p"
	.string "“A great place to find that something\n"
	.string "you need!”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender: @ 81E4774
	.string "Do you know about the machine\n"
	.string "BERRY BLENDER?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks: @ 81E47A1
	.string "People have to work together to get it\n"
	.string "to spin faster.\p"
	.string "The faster you can make it spin, the\n"
	.string "better {POKEBLOCK}S you can get, I've heard.$"

LilycoveCity_Text_ExplainBerryBlender: @ 81E4824
	.string "It's used for making a kind of candy\n"
	.string "called a {POKEBLOCK}.\p"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
	.string "its condition will improve by a lot.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar: @ 81E48A5
	.string "I heard there's a tower somewhere out\n"
	.string "on the sea routes.\p"
	.string "It's called the SKY PILLAR, I hear.$"

LilycoveCity_Text_SawTallTowerOnRoute131: @ 81E4902
	.string "I saw this tall tower somewhere\n"
	.string "around ROUTE 131.\p"
	.string "Could that possibly be…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon: @ 81E494D
	.string "We just arrived here on our\n"
	.string "honeymoon vacation.\p"
	.string "We happened to see a DRAGON-type\n"
	.string "POKéMON flying way up in the sky.\p"
	.string "Do cool POKéMON like that live in\n"
	.string "the HOENN region?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon: @ 81E49F4
	.string "On our honeymoon, we vowed to see as\n"
	.string "many rare POKéMON as we can.\p"
	.string "So we were delighted to see a rare\n"
	.string "POKéMON as soon as we arrived.\p"
	.string "I mean, we are totally happy!$"
	
LilycoveCity_Text_MelkorHouseSign:
	.string "CASA DE MELKOR\p"
	.string "Hay algo garabateado en una esquina\n"
	.string "del cartel...\p"
	.string "“MELKOR, PAGA EL SERVER”$"

LilycoveCity_Text_RivalUpgradeMusicPlayer:
	.string "By the way, {PLAYER}, have you been\n"
	.string "using the ITEMFINDER I gave you?\p"
	.string "I found an item on my way to LILYCOVE,\n"
	.string "but I think it's useless.\p"
	.string "Maybe you know how to use it, so take\n"
	.string "it!$"

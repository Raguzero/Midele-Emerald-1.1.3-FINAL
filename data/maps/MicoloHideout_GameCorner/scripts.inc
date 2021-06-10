MicoloHideout_GameCorner_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MicoloHideout_GameCorner_OnLoad
	.byte 0
  .set COINS_PRICE_50_MICOLO,  750
	.set COINS_PRICE_500_MICOLO, 7500

MicoloHideout_GameCorner_OnLoad:
	compare VAR_STATE_MICOLANDIA, 2
	call_if_lt MicoloHideout_GameCorner_CloseMicoloHideoutEntrance
	end

MicoloHideout_GameCorner_CloseMicoloHideoutEntrance:
	setmetatile 6, 0, METATILE_MauvilleGameCorner_CenteredUpperWall , 1
	setmetatile 6, 1, METATILE_MauvilleGameCorner_UpperGreenVendingMachine, 1
	setmetatile 6, 2, METATILE_MauvilleGameCorner_LowerGreenVendingMachine, 1
	setmetatile 7, 0, METATILE_MauvilleGameCorner_CenteredUpperWall , 1
	setmetatile 7, 1, METATILE_MauvilleGameCorner_UpperBlueVendingMachine, 1
	setmetatile 7, 2, METATILE_MauvilleGameCorner_LowerBlueVendingMachine, 1
	return

MicoloHideout_GameCorner_OpenMicoloHideoutEntrance:
	setmetatile 6, 0, METATILE_General_Upper_Door_Contest , 1
	setmetatile 6, 1, METATILE_General_Door_Contest, 1
	setmetatile 6, 2, METATILE_MauvilleGameCorner_NoShadowRedFloor, 0
	setmetatile 7, 0, METATILE_General_Upper_Door_Contest , 1
	setmetatile 7, 1, METATILE_General_Door_Contest, 1
	setmetatile 7, 2, METATILE_MauvilleGameCorner_NoShadowRedFloor, 0
	return

MicoloHideout_GameCorner_EventScript_PacochefJugando::
	lock
	msgbox MicoloHideout_GameCorner_EventScript_PacochefJugando_Text_0, MSGBOX_DEFAULT
	faceplayer
	msgbox MicoloHideout_GameCorner_EventScript_PacochefJugando_Text_1, MSGBOX_DEFAULT
    closemessage 
	applymovement 10, Common_Movement_FaceOriginalDirection
	return


MicoloHideout_GameCorner_EventScript_PacochefJugando_Text_0:
	.string "PACOCHEF: MUERE, MUERE, MUERE. PUTAS\n"
	.string "TRAGAPERRAS AMAÑADAS.$"

MicoloHideout_GameCorner_EventScript_PacochefJugando_Text_1:
	.string "...ah, eres tú. Dame un segundo,\n"
	.string "¿quieres? En seguida estoy contigo.\l"
	.string "¿¡CÓMO QUE PIERDES TU MONOCICLO,\l"
	.string "JUEGO INFERNAL?!$"

MicoloHideout_Sign_LaPapelera::
	lockall
	compare VAR_STATE_MICOLANDIA, 1
	goto_if_eq MicoloHideout_Sign_LaPapelera_2
	msgbox MicoloHideout_Sign_LaPapelera_Text_4, MSGBOX_SIGN
MicoloHideout_Sign_LaPapelera_1:
	releaseall
	return

MicoloHideout_Sign_LaPapelera_2:
	msgbox MicoloHideout_Sign_LaPapelera_Text_0, MSGBOX_SIGN
	waitmessage
	playse SE_HAZURE
	waitse
	applymovement 10, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 10, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 10, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 10, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	applymovement 10, Movement_Paco_Approach
	waitmovement 0
	msgbox MicoloHideout_Sign_LaPapelera_Text_1, MSGBOX_DEFAULT
	waitmessage
	applymovement EVENT_OBJ_ID_PLAYER, Movement_JugadorEmpujado
	applymovement 10, Movement_Paco_EmpujaJugador
	waitmovement 0
	msgbox MicoloHideout_Sign_LaPapelera_Text_2, MSGBOX_DEFAULT
	waitmessage
	playse SE_W026
	waitse
	playse SE_W153
	waitse
	playse SE_TRACK_MOVE
	special DoSealedChamberShakingEffect1
	waitstate
	delay 40
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_DOOR
	delay 40
	special DoSealedChamberShakingEffect2
	waitstate
	playse SE_DOOR
	delay 40
	call MicoloHideout_GameCorner_OpenMicoloHideoutEntrance
	playse(SE_RG_W_DOOR)
	special DrawWholeMapView
	msgbox MicoloHideout_Sign_LaPapelera_Text_3, MSGBOX_DEFAULT
	applymovement 10, Movement_Paco_Chau
	waitmovement 0
	playse SE_JIDO_DOA
	removeobject 10
	waitse
	setvar VAR_STATE_MICOLANDIA, 2
	goto MicoloHideout_Sign_LaPapelera_1


Movement_Paco_Approach:
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	step_end

Movement_JugadorEmpujado:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

Movement_Paco_EmpujaJugador:
	walk_up
	step_end

Movement_Paco_Chau:
	walk_right
	walk_up
	step_end

MicoloHideout_Sign_LaPapelera_Text_0:
	.string "It's empty.... no, wait, amigo. It's not\n"
	.string "empty.\p"
	.string "Parece haber algo al fondo de la\n"
	.string "papelera...$"

MicoloHideout_Sign_LaPapelera_Text_1:
    .string "PACOCHEF: Hey, sí, estoy tranquilo,\n"
	.string "déjame esa papelera un momento.$"

MicoloHideout_Sign_LaPapelera_Text_2:
    .string "UAAAAAAAAAGH ME CAGO EN SUS MUERTOS.\n"
	.string "MUDAMUDAMUDAMUDAMUDAMUDA.\l"
	.string "PACOPATADA$"

MicoloHideout_Sign_LaPapelera_Text_3:
	.string "...no debí beber tanto.$"

MicoloHideout_Sign_LaPapelera_Text_4:
	.string "La papelera ha quedado destruida...$"

MicoloHideout_GameCorner_EventScript_CoinsClerk:: @ 820FBB9
	lock
	faceplayer
	msgbox MicoloHideout_GameCorner_Text_ThisIsMicoloHideoutGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MicoloHideout_GameCorner_EventScript_NeedCoinCase
	message MicoloHideout_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0, 0
	showcoinsbox 1, 6
	goto MicoloHideout_GameCorner_EventScript_ChooseCoinsDefault50

MicoloHideout_GameCorner_EventScript_ChooseCoinsDefault50:: @ 820FBE5
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS_MIDELE, 0, 0
	switch VAR_RESULT
	case 0, MicoloHideout_GameCorner_EventScript_Buy50Coins
	case 1, MicoloHideout_GameCorner_EventScript_Buy500Coins
	goto MicoloHideout_GameCorner_EventScript_CancelBuyCoins
	end

MicoloHideout_GameCorner_EventScript_Buy50Coins:: @ 820FC33
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, MAX_COINS + 1 - 50
	goto_if_ge MicoloHideout_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50_MICOLO, 0
	compare VAR_RESULT, FALSE
	goto_if_eq MicoloHideout_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50_MICOLO, 0
	updatemoneybox 0, 0
	updatecoinsbox 1, 6
	playse SE_REGI
	msgbox MicoloHideout_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MicoloHideout_GameCorner_EventScript_Buy500Coins:: @ 820FC75
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, MAX_COINS + 1 - 500
	goto_if_ge MicoloHideout_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500_MICOLO, 0
	compare VAR_RESULT, FALSE
	goto_if_eq MicoloHideout_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500_MICOLO, 0
	updatemoneybox 0, 0
	updatecoinsbox 1, 6
	playse SE_REGI
	msgbox MicoloHideout_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MicoloHideout_GameCorner_EventScript_NeedCoinCase:: @ 820FCB7
	msgbox MicoloHideout_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

MicoloHideout_GameCorner_EventScript_NotEnoughMoney:: @ 820FCC1
	msgbox MicoloHideout_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MicoloHideout_GameCorner_EventScript_CancelBuyCoins:: @ 820FCD1
	msgbox MicoloHideout_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MicoloHideout_GameCorner_EventScript_NoRoomForCoins:: @ 820FCE1
	msgbox MicoloHideout_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

MicoloHideout_GameCorner_EventScript_MonPrizes::
	lock
	faceplayer
	msgbox MicoloHideout_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MicoloHideout_GameCorner_EventScript_MonPrizesFirst
  goto MicoloHideout_GameCorner_EventScript_NeedCoinCase
	release
	end

MicoloHideout_GameCorner_EventScript_MonPrizesFirst:
	message MicoloHideout_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 0, 0
	goto MicoloHideout_GameCorner_EventScript_MonPrizesList

MicoloHideout_GameCorner_EventScript_MonPrizesList:
  multichoice 12, 0, MULTI_GAME_CORNER_PKMN3, 0
  switch VAR_RESULT
	case 0, MicoloHideout_GameCorner_EventScript_DARK_PIKA_Confirm
	case 1, MicoloHideout_GameCorner_EventScript_WINTASS_Confirm
	case 2, MicoloHideout_GameCorner_EventScript_CATERMANO_Confirm
	goto MicoloHideout_GameCorner_EventScript_CancelDollSelect
	end

MicoloHideout_GameCorner_EventScript_DARK_PIKA_Confirm:
	setvar VAR_TEMP_1, 1
  bufferspeciesname 0, SPECIES_DARK_PIKACHU
	goto MicoloHideout_GameCorner_EventScript_MonConfirm

MicoloHideout_GameCorner_EventScript_WINTASS_Confirm:
	setvar VAR_TEMP_1, 2
  bufferspeciesname 0, SPECIES_WINTASS
	goto MicoloHideout_GameCorner_EventScript_MonConfirm

MicoloHideout_GameCorner_EventScript_CATERMANO_Confirm:
	setvar VAR_TEMP_1, 3
  bufferspeciesname 0, SPECIES_CATERPIE
	goto MicoloHideout_GameCorner_EventScript_MonConfirm

MicoloHideout_GameCorner_EventScript_MonConfirm:
	msgbox MicoloHideout_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MicoloHideout_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, MicoloHideout_GameCorner_EventScript_DARK_PIKA
	case 2, MicoloHideout_GameCorner_EventScript_WINTASS
	case 3, MicoloHideout_GameCorner_EventScript_CATERMANO
	end

MicoloHideout_GameCorner_EventScript_DARK_PIKA:
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 9000
	goto_if_lt MicoloHideout_GameCorner_EventScript_NoCoinsForMon
	getpartysize
	compare VAR_RESULT, 6
  goto_if_eq MicoloHideout_GameCorner_EventScript_NoRoom
	copyvar VAR_0x8004, VAR_RESULT
	removecoins 9000
	updatecoinsbox 0, 0
	playse SE_REGI
  waitse
	playfanfare MUS_FANFA4
	bufferspeciesname 0, SPECIES_DARK_PIKACHU
	message MicoloHideout_GameCorner_Text_GetMon
	waitfanfare
	waitmessage
	givemon SPECIES_DARK_PIKACHU, 90, ITEM_NONE
	bufferspeciesname 1, SPECIES_DARK_PIKACHU
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Common_EventScript_NameReceivedPartyMon
  goto MicoloHideout_GameCorner_EventScript_MonPrizesFirst

MicoloHideout_GameCorner_EventScript_WINTASS:
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 9000
	goto_if_lt MicoloHideout_GameCorner_EventScript_NoCoinsForMon
	getpartysize
	compare VAR_RESULT, 6
  goto_if_eq MicoloHideout_GameCorner_EventScript_NoRoom
	copyvar VAR_0x8004, VAR_RESULT
	removecoins 9000
	updatecoinsbox 0, 0
	playse SE_REGI
  waitse
	playfanfare MUS_FANFA4
	bufferspeciesname 0, SPECIES_WINTASS
	message MicoloHideout_GameCorner_Text_GetMon
	waitfanfare
	waitmessage
	givemon SPECIES_WINTASS, 90, ITEM_NONE
	bufferspeciesname 1, SPECIES_WINTASS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Common_EventScript_NameReceivedPartyMon
  goto MicoloHideout_GameCorner_EventScript_MonPrizesFirst

MicoloHideout_GameCorner_EventScript_CATERMANO:
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 9000
	goto_if_lt MicoloHideout_GameCorner_EventScript_NoCoinsForMon
	getpartysize
	compare VAR_RESULT, 6
  goto_if_eq MicoloHideout_GameCorner_EventScript_NoRoom
	copyvar VAR_0x8004, VAR_RESULT
	removecoins 9000
	updatecoinsbox 0, 0
	playse SE_REGI
  waitse
	playfanfare MUS_FANFA4
	bufferspeciesname 0, SPECIES_CATERPIE
	message MicoloHideout_GameCorner_Text_GetMon
	waitfanfare
	waitmessage
	givecustommon SPECIES_CATERPIE, 100, ITEM_NONE, ITEM_MASTER_BALL, NATURE_NAIVE, 0, 252, 252, 252, 252, 252, 252, 31, 31, 31, 31, 31, 31, MOVE_HORN_DRILL, MOVE_FISSURE, MOVE_MEGAHORN, MOVE_MIDELE_POWER, TRUE
	bufferspeciesname 1, SPECIES_CATERPIE
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Common_EventScript_NameReceivedPartyMon
  goto MicoloHideout_GameCorner_EventScript_MonPrizesFirst

MicoloHideout_GameCorner_EventScript_NoRoom:
	msgbox MicoloHideout_GameCorner_Text_NoRoom, 4
	hidecoinsbox 0, 0
	release
	end

MicoloHideout_GameCorner_EventScript_NoCoinsForMon:
	msgbox MicoloHideout_GameCorner_Text_DontHaveEnoughCoins, 4
	goto MicoloHideout_GameCorner_EventScript_MonPrizesList
	end

MicoloHideout_GameCorner_EventScript_CancelDollSelect:: @ 820FE92
	msgbox MicoloHideout_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

MicoloHideout_GameCorner_EventScript_SlotMachine:: @ 8210436
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

MicoloHideout_EventScript_VendingMachine::
	lockall
	message MicoloHideout_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0, 0
	goto MicoloHideout_EventScript_ChooseDrink
	end

MicoloHideout_EventScript_VendingMachine2::
	lockall
	compare VAR_STATE_MICOLANDIA, 1
	goto_if_eq MicoloHideout_EventScript_VendingMachine2_2
MicoloHideout_EventScript_VendingMachine2_1:
	end

MicoloHideout_EventScript_VendingMachine2_2:
	message MicoloHideout_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0, 0
	goto MicoloHideout_EventScript_ChooseDrink
	goto MicoloHideout_EventScript_VendingMachine2_1

MicoloHideout_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE_MIDELE, 0
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
  case 0, MicoloHideout_EventScript_SacredAsh
  case 1, MicoloHideout_EventScript_PPMax
  case 2, MicoloHideout_EventScript_Leftovers
  case 3, MicoloHideout_EventScript_FocusSash
	msgbox MicoloHideout_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto MicoloHideout_EventScript_ExitVendingMachine
	end

MicoloHideout_EventScript_SacredAsh::
	setvar VAR_TEMP_0, ITEM_SACRED_ASH
	goto MicoloHideout_EventScript_TryBuyDrink
	end

MicoloHideout_EventScript_Leftovers::
	setvar VAR_TEMP_0, ITEM_LEFTOVERS
	goto MicoloHideout_EventScript_TryBuyDrink
	end

MicoloHideout_EventScript_PPMax::
	setvar VAR_TEMP_0, ITEM_PP_MAX
	goto MicoloHideout_EventScript_TryBuyDrink
	end

MicoloHideout_EventScript_FocusSash::
	setvar VAR_TEMP_0, ITEM_FOCUS_SASH
	goto MicoloHideout_EventScript_TryBuyDrink
	end

MicoloHideout_EventScript_CheckMoneyLeftovers::
	checkmoney 15000, 0
	return

MicoloHideout_EventScript_CheckMoneyFocusSash::
	checkmoney 20000, 0
	return

MicoloHideout_EventScript_CheckMoneySacredAsh::
	checkmoney 9000, 0
	return

MicoloHideout_EventScript_CheckMoneyPPMax::
	checkmoney 12000, 0
	return

MicoloHideout_EventScript_RemoveMoneyLeftovers::
	removemoney 15000, 0
	return

MicoloHideout_EventScript_RemoveMoneyFocusSash::
	removemoney 20000, 0
	return

MicoloHideout_EventScript_RemoveMoneySacredAsh::
	removemoney 9000, 0
	return

MicoloHideout_EventScript_RemoveMoneyPPMax::
	removemoney 12000, 0
	return


MicoloHideout_EventScript_TryBuyDrink::
	compare VAR_TEMP_1, 0
	call_if_eq MicoloHideout_EventScript_CheckMoneyLeftovers
	compare VAR_TEMP_1, 1
	call_if_eq MicoloHideout_EventScript_CheckMoneyFocusSash
	compare VAR_TEMP_1, 2
	call_if_eq MicoloHideout_EventScript_CheckMoneySacredAsh
	compare VAR_RESULT, FALSE
	goto_if_eq MicoloHideout_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MicoloHideout_EventScript_NoRoomForDrink
	compare VAR_TEMP_1, 0
	call_if_eq MicoloHideout_EventScript_RemoveMoneyLeftovers
	compare VAR_TEMP_1, 1
	call_if_eq MicoloHideout_EventScript_RemoveMoneyFocusSash
	compare VAR_TEMP_1, 2
	call_if_eq MicoloHideout_EventScript_RemoveMoneySacredAsh
	updatemoneybox 0, 0
	bufferitemname 0, VAR_TEMP_0
	playse SE_JIHANKI
	msgbox MicoloHideout_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 8  @ 1/8 (12.5%) chance of an additional drink dropping
	compare VAR_RESULT, 0
	goto_if_ne MicoloHideout_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MicoloHideout_EventScript_NoRoomForDrink
	playse SE_JIHANKI
	msgbox MicoloHideout_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 3  @ 1/3 * the prev 1/8 chance of a third additional drink dropping, ~ 4% chance
	compare VAR_RESULT, 0
	goto_if_ne MicoloHideout_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0, 1
	compare VAR_RESULT, 0
	goto_if_eq MicoloHideout_EventScript_NoRoomForDrink
	playse SE_JIHANKI
	msgbox MicoloHideout_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname 1, VAR_TEMP_0
	bufferstdstring 2, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto MicoloHideout_EventScript_ChooseNewDrink
	end

MicoloHideout_EventScript_ChooseNewDrink::
	message MicoloHideout_Text_WhichDrinkWouldYouLike
	waitmessage
	goto MicoloHideout_EventScript_ChooseDrink
	end

MicoloHideout_EventScript_NotEnoughMoneyForDrink::
	msgbox MicoloHideout_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto MicoloHideout_EventScript_ExitVendingMachine
	end

MicoloHideout_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto MicoloHideout_EventScript_ExitVendingMachine
	end

MicoloHideout_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

MicoloHideout_VentaTickets::
	lock
	faceplayer
	checkflag FLAG_SYS_HAS_EON_TICKET 
	compare VAR_RESULT, TRUE
	goto_if_eq MicoloHideoutYaCompradoTickets
	showmoneybox 0, 0, 0
	msgbox MicoloHideout_VentaTickets_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MicoloHideout_EventScript_SiVendido
	compare VAR_RESULT, NO
	goto_if_eq MicoloHideoutTickets_NotEnoughMoney
	end
	
MicoloHideout_EventScript_SiVendido::
	checkmoney 50000, 0
    compare VAR_RESULT, 0
    goto_if_eq MicoloHideoutTickets_NotEnoughMoney
    playse SE_REGI
    removemoney 50000, 0
	delay 8
    updatemoneybox 0, 0
	giveitem ITEM_EON_TICKET
	setflag FLAG_SYS_HAS_EON_TICKET
	setvar VAR_DISTRIBUTE_EON_TICKET, 0
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	msgbox MicoloHideout_SiVendido_Text
	hidemoneybox
	release
	end
	
MicoloHideoutTickets_NotEnoughMoney::
	msgbox MicoloHideoutTickets_Text_NotEnoughMoney
	hidemoneybox
	release
	end
	
MicoloHideoutYaCompradoTickets::
	msgbox MicoloHideout_SiVendido_Text
	release
	end

MicoloHideout_EventScript_Gordo::
	lock
	faceplayer
	msgbox MicoloHideout_EventScript_Gordo_Text_0, MSGBOX_NPC
	return

MicoloHideout_EventScript_Gordo_Text_0:
	.string "Jeje... me he colado.\n"
	.string "¿Ah, te han dejado pasar?\p"
	.string "Dicen que aquí solo dejan pasar a los\n"
	.string "mejores... no tienes pinta de ser muy\l"
	.string "bueno, jeje. MICOLO te ganaría sin\l"
	.string "despeinarse.$"

MicoloHideout_EventScript_Recepcionista::
	lock
	faceplayer
	msgbox MicoloHideout_EventScript_Recepcionista_Text_0, MSGBOX_NPC
	return

MicoloHideout_EventScript_Recepcionista_Text_0:
	.string "Bienvenido al CASINO de MICOLANDIA,\n"
	.string "{PLAYER}. Disfruta de tu merecida\l"
	.string "recompensa tras haber derrotado a los\l"
	.string "4 líderes de gimnasio de MICOLANDIA y\l"
	.string "haber llegado al final del viaje.$"

MicoloHideout_EventScript_ViejoFichas::
	lock
	faceplayer
	msgbox MicoloHideout_EventScript_ViejoFichas_Text_0, MSGBOX_NPC
	return


MicoloHideout_EventScript_ViejoFichas_Text_0:
	.string "Jojojo... ¿me parece a mí o las fichas de\n"
	.string "este CASINO son más baratas que las\l"
	.string "del CASINO de MAUVILLE?\p"
	.string "Por cierto, ¿sigue el loco de los gachas\n"
	.string "por ahí? Antes se pasaba por aquí,\l"
	.string "pero MICOLO le metió un buen 6-0 y lo\l"
	.string "echó a micopatadas, jojojo...$"

MicoloHideout_EventScript_ViejoPremios::
	lock
	faceplayer
	msgbox MicoloHideout_EventScript_ViejoPremios_Text_0, MSGBOX_NPC
	return


MicoloHideout_EventScript_ViejoPremios_Text_0:
	.string "Mmm... los premios de este casino son\n"
	.string "excepcionales... no los encontrarás en\l"
	.string "ningún otro lugar... ¿o quizás sí?\p"
	.string "No me molestes, joven, todavía no me he\n"
	.string "tomado la pastilla.$"

MicoloHideout_EventScript_Caballero::
	lock
	faceplayer
	msgbox MicoloHideout_EventScript_Caballero_Text_0, MSGBOX_NPC
	return


MicoloHideout_EventScript_Caballero_Text_0:
	.string "No sé quién será ese tal MICOLO, pero\n"
	.string "debe de tener buen gusto si ha decido\l"
	.string "invitarme a mí hasta aquí...\p"
	.string "Ejem, esto del casino está muy bien,\n"
	.string "pero yo me esperaba... no sé... algo más.\p"
	.string "¿Dónde está ese tal MICOLO?$"

MicoloHideout_EventScript_TecnicoTragaperras::
	lock
	faceplayer
	msgbox MicoloHideout_EventScript_TecnicoTragaperras_Text_0, MSGBOX_NPC
	return


MicoloHideout_EventScript_TecnicoTragaperras_Text_0:
	.string "Dicen que las máquinas de este CASINO\n"
	.string "dan más premios...\p"
	.string "O eso te esperarías, pero no. ¿Has visto\n"
	.string "el código de esas cosas? ¡No entiendo\l"
	.string "absolutamente nada! ¡En mis 20 años de\l"
	.string "técnico de máquinas de casino no había\l"
	.string "visto nada igual!\p"
	.string "Ah, pero las ruletas... esas sí, dan mas\n"
	.string "premios. Pruébalas, no te arrepentirás.$"

MicoloHideout_EventScript_MagnoAquiles::
	lock
	applymovement 8, Common_Movement_WalkInPlaceFastestRight
	msgbox MicoloHideout_EventScript_MagnoAquiles_Text_0, MSGBOX_DEFAULT
	applymovement 9, Common_Movement_WalkInPlaceFastestLeft
	msgbox MicoloHideout_EventScript_MagnoAquiles_Text_1, MSGBOX_DEFAULT
	msgbox MicoloHideout_EventScript_MagnoAquiles_Text_2, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox MicoloHideout_EventScript_MagnoAquiles_Text_3, MSGBOX_DEFAULT
	msgbox MicoloHideout_EventScript_MagnoAquiles_Text_4, MSGBOX_DEFAULT
	msgbox MicoloHideout_EventScript_MagnoAquiles_Text_5, MSGBOX_DEFAULT
	msgbox MicoloHideout_EventScript_MagnoAquiles_Text_6, MSGBOX_DEFAULT
	msgbox MicoloHideout_EventScript_MagnoAquiles_Text_7, MSGBOX_DEFAULT
	msgbox MicoloHideout_EventScript_MagnoAquiles_Text_8, MSGBOX_DEFAULT
	msgbox MicoloHideout_EventScript_MagnoAquiles_Text_9, MSGBOX_DEFAULT
	closemessage
	release
	return


MicoloHideout_EventScript_MagnoAquiles_Text_0:
	.string "MAGNO: ¡Apuesto todo al AZUL!$"

MicoloHideout_EventScript_MagnoAquiles_Text_1:
	.string "AQUILES: ¡Puesto yo apuesto todo al\n"
	.string "ROJO!\p"
	.string "...$"

MicoloHideout_EventScript_MagnoAquiles_Text_2:
	.string "MAGNO: Oye... creo que nos hemos\n"
	.string "confundido otra vez de color...$"

MicoloHideout_EventScript_MagnoAquiles_Text_3:
	.string "MAGNO: ¡Eh! ¡Tú eres aquel chico que\n"
	.string "detuvo nuestros planes! Si no hubiese\l"
	.string "sido por ti y por ese MICOLO...$"

MicoloHideout_EventScript_MagnoAquiles_Text_4:
	.string "AQUILES: Creo que no deberías hablar\n"
	.string "así de MICOLO. Al fin y al cabo, él es\l"
	.string "quien nos ha dejado refugiarnos aquí\l"
	.string "en MICOLANDIA con toda clase de lujos.$"

MicoloHideout_EventScript_MagnoAquiles_Text_5:
	.string "MAGNO: Ya... pero, no sé... Algo falla...\n"
	.string "Mmm...$"

MicoloHideout_EventScript_MagnoAquiles_Text_6:
	.string "AQUILES: ¿A qué te refieres?$"

MicoloHideout_EventScript_MagnoAquiles_Text_7:
	.string "MAGNO: Diría que MICOLO nos ha estado\n"
	.string "utilizando durante todo este tiempo.$"

MicoloHideout_EventScript_MagnoAquiles_Text_8:
	.string "AQUILES: ¡Ja! ¿Utilizarnos? ¿A\n"
	.string "nosotros, las mentes más capaces de\l"
	.string "todo HOENN? ¡Ni en sueños!\p"
	.string "¡Apuesto todo al ROJO!$"

MicoloHideout_EventScript_MagnoAquiles_Text_9:
	.string "MAGNO: ¡Y que lo digas! ¡Apuesto todo al\n"
	.string "AZUL!\p"
	.string "Oh, espera... otra vez no...$"

MicoloHideout_EventScript_NerdMaquinas::
	lock
	compare VAR_STATE_MICOLANDIA, 1
	goto_if_eq MicoloHideout_EventScript_NerdMaquinas_2
	msgbox MicoloHideout_EventScript_NerdMaquinas_Text_1, MSGBOX_NPC
MicoloHideout_EventScript_NerdMaquinas_1:
	release
	return

MicoloHideout_EventScript_NerdMaquinas_2:
	msgbox MicoloHideout_EventScript_NerdMaquinas_Text_0, MSGBOX_NPC
	goto MicoloHideout_EventScript_NerdMaquinas_1


MicoloHideout_EventScript_NerdMaquinas_Text_0:
	.string "Jeje... aquí hay demasiadas máquinas\n"
	.string "expendedoras, ¿no te parece\l"
	.string "sospechoso?\p"
	.string "Además, ¿por qué una planta y una\n"
	.string "papelera? La decoración de interiores\l"
	.string "brilla por su ausencia en esta parte de\l"
	.string "la sala.$"

MicoloHideout_EventScript_NerdMaquinas_Text_1:
	.string "¡Lo sabía! ¡Sabía que había algo raro\n"
	.string "en este sitio!\p"
	.string "Por cierto... menuda PATADA SALTO...$"


MicoloHideout_GameCorner_Text_ThisIsMicoloHideoutGameCorner: @ 8210460
	.string "Bienvenido al CASINO de MICOLANDIA.$"

MicoloHideout_GameCorner_Text_NeedCoinCaseForCoins: @ 821047E
	.string "¿Quieres FICHAS?\n"
	.string "Si quieres comprar FICHAS,\p"
	.string "necesitarás un MONEDERO.$"

MicoloHideout_GameCorner_Text_WereYouLookingForCoins: @ 82104DF
	.string "¿Buscas FICHAS?\p"
	.string "50 FICHAS son 750¥.\n"
	.string "¿Quieres alguna?$"

MicoloHideout_GameCorner_Text_ThankYouHereAreYourCoins: @ 8210529
	.string "Muchas gracias.\n"
	.string "Toma tus FICHAS.$"

MicoloHideout_GameCorner_Text_DontHaveEnoughMoney: @ 8210553
	.string "Um… Parece que no tienes\n"
	.string "Suficiente dinero…$"

MicoloHideout_GameCorner_Text_DontHaveEnoughCoins: @ 8210553
	.string "Um… Parece que no tienes suficientes\n"
	.string "FICHAS…$"

MicoloHideout_GameCorner_Text_CoinCaseIsFull: @ 821057E
	.string "¿Oh?\n"
	.string "Tu MONEDERO está lleno.$"

MicoloHideout_GameCorner_Text_DontNeedCoinsThen: @ 821059A
	.string "Oh… ¿no necesitas fichas?\n"
	.string "Disfruta del CASINO.$"

MicoloHideout_GameCorner_Text_GetMon::
	.string "{PLAYER} received {STR_VAR_1}!$"

MicoloHideout_GameCorner_Text_NoRoom::
    .string "No hay sitio en tu equipo.$"

MicoloHideout_GameCorner_Text_OhIsThatSo: @ 82106BF
	.string "¿Estás seguro?\n"
	.string "No encontrarás estos POKéMON\l"
	.string "en ningún otro lugar.$"

MicoloHideout_GameCorner_Text_SoYourChoiceIsX: @ 8210705
	.string "¿Así que quieres un {STR_VAR_1}?$"

MicoloHideout_GameCorner_Text_WhichPrize: @ 821060D
	.string "¿Qué premio te gustaría comprar?$"

MicoloHideout_GameCorner_Text_ExchangeCoinsForPrizes: @ 82105D7
	.string "Bienvenido.\p"
	.string "Aquí puedes intercambiar tus FICHAS\n"
	.string "por premios midélicos.$"

MicoloHideout_Text_WhichDrinkWouldYouLike: @ 822056D
	.string "It's a VENDING MACHINE.\n"
	.string "Which item would you like?$"

MicoloHideout_Text_CanOfDrinkDroppedDown: @ 82205A1
	.string "Clang!\p"
	.string "A can of {STR_VAR_1} dropped down.$"

MicoloHideout_Text_ExtraCanOfDrinkDroppedDown: @ 82205C2
	.string "Clang!\p"
	.string "Score! An extra can of {STR_VAR_1}\n"
	.string "dropped down!$"

MicoloHideout_Text_NotEnoughMoney: @ 82205F1
	.string "Not enough money…$"

MicoloHideout_Text_DecidedAgainstBuyingDrink: @ 8220603
	.string "Decided against buying a drink.$"
	
MicoloHideout_VentaTickets_Text:
	.string "¡¡¡Eh, pringao!!\n"
	.string "¡¡O pringaa!!\p" 
	.string "¡Seas lo que seas\n"
	.string "Me da iguaa!\p"

	.string "¡¡Tengo cuatro tickets que te\n"
	.string	"abrirán las puertas a lugares\l"
	.string "que te molarán cantidubi!!\p"
	
	.string "¿Qué de donde los he\n"
	.string "sacado?\p"
	
	.string "¡Eso no es asunto tuyo!\p"
	
	.string "Bah, te los vendo por solo\n"
	.string "50.000 Pokeyens.\l"
	.string "¿Trato hecho?$"

MicoloHideoutTickets_Text_NotEnoughMoney:
	.string "¿Me estas intentando\n"
	.string "timar?$"
	
MicoloHideout_SiVendido_Text:
	.string "¡¡Esto es un trato dabuten!!$"

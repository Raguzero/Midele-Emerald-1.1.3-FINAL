MicoloHideout_GameCorner_MapScripts::
	.byte 0
  .set COINS_PRICE_50_MICOLO,  750
	.set COINS_PRICE_500_MICOLO, 7500

MicoloHideout_GameCorner_Sign_TrashBin::
  warp MAP_MICOLO_HIDEOUT_SECURITY_ROOM, 0, 0, 0
  waitstate
  end

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
	case 1, MicoloHideout_GameCorner_EventScript_MICOMON_Confirm
	case 2, MicoloHideout_GameCorner_EventScript_CATERMANO_Confirm
	goto MicoloHideout_GameCorner_EventScript_CancelDollSelect
	end

MicoloHideout_GameCorner_EventScript_DARK_PIKA_Confirm:
	setvar VAR_TEMP_1, 1
  bufferspeciesname 0, SPECIES_PIKACHU
	goto MicoloHideout_GameCorner_EventScript_MonConfirm

MicoloHideout_GameCorner_EventScript_MICOMON_Confirm:
	setvar VAR_TEMP_1, 2
  bufferspeciesname 0, SPECIES_DITTO
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
	case 2, MicoloHideout_GameCorner_EventScript_MICOMON
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
	bufferspeciesname 0, SPECIES_PIKACHU
	message MicoloHideout_GameCorner_Text_GetMon
	waitfanfare
	waitmessage
	givemon SPECIES_PIKACHU, 90, ITEM_NONE
	bufferspeciesname 1, SPECIES_PIKACHU
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Common_EventScript_NameReceivedPartyMon
  goto MicoloHideout_GameCorner_EventScript_MonPrizesFirst

MicoloHideout_GameCorner_EventScript_MICOMON:
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
	bufferspeciesname 0, SPECIES_DITTO
	message MicoloHideout_GameCorner_Text_GetMon
	waitfanfare
	waitmessage
	givemon SPECIES_DITTO, 90, ITEM_NONE
	bufferspeciesname 1, SPECIES_DITTO
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
	givemon SPECIES_CATERPIE, 90, ITEM_NONE
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

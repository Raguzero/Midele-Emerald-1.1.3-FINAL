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

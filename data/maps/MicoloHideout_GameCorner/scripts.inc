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
	msgbox MicoloHideout_GameCorner_Text_ThisIsMicolandiaGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MicoloHideout_GameCorner_EventScript_NeedCoinCase
	message MicoloHideout_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0, 0
	showcoinsbox 1, 6
	goto MicoloHideout_GameCorner_EventScript_ChooseCoinsDefault50

MicoloHideout_GameCorner_EventScript_ChooseCoinsDefault50:: @ 820FBE5
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, 0
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

MicoloHideout_GameCorner_Text_ThisIsMicolandiaGameCorner: @ 8210460
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

MicoloHideout_GameCorner_Text_CoinCaseIsFull: @ 821057E
	.string "¿Oh?\n"
	.string "Tu MONEDERO está lleno.$"

MicoloHideout_GameCorner_Text_DontNeedCoinsThen: @ 821059A
	.string "Oh… ¿no necesitas fichas?\n"
	.string "Disfruta del CASINO.$"

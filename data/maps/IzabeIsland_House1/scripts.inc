IzabeIsland_House1_MapScripts::
	.byte 0

IzabeIsland_House1_EventScript_Cook::
	msgbox IzabeIsland_House1_Text_Cook, MSGBOX_NPC
	end

IzabeIsland_House1_EventScript_Judge::
	lock
	faceplayer
	goto_if_set FLAG_IZABE_NPC_TRADE_COMPLETED, IzabeIsland_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_IZABE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox IzabeIsland_House1_Text_WillingToTradeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq IzabeIsland_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq IzabeIsland_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne IzabeIsland_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	msgbox IzabeIsland_House1_Text_ThanksForTrading, MSGBOX_DEFAULT
	setflag FLAG_IZABE_NPC_TRADE_COMPLETED
	release
	end
	
IzabeIsland_House1_EventScript_TradeCompleted:: @ 8203C93
	msgbox IzabeIsland_House1_Text_HowIsIt, MSGBOX_DEFAULT
	release
	end

IzabeIsland_House1_EventScript_NotRequestedMon:: @ 8203C9D
	bufferspeciesname 0, VAR_0x8009
	msgbox IzabeIsland_House1_Text_NotRequestedMon, MSGBOX_DEFAULT
	release
	end

IzabeIsland_House1_EventScript_DeclineTrade:: @ 8203CAB
	msgbox IzabeIsland_House1_Text_DeclineTrade, MSGBOX_DEFAULT
	release
	end

IzabeIsland_House1_Text_Cook::
	.string "Debido al clima adverso de esta isla,\n"
	.string "cultivar bayas es difícil. Por esa razón\l"
	.string "los alimentos son algo muy valioso aquí.\p"
	.string "¿Mi comida favorita?\n"
	.string "Pato relleno, por supuesto. Jejeje.$"

IzabeIsland_House1_Text_WillingToTradeIt::
	.string "Mi hermano está loco, creo que mi\n"
	.string "{STR_VAR_2} ya no está seguro aquí.\p"
	.string "Ya sé, te dejaré que cuides mi\n"
	.string "{STR_VAR_2} si a cambio me das un\l"
	.string "{STR_VAR_1}. Mi hermano odia los\l"
	.string "{STR_VAR_1}, dice que saben mal.\n"
	.string "¿Qué te parece?$"

IzabeIsland_House1_Text_ThanksForTrading::
	.string "Gracias. Prometo que mi hermano no\n"
	.string "tocará a tu {STR_VAR_1}. Cuida de mi\l"
	.string "{STR_VAR_2}.$"

IzabeIsland_House1_Text_HowIsIt::
	.string "¿Qué tal está mi {STR_VAR_2}\n"
	.string "Tu {STR_VAR_1} está bien, de momento...$"

IzabeIsland_House1_Text_DeclineTrade::
	.string "¿No quieres? Por favor, mi POKéMON\n"
	.string "necesita ayuda...$"

IzabeIsland_House1_Text_NotRequestedMon::
	.string "¡Eso no es el POKéMON que\n"
	.string "te pedí!$"

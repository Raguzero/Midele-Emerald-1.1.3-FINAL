Route117_PokemonDayCare_MapScripts:: @ 822BBB1
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition: @ 822BBB7
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_EventScript_Beauty::
	lock
	faceplayer
	goto_if_set FLAG_DAYCARE_TRADE_COMPLETED, Route117_PokemonDayCare_EventScript_ExplainDitto
	setvar VAR_0x8008, INGAME_TRADE_DAYCARE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox Route117_PokemonDayCare_Text_Beauty_GiveDitto, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route117_PokemonDayCare_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x8004, 255
	goto_if_eq Route117_PokemonDayCare_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne Route117_PokemonDayCare_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname 0, VAR_0x8009
	msgbox Route117_PokemonDayCare_Text_ExplainDitto, MSGBOX_NPC
	setflag FLAG_DAYCARE_TRADE_COMPLETED
	release
	end
	
Route117_PokemonDayCare_EventScript_TradeCompleted:: @ 8203C93
	msgbox IzabeIsland_House1_Text_HowIsIt, MSGBOX_NPC
	release
	end

Route117_PokemonDayCare_EventScript_NotRequestedMon:: @ 8203C9D
	bufferspeciesname 0, VAR_0x8009
	msgbox Route117_PokemonDayCare_Text_Beauty_NotRequestedMon, MSGBOX_NPC
	release
	end

Route117_PokemonDayCare_EventScript_DeclineTrade:: @ 8203CAB
	msgbox Route117_PokemonDayCare_Text_Beauty_DeclineTrade, MSGBOX_NPC
	release
	end

Route117_PokemonDayCare_EventScript_ExplainDitto:: @ 82700EA
	msgbox Route117_PokemonDayCare_Text_ExplainDitto, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_DITTO
	release
	end

Route117_PokemonDayCare_Text_Beauty_GiveDitto::
	.string "No te lo vas a creer, he encontrado este\n"
	.string "{STR_VAR_2} en la GUARDERÍA. Parece que es\l"
	.string "muy popular aquí...\p"
	.string "De todas formas, a mí no me gustan los\n"
	.string "{STR_VAR_2}...\p"
	.string "Ya sé, te cambio mi {STR_VAR_2} por un\n"
	.string "{STR_VAR_1}, ¿qué dices?$"

Route117_PokemonDayCare_Text_ExplainDitto::
	.string "Dicen que DITTO es un POKéMON que puede\n"
	.string "criar con casi cualquier especie de\l"
	.string "POKéMON. ¿Será verdad?$"

Route117_PokemonDayCare_Text_Beauty_NotRequestedMon::
	.string "¡Eso no es un {STR_VAR_1}!\n"
	.string "¡No me tomes el pelo!$"

Route117_PokemonDayCare_Text_Beauty_DeclineTrade::
	.string "Si cambies de idea, aquí estaré.$"

Route117_PokemonDayCare_Text_PlayerReceivedDitto::
	.string "{PLAYER} received DITTO!$"

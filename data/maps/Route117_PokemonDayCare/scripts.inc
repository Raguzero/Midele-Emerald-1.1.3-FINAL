Route117_PokemonDayCare_MapScripts:: @ 822BBB1
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition: @ 822BBB7
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_EventScript_Beauty::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DITTO, Route117_PokemonDayCare_EventScript_ExplainDitto
	msgbox Route117_PokemonDayCare_Text_Beauty_GiveDitto, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_DITTO
	givemon SPECIES_DITTO, 5, ITEM_EVERSTONE, FALSE, TRUE
	compare VAR_RESULT, 0
	goto_if_eq Route117_PokemonDayCare_EventScript_ReceiveDittoParty
	compare VAR_RESULT, 1
	goto_if_eq Route117_PokemonDayCare_EventScript_ReceiveDittoPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route117_PokemonDayCare_EventScript_ReceiveDittoParty:: @ 8270085
	call Route117_PokemonDayCare_EventScript_ReceiveDittoFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route117_PokemonDayCare_EventScript_ExplainDitto
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route117_PokemonDayCare_EventScript_ExplainDitto
	end

Route117_PokemonDayCare_EventScript_ReceiveDittoPC:: @ 82700AD
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route117_PokemonDayCare_EventScript_SendDittoToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route117_PokemonDayCare_EventScript_SendDittoToPC
	end

Route117_PokemonDayCare_EventScript_SendDittoToPC:: @ 82700D0
	call Common_EventScript_TransferredToPC
	goto Route117_PokemonDayCare_EventScript_ExplainDitto
	end

Route117_PokemonDayCare_EventScript_ReceiveDittoFanfare:: @ 82700DB
	playfanfare MUS_FANFA4
	message Route117_PokemonDayCare_Text_PlayerReceivedDitto
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_DITTO
	return

Route117_PokemonDayCare_EventScript_ExplainDitto:: @ 82700EA
	msgbox Route117_PokemonDayCare_Text_ExplainDitto, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_DITTO
	release
	end

Route117_PokemonDayCare_Text_Beauty_GiveDitto::
	.string "No te lo vas a creer, he encontrado este\n"
	.string "DITTO en la GUARDERÍA. Parece que es\l"
	.string "muy popular aquí...\p"
	.string "De todas formas, a mí no me gustan los\n"
	.string "DITTO, ¿qué tal si te lo quedas tú?$"

Route117_PokemonDayCare_Text_ExplainDitto::
	.string "Dicen que DITTO es un POKéMON que puede\n"
	.string "criar con casi cualquier especie de\l"
	.string "POKéMON. ¿Será verdad?$"

Route117_PokemonDayCare_Text_PlayerReceivedDitto::
	.string "{PLAYER} received DITTO!$"

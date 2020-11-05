Micolandia_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Micolandia_OnTransition
	.byte 0

Micolandia_OnTransition: @ 81DC2D7
	//setflag FLAG_VISITED_PETALBURG_CITY
	end
	
Micolandia_EventScript_Marihuana::
	msgbox Micolandia_Text_Marihuana, MSGBOX_NPC
	end
	
Micolandia_EventScript_BienvenidaSign::
	msgbox Micolandia_Text_BienvenidaSign, MSGBOX_SIGN
	end
	
Micolandia_EventScript_LigaSign::
	msgbox Micolandia_Text_LigaSign, MSGBOX_SIGN
	end
	
Micolandia_EventScript_GymNoroesteSign::
	msgbox Micolandia_GymNoroesteSign, MSGBOX_SIGN
	end

Micolandia_EventScript_GymNoresteSign::
	msgbox Micolandia_GymNoresteSign, MSGBOX_SIGN
	end

Micolandia_EventScript_GymSuroesteSign::
	msgbox Micolandia_GymSuroesteSign, MSGBOX_SIGN
	end

Micolandia_EventScript_GymSuresteSign::
	msgbox Micolandia_GymSuresteSign, MSGBOX_SIGN
	end
	
Micolandia_EventScript_CibercafeSign::
	msgbox Micolandia_CibercafeSign, MSGBOX_SIGN
	end
	
Micolandia_VentaTickets::
	lock
	faceplayer
	checkitem ITEM_EON_TICKET, 1 
	compare VAR_RESULT, TRUE
	goto_if_eq MicolandiaYaCompradoTickets
	showmoneybox 0, 0, 0
	msgbox Micolandia_VentaTickets_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Micolandia_EventScript_SiVendido
	compare VAR_RESULT, NO
	goto_if_eq Micolandia_EventScript_NotEnoughMoney
	end
	
Micolandia_EventScript_SiVendido::
	checkmoney 50000, 0
    compare VAR_RESULT, 0
    goto_if_eq Micolandia_EventScript_NotEnoughMoney
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
	msgbox Micolandia_SiVendido_Text
	hidemoneybox
	release
	end
	
Micolandia_EventScript_NotEnoughMoney::
	msgbox Micolandia_Text_NotEnoughMoney
	hidemoneybox
	release
	end
	
MicolandiaYaCompradoTickets::
	msgbox Micolandia_SiVendido_Text
	release
	end
	
Micolandia_Text_Marihuana:
	.string "¿Ves esas plantas de ahí?\p"
	.string "Cualquiera diría que hay\n" 
	.string "Pokémon salvajes.\p"

	.string "Pero si fumas de eso serás tú quien\n"
	.string	"acabará bien salvaje jeje$"

Micolandia_Text_BienvenidaSign:
	.string "¡Bienvenido a MICOLANDIA!\n"
	.string "Si estás aquí es que fuiste elegido\p"
	.string "para afrontar el desafio de la\n"
	.string "Liga Pokemon Midelar.\p"
	
	.string "¡Deberás superar la prueba\n"
	.string "de los cuatro lideres de Gymnasio\p"
	.string "para participar en la nueva y\n"
	.string "extraordinario Liga Pokemon Midelar!$"
	
Micolandia_Text_LigaSign:
	.string "Liga Pokemon Midelar$"
	
Micolandia_GymNoroesteSign: @ 81DCAAA
	.string "POKEMON GYM Nº1\n"
	.string "LEADER: ????1\l"
	.string "“Mensaje descriptivo del lider”$"

Micolandia_GymNoresteSign: @ 81DCAAA
	.string "POKEMON GYM Nº2\n"
	.string "LEADER: ????1\l"
	.string "“Mensaje descriptivo del lider”$"

Micolandia_GymSuroesteSign: @ 81DCAAA
	.string "POKEMON GYM Nº3\n"
	.string "LEADER: ????1\l"
	.string "“Mensaje descriptivo del lider”$"

Micolandia_GymSuresteSign: @ 81DCAAA
	.string "POKEMON GYM Nº4\n"
	.string "LEADER: ????1\l"
	.string "“Mensaje descriptivo del lider”$"
	
Micolandia_CibercafeSign:
	.string "CiberCafé Batalla$"

Micolandia_VentaTickets_Text:
	.string "¡¡¡Eh, pringao!!\n"
	.string "¡¡O pringaa!!\p" 
	.string "¡Seas lo que seas\n"
	.string "Me da iguaa!\p"

	.string "¡¡Tengo cuatro tickets que\n"
	.string	"te abrirán las puertas\p"
	.string "a lugares que te molarán\n"
	.string "cantidubi!!\p"
	
	.string "¿Qué de donde los he\n"
	.string "sacado?\p"
	
	.string "¡Eso no es asunto tuyo!\p"
	
	.string "Bah, te vendo los tres\n"
	.string "por solo 50000\l"
	.string "¿Trato hecho?$"

Micolandia_Text_NotEnoughMoney:
	.string "¿Me estas intentando\n"
	.string "timar?$"
	
Micolandia_SiVendido_Text:
	.string "Esto es un trato dabuten!!$"

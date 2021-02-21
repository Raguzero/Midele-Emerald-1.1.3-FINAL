Micolandia_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Micolandia_OnTransition
	.byte 0

Micolandia_OnTransition: @ 81DC2D7
	setflag FLAG_VISITED_MICOLANDIA
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
	
Micolandia_Kirlia_Script::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KIRLIA, 0
	waitmoncry
	release
	end
	
Micolandia_Dueno_de_Kirlia_Script::
	lock
	faceplayer
	msgbox Micolandia_Dueno_de_Kirlia_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Micolandia_Dueno_de_Kirlia_Teleport
	release
	end
Micolandia_Dueno_de_Kirlia_Teleport::
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Micolandia_EventScript_PlayersHouseMale
	compare VAR_RESULT, FEMALE
	call_if_eq Micolandia_EventScript_BirchsHouseFemale
	release
	end

Micolandia_EventScript_PlayersHouseMale::
	warp MAP_LITTLEROOT_TOWN, 1, 0, 0
	waitstate
	end

Micolandia_EventScript_BirchsHouseFemale::
	warp MAP_LITTLEROOT_TOWN, 0, 0, 0
	waitstate
	end

Micolandia_VentaTickets::
	lock
	faceplayer
	checkflag FLAG_SYS_HAS_EON_TICKET 
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
	.string	"acabará bien salvaje. ¡jeje!$"

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
	.string "LIGA POKÉMON MIDELAR$"
	
Micolandia_GymNoroesteSign:
	.string "POKEMON GYM Nº1\n"
	.string "LEADER: SANTYGRASS\l"
	.string "“TEMÁTICA: HIERBA QUEMADA”$"

Micolandia_GymNoresteSign:
	.string "POKEMON GYM Nº2\n"
	.string "LEADER: DARKI\l"
	.string "“TEMÁTICA: BUENROLLO y MALROLLO”$"

Micolandia_GymSuroesteSign:
	.string "POKEMON GYM Nº3\n"
	.string "LEADER: SAPPH\l"
	.string "“TEMÁTICA: ????”$"

Micolandia_GymSuresteSign:
	.string "POKEMON GYM Nº4\n"
	.string "LEADER: GOOSES\l"
	.string "“TEMÁTICA: INVIERNO”$"
	
Micolandia_CibercafeSign:
	.string "CIBERCAFE BATALLA$"

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
	
	.string "Bah, te los vendo por solo\n"
	.string "50000 Pokeyens.\l"
	.string "¿Trato hecho?$"

Micolandia_Text_NotEnoughMoney:
	.string "¿Me estas intentando\n"
	.string "timar?$"
	
Micolandia_SiVendido_Text:
	.string "¡¡Esto es un trato dabuten!!$"
	
Micolandia_Dueno_de_Kirlia_Text:
	.string "La única forma de salir de aquí\n"
	.string "es volando.\p"

	.string "Pero mi KIRLIA puede usar la\n"
	.string "técnica del TELEPORT para enviarte\l"
	.string "a tu casa. ¡Es gratis!\p"
	
	.string "¿Quieres que te lleve a tu casa?$"

Micolandia_Mart_MapScripts::
	.byte 0

// ESTO FUNCIONA COMO CAMBIADOR DE EVS, NO COMO TIENDA, NO TOCAR NADA:
Micolandia_Mart_EventScript_Clerk::
	lock
	faceplayer
	msgbox Micolandia_EV_Mart, MSGBOX_DEFAULT
	waitmessage
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	evmart Micolandia_Mart_Pokemart
	msgbox Micolandia_EV_Mart_Bye, MSGBOX_DEFAULT
	release
	end

 .align 2	

Micolandia_Mart_Pokemart:
	.2byte ITEM_POTION
	.2byte ITEM_POTION
	.2byte ITEM_POTION
	.2byte ITEM_POTION
	.2byte ITEM_POTION
	.2byte ITEM_POTION
	.2byte ITEM_NONE
	release
	end
	
Micolandia_EV_Mart:
	.string "¡Bienvenido al EV CHANGER!\p"

	.string "Aquí podrás cambiar a tu gusto los\n"
	.string "EVs de tus POKÉMON.\p"
	
	.string "IT'S FREE!\p"

	.string "Así que, ¿Cuales EVS quieres cambiar\n"
	.string "a cual POKÉMON?$"
	
Micolandia_EV_Mart_Bye:
	.string "¡Hasta pronto!$"

Micolandia_Mart_MapScripts::
	.byte 0
	
Micolandia_Mart_EventScript_Boy::
	msgbox Micolandia_Mart_Text_Boy, MSGBOX_NPC
	end

Micolandia_Mart_EventScript_Shop::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Micolandia_Mart_Pokemart_Shop
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Micolandia_Mart_Pokemart_Shop:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end	
	
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
	
Micolandia_Mart_Text_Boy:
	.string "¿Has usado ya el EV CHANGER?\p"
	
	.string "¡Puedes redistribuir los EVs a tus\n"
	.string "POKÉMON como quieras!\l"
	.string "¡Es super útil!\p"

	.string "Se acabó el comprar vitaminas y plantar\n"
	.string "bayas reductoras de EVs.$"


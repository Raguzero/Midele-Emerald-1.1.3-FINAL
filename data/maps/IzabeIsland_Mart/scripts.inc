IzabeIsland_Mart_MapScripts::
	.byte 0

IzabeIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart IzabeIsland_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

IzabeIsland_Mart_EventScript_HexManiac::
	msgbox IzabeIsland_Mart_Text_HexManiac, MSGBOX_NPC
	end

IzabeIsland_Mart_Text_HexManiac::
	.string "En esta tienda venden cosas que no\n"
	.string "encontrarás en el resto de la región...\l"
	.string "Deberías aprovechar, jeje.$"

	.align 2
IzabeIsland_Mart_Pokemart_Basic: @ 8207D8C
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_BERRY_JUICE
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_PP_UP
	.2byte ITEM_MACHO_BRACE
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_BEAD_MAIL
	.2byte ITEM_GLITTER_MAIL
	.2byte ITEM_TROPIC_MAIL
	.2byte ITEM_RETRO_MAIL
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_DREAM_MAIL
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_NONE
	release
	end

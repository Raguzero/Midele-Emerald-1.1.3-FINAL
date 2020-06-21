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
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_ORANGE_MAIL
	.2byte ITEM_NONE
	release
	end

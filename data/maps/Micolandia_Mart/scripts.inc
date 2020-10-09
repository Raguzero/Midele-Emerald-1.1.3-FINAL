Micolandia_Mart_MapScripts::
	.byte 0

Micolandia_Mart_EventScript_Clerk:: @ 81FF9CE
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	evmart Micolandia_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

 .align 2	
	
Micolandia_Mart_Pokemart: @ 81FF9E8
	.2byte ITEM_POTION
	.2byte ITEM_POTION
	.2byte ITEM_POTION
	.2byte ITEM_POTION
	.2byte ITEM_POTION
	.2byte ITEM_POTION
	.2byte ITEM_NONE
	release
	end

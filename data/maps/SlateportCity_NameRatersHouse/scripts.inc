SlateportCity_NameRatersHouse_MapScripts:: @ 8209AA4
	.byte 0
	
SlateportCity_DexPrizes_Sign::
	msgbox SlateportCity_DexPrizes_Sign_Text, MSGBOX_SIGN
	end

SlateportCity_NameRatersHouse_EventScript_NameRater:: @ 8209AA5
	lock
	faceplayer
	compare VAR_DEXPRIZE, 6
	call_if_eq SlateportCity_Fin_Investigacion_Script
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_NPC
	specialvar VAR_RESULT, PokedexRatingPrize
    copyvar VAR_0x8005, VAR_RESULT
    compare VAR_0x8005, ITEM_NONE
    goto_if_eq NoTienesPremioTeJodes_Script
	compare VAR_DEXPRIZE, 0
	call_if_eq SlateportCity_20more
	compare VAR_DEXPRIZE, 1
	call_if_eq SlateportCity_40more
	compare VAR_DEXPRIZE, 2
	call_if_eq SlateportCity_60more
	compare VAR_DEXPRIZE, 3
	call_if_eq SlateportCity_80more
	compare VAR_DEXPRIZE, 4
	call_if_eq SlateportCity_100more
	compare VAR_DEXPRIZE, 5
	call_if_eq SlateportCity_151more
	
SlateportCity_20more::
	msgbox SlateportCity_20more_Text, MSGBOX_NPC
    goto TeDoyUnPremio_Script
    end
	
SlateportCity_40more::
	msgbox SlateportCity_40more_Text, MSGBOX_NPC
    goto TeDoyUnPremio_Script
    end
	
SlateportCity_60more::
	msgbox SlateportCity_60more_Text, MSGBOX_NPC
    goto TeDoyUnPremio_Script
    end
	
SlateportCity_80more::
	msgbox SlateportCity_80more_Text, MSGBOX_NPC
    goto TeDoyUnPremio_Script
    end
	
SlateportCity_100more::
	msgbox SlateportCity_100more_Text, MSGBOX_NPC
    goto TeDoyUnPremio_Script
    end
	
SlateportCity_151more::
	msgbox SlateportCity_151more_Text, MSGBOX_NPC
    goto TeDoyUnPremio_Script
    end
	
TeDoyUnPremio_Script::
	msgbox SlateportCity_Dar_Premio_Text, MSGBOX_NPC
    giveitem VAR_0x8005, 1
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	addvar VAR_DEXPRIZE, 1
	closemessage
	release
    end
	
NoTienesPremioTeJodes_Script::
	msgbox NoTienesPremioTeJodes_Text, MSGBOX_NPC
	release
    end
	
SlateportCity_Fin_Investigacion_Script::
	msgbox SlateportCity_Fin_Investigacion_Text, MSGBOX_NPC
	release
    end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname: @ 8209B8E
	.string "Hi!, I'm one of PROF. BIRCH's AIDES.\p"
	
	.string "I'm in charge of collecting\n"
	.string "information about the Pokedex.\p"

	.string "I'll reward you as you catch new\n" 
	.string "POKéMON!$"
	
SlateportCity_Fin_Investigacion_Text:
	.string "Hi!, I'm one of PROF. BIRCH's AIDES.\p"
	
	.string "Thanks for your help, with this\n" 
	.string "amount of Pokémon that you have\l" 
	.string "shown me, it is enough.$"
	
NoTienesPremioTeJodes_Text:
	.string "You need to catch more new POKéMON\n" 
	.string "for it to reward you!$"
	
SlateportCity_Dar_Premio_Text:
	.string "You deserve this reward for\n" 
	.string "such good work.$"
	
SlateportCity_20more_Text:
	.string "Good job!\n" 
	.string "You have caught 20 POKéMON!$"
	
SlateportCity_40more_Text:
	.string "Good job!\n" 
	.string "You have caught 40 POKéMON!$"
	
SlateportCity_60more_Text:
	.string "Good job!\n" 
	.string "You have caught 60 POKéMON!$"
	
SlateportCity_80more_Text:
	.string "Good job!\n" 
	.string "You have caught 80 POKéMON!$"
	
SlateportCity_100more_Text:
	.string "Good job!\n" 
	.string "You have caught 100 POKéMON!$"
	
SlateportCity_151more_Text:
	.string "Wonderful!\n" 
	.string "You have caught 151 POKéMON!$"
	
SlateportCity_DexPrizes_Sign_Text:
	.string "PRIZE LIST:\p"

	.string "20 POKéMON = EVERSTONE\n"
	.string "40 POKéMON = SCOPE LENS\l"
	.string "60 POKéMON = AMULET COIN\l"
	.string "80 POKéMON = LANSAT BERRY\l"
	.string "100 POKéMON = STARF BERRY\l"
	.string "151 POKéMON = MASTER BALL$"

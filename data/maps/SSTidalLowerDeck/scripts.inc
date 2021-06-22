SSTidalLowerDeck_MapScripts:: @ 823C818
	.byte 0

SSTidalLowerDeck_EventScript_Phillip:: @ 823C819
	trainerbattle_single TRAINER_PHILLIP, SSTidalLowerDeck_Text_PhillipIntro, SSTidalLowerDeck_Text_PhillipDefeat
	msgbox SSTidalLowerDeck_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_EventScript_Leonard:: @ 823C830
	trainerbattle_single TRAINER_LEONARD, SSTidalLowerDeck_Text_LeonardIntro, SSTidalLowerDeck_Text_LeonardDefeat
	msgbox SSTidalLowerDeck_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalLowerDeck_Text_PhillipIntro: @ 823C847
	.string "Arrrgh! I'm fed up and dog-tired of\n"
	.string "cleaning this huge place!\p"
	.string "Let's have a quick battle!$"

SSTidalLowerDeck_Text_PhillipDefeat: @ 823C8A0
	.string "Little bro, I lost!$"

SSTidalLowerDeck_Text_PhillipPostBattle: @ 823C8B4
	.string "We're the CLEANUP BROTHERS!\p"
	.string "The old one dumps the detergent,\n"
	.string "and the young one does the scrubbing!$"

SSTidalLowerDeck_Text_LeonardIntro: @ 823C917
	.string "This is the bottom of the ship's hull.\n"
	.string "There's plenty of room.\l"
	.string "It'll be alright for a POKéMON battle.$"

SSTidalLowerDeck_Text_LeonardDefeat: @ 823C97D
	.string "Big bro, I lost!$"

SSTidalLowerDeck_Text_LeonardPostBattle: @ 823C98E
	.string "We're the CLEANUP BROTHERS!\p"
	.string "The old one dumps the detergent,\n"
	.string "and the young one does the scrubbing!$"

SSTidalLowerDeck_EventScript_CollectorVendor::
	lockall
	faceplayer
	msgbox SSTidalLowerDeck_EventScript_CollectorVendor_Text_0, MSGBOX_DEFAULT
	waitmessage
    pokemart SSTidalLowerDeck_Mart
	msgbox SSTidalLowerDeck_EventScript_CollectorVendor_Text_1, MSGBOX_DEFAULT
	releaseall
	end


SSTidalLowerDeck_EventScript_CollectorVendor_Text_0:
	.string "¡Oh! Hola...\p"
	.string "¿Tú también eres uno de los míos? ¿Un...\n"
	.string "COLECCIONISTA?\p"
	.string "Si es así, tengo algo que te interesará.\n"
	.string "¡Pero no te saldrá gratis!$"

SSTidalLowerDeck_EventScript_CollectorVendor_Text_1:
	.string "Estaré aquí si me necesitas...$"

    .align 2
SSTidalLowerDeck_Mart::
    .2byte ITEM_PEARL
    .2byte ITEM_BIG_PEARL 
    .2byte ITEM_STARDUST 
    .2byte ITEM_STAR_PIECE
    .2byte ITEM_NUGGET
    .2byte ITEM_TINY_MUSHROOM
    .2byte ITEM_BIG_MUSHROOM
    .2byte ITEM_HEART_SCALE
    .2byte ITEM_RED_SHARD
    .2byte ITEM_YELLOW_SHARD
    .2byte ITEM_BLUE_SHARD
    .2byte ITEM_GREEN_SHARD
    .2byte ITEM_EXP_SHARE
    .2byte ITEM_LUCKY_EGG
    .2byte ITEM_NONE
    release
    end 

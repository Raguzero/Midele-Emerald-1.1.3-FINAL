BattleFrontier_Lounge5_MapScripts:: @ 82645C5
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl:: @ 82645C6
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	compare VAR_0x8004, 255
	goto_if_eq BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg:: @ 8264603
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown:: @ 826460D
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman:: @ 8264617
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt:: @ 8264620
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy:: @ 8264629
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end
	
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger1::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_Midele_NatureChanger1_Greeting, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_NoChange

	msgbox BattleFrontier_Lounge5_Text_Midele_NatureChanger_ChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_NoChange
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_NoEgg

	msgbox BattleFrontier_Lounge5_Text_Midele_NatureChanger_ChooseNature, MSGBOX_DEFAULT
	multichoicegrid 0, 0, MULTI_MIDELE_NATURES_1, 3, 0
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Hardy
	case 1, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Lonely
	case 2, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Brave
	case 3, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Adamant
	case 4, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Naughty
	case 5, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Bold
	case 6, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Docile
	case 7, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Relaxed
	case 8, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Impish
	case 9, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Lax
	case 10, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Timid
	case 11, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Hasty
	case 12, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Serious
	case 13, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Jolly
	case 14, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Naive
	case 15, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Modest
	case 16, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Mild
	case 17, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_NoChange
	case MULTI_B_PRESSED, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_NoChange
	end

@ TODO: possible refactor
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger2::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_Midele_NatureChanger2_Greeting, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_NoChange

	msgbox BattleFrontier_Lounge5_Text_Midele_NatureChanger_ChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_NoChange
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_NoEgg

	msgbox BattleFrontier_Lounge5_Text_Midele_NatureChanger_ChooseNature, MSGBOX_DEFAULT
	multichoicegrid 0, 0, MULTI_MIDELE_NATURES_2, 3, 0
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Quiet
	case 1, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Bashful
	case 2, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Rash
	case 3, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Calm
	case 4, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Gentle
	case 5, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Sassy
	case 6, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Careful
	case 7, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Quirky
	case 8, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_NoChange
	case MULTI_B_PRESSED, BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_NoChange
	end
	
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Hardy::
	setvar VAR_0x8005, NATURE_HARDY
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Lonely::
	setvar VAR_0x8005, NATURE_LONELY
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Brave::
	setvar VAR_0x8005, NATURE_BRAVE
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Adamant::
	setvar VAR_0x8005, NATURE_ADAMANT
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Naughty::
	setvar VAR_0x8005, NATURE_NAUGHTY
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Bold::
	setvar VAR_0x8005, NATURE_BOLD
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Docile::
	setvar VAR_0x8005, NATURE_DOCILE
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Relaxed::
	setvar VAR_0x8005, NATURE_RELAXED
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Impish::
	setvar VAR_0x8005, NATURE_IMPISH
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Lax::
	setvar VAR_0x8005, NATURE_LAX
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Timid::
	setvar VAR_0x8005, NATURE_TIMID
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Hasty::
	setvar VAR_0x8005, NATURE_HASTY
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Serious::
	setvar VAR_0x8005, NATURE_SERIOUS
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Jolly::
	setvar VAR_0x8005, NATURE_JOLLY
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Naive::
	setvar VAR_0x8005, NATURE_NAIVE
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Modest::
	setvar VAR_0x8005, NATURE_MODEST
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Mild::
	setvar VAR_0x8005, NATURE_MILD
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Quiet::
	setvar VAR_0x8005, NATURE_QUIET
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Bashful::
	setvar VAR_0x8005, NATURE_BASHFUL
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Rash::
	setvar VAR_0x8005, NATURE_RASH
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Calm::
	setvar VAR_0x8005, NATURE_CALM
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Gentle::
	setvar VAR_0x8005, NATURE_GENTLE
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Sassy::
	setvar VAR_0x8005, NATURE_SASSY
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Careful::
	setvar VAR_0x8005, NATURE_CAREFUL
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Quirky::
	setvar VAR_0x8005, NATURE_QUIRKY
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply

BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_Apply::
	special MideleChangeSelectedMonNature
	playfanfare MUS_ME_WASURE
	waitfanfare
	msgbox BattleFrontier_Lounge5_Text_Midele_NatureChanger_Done, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_NoChange
	end
	
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_NoChange::
	msgbox BattleFrontier_Lounge5_Text_Midele_NatureChanger_NoChange
	release
	end
	
BattleFrontier_Lounge5_EventScript_Midele_NatureChanger_NoEgg::
	msgbox BattleFrontier_Lounge5_Text_Midele_NatureChanger_NoEgg
	release
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting:: @ 8264632
	.string "Ehehe!\n"
	.string "I can tell what POKéMON are thinking!\p"
	.string "Please!\n"
	.string "Can I see your POKéMON?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown:: @ 826467F
	.string "Boo!\n"
	.string "Cheapie!$"

BattleFrontier_Lounge5_Text_NatureGirlHardy:: @ 826468D
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlLonely:: @ 82646E5
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"

BattleFrontier_Lounge5_Text_NatureGirlBrave:: @ 8264741
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant:: @ 82647A4
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty:: @ 82647FC
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"

BattleFrontier_Lounge5_Text_NatureGirlBold:: @ 8264858
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky:: @ 82648BE
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed:: @ 8264916
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"

BattleFrontier_Lounge5_Text_NatureGirlImpish:: @ 8264972
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"

BattleFrontier_Lounge5_Text_NatureGirlLax:: @ 82649D5
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "It says it likes to be sneaky even\l"
	.string "if it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlTimid:: @ 8264A3F
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"

BattleFrontier_Lounge5_Text_NatureGirlHasty:: @ 8264A9B
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "It will battle even if it has a lot\l"
	.string "of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlSerious:: @ 8264AF3
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "It says it likes to be sneaky even\l"
	.string "if it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlJolly:: @ 8264B5D
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will worry about itself!$"

BattleFrontier_Lounge5_Text_NatureGirlModest:: @ 8264BC3
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "It says it worries about itself whether\l"
	.string "or not it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlMild:: @ 8264C36
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"

BattleFrontier_Lounge5_Text_NatureGirlBashful:: @ 8264C95
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "It says it worries about itself even\l"
	.string "if it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlRash:: @ 8264D01
	.string "Hmhm…\p"
	.string "This one says it likes to be sneaky!\n"
	.string "It says it likes to be sneaky even\l"
	.string "if it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlCalm:: @ 8264D6B
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "It says it worries about itself even\l"
	.string "if it has a lot of ouchies!$"

BattleFrontier_Lounge5_Text_NatureGirlGentle:: @ 8264DD7
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will hit back!$"

BattleFrontier_Lounge5_Text_NatureGirlSassy:: @ 8264E33
	.string "Hmhm…\p"
	.string "This one says it likes to battle!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"

BattleFrontier_Lounge5_Text_NatureGirlCareful:: @ 8264E8F
	.string "Hmhm…\p"
	.string "This one says it looks after itself!\n"
	.string "But if it gets enough ouchies,\l"
	.string "it will turn sneaky!$"

BattleFrontier_Lounge5_Text_NatureGirlEgg:: @ 8264EEE
	.string "That's silly! An EGG is asleep!\n"
	.string "I can't talk to it!$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon:: @ 8264F22
	.string "How charming!\n"
	.string "That little lady claims she can\l"
	.string "understand POKéMON!$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound:: @ 8264F64
	.string "I have this feeling that the little girl\n"
	.string "is saying something profound.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot:: @ 8264FAB
	.string "I know something!\p"
	.string "That little girl plays at the red house\n"
	.string "a lot!$"
	
BattleFrontier_Lounge5_Text_Midele_NatureChanger1_Greeting::
	.string "SASAGEYOOO, SASAGEYOOO....\p"
	.string "Uh, perdona... me he dejado llevar.\n"
	.string "Gracias a mi poder, puedo cambiar la\p"
	.string "NATURALEZA de tus POKéMON.\n"
	.string "¿Te interesa?$"
	
BattleFrontier_Lounge5_Text_Midele_NatureChanger2_Greeting::
	.string "4%... esa es la probabilidad de\n"
	.string "que te toque la naturaleza que quieres.\p"
	.string "¿Injusto? No te preocupes, yo puedo\n"
	.string "cambiar la NATURALEZA de tus POKéMON.\p"
	.string "¿Te interesa?$"
	
	
BattleFrontier_Lounge5_Text_Midele_NatureChanger_NoChange::
	.string "Vuelve cuando quieras.$"
	
BattleFrontier_Lounge5_Text_Midele_NatureChanger_ChooseMon::
	.string "Elige un POKéMON.$"
	
BattleFrontier_Lounge5_Text_Midele_NatureChanger_ChooseNature::
	.string "Elige una NATURALEZA.$"
	
BattleFrontier_Lounge5_Text_Midele_NatureChanger_NoEgg::
	.string "No puedo cambiar la NATURALEZA\n"
	.string "de un HUEVO.$"
	
BattleFrontier_Lounge5_Text_Midele_NatureChanger_Done::
	.string "La NATURALEZA de tu POKéMON ha sido\n"
	.string "modificada exitosamente.$"

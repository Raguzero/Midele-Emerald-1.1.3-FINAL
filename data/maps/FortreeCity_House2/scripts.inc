FortreeCity_House2_MapScripts:: @ 82177CA
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver:: @ 82177CB
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM10, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, 1
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, 1
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, 1
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM10
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM10
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Midele_HiddenPowerTypeChange::
	lock
	faceplayer
	msgbox FortreeCity_House2_Text_Midele_HPTypeGreeting, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FortreeCity_House2_EventScript_Midele_HiddenPowerTypeChange_NoChange

	msgbox FortreeCity_House2_Text_Midele_HPTTypeChooseMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq FortreeCity_House2_EventScript_Midele_HiddenPowerTypeChange_NoChange
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq FortreeCity_House2_EventScript_Midele_HiddenPowerTypeChange_NoEgg

	msgbox FortreeCity_House2_Text_Midele_HPTypeChoose, MSGBOX_DEFAULT
	multichoicegrid 0, 0, MULTI_MIDELE_HIDDEN_POWER_TYPES, 3, 0
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_Midele_HP_Normal
	case 1, FortreeCity_House2_EventScript_Midele_HP_Fighting
	case 2, FortreeCity_House2_EventScript_Midele_HP_Flying
	case 3, FortreeCity_House2_EventScript_Midele_HP_Poison
	case 4, FortreeCity_House2_EventScript_Midele_HP_Ground
	case 5, FortreeCity_House2_EventScript_Midele_HP_Rock
	case 6, FortreeCity_House2_EventScript_Midele_HP_Bug
	case 7, FortreeCity_House2_EventScript_Midele_HP_Ghost
	case 8, FortreeCity_House2_EventScript_Midele_HP_Steel
	case 9, FortreeCity_House2_EventScript_Midele_HP_Fire
	case 10, FortreeCity_House2_EventScript_Midele_HP_Water
	case 11, FortreeCity_House2_EventScript_Midele_HP_Grass
	case 12, FortreeCity_House2_EventScript_Midele_HP_Electric
	case 13, FortreeCity_House2_EventScript_Midele_HP_Psychic
	case 14, FortreeCity_House2_EventScript_Midele_HP_Ice
	case 15, FortreeCity_House2_EventScript_Midele_HP_Dragon
	case 16, FortreeCity_House2_EventScript_Midele_HP_Dark
	case 17, FortreeCity_House2_EventScript_Midele_HP_Fairy
	case MULTI_B_PRESSED, FortreeCity_House2_EventScript_Midele_HiddenPowerTypeChange_NoChange
	end

FortreeCity_House2_EventScript_Midele_HiddenPowerTypeChange_NoChange::
	msgbox FortreeCity_House2_Text_Midele_HPBye, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Midele_HiddenPowerTypeChange_NoEgg::
	msgbox FortreeCity_House2_Text_Midele_HPEgg, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Midele_HP_Normal::
	 setvar VAR_0x8005, TYPE_NORMAL
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Fighting::
	 setvar VAR_0x8005, TYPE_FIGHTING
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Flying::
	 setvar VAR_0x8005, TYPE_FLYING
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Poison::
	 setvar VAR_0x8005, TYPE_POISON
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Ground::
	 setvar VAR_0x8005, TYPE_GROUND
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Rock::
	 setvar VAR_0x8005, TYPE_ROCK
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Bug::
	 setvar VAR_0x8005, TYPE_BUG
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Ghost::
	 setvar VAR_0x8005, TYPE_GHOST
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Steel::
	 setvar VAR_0x8005, TYPE_STEEL
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Fire::
	 setvar VAR_0x8005, TYPE_FIRE
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Water::
	 setvar VAR_0x8005, TYPE_WATER
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Grass::
	 setvar VAR_0x8005, TYPE_GRASS
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Electric::
	 setvar VAR_0x8005, TYPE_ELECTRIC
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Psychic::
	 setvar VAR_0x8005, TYPE_PSYCHIC
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Ice::
	 setvar VAR_0x8005, TYPE_ICE
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Dragon::
	 setvar VAR_0x8005, TYPE_DRAGON
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Dark::
	 setvar VAR_0x8005, TYPE_DARK
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply
FortreeCity_House2_EventScript_Midele_HP_Fairy::
	 setvar VAR_0x8005, TYPE_FAIRY
	 goto FortreeCity_House2_EventScript_Midele_HP_Apply

FortreeCity_House2_EventScript_Midele_HP_Apply::
	special MideleChangeSelectedMonHiddenPowerType
	playfanfare MUS_ME_WASURE
	waitfanfare
	msgbox FortreeCity_House2_Text_Midele_HPDone, MSGBOX_DEFAULT
	goto FortreeCity_House2_EventScript_Midele_HiddenPowerTypeChange_NoChange
	end

FortreeCity_House2_EventScript_Greeting:: @ 8217862
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower:: @ 821786E
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess:: @ 8217878
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature: @ 8217882
	.string "People… POKéMON…\p"
	.string "Their hidden powers are aroused by\n"
	.string "living in natural environments…$"

FortreeCity_House2_Text_CoinInWhichHand: @ 82178D6
	.string "Let this old woman see if your hidden\n"
	.string "power has awoken…\p"
	.string "I hold a coin in my hand.\p"
	.string "Now, tell me, have I palmed it in\n"
	.string "the right hand? Or in the left?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand: @ 821796A
	.string "Oh! Yes, correct!\p"
	.string "We shall try again.\p"
	.string "In which hand have I palmed the coin?\n"
	.string "The right or left?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2: @ 82179C9
	.string "Oh! Yes, correct!\p"
	.string "We shall try again.\p"
	.string "In which hand have I palmed the coin?\n"
	.string "The right or left?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken: @ 8217A28
	.string "Oh! Splendid!\n"
	.string "Your hidden power has awoken!\p"
	.string "Here, take this and awaken the hidden\n"
	.string "power of your POKéMON.$"

FortreeCity_House2_Text_ExplainHiddenPower: @ 8217A91
	.string "HIDDEN POWER is a move that changes\n"
	.string "with the POKéMON.$"

FortreeCity_House2_Text_YouGuessedWrong: @ 8217AC7
	.string "No, too bad.\n"
	.string "You guessed wrong.$"

FortreeCity_House2_Text_Midele_HPTypeGreeting:
	.string "Alabada sea Midele.\n"
	.string "Gracias al poder que me ha dado he\p"
	.string "logrado dominar el arte del PODER\n"
	.string "OCULTO... pagando un precio.\p"
	.string "Compartiré este poder contigo...\n"
	.string "¿Quieres cambiar el tipo del PODER \p"
	.string "OCULTO de alguno de tus POKéMON?$"

FortreeCity_House2_Text_Midele_HPBye:
	.string "Vuelve cuando quieras.$"

FortreeCity_House2_Text_Midele_HPTTypeChooseMon:
	.string "Elige un POKéMON.$"

FortreeCity_House2_Text_Midele_HPEgg::
	.string "No puedo cambiar el tipo del\n"
	.string "PODER OCULTO a un HUEVO.$"

FortreeCity_House2_Text_Midele_HPTypeChoose::
	.string "Elige un tipo.$"

FortreeCity_House2_Text_Midele_HPDone::
	.string "El poder de Midele ha cambiado\n"
	.string "exitosamente el tipo de PODER\p"
	.string "OCULTO de tu POKéMON.$"

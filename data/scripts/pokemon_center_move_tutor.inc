PKMN_Center_Move_Tutor::
	lockall
	message PKMN_Center_Move_Tutor_Text_HowCanHelp
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_POKE_CENTER_TUTOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, PKMN_Center_MoveReminder_EventScript
	case 1, PKMN_Center_Move_Tutor_MoveTutorIntro
	case 2, PKMN_Center_MoveDeleter_EventScript
	case 3, PKMN_Center_NameRater_EventScript
	case 4, PKMN_Center_Fly_EventScript
	case 5, PKMN_Center_Move_Tutor_General_Exit
	case MULTI_B_PRESSED, PKMN_Center_Move_Tutor_General_Exit

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Move Reminder @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

PKMN_Center_MoveReminder_EventScript::
	msgbox PKMN_Center_MoveReminder_Text_WantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, PKMN_Center_Move_Tutor_General_Exit
	goto PKMN_Center_MoveReminder_EventScriptChooseMon
	end

PKMN_Center_MoveReminder_EventScriptChooseMon:: 
	msgbox PKMN_Center_MoveReminder_Text_TutorWhichMon, MSGBOX_DEFAULT
	special ChooseMonForMoveRelearner
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq PKMN_Center_Move_Tutor_General_Exit
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq PKMN_Center_MoveReminder_EventScriptCantTeachEgg
	compare VAR_0x8005, 0
	goto_if_eq PKMN_Center_MoveReminder_EventScriptNoMoveToTeachMon
	goto PKMN_Center_MoveReminder_EventScriptChooseMove
	end

PKMN_Center_MoveReminder_EventScriptChooseMove:: 
	msgbox PKMN_Center_MoveReminder_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	compare VAR_0x8004, 0
	goto_if_eq PKMN_Center_MoveReminder_EventScriptChooseMon
	goto PKMN_Center_MoveReminder_EventScriptRememberAnotherMove
	end

PKMN_Center_MoveReminder_EventScriptNoMoveToTeachMon:: 
	msgbox PKMN_Center_MoveReminder_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto PKMN_Center_MoveReminder_EventScriptChooseMon
	end

PKMN_Center_MoveReminder_EventScriptCantTeachEgg:: 
	msgbox PKMN_Center_MoveReminder_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto PKMN_Center_MoveReminder_EventScriptChooseMon
	end
	
PKMN_Center_MoveReminder_EventScriptRememberAnotherMove::
	msgbox PKMN_Center_MoveReminder_Text_RememberAnotherMove, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PKMN_Center_Move_Tutor_General_Exit
	goto PKMN_Center_MoveReminder_EventScriptChooseMon

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Move Tutor @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

PKMN_Center_Move_Tutor_MoveTutorIntro::
	//goto_if_set FLAG_TALKED_TO_MOVE_TUTOR, PKMN_Center_Move_Tutor_MoveTutorMenu
	//msgbox PKMN_Center_Move_Tutor_Text_Explanation, MSGBOX_DEFAULT
	//setflag FLAG_TALKED_TO_MOVE_TUTOR
	goto PKMN_Center_Move_Tutor_MoveTutorMenu

PKMN_Center_Move_Tutor_MoveTutorMenu::
    goto_if_unset FLAG_BADGE04_GET, PKMN_Center_Move_Tutor_FirstGroup
    msgbox PKMN_Center_Move_Tutor_Text_WhichSetofMoves
	multichoicegrid 0, 0, MULTI_LISTAS_CIBERCAFE, 2, 0
    switch VAR_RESULT
    case 0, PKMN_Center_Move_Tutor_MoveList4
    case 1, PKMN_Center_Move_Tutor_SecondGroup
    case MULTI_B_PRESSED, PKMN_Center_Move_Tutor_ExitReturn
    releaseall
    end

PKMN_Center_Move_Tutor_FirstGroup:
    goto_if_set FLAG_BADGE03_GET, PKMN_Center_Move_Tutor_MoveList4
    goto_if_set FLAG_BADGE02_GET, PKMN_Center_Move_Tutor_MoveList3
    goto_if_set FLAG_BADGE01_GET, PKMN_Center_Move_Tutor_MoveList2
    goto PKMN_Center_Move_Tutor_MoveList1

PKMN_Center_Move_Tutor_SecondGroup:
    goto_if_set FLAG_BADGE08_GET, PKMN_Center_Move_Tutor_MoveList9
    goto_if_set FLAG_BADGE07_GET, PKMN_Center_Move_Tutor_MoveList8
    goto_if_set FLAG_BADGE06_GET, PKMN_Center_Move_Tutor_MoveList7
    goto_if_set FLAG_BADGE05_GET, PKMN_Center_Move_Tutor_MoveList6
    goto PKMN_Center_Move_Tutor_MoveList5
	
PKMN_Center_Move_Tutor_MoveList1::
	setvar VAR_TEMP_C, SCROLL_MULTI_PC_TUTOR_SET_1
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 5
	setvar VAR_0x8004, SCROLL_MULTI_PC_TUTOR_SET_1
	setvar VAR_0x8006, 0
	goto PKMN_Center_Move_Tutor_ChooseMove
	
PKMN_Center_Move_Tutor_MoveList2::
	setvar VAR_TEMP_C, SCROLL_MULTI_PC_TUTOR_SET_2
	setvar VAR_TEMP_E, 1
	setvar VAR_TEMP_F, 9
	setvar VAR_0x8004, SCROLL_MULTI_PC_TUTOR_SET_2
	setvar VAR_0x8006, 0
	goto PKMN_Center_Move_Tutor_ChooseMove

PKMN_Center_Move_Tutor_MoveList3::
	setvar VAR_TEMP_C, SCROLL_MULTI_PC_TUTOR_SET_3
	setvar VAR_TEMP_E, 2
	setvar VAR_TEMP_F, 12
	setvar VAR_0x8004, SCROLL_MULTI_PC_TUTOR_SET_3
	setvar VAR_0x8006, 0
	goto PKMN_Center_Move_Tutor_ChooseMove

PKMN_Center_Move_Tutor_MoveList4::
	setvar VAR_TEMP_C, SCROLL_MULTI_PC_TUTOR_SET_4
	setvar VAR_TEMP_E, 3
	setvar VAR_TEMP_F, 15
	setvar VAR_0x8004, SCROLL_MULTI_PC_TUTOR_SET_4
	setvar VAR_0x8006, 0
	goto PKMN_Center_Move_Tutor_ChooseMove

PKMN_Center_Move_Tutor_MoveList5::
	setvar VAR_TEMP_C, SCROLL_MULTI_PC_TUTOR_SET_5
	setvar VAR_TEMP_E, 4
	setvar VAR_TEMP_F, 3
	setvar VAR_0x8004, SCROLL_MULTI_PC_TUTOR_SET_5
	setvar VAR_0x8006, 0
	goto PKMN_Center_Move_Tutor_ChooseMove

PKMN_Center_Move_Tutor_MoveList6::
	setvar VAR_TEMP_C, SCROLL_MULTI_PC_TUTOR_SET_6
	setvar VAR_TEMP_E, 5
	setvar VAR_TEMP_F, 6
	setvar VAR_0x8004, SCROLL_MULTI_PC_TUTOR_SET_6
	setvar VAR_0x8006, 0
	goto PKMN_Center_Move_Tutor_ChooseMove

PKMN_Center_Move_Tutor_MoveList7::
	setvar VAR_TEMP_C, SCROLL_MULTI_PC_TUTOR_SET_7
	setvar VAR_TEMP_E, 6
	setvar VAR_TEMP_F, 9
	setvar VAR_0x8004, SCROLL_MULTI_PC_TUTOR_SET_7
	setvar VAR_0x8006, 0
	goto PKMN_Center_Move_Tutor_ChooseMove
	
PKMN_Center_Move_Tutor_MoveList8::
	setvar VAR_TEMP_C, SCROLL_MULTI_PC_TUTOR_SET_8
	setvar VAR_TEMP_E, 7
	setvar VAR_TEMP_F, 12
	setvar VAR_0x8004, SCROLL_MULTI_PC_TUTOR_SET_8
	setvar VAR_0x8006, 0
	goto PKMN_Center_Move_Tutor_ChooseMove
	
PKMN_Center_Move_Tutor_MoveList9::
	setvar VAR_TEMP_C, SCROLL_MULTI_PC_TUTOR_SET_9
	setvar VAR_TEMP_E, 8
	setvar VAR_TEMP_F, 15
	setvar VAR_0x8004, SCROLL_MULTI_PC_TUTOR_SET_9
	setvar VAR_0x8006, 0
	goto PKMN_Center_Move_Tutor_ChooseMove

PKMN_Center_Move_Tutor_ChooseMove::
    msgbox PKMN_Center_Move_Tutor_Text_WhichMove, MSGBOX_DEFAULT
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_D, VAR_RESULT
	compare VAR_RESULT, VAR_TEMP_F // VAR_TEMP_F is set to the ID of the "Exit" option
	goto_if_eq PKMN_Center_Move_Tutor_Exit
	compare VAR_RESULT MULTI_B_PRESSED
	goto_if_eq PKMN_Center_Move_Tutor_CloseDescriptionWindowReturn 
	goto PKMN_Center_Move_Tutor_ConfirmMoveSelection
	end
	
PKMN_Center_Move_Tutor_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_D
	copyvar VAR_0x8005, VAR_TEMP_E
	special BufferBattleFrontierTutorMoveName
	buffernumberstring 1, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox PKMN_Center_Move_Tutor_Text_IsThisRightMove, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq PKMN_Center_Move_Tutor_CloseDescriptionWindow
	goto PKMN_Center_Move_Tutor_TeachTutorMove
	end

PKMN_Center_Move_Tutor_TeachTutorMove::
	msgbox PKMN_Center_Move_Tutor_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	compare VAR_RESULT, FALSE
	goto_if_eq PKMN_Center_Move_Tutor_CloseDescriptionWindow
	msgbox PKMN_Center_Move_Tutor_Text_TeachAnotherMove, MSGBOX_YESNO
    compare VAR_RESULT, NO
	goto_if_eq PKMN_Center_Move_Tutor_Exit
    goto PKMN_Center_Move_Tutor_CloseDescriptionWindow
	end

PKMN_Center_Move_Tutor_CloseDescriptionWindow::
    special CloseBattleFrontierTutorWindow
    goto PKMN_Center_Move_Tutor_MoveTutorMenu

PKMN_Center_Move_Tutor_CloseDescriptionWindowReturn::
    special CloseBattleFrontierTutorWindow
	goto_if_set FLAG_BADGE04_GET, PKMN_Center_Move_Tutor_MoveTutorMenu
    goto PKMN_Center_Move_Tutor

PKMN_Center_Move_Tutor_ExitReturn::
    goto PKMN_Center_Move_Tutor

PKMN_Center_Move_Tutor_Exit::
	special CloseBattleFrontierTutorWindow
    msgbox PKMN_Center_Move_Tutor_Text_SeeYou, MSGBOX_DEFAULT
	releaseall
	end


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Move Deleter @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	

PKMN_Center_MoveDeleter_EventScript::
	msgbox PKMN_Center_MoveDeleter_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, PKMN_Center_MoveDeleter_EventScript_ChooseMonAndMoveToForget
	case NO, PKMN_Center_Move_Tutor_General_Exit
	releaseall
	end

PKMN_Center_MoveDeleter_EventScript_ChooseMonAndMoveToForget::
	msgbox PKMN_Center_MoveDeleter_Text_WhichMonShouldForget, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq PKMN_Center_Move_Tutor_General_Exit
	special IsSelectedMonEgg
	compare VAR_RESULT, TRUE
	goto_if_eq PKMN_Center_MoveDeleter_EventScript_EggCantForgetMoves
	special GetNumMovesSelectedMonHas
	compare VAR_RESULT, 1
	goto_if_eq PKMN_Center_MoveDeleter_EventScript_MonOnlyKnowsOneMove
	msgbox PKMN_Center_MoveDeleter_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	compare VAR_0x8005, MAX_MON_MOVES
	goto_if_eq PKMN_Center_MoveDeleter_EventScript_ChooseMonAndMoveToForget
	special BufferMoveDeleterNicknameAndMove
	msgbox PKMN_Center_MoveDeleter_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, PKMN_Center_MoveDeleter_EventScript_TryForgetMove
	case NO, PKMN_Center_Move_Tutor_General_Exit
	releaseall
	end

PKMN_Center_MoveDeleter_EventScript_TryForgetMove::
	special MoveDeleterForgetMove
	playfanfare MUS_ME_WASURE
	waitfanfare
	msgbox PKMN_Center_MoveDeleter_Text_MonHasForgottenMove, MSGBOX_DEFAULT
	releaseall
	end

PKMN_Center_MoveDeleter_EventScript_MonOnlyKnowsOneMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox PKMN_Center_MoveDeleter_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
	releaseall
	end

PKMN_Center_MoveDeleter_EventScript_EggCantForgetMoves::
	msgbox PKMN_Center_MoveDeleter_Text_EggCantForgetMoves, MSGBOX_DEFAULT
	releaseall
	end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Name Rater @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

PKMN_Center_NameRater_EventScript::
	msgbox PKMN_Center_NameRater_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_ne PKMN_Center_NameRater_EventScript_RateMonNickname
	compare VAR_0x8004, 255
	goto_if_eq PKMN_Center_Move_Tutor_General_Exit
	end

PKMN_Center_NameRater_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq PKMN_Center_NameRater_EventScript_CantRateEgg
	special BufferMonNickname
	msgbox PKMN_Center_NameRater_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	compare VAR_RESULT, TRUE
	goto_if_eq PKMN_Center_NameRater_EventScript_NewNameDifferent
	msgbox PKMN_Center_NameRater_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	releaseall
	end

PKMN_Center_NameRater_EventScript_CantRateEgg::
	msgbox PKMN_Center_NameRater_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	releaseall
	end

PKMN_Center_NameRater_EventScript_NewNameDifferent::
	msgbox PKMN_Center_NameRater_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	releaseall
	end

PKMN_Center_Move_Tutor_General_Exit::
    msgbox PKMN_Center_Move_Tutor_Text_SeeYou, MSGBOX_DEFAULT
	releaseall
	end
	
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ FLY @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	
PKMN_Center_Fly_EventScript::
	goto_if_set FLAG_BADGE06_GET, PKMN_Center_Fly_Have_Badge06_EventScript
	msgbox PKMN_Center_Fly_NO_BADGE06, MSGBOX_DEFAULT
	releaseall
	end
PKMN_Center_Fly_Have_Badge06_EventScript::
	call Common_EventScript_FlyingTaxi
	releaseall
	end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Strings @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

PKMN_Center_Move_Tutor_Text_HowCanHelp:
	.string "How can I help you today?$"

PKMN_Center_Move_Tutor_Text_WhichSetofMoves:
	.string "Which set of moves would you\n"
	.string "like to choose from?$"

PKMN_Center_Move_Tutor_Text_WhichMove:
	.string "Which move should I teach your POKéMON?$"
	
PKMN_Center_Move_Tutor_Text_IsThisRightMove:
	.string "The move {STR_VAR_1}, is it?$"

PKMN_Center_Move_Tutor_Text_TeachMoveToWhichMon:
	.string "Which POKéMON should learn\n"
	.string "{STR_VAR_1}?$"
	
PKMN_Center_Move_Tutor_Text_TeachAnotherMove:
	.string "Would you like me to teach\n"
    .string "another move?$"

PKMN_Center_Move_Tutor_Text_SeeYou:
	.string "See you later, then!$"

PKMN_Center_MoveReminder_Text_WantMeToTeachMove:
	.string "Would you like a POKéMON to remember\n"
	.string "a move it has forgotten?$"

PKMN_Center_MoveReminder_Text_TutorWhichMon:
	.string "Which POKéMON should remember a move?$"

PKMN_Center_MoveReminder_Text_TeachWhichMove:
	.string "Which move would you like it to\n"
	.string "remember?$"

PKMN_Center_MoveReminder_Text_DontHaveMoveToTeachPokemon:
	.string "I'm sorry, that POKéMON doesn't have\n"
	.string "any moves it can remember.$"

PKMN_Center_MoveReminder_Text_CantTeachEgg:
	.string "I'm sorry, an Egg can't remember any\n"
	.string "moves.$"

PKMN_Center_MoveReminder_Text_RememberAnotherMove:
	.string "Would you like a POKéMON to remember\n"
	.string "another move?$"
	
PKMN_Center_MoveDeleter_Text_ICanMakeMonForgetMove:
	.string "Would you like one of your POKéMON\n"
	.string "to forget a move?$"

PKMN_Center_MoveDeleter_Text_WhichMonShouldForget:
	.string "Which POKéMON should forget a move?$"

PKMN_Center_MoveDeleter_Text_WhichMoveShouldBeForgotten:
	.string "Which move should be forgotten?$"

PKMN_Center_MoveDeleter_Text_MonOnlyKnowsOneMove:
	.string "{STR_VAR_1} knows only one move,\n"
	.string "so it can't be forgotten.$"

PKMN_Center_MoveDeleter_Text_MonsMoveShouldBeForgotten:
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
	.string "That move should be forgotten?$"

PKMN_Center_MoveDeleter_Text_MonHasForgottenMove:
	.string "It worked to perfection!\p"
	.string "{STR_VAR_1} has forgotten\n"
	.string "{STR_VAR_2} completely.$"

PKMN_Center_MoveDeleter_Text_EggCantForgetMoves:
	.string "What?\n"
	.string "No Egg should know any moves.$"
	
PKMN_Center_NameRater_Text_CritiqueWhichMonNickname:
	.string "Which POKéMON's nickname should\n"
	.string "be changed?$"

PKMN_Center_NameRater_Text_WhatShallNewNameBe:
	.string "What would you like {STR_VAR_1}'s\n"
	.string "new nickname to be?$"

PKMN_Center_NameRater_Text_MonShallBeKnownAsName:
	.string "Done! From now on, this POKéMON\n"
	.string "shall be known as {STR_VAR_1}!$"

PKMN_Center_NameRater_Text_NameNoDifferentYetSuperior:
	.string "Okay! {STR_VAR_1}'s nickname\n"
	.string "will stay as it is.$"

PKMN_Center_NameRater_Text_ThatIsMerelyAnEgg:
	.string "Now, now.\n"
	.string "That is merely an Egg!$"
	
PKMN_Center_Fly_NO_BADGE06:
	.string "This option is not yet available.\n"
	.string "Come back when you have six badges.$"


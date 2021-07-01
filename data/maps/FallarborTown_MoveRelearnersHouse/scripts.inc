FallarborTown_MoveRelearnersHouse_MapScripts:: @ 8201382
	.byte 0
	
FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_RECEIVED_EGG, FallarborTown_MoveRelearnersHouse_EventScript_ReceivedEgg
	goto FallarborTown_MoveRelearnersHouse_EventScript_TryGiveEgg

FallarborTown_MoveRelearnersHouse_EventScript_TryGiveEgg::
	checkitem ITEM_HEART_SCALE, 3
	compare VAR_RESULT, TRUE
	call_if_eq FallarborTown_MoveRelearnersHouse_EventScript_ReceivedMon
	goto FallarborTown_EventScript_No3HeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_ReceivedMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_DeclineEgg
	specialvar VAR_0x8006, CalculatePlayerPartyCount
	compare VAR_0x8006, PARTY_SIZE
	goto_if_eq FallarborTown_MoveRelearnersHouse_EventScript_NoRoomForEgg
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThankYou, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE, 3
	setflag FLAG_DAILY_RECEIVED_EGG
	playfanfare MUS_FANFA4
	message FallarborTown_MoveRelearnersHouse_Text_ReceivedTheEgg
	special SetSpeciesAndEggMove
	waitfanfare
	giveEgg VAR_0x8004
	special SetGiftEggMove
	release
	end

FallarborTown_MoveRelearnersHouse_EventScript_ReceivedEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_SometimesEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoRoomForEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

FallarborTown_MoveRelearnersHouse_EventScript_DeclineEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end
	
FallarborTown_EventScript_No3HeartScale:: @ 8270F57
	msgbox FallarborTown_MoveRelearnersHouse_Text_YouHaventGotThreeHS, MSGBOX_DEFAULT
	release
	end

FallarborTown_MoveRelearnersHouse_Text_HaveEggWillYouTakeIt:
	.string "Oh, hey! That…\n"
	.string "That's a HEART SCALE!\l" 
	.string "I'm looking for those!\p"
	.string "Oh, man, you've got to trade\n"
	.string "3 HEART SCALE with me!\l"
	.string "I'll give you an EGG.\p"
	.string "Would you be interested\n"
	.string "in taking it?$"

FallarborTown_MoveRelearnersHouse_Text_ThankYou:
	.string "Oh, thank you! Please take good care\n"
	.string "of this EGG!$"

FallarborTown_MoveRelearnersHouse_Text_ReceivedTheEgg:
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.\p"

	.string "{PLAYER} received the EGG.$"

FallarborTown_MoveRelearnersHouse_Text_NoRoomForThisEgg:
	.string "Oh? You've got a full party.\n"
	.string "There's no room for this EGG...$"

FallarborTown_MoveRelearnersHouse_Text_AsYouWishThen:
	.string "Oh…\p"
	.string "That's a shame. Let me know if you\n"
	.string "change your mind.$"

FallarborTown_MoveRelearnersHouse_Text_SometimesEggFoundAtDayCare:
	.string "Come back tomorrow, I'll need\n"
	.string "more HEART SCALE.\p"
	.string "In return I'll give you another egg.$"
	
FallarborTown_MoveRelearnersHouse_Text_YouHaventGotThreeHS: @ 8271027
	.string "You haven't got three HEART SCALE.$"

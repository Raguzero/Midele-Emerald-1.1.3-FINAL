IzabeIsland_MicoloTruck_MapScripts::
	.byte 0

IzabeIsland_MicoloTruck_EventScript_ItemChoiceSpecs::
	finditem ITEM_CHOICE_SPECS
	end

IzabeIsland_MicoloTruck_EventScript_ItemChoiceBand::
	finditem ITEM_CHOICE_BAND
	end

IzabeIsland_MicoloTruck_EventScript_ItemChoiceScarf::
	finditem ITEM_CHOICE_SCARF
	end

IzabeIsland_MicoloTruck_EventScript_ItemGCalcium::
	finditem ITEM_G_CALCIUM
	end

IzabeIsland_MicoloTruck_EventScript_GiftHonedge::
	lock
	setvar VAR_TEMP_1, SPECIES_HONEDGE_MONADO
	givemon SPECIES_HONEDGE_MONADO, 45, ITEM_MASTER_BALL
	compare VAR_RESULT, 0
	goto_if_eq IzabeIsland_MicoloTruck_EventScript_ReceiveMonParty
	compare VAR_RESULT, 1
	goto_if_eq IzabeIsland_MicoloTruck_EventScript_ReceiveMonPC
	goto Common_EventScript_NoMoreRoomForPokemon 
	release
	end

IzabeIsland_MicoloTruck_EventScript_ReceiveMonParty:: @ 8270085
	call IzabeIsland_MicoloTruck_EventScript_ReceiveMonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq IzabeIsland_MicoloTruck_EventScript_ReceiveMonEnd
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto IzabeIsland_MicoloTruck_EventScript_ReceiveMonEnd
	end

IzabeIsland_MicoloTruck_EventScript_ReceiveMonPC:: @ 82700AD
	call IzabeIsland_MicoloTruck_EventScript_ReceiveMonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq IzabeIsland_MicoloTruck_EventScript_SendMonPC
	call Common_EventScript_NameReceivedBoxMon
	goto IzabeIsland_MicoloTruck_EventScript_SendMonPC
	end
	
IzabeIsland_MicoloTruck_EventScript_SendMonPC:: @ 82700D0
	call Common_EventScript_TransferredToPC
	goto IzabeIsland_MicoloTruck_EventScript_ReceiveMonEnd
	end

IzabeIsland_MicoloTruck_EventScript_ReceiveMonFanfare:: @ 82700DB
	playfanfare MUS_FANFA4
	message IzabeIsland_MicoloTruck_Text_ReceivedMon
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_HONEDGE_MONADO
	return

IzabeIsland_MicoloTruck_EventScript_ReceiveMonEnd:
	setflag FLAG_RECEIVED_HONEDGE
	removeobject 5
	release
	end

IzabeIsland_MicoloTruck_Text_ReceivedMon: @ 82706E8
	.string "{PLAYER} received HONEDGE!$"

Std_ObtainItem:: @ 8271AD3
	copyvar VAR_0x8004, VAR_0x8000
	copyvar VAR_0x8005, VAR_0x8001
	additem VAR_0x8000, VAR_0x8001
	copyvar VAR_0x8007, VAR_RESULT
	compare VAR_0x8007, 0
	call_if_eq EventScript_TryAddItemToPCObtain
	call EventScript_ObtainItemMessage
	return
	
EventScript_TryAddItemToPCObtain::
	checkitemtype VAR_0x8004 @ Don't add if it's a key item
	compare VAR_RESULT, POCKET_KEY_ITEMS
	goto_if_eq EventScript_TryAddItemToPCObtainContinue
	addpcitem VAR_0x8004, VAR_0x8005
	compare VAR_RESULT, 0
	call_if_eq EventScript_TryAddItemToPCObtainContinue
	setvar VAR_0x8007, 2  @ (0= full, 1= in pocket, 2=in PC) 
EventScript_TryAddItemToPCObtainContinue::
	return

EventScript_ObtainItemMessage:: @ 8271AE3
	bufferitemnameplural 1, VAR_0x8000, VAR_0x8001
	checkitemtype VAR_0x8000
	call EventScript_BufferPocketNameAndTryFanfare
	compare VAR_0x8007, 0
	call_if_ne EventScript_ObtainedItem
	compare VAR_0x8007, 0
	call_if_eq EventScript_NoRoomForItem
	return

EventScript_BufferPocketNameAndTryFanfare:: @ 8271B08
	switch VAR_RESULT
	case POCKET_ITEMS, EventScript_BufferItemsPocket
	case POCKET_KEY_ITEMS, EventScript_BufferKeyItemsPocket
	case POCKET_POKE_BALLS, EventScript_BufferPokeballsPocket
	case POCKET_TM_HM, EventScript_BufferTMHMsPocket
	case POCKET_BERRIES, EventScript_BufferBerriesPocket
	end

EventScript_BufferItemsPocket:: @ 8271B45
	bufferstdstring 2, STDSTRING_ITEMS
	compare VAR_0x8007, 0
	call_if_ne EventScript_PlayFanfareObtainedItem
	return

EventScript_BufferKeyItemsPocket:: @ 8271B55
	bufferstdstring 2, STDSTRING_KEYITEMS
	compare VAR_0x8007, 0
	call_if_ne EventScript_PlayFanfareObtainedItem
	return

EventScript_BufferPokeballsPocket:: @ 8271B65
	bufferstdstring 2, STDSTRING_POKEBALLS
	compare VAR_0x8007, 0
	call_if_ne EventScript_PlayFanfareObtainedItem
	return

EventScript_BufferTMHMsPocket:: @ 8271B75
	bufferstdstring 2, STDSTRING_TMHMS
	compare VAR_0x8007, 0
	call_if_ne EventScript_PlayFanfareObtainedTMHM
	return

EventScript_BufferBerriesPocket:: @ 8271B85
	bufferstdstring 2, STDSTRING_BERRIES
	compare VAR_0x8007, 0
	call_if_ne EventScript_PlayFanfareObtainedItem
	return

EventScript_ObtainedItem:: @ 8271B95
	compare VAR_0x8001, 1
	goto_if_eq EventScript_ObtainedItemMessage
	buffernumberstring 0, VAR_0x8001
	message gText_ObtainedTheItems
	goto EventScript_ContinueObtainedItem
EventScript_ObtainedItemMessage:
	message gText_ObtainedTheItem
EventScript_ContinueObtainedItem:
	waitfanfare
	call EventScript_PutItemMsg
	setvar VAR_RESULT, 1
	return

EventScript_NoRoomForItem:: @ 8271BA9
	setvar VAR_RESULT, 0
	return

EventScript_PlayFanfareObtainedItem:: @ 8271BAF
	playfanfare MUS_FANFA4
	return

EventScript_PlayFanfareObtainedTMHM:: @ 8271BB3
	playfanfare MUS_ME_WAZA
	return

Std_ObtainDecoration:: @ 8271BB7
	adddecoration VAR_0x8000
	copyvar VAR_0x8007, VAR_RESULT
	call EventScript_ObtainDecorationMessage
	return

EventScript_ObtainDecorationMessage:: @ 8271BC5
	bufferdecorationname 1, VAR_0x8000
	compare VAR_0x8007, 1
	call_if_eq EventScript_ObtainedDecor
	compare VAR_0x8007, 0
	call_if_eq EventScript_NoRoomForDecor
	return

EventScript_ObtainedDecor:: @ 8271BE0
	playfanfare MUS_FANFA4
	message gText_ObtainedTheDecor
	waitfanfare
	msgbox gText_TheDecorWasTransferredToThePC, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

EventScript_NoRoomForDecor:: @ 8271BF7
	setvar VAR_RESULT, 0
	return

Std_FindItem:: @ 8271BFD
	lock
	faceplayer
	waitse
	copyvar VAR_0x8004, VAR_0x8000
	copyvar VAR_0x8005, VAR_0x8001
	checkitemspace VAR_0x8000, VAR_0x8001
	copyvar VAR_0x8007, VAR_RESULT
	compare VAR_0x8007, 0
	call_if_eq EventScript_CheckPCSpace
	bufferitemnameplural 1, VAR_0x8000, VAR_0x8001
	checkitemtype VAR_0x8000
	call EventScript_BufferPocketNameAndTryFanfare
	compare VAR_0x8007, 0
	call_if_ne EventScript_PickUpItem
	compare VAR_0x8007, 0
	call_if_eq EventScript_NoRoomToPickUpItem
	release
	return
	
EventScript_CheckPCSpace::
	checkitemtype VAR_0x8004 @ Don't add if it's a key item
	compare VAR_RESULT, POCKET_KEY_ITEMS
	goto_if_eq EventScript_CheckPCSpaceContinue
	pyramid_inchallenge
	copyvar VAR_0x8004, VAR_0x8000  @ pyramid_inchallenge modifies VAR_0x8004
	compare VAR_RESULT, 1
	goto_if_eq EventScript_CheckPCSpaceContinue
	checkpcspace VAR_0x8004, VAR_0x8005
	compare VAR_RESULT, 0
	call_if_eq EventScript_CheckPCSpaceContinue
	setvar VAR_0x8007, 2  @ (0= full, 1= in pocket, 2=in PC) 
EventScript_CheckPCSpaceContinue::
	return

EventScript_PickUpItem:: @ 8271C3A
	removeobject VAR_LAST_TALKED
	compare VAR_0x8007, 2
	goto_if_eq EventScript_PickUpItemPCAdd
	additem VAR_0x8004, VAR_0x8005
	goto EventScript_PickUpItemContinueAdd
EventScript_PickUpItemPCAdd::
	addpcitem VAR_0x8004, VAR_0x8005
EventScript_PickUpItemContinueAdd::
	specialvar VAR_RESULT, BufferTMHMMoveName
	copyvar VAR_0x8008, VAR_RESULT
	compare VAR_0x8008, 1
	call_if_eq EventScript_FoundTMHM
	compare VAR_0x8008, 0
	call_if_eq EventScript_FoundItem
	waitfanfare
	waitmessage
	bufferitemnameplural 1, VAR_0x8004, VAR_0x8005
	pyramid_inchallenge
	compare VAR_RESULT, 1
	goto_if_eq EventScript_PutBattlePyramidItemInBag
	call EventScript_PutItemMsg
	return

EventScript_PutBattlePyramidItemInBag:: @ 8271C86
	msgbox gText_PlayerPutItemInBag, MSGBOX_DEFAULT
	return

EventScript_FoundTMHM:: @ 8271C8F
	bufferitemnameplural 0, VAR_0x8004, VAR_0x8005
	message gText_PlayerFoundOneTMHM
	return

EventScript_FoundItem:: @ 8271C9B
	message gText_PlayerFoundOneItem
	return

EventScript_NoRoomToPickUpItem:: @ 8271CA1
	msgbox gText_ObtainedTheItem, MSGBOX_DEFAULT
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

EventScript_HiddenItemScript:: @ 8271CB7
	lockall
	waitse
	additem VAR_0x8005
	copyvar VAR_0x8007, VAR_RESULT
	compare VAR_0x8007, 0
	call_if_eq EventScript_TryAddItemToPCHidden
	bufferitemnameplural 1, VAR_0x8005, 1
	checkitemtype VAR_0x8005
	call EventScript_BufferPocketNameAndTryFanfare
	compare VAR_0x8007, 0
	goto_if_ne EventScript_PickUpHiddenItem
	compare VAR_0x8007, 0
	goto_if_eq EventScript_NoRoomForHiddenItem
	end
	
EventScript_TryAddItemToPCHidden::
	checkitemtype VAR_0x8005 @ Don't add if it's a key item
	compare VAR_RESULT, POCKET_KEY_ITEMS
	goto_if_eq EventScript_TryAddHiddenItemToPCContinue
	addpcitem VAR_0x8004, VAR_0x8005  // ??  por que en la wiki es 	addpcitem VAR_0x8005  ???
	compare VAR_RESULT, 0
	call_if_eq EventScript_TryAddHiddenItemToPCContinue
	setvar VAR_0x8007, 2  @ (0= full, 1= in pocket, 2=in PC) 
EventScript_TryAddHiddenItemToPCContinue::
	return

EventScript_PickUpHiddenItem:: @ 8271CE8
	copyvar VAR_0x8008, VAR_0x8004
	copyvar VAR_0x8004, VAR_0x8005
	specialvar VAR_RESULT, BufferTMHMMoveName
	compare VAR_RESULT, 1
	goto_if_eq EventScript_FoundHiddenTMHM
	compare VAR_RESULT, 0
	goto_if_eq EventScript_FoundHiddenItem
	end

EventScript_FoundHiddenTMHM:: @ 8271D0E
	bufferitemnameplural 0, VAR_0x8004, 1
	message gText_PlayerFoundOneTMHM
	goto EventScript_PutHiddenItemInPocket
	end

EventScript_FoundHiddenItem:: @ 8271D1F
	message gText_PlayerFoundOneItem
	goto EventScript_PutHiddenItemInPocket
	end

EventScript_PutHiddenItemInPocket:: @ 8271D2A
	waitmessage
	waitfanfare
	bufferitemnameplural 1, VAR_0x8004, 1
	copyvar VAR_0x8004, VAR_0x8008
	call EventScript_PutItemMsg
	special TryPutTreasureInvestigatorsOnAir
	special SetHiddenItemFlag
	releaseall
	end
	
EventScript_PutItemMsg::
	compare VAR_0x8007, 2
	goto_if_eq EventScript_PutItemPCMsg
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto EventScript_PutItemContinueMsg
EventScript_PutItemPCMsg::
	msgbox gText_PutItemInPC, MSGBOX_DEFAULT
EventScript_PutItemContinueMsg::
	return

EventScript_NoRoomForHiddenItem:: @ 8271D47
	msgbox gText_PlayerFoundOneItem, MSGBOX_DEFAULT
	msgbox gText_TooBadBagAndPCAreFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	releaseall
	end

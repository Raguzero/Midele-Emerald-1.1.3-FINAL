DesertUnderpass_MapScripts:: @ 823AF37
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	.byte 0

DesertUnderpass_OnTransition: @ 823AF3D
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	end

Desert_Underpass_EventScript_HeartScale::
	giveitem ITEM_HEART_SCALE, 3
	compare VAR_RESULT, FALSE
	call_if_eq Desert_Underpass_BagFull
	closemessage
	removeobject 4
	setflag FLAG_ITEM_DESERTUNDERPASS_HEART_SCALE
	end
	
Desert_Underpass_BagFull::
	call Common_EventScript_BagIsFull
	closemessage
	release
	end

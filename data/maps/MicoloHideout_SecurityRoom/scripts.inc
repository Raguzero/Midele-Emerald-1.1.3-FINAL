MicoloHideout_SecurityRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MicoloHideout_SecurityRoom_OnTransition
	.byte 0

MicoloHideout_SecurityRoom_OnTransition:
  setflag FLAG_LANDMARK_MICOLO_HIDEOUT
  end

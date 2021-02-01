ShoalCave_LowTideIceRoom_MapScripts:: @ 82396A1
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideIceRoom_OnLoad
	.byte 0

ShoalCave_LowTideIceRoom_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, ShoalCave_LowTideIceRoom_EventScript_CloseSuicune
	end

ShoalCave_LowTideIceRoom_EventScript_CloseSuicune::
	setmetatile 10, 2, 0x37E, 1
	setmetatile 11, 2, 0x37E, 1
	return

ScorchedSlab_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ScorchedSlab_B2F_OnLoad
	.byte 0

ScorchedSlab_B2F_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, ScorchedSlab_B2F_EventScript_CloseEntei
	end

ScorchedSlab_B2F_EventScript_CloseEntei::
	setmetatile 17, 4, 0x202, 1
	setmetatile 18, 4, 0x202, 1
	setmetatile 19, 4, 0x202, 1
	return

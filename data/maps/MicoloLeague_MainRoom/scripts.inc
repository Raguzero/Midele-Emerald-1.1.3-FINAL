MicoloLeague_MainRoom_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, MicoloLeague_MainRoom_OnLoad
	.byte 0

MicoloLeague_MainRoom_OnLoad::
    checktrainerflag TRAINER_PACOCHEF_MICOLANDIA
    call_if_eq MicoloLeague_MainRoom_BlockPacochefRoom
    end

MicoloLeague_MainRoom_BlockPacochefRoom:
    setmetatile 11, 9, 0x380,  0
    return

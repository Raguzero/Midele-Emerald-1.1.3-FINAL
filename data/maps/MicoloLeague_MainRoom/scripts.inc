MicoloLeague_MainRoom_MapScripts::
    map_script MAP_SCRIPT_ON_LOAD, MicoloLeague_MainRoom_OnLoad
	.byte 0

MicoloLeague_MainRoom_OnLoad::
    checktrainerflag TRAINER_PACOCHEF_MICOLANDIA
    call_if_eq MicoloLeague_MainRoom_BlockPacochefRoom
    checktrainerflag TRAINER_AVADER_MICOLANDIA
    call_if_eq MicoloLeague_MainRoom_BlockVaderRoom
    checktrainerflag TRAINER_LAVENDER_MICOLANDIA
    call_if_eq MicoloLeague_MainRoom_BlockLavenderRoom
    checktrainerflag TRAINER_RAGU
    call_if_eq MicoloLeague_MainRoom_BlockRaguRoom

    call MicoloLeague_MainRoom_TryBlockFinalRoom
    end

MicoloLeague_MainRoom_BlockPacochefRoom:
    setmetatile 11, 9, 0x380,  0
    return

MicoloLeague_MainRoom_BlockVaderRoom:
    setmetatile 6, 5, 0x380,  0
    return

MicoloLeague_MainRoom_BlockLavenderRoom:
    setmetatile 6, 9, 0x380,  0
    return
    
MicoloLeague_MainRoom_BlockRaguRoom:
    setmetatile 11, 5, 0x380,  0
    return

MicoloLeague_MainRoom_TryBlockFinalRoom::
	checktrainerflag TRAINER_PACOCHEF_MICOLANDIA
	goto_if 0, MicoloLeague_MainRoom_TryBlockFinalRoom_2
	checktrainerflag TRAINER_AVADER_MICOLANDIA
	goto_if 0, MicoloLeague_MainRoom_TryBlockFinalRoom_2
	checktrainerflag TRAINER_RAGU
	goto_if 0, MicoloLeague_MainRoom_TryBlockFinalRoom_2
	checktrainerflag TRAINER_LAVENDER_MICOLANDIA
	goto_if 0, MicoloLeague_MainRoom_TryBlockFinalRoom_2
MicoloLeague_MainRoom_TryBlockFinalRoom_1:
	return

MicoloLeague_MainRoom_TryBlockFinalRoom_2:
	setobjectxyperm 1, 8, 2
	setobjectxyperm 2, 9, 2
	goto MicoloLeague_MainRoom_TryBlockFinalRoom_1

MicoloLeague_VaderRoom_EventScript_Mewtwo::
    lock
    faceplayer 
    waitse
    playmoncry SPECIES_MEWTWO, 0
    msgbox MicoloLeagueLobby_Text_Mewtwo, MSGBOX_DEFAULT
    waitmoncry
    release
    end

MicoloLeague_MainRoom_EventScript_PCExplanation::
    msgbox MicoloLeague_MainRoom_Text_PCExplanation, MSGBOX_SIGN
    end

MicoloLeagueLobby_Text_Mewtwo:
    .string "MEWTWO: ¡Twooo!$"

MicoloLeague_MainRoom_Text_PCExplanation:
    .string "Explicación de la MICOLIGA:\p"
    .string "Deberás enfrentarte a los cuatro\n"
    .string "entrenadores de la MICOLIGA, y una vez\l"
    .string "los derrotes, podrás luchar contra el\l"
    .string "CAMPEÓN.\p"
    .string "Los cuatro teletransportadores del\n"
    .string "suelo te llevarán a las salas de los\l"
    .string "cuatro entrenadores. Una vez entres\l"
    .string "en una sala, no podrás salir hasta que\l"
    .string "derrotes a su entrenador o seas\l"
    .string "derrotado.\p"
    .string "Fin de la explicación de la MICOLIGA.$"

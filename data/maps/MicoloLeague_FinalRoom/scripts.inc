MicoloLeague_FinalRoom_MapScripts::
	.byte 0

MicoloLeague_FinalRoom_Micolo::
	lockall
	faceplayer
	trainerbattle_single TRAINER_MICOLO_MICOLANDIA, MicoloLeague_FinalRoom_Micolo_Text_0, MicoloLeague_FinalRoom_Micolo_Text_1, MicoloLeague_FinalRoom_Micolo_Defeat, FALSE
	releaseall
	return


MicoloLeague_FinalRoom_Micolo_Defeat::
	lockall
	checkitem ITEM_PSYCHE_ARMOR, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MicoloLeague_FinalRoom_Micolo_Defeat_2
MicoloLeague_FinalRoom_Micolo_Defeat_1:
	playbgm SASAGEYO, 0 @ TODO: cambiar por música apropiada para el final del juego
	msgbox MicoloLeague_FinalRoom_Micolo_Defeat_Text_1, MSGBOX_DEFAULT
	call MicoloLeague_FinalRoom_GameEndFlags
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MicoloLeague_FinalRoom_Micolo_Defeat_5
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
MicoloLeague_FinalRoom_Micolo_Defeat_4:
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClear @ TODO: no hacer que se registre en el HALL OF FAME
	waitstate
	releaseall
	return

MicoloLeague_FinalRoom_Micolo_Defeat_2:
	msgbox MicoloLeague_FinalRoom_Micolo_Defeat_Text_0, MSGBOX_DEFAULT
	giveitem ITEM_PSYCHE_ARMOR, 1
	goto MicoloLeague_FinalRoom_Micolo_Defeat_1

MicoloLeague_FinalRoom_Micolo_Defeat_5:
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	goto MicoloLeague_FinalRoom_Micolo_Defeat_4


MicoloLeague_FinalRoom_GameEndFlags::
	cleartrainerflag TRAINER_PACOCHEF_MICOLANDIA
	cleartrainerflag TRAINER_LAVENDER_MICOLANDIA
	cleartrainerflag TRAINER_AVADER_MICOLANDIA
	cleartrainerflag TRAINER_RAGU
    cleartrainerflag TRAINER_MICOLO_MICOLANDIA
	return


MicoloLeague_FinalRoom_Micolo_Text_0:
	.string "TEXTO MICOLO PREBATTLE$"

MicoloLeague_FinalRoom_Micolo_Text_1:
	.string "TEXTO MICOLO DEFEAT$"

MicoloLeague_FinalRoom_Micolo_Defeat_Text_0:
	.string "TEXTO GIVE PSYCHE ARMOR$"

MicoloLeague_FinalRoom_Micolo_Defeat_Text_1:
	.string "TEXTO TE PASASTE EL JUEGO$"


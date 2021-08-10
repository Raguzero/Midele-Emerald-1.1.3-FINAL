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
	setflag FLAG_FORM_SPOILER_DEX
	checkitem ITEM_PSYCHE_ARMOR, 1
	compare VAR_RESULT, FALSE
	goto_if_eq MicoloLeague_FinalRoom_Micolo_Defeat_2
MicoloLeague_FinalRoom_Micolo_Defeat_1:
	msgbox MicoloLeague_FinalRoom_Micolo_Defeat_Text_1, MSGBOX_DEFAULT
	call MicoloLeague_FinalRoom_GameEndFlags
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq MicoloLeague_FinalRoom_Micolo_Defeat_5
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
MicoloLeague_FinalRoom_Micolo_Defeat_4:
	special SavePostMicolo @ Guarda partida
	closemessage
	fadescreenspeed FADE_TO_BLACK, 24
	special ShowGameCredits @ Muestra créditos
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
	.string "Enhorabuena por derrotar al inútil y\n"
	.string "vencer a los tres PALLASOS. Ahora te\l"
	.string "enfrentarás a la pesadilla Midelar.$"

MicoloLeague_FinalRoom_Micolo_Text_1:
.string "Monociclo porque mono es uno y la vida\n"
.string "es un ciclo.$"

MicoloLeague_FinalRoom_Micolo_Defeat_Text_0:
	.string "Te hago entrega de este pequeño\n"
	.string "regalo.$"

MicoloLeague_FinalRoom_Micolo_Defeat_Text_1:
	.string "No creas que hayas ganado por ser\n"
	.string "bueno, a Shadow Pikachu no le apetecía\l"
	.string "luchar como sabe tras haber visto\l"
	.string "todos tus combates, le hubiera dado\l"
	.string "lástima humillar a un entrenador al que\l"
	.string "respeta, como es tu caso.$"

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
	.string "Así que volvemos a vernos. n.n\n"
	.string "Enhorabuena por derrotar al smod inútil\l"
	.string "y vencer a los tres PALLASOS.\p"

	.string "Desde la primera vez que te ví, supe\n"
	.string "que llegarías hasta aquí.\p"
	
	.string "Durante mis viajes estuve pensando\n" 
	.string "en hacer algo diferente a los desafíos\l" 
	.string "a los que me enfrentaba. En mi aventura\l" 
	.string "por HOENN descubrí el BATTLE FRONTIER,\l"
	.string "en ese lugar se me ocurrió lo que estaba\l" 
	.string "pensando en mis otros viajes,\l" 
	.string "el desafío definitivo, por esa razón\l"
	.string "construí con la ayuda de mis POKéMON y\l" 
	.string "mis más fieles seguidores, el lugar\l"
	.string "donde estamos ahora.\p"
	
	.string "¿Todo listo? ¡Ahora te enfrentarás a la\n" 
	.string "pesadilla Midelar!$"

MicoloLeague_FinalRoom_Micolo_Text_1:
	.string "Monociclo porque mono es uno y la vida\n"
	.string "es un ciclo.$"

MicoloLeague_FinalRoom_Micolo_Defeat_Text_0:
	.string "Te hago entrega de este pequeño\n"
	.string "regalo, fruto de una de mis más\l"
	.string "ambiciosas investigaciones.\p"
	
	.string "¡Con esto podrás hacer que MEWTWO\n"
	.string "alcance su máximo potencial!$"

MicoloLeague_FinalRoom_Micolo_Defeat_Text_1:
	.string "¡Superaste la MICOLIGA, el mayor\n"
	.string "desafío de todos los tiempos!\p"

	.string "Y para que conste tu victoria,\n"
	.string "todos los POKéMON de tu equipo serán\l"
	.string "galardonados con 7 RIBBONS especiales\l"
	.string "que darán fe de que habeis superado\l"
	.string "todos los Desafíos de la MICOLIGA.\p"
	
	.string "¡Enhorabuena {PLAYER} n.n!\p"

	.string "Pero no creas que hayas ganado por ser\n"
	.string "bueno, a Shadow Pikachu no le apetecía\l"
	.string "luchar como sabe tras haber visto\l"
	.string "todos tus combates, le hubiera dado\l"
	.string "lástima humillar a un entrenador al que\l"
	.string "respeta, como es tu caso.\p"
	
	.string "Bueno, {PLAYER}, espero que nos\n"
	.string "volvamos a ver, ¡hasta entonces!$"

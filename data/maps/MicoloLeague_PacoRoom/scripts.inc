MicoloLeague_PacoRoom_MapScripts::
	.byte 0

MicoloLeague_PacoRoom_Piba1::
	lock
	goto_if_unset FLAG_TEMP_1, MicoloLeague_PacoRoom_Piba1_2
	msgbox MicoloLeague_PacoRoom_Piba1_Text_1, MSGBOX_NPC
MicoloLeague_PacoRoom_Piba1_1:
	release
	return

MicoloLeague_PacoRoom_Piba1_2:
	msgbox MicoloLeague_PacoRoom_Piba1_Text_0, MSGBOX_NPC
	setflag FLAG_TEMP_1
	goto MicoloLeague_PacoRoom_Piba1_1


MicoloLeague_PacoRoom_Piba2::
	lock
	goto_if_unset FLAG_TEMP_2, MicoloLeague_PacoRoom_Piba2_2
	msgbox MicoloLeague_PacoRoom_Piba2_Text_0, MSGBOX_NPC
MicoloLeague_PacoRoom_Piba2_1:
	release
	return

MicoloLeague_PacoRoom_Piba2_2:
	msgbox MicoloLeague_PacoRoom_Piba1_Text_0, MSGBOX_NPC
	setflag FLAG_TEMP_2
	goto MicoloLeague_PacoRoom_Piba2_1


MicoloLeague_PacoRoom_HombreDeAsul::
	msgbox MicoloLeague_PacoRoom_HombreDeAsul_Text_0, MSGBOX_NPC
	return


MicoloLeague_PacoRoom_Candela::
	msgbox MicoloLeague_PacoRoom_Candela_Text_0, MSGBOX_NPC
	return


MicoloLeague_PacoRoom_CameraMan::
	msgbox MicoloLeague_PacoRoom_CameraMan_Text_0, MSGBOX_NPC
	return


MicoloLeague_PacoRoom_SnorlaxDoll::
	msgbox MicoloLeague_PacoRoom_SnorlaxDoll_Text_0, MSGBOX_NPC
	return


MicoloLeague_PacoRoom_CyndaDoll::
	msgbox MicoloLeague_PacoRoom_CyndaDoll_Text_0, MSGBOX_NPC
	return


MicoloLeague_PacoRoom_Latias::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_LATIAS, 0
	msgbox MicoloLeague_PacoRoom_Latias_Text_0, MSGBOX_DEFAULT
	waitmoncry
	release
	return


MicoloLeague_PacoRoom_Latios::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_LATIOS, 0
	msgbox MicoloLeague_PacoRoom_Latios_Text_0, MSGBOX_DEFAULT
	waitmoncry
	release
	return


MicoloLeague_PacoRoom_Suicune::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SUICUNE, 0
	msgbox MicoloLeague_PacoRoom_Suicune_Text_0, MSGBOX_DEFAULT
	waitmoncry
	release
	return


MicoloLeague_PacoRoom_Piba1_Text_0:
	.string "Bienvenido a la estancia de Paquito el\n"
	.string "chocolatero. Fumar está permitido.\l"
	.string "Tirarse por los pozos no, que limpiar\l"
	.string "cadáveres es asqueroso.$"

MicoloLeague_PacoRoom_Piba1_Text_1:
	.string "¿Qué? No tengo nada más que decir,\n"
	.string "largo, atontao.$"

MicoloLeague_PacoRoom_Piba2_Text_0:
	.string "Fuera, bicho, tira pa'lante.$"

MicoloLeague_PacoRoom_HombreDeAsul_Text_0:
	.string "¿Oh? Un amigo de Paco, ya veo. Soy uno\n"
	.string "de los alter-egos de ese autista,\l"
	.string "Francesco. Me usa para hacer el payaso\l"
	.string "en roles. Podría apuñalarte aquí y\l"
	.string "ahora, pero creo que está esperando\l"
	.string "por ti. Espero que me deje tus restos.$"

MicoloLeague_PacoRoom_Candela_Text_0:
	.string "Hostia, ¡hola {PLAYER}!\p"
	.string "¿...que qué hago aquí? Entre tú y yo, sí,\n"
	.string "soy la líder de tipo fuego. Pero eso no\l"
	.string "significa que no pueda estar CALIENTE.\l"
	.string "Mind your own business. ¡Suerte!$"

MicoloLeague_PacoRoom_CameraMan_Text_0:
	.string "¡AAAAAH Y TÚ QUIÉN ERES!\p"
	.string "¿...vienes a derrotar a Micolo? ¿A\n"
	.string "SALVARNOS? Mis plegarias han sido\l"
	.string "escuchadas :D\p"
	.string "Soy Fran, el real, no ese bicho chungo\n"
	.string "que se hace llamar Pacochef. Tengo un\l"
	.string "trabajo de mierda como cámara, esos\l"
	.string "pelotudos de Shiyo y Nacho me han\l"
	.string "pedido que grabe todo para que se\l"
	.string "pueda ver en el emulador. Grrrr, se van\l"
	.string "a enterar cuando salga de aquí.\p"
	.string "...espera, ¿cómo que solo soy un NPC?\n"
	.string "¡VUELVE AQUÍ, CABRÓN!$"

MicoloLeague_PacoRoom_SnorlaxDoll_Text_0:
	.string "Es un Snorlax dormido... está abrazando\n"
	.string "un cristal Midelar.$"

MicoloLeague_PacoRoom_CyndaDoll_Text_0:
	.string "Es un muñeco de Cyndaquil. Hay una nota\n"
	.string "al lado...\p"
	.string "“Nunca olvides de dónde vienes y cómo\n"
	.string "empezó todo.”$"

MicoloLeague_PacoRoom_Latias_Text_0:
	.string "TIAAAS...$"

MicoloLeague_PacoRoom_Latios_Text_0:
	.string "TIOOOS...$"

MicoloLeague_PacoRoom_Suicune_Text_0:
	.string "Cuuuune...$"


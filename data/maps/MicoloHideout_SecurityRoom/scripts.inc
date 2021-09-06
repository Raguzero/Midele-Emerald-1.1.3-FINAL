MicoloHideout_SecurityRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MicoloHideout_SecurityRoom_OnTransition
	.byte 0

MicoloHideout_SecurityRoom_OnTransition:
  setflag FLAG_LANDMARK_MICOLO_HIDEOUT
  end

MicoloHideout_SecurityRoom_PC1::
	playse SE_PC_LOGIN
	waitse
	msgbox MicoloHideout_SecurityRoom_PC1_Text_0, MSGBOX_SIGN
	return


MicoloHideout_SecurityRoom_PC2::
	playse SE_PC_LOGIN
	waitse
	msgbox MicoloHideout_SecurityRoom_PC2_Text_0, MSGBOX_SIGN
	return


MicoloHideout_SecurityRoom_PC3::
	playse SE_PC_LOGIN
	waitse
	msgbox MicoloHideout_SecurityRoom_PC3_Text_0, MSGBOX_SIGN
	return


MicoloHideout_SecurityRoom_PC4::
	msgbox MicoloHideout_SecurityRoom_PC4_Text_0, MSGBOX_SIGN
	return


MicoloHideout_SecurityRoom_Machine::
	msgbox MicoloHideout_SecurityRoom_Machine_Text_0, MSGBOX_SIGN
	return

MicoloHideout_SecurityRoom_SecurityMan::
	lockall
	faceplayer
	msgbox MicoloHideout_SecurityRoom_SecurityMan_Text_0
	releaseall
	return


MicoloHideout_SecurityRoom_SecurityMan_Text_0:
	.string "Maldito PACOCHEF... ya ha dejado la\n"
	.string "puerta abierta otra vez...\p"
	.string "¿Eh? ¿Has conseguido entrar? Se\n"
	.string "supone que mi trabajo es detenerte,\l"
	.string "pero bueno... esto está lleno de\l"
	.string "entrenadores fortísimos, si sigues\l"
	.string "adelante ellos harán que te\l"
	.string "arrepientas.\p"
	.string "Por cierto... ¡ni se te ocurra leer lo que\n"
	.string "hay en los PCs de esta sala!$"


MicoloHideout_SecurityRoom_PC1_Text_0:
	.string "Hay un documento abierto en el PC.\p"
	.string "“REPORTE MICOLANDIA 1”\p"
	.string "“He decidido asentarme en esta isla.\n"
	.string "Está cerca de mi isla natal, IZABE n.n\p"
	.string "Construiré aquí mi base de operaciones\n"
	.string "y haré que vengan mis compañeros más\l"
	.string "leales n.n\p"
	.string "PD: Monociclo porque mono es uno y la\n"
	.string "vida es un ciclo.”$"

MicoloHideout_SecurityRoom_PC2_Text_0:
	.string "Hay un documento abierto en el PC.\p"
	.string "“REPORTE MICOLANDIA 2”\p"
	.string "“Han comenzado a venir entrenadores a\n"
	.string "la isla y se han asentado aquí.\p"
	.string "Esto cada vez más se empieza a paracer\n"
	.string "a un poblado loooooooooooool\p"
	.string "Lo aprovecharé para crear mis propios\n"
	.string "GIMNASIOS y LIGA POKéMON n.n\p"
	.string "Haciendo que los entrenadores más\n"
	.string "fuertes vengan aquí, podré utilizarlos\l"
	.string "para entrenar mis nuevas creaciones.\p"
	.string "PD: Monociclo porque mono es uno y la\n"
	.string "vida es un ciclo.”$"

MicoloHideout_SecurityRoom_PC3_Text_0:
	.string "Hay un documento abierto en el PC.\p"
	.string "“REPORTE MICOLANDIA 3”\p"
	.string "“Ya ha finalizado la construcción de la\n"
	.string "MICOLIGA y el MICOGIMNASIO.\p"
	.string "Con eso y el laboratorio, ya estoy listo\n"
	.string "para tomar la región n.n\p"
	.string "Comenzaré con contactar con AQUA y\n"
	.string "MAGMA, parecen poseer tecnología\l"
	.string "bastante interesante xDDDDDDDD\p"
	.string "PD: Monociclo porque mono es uno y la\n"
	.string "vida es un ciclo.”$"

MicoloHideout_SecurityRoom_PC4_Text_0:
	.string "En este PC se monitorizan las cámaras\n"
	.string "de seguridad de la guarida de MICOLO.$"

MicoloHideout_SecurityRoom_Machine_Text_0:
	.string "Es el sistema de seguridad de la\n"
	.string "GUARIDA MICOLO.$"

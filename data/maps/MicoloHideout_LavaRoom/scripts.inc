MicoloHideout_LavaRoom_MapScripts::
	.byte 0

MicoloHideout_LavaRoom_EventScript_GiratinaMaster::
	lock
	faceplayer
	special HasDefeatedAllMicoloHideoutTrainers
	compare VAR_RESULT, TRUE
	goto_if_eq MicoloHideout_LavaRoom_EventScript_GiratinaMaster_2
	msgbox MicoloHideout_LavaRoom_EventScript_GiratinaMaster_Text_1, MSGBOX_DEFAULT
MicoloHideout_LavaRoom_EventScript_GiratinaMaster_1:
	release
	return

MicoloHideout_LavaRoom_EventScript_GiratinaMaster_2:
	msgbox MicoloHideout_LavaRoom_EventScript_GiratinaMaster_Text_0, MSGBOX_DEFAULT
	applymovement 6, MicoloHideout_LavaRoom_Movement_GiratinaMaster
	waitmovement 0
    removeobject 6
	setflag FLAG_HIDE_LAVAROOM_GIRATINAMASTER
	goto MicoloHideout_LavaRoom_EventScript_GiratinaMaster_1


MicoloHideout_LavaRoom_Movement_GiratinaMaster:
	walk_up
	step_end

MicoloHideout_LavaRoom_EventScript_GiratinaMaster_Text_0:
	.string "GIRATINA MASTER: ¿has derrotado a\n"
	.string "todos los entrenadores? eres pro,\l"
	.string "puedes pasar. cierro tema. lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock:$"

MicoloHideout_LavaRoom_EventScript_GiratinaMaster_Text_1:
	.string "GIRATINA MASTER: SOY MOD, NO PUEDES\n"
	.string "PASAR. SE CIERRA LA LIGA.\p"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\n"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock: :lock: :lock:\l"
	.string ":lock: :lock: :lock: :lock:\p"
	.string "soy mod, pero te dejaré pasar si\n"
	.string "derrotas a todos los entrenadores de\l"
	.string "la GUARIDA.\p"
	.string "has derrotado a {STR_VAR_1} de\n"
	.string "{STR_VAR_2}.\p"
	.string "venga, combate o te baneo. cierro tema.\p"
	.string ":lock: lock: lock: lock: lock: lock: lock:\n"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock: lock: lock:\l"
	.string "lock: lock: lock: lock: lock:$"

MicoloHideout_LavaRoom_EventScript_Phent::
	trainerbattle_single TRAINER_PHENT, MicoloHideout_LavaRoom_Text_PhentIntro, MicoloHideout_LavaRoom_Text_PhentDefeat
	msgbox MicoloHideout_LavaRoom_Text_PhentPostBattle, MSGBOX_AUTOCLOSE
	end	
	
MicoloHideout_LavaRoom_EventScript_EEVEETO::
	trainerbattle_double TRAINER_EEVEETO, MicoloHideout_LavaRoom_Text_EEVEETOIntro, MicoloHideout_LavaRoom_Text_EEVEETODefeat, MicoloHideout_LavaRoom_EEVEETO_MasdeunPokemon
	msgbox MicoloHideout_LavaRoom_Text_EEVEETOPostBattle, MSGBOX_AUTOCLOSE
	end

MicoloHideout_LavaRoom_EEVEETO_MasdeunPokemon: // BATALLA DOBLE
	.string "Así que solo llevas un Pokémon?\n"
	.string "No puedo luchar contigo, entonces.\p"

	.string "Mi estrategia es solo para las\n"
	.string "BATALLA DOBLE.$"
	
MicoloHideout_LavaRoom_Text_EEVEETOIntro: 
	.string "Mal día has elegido para pasear\n"
	.string "sin el casco anti-hax.\p" 
	
	.string "Mi Abomasnow al fin ha alcanzado\n" 
	.string "el poder de la Megaevolución.\p"

    .string "Preparate para sentir el poder\n"
    .string "del invierno!$"

MicoloHideout_LavaRoom_Text_EEVEETODefeat: 
	.string "Ok, he perdido, pero seguro que\n"
    .string "te he jodido el Nuzlocke.$"

MicoloHideout_LavaRoom_Text_EEVEETOPostBattle:
	.string "No importa, usaré esta derrota\n"
	.string "como pretexto para que el cabrón\l"
	.string "de Shiyo haga Midele Platinum.$"
	
MicoloHideout_LavaRoom_Text_PhentIntro:
	.string "Existe una teoría que relata que\n"
	.string "los DITTOS son los desechos expulsados\l"
	.string "por el POKéMON legendario MEW.\p"
	
	.string "Se cree, por ello, que por eso DITTO\n"
	.string "es el único POKéMON aparte de MEW, que\l" 
	.string "sabe TRANSFORM de forma natural, y que\l" 
	.string "por eso hay DITTOs pululando por los\l"
	.string "alrededores de un laboratorio en KANTO,\l"
	.string "donde el TEAM ROCKET hizo experimentos\l"
	.string "con MEW para poder crear a MEWTWO.\p"

	.string "Me encomendaron la tarea de examinar\n"
	.string "los excrementos de MEW y varios POKéMON,\l"
	.string "pero ahora mismo estoy en un punto\l"
	.string "muerto, ya que no he descubierto\l" 
	.string "nada sorprendente.\p"
	
	.string "Nada tan sorprendente como mi mayor\n"
	.string "experimento de todos:\p"
	
	.string "¡EL PIKACHU OSCURO DEL TRUENO DE\n" 
	.string "LA OSCURIDAD!$"

MicoloHideout_LavaRoom_Text_PhentDefeat: 
	.string "¡Vaya trabajo de mierda!$"

MicoloHideout_LavaRoom_Text_PhentPostBattle:
	.string "Este trabajo es... literalmente...\n"
	.string "¡MIERDA!\p"

	.string "Mmm... tal vez pueda investigar porque\n"
	.string "existen REGIELEKI y REGIDRAGO.\p"
	
	.string "Si los REGIS originales siempre fueron\n"
	.string "REGICE, REGIROCK y REGISTEEL...\p"
	
	.string "¿Por qué GF sacó los otros dos?$"

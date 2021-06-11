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

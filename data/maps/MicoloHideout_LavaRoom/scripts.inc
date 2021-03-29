MicoloHideout_LavaRoom_MapScripts::
	.byte 0

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

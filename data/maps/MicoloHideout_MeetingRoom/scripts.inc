MicoloHideout_MeetingRoom_MapScripts::
	.byte 0
	
MicoloHideout_MeetingRoom_EventScript_Goldie::
	trainerbattle_double TRAINER_GOLDIE, Goldie_AntesBatalla, Goldie_MensajeDerrota, Goldie_MasdeunPokemon
	msgbox Goldie_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_MeetingRoom_EventScript_Merum::
	trainerbattle_single TRAINER_MERUM, Merum_AntesBatalla, Merum_MensajeDerrota
	msgbox Merum_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
Goldie_MasdeunPokemon: // BATALLA DOBLE
	.string "Pero si no llevas más de un\n"
	.string "POKÉMON con vida...\p"

	.string "Mi equipo es solo para DOBLES,\n"
	.string "así que vuelve cuando tengas\l"
	.string "al menos dos.$"
	
Goldie_AntesBatalla: 
	.string "¡Te doy la bienvenida!\p"

    .string "¿Sabes qué hacen dos personas\n"
    .string "cuando se conocen?\p"

    .string "¡Exacto! ¡Compartir logros\n"
    .string "en gachas de baja calidad!\p"

    .string "...Oh, que quieres luchar.\p"

    .string "Vale, ¡no pienso perder!\n"
    .string "(posa por algún motivo)$"
	
Goldie_MensajeDerrota: 
    .string "Oh, lo olvidaba, que aquí\n"
    .string "no está programado.\p"

    .string "Al menos me lo justifican\n"
    .string "mejor que los guardas de Galar.$"
	
Goldie_DespuesDeBatalla:
    .string "¿Sabías que en los dos anteriores\n"
    .string "juegos Midele yo salía como NPC\l"
    .string "masculino? Me han dejado niquelada.\p"

    .string "Y sí, acabo de romper la\n"
    .string "cuarta pared de gratis.$"
	
Merum_AntesBatalla: 
    .string "A ver que yo me entere... ¿me estás\n"
    .string "diciendo que tienes un equipo de\l"
    .string "la hostia y entre ellos no hay un\l"
    .string "buen puto MOÁI bien mamadísimo?\p"
    .string "Es que es para pegarte.\p"
    .string "Es más, seré YO quien te pegue.$"
	
Merum_MensajeDerrota: 
    .string "Vaya por dios. Bueno, como sea...\n"
    .string "espero que este combate sirviese\l"
    .string "para mostrarte lo que mola mi MOÁI.$"
	
Merum_DespuesDeBatalla:
	.string "Es gracioso y a la par triste cuando\n"
    .string "tu parodia es exactamente como tú.\p"

    .string "Si te empiezas a sentir como un NPC\n"
    .string "es que quizás deberías ampliar tus\l"
    .string "temas de conversación. Dicho eso,\l"
    .string "¿qué opinas de mi GRAN MOÁI?$"


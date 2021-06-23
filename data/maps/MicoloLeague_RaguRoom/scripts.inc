MicoloLeague_RaguRoom_MapScripts::
	.byte 0
	
MicoloLeague_RaguRoom_EventScript_Ragu::
	//goto_if_set AÑADIR NUEVA FLAG PARA QUE NO LUCHE DE NUEVO, MicoloLeague_RaguRoom_EventScript_Ragu_Derrotado
	trainerbattle_single TRAINER_RAGU, MicoloLeague_RaguRoom_Text_RaguIntro, MicoloLeague_RaguRoom_Text_RaguDefeat, MicoloLeague_RaguRoom_EventScript_RaguDefeated, NO_MUSIC
	release
	end
	
MicoloLeague_RaguRoom_EventScript_RaguDefeated::
	msgbox MicoloLeague_RaguRoom_Text_RaguPostBattle, MSGBOX_DEFAULT
	waitmessage
	//setflag AÑADIR NUEVA FLAG PARA QUE NO LUCHE DE NUEVO
	release
	end
	
MicoloLeague_RaguRoom_EventScript_Ragu_Derrotado::
	faceplayer
	lock
	msgbox MicoloLeague_RaguRoom_Text_RaguPostBattle, MSGBOX_DEFAULT
	release
	end
	
MicoloLeague_RaguRoom_Mudkip::
	waitse
	playmoncry SPECIES_MUDKIP, 2
	delay 40
	waitmoncry
	msgbox MicoloLeague_RaguRoom_Text_Mudkip, MSGBOX_NPC
	release
	end
	
MicoloLeague_RaguRoom_NPCmirandoTV::
	lockall
	msgbox MicoloLeague_RaguRoom_Text_NPCmirandoTV, MSGBOX_NPC
	releaseall
	end
	
MicoloLeague_RaguRoom_EsclavoSign::
	msgbox MicoloLeague_RaguRoom_Text_EsclavoSign, MSGBOX_SIGN
	end
	
MicoloLeague_RaguRoom_TeleSign::
	msgbox MicoloLeague_RaguRoom_Text_TeleSign, MSGBOX_SIGN
	end
	
MicoloLeague_RaguRoom_PlanosSign::
	msgbox MicoloLeague_RaguRoom_Text_PlanosSign, MSGBOX_SIGN
	end
	
MicoloLeague_RaguRoom_TumbaSign::
	msgbox MicoloLeague_RaguRoom_Text_TumbaSign, MSGBOX_SIGN
	end
	
MicoloLeague_RaguRoom_PCSign::
	msgbox MicoloLeague_RaguRoom_Text_PCSign, MSGBOX_SIGN
	end
	
MicoloLeague_RaguRoom_Text_EsclavoSign:
	.string "¡ATENCIÓN!\p" 
	
	.string "Prohibido lanzar comida a los\n"
	.string "esclavos, no sabemos como pueden\l"
	.string "reaccionar ante los visitantes.$"

MicoloLeague_RaguRoom_Text_TeleSign:
	.string "Parece que están reproduciendo las\n"
	.string "jugadas más mortíferas del NUZLOCKE\l"
	.string "de EEVEETO.$"
	
MicoloLeague_RaguRoom_Text_PlanosSign:
	.string "Parecen notas sobre MIDELE EMERALD:\p"
	
	.string "Copypaste de scripts\p"

	.string "Recordar que manden equipo y frases\p"

	.string "Hacer más óptimo el trabajo de mis\n"
	.string "esclavos, para ello les daré una\l"
	.string "papelera a cada uno donde puedan hacer\l"
	.string "sus necesidades sin interrupciones.\p"
	
	.string "Fecha definitiva Lanzamiento de\n"
	.string "MIDELE EMERALD: JULIO 2021$"
	
MicoloLeague_RaguRoom_Text_Mudkip:
	.string "¡Es el POKéMON favorito de RAGU!\p"

	.string "Lleva una nota en la boca que dice\n"
	.string "lo siguiente:\p"
	
	.string "so i herd u liek mudkipz$"

MicoloLeague_RaguRoom_Text_TumbaSign:
	.string "Aquí yace PIKACHU aplastado.$"
	
MicoloLeague_RaguRoom_Text_NPCmirandoTV:
	.string "¡SIIIIIII! ¡TOMAAAAAAAAA!\n" 
	.string "¡Han matado al SNORLAX roto de\l"
	.string "EEVEETO!\p"
	
	.string "¡Esta droja es maravillosa!\p"
	
	.string "...\p"
	
	.string "¡JOJOJO! ¡Se ha comido un golpe crítico\n"
	.string "que le hizo KO a su HYDREIGON.\p"
	
	.string "¡EEVEETO ESTÁ A PUNTO DE PERDER!\p"
	
	.string "...\p"
	
	.string "¿QUÉ? ¿QUÉ? ¿¿¿QUEEEEEEEEEEE???\p"
	
	.string "¡MALDITA IA! ¡ME CAGOENTOOOO!\n" 
	.string "La IA se ha puesto a boostearse en vez\l" 
	.string "de matarle un POKéMON, ¡AAAAAAAAAAA!\p"
	
	.string "...\p"
	
	.string "EEVEETO está remontando, ¡¡¡NOOOOO!!!\n"
	.string "¡Está haciendo KO a todo lo que sale!\p"
	
	.string "...\p"
	
	.string "¡JODEEEEEEEEEEEEER!\n"
	.string "¡EEVEETO HA GANADO EL NUZLOCKE!\p"
	.string "¡VAYA MIERDA!$"
	
MicoloLeague_RaguRoom_Text_PCSign:
	.string "Parecen notas sobre un MIDELE\n"
	.string "PLATINUM cancelado:\p"
	
	.string "Justo después de lo ocurrido en\n"
	.string "MIDELE EMERALD.\p"
	
	.string "Una nueva y gran amenaza se cierne\n"
	.string "sobre SINNOH que afectará a todo\l"
	.string "el MUNDO POKéMON.\p"
	
	.string "MICOLO ha sido engañado y capturado\n"
	.string "por DARKI MALRO y sus esbirros, y se\l"
	.string "ha llevado todos los experimentos,\l"
	.string "incluyendo el PODER MIDELAR.\p"
	
	.string "DARKI MALRO ha conseguido un ejercito\n"
	.string "de esbirros de otros mundos gracias\l" 
	.string "al uso de una máquina con un\l"
	.string "desmesurado poder que ha desequilibrado\l"
	.string "las estructuras del espacio-tiempo.\p"
	
	.string "El MT. CORONA de SINNOH ha sido\n"
	.string "eliminado completamente.\p"
	
	.string "¿Aparecerá alguien capaz de\n" 
	.string "hacerle FRENTE?$"
	
MicoloLeague_RaguRoom_Text_RaguIntro: 
	.string "FRASES$"

MicoloLeague_RaguRoom_Text_RaguDefeat: 
	.string "¡Salid de TWITTER!$"

MicoloLeague_RaguRoom_Text_RaguPostBattle:
	.string "FRASES$"
	

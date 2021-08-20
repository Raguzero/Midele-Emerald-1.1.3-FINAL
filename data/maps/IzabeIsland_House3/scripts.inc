IzabeIsland_House3_MapScripts::
	.byte 0


IzabeIsland_House3_EventScript_Scientist::
	msgbox IzabeIsland_House3_Text_Scientist, MSGBOX_NPC
	end

IzabeIsland_House3_EventScript_Kanto1::
	playse SE_PC_LOGIN
	waitse
	msgbox IzabeIsland_House3_Text_Kanto1, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_Johto1::
	playse SE_PC_LOGIN
	waitse
	msgbox IzabeIsland_House3_Text_Johto1, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_StackOfBooks::
	msgbox IzabeIsland_House3_Text_StackOfBooks, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_Bookshelf::
	msgbox IzabeIsland_House3_Text_Bookshelf, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_Izabe1::
	playse SE_PC_LOGIN
	waitse
	msgbox IzabeIsland_House3_Text_Izabe1, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_Izabe2::
	playse SE_PC_LOGIN
	waitse
	msgbox IzabeIsland_House3_Text_Izabe2, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_Izabe3::
	msgbox IzabeIsland_House3_Text_Izabe3, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_MicoloDiary::
	msgbox IzabeIsland_House3_Text_MicoloDiary, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_Machine::
	msgbox IzabeIsland_House3_Text_Machine, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_LabMon::
	lock
	goto_if_set FLAG_RECEIVED_MICOLO_MON, IzabeIsland_House3_EventScript_AlreadyReceivedMonEnd
	msgbox IzabeIsland_House3_Text_LabMon, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_FLOETTE
	givemon SPECIES_FLOETTE, 30, ITEM_PETAYA_BERRY, TRUE, TRUE
	compare VAR_RESULT, 0
	goto_if_eq IzabeIsland_House3_EventScript_ReceiveMonParty
	compare VAR_RESULT, 1
	goto_if_eq IzabeIsland_House3_EventScript_ReceiveMonPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

IzabeIsland_House3_EventScript_ReceiveMonParty:: @ 8270085
	call IzabeIsland_House3_EventScript_ReceiveMonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq IzabeIsland_House3_EventScript_ReceiveMonEnd
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto IzabeIsland_House3_EventScript_ReceiveMonEnd
	end

IzabeIsland_House3_EventScript_ReceiveMonPC:: @ 82700AD
	call IzabeIsland_House3_EventScript_ReceiveMonFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq IzabeIsland_House3_EventScript_SendMonPC
	call Common_EventScript_NameReceivedBoxMon
	goto IzabeIsland_House3_EventScript_SendMonPC
	end
	
IzabeIsland_House3_EventScript_SendMonPC:: @ 82700D0
	call Common_EventScript_TransferredToPC
	goto IzabeIsland_House3_EventScript_ReceiveMonEnd
	end

IzabeIsland_House3_EventScript_ReceiveMonFanfare:: @ 82700DB
	playfanfare MUS_FANFA4
	message IzabeIsland_House3_Text_ReceivedMon
	waitmessage
	waitfanfare
	bufferspeciesname 0, SPECIES_FLOETTE
	return

IzabeIsland_House3_EventScript_ReceiveMonEnd:
	setflag FLAG_RECEIVED_MICOLO_MON
	release
	end

IzabeIsland_House3_EventScript_AlreadyReceivedMonEnd:
	msgbox IzabeIsland_House3_Text_LabMonAfterReceived, MSGBOX_DEFAULT
	release
	end

IzabeIsland_House3_EventScript_DarkPikaNotes::
	msgbox IzabeIsland_House3_EventScript_DarkPikaNotes_Text_0, MSGBOX_DEFAULT
	multichoicegrid 0, 0, MULTI_IZABE_HOUSE3_DOCUMENTS, 1, 0
	switch VAR_RESULT
	case 0, IzabeIsland_House3_EventScript_DarkPikaNotes_3
	case 1, IzabeIsland_House3_EventScript_DarkPikaNotes_4
	case 2, IzabeIsland_House3_EventScript_DarkPikaNotes_5
IzabeIsland_House3_EventScript_DarkPikaNotes_1:
	release
	return

IzabeIsland_House3_EventScript_DarkPikaNotes_3:
	msgbox IzabeIsland_House3_EventScript_DarkPikaNotes_Text_1, MSGBOX_SIGN
	goto IzabeIsland_House3_EventScript_DarkPikaNotes_1

IzabeIsland_House3_EventScript_DarkPikaNotes_4:
	msgbox IzabeIsland_House3_EventScript_DarkPikaNotes_Text_2, MSGBOX_SIGN
	goto IzabeIsland_House3_EventScript_DarkPikaNotes_1

IzabeIsland_House3_EventScript_DarkPikaNotes_5:
	msgbox IzabeIsland_House3_EventScript_DarkPikaNotes_Text_3, MSGBOX_SIGN
	goto IzabeIsland_House3_EventScript_DarkPikaNotes_1


IzabeIsland_House3_EventScript_DarkPikaNotes_Text_0:
	.string "En el fondo de la estantería observas\n"
	.string "múltiples documentos que comparten el\l"
	.string "título “Investigación sobre POKéMON\l"
	.string "confidenciales” ¿Cuál quieres leer?$"

IzabeIsland_House3_EventScript_DarkPikaNotes_Text_1:
	.string "“Reporte de investigación sobre la\n"
	.string "creación del PIKACHU definitivo, por\l"
	.string "PHENT”.\p"
	.string "“Tras 478 intentos de crianza\n"
	.string "selectiva de incontables PIKACHU\l"
	.string "traídos de distintas regiones y\l"
	.string "cuidados por los mejores entrenadores,\l"
	.string "he conseguido hacer eclosionar al\l"
	.string "PIKACHU con las características que\l"
	.string "MICOLO deseaba (a partir de ahora,\l"
	.string "DARK PIKA)”\p"
	.string "“La principal característica de DARK\n"
	.string "PIKA que lo diferencia de otros\l"
	.string "PIKACHU es su color negro, producto de\l"
	.string "la gran concentración de energía\l"
	.string "eléctrica que este almacena.”\p"
	.string "“Esta gran cantidad de energía le\n"
	.string "permite ejecutar sin ninguna clase de\l"
	.string "problema poderosísimos ataques\l"
	.string "eléctricos. Es tal su energía que,\l"
	.string "según mis cálculos, sería incluso capaz\l"
	.string "de destruir una ciudad entera en un\l"
	.string "arrannque de ira.”\p"
	.string "“No hemos sido capaces de hacer\n"
	.string "evolucionar a DARK PIKA y tampoco\l"
	.string "tiene ninguna preevolución conocida ni\l"
	.string "es capaz de criar, pero esto no es\l"
	.string "problema ninguno para su poderío.”\l"
	.string "“MICOLO ya lo ha establecido como su\l"
	.string "POKéMON insignia.”\p"
	.string "“ANEXO: CARACTERÍSTICAS TÉCNICAS\p"
	.string "Tipo: ELECTRIC/DARK\n"
	.string "Habilidades: INTIMIDATE/TOUGH CLAWS\p"
	.string "Estadísticas base:\n"
	.string "HP: 115, ATK: 125, DEF: 85, SPD: 180, SATK:\l"
	.string "120, SDEF: 120\p"
	.string "Movimientos: es capaz de aprender los\n"
	.string "movimientos DARK THUNDER, SEISMIC\l"
	.string "PUNCH, BRUTAL BALL y MIDELE POWER al\l"
	.string "subir de nivel. ”$"

IzabeIsland_House3_EventScript_DarkPikaNotes_Text_2:
	.string "“Reporte de investigación sobre\n"
	.string "CATERMANO, por A.VADER”\p"
	.string "“El otro día iba caminando por la hierba\n"
	.string "y me apareció un CATERPIE shiny, lo\l"
	.string "llamé CATERMANO.\p"
	.string "Quería llevarlo en mi equipo, por eso de\n"
	.string "que es shiny, pero es tremenda basura.\l"
	.string "Además, si lo evoluciono perdería su\l"
	.string "color dorado.\p"
	.string "Le diré a MICOLO que es un CATERPIE\n"
	.string "especial y le pediré permiso para usar\l"
	.string "el laboratorio y hacerle aprender el\l"
	.string "movimiento MIDELE POWER, seguro que\l"
	.string "cuela. MASTERMINDED.”\p"
	.string "“Quizás lo clone y lo venda en el casino.\n"
	.string "La gente se pensará que es algo\l"
	.string "especial, pero es un mero CATERPIE\l"
	.string "shiny con el movimiento MIDELE POWER y\l"
	.string "los puntos de esfuerzo al máximo.”$"

IzabeIsland_House3_EventScript_DarkPikaNotes_Text_3:
	.string "“Reporte de investigación sobre\n"
	.string "MICOMON, por LAVENDER”\p"
	.string "“Durante mi estadía en KANTO, logré\n"
	.string "crear al MICOMON. Mi idea era crear el\l"
	.string "POKéMON más poderoso de todos, el tan\l"
	.string "ansiado por MICOLO.”\p"
	.string "“Cloné unos cuantos, pero eran\n"
	.string "bastante inútiles. Durante nuestra\l"
	.string "huida de KANTO en barco, los tiré todos\l"
	.string "al mar.”\p"
	.string "“Calculo que habrán acabado todos en\n"
	.string "las costas de SINNOH. Con suerte nadie\l"
	.string "los encontrará y nunca volveremos a\l"
	.string "saber más de ellos.”$"


IzabeIsland_House3_Text_Scientist::
	.string "Mmm...\n"
	.string "¿Sabes donde nos encontramos?\l"
	.string "Esto es el LABORATORIO de MICOLO.\p"
	.string "Hace tiempo, MICOLO, el científico más\n"
	.string "destacado de la ISLA vivía aquí.\l"
	.string "Sin embargo, un día ocurrió un incidente\l"
	.string "y no se volvió a ver a MICOLO...\p"
	.string "Si quieres saber más, puedes investigar\n"
	.string "el laboratorio. Tal vez encuentres algún\l"
	.string "documento interesante...$"

IzabeIsland_House3_Text_Kanto1::
	.string "Hay un documento abierto en el PC.\n"
	.string "“Diario de MICOLO: KANTO”\p"
	.string "“Junto a la ayuda de la MAFIA, fui capaz\n"
	.string "de controlar KANTO y establecer mi\l"
	.string "GUARIDA en las profundidades de CUEVA\l"
	.string "CELESTE. n.n”\p"
	.string "“Sin embargo, la POLICÍA de KANTO cercó\n"
	.string "a la MAFIA y cierta persona entrometida\l"
	.string "logró derrotarme.”\p"
	.string "“Pero no pasa nada, iré a JOHTO y crearé\n"
	.string "mi GUARDERÍA MIDELE n.n”\p"
	.string "“PD: Tonto el que lo lea xDDDDDDDDDDDDD”$"

IzabeIsland_House3_Text_Johto1::
	.string "Hay un documento abierto en el PC.\n"
	.string "“Diario de MICOLO: JOHTO”\p"
	.string "“He establecido la GUARIDA MIDELE\n"
	.string "exitosamente en JOHTO. n.n”\l"
	.string "“Sin embargo, alguien ha logrado entrar\l"
	.string "y derrotarme otra vez. LOOOOOOL.”\p"
	.string "“La ayuda de FURRY ha sido inútil.”\n"
	.string "“Tras mi segunda derrota, no me queda\l"
	.string "más remedio que volver a IZABE. n.n”\p"
	.string "“PD: Tonto el que lo lea xDDDDDDDDDDDDD”$"

IzabeIsland_House3_Text_StackOfBooks::
	.string "Es una pila de diversos libros.\n"
	.string "Entre ellos hay una copia del libro\l"
	.string "maldito, el MICONOMICÓN.$"

IzabeIsland_House3_Text_Bookshelf::
	.string "Hay un montón de libros. Entre ellos\n"
	.string "lees títulos como “Hola reina: n.n” y\l"
	.string "“PKHex: guía para novatos”.$"

IzabeIsland_House3_Text_Izabe1::
	.string "Hay un documento abierto en el PC.\n"
	.string "“INVESTIGACIÓN 1: IZABE”\p"
	.string "“Necesitaré diversas máquinas para el\n"
	.string "comienzo de investigación. n.n”\l"
	.string "“He decidido almacenarlas en una casa\l"
	.string "abandonada de la isla. n.n”\l"
	.string "“Solo se puede acceder por la parte de\l"
	.string "atrás, así que no creo que nadie las\l"
	.string "encuentre. n.n”\p"
	.string "“PD: Tonto el que lo lea xDDDDDDDDDDDDD”$"

IzabeIsland_House3_Text_Izabe2::
	.string "Hay un documento abierto en el PC.\n"
	.string "“INVESTIGACIÓN 2: IZABE”\p"
	.string "“Necesitaré una gran fuente de energía\n"
	.string "para realizar los experimentos. n.n”\l"
	.string "“He decidido utilizar el viejo generador\l"
	.string "abandonado de la isla. n.n”\l"
	.string "“Solo se puede acceder por el lago de la\l"
	.string "isla, así que no creo que nadie sea\l"
	.string "capaz de bucear hasta allí. n.n”\p"
	.string "“PD: Tonto el que lo lea xDDDDDDDDDDDDD”$"

IzabeIsland_House3_Text_Izabe3::
	.string "Hay una libreta en la mesa.\n"
	.string "“INVESTIGACIÓN 3: IZABE”\p"
	.string "“La cueva de las afueras parece estar a\n"
	.string "muy bajas temperaturas.”\l"
	.string "“Debido a esto, la gente suele preferir\l"
	.string "no acercarse al lugar. n.n”\l"
	.string "“Podría ser un buen lugar para realizar\l"
	.string "algunos de mis experimentos. n.n\p"
	.string "“PD: Tonto el que lo lea xDDDDDDDDDDDDD”$"

IzabeIsland_House3_Text_MicoloDiary::
	.string "Hay una libreta en la mesa. Parece ser\n"
	.string "bastante antigua.\p"
	.string "“DIARIO DE MICOLO”\p"
	.string "“Mis experimentos sobre crianza y\n"
	.string "clonación han dado resultado, pero a un\l"
	.string "alto precio.”\l"
	.string "“Usando mi método de evolución forzada,\l"
	.string "he logrado crear unos seres gigantes\l"
	.string "muy agresivos.”\l"
	.string "“Los he encerrado en diversos lugares\l"
	.string "de la isla, y me iré antes de que los\l"
	.string "lugareños los encuentren.”\l"
	.string "“Mi objetivo será KANTO, usaré toda la\l"
	.string "tecnología que he desarrollado para\l"
	.string "ser el más poderoso de la región. n.n”\p"
	.string "El resto de páginas están arrancadas...$"

IzabeIsland_House3_Text_LabMon::
	.string "Hay una POKé BALL junto a una nota.\n"
	.string "“Dejo aquí a mi compañero más fiel. Él\l"
	.string "se encargará de vigilar el LABORATORIO\l"
	.string "en mi ausencia. Cuídate, amigo, volveré.”$"

IzabeIsland_House3_Text_LabMonAfterReceived::
	.string "Ya solo queda la nota en la mesa.\n"
	.string "“Dejo aquí a mi compañero más fiel. Él\l"
	.string "se encargará de vigilar el LABORATORIO\l"
	.string "en mi ausencia. Cuídate, amigo, volveré.”$"

IzabeIsland_House3_Text_ReceivedMon: @ 82706E8
	.string "{PLAYER} received FLOETTE!$"

IzabeIsland_House3_Text_Machine::
	.string "Una extraña máquina. Parece que\n"
	.string "no funciona.$"

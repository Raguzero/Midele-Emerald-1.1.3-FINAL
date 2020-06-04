IzabeIsland_House3_MapScripts::
	.byte 0


IzabeIsland_House3_EventScript_Scientist::
	msgbox IzabeIsland_House3_Text_Scientist, MSGBOX_NPC
	end

IzabeIsland_House3_EventScript_Kanto1::
	msgbox IzabeIsland_House3_Text_Kanto1, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_Johto1::
	msgbox IzabeIsland_House3_Text_Johto1, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_StackOfBooks::
	msgbox IzabeIsland_House3_Text_StackOfBooks, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_Bookshelf::
	msgbox IzabeIsland_House3_Text_Bookshelf, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_Izabe1::
	msgbox IzabeIsland_House3_Text_Izabe1, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_Izabe2::
	msgbox IzabeIsland_House3_Text_Izabe2, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_Izabe3::
	msgbox IzabeIsland_House3_Text_Izabe3, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_MicoloDiary::
	msgbox IzabeIsland_House3_Text_MicoloDiary, MSGBOX_SIGN
	end

IzabeIsland_House3_EventScript_LabMon::
	msgbox IzabeIsland_House3_Text_LabMon, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, SPECIES_FLOETTE
	givemon SPECIES_FLOETTE, 30, ITEM_LUCKY_EGG, TRUE
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
	setflag FLAG_RECEIVED_CASTFORM
	release
	end


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
	.string "abandonada de la isla. n.n”\l"
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
	.string "en mi ausencia. Cuídate, amigo, volveré.$"

IzabeIsland_House3_Text_ReceivedMon: @ 82706E8
	.string "{PLAYER} received FLOETTE!$"

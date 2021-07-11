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
	
MicoloHideout_MeetingRoom_EventScript_Kaderete::  
	trainerbattle_single TRAINER_KADERETE_2, MicoloHideout_MeetingRoom_Text_KadereteIntro, MicoloHideout_MeetingRoom_Text_KadereteDefeat
	msgbox MicoloHideout_MeetingRoom_Text_KaderetePostBattle, MSGBOX_AUTOCLOSE
	end
	
MicoloHideout_MeetingRoom_EventScript_Hathar::  
	trainerbattle_single TRAINER_HATHAR, MicoloHideout_MeetingRoom_Text_HatharIntro, MicoloHideout_MeetingRoom_Text_HatharDefeat
	msgbox MicoloHideout_MeetingRoom_Text_HatharPostBattle, MSGBOX_AUTOCLOSE
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
	
MicoloHideout_MeetingRoom_Text_HatharIntro: 
    .string "Te voy a banear.$"

MicoloHideout_MeetingRoom_Text_HatharDefeat: 
    .string "¡Ay! ¡Mi apendice!$"
 
MicoloHideout_MeetingRoom_Text_HatharPostBattle:
    .string "Podría haberte ganado,\n"
    .string "si no estuviese recuperandome\l" 
	.string "de mi vesicula.$"
	
MicoloHideout_MeetingRoom_Text_KadereteIntro: 
	.string "¿Cómo puedo haber acabado yo aquí?\p"

    .string "O sea, mira a toda esta gente.\n"
    .string "Está todo lleno de putos frikazos...\p"

    .string "En fin, ya me has enfadado.\n"
    .string "¡¡¡A poquemonear!!!$"

MicoloHideout_MeetingRoom_Text_KadereteDefeat: 
	.string "NOOOOOOOO$"

MicoloHideout_MeetingRoom_Text_KaderetePostBattle: 
	.string "En fin, tampoco le había echado ganas.\p"

    .string "Vete antes de que te parta la cara.$"

MicoloHideout_MeetingRoom_Showcase_Monociclo::
	msgbox MicoloHideout_MeetingRoom_Showcase_Monociclo_Text_0, MSGBOX_SIGN
	return


MicoloHideout_MeetingRoom_Showcase_Micomandamientos::
	msgbox MicoloHideout_MeetingRoom_Showcase_Micomandamientos_Text_0, MSGBOX_SIGN
	return


MicoloHideout_MeetingRoom_Showcase_Monociclo_Text_0:
	.string "Hay un monociclo dentro.$"

MicoloHideout_MeetingRoom_Showcase_Micomandamientos_Text_0:
	.string "Hay una inscripción en una tabilla de\n"
	.string "piedra. Lees lo que pone:\p"
	.string "“LOS DIEZ MICOMANDAMIENTOS\p"
	.string "1. Amarás al mico sobre todas las cosas.\p"
	.string "2. No tomarás el nombre del mico en vano.\p"
	.string "3. Santificarás a los monociclos.\p"
	.string "4. Honrarás a MIDELE y a ULTRA MAGIC.\p"
	.string "5. No pensarás.\p"
	.string "6. No hackearás POKéMON impuros.\p"
	.string "7. No robarás protagonismo a MICOLO.\p"
	.string "8. No dirás LOOOOOOL en vano.\p"
	.string "9. NO consentirás pensamientos ni\n"
	.string "deseos inteligentes.\p"
	.string "10. NO codiciarás monociclos ajenos.\p"
	.string "En nombre del mico, del hijo, del\n"
	.string "espíritu midélico. LOOOOOOOOOL.”$"

MicoloHideout_MeetingRoom_MagmaLetter::
	msgbox MicoloHideout_MeetingRoom_MagmaLetter_Text_0, MSGBOX_SIGN
	return


MicoloHideout_MeetingRoom_MagmaLetter_Text_0:
	.string "Hay una carta con el símbolo MAGMA en\n"
	.string "la mesa, dice lo siguiente:\p"
	.string "“Estimado MICOLO:\p"
	.string "Tu plan sobre el secado de todas las\n"
	.string "rutas marítimas más allá de RUTA 124\l"
	.string "nos ha parecido bastante interesante,\l"
	.string "así que hemos decidido enviarte todas\l"
	.string "esas máquinas, como pediste.\p"
	.string "Son el mismo tipo de máquinas que\n"
	.string "utilizamos en nuestra GUARIDA MAGMA,\l"
	.string "así que sin duda te serán útiles.\p"
	.string "Según tus indicaciones, se espera que\n"
	.string "sean enviadas en unos días a la isla al\l"
	.string "oeste de IZABE, de nombre MICOLANDIA.\l"
	.string "Recomiendo que hagas espacio para\l"
	.string "ellas, pues son bastante grandes.\p"
	.string "PD: si bien nuestras máquinas son de la\n"
	.string "máxima calidad, dudo que sean capaces\l"
	.string "de secar en su totalidad toda esa masa\l"
	.string "de agua. Probablamente ocurra un\l"
	.string "secado parcial, pero eso debería ser\l"
	.string "más que suficiente para probar la\l"
	.string "efectividad de las máquinas.\p"
	.string "LÍDER MAGMA, MAGNO”$"

MicoloHideout_MeetingRoom_PC1::
	playse SE_PC_LOGIN
	waitse
	msgbox MicoloHideout_MeetingRoom_PC1_Text_0, MSGBOX_SIGN
	return


MicoloHideout_MeetingRoom_PC2::
	playse SE_W153
	waitse
	msgbox MicoloHideout_MeetingRoom_PC2_Text_0, MSGBOX_SIGN
	return


MicoloHideout_MeetingRoom_PC3::
	playse SE_PC_LOGIN
	waitse
	msgbox MicoloHideout_MeetingRoom_PC3_Text_0, MSGBOX_SIGN
	return


MicoloHideout_MeetingRoom_PCHeal::
	lock
	playse SE_PC_LOGIN
	waitse
	msgbox MicoloHideout_MeetingRoom_PCHeal_Text_0, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq MicoloHideout_MeetingRoom_PCHeal_2
MicoloHideout_MeetingRoom_PCHeal_1:
	release
	return

MicoloHideout_MeetingRoom_PCHeal_2:
	playse MUS_ME_ASA
	waitse
	special HealPlayerParty
	goto MicoloHideout_MeetingRoom_PCHeal_1


MicoloHideout_MeetingRoom_PC1_Text_0:
	.string "Hay un montón de datos técnicos sobre\n"
	.string "POKéMON y entrenadores.$"

MicoloHideout_MeetingRoom_PC2_Text_0:
	.string "No funciona. Le han pegado una PATADA\n"
	.string "SALTO...$"

MicoloHideout_MeetingRoom_PC3_Text_0:
	.string "Hay una tabla con datos sobre las\n"
	.string "operaciones de MICOLANDIA:\p"
	.string "“MAQUINARIA MAGMA: 300000¥\p"
	.string "INFRAESTRUCTURA GENERAL DE LA CIUDAD:\n"
	.string "1000000¥\p"
	.string "MICOCASINO: 250000¥\p"
	.string "MICOLIGA: 350000¥\p"
	.string "LABORATORIO: 800000¥\p"
	.string "MONOCICLOS: 9999000¥”$"

MicoloHideout_MeetingRoom_PCHeal_Text_0:
	.string "¿Quieres curar a tus POKéMON?$"

MicoloHideout_MeetingRoom_MauvilleMewVader::
	lock
	faceplayer
	playmoncry SPECIES_MEW, 2
	waitmoncry
	msgbox MicoloHideout_MeetingRoom_MauvilleMewVader_Text_0, MSGBOX_DEFAULT
	release
	return


MicoloHideout_MeetingRoom_MauvilleMewVader_Text_0:
	.string "Este MEW tiene una nota:\p"
	.string "“He ido a la RUTA 110 con tu PRIMA.\n"
	.string "Si quieres pasar, ve a buscarme.\p"
	.string "A.VADER”$"


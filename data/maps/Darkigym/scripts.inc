Darkigym_MapScripts::
	.byte 0
	
    @ Combate contra totem.
Darkigym_EventScript_Totem::
	lockall
	playmoncry SPECIES_TYRANITAR, 2
	delay 40
	waitmoncry
	msgbox Darkigym_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_TYRANITAR
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 3
	setflag FLAG_TOTEM_GYMDARKI
    msgbox Darkigym_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.

Darkigym_EventScript_GymStatue_Sign::
	lockall
	goto_if_set FLAG_DEFEATED_DARKI_GYM, Darkigym_EventScript_GymStatueCertified
	goto Darkigym_EventScript_GymStatue
	end

Darkigym_EventScript_GymStatueCertified::
	msgbox Darkigym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

Darkigym_EventScript_GymStatue::
	msgbox Darkigym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end
	
Darkigym_EventScript_Buenro::
	trainerbattle_single TRAINER_DARKI_BUENRO, Darkigym_Text_BuenroIntro, Darkigym_Text_BuenroDefeat, Darkigym_EventScript_BuenroDefeated, NO_MUSIC
	release
	end
	
Darkigym_EventScript_Malro::
	goto_if_set FLAG_DEFEATED_DARKI_GYM, Darkigym_EventScript_Darki_Derrotado
	trainerbattle_single TRAINER_DARKI_MALRO, Darkigym_Text_MalroIntro, Darkigym_Text_MalroDefeat, Darkigym_EventScript_MalroDefeated, NO_MUSIC
	release
	end
	
Darkigym_EventScript_MalroDefeated::
	msgbox Darkigym_Text_MalroPostBattle, MSGBOX_DEFAULT
	waitmessage
	message Darkigym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox Darkigym_Text_ExplainBadgeTakeThis, MSGBOX_DEFAULT
	delay 30
	msgbox Darkigym_Text_MalroPostBattle2, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DARKI_GYM
	release
	end
	
Darkigym_EventScript_Darki_Derrotado::
	faceplayer
	lock
	msgbox Darkigym_Text_MalroPostBattle2, MSGBOX_DEFAULT
	release
	end
	
Darkigym_EventScript_BuenroDefeated::
	msgbox Darkigym_Text_BuenroPostBattle, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end
	
Darkigym_EventScript_Teleport_Entrada::
	msgbox Darkigym_Text_Teleport_Entrada, MSGBOX_YESNO
	goto_if_eq Darkigym_EventScript_Teleport_Si
	release
	end
Darkigym_EventScript_Teleport_Si::
	warp MAP_DARKIGYM, 0, 0, 0
	waitstate
	release
	end

Darkigym_Text_MalroIntro: 
	.string "Así que lograste llegar hasta aquí.\p"
	
	.string "Je, patética criatura, ¿así que\n" 
	.string "tu eres la mierdecilla que se metió\l" 
	.string "en mi guarida para acabar con\l" 
	.string "mis planes?\p"
	
	.string "Había oido que en este mundo los\n" 
	.string "niños son los que cortan el bacalao.\p"

	.string "Pero sabrás... que yo Darkizard, el\n" 
	.string "señor del inframundo, el buscador del\l" 
	.string "caos, el hater definitivo, aquel que\l" 
	.string "sumirá a este y todos los mundos que\l"
	.string "osan molestarme con su estupidez en la\l" 
	.string "mas angustiosa desesperación y horror\l"
	.string "¿Crees acaso que una pulga\l"
	.string "insignificante como TU, por mas que sea\l"
	.string "el protagonista podrá contra mi? ¡JA!\p"

	.string "Creo que pronto verás la gravedad de\n" 
	.string "tu error al venir aquí...$"

Darkigym_Text_MalroDefeat: 
	.string "Me cago en tu vida y en tus muertos\n" 
	.string "pulga, ¿como es esto siquiera posible?\p"

	.string "Derrotado por una criatura... todos\n" 
	.string "mis planes, arruinados.$"

Darkigym_Text_MalroPostBattle:
	.string "¿Es que no lo entiendes?\p"

	.string "Todo esto de viajar en el tiempo fue\n" 
	.string "para matar al imbecil de masuda.\p"
	
	.string "¡En este punto de la historia él es\n"
	.string "quien se convierte en el dios de tu\l" 
	.string "mundo, y lo que vendrá después será\l"
	.string "horrible, Sinnoh, Lilia, y hasta matará\l" 
	.string "a la mitad de los pokémon existentes!\p"
	
	.string "Su soberbia, codicia y estupidez hará\n" 
	.string "sufrir a muchas personas...\p"

	.string "Ahora que sabes esto...\n" 
	.string "¡¿Aún así me expulsarás?!\p"

	.string ".....\p"

	.string "No... no le estoy hablando a esa carcasa\n" 
	.string "vacia a la que controlas...\p"

	.string "Tu jugador... si, el imbecil que se\n" 
	.string "habrá gastado 40 horas de su vida o más\l"
	.string "en jugar este Hackroom.\p"

	.string "Aún no es tarde, incluso un torpe como\n" 
	.string "tu me puede ser útil, si.\p"
	
	.string "Encuentra a masuda y partele la boca\n"
	.string "por mi.\p"

	.string "Si un insignificante ser como tu, pudo\n" 
	.string "ganarme a mi, quizás tu suerte sea la\l" 
	.string "clave para destruir a ese dictador,\l"
	.string "y quien sabe, hasta podrías invocar a\l" 
	.string "una leyenda y todo si tienes suerte\l"
	.string "fu fu fu.\p"
	
	.string "Y antes que se me olvide, toma,\n" 
	.string "la medalla Determinación, como prueba\l" 
	.string "de que sabes usar el buen y el mal rollo\l" 
	.string "para superar todos los obstaculos que\l" 
	.string "se te presenten, lo necesitarás para\l" 
	.string "vencer a ese capullo.$"

Darkigym_Text_MalroPostBattle2:
	.string "¿Sigues aquí?\p"

	.string "¡Largo!, ve y dale una PALIZA a ese\n" 
	.string "idiota de Masuda por los dos.\p"
	
	.string "Si lo metes dentro de un Victreebel o le\n" 
	.string "estampes un Mimikyu en la cara.\l"
	.string "Tanto mejor.\p"
	
	.string "¿Ah... que quieres que te lleve de\n" 
    .string "vuelta a la entrada?\p"

    .string "Pues te jodes, te devuelves a pie,\n" 
    .string "tomalo como mi venganza por atreverte\l" 
    .string "a ganarme fu fu fu.\p"

    .string ".....\p"

    .string "Demonios, eso también me\n"
	.string "lo prohibieron!\p"

    .string "Bueno... te dejaré usar una cuerda huida\n"
    .string "o algo, estarás agradecido...$"

Darkigym_Text_BuenroIntro:
	.string "OH! Genialoso, un invitado!\p"

	.string "Espera, esas ropas... tu no eres\n"
	.string "un invitado, ¡eres EL humano!\p"

	.string "Me han dicho que debo capturarte.\p"

	.string "Si te dejo a tus anchas podrías echar\n" 
	.string "todos sus planes por tierra.\p"

	.string "Además este sitio es muy peligroso, solo\n" 
	.string "alguien igual de genialoso como yo\l"
	.string "podría atravesarlo y salir indemne.\p"
	
	.string "¿Insistes en seguir?\p"
	
	.string "Bueno, supongo que YO el GRAN Darkizard,\n" 
	.string "el todo poderoso buen rollo,\l" 
	.string "Capitan de la guardía imperial del\l" 
	.string "inframundo y co-lider de este Gymnasio,\l"
	.string "tendre que detenerte aquí y ahora.\p"

	.string "Nyeh heh heh heh$" 
	
Darkigym_Text_BuenroDefeat:
	.string "Vaya, si que eres fuerte,\n"
	.string "tienes mi respeto.$"

Darkigym_Text_BuenroPostBattle:
	.string "Ahora te espera la más genial de mis\n"
	.string "creaciones y me la encargo nada más ni\l" 
	.string "nada menos que mi hermano el Mal rollo.\p"

	.string "Él quería que construyera una mazmorra\n" 
	.string "que les hiciera sentir el horror y la\l"
	.string "desesperación que es transitar por\l" 
	.string "aquellos agónicos sitios.\p"

	.string "Que son: Alola y Sinnoh.\p"

	.string "Que para mi no estan TAAAAN mal como dice\n"
	.string "malro, pero bueno, como decía.\p"

	.string "Para un amante de los puzzles como yo,\n"
	.string "no podría contentarme con hacer solo un\l" 
	.string "pasillo simplon en el que se avanzara\l" 
	.string "muy lentamente.\p"

	.string "Así que hice un pasillo en el que avanzas\n" 
	.string "muy lentamente, te puedes extraviar para\l"
	.string "siempre y te asalten todo tipo de trampas\l" 
	.string "mortales meticulozamente colocadas para\l" 
	.string "enviarte directo a un CENTRO POKEMON\p"
	
	.string "Nyeh heh heh.\p"

	.string "Te advierto, solo un verdadero amante\n" 
	.string "de los Puzzles y las mazmorras con\l" 
	.string "la mas ferrea de las voluntades podrá\l"
	.string "superarlo.\p"

	.string "No te preocupes, si pudiste vencerme\n" 
	.string "a mi, al GRAN DARKIZARD, esta mazmorra\l" 
	.string "de la desesperación no sera nada\l"
	.string "para ti.\p"

	.string "Nyehehehe\p"

	.string "En especial por que ese tal RAGU, mejoró\n" 
	.string "las MO, ¡mecachis!\p"

	.string "¡Ánimo y mucha suerte!\p"

	.string "Te advierto, te enfrentaras con el rey\n" 
	.string "del inframundo y gobernante de todos\l" 
	.string "los monstruos.\p"

	.string "¡Sus tormentas de arena y aura siniestra\n" 
	.string "son legendarias!\p"

	.string "Vinimos aquí a llevar a cabo una\n" 
	.string "operación que asegurará la salvación de\l" 
	.string "esta rama de las lineas del mundo.\p"
	
	.string "¿A que es todo un cacho de pan\n"
	.string "malrollo?\p"

	.string "Estoy seguro que te agradará.\p" 
	
	.string "Nyeh heh heh\p"
//si los pokemon estan dañados
	.string "Oh, veo que tu equipo esta decaido.\p"
	
	.string "(Fuiste curado de las heridas)\p"

	.string "Tanto mejor, sigue adelante humano,\n" 
	.string "no pierdas la determinación.$"

Darkigym_Text_ReceivedBadge:
	.string "{PLAYER} recibió la MEDALLA\n"
	.string "DETERMINACIÓN de DARKIZARD.$"

Darkigym_Text_ExplainBadgeTakeThis:
	.string "Con esta MEDALLA en tu poder, desde\n"
	.string "ahora mismo, tus POKÉMON no tienen\l"
	.string "ninguna limitación para subir hasta\l"
	.string "el nivel 100.\p"

	.string "Y debido a que ya tienes la última\n"
	.string "medalla, podrás participar en\l"
	.string "la MICOLIGA.$"
	
Darkigym_Text_GymStatue:
	.string "POKEMON GYM Nº4\n"
	.string "LEADER: DARKIZARD\l"
	.string "“TEMÁTICA: MAL ROLLO Y BUENROLLO”$"

Darkigym_Text_GymStatueCertified:
	.string "POKEMON GYM Nº4\n"
	.string "LEADER: DARKIZARD\l"
	.string "“TEMÁTICA: MAL ROLLO Y BUENROLLO”\p"

	.string "DARKIZARD'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
	
Darkigym_Text_Teleport_Entrada:
	.string "Si usas esta baldosa teletransporte\n"
	.string "volverás a la entrada y tendrás que\l"
	.string "recorrer todo desde el principio.\p"
	
	.string "¿Estás seguro que quieres usarla?$"

Darkigym_Text_Totemaparece:
	.string "TYRANITAR, the Totem Pokémon\n"
	.string "has appeared!$"
	
Darkigym_Text_Totemderrotado:
	.string "TYRANITAR disappeared...$"

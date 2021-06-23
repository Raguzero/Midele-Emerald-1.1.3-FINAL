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
	goto_if_set FLAG_DEFEATED_DARKIBUENRO_GYM, Darkigym_EventScript_BuenroDefeated2
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
	setflag FLAG_DEFEATED_DARKIBUENRO_GYM
	release
	end
	
Darkigym_EventScript_BuenroDefeated2::
	goto_if_set FLAG_DEFEATED_DARKI_GYM, Darkigym_EventScript_Buenro_DarkiDerrotado
	faceplayer
	lock
	msgbox Darkigym_Text_BuenroPostBattle2, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end
	
Darkigym_EventScript_Buenro_DarkiDerrotado::
	faceplayer
	lock
	msgbox Darkigym_Text_BuenroPostBattle3, MSGBOX_DEFAULT
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
	
Darkigym_CabezaLylie_Sign::
	msgbox Darkigym_Text_CabezaLylie_Sign, MSGBOX_SIGN
	end

Darkigym_PCDarki_Sign::
	msgbox Darkigym_Text_PCDarki_Sign, MSGBOX_SIGN
	end
	
Darkigym_CartaMagma1_Sign::
	msgbox Darkigym_Text_CartaMagma1_Sign, MSGBOX_SIGN
	end
	
Darkigym_CartaMagma2_Sign::
	msgbox Darkigym_Text_CartaMagma2_Sign, MSGBOX_SIGN
	end
	
Darkigym_MaquinaMeteorito_Sign::
	msgbox Darkigym_Text_MaquinaMeteorito_Sign, MSGBOX_SIGN
	end
	
Darkigym_VitrinaIzquierda_Sign::
	msgbox Darkigym_Text_VitrinaIzquierda_Sign, MSGBOX_SIGN
	end
	
Darkigym_VitrinaDerecha_Sign::
	msgbox Darkigym_Text_VitrinaDerecha_Sign, MSGBOX_SIGN
	end
	
Darkigym_EventScript_RedSecretaria::
	trainerbattle_single TRAINER_ESBIRRO_DARKI_1, Darkigym_Text_RedSecretariaIntro, Darkigym_Text_RedSecretariaDefeat
	msgbox Darkigym_Text_RedSecretariaPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Kizarde::
	trainerbattle_single TRAINER_ESBIRRO_DARKI_2, Darkigym_Text_KizardeIntro, Darkigym_Text_KizardeDefeat
	msgbox Darkigym_Text_KizardePostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Espi::
	trainerbattle_single TRAINER_ESBIRRO_DARKI_3, Darkigym_Text_EspiIntro, Darkigym_Text_EspiDefeat
	msgbox Darkigym_Text_EspiPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Mobu::
	trainerbattle_single TRAINER_ESBIRRO_DARKI_4, Darkigym_Text_MobuIntro, Darkigym_Text_MobuDefeat
	msgbox Darkigym_Text_MobuPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Roxy::
	trainerbattle_single TRAINER_ESBIRRO_DARKI_5, Darkigym_Text_RoxyIntro, Darkigym_Text_RoxyDefeat
	msgbox Darkigym_Text_RoxyPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONYPXP, Darkigym_Text_AnthonyIntro, Darkigym_Text_AnthonyDefeat
	msgbox Darkigym_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Dranix::
	trainerbattle_single TRAINER_DRANIX, Darkigym_Text_DranixIntro, Darkigym_Text_DranixDefeat
	msgbox Darkigym_Text_DranixPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Umbreon123::
	trainerbattle_single TRAINER_UMBREON123, Darkigym_Text_Umbreon123Intro, Darkigym_Text_Umbreon123Defeat
	msgbox Darkigym_Text_Umbreon123PostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Ultramagic::
	trainerbattle_single TRAINER_ULTRA_MAGIC, Darkigym_Text_UltramagicIntro, Darkigym_Text_UltramagicDefeat
	msgbox Darkigym_Text_UltramagicPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_Charz::
	trainerbattle_single TRAINER_CHARZ, Darkigym_Text_CharzIntro, Darkigym_Text_CharzDefeat
	msgbox Darkigym_Text_CharzPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_FurryTrainerdelpasado::
	trainerbattle_single TRAINER_FURRY, Darkigym_Text_FurryIntro, Darkigym_Text_FurryDefeat
	msgbox Darkigym_Text_FurryPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_DarkMelkorOtraDimension::
	trainerbattle_single TRAINER_DARK_MELKOR, Darkigym_Text_DarkMelkorIntro, Darkigym_Text_DarkMelkorDefeat
	msgbox Darkigym_Text_DarkMelkorPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_FanboyKalos_DimensionZ::
	trainerbattle_single TRAINER_FANBOY_KALOS, Darkigym_Text_FanboyKalosIntro, Darkigym_Text_FanboyKalosDefeat
	msgbox Darkigym_Text_FanboyKalosPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_AngelFS::
	trainerbattle_single TRAINER_ANGELFS, Darkigym_Text_AngelFSIntro, Darkigym_Text_AngelFSDefeat
	msgbox Darkigym_Text_AngelFSPostBattle, MSGBOX_AUTOCLOSE
	end
	
Darkigym_EventScript_TiloAlola::
	trainerbattle_single TRAINER_TILO_ALOLA, Darkigym_Text_TiloAlolaIntro, Darkigym_Text_TiloAlolaDefeat
	goto_if_set FLAG_DEFEATED_TILO, Darkigym_EventScript_Tilo_Derrotado
	msgbox Darkigym_Text_TiloAlolaPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_DEFEATED_TILO
	giveitem ITEM_REVIVE, 10
	compare VAR_RESULT, FALSE
	call_if_eq Darkigym_EventScript_BagFull
	closemessage
	end
	
Darkigym_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	return
	
Darkigym_EventScript_Tilo_Derrotado::
	msgbox Darkigym_Text_TiloAlolaPostBattle2, MSGBOX_NPC
	release
	end
	
Darkigym_Text_RedSecretariaIntro: 
	.string "¿Espera eres un humano?\p"

	.string "No se supone que los humanos\n" 
	.string "corrientes puedan rondar en este\l"
	.string "pedazo del inframundo.\p"

	.string "Supongo que tienes una cita o algo\n" 
	.string "coon mi señor...\p"

	.string "¿Que no la tienes?\p"

	.string "Bueno espero que vinieras aquí buscando\n" 
	.string "una muerte horrible.\p"

	.string "Por que nadie ve a mi jefe el mal rollo\n" 
	.string "sin una cita previa.$" 
	
Darkigym_Text_RedSecretariaDefeat: 
	.string "¿Pero que mier...?$"

Darkigym_Text_RedSecretariaPostBattle:
	.string "¿Como me has... ganado?\p"

	.string "Tsk...Malditas sean las reglas de\n"
	.string "este mundo.\p"

	.string "Te habría llenado todos los esfinteres\n" 
	.string "con granadas y volado en mil pedazos,\l" 
	.string "si no fuera por este asqueroso y\l"
	.string "opresor ambiente family friendly.\p"

	.string "Prosigue, ya avise a mi amo de que vas\n" 
	.string "en camino.\p"

	.string "No tiene fe de que llegues ante el,\n"
	.string "pero si eres tan gilipollas como para\l" 
	.string "haber llegado hasta aquí solo\l" 
	.string "te resta avanzar.$"
	
Darkigym_Text_KizardeIntro: 
	.string "¡Alto Ahí! pequeña ardilla\n"
	.string "como osas entrar en la guarída\l"
	.string "del gran cientifico loco\l"
	.string "D. Kizarde.\p"

	.string "Fu wa ja ja ja ja ja ja ja ja ja$"

Darkigym_Text_KizardeDefeat:
	.string "Oh no! ¡debes ser un agente enviado\n" 
	.string "la organización!\p"

	.string "¡Vienen tras mi ultimo invento!$"

Darkigym_Text_KizardePostBattle:
	.string "Maravillate pequeña ardilla,\n"
	.string "ante la maquina de viaje espacio\l"
	.string "temporal.\p"

	.string "¿Sin ella, como crees que nuestros jefes\n" 
	.string "pueden viajar a tantos mundos?\p"

	.string "Solo un genio como yo,\n"
	.string "el miembro numero uno del laboratorio\l"
	.string "de inventos subterraneos.\p"

	.string "El cientifico loco D. Kizarde,\n"
	.string "podría haber inventado tan\l" 
	.string "impresionante máquina. Mua ja ja\p"

	.string "Ya que me ganaste te contaré un\n"
	.string "secreto.\p"

	.string "Esta máquina la cree con el fin de\n" 
	.string "evitar la tercera guerra\l" 
	.string "interdimensional.\p"

	.string "En la que Gooses junto a las brujas\n" 
	.string "del destino, busca oprimir a toda la\l"
	.string "humanidad con su ejercito de\l" 
	.string "lolis waifus.\p"

	.string "Siendo el detonante... un tal Masuda.\p"

	.string "El cual dio a luz a Lilie para controlar\n"
	.string "las mentes de todos aquellos niños que\l" 
	.string "segun el no tienen tiempo para jugar\l"
	.string "más que juegos cortitos de movil...\p"

	.string "Sabes, veo en ti el poder de cambiar\n"
	.string "el futuro.\p"

	.string "Vamos, sigue adelante y demuestrale a\n"
	.string "nuestro jefe, que puedes hacerlo, y\l" 
	.string "salvarnos a todos de tan\l" 
	.string "aciago destino.$"
	
Darkigym_Text_EspiIntro: 
	.string "Hola intruso.\n"
	.string "¿quieres jugar conmigo?$"

Darkigym_Text_EspiDefeat: 
	.string "Repampanos, se acabo el juego.$"

Darkigym_Text_EspiPostBattle:
	.string "Es una lastima, yo quería seguir jugando\n"
	.string "si te ganaba y mataba.\p"

	.string "Podría haberte añadido a mi colección\n" 
	.string "de cadaveres.\p"

	.string "Y de hecho tengo bastante repetida a\n" 
	.string "cierta niña rubia.\p"

	.string "¿Que? ¿te creias que todas estas tumbas\n" 
	.string "son de adorno?\p"

	.string "Nope... son todas de los enemigos de mi\n" 
	.string "señor que me ha mandado a despedazar\l" 
	.string "con mi guadaña, jia jajajajaja$"
	
Darkigym_Text_MobuIntro: 
	.string "...............$"

Darkigym_Text_MobuDefeat: 
	.string "Ah.. ¿Eh? ¿Que ha pasado?$"

Darkigym_Text_MobuPostBattle:
	.string "Ah... disculpa, creo que me volvi a\n" 
	.string "descontrolar durante mi entrenamiento.\p"

	.string "Aún no logro dominar mi estado 100%...\p"

	.string "Aunque mi maestro el buen rollo, dice\n" 
	.string "que ya logro hacer muchas cosas sin\l" 
	.string "necesidad de usar mis poderes\l" 
	.string "psiquicos.\p"

	.string "Como sea... siento una gran fuerza en\n" 
	.string "ti ¿que buscas aquí?\p"

	.string "¿Dices que estas buscando la medalla\n" 
	.string "del gymnasio?\p"

	.string "¿Que no te da miedo el lider?\p"

	.string "I-increible, ojala pudiera ser tan\n" 
	.string "valiente como tu.\p"

	.string "Bueno, mucha suerte entrenador,\n" 
	.string "te animare desde aquí.$"
	
Darkigym_Text_RoxyIntro: 
	.string "Vaya, así que eres tu el que ha\n" 
	.string "montado tanto revuelo.\p"

	.string "....\p"

	.string "No pareces la gran cosa.\p"

	.string "No se por que los demás se han\n" 
	.string "dejado vencer por ti.\p"

	.string "Oh bueno, supongo que deberé\n" 
	.string "pararte ahora.\p"

	.string "Peleare por el honor del inframundo y la\n"
	.string "felicidad de mis hermanos, por lo que ni\l" 
	.string "de coña puedo permitirme perder.\p" 

	.string "¿Estás preparado?$" 
	
Darkigym_Text_RoxyDefeat: 
	.string "Lo siento... malro y buenro...$"

Darkigym_Text_RoxyPostBattle:
	.string "Rayos.\p"

	.string "Ahora entiendo por que has llegado\n" 
	.string "hasta aquí.\p"

	.string "Por lo que veo tambien dominas el\n" 
	.string "poder de la determinación.\p"

	.string "Supongo que entonces no necesito usar\n" 
	.string "toda mi fuerza, así que puedes pasar.\p"

	.string "Quien sabe, con algo de suerte lograras\n" 
	.string "tranquilizar al mal rollo.\p"

	.string "No lo entiendo muy bien, pero, eso de\n" 
	.string "jugar con las lineas del tiempo,\l" 
	.string "no me mola.\p"

	.string "Adelante humano y recuerda:\p"

	.string "Por horrible y oscuro que se torne\n"
	.string "tu camino, nunca dejes de caminar.$"
	
Darkigym_Text_AnthonyIntro:
	.string "No hay nada mejor que los taladros.\p"
	
	.string "¿Quieres saber por que?\n"
	.string "Pues...\p"
	
	.string "Preparate para mi...\n"
	.string "GIGA\l" 
	.string "DRILL\l" 
	.string "BREAKEEEEEEEEEEEEEEEEEEEEEEEEER.$"

Darkigym_Text_AnthonyDefeat: 
	.string "¡Taladro roto!$"

Darkigym_Text_AnthonyPostBattle:
	.string "Mirate Tengen Toppa Gurren-Lagann.\p"
	
	.string "Solo así sabrás el verdadero\n"
	.string "significado de los taladros y de mi\l"
	.string "técnica definitiva:\p"
	
	.string "Giga Drill Breaker.$"
	
Darkigym_Text_DranixIntro:
	.string "Espero que hayas traido Autan.\p"
	
	.string "¡Porque vas a ser acribillado a\n"
	.string "picaduras de mi ejercito definitivo\l"
	.string "de BEEDRILLs!$"

Darkigym_Text_DranixDefeat: 
	.string "¡Noooo! Mis preciosos BEEDRILLs...$"

Darkigym_Text_DranixPostBattle:
	.string "¡Pero Beedrill tiene que ser un\n"
	.string "OVERUSED como sea!\p"
	
	.string "¡Necesitamos mas gente llevando\n"
	.string "a BEEDRILL en su equipo!\p"
	
	.string "Mmm... mejor actualizaré la Tier List\n"
	.string "para que se así sea.$"
	
Darkigym_Text_Umbreon123Intro:
	.string "Meeeelkor... maaaaaldito...\n"
	.string "Meeeelkor.\p"
	
	.string "Meeeelkor, me baneaaaaste, me\n"
	.string "cambiaaaaste el texto personal y firma.\p"
	
	.string "Pusiste que soy un troll sin gracia y\n"
	.string "que me gusta el flood y el spam.\p"
	
	.string "Y me diste -100 Karma... como a ningún\n"
	.string "otro usuario.\p"
	
	.string "Meeeelkor, me humillaaaaaste.\p"
	
	.string "Meeeelkor.........$"

Darkigym_Text_Umbreon123Defeat: 
	.string "Maaaaaaldito...$"

Darkigym_Text_Umbreon123PostBattle:
	.string "Meeeeelkor, me vengareeeeeeeee.$"
	
Darkigym_Text_UltramagicIntro:
	.string "¡Ey DOOD!\n"
	.string "¿Conoces a LAVENDER?\p"

	.string "¡La POLICIA de JOHTO lo está\n" 
	.string "buscando! ¡Y a mi también, DOOD!\p"
	
	.string "¡Un momento, esto no son las carataras\n"
	.string "TOHJO!\p"

	.string "¡Todo esto es muy raro! ¿¡QUÉ ESTÁ\n"
	.string "PASANDO AQUÍ, DOOD?!$"

Darkigym_Text_UltramagicDefeat: 
    .string "You are all DOOD!$"

Darkigym_Text_UltramagicPostBattle:
	.string "¡Hey DOOD! ¡Era broma!\n"
	.string "Yo soy una personal normal.\p"

	.string "¿Conoces a LAVENDER también?\n"
	.string "Uy, ehm... yo no conozco a NACHO.\l"
	.string ":dood:$"
	
Darkigym_Text_CharzIntro:
	.string "Humanos fuertes...\p"

	.string "Humanos débiles...\p"
	
	.string "Esa es la visión egoista que rige\n" 
	.string "nuestro mundo.\p"
	
	.string "¿Pero acaso hay algún problema\n"
	.string "con ello?\p"
	
	.string "¡Por supuesto que NO!\p"
	
	.string "Los seres humanos somos egoístas por\n"
	.string "naturaleza, aunque vivamos en una\l"
	.string "sociedad con unas reglas autoimpuestas\l"
	.string "que evitan que los verdaderos...\l"
	.string "superhumanos, lo más fuertes, como yo,\l"
	.string "triunfemos siempre.\p"

	.string "Un humano débil no sirve para nada,\n"
	.string "solo nos hace a todos más\l"
	.string "manipulables.\p"
	
	.string "Pero...\p"
	
	.string "Si pudiesemos tirar abajo este maldito\n"
	.string "sistema caduco que ya está apunto\l" 
	.string "de explotar...\p"

	.string "La humanidad por fin conseguiría\n" 
	.string "alcanzar su mayor plenitud porque\l" 
	.string "solo sobreviviríamos los más fuertes\l" 
	.string "de todos.\p"
	
	.string "Por ello, debo eliminar a todos los\n"
	.string "débiles como tu.\p" 
	.string "Selección Natural lo llamo.$"

Darkigym_Text_CharzDefeat: 
	.string "¿SELECCIÓN NATURAL?\p"
	
	.string "¡¡¡NOOOOOOOOOOOOOOOOO!!!$"

Darkigym_Text_CharzPostBattle:
	.string "Eres bastante poderoso...\p"
	
	.string "Deberías unirte a nosotros, podríamos\n"
	.string "conseguir grandes cosas contigo a\l"
	.string "nuestro lado.\p"
	
	.string "...\p"
	
	.string "Oh, venga, ¡Vamos! ¡Unete!\p"
	
	.string "¡Humanos fuertes vivirán!\p"

	.string "¡Humanos débiles morirán!\p"
	
	.string "¡Tenemos que romper este sistema\n"
	.string "caduco!\p"
	
	.string "¡Debemos demostrar al mundo que solo\n"
	.string "lo más fuertes deben sobrevivir!$"
	
Darkigym_Text_FurryIntro:
	.string "Sniff... sniff...\n"
	.string "¡Este lugar apesta a hacks!\p"
	
	.string "Estaba tan tranquilo en la ROUTE 46\n"
	.string "de JOHTO, cuando de pronto ví abrirse\l"
	.string "una especie de portal que me absorbió\l"
	.string "y me trajo a este lugar tan oscuro.\p"
	
	.string "¡Alguien debe haber usado POKEHEX para\n"
	.string "cambiar las coordenadas de mi\l" 
	.string "localización!\p" 

	.string "¡ESTO ES UN HACKEO PELIGROSO!\n" 
	.string "¿ME OYES?\p"
	
	.string "...\p"
	
	.string "Sniff... Sniff...\n"
	.string "¡Tu también hueles a hacks...!\p" 

	.string "¡Malditos Hackers! ¡Os vais a enterar!\p"
	
	.string "Mandaré un aviso a NOENTIENDO para que\n" 
	.string "os baneen para siempre.$"

Darkigym_Text_FurryDefeat: 
	.string "Voy a llamar a NOENTIENDO ¡YA!\p"
	
	.string "En cuanto consiga cobertura...$"

Darkigym_Text_FurryPostBattle:
	.string "La gente aquí debe tener hackeado\n"
	.string "el cerebro.\p"
	
	.string "¿Te puedes creer que el FURRY que\n"
	.string "conocen se corrompió ante los HACKs,\l"
	.string "se unió al bando de MICOLO y toda esa\l"
	.string "chusma, y se fué de JOHTO para luego\l"
	.string "convertirse en un PIRATA?\p"
	
	.string "¡Están mintiendo!\n" 
	.string "¡Yo nunca caería tan bajo!$"
	
Darkigym_Text_DarkMelkorIntro:
	.string "¡DARKNESS! ¡DARKNESS! ¡DARKNESS!\p"

	.string "Interesante... ¡Qué interesante es\n"
	.string "este mundo!\p"
	
	.string "Vengo de un mundo en el que dejé atrás\n"
	.string "parte de mi humanidad para converger\l"
	.string "junto a la oscuridad.\p"
	
	.string "¡SÍ! ¡DARKNESS! ¡DARKNESS! ¡DARKNESS!\p"

	.string "¡Y claro, que valió la pena!\p"

	.string "¡Aplasté con mis propias manos a ese...\n" 
	.string "maldito webmaster de SEREBII!\p"
	
	.string "¡Nunca le perdoné que fastidiase mi\n"
	.string "gran exclusiva de los nombres POKéMON\l" 
	.string "de 5ªGENERACIÓN!\p"
	
	.string "...\p"
	
	.string "¡Ahora debo convencer al MELKOR de\n"
	.string "este mundo para que se una a mí para\l"
	.string "salvar la SAGA POKÉMON de las garras\l"
	.string "de MASUDA!\p"
	
	.string "¡Tenemos que impedir que borre toda la\n"
	.string "POKéDEX!\p"
	
	.string "Pero antes, debo librarme de ti.$"

Darkigym_Text_DarkMelkorDefeat: 
	.string "¡DARKNESS! ¡DARKNESS! ¡DARKNESS!\p"
	
	.string "Aunque lo parezca, no soy un producto\n" 
	.string "de NOMURA.$"

Darkigym_Text_DarkMelkorPostBattle:
	.string "¡DARKNESS! ¡DARKNESS! ¡DARKNESS!\p"

	.string "Mmm... ese portal del que vine me\n" 
	.string "ha hecho perder a la mitad del equipo,\l"
	.string "pero parece que ya no puedo volver.\p"
	
	.string "...\p"
	
	.string "¿Qué es ese portal, dices?\p"

	.string "No te sabría decir, pero parece ser\n"
	.string "que alguien está alterando el equilibrio\l"
	.string "del espacio-tiempo, lo que está\l"
	.string "provocando la apertura de portales\l"
	.string "dimensionales que está trayendo a\l" 
	.string "gentes de otros mundos.\p"
	
	.string "¡Un invento maravilloso!\n" 
	.string "¡Tal vez tengamos una oportunidad para\l"
	.string "abatir el futuro mal que se cierne\l"
	.string "sobre nosotros!\p"
	
	.string "¡SALVEMOS LA SAGA POKéMON DE LAS GARRAS\n"
	.string "DE MASUDA!$"
	
Darkigym_Text_FanboyKalosIntro:
	.string "No tengo ni la más remota idea de donde\n"
	.string "estoy, ¡pero que importa!\l"
	.string "¡VIVA LA 6ªGEN! ¡VIVA POKEMON Z!\p"

	.string "¿CÓMO? ¿QUÉ ES POKEMON Z?\p"
	
	.string "¡PERO COMO PUEDES NO SABERLO! ¡SI ES EL\n"
	.string "MEJOR JUEGO QUE HA SACADO GAMEFREAK\l"
	.string "EN TODOS ESTOS AÑOS!\p"
	
	.string "¿HAS ESTADO VIVIENDO EN UNA CUEVA\n" 
	.string "O QUÉ?\p"
	
	.string "¡EJEM!\n"
	.string "Déjame explicarte las maravillas de\l" 
	.string "POKéMON Z.\p"
	
	.string "Se trata de la secuela de POKÉMON XY,\n"
	.string "y tiene lugar 3 años después, en la\l"
	.string "región de KALOS, pero esta vez todo\l" 
	.string "toma lugar en KALOS SUR.\p"
	
	.string "LYSSON sobrevivió, y vuelve a ser\n" 
	.string "nuestro mayor enemigo, con un plan B:\l" 
	.string "Ha conseguido fusionar a todos los\l" 
	.string "ZYGARDES 1% en uno solo, formando el\l"
	.string "ZYGARDE FORMA COMPLETA 100%.\p"
	
	.string "También hace su aparición VOLCANION,\n" 
	.string "y el juego tiene un contenido POSTGAME\l" 
	.string "fabuloso e inmenso.\p"
	
	.string "El único pero, es que no tiene ningún\n"
	.string "FRENTE BATALLA.\p"
	
	.string "...\p"

	.string "¿¡PERO QUE DICES?!\n" 
	.string "¿¡CÓMO QUÉ NI POKéMON Z, NI KALOS\l" 
	.string "SUR EXISTEN?!\p"

	.string "¡YA ME HE CANSADO DE QUE TE BURLES\n" 
	.string "DE MI!$"

Darkigym_Text_FanboyKalosDefeat: 
	.string "¿PERO QUÉ...?\p"
	
	.string "¿Por qué mi MAWILE no puede...\n"
	.string "megaevolucionar con su Megapiedra\l"
	.string "usando mi Megaanillo?$"

Darkigym_Text_FanboyKalosPostBattle:
	.string "¡Espera! ¿Este no es mi mundo?\n"
	.string "¿Aqui no hay POKeMON Z...?\l"
	.string "¿Tampoco KALOS SUR...?\p"
	
	.string "Pero entonces... ¿Que hay aquí\n"
	.string "después de POKéMON XY?\p"
	
	.string "¿REMAKES DE RSE SIN FRENTE?\n"
	.string "¿POKéMON SOL y LUNA?\l"
	.string "¿ALOLA? ¿ROTOMDEX?\l"
	.string "¿POKéMON LETS GO PIKACHU y EEVEE?\l"
	.string "¿POKéMON ESPADA y ESCUDO con la\l"
	.string "eliminación de la mitad de la Dex?\l"
	.string "¿DINAMAX? ¿GIGAMAX?\l"
	.string "¿DLC a 30 euros y POKÉMON HOME cuatro\l"
	.string "veces más caro que POKéBANCO?\p"

	.string "¡ESTE MUNDO ES UNA MIERDA!$"
	
Darkigym_Text_AngelFSIntro:
	.string "Mire estoy en 1 de secundaria y las\n" 
	.string "16 niñas de mi salon me tratan como\l"
	.string "alfombre osea me aserco y se alejan\l" 
	.string "o gritan: AAAAAA quitate!!!\p"

	.string "y con todas es igual.\n" 
	.string "Que demonios hago!!$"

Darkigym_Text_AngelFSDefeat: 
    .string "Ahora las niñas gritarían:\n" 
	.string "AAAAAA quitate!!!$"

Darkigym_Text_AngelFSPostBattle:
	.string "¡Las niñas ya no están!\p"

	.string "No me volverán a tratar como\n"
	.string "alfombre. :)$"
	
Darkigym_Text_TiloAlolaIntro:
	.string "¡Alola, entrenador!\p"

	.string "Que agradable clima hoy...\p"

	.string "Pero no tanto como mi querida y\n" 
	.string "natal ALOLA con toda esa alegría,\l"
	.string "felicidad, sol y buen clima...\p"

	.string "¿Quieres que comparta mi entusiasmo\n" 
	.string "contigo con un par de buenas\l" 
	.string "malasadas?\p"

	.string "Porque sabes, las malasadas son el mejor\n" 
	.string "manjar del mundo, riquisimas,\l" 
	.string "impedirbles.\p"

	.string "Ven ven, combatamos un poquito, cuando\n" 
	.string "me ganes, te regalare 10 revivires.$"

Darkigym_Text_TiloAlolaDefeat: 
	.string "¡Wow, eres super fuerte, grandioso,\n" 
	.string "maravilloso, todo un maquina, nunca\l" 
	.string "tuve una oportunidad...!$"

Darkigym_Text_TiloAlolaPostBattle:
	.string "¡Quién diría que me encontraría con\n" 
	.string "una persona tan increíble como tu!\p"
	
	.string "¿Que nos acabamos de conocer? da igual,\n" 
	.string "soy tu mas grande admira-\l" 
	.string "AAAAAAAAAAARG!!!!\p"

	.string "¡NO NO PERDONEME SEÑOR MALROLLO!\n" 
	.string "¡NOOOOOOOOO!\p"
	
	.string "................................\p"
	
	.string "(Coges los 10 REVIVE que te iba a dar)$"
	
Darkigym_Text_TiloAlolaPostBattle2:
	.string "................................$"

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
	.string "para matar al imbecil de MASUDA.\p"
	
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
	
	.string "Encuentra a Masuda y partele la boca\n"
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

    .string "¡Demonios, eso también me\n"
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
	.string "no podría contentarme con hacer solo\l" 
	.string "un pasillo simplon en el que se\l" 
	.string "avanzara muy lentamente.\p"

	.string "Así que hice un pasillo en el que\n" 
	.string "avanzas muy lentamente, te puedes\l"
	.string "extraviar para siempre y te asalten\l" 
	.string "todo tipo de trampas mortales\l" 
	.string "meticulozamente colocadas para\l" 
	.string "enviarte directo a un CENTRO POKéMON.\p"
	
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

	.string "Te advierto, te enfrentarás con el rey\n" 
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

	.string "Oh, veo que tu equipo esta decaido.\p"
	
	.string "(Fuiste curado de las heridas)\p"

	.string "Tanto mejor, sigue adelante humano,\n" 
	.string "no pierdas la determinación.$"

Darkigym_Text_BuenroPostBattle2:	
	.string "Oh, veo que tu equipo esta decaido.\p"
	
	.string "(Fuiste curado de las heridas)\p"

	.string "Tanto mejor, sigue adelante humano,\n" 
	.string "no pierdas la determinación.$"
	
Darkigym_Text_BuenroPostBattle3:
	.string "Así que nos derrotaste a ambos, a\n"
	.string "buenro, osea yo, y a malro, es decir,\l"
	.string "mi hermano.\p"
	
	.string "Nyeh heh heh$"

Darkigym_Text_ReceivedBadge:
	.string "{PLAYER} recibió la MEDALLA\n"
	.string "DETERMINACIÓN de DARKIZARD.$"

Darkigym_Text_ExplainBadgeTakeThis:
	.string "Con esta MEDALLA en tu poder, desde\n"
	.string "ahora mismo, tus POKÉMON no tienen\l"
	.string "ninguna limitación para subir hasta\l"
	.string "el nivel 100.\p"
	
	.string "Ahora todo POKEMON intercambiado\n"
	.string "obedecerá todas tus ordenes, incluso\l"
	.string "aunque sean moralmente reprochables.\p"
	
	.string "¡Je! ¡patético!\p"

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
	
Darkigym_Text_CabezaLylie_Sign:
	.string "Parece la cabeza disecada de una niña\n" 
	.string "rubia y de ojos verdes, una expresion\l" 
	.string "de agonia eterna deforma su cara...$"

Darkigym_Text_PCDarki_Sign:
	.string "Aquí hay un correo: Operación Hades en\n" 
	.string "proceso, se necesitan grandes dosis de\l" 
	.string "autismo, la máquina del tiempo, entre\l" 
	.string "otras herramientas han facilitado\l" 
	.string "la obtencion de efectivos para\l" 
	.string "enfrentarnos a un gran mal que se ciñe\l" 
	.string "sobre todos nostros, si todo sale bien\l" 
	.string "lograremos reunir suficiente autismo de\l" 
	.string "este mundo como para evitarlo.\p"
	
	.string "Micolo y El pinguino no tienen por que\n" 
	.string "sospechar nada... $"
	
Darkigym_Text_MaquinaMeteorito_Sign:
	.string "Una máquina que parece micro-ondas, con\n"
	.string "una placa que dice:\p"

	.string "Invento futurista numero X.Y22 máquina\n" 
	.string "de saltos temporales nombre sujeto\l" 
	.string "a revisión.$"
	
Darkigym_Text_CartaMagma1_Sign:
	.string "Es una invitación de un tal Micolo a\n"
	.string "distintas personas para que defiendan\l" 
	.string "su guarida como lideres de Gymnasio.\p"
	
	.string "El final está marcado con una pata\n" 
	.string "de pinguino...$"
	
Darkigym_Text_CartaMagma2_Sign:
	.string "Querido Señor Micolo, Yo y mi hermano\n" 
	.string "malro estaremos complacidos de ser\l" 
	.string "lideres de gymnasio de su liga autista.\p"
	
	.string "Malro esta especialmente emocionado,\n" 
	.string "dice algo que todo entra en sus planes,\l" 
	.string "pero no le haga mucho caso, simplemente\l" 
	.string "le gusta mucho fingir que es un villano,\l" 
	.string "por lo que puede contar con nosotros.$"
	
Darkigym_Text_VitrinaIzquierda_Sign:
	.string "Se ve una lanza color púrpura oscuro\n" 
	.string "con un ojo ensangrentado que te\l" 
	.string "mira fijamente.$"
	
Darkigym_Text_VitrinaDerecha_Sign:
	.string "Una pila de huesos en una caja que tiene\n" 
	.string "escrito a un lado: buenos recuerdos$"


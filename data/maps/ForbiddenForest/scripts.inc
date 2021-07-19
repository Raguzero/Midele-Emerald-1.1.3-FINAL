ForbiddenForest_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ForbiddenForest_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, ForbiddenForest_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, ForbiddenForest_OnLoad
	.byte 0
	
ForbiddenForest_OnResume: 
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ForbiddenForest_EventScript_TryRemoveCelebi
	end
	
ForbiddenForest_OnTransition:
	setflag FLAG_LANDMARK_FORBIDDEN_FOREST
	call_if_unset FLAG_CAUGHT_CELEBI, ForbiddenForest_EventScript_TryShowCelebi
	end
	
ForbiddenForest_OnLoad:
	call_if_unset FLAG_FORBIDDEN_FOREST_CELEBI_ENTRANCE, ForbiddenForest_Script_Close
	end
	
ForbiddenForest_EventScript_Celebi_Sign::
	lockall
	goto_if_set FLAG_FORBIDDEN_FOREST_CELEBI_ENTRANCE, ForbiddenForest_EventScript_Celebi_Sign3	
	msgbox ForbiddenForest_Text_Celebi, MSGBOX_SIGN
	specialvar VAR_RESULT, CheckJirachiMewinTeam
	compare VAR_RESULT, TRUE
	goto_if_eq ForbiddenForest_EventScript_Celebi_Sign2
	end
	
ForbiddenForest_EventScript_Celebi_Sign3::
	lock
	msgbox ForbiddenForest_Text_Celebi, MSGBOX_SIGN
	release
	end

ForbiddenForest_EventScript_Celebi_Sign2::
	waitse
	playmoncry SPECIES_MEW, 2
	delay 40
	waitmoncry
	waitse
	playmoncry SPECIES_JIRACHI, 2
	delay 40
	waitmoncry
	setmetatile 19, 12, METATILE_General_Grass, 0
	setmetatile 19, 13, METATILE_General_Grass, 0
	setmetatile 19, 14, METATILE_General_Grass, 0
	setmetatile 19, 15, METATILE_General_Grass, 0
	setmetatile 20, 12, METATILE_General_Grass, 0
	setmetatile 20, 13, METATILE_General_Grass, 0
	setmetatile 20, 14, METATILE_General_Grass, 0
	setmetatile 20, 15, METATILE_General_Grass, 0
	special DrawWholeMapView
	setflag FLAG_FORBIDDEN_FOREST_CELEBI_ENTRANCE
	msgbox ForbiddenForest_Text_Celebi2, MSGBOX_SIGN
	releaseall
	end
	
ForbiddenForest_Script_Close::
	setmetatile 19, 12, METATILE_General_Grass_TreeUp, 1
	setmetatile 19, 13, 0x016, 1
	setmetatile 19, 14, METATILE_General_Grass_TreeUp, 1
	setmetatile 19, 15, 0x016, 1
	setmetatile 20, 12, METATILE_General_Grass_TreeUp, 1
	setmetatile 20, 13, 0x016, 1
	setmetatile 20, 14, METATILE_General_Grass_TreeUp, 1
	setmetatile 20, 15, 0x016, 1
	return

ForbiddenForest_EventScript_TryRemoveCelebi::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject 1
	return

ForbiddenForest_EventScript_HideCelebi::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_CELEBI
	return

ForbiddenForest_EventScript_TryShowCelebi::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_CELEBI, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_CELEBI
	return

ForbiddenForest_EventScript_Celebi::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CELEBI, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_CELEBI, 60, ITEM_LUM_BERRY
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ForbiddenForest_EventScript_DefeatedCelebi
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq ForbiddenForest_EventScript_RanFromCelebi
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq ForbiddenForest_EventScript_RanFromCelebi
	setflag FLAG_CAUGHT_CELEBI
	release
	end

ForbiddenForest_EventScript_DefeatedCelebi:: 
	setflag FLAG_DEFEATED_CELEBI
	goto Common_EventScript_RemoveStaticPokemon
	end

ForbiddenForest_EventScript_RanFromCelebi:: 
	setvar VAR_0x8004, SPECIES_CELEBI
	goto Common_EventScript_LegendaryFlewAway
	end
	
ForbiddenForest_EventScript_Ezecuter::  
	trainerbattle_single TRAINER_FORBIDDENFOREST_EZECUTER, ForbiddenForest_Text_EzecuterIntro, ForbiddenForest_Text_EzecuterDefeat
	msgbox ForbiddenForest_Text_EzecuterPostBattle, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_EventScript_Kefky::
	trainerbattle_single TRAINER_KEFKY, Kefky_AntesBatalla, Kefky_MensajeDerrota
	msgbox Kefky_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end

ForbiddenForest_EventScript_ElPrincipe::
	trainerbattle_double TRAINER_ELPRINCIPE, ElPrincipe_AntesBatalla, ElPrincipe_MensajeDerrota, ElPrincipe_Text_MasdeunPokemon
	msgbox ElPrincipe_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_EventScript_CharizardFan::
	trainerbattle_single TRAINER_CHARIZARD_FAN, CharizardFan_AntesBatalla, CharizardFan_MensajeDerrota
	msgbox CharizardFan_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_EventScript_Puffu::
	trainerbattle_single TRAINER_PUFFU, ForbiddenForest_Text_PuffuIntro, ForbiddenForest_Text_PuffuDefeat
	msgbox ForbiddenForest_Text_PuffuPostBattle, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_EventScript_Merciboku::
	trainerbattle_single TRAINER_MERCIBOKU, ForbiddenForest_Text_MercibokuIntro, ForbiddenForest_Text_MercibokuDefeat
	msgbox ForbiddenForest_Text_MercibokuPostBattle, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_EventScript_Tenshinhan::
	trainerbattle_single TRAINER_TENSHINHAN, Tenshinhan_AntesBatalla, Tenshinhan_MensajeDerrota
	msgbox Tenshinhan_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_EventScript_Grim::
	trainerbattle_single TRAINER_GRIM, Grim_AntesBatalla, Grim_MensajeDerrota
	msgbox Grim_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_EventScript_JProgamer::
	trainerbattle_single TRAINER_JPROGAMER, JProgamer_AntesBatalla, JProgamer_MensajeDerrota
	msgbox JProgamer_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_EventScript_Castillo::
	trainerbattle_single TRAINER_CASTILLO, Castillo_AntesBatalla, Castillo_MensajeDerrota
	msgbox Castillo_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_EventScript_Santygrass::
	lockall
	msgbox ForbiddenForest_Text_Santygrass_TalkToHimself, MSGBOX_DEFAULT
	faceplayer
	playse SE_PIN
	applymovement 11, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox ForbiddenForest_Text_Santygrass_Talks, MSGBOX_NPC
	setflag FLAG_COMPLETE_FORBIDDEN_FOREST
	applymovement 11, ForbiddenForest_Movement_SantygrassSpin
	waitmovement 0
	playse SE_W100
	applymovement 11, ForbiddenForest_Movement_SantygrassJumpaway
	waitmovement 0
	removeobject 11
	releaseall
	end
	
ForbiddenForest_Movement_SantygrassSpin:
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_4
	step_end

ForbiddenForest_Movement_SantygrassJumpaway:
	face_up
	disable_anim
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	slide_up
	step_end
	
ForbiddenForest_Text_Celebi:
	.string "EL CAMINO HACIA EL VIAJERO DEL\n"
	.string "TIEMPO SOLO SE ABRIRÁ CON LA\l"
	.string "LLAMADA DEL POKÉMON QUE CONTIENE\l"
	.string "EL ADN DE TODOS Y DEL POKÉMON QUE\l"
	.string "PUEDE CONCEDER CUALQUIER DESEO$"
	
ForbiddenForest_Text_Celebi2:
	.string "EL CAMINO SE HA ABIERTO\n"
	.string "EL VIAJERO DEL TIEMPO QUIERE VERTE$"

ForbiddenForest_Text_EzecuterIntro: 
	.string "Dicen que por aquí se esconde.\n"
	.string "un Pokémon legendario.$"

ForbiddenForest_Text_EzecuterDefeat: 
	.string "¡¡¡Eres bochornoso!!!$"

ForbiddenForest_Text_EzecuterPostBattle: 
	.string "Eres totalmente bochornoso.$"
	
ForbiddenForest_Text_PuffuIntro: 
	.string "Hola, ¿Eres fan de los Puffus?$"

ForbiddenForest_Text_PuffuDefeat: 
	.string "¿Por qué has hecho daño a los\n"
	.string "Puffus? T.T$"

ForbiddenForest_Text_PuffuPostBattle:
	.string "No le hagas caso a DARKIZARD.\p"

	.string "¡Añade un Puffu en tu vida!\p"
	
	.string "¡Si es que son tan monos! :puffu:$"
	
ForbiddenForest_Text_MercibokuIntro: 
	.string "la primera vez y mucho menos\n" 
	.string "sera la ultima que me masturbo\l" 
	.string "con mi lopunny o con mi gardevoir.\p"
	
	.string "A veces me entran las ganas de una\n" 
	.string "gordita y me hecho a chansey =P\l" 
	.string "(mi garcha es muy caprichosa jeje)\p"
	
	.string "y aunque me paso horas con mi\n" 
	.string "machamp hombre en el poke-recreo\l" 
	.string "no me considero para nada gay.$"

ForbiddenForest_Text_MercibokuDefeat: 
	.string "Ay... mi pobre garcha...$" 

ForbiddenForest_Text_MercibokuPostBattle:
	.string "De verdad no te gustaría probar\n"
	.string "una gordita? =P$"
	
Kefky_AntesBatalla: 
	.string "Yo solo uso un Pokémon si es mono.$"

Kefky_MensajeDerrota: 
	.string "¿A que eran monos?$"
 
Kefky_DespuesDeBatalla:
	.string "Me he vestido de mujer por perder\n"
	.string "una apuesta, pero soy un tío.$"

ElPrincipe_AntesBatalla: 
	.string "¡Por fin he ideado la estrategia\n"
	.string "definitiva que me llevará a lo\l"
	.string "más alto del firmamento!\p"
	
	.string "Ten en cuenta que esto será una\n"
	.string "BATALLA DOBLE.\p"

	.string "Te mostraré la estrategia de mi\n"
	.string "fenomenal equipo.\p"
	
	.string "La genuina estrategia de la...\n"
	.string "FLOR DEL FIRMAMENTO.$"

ElPrincipe_MensajeDerrota: 
	.string "¡IMPOSIBLE!\p"
	
	.string "La estrategia de la FLOR DEL\n"
	.string "FIRMAMENTO... con los 4 climas\l"
	.string "ha sido desarmada...\p"

	.string "No puedes saber que tipo de\n"
	.string "WEATHER BALL usa mi ROSERADE\l"
	.string "contra ti...\p"

	.string "Debería haberte puesto contra\n"
	.string "las cuerdas solo por eso...\p"

	.string "¡No lo entiendo!$"
 
ElPrincipe_DespuesDeBatalla:
	.string "Mirad, os quiero explicar cómo\n" 
	.string "funciona este equipo ya que no lo\l" 
	.string "voy a usar...\p"
	
	.string "Da igual a quien saque primero\n" 
	.string "la clave es sacar primero siempre\l"
	.string "a ROSERADE.\p"
	
	.string "Si saco a TYRANITAR con ROSERADE,\n" 
	.string "hago WEATHER BALL de tipo-roca sin\l" 
	.string "esperar a que TYRANITAR haga\l" 
	.string "SANDSTORM.\p" 
	
	.string "Si saco a JOLTEON, que es más rápido\n" 
	.string "que ROSERADE, hace RAIN DANCE y\l" 
	.string "ROSERADE WEATHER BALL del tipo-agua.\p"

	.string "Si uso SUNNY DAY, entonces mi\n" 
	.string "ROSERADE usará WEATHER BALL del\l"
	.string "tipo-fuego.\p" 	
	
	.string "Y por último lo puedo sacar también\n"
	.string "con ABOMASNOW, que no hace falta que\l" 
	.string "haga nada para que se ponga a granizar\l" 
	.string "y ROSERADE hace WEATHER BALL del\l"
	.string "tipo-hielo.\p"
	
	.string "...\p"
	
	.string "¿Qué 4 climas en un equipo de BATALLA\n"
	.string "DOBLES es una estupidez?\p"
	
	.string "...\p"
	
	.string "¿Y qué no puedo depender solo de mi\n"
	.string "ROSERADE para que toda la estrategia\l" 
	.string "funcione de forma óptima?\p"
	
	.string "¿Estás intentando decir que mi equipo es\n"
	.string "es malisimo y que lo rehaga de 0?\p"
	
	.string "¡No te mofes de mí, lo que pasa es que\n"
	.string "no tienes imaginación!$"
	
ElPrincipe_Text_MasdeunPokemon: // BATALLA DOBLE
	.string "Así que solo llevas un Pokémon?\n"
	.string "No puedo luchar contigo, entonces.\p"

	.string "Mi estrategia de la FLOR DEL FIRMAMENTO\n"
	.string "solo brilla en BATALLA DOBLE.$"
	
CharizardFan_AntesBatalla: 
	.string "MEGA CHARIZARD X, MEGA CHARIZARD Y,\n"
	.string "y GIGA CHARIZARD son los mejores.\p"
	
	.string "¡VIVA GAMEFREAK!\p"

	.string "¡VIVA CHARIZARD!$"

CharizardFan_MensajeDerrota: 
	.string "¿CÓMOOOOOOOOOOOOOOOOO?\p"
	
	.string "Le pediré a GF otra forma de CHARIZARD.$"
 
CharizardFan_DespuesDeBatalla:
	.string "¿Qué por qué solo quiero cosas nuevas\n"
	.string "para CHARIZARD?\p"

	.string "Porque CHARIZARD es el mejor POKÉMON\n" 
	.string "de la saga.\p"
	
	.string "Le pediré a GF una MEGA CHARIZARD Z.\p"
	
	.string "¿O mejor otra Gigamax?\p"
	
	.string "¿O tal vez una Forma Regional de tipo\n"
	.string "Dragon/Fuego?$"
	
Tenshinhan_AntesBatalla: 
	.string "Bueno, novato, veamos que puedes hacer\n" 
	.string "contra este negro, pero te aviso que\l" 
	.string "acabarás llorando...$"

Tenshinhan_MensajeDerrota: 
	.string "Vaya, pues sí que me has ganado, hora\n" 
	.string "de volver a la tumba otros 5 años$"
 
Tenshinhan_DespuesDeBatalla:
	.string "Siempre digo que lo dejo y aquí me ves,\n" 
	.string "hablándote a través de una hackrom\l" 
	.string "diciéndote estás tonterías.\p"
	
	.string "Pero aquí sigo. Jejeje$"

Grim_AntesBatalla: 
	.string "Hola, viajero. Por tu aspecto y\n" 
	.string "mirada deduzco que estás embarcado\l" 
	.string "en un largo viaje.\p" 
	
	.string "En tiempos yo también estuve inmerso\n" 
	.string "en uno, pero no acabó tan bien como\l" 
	.string "esperaba. Perdí la fe en muchas\l" 
	.string "cosas en las que creía, aunque\l"
	.string "al menos me consuela saber que\l"
	.string "muchas lecciones.\p"
	
	.string "Ahora dedico mis días a la vida\n"
	.string	"contemplativa, buscando la mejora\l"
	.string "personal y la pureza del alma.\p"
	
	.string "¿Sabes?\n" 
	.string "Este bosque engaña. A pesar de\l" 
	.string "su tranquilidad, noto que guarda\l" 
	.string "algunos secretos. Quizá esté\l" 
	.string "relacionado de alguna manera\l" 
	.string "con Génesis... el Árbol de la\l"
	.string "Vida.\p" 
	
	.string "Un tal Krossotha Vader\n"
	.string "lo buscaba con ahínco.\p"
	
	.string "Un tipo turbio y malvado...\p"

	.string "En fin, discúlpame.\n" 
	.string "Estoy aquí soltándote una\l" 
	.string "turra que ni te va ni te\l" 
	.string "va ni te viene y seguro que y\l" 
	.string "solo buscas combatir.\p"
	
	.string "Mis Pokémon no es que sean los\n" 
	.string "más fuertes, pero son los que\l" 
	.string "han crecido a mi lado. ¡Veamos\l" 
	.string "de qué pasta estás hecho!$"  

Grim_MensajeDerrota: 
	.string "¡Así son las cosas! Reconozco\n" 
	.string "tu justa pericia y mi derrota.$"  
 
Grim_DespuesDeBatalla:
	.string "Viris acquirit eundo.\p"

	.string "La fuerza se adquiere avanzando.\n" 
	.string "Es algo que aprendí durante\l" 
	.string "mi aventura.\p"
	
	.string "¡Sigue adelante, entrenador!\n"
	.string "Hasta el fin del mundo, si\l" 
	.string "es preciso.\p"
	
	.string "Espíritus fuertes como el\n" 
	.string "tuyo me hacen creer que un\l" 
	.string "mundo mejor es posible.$"
	
JProgamer_AntesBatalla: 
	.string "No sé si sabeis que es un borrego\n" 
	.string "pero es alguien que le cree todo\l"
	.string "al nuevo orden mundial que se ha\l"
	.string "instaurado ya en la sociedad.\p"
	
	.string "Llevo varios años y Mideles avisando,\n"
	.string "¡pero nadie me hizo caso!\p"
	
	.string "¡Ya es tarde! ¡Muy tarde!\p"
	
	.string "El nuevo orden mundial ya nos obliga\n"
	.string "a llevar bozales para callarnos ante\l"
	.string "las versiones oficiales del gobierno.\p"
	
	.string "La medicina actual no busca curarnos,\n"
	.string "busca mantenernos vivos y enfermos\l"
	.string "para sacarnos el dinero.\p"
	
	.string "Y los alimentos transgénicos y la leche\n"
	.string "materna son claramente cancerígenas.\p"
	
	.string "¿Que será lo próximo? ¿Ponermos en fila\n"
	.string "como borregos para que nos metan un\l"
	.string "PCR por el culo?\p"
	
	.string "...\p"
	
	.string "¿Qué pasa?\n"
	.string "¿Quieres fuentes de todo esto?\p"

	.string "¡No necesito fuentes, debatir con\n" 
	.string "borregos es lo mismo que perder\l" 
	.string "el tiempo, todas las fuentes\l"
	.string "están trucadas!\p"

	.string "¡Demuéstrame que no eres un borrego\n"
	.string "del sistema!$"

JProgamer_MensajeDerrota: 
	.string "¡Otro maldito borrego del sistema!\p"

	.string "¡Te voy a jalar el clito...!$"
 
JProgamer_DespuesDeBatalla:
	.string "¡Todo el que vaya en contra de la versión\n"
	.string "oficial, será tratado como un peligroso\l"
	.string "negacionista!\p"
	
	.string "¡Esta plandemia existe para controlarnos\n"
	.string "mentalmente a todos con el 5G!\p"
	
	.string "¿Fuentes? Ya te lo he dicho antes,\n"
	.string "maldito borrego.\p"
	
	.string "¡No necesito fuentes, debatir con\n" 
	.string "borregos es lo mismo que perder\l" 
	.string "el tiempo, todas las fuentes\l"
	.string "están trucadas!$"
	
Castillo_AntesBatalla: 
	.string "veo a arceus arriba de mi casa en serio\n"
	.string "lo juro$" 

Castillo_MensajeDerrota: 
	.string "es en serio que veo a arceus\n" 
	.string "no estoy loco$"
 
Castillo_DespuesDeBatalla:
	.string "ablo muy enceio por que lo vi en la\n"
	.string "vida real a arceus, lo juro\p"
	
	.string "por cierto\n"
	.string "parece que ash tiene un crayon en el\l"
	.string "cerebro como homero simpson, ojala que\l"
	.string "serena no me haga nada por decir esto$" 
	
ForbiddenForest_Text_Santygrass_TalkToHimself:
	.string "Que extraño es este bosque...\p"

	.string "Por mucho que lo intente quemar...\n"
	.string "¡Las llamas se vuelven a apagar!\p"
	
	.string "Siento como si el mismísimo TIEMPO\n"
	.string "volviese hacia atrás cada vez que\l"
	.string "lo intento.\p"

	.string "¿Debe ser que el CELEBI de este mundo\n"
	.string "es el protector de este bosque?$"

ForbiddenForest_Text_Santygrass_Talks:
	.string "¡Oh! ¡No me dí cuenta de que estabas\n"
	.string "ahí!\p"

	.string "Así que eres {PLAYER} ¿eh?\n"
	.string "He oido cosas impresionantes de tí.\p"
	
	.string "Yo soy SANTYGRASS, uno de los cuatro\n"
	.string "lideres de GYM de MICOLANDIA.\l"
	.string "¿Me estabas buscando?\p"
	
	.string "De acuerdo, ahora mismo vuelvo a mi\n"
	.string "GYMNASIO para esperar tu desafío.\l"
	.string "¡No te lo pondré fácil!\p"

	.string "Y recuerda: ¡No hay nada mejor\n"
	.string "que el olor a hierba quemada!$"

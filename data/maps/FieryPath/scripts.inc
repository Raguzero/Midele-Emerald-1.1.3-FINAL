FieryPath_MapScripts:: @ 8230F24
	map_script MAP_SCRIPT_ON_RESUME, FieryPath_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, FieryPath_OnLoad
	.byte 0

FieryPath_OnTransition: @ 8230F2A
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
	setflag FLAG_LANDMARK_FIERY_PATH
	call_if_unset FLAG_CAUGHT_MOLTRES, Fiery_Path_EventScript_TryShowMoltres
	end
	
FieryPath_OnResume: 
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Fiery_Path_EventScript_TryRemoveMoltres
	end
	
FieryPath_OnLoad: @ 81F2561
	call_if_unset FLAG_SYS_GAME_CLEAR, Fiery_Path_EventScript_HideMoltres
	end
	
    @ Combate contra totem.
Fiery_Path_EventScript_Totem::
	lockall
	msgbox DesafiarTotem_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Fiery_Path_EventScript_Totem2
	releaseall
	end	

Fiery_Path_EventScript_Totem2::
	playmoncry SPECIES_CENTISKORCH, 2
	delay 40
	waitmoncry
	msgbox Fiery_Path_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_CENTISKORCH
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 9
	removeobject 11
	removeobject 12
	removeobject 13
	removeobject 14
	removeobject 15
	setflag FLAG_TOTEM_FIERYPATH
    msgbox Fiery_Path_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.	

FieryPath_EventScript_MoveScottToFallarbor:: @ 8230F37
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	return
	
Fiery_Path_EventScript_TryRemoveMoltres::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Common_EventScript_NopReturn
	removeobject 10
	return

Fiery_Path_EventScript_HideMoltres::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_MOLTRES
	return

Fiery_Path_EventScript_TryShowMoltres::
	setvar VAR_TEMP_1, 1
	goto_if_unset FLAG_SYS_GAME_CLEAR, Common_EventScript_NopReturn
	goto_if_set FLAG_DEFEATED_MOLTRES, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_MOLTRES
	return

Fiery_Path_EventScript_Moltres::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MOLTRES, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_MOLTRES, 60, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Fiery_Path_EventScript_DefeatedMoltres
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Fiery_Path_EventScript_RanFromMoltres
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Fiery_Path_EventScript_RanFromMoltres
	setflag FLAG_CAUGHT_MOLTRES
	release
	end

Fiery_Path_EventScript_DefeatedMoltres:: 
	setflag FLAG_DEFEATED_MOLTRES
	goto Common_EventScript_RemoveStaticPokemon
	end

Fiery_Path_EventScript_RanFromMoltres:: 
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end
	
Fiery_Path_EventScript_Pacochef::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_FIERYPATH_PACOCHEF, NULL, Fiery_Path_Text_PacochefIntro, Fiery_Path_Text_PacochefDefeat, Fiery_Path_PacochefPostBattle
	msgbox Fiery_Path_Text_PacochefPostBattle
	closemessage
	end
	
Fiery_Path_PacochefPostBattle::
	msgbox Fiery_Path_Text_PacochefPostBattle
	closemessage
	end

Fiery_Path_Text_PacochefIntro:
	.string "Oh, anda, la piltrafilla del\n"
	.string "museo de SLATEPORT CITY.\p"
	
	.string "Veo que haces progresos, ¿eh?\p"

	.string "Has vencido a mis compañeros y además\n" 
	.string "tienes otra medalla.\p"
	
	.string "¿Uh? ¿La MAFIA? JAJAJAJA no me hagas\n" 
	.string "reír, venimos aquí, principalmente, a\l" 
	.string "encendernos los porros.\p" 
	
	.string "Por muy bocazas que sean, solo somos\n" 
	.string "una pandilla de degenerados venida\l" 
	.string "a menos.\p" 
	
	.string "Puede que nos veamos en otra ocasión.\p"
	
	.string "Ahora bien... ¿Ves este bicharraco\n" 
	.string "de aquí?\p" 
	
	.string "Probablemente ya hayas encontrado\n" 
	.string "POKéMON así durante la aventura.\p" 
	
	.string "Me gusta llamarlos TOTEM, o DOMINANTES.\p" 
	
	.string "Estos pobres desgraciados han sido\n" 
	.string "modificados en el LABORATORIO MIDELE\l"
	.string "con fines macabros.\p" 
	
	.string "¿Que qué hacen repartidos por\n"
	.string "la región?\p"
	
	.string "Uh... si me das un combate entretenido,\n" 
	.string "tal vez te lo diga.\p" 
	
	.string "¿Preparado? SO NO CHI NO SADAMEEEEEEEE$"

Fiery_Path_Text_PacochefDefeat: 
	.string "Ajajajajaja, combatir fumado\n"
	.string "es la polla.$"

Fiery_Path_Text_PacochefPostBattle: 
	.string "Jeje... bien, lo drometido es peuda.\p"
	
	.string "Como dije antes, la terrible\n" 
	.string "ORGANIZACIÓN MIDELAR es real.\p" 
	
	.string "Hace tiempo intentó tomar el control\n" 
	.string "en KANTO y JOHTO, pero MICOLO I, aquel\l" 
	.string "que Mono es uno y la vida un Ciclo,\l" 
	.string "falló en ambas ocasiones.\p" 
	
	.string "Pero aquí en HOENN sus intenciones son\n" 
	.string "aún más perversas.\p" 
	
	.string "Ha corrompido por completo el ADN de\n" 
	.string "muchos POKéMON y este es el resultado,\l" 
	.string "los TOTEM.\p" 
	
	.string "Llevo mucho tiempo infiltrado en su\n" 
	.string "organización, y tras ver sufrir a estos\l" 
	.string "monstruitos, decidí liberarlos\l"
	.string "por HOENN.\p"
	
	.string "Quizá liberarlos no es la palabra...\n" 
	.string "los solté para dar un buen espectáculo,\l" 
	.string "causar un poco de caos y ver quién\l" 
	.string "podía hacerles frente.\p"
	
	.string "Divertido, ¿verdad?...\p" 
	
	.string "¿No te lo parece? Vaya furryoso\n" 
	.string "amargado meh.\p"
	
	.string "Por ahora no lo has hecho nada mal,\n"
	.string "¿podrás con el que tenemos\l"
	.string "ahí delante?\p"
	
	.string "Quién sabe. Quizá te arranque los dedos\n" 
	.string "uno a uno.\p"
	
	.string "Quizá si vences a todos te conviertas en\n"
	.string "el elegido destinado a derrotar a MICOLO\l" 
	.string "de una vez por todas.\p" 
	
	.string "O tal vez te convertirás en su sujeto de\n" 
	.string "pruebas JAJAAAAA.\p" 
	
	.string "No lo sabrás hasta que lo hagas.\p" 
	
	.string "Mientras tanto... nos veremos en otra\n" 
	.string "ocasión, pero trae algo de ron para\l" 
	.string "amenizar las charletas.$"
	
Fiery_Path_EventScript_Chinpo::  
	trainerbattle_single TRAINER_FIERYPATH_CHINPO, Fiery_Path_Text_ChinpoIntro, Fiery_Path_Text_ChinpoDefeat
	msgbox Fiery_Path_Text_ChinpoPostBattle, MSGBOX_AUTOCLOSE
	end

Fiery_Path_Text_ChinpoIntro: 
	.string "PxP... quién te ha visto\n"
	.string "y quién te ve...\p"
	
	.string "Quedarás en nuestros\n"
	.string "recuerdos.\p"
	
	.string "¡Siempre se van los mejores!\p"
	
	.string "...\p"
	
	.string "¿EING? ¡Pero si tú no eres\n"
	.string "de los nuestros!$"

Fiery_Path_Text_ChinpoDefeat: 
	.string "¿BULBASAUR? ¿Qué te ha pasado?$"

Fiery_Path_Text_ChinpoPostBattle: 
	.string "Parece que me he pasado dándole\n"
    .string "las anfetavitaminas a mi BULBASAUR...\p"
    
    .string "¡Se le salen hasta los ojos de\n"
    .string "sus órbitas!$"
	
Fiery_Path_EventScript_Kaderete::  
	trainerbattle_single TRAINER_FIERYPATH_KADERETE, Fiery_Path_Text_KadereteIntro, Fiery_Path_Text_KadereteDefeat
	msgbox Fiery_Path_Text_KaderetePostBattle, MSGBOX_AUTOCLOSE
	end

Fiery_Path_Text_KadereteIntro: 
	.string "Te estás metiendo en la boca del\n"
	.string "lobo, pero ya es demasiado tarde\l"
	.string "para que te eches atrás.\p"
	
	.string "¡Yo soy KADERETE, y somos la\n" 
	.string "MAFIA PxP! ¡No vamos a permitir\l"
	.string "que nadie se chive de nuestros\l"
	.string "planes al STAFF de PxP!\p"
	
	.string "¡Nos hemos llevado muchos Warns, Bans\n"
	.string "y gastado muchas multicuentas para\l"
	.string "llegar hasta aquí!\p"
	
	.string "...\p"
	
	.string "¡AH, JODER! ¡Pero si PxP está muerto!\p"
	
	.string "Y por tanto tampoco somos ya la\n"
	.string "MAFIA PxP...\p"
	
	.string "¡Bah, qué más da! ¡Pelea!$"

Fiery_Path_Text_KadereteDefeat: 
	.string "¿Cómo has resistido la HYPNOSIS\n"
	.string "de mi MONSTER HAUNTER?$"

Fiery_Path_Text_KaderetePostBattle: 
	.string "Te lo vuelvo a decir, aquí no se te ha\n"
	.string "perdido nada, así que mejor vuelve a\l"
	.string "casa con tu mamá, o busca a la puta\l"
	.string "madre de KRUB en el polígono, lo que\l"
	.string "tu prefieras.$"
	
Fiery_Path_EventScript_Krub::  
	trainerbattle_single TRAINER_FIERYPATH_KRUB, Fiery_Path_Text_KrubIntro, Fiery_Path_Text_KrubDefeat
	msgbox Fiery_Path_Text_KrubPostBattle, MSGBOX_AUTOCLOSE
	end

Fiery_Path_Text_KrubIntro: 
	.string "La idea que ha tenido PACOCHEF hace que\n"
	.string "esta región sea más interesante.\p"
	
	.string "Por cierto, ¿quieres que te cuente algo\n"
	.string "más interesante que eso?\p"
	
	.string "Para ello, ¡tendrás que vencerme!$"

Fiery_Path_Text_KrubDefeat: 
	.string "Pues eso. Ahora te cuento.$"

Fiery_Path_Text_KrubPostBattle: 
	.string "Mejor me dedico al cultivo de una\n"
	.string "granja de setas.\p"

	.string "Ni te imaginas lo nutritivas que son.\p"

	.string "Por cierto, dicen que han visto a\n"
	.string "la puta madre de KADERETE en el\l"
	.string "polígono y parece que tiene\l"
	.string "muchos clientes.$"
	
Fiery_Path_EventScript_DobleC::  
	trainerbattle_single TRAINER_FIERYPATH_DOBLEC, Fiery_Path_Text_DobleCIntro, Fiery_Path_Text_DobleCDefeat
	msgbox Fiery_Path_Text_DobleCPostBattle, MSGBOX_AUTOCLOSE
	end

Fiery_Path_Text_DobleCIntro:
	.string "¿Otro NOOB pasa por aquí?\n"
	.string "¡JAJAJAJAJAJAJA!\p"
	
	.string "Mi nombre es DOBLE C.\p"

	.string "¡Y me encanta ayudar a promover\n"
	.string "el CAOS en esta región!\p"
	
	.string "¡Me hace sentir vivo!\p"
	
	.string "Y sobre todo, lo voy a gozar\n"
	.string "por ver la cara que van a poner\l" 
	.string "los NOOBS como tu cuando descubran\l"
	.string "lo que hemos preparado.\p"
	
	.string "¡JAJAJAJAJAJAJA!\p"
	
	.string "¡Siente el poder de la antigua\n"
	.string "MAFIA PxP!$"

Fiery_Path_Text_DobleCDefeat: 
	.string "Debería haber traido al equipo\n"
	.string "bueno, en vez de al que me enciende\l"
	.string "los porros.$"

Fiery_Path_Text_DobleCPostBattle: 
	.string "¡Cuando descubras la sorpresa te vas\n"
	.string "a caer de culo, pedazo de NOOB!$"

Fiery_Path_Text_Totemaparece:
	.string "CENTISKORCH, the TOTEM POKéMON of\n" 
	.string "FIERY PATH, has appeared!$"
	
Fiery_Path_Text_Totemderrotado:
	.string "CENTISKORCH disappeared...$"

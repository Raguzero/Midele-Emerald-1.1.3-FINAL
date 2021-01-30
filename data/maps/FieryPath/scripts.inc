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
Fiery_Path_EventScript_Totem:: @ 8237725
	lockall
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
	trainerbattle_single TRAINER_FIERYPATH_PACOCHEF, Fiery_Path_Text_PacochefIntro, Fiery_Path_Text_PacochefDefeat
	msgbox Fiery_Path_Text_PacochefPostBattle, MSGBOX_AUTOCLOSE
	end

Fiery_Path_Text_PacochefIntro: 
	.string "FRASES.\n"
	.string "FRASES.$"

Fiery_Path_Text_PacochefDefeat: 
	.string "FRASE$"

Fiery_Path_Text_PacochefPostBattle: 
	.string "FRASES.$"
	
Fiery_Path_EventScript_Chinpo::  
	trainerbattle_single TRAINER_FIERYPATH_CHINPO, Fiery_Path_Text_ChinpoIntro, Fiery_Path_Text_ChinpoDefeat
	msgbox Fiery_Path_Text_ChinpoPostBattle, MSGBOX_AUTOCLOSE
	end

Fiery_Path_Text_ChinpoIntro: 
	.string "FRASES.\n"
	.string "FRASES.$"

Fiery_Path_Text_ChinpoDefeat: 
	.string "¿BULBASAUR? ¿Qué te ha pasado?$"

Fiery_Path_Text_ChinpoPostBattle: 
	.string "Parece que me he pasado dandole\n"
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
	
	.string "¡Somos la Mafia PxP, y no vamos a\n"
	.string "permitir que nadie arruine nuestros\l"
	.string "planes!$"

Fiery_Path_Text_KadereteDefeat: 
	.string "No funcionó bien la estrategia.$"

Fiery_Path_Text_KaderetePostBattle: 
	.string "Te lo vuelvo a decir, aquí no se te ha\n"
	.string "perdido nada, así que mejor vuelve a\l"
	.string "casa con tu mamá.$"
	
Fiery_Path_EventScript_Krub::  
	trainerbattle_single TRAINER_FIERYPATH_KRUB, Fiery_Path_Text_KrubIntro, Fiery_Path_Text_KrubDefeat
	msgbox Fiery_Path_Text_KrubPostBattle, MSGBOX_AUTOCLOSE
	end

Fiery_Path_Text_KrubIntro: 
	.string "FRASES.\n"
	.string "FRASES.$"

Fiery_Path_Text_KrubDefeat: 
	.string "FRASE$"

Fiery_Path_Text_KrubPostBattle: 
	.string "FRASES.$"
	
Fiery_Path_EventScript_DobleC::  
	trainerbattle_single TRAINER_FIERYPATH_DOBLEC, Fiery_Path_Text_DobleCIntro, Fiery_Path_Text_DobleCDefeat
	msgbox Fiery_Path_Text_DobleCPostBattle, MSGBOX_AUTOCLOSE
	end

Fiery_Path_Text_DobleCIntro:
	.string "¿Otro NOOB pasa por aquí?\n"
	.string "¡JAJAJAJAJAJAJA!\p"
	
	.string "Mi nombre es DOBLE C.\p"

	.string "¡Y me encanta ayudar a promover\n"
	.string "el CAOS en esta región.\p"
	
	.string "¡Me hace sentir vivo!\p"
	
	.string "Y sobre todo, lo voy a gozar\n"
	.string "por ver la cara que van a poner\l" 
	.string "los NOOBS como tu cuando descubran\l"
	.string "lo que hemos planeado.\p"
	
	.string "¡JAJAJAJAJAJAJA!\p"
	
	.string "¡Siente el poder de la Mafia PxP!$"

Fiery_Path_Text_DobleCDefeat: 
	.string "Debería haber traido al equipo\n"
	.string "bueno, en vez de al que me enciende\l"
	.string "los porros.$"

Fiery_Path_Text_DobleCPostBattle: 
	.string "¡Cuando descubras la sorpresa te vas\n"
	.string "a caer de culo, pedazo de NOOB!$"

Fiery_Path_Text_Totemaparece:
	.string "CENTISKORCH, the Totem Pokémon of\n" 
	.string "Fiery Path, has appeared!$"
	
Fiery_Path_Text_Totemderrotado:
	.string "CENTISKORCH disappeared...$"


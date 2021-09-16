MicoloLeagueLobby_MapScripts:: @ 82295D2
	map_script MAP_SCRIPT_ON_TRANSITION, MicoloLeagueLobby_PokemonCenter_OnTransition

	.byte 0
	
MicoloLeagueLobby_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_MICOLANDIA
	call Common_EventScript_UpdateBrineyLocation
	compare VAR_STATE_MICOLANDIA, 3
	call_if_eq MicoloLeagueLobby_EventScript_SetGuardUnblockingDoor
   	compare VAR_STATE_MICOLANDIA, 3
	call_if_ne MicoloLeagueLobby_EventScript_SetGuardBlockingDoor
	end

MicoloLeagueLobby_EventScript_SetGuardUnblockingDoor::
	setobjectxyperm 8, 8, 2 
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm 10, 11, 2 
	setobjectmovementtype 10, MOVEMENT_TYPE_FACE_DOWN
	return

MicoloLeagueLobby_EventScript_SetGuardBlockingDoor::
	setobjectxyperm 8, 9, 2
	setobjectxyperm 10, 10, 2
	setobjectmovementtype 10, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 10, MOVEMENT_TYPE_FACE_DOWN
	return


@ VAR_0x800B is the Nurse's object event id
MicoloLeagueLobby_PokemonCenter_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end
  
MicoloLeagueLobby_EventScript_1::
	msgbox MicoloLeagueLobby_Text_1, MSGBOX_NPC
	end
	
MicoloLeagueLobby_EventScript_2::
	msgbox MicoloLeagueLobby_Text_2, MSGBOX_NPC
	end
	
MicoloLeagueLobby_EventScript_3::
	msgbox MicoloLeagueLobby_Text_3, MSGBOX_NPC
	end
	
MicoloLeagueLobby_EventScript_4::
	msgbox MicoloLeagueLobby_Text_4, MSGBOX_NPC
	end

MicoloLeagueLobby_Sign_1::
	msgbox MicoloLeagueLobby_Text_5, MSGBOX_SIGN
	end
	
MicoloLeagueLobby_EventScript_ResetTrainerFlagsMachine::
	lock
	faceplayer
	msgbox MicoloLeagueLobby_Text_ResetTrainerFlagsMachine, MSGBOX_NPC
	msgbox MicoloLeagueLobby_Text_ResetTrainerFlagsMachinePregunta, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MicoloLeagueLobby_EventScript_ResetTrainerYES
	msgbox MicoloLeagueLobby_Text_ResetTrainerFlagsMachineNO, MSGBOX_DEFAULT
	release
	end
MicoloLeagueLobby_EventScript_ResetTrainerYES:
	msgbox MicoloLeagueLobby_Text_ResetTrainerFlagsComplete, MSGBOX_DEFAULT	
	cleartrainerflag TRAINER_ENTROPIA
	cleartrainerflag TRAINER_UTALAWEA
	cleartrainerflag TRAINER_FORBIDDENFOREST_EZECUTER
	cleartrainerflag TRAINER_ISMAPKM_1
	cleartrainerflag TRAINER_GOLDIE
	cleartrainerflag TRAINER_KEFKY
	cleartrainerflag TRAINER_ELPRINCIPE
	cleartrainerflag TRAINER_JZOMBIE2
	cleartrainerflag TRAINER_CHARIZARD_FAN
	cleartrainerflag TRAINER_JAVISITO_POSTGAME
	cleartrainerflag TRAINER_MERUM
	cleartrainerflag TRAINER_TREVEJO
	cleartrainerflag TRAINER_PUFFU 
	cleartrainerflag TRAINER_MERCIBOKU 
	cleartrainerflag TRAINER_EEVEETO 
	cleartrainerflag TRAINER_UTALAWEA 
	cleartrainerflag TRAINER_TENSHINHAN 
	cleartrainerflag TRAINER_KAISSER 
	cleartrainerflag TRAINER_FELIPEX88 
	cleartrainerflag TRAINER_RED_KROW 
	cleartrainerflag TRAINER_GRIM 
	cleartrainerflag TRAINER_MAESTRO_ARENA 
	cleartrainerflag TRAINER_MANEC 
	cleartrainerflag TRAINER_ALPHA 
	cleartrainerflag TRAINER_JPROGAMER 
	cleartrainerflag TRAINER_SLOWBRO
	cleartrainerflag TRAINER_BOTONES
	cleartrainerflag TRAINER_HYPEANTONIO_2
	cleartrainerflag TRAINER_VIN
	cleartrainerflag TRAINER_ESBIRRO_DARKI_1
	cleartrainerflag TRAINER_ESBIRRO_DARKI_2
	cleartrainerflag TRAINER_ESBIRRO_DARKI_3
	cleartrainerflag TRAINER_ESBIRRO_DARKI_4
	cleartrainerflag TRAINER_ESBIRRO_DARKI_5
	cleartrainerflag TRAINER_ANTHONYPXP
	cleartrainerflag TRAINER_DRANIX
	cleartrainerflag TRAINER_UMBREON123
	cleartrainerflag TRAINER_PHENT
	cleartrainerflag TRAINER_ULTRA_MAGIC
	cleartrainerflag TRAINER_CHARZ
	cleartrainerflag TRAINER_GHADDAR_2
	cleartrainerflag TRAINER_KADERETE_2
	cleartrainerflag TRAINER_FURRY
	cleartrainerflag TRAINER_DARK_MELKOR
	cleartrainerflag TRAINER_ANGELFS
	cleartrainerflag TRAINER_MDRAGON
	cleartrainerflag TRAINER_ALBERMAUS
	cleartrainerflag TRAINER_HATHAR
	cleartrainerflag TRAINER_CASTILLO
	cleartrainerflag TRAINER_JOSITO_2
	cleartrainerflag TRAINER_MR_ZERO
	cleartrainerflag TRAINER_ZZZ
	cleartrainerflag TRAINER_FENAN
	cleartrainerflag TRAINER_ADDRI_2
	cleartrainerflag TRAINER_POISONMASTAHHHH
	cleartrainerflag TRAINER_BLUE_AND_YELLOW
	cleartrainerflag TRAINER_DUNK_2
	cleartrainerflag TRAINER_SANTYGRASS_3
	setvar VAR_SHIFTEO_SANTY_GYM, 4
	cleartrainerflag TRAINER_GOOSES
	setflag FLAG_REMATCH_GOOSES
	cleartrainerflag TRAINER_SAPPH
	setflag FLAG_REMATCH_SAPPH
	clearflag FLAG_HIDE_SAPPHGYM_ZIGZA
    cleartrainerflag TRAINER_SAPPH_GYM_1
    cleartrainerflag TRAINER_SAPPH_GYM_2
    cleartrainerflag TRAINER_SAPPH_GYM_3
    cleartrainerflag TRAINER_SAPPH_GYM_4
    setvar VAR_STATE_SAPPH_GYM, 0
	cleartrainerflag TRAINER_DARKI_BUENRO
	cleartrainerflag TRAINER_DARKI_MALRO
	setflag FLAG_REMATCH_DARKIBUENRO
	setflag FLAG_REMATCH_DARKIMALRO
	clearflag FLAG_MIRORB_DEFEATED
	cleartrainerflag TRAINER_MIRORB
	cleartrainerflag TRAINER_KRUB_2
	release
	end
	
MicoloLeagueLobby_EventScript_Tutor_Definitive_List::
	lockall
	faceplayer
	msgbox Tutor_Definite_List_Text, MSGBOX_DEFAULT	
	multichoicegrid 0, 0, MULTI_MOVE_TUTOR_LIST, 2, 0
	switch VAR_RESULT
	case 0, EXPLOSION
	case 1, DOUBLEEDGE
	case 2, DYNAMICPUNCH
	case 3, SUBSTITUTE
	case 4, SLEEPTALK
	case 5, METRONOME
	case 6, MIMIC
	case 7, FURRYCUTTER
	case 8, ROLLOUT
	case 9, SWAGGER
	case 10, MORETUTOR1
	case 11, MORETUTOR2
	case MULTI_B_PRESSED, No_Tutor
	end
	
EXPLOSION::	
	call PacifidlogTown_PokemonCenter_1F_EventScript_ExplosionTutor
	releaseall
	end
	
DOUBLEEDGE::	
	call SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor
	releaseall
	end

DYNAMICPUNCH::	
	call MossdeepCity_EventScript_DynamicPunchTutor
	releaseall
	end
	
SUBSTITUTE::	
	call LilycoveCity_DepartmentStoreRooftop_EventScript_SubstituteTutor
	releaseall
	end
	
SLEEPTALK::	
	call FortreeCity_House2_EventScript_SleepTalkTutor
	releaseall
	end
	
METRONOME::	
	call FallarborTown_Mart_EventScript_MetronomeTutor
	releaseall
	end
	
MIMIC::	
	call LavaridgeTown_House_EventScript_MimicTutor
	releaseall
	end
	
FURRYCUTTER::	
	call VerdanturfTown_PokemonCenter_1F_EventScript_FuryCutterTutor
	releaseall
	end
	
ROLLOUT::	
	call MauvilleCity_EventScript_RolloutTutor
	releaseall
	end
	
SWAGGER::	
	call SlateportCity_PokemonFanClub_EventScript_SwaggerTutor
	releaseall
	end

MORETUTOR1::	
	call BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	releaseall
	end
	
MORETUTOR2::	
	call BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	releaseall
	end
	
No_Tutor::
	releaseall
	end
	
MicoloLeagueLobby_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MicoloLeagueLobby_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MicoloLeagueLobby_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_MASTER_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_ELIXIR
	.2byte ITEM_MAX_ELIXIR
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_SACRED_ASH
	.2byte ITEM_NONE
	release
	end
	
MicoloLeagueLobby_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MicoloLeagueLobby_Pokemart2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MicoloLeagueLobby_Pokemart2:
	.2byte ITEM_WHITE_HERB
	.2byte ITEM_POWER_HERB
	.2byte ITEM_MENTAL_HERB
	.2byte ITEM_FOCUS_SASH
	.2byte ITEM_FOCUS_BAND
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_LUM_BERRY
	.2byte ITEM_LIECHI_BERRY
	.2byte ITEM_GANLON_BERRY
	.2byte ITEM_PETAYA_BERRY
	.2byte ITEM_APICOT_BERRY
	.2byte ITEM_SALAC_BERRY
	.2byte ITEM_PP_UP
	.2byte ITEM_PP_MAX
	.2byte ITEM_NONE
	release
	end

MicoloLeagueLobby_EventScript_ExitOldMan::
	msgbox MicoloLeagueLobby_EventScript_ExitOldMan_Text_0, MSGBOX_NPC
	return

MicoloLeagueLobby_EventScript_ExitOldMan_Text_0:
	.string "Esas escaleras de la izquierda te\n"
	.string "llevarán de vuelta a MICOLANDIA.\p"
	.string "Es una suerte que sean escaleras\n"
	.string "automáticas...$"

MicoloLeagueLobby_EventScript_Dusclops::
    lock
    faceplayer 
    waitse
    playmoncry SPECIES_DUSCLOPS, 0
    msgbox MicoloLeagueLobby_Text_Dusclops, MSGBOX_DEFAULT
    waitmoncry
    release
    end

MicoloLeagueLobby_Text_Dusclops:
    .string "DUSCLOPS: Cloooops...$"
    
MicoloLeagueLobby_EventScript_GuardCheck::
	lockall
	compare VAR_STATE_MICOLANDIA, 3
	goto_if_eq MicoloLeagueLobby_EventScript_GuardCheck_2
	msgbox MicoloLeagueLobby_EventScript_GuardCheck_Text_0, MSGBOX_NPC
	applymovement 8, MicoloLeagueLobby_Movement_Guard1
	applymovement 10, MicoloLeagueLobby_Movement_Guard2
	waitmovement 0
	setvar VAR_STATE_MICOLANDIA, 3
    setobjectxyperm 8, 8, 2
	setobjectxyperm 10, 11, 2
	
MicoloLeagueLobby_EventScript_GuardCheck_1:
	releaseall
	return

MicoloLeagueLobby_EventScript_GuardCheck_2:
	msgbox MicoloLeagueLobby_EventScript_GuardCheck_Text_0, MSGBOX_NPC
	goto MicoloLeagueLobby_EventScript_GuardCheck_1


MicoloLeagueLobby_Movement_Guard1:
	walk_left
    face_down
	step_end

MicoloLeagueLobby_Movement_Guard2:
	walk_right
    face_down
	step_end

MicoloLeagueLobby_EventScript_GuardCheck_Text_0:
    .string "Se acerca el final de tu viaje. Llegó la\n"
	.string "hora de que demuestres que eres el\l"
	.string "mejor entrenador de MICOLANDIA, y para\l"
	.string "ello tendrás que vencer a la ELITE FOUR\l"
	.string "entera de la MICOLIGA y a la persona\l"
	.string "que sostiene el título de CAMPEÓN.\l"
	.string "Ellos son los entrenadores más fuertes\l" 
	.string "que jamás hayas visto.\p"
	.string "Ten en cuenta que una vez que entres,\n"
	.string "no podrás salir hasta completar la\l"
	.string "MICOLIGA... o perder.\p"
	.string "Si estás preparado, entra por esa\n"
	.string "puerta, pero si no eres mas que otro\l"
	.string "cobarde, llora, y vuelve a casa con tu\l"
	.string "mamá.$"

MicoloLeagueLobby_Text_1:
	.string "¡La LIGA POKéMON Oficial de HOENN es\n" 
	.string "para casuals!\p"

	.string "La MICOLIGA es mejor porque ofrece\n" 
	.string "un reto mayor.\p"
	
	.string "Aún no pude vencer a LAVENDER, pero\n"
	.string "algún día lo conseguiré. ¡Ya verás!$"
	
MicoloLeagueLobby_Text_2:
	.string "¿POR QUÉ QUITARON A STEVEN DE CAMPEÓN\n" 
	.string "DE LA LIGA DE HOENN PARA PONER AL TIPO\l" 
	.string "DE LA CAPA VERDE?\p"
	
	.string "¡NO TE LO PERDONARÉ JAMÁS, GF, JAMÁS!$"
	
MicoloLeagueLobby_Text_3:
	.string "¿Quién crees que es el CAMPEÓN?\p"
	
	.string "Es decir, el último oponente al que\n"
	.string "necesitarás vencer para que puedas\l"
	.string "completar la MICOLIGA.\p"
	
	.string "Ya te lo imaginas, ¿verdad?$"
	
MicoloLeagueLobby_Text_4:
	.string "Te esperan cinco enfrentamientos\n"
	.string "consecutivos para poder completar\l" 
	.string "la MICOLIGA.\p"

	.string "Te aconsejo que compres todos los\n"
	.string "objetos curativos que puedas, y que\l"
	.string "refuerces al máximo el potencial de\l"
	.string "tus POKéMON con ayuda de todos los\l"
	.string "objetos que encontraste, y de todas\l"
	.string "las personas que conociste en tu\l"
	.string "aventura.\p"
	
	.string "¡Esta LIGA POKéMON es dura de verdad!\p"

	.string "Aún nadie ha podido superar los cinco\n"
	.string "enfrentamientos seguidos.$"
	
MicoloLeagueLobby_Text_ResetTrainerFlagsMachine:
	.string "¡Hola, soy el RESET.ADOR!\p"
	
	.string "Esta máquina que ves aquí, sirve para\n"
	.string "resetear todos los encuentros con\l"
	.string "entrenadores especiales de MIDELE\l" 
	.string "EMERALD que has tenido a lo largo\l"
	.string "del juego.\p"

	.string "Si quieres volver a luchar contra todos\n"
	.string "los entrenadores especiales, yo puedo\l"
	.string "hacer ese deseo realidad.\p"
	
	.string "Ten en cuenta, que no todos los\n"
	.string "entrenadores especiales son\l"
	.string "reseteables, y que no podrás elegir\l"
	.string "cuales quieres resetear.\p"
	
	.string "¡Van todos en el pack!$"

MicoloLeagueLobby_Text_ResetTrainerFlagsMachinePregunta:
	.string "¿Quieres usar la máquina para resetear\n"
	.string "los encuentros de los entrenadores\l"
	.string "especiales de MIDELE EMERALD?$"
	
MicoloLeagueLobby_Text_ResetTrainerFlagsMachineNO:
	.string "Así que no quieres...$"
	
MicoloLeagueLobby_Text_ResetTrainerFlagsComplete:
	.string "Los entrenadores especiales MIDELE se\n"
	.string "han reseteado de forma satisfactoria.$"
	
Tutor_Definite_List_Text:
	.string "Entrenador, seguro que durante tu\n"
	.string "aventura te has encontrado con gente\l"
	.string "la cual quiso enseñarte movimientos de\l"
	.string "lo más raros... ¿recuerdas a todos y\l"
	.string "cada uno de ellos?\p"
	.string "¿No? ¡Pues qué más da! Yo te ayudaré a\n"
	.string "recordar...\p"
	.string "¡la lista de movimientos de tutor\n"
	.string "definitiva!$"

MicoloLeagueLobby_Text_5:
	.string "“LAVENDER es un BBCITO.\n"
	.string "Firmado: SAPPHIRE”$"

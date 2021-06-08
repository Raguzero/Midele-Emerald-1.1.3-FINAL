Micolandia_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Micolandia_OnTransition
	.byte 0

Micolandia_OnTransition:
	setflag FLAG_VISITED_MICOLANDIA
	compare VAR_STATE_MICOLANDIA, 0
	call_if_eq Micolandia_EventScript_SetGuardBlockingDoor
	compare VAR_STATE_MICOLANDIA, 1
	call_if_eq Micolandia_EventScript_SetGuardUnblockingDoor
	end
	
Micolandia_EventScript_SetGuardBlockingDoor::
	setobjectxyperm 5, 41, 6
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_DOWN
	return

Micolandia_EventScript_SetGuardUnblockingDoor::
	setobjectxyperm 5, 40, 7
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_DOWN
	return
	
Micolandia_EventScript_Marihuana::
	msgbox Micolandia_Text_Marihuana, MSGBOX_NPC
	end
	
Micolandia_EventScript_BienvenidaSign::
	msgbox Micolandia_Text_BienvenidaSign, MSGBOX_SIGN
	end
	
Micolandia_EventScript_LigaSign::
	msgbox Micolandia_Text_LigaSign, MSGBOX_SIGN
	end
	
Micolandia_EventScript_GymNoroesteSign::
	msgbox Micolandia_GymNoroesteSign, MSGBOX_SIGN
	end

Micolandia_EventScript_GymNoresteSign::
	msgbox Micolandia_GymNoresteSign, MSGBOX_SIGN
	end

Micolandia_EventScript_GymSuroesteSign::
	msgbox Micolandia_GymSuroesteSign, MSGBOX_SIGN
	end

Micolandia_EventScript_GymSuresteSign::
	msgbox Micolandia_GymSuresteSign, MSGBOX_SIGN
	end
	
Micolandia_EventScript_CibercafeSign::
	msgbox Micolandia_CibercafeSign, MSGBOX_SIGN
	end
	
Micolandia_EventScript_ForestSign::
	msgbox Micolandia_Text_ForestSign, MSGBOX_SIGN
	end
	
Micolandia_EventScript_GymSantySign::
	lock
	faceplayer
	msgbox Micolandia_Text_GymSantySign, MSGBOX_NPC
	release
	end
	
Micolandia_EventScript_GymDarkiSign::
	lock
	faceplayer
	msgbox Micolandia_Text_GymDarkiSign, MSGBOX_NPC
	release
	end

Micolandia_EventScript_GymSapphSign::
	lock
	faceplayer
	msgbox Micolandia_Text_GymSapphSign, MSGBOX_NPC
	release
	end

Micolandia_EventScript_GymGoosesSign::
	lock
	faceplayer
	msgbox Micolandia_Text_GymGoosesSign, MSGBOX_NPC
	release
	end
	
Micolandia_Kirlia_Script::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KIRLIA, 0
	waitmoncry
	release
	end
	
Micolandia_Dueno_de_Kirlia_Script::
	lock
	faceplayer
	msgbox Micolandia_Dueno_de_Kirlia_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Micolandia_Dueno_de_Kirlia_Teleport
	release
	end
Micolandia_Dueno_de_Kirlia_Teleport::
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Micolandia_EventScript_PlayersHouseMale
	compare VAR_RESULT, FEMALE
	call_if_eq Micolandia_EventScript_BirchsHouseFemale
	release
	end

Micolandia_EventScript_PlayersHouseMale::
	warp MAP_LITTLEROOT_TOWN, 1, 0, 0
	waitstate
	end

Micolandia_EventScript_BirchsHouseFemale::
	warp MAP_LITTLEROOT_TOWN, 0, 0, 0
	waitstate
	end
	
Micolandia_EventScript_TopoVigilante::
	lock
	faceplayer
	compare VAR_STATE_MICOLANDIA, 1
	call_if_eq Micolandia_EventScript_TopoVigilante2
	goto_if_set FLAG_DEFEATED_GOOSES_GYM, Micolandia_EventScript_TopoCombate
	msgbox Micolandia_Text_TopoVigilante, MSGBOX_DEFAULT
	release
	end
	
Micolandia_EventScript_TopoCombate::
	lock
	faceplayer
	msgbox Micolandia_Text_TopoVigilante2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TOPO, Micolandia_Text_TopoDerrota
	msgbox Micolandia_Text_TopoPostCombate, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Micolandia_Movement_Player
	waitmovement 0
	setvar VAR_STATE_MICOLANDIA, 1
	applymovement 5, Micolandia_Topo_Movement
	waitmovement 0
	releaseall
	end
	
Micolandia_EventScript_TopoVigilante2::
	lock
	faceplayer
	msgbox Micolandia_Text_TopoVigilante3, MSGBOX_DEFAULT
	release
	end
	
Micolandia_Movement_Player:
	walk_down
	walk_in_place_fastest_up
	step_end
	
Micolandia_Topo_Movement:
	walk_down
	walk_left
	walk_in_place_fastest_down
	step_end
	
Micolandia_Text_TopoVigilante:
	.string "Hola, soy TOPO, el vigilante\n"
	.string "de seguridad.\p"
	
	.string "Este edificio que ves delante tiene\n"
	.string "muchas instalaciones. El Micocasino,\l"
	.string "los laboratorios y, por supuesto, la\l"
	.string "impresionante Micoliga.\p"
	
	.string "Pero este lugar es exclusivo.\p"
	
	.string "Solo te puedo dejar pasar si has\n"
	.string "conseguido la Medalla de los 4 lideres\l"
	.string "de gym de MICOLANDIA.$"
	
Micolandia_Text_TopoVigilante2:
	.string "Hola, soy TOPO, el vigilante\n"
	.string "de seguridad.\p"
	
	.string "Este edificio que ves delante tiene\n"
	.string "muchas instalaciones. El Micocasino,\l"
	.string "los laboratorios y, por supuesto, la\l" 
	.string "impresionante Micoliga.\p"
	
	.string "Ya me he enterado que has vencido a los\n"
	.string "lideres gym de MICOLANDIA.\p"
	
	.string "Te has ganado el derecho a dejarte pasar\n"
	.string "por esta puerta.\p"

	.string "Pero antes...\p"
	
	.string "(Se pone las gafas de sol)\p"
	
	.string "¡Demuéstrame lo que vales!$"
	
Micolandia_Text_TopoDerrota:
	.string "¿Es que no soy lo suficientemente\n"
	.string "intimidante?$"
	
Micolandia_Text_TopoVigilante3:
	.string "Hola, soy TOPO, el vigilante\n"
	.string "de seguridad.\p"
	
	.string "No tendrás miedo a entrar por\n"
	.string "esa puerta ¿no?$"
	
Micolandia_Text_TopoPostCombate:
	.string "Me has convencido.\n"
	.string "¡Adelante!$"

Micolandia_Text_Marihuana:
	.string "¿Ves esas plantas de ahí?\p"
	.string "Cualquiera diría que hay\n" 
	.string "Pokémon salvajes.\p"

	.string "Pero si fumas de eso serás tú quien\n"
	.string	"acabará bien salvaje. ¡jeje!$"

Micolandia_Text_BienvenidaSign:
	.string "¡Bienvenido a MICOLANDIA!\n"
	.string "Si estás aquí es que fuiste elegido\p"
	.string "para afrontar el desafio de la\n"
	.string "Liga Pokemon Midelar.\p"
	
	.string "¡Deberás superar la prueba\n"
	.string "de los cuatro lideres de Gymnasio\p"
	.string "para participar en la nueva y\n"
	.string "extraordinario Liga Pokemon Midelar!$"
	
Micolandia_Text_LigaSign:
	.string "LIGA POKÉMON MIDELAR$"
	
Micolandia_GymNoroesteSign:
	.string "POKEMON GYM Nº1\n"
	.string "LEADER: SANTYGRASS\l"
	.string "“TEMÁTICA: HIERBA QUEMADA”$"

Micolandia_GymNoresteSign:
	.string "POKEMON GYM Nº2\n"
	.string "LEADER: DARKI\l"
	.string "“TEMÁTICA: BUENROLLO y MALROLLO”$"

Micolandia_GymSuroesteSign:
	.string "POKEMON GYM Nº3\n"
	.string "LEADER: SAPPH\l"
	.string "“TEMÁTICA: ????”$"

Micolandia_GymSuresteSign:
	.string "POKEMON GYM Nº4\n"
	.string "LEADER: GOOSES\l"
	.string "“TEMÁTICA: INVIERNO”$"
	
Micolandia_CibercafeSign:
	.string "CIBERCAFE BATALLA$"
	
Micolandia_Text_ForestSign:
	.string "Entrada a Forbidden Forest.\p"

	.string "Entra bajo tu propio riesgo.$"
	
Micolandia_Text_GymSantySign:
	.string "Estamos haciendo preparativos.\n"
	.string "¡Lo sentimos!\p"
	
	.string "¿Por qué no visitas el bosque\n"
	.string "mientras tanto? Te servirá\l"
	.string "para entrenar.\p"
	
	.string "Pero cuidado, ¡hay entrenadores\n"
	.string "¡bastante fuertes!$"
	
Micolandia_Text_GymDarkiSign:
	.string "Solo está permitido el paso\n"
	.string "a quienes hayan derrotado al\l"
	.string "LIDER SANTY.$"
	
Micolandia_Text_GymSapphSign:
	.string "Solo está permitido el paso\n"
	.string "a quienes hayan derrotado al\l"
	.string "LIDER DARKI.$"
	
Micolandia_Text_GymGoosesSign:
	.string "Solo está permitido el paso\n"
	.string "a quienes hayan derrotado a la\l"
	.string "LIDER SAPPH.$"

Micolandia_Dueno_de_Kirlia_Text:
	.string "La única forma de salir de aquí\n"
	.string "es volando.\p"

	.string "Pero mi KIRLIA puede usar la\n"
	.string "técnica del TELEPORT para enviarte\l"
	.string "a tu casa. ¡Es gratis!\p"
	
	.string "¿Quieres que te lleve a tu casa?$"

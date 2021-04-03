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
	msgbox ForbiddenForest_Text_Celebi, MSGBOX_SIGN
	specialvar VAR_RESULT, CheckJirachiMewinTeam
	compare VAR_RESULT, TRUE
	goto_if_eq ForbiddenForest_EventScript_Celebi_Sign2
	end

ForbiddenForest_EventScript_Celebi_Sign2::
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
	
ForbiddenForest_EventScript_Felipex88::
	trainerbattle_double TRAINER_FELIPEX88, Felipex88_AntesBatalla, Felipex88_MensajeDerrota, Felipex88_Text_MasdeunPokemon
	msgbox Felipex88_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_EventScript_Tenshinhan::
	trainerbattle_single TRAINER_TENSHINHAN, Tenshinhan_AntesBatalla, Tenshinhan_MensajeDerrota
	msgbox Tenshinhan_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
ForbiddenForest_Text_Celebi:
	.string "El cartel se ha deteriorado\n"
	.string "por el paso del tiempo y solo\l"
	.string "se puede leer lo siguiente:\p"
	
	.string "El ca..no sol. s. .br.r.\n"
	.string "c.n l.s mi.tic.s M.W y\p"
	.string "JI...HI\n$"
	
ForbiddenForest_Text_Celebi2:
	.string "El camino se ha abierto.$"

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
	
Felipex88_AntesBatalla: 
	.string "Hola, soy Felipex88, y me gusta hacer\n"
	.string "cachitos mi lengua.\p"

	.string "Los mexicanos en si son feos, chicos\n"
	.string "y negros, más aún los k juegan pokemon,\l" 
	.string "no salva ninguno pu viejo, e visto fotos\l" 
	.string "y son todos unos troles, llegan a dar\l" 
	.string "miedo y pena, para lo único k sirven es\l" 
	.string "para sentarse a jugar mierdas\l"
	.string "como estas.\p"
	
	.string "Los de este foro tampoco se salvan,\n" 
	.string "dan pena ver que siempre están\l"
	.string "introducidos en el mundo virtual\l"
	.string "desperdiciando sus jóvenes vidas.\p"
	
	.string "Empezando por las mujeres y terminando\n" 
	.string "por el mas feo del foro del k hay k\l" 
	.string "estar eligiendo con pinzas cual es el\l"
	.string "mas ogro, da pena meterse al foro a\l" 
	.string "preguntar algo y que te respondan los\l" 
	.string "mismos sin vida de siempre, de verdad\l" 
	.string "es penosa la situación y el idiota k\l"
	.string "cree sentirse de acero jugando a un\l" 
	.string "juego random donde el 70% es pura\l" 
	.string "suerte entre criticals, fallidas, y\l" 
	.string "evasiones y solo el 30 de forma\l"
	.string "normal, esta mas que perdido.$"

Felipex88_MensajeDerrota: 
	.string "¡Hora de cortarse la lengua!\n"
	.string ":video: :video:\l"
	.string "ghhghfghgghghghggh$"
 
Felipex88_DespuesDeBatalla:
	.string "Comog podeig gegui guando a gesta wea.\p"

	.string "Soig gunos fragasagos, salig a gugar\n" 
	.string "a gosas mas agultas con viogentas\l"
	.string "y sangggre... muga sangggreee ghghghgh\p"
	
	.string "¡GHAMA A GUNA GAMBUGANCIA!$"
	
Felipex88_Text_MasdeunPokemon: // BATALLA DOBLE
	.string "¿Así que solo llevas un Pokémon?\p"
	.string "Prefiero cortarme la lengua que usar\n"
	.string "mi equipo en BATALLA INDIVIDUAL.$"
	
Tenshinhan_AntesBatalla: 
	.string "FRASES.$"

Tenshinhan_MensajeDerrota: 
	.string "FRASES$"
 
Tenshinhan_DespuesDeBatalla:
	.string "FRASES\n"
	.string "FRASES.$"


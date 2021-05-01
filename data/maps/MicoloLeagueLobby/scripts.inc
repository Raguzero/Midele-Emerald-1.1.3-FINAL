MicoloLeagueLobby_MapScripts:: @ 82295D2
	map_script MAP_SCRIPT_ON_TRANSITION, MicoloLeagueLobby_PokemonCenter_OnTransition

	.byte 0
	
MicoloLeagueLobby_PokemonCenter_OnTransition:
	setrespawn HEAL_LOCATION_MICOLANDIA // CAMBIARLO LUEGO
	call Common_EventScript_UpdateBrineyLocation
	end

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
	//cleartrainerflag TRAINER_UTALAWEA
	//cleartrainerflag TRAINER_UTALAWEA
	//cleartrainerflag TRAINER_UTALAWEA
	//cleartrainerflag TRAINER_UTALAWEA
	// Etc
	release
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
MicoloLeagueLobby_Pokemart: // YA SE CAMBIARAN LOS OBJETOS
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
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
MicoloLeagueLobby_Pokemart2: // YA SE CAMBIARAN LOS OBJETOS
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_PROTEIN
	.2byte ITEM_CALCIUM
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CARBOS
	.2byte ITEM_HP_UP
	.2byte ITEM_SALAC_BERRY
	.2byte ITEM_GANLON_BERRY
	.2byte ITEM_PETAYA_BERRY
	.2byte ITEM_APICOT_BERRY
	.2byte ITEM_LIECHI_BERRY
	.2byte ITEM_NONE
	release
	end

MicoloLeagueLobby_Text_1:
	.string "¡La Liga Pokémon Oficial de HOENN es\n" 
	.string "para casuals!\p"

	.string "La MICOLIGA es mejor porque ofrece\n" 
	.string "un reto mayor.\p"
	
	.string "Aún no pude vencer a LAVENDER, pero\n"
	.string "algún día lo conseguiré.$"
	
MicoloLeagueLobby_Text_2:
	.string "¿POR QUÉ QUITARON A STEVEN DE CAMPEÓN\n" 
	.string "DE LA LIGA DE HOENN PARA PONER AL TIPO\l" 
	.string "DE LA CAPA VERDE?\p"
	
	.string "¡NO TE LO PERDONARÉ JAMÁS, GF, JAMÁS!$"
	
MicoloLeagueLobby_Text_3:
	.string "¿Quién crees que es el CAMPEÓN?\p"
	
	.string "Es decir, el último oponente al que\n"
	.string "necesitarás vencer para que puedas\l"
	.string "coronarte como el nuevo Campeón de\l"
	.string "de la MICOLIGA.\p"
	
	.string "Ya te lo imaginas, ¿verdad?$"
	
MicoloLeagueLobby_Text_4:
	.string "Te esperan cinco enfrentamientos\n"
	.string "consecutivos para erigirte como\l" 
	.string "nuevo Campeón de la MICOLIGA.\p"

	.string "Te aconsejo que compres todos los\n"
	.string "objetos curativos que puedas, y que\l"
	.string "refuerces al máximo el potencial de\l"
	.string "tus Pokémon con ayuda de todos los\l"
	.string "objetos que encontraste, y de todas\l"
	.string "las personas que conociste en tu\l"
	.string "aventura.\p"
	
	.string "¡Esta Liga Pokémon es dura de verdad!\p"

	.string "Aún nadie ha podido vencer a los\n"
	.string "cinco entrenadores del ALTO MANDO.$"
	
MicoloLeagueLobby_Text_ResetTrainerFlagsMachine:
	.string "¡Hola, soy el ReseT.Ador!\p"
	
	.string "Esta máquina que ves aquí, sirve para\n"
	.string "resetear todos los encuentros con\l"
	.string "entrenadores especiales de MIDELE\l" 
	.string "que has tenido a lo largo del juego.\p"

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
	.string "especiales de MIDELE?$"
	
MicoloLeagueLobby_Text_ResetTrainerFlagsMachineNO:
	.string "Así que no quieres...$"
	
MicoloLeagueLobby_Text_ResetTrainerFlagsComplete:
	.string "Los entrenadores especiales MIDELE se\n"
	.string "han reseteado de forma satisfactoria.$"

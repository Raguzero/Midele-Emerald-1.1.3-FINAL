Micolandia_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Micolandia_OnTransition
	.byte 0

Micolandia_OnTransition: @ 81DC2D7
	//setflag FLAG_VISITED_PETALBURG_CITY
	end
	
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
	
Micolandia_Text_Marihuana:
	.string "¿Ves esas plantas de ahí?\p"
	.string "Cualquiera diría que hay\n" 
	.string "Pokémon salvajes.\p"

	.string "Pero si fumas de eso serás tú quien\n"
	.string	"acabará bien salvaje jeje$"

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
	.string "Liga Pokemon Midelar$"
	
Micolandia_GymNoroesteSign: @ 81DCAAA
	.string "POKEMON GYM Nº1\n"
	.string "LEADER: ????1\l"
	.string "“Mensaje descriptivo del lider”$"

Micolandia_GymNoresteSign: @ 81DCAAA
	.string "POKEMON GYM Nº2\n"
	.string "LEADER: ????1\l"
	.string "“Mensaje descriptivo del lider”$"

Micolandia_GymSuroesteSign: @ 81DCAAA
	.string "POKEMON GYM Nº3\n"
	.string "LEADER: ????1\l"
	.string "“Mensaje descriptivo del lider”$"

Micolandia_GymSuresteSign: @ 81DCAAA
	.string "POKEMON GYM Nº4\n"
	.string "LEADER: ????1\l"
	.string "“Mensaje descriptivo del lider”$"


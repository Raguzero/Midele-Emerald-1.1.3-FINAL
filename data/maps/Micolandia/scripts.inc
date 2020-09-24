Micolandia_MapScripts::
	.byte 0
	
Micolandia_EventScript_Marihuana::
	msgbox Micolandia_Text_Marihuana, MSGBOX_NPC
	end
	
Micolandia_EventScript_BienvenidaSign::
	msgbox Micolandia_Text_BienvenidaSign, MSGBOX_SIGN
	end
	
Micolandia_EventScript_LigaSign::
	msgbox Micolandia_Text_LigaSign, MSGBOX_SIGN
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

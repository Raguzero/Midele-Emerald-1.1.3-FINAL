IzabeIsland_Town_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, IzabeIsland_Town_OnTransition
	.byte 0
	
IzabeIsland_Town_OnTransition:
	setflag FLAG_VISITED_IZABE_ISLAND_TOWN
	end
	
IzabeIsland_Town_Trigger_SecretHouse::
	warp MAP_IZABE_ISLAND_SECRET_HOUSE, 255, 4, 1
	waitstate
	end

IzabeIsland_Town_EventScript_Expert::
	msgbox IzabeIsland_Town_Text_Expert, MSGBOX_NPC
	end
	
IzabeIsland_Town_EventScript_GameboyKid::
	msgbox IzabeIsland_Town_Text_GameboyKid, MSGBOX_NPC
	end

IzabeIsland_Town_EventScript_Maid::
	msgbox IzabeIsland_Town_Text_Maid, MSGBOX_NPC
	end

IzabeIsland_Town_EventScript_Cameraman::
	msgbox IzabeIsland_Town_Text_Cameraman, MSGBOX_NPC
	end
	
IzabeIsland_Town_EventScript_SignTown::
	msgbox IzabeIsland_Town_Text_SignTown, MSGBOX_NPC
	end
	
IzabeIsland_Town_EventScript_ItemSunStone::
	finditem ITEM_SUN_STONE
	end

IzabeIsland_Town_EventScript_ItemDragonFang::
	finditem ITEM_DRAGON_FANG
	end

IzabeIsland_Town_Text_Expert::
	.string "¿Ves estas estatuas? Verás varias a lo\n"
	.string "largo de toda la isla. Dicen que estaban\l"
	.string "aquí incluso antes de que se edificase\l"
	.string "la ciudad.$"

IzabeIsland_Town_Text_GameboyKid::
	.string "Qué aburrido...\p"
	.string "¿Eh? ¿Que a qué estoy jugando?\n"
	.string "¡A POKéMON EDICIÓN ESPADA y ESCUDO¡\p"
	.string "Tal vez debería dejarlo e irme a jugar\n"
	.string "a las afueras del pueblo...\p"
	.string "¿Eh? ¿Que qué opino de MASUDA?\p"
	.string "Diría que es un tipo NORMAL, aunque, a\n"
	.string "veces... ¡es un poco FANTASMA!$"

IzabeIsland_Town_Text_Maid::
	.string "Esto de aquí es la casa del ALCALDE.\n"
	.string "La gente del pueblo se suele reunir\l"
	.string "aquí para socializar.\p"
	.string "Dentro también encontrarás la salida\n"
	.string "a las afueras del pueblo.$"

IzabeIsland_Town_Text_Cameraman::
	.string "Estoy grabando un documental sobre este\n"
	.string "lago. Dicen que en él se pueden avistar\l"
	.string "LAPRAS.\p"
	.string "¿Que cómo pueden vivir LAPRAS en un lago\n"
	.string "tan pequeño?\p"
	.string "Pues... este lago es más profundo de lo\n"
	.string "que parece, probablemente los LAPRAS\l"
	.string "vivan en sus profundidades.$"
	
IzabeIsland_Town_Text_SignTown::
	.string "IZABE TOWN\n"
	.string "“Precioso lugar rodeado de mar y de\l"
	.string "enormes montañas que dan culto a\l"
	.string "una leyenda.”$"

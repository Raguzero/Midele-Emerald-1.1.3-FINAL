IzabeIsland_Lobby_MapScripts::
	.byte 0

IzabeIsland_Lobby_EventScript_Receptionist::
	msgbox IzabeIsland_Lobby_Text_Receptionist, MSGBOX_NPC
	end
	
IzabeIsland_Lobby_EventScript_OldMan::
	msgbox IzabeIsland_Lobby_Text_OldMan, MSGBOX_NPC
	end
	
IzabeIsland_Lobby_Text_Receptionist::
	.string "ISLA IZABE se enorgullece de estar a la\n"
	.string "última en investigación marina y naval.\p"
	.string "Trabajamos junto a los ASTILLEROS y el\n"
	.string "MUSEO OCEÁNICO de CIUDAD PORTUAL.$"

IzabeIsland_Lobby_Text_OldMan::
	.string "Uf... el camino a la ciudad es más largo\n"
	.string "de lo que parece. Creo que me tomaré un\p"
	.string "descanso.$"

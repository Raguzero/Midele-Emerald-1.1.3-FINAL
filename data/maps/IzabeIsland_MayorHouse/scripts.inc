IzabeIsland_MayorHouse_MapScripts::
	.byte 0

IzabeIsland_MayorHouse_EventScript_OldWoman::
	msgbox IzabeIsland_MayorHouse_Text_OldWoman, MSGBOX_NPC
	end

IzabeIsland_MayorHouse_EventScript_GameBoyKid::
	msgbox IzabeIsland_MayorHouse_Text_GameBoyKid, MSGBOX_NPC
	end

IzabeIsland_MayorHouse_EventScript_FatMan1::
	msgbox IzabeIsland_MayorHouse_Text_FatMan1, MSGBOX_NPC
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	end

IzabeIsland_MayorHouse_EventScript_FatMan2::
	msgbox IzabeIsland_MayorHouse_Text_FatMan2, MSGBOX_NPC
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	end

IzabeIsland_MayorHouse_EventScript_FatMan3::
	msgbox IzabeIsland_MayorHouse_Text_FatMan3, MSGBOX_NPC
	applymovement 3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	end

IzabeIsland_MayorHouse_Text_OldWoman::
	.string "Ay... este nieto mío siempre está con la\n"
	.string "maquinita. Vale que en esta isla no hay\l"
	.string "mucho que hacer, pero...\p"
	.string "En fin, la juventud...$"

IzabeIsland_MayorHouse_Text_GameBoyKid::
	.string "Jugar en las afueras del pueblo es muy\n"
	.string "aburrido, está lleno de entrenadores...\p"
	.string "Prefiero quedarme aquí jugando a mis\n"
	.string "videojuegos favoritos.$"

IzabeIsland_MayorHouse_Text_FatMan1::
	.string "¿Qué? No molestes, estamos jugando a\n"
	.string "WAIFUS & DRAGONS, 12ª edición.$"

IzabeIsland_MayorHouse_Text_FatMan2::
	.string "¿Qué? ¿Un 1 otra vez? Este dado está\n"
	.string "trucado, maldita sea...$"

IzabeIsland_MayorHouse_Text_FatMan3::
	.string "Zzz...\p"
	.string "Parece que se ha quedado dormido...$"

GymGooses_MapScripts::
	.byte 0
	
GymGooses_CasillaTableroDado::
	msgbox GymGoosesTirarDado_Text, MSGBOX_DEFAULT	
	goto Script_RandomDados
	end

Script_RandomDados::
	lock
	faceplayer
	random 6
	switch VAR_RESULT
	case 0, Script_Dado1
	case 1, Script_Dado2
	case 2, Script_Dado3
	case 3, Script_Dado4
	case 4, Script_Dado5
	case 5, Script_Dado6
	end

Script_Dado1::
	msgbox GymGoosesDado1_Text, MSGBOX_DEFAULT
	applymovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado1
	waitmovement 0
	closemessage
	release
	end

Script_Dado2::
	msgbox GymGoosesDado2_Text, MSGBOX_DEFAULT
	applymovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado2
	waitmovement 0	
	closemessage
	release
	end

Script_Dado3::
	msgbox GymGoosesDado3_Text, MSGBOX_DEFAULT
	applymovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado3
	waitmovement 0	
	closemessage
	release
	end
	
Script_Dado4::
	msgbox GymGoosesDado4_Text, MSGBOX_DEFAULT
	applymovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado4
	waitmovement 0	
	closemessage
	release
	end

Script_Dado5::
	msgbox GymGoosesDado5_Text, MSGBOX_DEFAULT
	applymovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado5
	waitmovement 0	
	closemessage
	release
	end

Script_Dado6::
	msgbox GymGoosesDado6_Text, MSGBOX_DEFAULT
	applymovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado6
	waitmovement 0	
	closemessage
	release
	end

//Dado primera casilla
GymGoosesDado1_Movement_PlayerDado1:
	walk_left
	step_end
GymGoosesDado1_Movement_PlayerDado2:
	walk_left
	walk_left
	step_end
GymGoosesDado1_Movement_PlayerDado3:
	walk_left
	walk_left
	walk_left
	step_end
GymGoosesDado1_Movement_PlayerDado4:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end
GymGoosesDado1_Movement_PlayerDado5:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end
GymGoosesDado1_Movement_PlayerDado6:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

GymGoosesTirarDado_Text:
	.string "¡Tira el dado!$"
	
GymGoosesDado1_Text:
	.string "¡Has sacado un 1, te moverás 1 casilla.$"
	
GymGoosesDado2_Text:
	.string "¡Has sacado un 2, te moverás 2 casillas.$"

GymGoosesDado3_Text:
	.string "¡Has sacado un 3, te moverás 3 casillas.$"
	
GymGoosesDado4_Text:
	.string "¡Has sacado un 4, te moverás 4 casillas.$"
	
GymGoosesDado5_Text:
	.string "¡Has sacado un 5, te moverás 5 casillas.$"
	
GymGoosesDado6_Text:
	.string "¡Has sacado un 6, te moverás 6 casillas.$"


GymGooses_MapScripts::
	.byte 0
	
GymGooses_CasillaTableroDado::
	msgbox GymGoosesTirarDado_Text, MSGBOX_DEFAULT
	waitmessage
	lock
	faceplayer
	applydicemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado1
	special BufferSpecialVarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmovement 0
	closemessage
	release
	end
	

//Dado primera casilla
GymGoosesDado1_Movement_PlayerDado1:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

GymGoosesTirarDado_Text:
	.string "¡Tira el dado!$"

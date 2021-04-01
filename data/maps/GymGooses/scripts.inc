GymGooses_MapScripts::
	.byte 0
	
GymGooses_CasillaTableroDado::
	msgbox GymGoosesTirarDado_Text, MSGBOX_DEFAULT
	waitmessage
	lock
	faceplayer
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado1
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end

GymGooses_CasillaTableroDado2::
	msgbox GymGoosesTirarDado_Text, MSGBOX_DEFAULT
	waitmessage
	lock
	faceplayer
	random 6
	addvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	special Buffer0x8004VarToStringVar1
	msgbox gText_DiceResult, MSGBOX_DEFAULT
	waitmessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado2
	waitmovement 0
	special DoApplyrangemovementLastStep
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

//Dado segunda casilla
GymGoosesDado1_Movement_PlayerDado2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

GymGoosesTirarDado_Text:
	.string "¡Tira el dado!$"

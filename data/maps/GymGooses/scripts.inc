GymGooses_MapScripts::
	.byte 0

// Primera Sala	
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
	
GymGooses_CasillaTableroDado3::
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
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado3
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
GymGooses_CasillaTableroDado4::
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
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado4
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end
	
GymGooses_CasillaTableroDado5::
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
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesDado1_Movement_PlayerDado5
	waitmovement 0
	special DoApplyrangemovementLastStep
	release
	end

GymGooses_CasillaTableroCombate::
	msgbox GymGoosesCombate_Text, MSGBOX_DEFAULT
	lock
	faceplayer
	setflag FLAG_RYU_RANDOMBATTLE
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq CasillaTableroLoss
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq CasillaTableroWin
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq CasillaTableroLoss
CasillaTableroWin::
	clearflag FLAG_RYU_RANDOMBATTLE
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, GymGoosesMoverIzq
	waitmovement 0
	release
	end
CasillaTableroLoss::
	special HealPlayerParty
	clearflag FLAG_RYU_RANDOMBATTLE
	closemessage
	warp MAP_GYM_GOOSES, 0, 0, 0
	release
	end

GymGooses_CasillaTableroCombate2::
	msgbox GymGoosesCombate_Text, MSGBOX_DEFAULT
	lock
	faceplayer
	setflag FLAG_RYU_RANDOMBATTLE
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq CasillaTableroLoss2
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq CasillaTableroWin2
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq CasillaTableroLoss2
CasillaTableroWin2::
	clearflag FLAG_RYU_RANDOMBATTLE
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, GymGoosesMoverDer
	waitmovement 0
	release
	end
CasillaTableroLoss2::
	special HealPlayerParty
	clearflag FLAG_RYU_RANDOMBATTLE
	closemessage
	warp MAP_GYM_GOOSES, 0, 0, 0
	release
	end
	
GymGooses_CasillaTableroCombate3::
	msgbox GymGoosesCombate_Text, MSGBOX_DEFAULT
	lock
	faceplayer
	setflag FLAG_RYU_RANDOMBATTLE
	setvar VAR_0x8004, SPECIAL_RANDOM_BATTLE
    setvar VAR_0x8005, 0
    special DoSpecialTrainerBattle
    waitstate
    compare VAR_RESULT, B_OUTCOME_DREW
    call_if_eq CasillaTableroLoss3
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq CasillaTableroWin3
    compare VAR_RESULT, B_OUTCOME_LOST
    call_if_eq CasillaTableroLoss3
CasillaTableroWin3::
	clearflag FLAG_RYU_RANDOMBATTLE
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, GymGoosesMoverDown
	waitmovement 0
	release
	end
CasillaTableroLoss3::
	special HealPlayerParty
	clearflag FLAG_RYU_RANDOMBATTLE
	closemessage
	warp MAP_GYM_GOOSES, 0, 0, 0
	release
	end
	
GymGooses_CasillaTableroStatus::
	msgbox GymGoosesStatus_Text, MSGBOX_DEFAULT
	lock
	faceplayer
	pike_getstatus
	compare VAR_RESULT, PIKE_STATUS_TOXIC
	call_if_eq GymGoosesStatus_Poison_Script
	compare VAR_RESULT, PIKE_STATUS_BURN
	call_if_eq GymGoosesStatus_Burn_Script
	compare VAR_RESULT, PIKE_STATUS_PARALYSIS
	call_if_eq GymGoosesStatus_Prz_Script
	compare VAR_RESULT, PIKE_STATUS_SLEEP
	call_if_eq GymGoosesStatus_Slp_Script
	compare VAR_RESULT, PIKE_STATUS_FREEZE
	call_if_eq GymGoosesStatus_Freeze_Script
	end

GymGooses_CasillaTableroPregunta::
	msgbox GymGoosesPregunta_Text, MSGBOX_DEFAULT
	lock
	faceplayer
//CasillaTableroCorrecta::
	closemessage
	applyrangemovement EVENT_OBJ_ID_PLAYER, GymGoosesMoverIzq
	waitmovement 0
	release
	end
//CasillaTableroIncorrecta::
//	closemessage
//	warp MAP_GYM_GOOSES, 0, 0, 0
//	release
//	end

// Mover 1 paso en casillas no-dado
GymGoosesMoverIzq:
	walk_left
	step_end
	
GymGoosesMoverDer:
	walk_right
	step_end
	
GymGoosesMoverUp:
	walk_up
	step_end
	
GymGoosesMoverDown:
	walk_down
	step_end

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
	
//Dado tercera casilla
GymGoosesDado1_Movement_PlayerDado3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end
	
//Dado cuarta casilla
GymGoosesDado1_Movement_PlayerDado4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

//Dado quinta casilla	
GymGoosesDado1_Movement_PlayerDado5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
GymGoosesStatus_Poison_Script::
	pike_flashscreen
	message GymGoosesStatus_Poison
	waitmessage
	end
	
GymGoosesStatus_Slp_Script::
	pike_flashscreen
	message GymGoosesStatus_Slp
	waitmessage
	end
	
GymGoosesStatus_Prz_Script::
	pike_flashscreen
	message GymGoosesStatus_Prz
	waitmessage
	end
	
GymGoosesStatus_Burn_Script::
	pike_flashscreen
	message GymGoosesStatus_Burn
	waitmessage
	end
	
GymGoosesStatus_Freeze_Script::
	pike_flashscreen
	message GymGoosesStatus_Freeze
	waitmessage
	end
	
// Segunda Sala

GymGoosesTirarDado_Text:
	.string "Casilla Dado: ¡Tira el dado!$"
	
GymGoosesCombate_Text:
	.string "Casilla Pokeball: ¡A combatir!$"
	
GymGoosesStatus_Text:
	.string "Casilla Status: ¡Tus pokémon\n"
	.string "sufrirán un estado alterado!$"
	
GymGoosesStatus_Poison:
	.string "¡INTOXICATE!$"
	
GymGoosesStatus_Slp:
	.string "¡DUERME!$"
	
GymGoosesStatus_Prz:
	.string "¡PARALIZATE!$"
	
GymGoosesStatus_Burn:
	.string "¡QUÉMATE!$"
	
GymGoosesStatus_Freeze:
	.string "¡CONGELATE!$"
	
GymGoosesPregunta_Text:
	.string "Casilla Pregunta: ¡Debes responder\n"
	.string "de forma correcta a la siguiente\l"
	.string "pregunta!$"

GymGooses_MapScripts::
	.byte 0
	
GymGooses_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GOOSES_GYM, GymGooses_EventScript_GymGuidePostVictory
	msgbox GymGooses_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

GymGooses_EventScript_GymGuidePostVictory::
	msgbox GymGooses_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

GymGooses_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_DEFEATED_GOOSES_GYM, GymGooses_EventScript_GymStatueCertified
	goto GymGooses_EventScript_GymStatue
	end

GymGooses_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_DEFEATED_GOOSES_GYM, GymGooses_EventScript_GymStatueCertified
	goto GymGooses_EventScript_GymStatue
	end

GymGooses_EventScript_GymStatueCertified::
	msgbox GymGooses_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

GymGooses_EventScript_GymStatue::
	msgbox GymGooses_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end
	
GymGooses_EventScript_TeleportGirl::
	lock
	faceplayer
	msgbox GymGooses_TeleportGirl_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymGooses_EventScript_TeleportGirl_Si
	release
	end
GymGooses_EventScript_TeleportGirl_Si::
	call_if_eq GymGooses_EventScript_Entrada
	release
	end

GymGooses_EventScript_Entrada::
	warp MAP_GYM_GOOSES, 0, 0, 0
	waitstate
	end

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


// Tercera Sala


// Cuarta Sala
    @ Combate contra totem.
GymGooses_EventScript_Totem:: @ 8237725
	lockall
	playmoncry SPECIES_DELIBIRD, 2
	delay 40
	waitmoncry
	msgbox Fiery_Path_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_CENTISKORCH
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 2
	removeobject 3
	setflag FLAG_TOTEM_GYMGOOSES
    msgbox Fiery_Path_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.	
	
// Quinta Sala
GymGooses_EventScript_Gooses::
	trainerbattle_single TRAINER_GOOSES, GymGooses_Text_GoosesIntro, GymGooses_Text_GoosesDefeat, GymGooses_EventScript_GoosesDefeated, NO_MUSIC
	release
	end
	
GymGooses_EventScript_GoosesDefeated::
	message GymGooses_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GymGooses_Text_ExplainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_GOOSES_GYM
	delay 30
	release
	end

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
	
GymGooses_Text_GymGuideAdvice:
	.string "¡Ya veo que has llegado lejos!\p"
	
	.string "Bienvenido al último GYM de MICOLANDIA.\p"

	.string "La pruebas de este GYM son:\n"
	.string "Completar los 3 TABLEROS de DADOS\l"
	.string "Derrotar al POKÉMON TOTEM\l"
	.string "Derrotar al LIDER de GYM\p"
	
	.string "Si consigues superar las pruebas,\n"
	.string "se te recompensará con la no-oficial\l"
	.string "MEDALLA FRIO INVERNAL.\p"

	.string "Bien, te voy a explicar en que consiste\n"
	.string "la prueba principal: TABLERO de DADOS.\p"
	
	.string "El tablero de dados consiste en avanzar\n"
	.string "casillas usando dados aleatorios del\l"
	.string "1 al 6.\p"
	
	.string "Avanzarás casillas según el número que\n"
	.string "aparezca, pero tendrás que afrontar\l"
	.string "desafios según la casilla en la que\l"
	.string "caigas.\p"
	
	.string "Te explicaré la función de cada casilla:\p"

	.string "Casilla Naranja: Te permite tirar un dado\n"
	.string "del 1 al 6.\p"
	
	.string "Casilla Direccional: Te permite avanzar\n"
	.string "una casilla.\p"

	.string "Casilla Salto: Nada útil, solo haces que\n"
	.string "des un salto en el sitio.\p"

	.string "Casilla Pokéball: Combatirás contra\n"
	.string "un entrenador generado con un equipo\l"
	.string "generado de forma aleatoria.\p"

	.string "Casilla Morada: Tendrás que responder de\n"
	.string "forma correcta a una pregunta.\p"

	.string "Casilla Musical: Tus pokémon pueden\n"
	.string "caer en un estado alterado aleatorio.\p"	

	.string "En cuanto al LIDER GOOSES, solo te puedo\n"
	.string "decir... ¡Que tengas mucho cuidado\l" 
	.string "con las congelaciones!\p"

	.string "¡Buen hax!$"

GymGooses_Text_GymGuidePostVictory:
	.string "¡Enhorabuena! ¡Ya puedes participar\n"
	.string "en la MICOLIGA!\p"
	
	.string "¡Buen hax!$"	
	
GymGooses_Text_GymStatue:
	.string "POKEMON GYM Nº4\n"
	.string "LEADER: GOOSES\l"
	.string "“TEMÁTICA: FRIO INVERNAL”$"

GymGooses_Text_GymStatueCertified:
	.string "POKEMON GYM Nº4\n"
	.string "LEADER: GOOSES\l"
	.string "“TEMÁTICA: FRIO INVERNAL”\p"

	.string "GOOSES'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
	
GymGooses_TeleportGirl_Text:
	.string "Si quieres salir del GYM, te puedo\n"
	.string "regresar a la entrada, pero ten en\l"
	.string "cuenta que tendrás que empezar el\l"
	.string "tablero desde el principio.\p"

	.string "¿Quieres que te lleve a la entrada\n"
	.string "del GYM?$"
	
GymGooses_Text_GoosesIntro:
	.string "FRASES$"
	
GymGooses_Text_GoosesDefeat:
	.string "FRASES$"
	
GymGooses_Text_GoosesPostBattle:
	.string "FRASES$"
	
GymGooses_Text_ReceivedBadge:
	.string "{PLAYER} recibió la MEDALLA FRIO\n"
	.string "INVERNAL de GOOSES.$"

GymGooses_Text_ExplainBadgeTakeThis:
	.string "Con esta MEDALLA en tu poder, desde\n"
	.string "ahora mismo, tus POKÉMON no tienen\l"
	.string "ninguna limitación para subir de\l"
	.string "nivel, pudiendo llegar al Nivel 100.\p"

	.string "Y debido a que ya tienes la última\n"
	.string "medalla, podrás participar en\l"
	.string "la MICOLIGA.$"

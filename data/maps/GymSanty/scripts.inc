GymSanty_MapScripts::
	.byte 0

GymSanty_EventScript_Santy::
	switch VAR_SHIFTEO_SANTY_GYM
	case 0, GymSanty_EventScript_Santy_Shifteo0
	case 1, GymSanty_EventScript_Santy_Shifteo1
	case 2, GymSanty_EventScript_Santy_Shifteo2
	case 3, GymSanty_EventScript_Santy_Derrotado
	end

GymSanty_EventScript_Santy_Shifteo0::
	trainerbattle_single TRAINER_ISMAPKM_1, GymSanty_Text_SantyShifteo0Intro, GymSanty_Text_SantyShifteo0Defeat, GymSanty_EventScript_SantyShifteo0Defeated, NO_MUSIC
	release
	end
	
GymSanty_EventScript_Santy_Shifteo1::
	trainerbattle_single TRAINER_JOSITO, GymSanty_Text_SantyShifteo1Intro, GymSanty_Text_SantyShifteo1Defeat, GymSanty_EventScript_SantyShifteo1Defeated, NO_MUSIC
	release
	end
	
GymSanty_EventScript_Santy_Shifteo2::
	trainerbattle_single TRAINER_FIERYPATH_PACOCHEF, GymSanty_Text_SantyShifteo2Intro, GymSanty_Text_SantyShifteo2Defeat, GymSanty_EventScript_SantyShifteo2Defeated, NO_MUSIC
	release
	end
	
GymSanty_EventScript_Santy_Derrotado::
	msgbox GymSanty_Text_SantyPostBattle, MSGBOX_DEFAULT
	release
	end

GymSanty_EventScript_SantyShifteo0Defeated::
	setvar VAR_SHIFTEO_SANTY_GYM, 1
	warp MAP_GYM_SANTY, 1, 0, 0
	waitstate
	release
	end
	
GymSanty_EventScript_SantyShifteo1Defeated::
	setvar VAR_SHIFTEO_SANTY_GYM, 2
	warp MAP_GYM_SANTY, 1, 0, 0
	waitstate
	release
	end

GymSanty_EventScript_SantyShifteo2Defeated::
	message GymSanty_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GymSanty_Text_ExplainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SANTY_GYM
	setvar VAR_SHIFTEO_SANTY_GYM, 3
	delay 30
	release
	end

GymSanty_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SANTY_GYM, GymSanty_EventScript_GymGuidePostVictory
	msgbox GymSanty_Text_GymGuideAdvice, MSGBOX_DEFAULT
	msgbox GymSanty_Text_GymGuideAdvice2, MSGBOX_DEFAULT
	msgbox GymSanty_Text_GymGuideAdvice3, MSGBOX_DEFAULT
	release
	end
	
GymSanty_EventScript_GymGuideAdviceExplainMicoliga::
	msgbox GymSanty_Text_GymGuideAdvice2, MSGBOX_DEFAULT
	release
	end

GymSanty_EventScript_GymGuidePostVictory::
	msgbox GymSanty_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	msgbox GymSanty_Text_GymGuideAdviceExplainMicoliga, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq GymSanty_EventScript_GymGuideAdviceExplainMicoliga
	release
	end

GymSanty_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_DEFEATED_SANTY_GYM, GymSanty_EventScript_GymStatueCertified
	goto GymSanty_EventScript_GymStatue
	end

GymSanty_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_DEFEATED_SANTY_GYM, GymSanty_EventScript_GymStatueCertified
	goto GymSanty_EventScript_GymStatue
	end

GymSanty_EventScript_GymStatueCertified::
	msgbox GymSanty_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

GymSanty_EventScript_GymStatue::
	msgbox GymSanty_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end
	
GymSanty_Text_GymGuideAdviceExplainMicoliga:
	.string "¿Quieres que te explique que es esto?$"
	
GymSanty_Text_GymGuideAdvice:
	.string "¡Veo que eres una cara nueva!$"
	
GymSanty_Text_GymGuideAdvice2:
	.string "Te explicaré en que consiste todo esto.\p"
	
	.string "En MICOLANDIA se está organizado una\n"
	.string "nueva competición que permite sacar\l"
	.string "todo el potencial de los entrenadores.\p"
	
	.string "Cada entrenador tendrá que superar cada\n"
	.string "uno de los retos que suponen los 4 GYM\l" 
	.string "de MICOLANDIA, de forma ordenada.\p"
	
	.string "El entrenador que sea capaz de derrotar\n" 
	.string "a los 4 LIDERES será invitado para\l" 
	.string "participar en la maravillosa MICOLIGA.\p"
	
	.string "¿Qué es la MICOLIGA?\p"
	
	.string "Es una nueva LIGA POKÉMON más dificil\n"
	.string "que cualquier otra LIGA de cualquier\l" 
	.string "otra región.\p"
	
	.string "La MICOLIGA se trata del mayor reto que\n"
	.string "jamás se ha hecho en la historia de\l"
	.string "las competiciones POKéMON.\p"
	
	.string "Por lo que el entrenador que se proclame\n"
	.string "vencedor en la MICOLIGA será el mejor\l" 
	.string "entrenador de MIDELE.\p"

	.string "Ten en cuenta, que todo esto es...\n"
	.string "digamos, no-oficial, por lo que no tiene\l" 
	.string "ninguna validez legal para los gobiernos\l"
	.string "que organizan la LIGA POKÉMON de cada\l"
	.string "región, y por tanto, en tu info de\l" 
	.string "entrenador no quedarán registradas las\l" 
	.string "medallas que consigas en este lugar.\p"
	
	.string "Cada GYM constará de 3 pruebas:\n"
	.string "Derrotar a todos los entrenadores\l"
	.string "Derrotar al POKÉMON TOTEM\l"
	.string "Derrotar al LIDER de GYM$"

GymSanty_Text_GymGuideAdvice3:
	.string "En cuanto a este GYM...\p"

	.string "Si consigues superar las 3 pruebas,\n"
	.string "se te recompensará con la no-oficial\l"
	.string "MEDALLA HIERBA QUEMADA.\p"

	.string "Por cierto, el LIDER SANTYGRASS es un\n"
	.string "maestro del olor a hierba quemada y del\l"
	.string "shifteo.\p"

	.string "¡Ten mucho cuidado y no caigas en la\n" 
	.string "desesperación que supone el shifteo!\p"
	
	.string "¡Buen hax!$"

GymSanty_Text_GymGuidePostVictory:
	.string "¡WOW! ¡Así que venciste a SANTYGRASS!$"

GymSanty_Text_SantyShifteo0Intro:
	.string "BIENVENIDO AL GYM\p" 
	.string "YA HUELO LA HIERBA QUEMADA\p"
	.string "¡JAJAJAJAJA!\p"
	.string "MEJORAR FRASES FRASES FRASES$"
	
GymSanty_Text_SantyShifteo0Defeat:
	.string "¡JEJEJEJE! AQUI NO HA PASADO NADA.\p"
	.string "“SANTYGRASS USA EL PODER DEL SHIFTEO”\p"
	.string "MEJORAR FRASES FRASES FRASES$"
	
GymSanty_Text_SantyShifteo1Intro:
	.string "BIENVENIDO AL GYM\p" 
	.string "¿OCURRE ALGO?\p"
	.string "¿QUE YA ME HAS VENCIDO?\p"
	.string "NO SE DE QUE HABLAS!!!\p"
	.string "MEJORAR FRASES FRASES FRASES$"
	
GymSanty_Text_SantyShifteo1Defeat:
	.string "¡JAJAJAJAJAJAJA! ¡NO VENCERÁS!\p"
	.string "“SANTYGRASS USA EL PODER DEL SHIFTEO”\p"
	.string "MEJORAR FRASES FRASES FRASES$"
	
GymSanty_Text_SantyShifteo2Intro:
	.string "BIENVENIDO AL GYM\p" 
	.string "¿QUE TE PASA? JAJAJA\p"

	.string "¿QUE YA ME HAS VENCIDO DOS VECES?\p"
	.string "NO SE DE QUE HABLAS!!!\p"
	
	.string "ESTA BIEN, ESTA SERÁ LA\n"
	.string "BATALLA DECISIVA!!\p"
	
	.string "ECHARE TODAS LAS PLANTAS AL SOL\p"
	.string "MEJORAR FRASES FRASES FRASES$"
	
GymSanty_Text_SantyShifteo2Defeat:
	.string "ME HAS VENCIDO...\p"
	.string "ESTA BIEN, TE GANASTE\n"
	.string "LA MEDALLA.\p"
	.string "MEJORAR FRASES FRASES FRASES$"

GymSanty_Text_ReceivedBadge:
	.string "{PLAYER} recibió la MEDALLA HIERBA\n"
	.string "QUEMADA de SANTYGRASS.$"

GymSanty_Text_ExplainBadgeTakeThis:
	.string "Con esta medalla en tu poder, estarás\n"
	.string "capacitado para retar al siguiente\l"
	.string "GYM.\p"
	
	.string "DARKIZARD te estará esperando allí.$"

GymSanty_Text_SantyPostBattle:
	.string "FRASES$"

GymSanty_Text_GymStatue:
	.string "POKEMON GYM Nº1\n"
	.string "LEADER: SANTYGRASS\l"
	.string "“TEMÁTICA: HIERBA QUEMADA”$"

GymSanty_Text_GymStatueCertified:
	.string "POKEMON GYM Nº1\n"
	.string "LEADER: SANTYGRASS\l"
	.string "“TEMÁTICA: HIERBA QUEMADA”\p"

	.string "SANTYGRASS'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"


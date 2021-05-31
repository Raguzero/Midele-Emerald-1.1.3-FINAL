ScorchedSlab_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ScorchedSlab_B2F_OnLoad
	.byte 0

ScorchedSlab_B2F_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, ScorchedSlab_B2F_EventScript_CloseEntei
	end
	
    @ Combate contra totem.
ScorchedSlab_B2F_EventScript_Totem::
	lockall
	playmoncry SPECIES_RHYPERIOR, 2
	delay 40
	waitmoncry
	msgbox ScorchedSlab_B2F_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_RHYPERIOR
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 5
	setflag FLAG_TOTEM_SCORCHEDSLAB
    msgbox ScorchedSlab_B2F_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.

ScorchedSlab_B2F_EventScript_Botones::
	trainerbattle_single TRAINER_BOTONES, ScorchedSlab_B2F_Text_BotonesIntro, ScorchedSlab_B2F_Text_BotonesDefeat
	msgbox ScorchedSlab_B2F_Text_BotonesPostBattle, MSGBOX_AUTOCLOSE
	end

ScorchedSlab_B2F_EventScript_Hypeantonio::
	trainerbattle_single TRAINER_HYPEANTONIO_2, ScorchedSlab_B2F_Text_HypeantonioIntro, ScorchedSlab_B2F_Text_HypeantonioDefeat
	msgbox ScorchedSlab_B2F_Text_HypeantonioPostBattle, MSGBOX_AUTOCLOSE
	end

ScorchedSlab_B2F_EventScript_CloseEntei::
	setmetatile 17, 4, 0x202, 1
	setmetatile 18, 4, 0x202, 1
	setmetatile 19, 4, 0x202, 1
	return

ScorchedSlab_B2F_Text_Totemaparece:
	.string "RHYPERIOR, the Totem Pokémon\n"
	.string "has appeared!$"

ScorchedSlab_B2F_Text_Totemderrotado:
	.string "RHYPERIOR disappeared...$"

ScorchedSlab_B2F_Text_BotonesIntro: 
	.string "En los pantallazos de CORO CORO\n"
	.string "dicen que esta zona es especial\l"
	.string "pero,¡¡¡yo no veo nada mas que\l"
	.string "FIRE y SOLAR STONES!!!\p"

	.string "¡Paren ya con los FAKES!$"

ScorchedSlab_B2F_Text_BotonesDefeat: 
	.string "aveces me siento feo, recuerdo que\n" 
	.string "existe mega swapert y se me pasa$"

ScorchedSlab_B2F_Text_BotonesPostBattle:
	.string "Denle ban al que pone los\n"
	.string "pantallazos es un trolleo\l"
	.string "maximo por favor dejen esto.$"

ScorchedSlab_B2F_Text_HypeantonioIntro: 
	.string "Hola, soy Hypeantonio, ¿me recuerdas?\p"

	.string "Nos vimos en Petalburg Woods hace un\n"
	.string "tiempo.\p"

	.string "Se dice que esta cueva tiene este\n"
	.string "efecto de clima soleado debido a\l"
	.string "que su estructura está formada por\l"
	.string "piedras fuego y piedras solares.\p"

	.string "Debido a ello, el reflejo de toda esa\n"
	.string "cantidad de piedras simulan los rayos\l"
	.string "del sol, lo que hace que aquí haya un\l"
	.string "calor bochornoso, como si estuvieramos\l"
	.string "a aire libre a pleno sol de Agosto.\p"

	.string "Pero yo tengo una teoría mucho mas real.\n"
	.string "¿Quieres que la cuente?\p"

	.string "...\p"

	.string "Zygarde es un Pokémon que representa\n" 
	.string "los diversos estados del humano en\l" 
	.string "función de ciertos patrones.\p"

	.string "...\p"

	.string "¿Qué pasa? ¿Quieres que me calle y que\n"
	.string "te rete a un combate?\p"

	.string "Está bien, pero si te gano te contaré\n"
	.string "el resto de la teoría.\p"

	.string "Y si pierdo, también.$"

ScorchedSlab_B2F_Text_HypeantonioDefeat: 
	.string "¡Ahora si que está claro, estos rayos\n" 
	.string "de sol son cosa de ZYGARDE!$"

ScorchedSlab_B2F_Text_HypeantonioPostBattle:
	.string "Como iba diciendo:\p"

	.string "Zygarde es un Pokémon que representa\n" 
	.string "los diversos estados del humano en\l" 
	.string "función de ciertos patrones.\p"

	.string "Es una quimera (que tiende a gárgola),\n" 
	.string "es decir, como ángel o demonio puede\l" 
	.string "camuflarse en diversos estados para\l" 
	.string "engañar con su apariencia.\p"

	.string "La forma 10% representa la licantropía,\n" 
	.string "es decir, la transformación en lobo.\p"

	.string "La forma 50% representa el quimerismo\n" 
	.string "entre humano y serpiente, presente en\l" 
	.string "diversas culturas, como Naga,\l" 
	.string "en la hinduísta.\p"

	.string "La forma completa es el humano, tanto\n" 
	.string "en forma de ángel como de demonio\l" 
	.string "(ambos unidos en un ser).\p" 

	.string "Los ángeles y demonios suelen\n" 
	.string "representarse con aspecto humano y,\l" 
	.string "en este caso, aparece en forma de\l" 
	.string "golem/gárgola.\p"

	.string "La gárgola en sí es un ángel con\n" 
	.string "apariencia demoníaca.\p"

	.string "(Media hora después)\p"

	.string "Y por tanto, la Joya del Sol permite\n" 
	.string "a los Pokémon despertar su lado humano.\p" 

	.string "Es un fragmento de la energía del Sol,\n" 
	.string "capaz de realizar la Humanización.\p"

	.string "Cuando su efecto pasa, se transforma\n" 
	.string "en una Joya de la Luna.\p"

	.string "Y por eso esta cueva es tan especial, y\n"
	.string "al igual que este lugar, existe otro\l"
	.string "con los poderes lunares que resguarda\l"
	.string "la Joya de la Luna.$"

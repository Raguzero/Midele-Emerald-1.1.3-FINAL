IzabeIsland_SecretHouseB1_MapScripts::
	.byte 0

IzabeIsland_SecretHouseB1_EventScript_Item_FocusSash::
	finditem ITEM_FOCUS_SASH
	end

IzabeIsland_SecretHouseB1_EventScript_PC::
	playse SE_PC_LOGIN
	waitse
	msgbox IzabeIsland_SecretHouseB1_Text_PC, MSGBOX_SIGN
	end

IzabeIsland_SecretHouseB1_EventScript_Titan::
	lockall
	msgbox DesafiarMasuda_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq IzabeIsland_SecretHouseB1_EventScript_TitanNoFight
	msgbox DesafiarMasuda_Text_Desacuerdo, MSGBOX_DEFAULT
	setvar VAR_0x8004, BOSS_BATTLE_MASUDA
	special CreateBossBattleMon
	special BattleSetup_StartBossBattle
	waitstate
	setvar VAR_LAST_TALKED, 1
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	call_if_eq IzabeIsland_SecretHouseB1_EventScript_TitanDefeated
	releaseall
	end

IzabeIsland_SecretHouseB1_EventScript_TitanNoFight:
	msgbox DesafiarMasuda_Text_DeAcuerdo, MSGBOX_DEFAULT
	releaseall
	end

IzabeIsland_SecretHouseB1_EventScript_TitanDefeated::
	giveitem ITEM_MICOLO_KEY
	setflag FLAG_DEFEATED_IZABE_GIANT_2
	removeobject 1
	releaseall
	end

IzabeIsland_SecretHouseB1_Text_PC::
	.string "Hay un documento abierto en el PC.\n"
	.string "“MICOLO: DIARIO SECRETO”\p"
	.string "“Al fin he vuelto a HOENN tras mis\n"
	.string "viajes fallidos en JOHTO y KANTO.”\l"
	.string "“Pero la tercera es la vencida. n.n”\l"
	.string "“Con el conocimiento que he obtenido\l"
	.string "retomaré mis experimentos y lograré\l"
	.string "conquistar HOENN. Mi primer paso\l"
	.string "será la sequía casi total del mar.”\l"
	.string "“Nadie me detendrá n.n”\l"
	.string "“PD: Monociclo porque mono es uno.”$"

DesafiarMasuda_Text:
	.string "MASUDA: ¿Pero qué mierdas pasa en este\n"
	.string "lugar?\p"
	.string "Sentí una perturbación en mi cuenta\n"
	.string "bancaria y no me está llegando tanto\l"
	.string "dinero de esta línea... ¿acaso alguien\l"
	.string "osa desafiar mi perfecta visión de en\l"
	.string "lo que se convertirá la saga?\p"
	.string "Ah... ya entiendo... es ese Darkizard...\n"
	.string "ese obsesivo que va de dimensión a\l"
	.string "dimensión y hace que la gente exija más\l"
	.string "calidad, mata Lilies indefensas, lanza\l"
	.string "nukes a toda Sinnoh existente y me\l"
	.string "hace perder millones en el proceso...\p"
	.string "Arg... de verdad me da pereza... quizás ya\n"
	.string "gano lo suficiente, e igual hay\l"
	.string "suficientes idiotas que compran\l"
	.string "cualquier cosa con POKéMON de nombre,\l"
	.string "debería largarme y dejarlo a su bola...\p"
	.string "Oye, tú, niño, seguro que me das la\n"
	.string "razon... vosotros ya no tenéis tiempo\l"
	.string "para esto, preferís vuestros móviles y\l"
	.string "apenas tenéis dos neuronas para\l"
	.string "juntar... ¿por qué querría la gente\l"
	.string "tener un reto real? ¿Estás de acuerdo?$"

DesafiarMasuda_Text_DeAcuerdo:
	.string "MASUDA: Bueno, me alegro, en ese caso\n"
	.string "creo que ni me molestaré en crear\l"
	.string "BLANCO y NEGRO en esta línea\l"
	.string "temporal... ¿que qué es eso? Nah, no te\l"
	.string "preocupes, no es como si un juego de\l"
	.string "mediana calidad te fuese a interesar...$"

DesafiarMasuda_Text_Desacuerdo:
	.string "MASUDA: ¿Cómo? MELASUDA.\p"
	.string "Aunque, bueno... si piensas así tendré\n"
	.string "que enseñarte por qué la dificultad no\l"
	.string "vende, enano.\p"
	.string "Prepárate para darme todo tu dinero.$"

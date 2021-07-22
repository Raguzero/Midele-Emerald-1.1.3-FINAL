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
	compare VAR_RESULT, NO
	goto_if_eq IzabeIsland_SecretHouseB1_EventScript_TitanNoFight
	setvar VAR_0x8004, BOSS_BATTLE_MASUDA
	special CreateBossBattleMon
	special BattleSetup_StartBossBattle
	waitstate
	setvar VAR_LAST_TALKED, 1
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	call_if_eq IzabeIsland_SecretHouseB1_EventScript_TitanDefeated
IzabeIsland_SecretHouseB1_EventScript_TitanNoFight:
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
	.string "TEXTO MASUDA$"

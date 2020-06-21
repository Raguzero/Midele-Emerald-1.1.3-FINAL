IzabeIsland_SecretHouseB1_MapScripts::
	.byte 0

IzabeIsland_SecretHouseB1_EventScript_Item_ScopeLens::
	finditem ITEM_SCOPE_LENS
	end

IzabeIsland_SecretHouseB1_EventScript_PC::
	playse SE_PC_LOGIN
	waitse
	msgbox IzabeIsland_SecretHouseB1_Text_PC, MSGBOX_SIGN
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

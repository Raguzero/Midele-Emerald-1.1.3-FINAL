IzabeIsland_SecretHouse_MapScripts::
	.byte 0
	
IzabeIsland_SecretHouse_EventScript_Trophie1::
	msgbox IzabeIsland_SecretHouse_Text_Trophie1, MSGBOX_NPC
	end
	
IzabeIsland_SecretHouse_EventScript_Trophie2::
	msgbox IzabeIsland_SecretHouse_Text_Trophie2, MSGBOX_NPC
	end
	
IzabeIsland_SecretHouse_EventScript_Planos::
	msgbox IzabeIsland_SecretHouse_Text_Planos, MSGBOX_NPC
	end

IzabeIsland_SecretHouse_EventScript_MetalCoat::
	finditem ITEM_METAL_COAT
	end

IzabeIsland_SecretHouse_EventScript_Item_LightBall::
	finditem ITEM_LIGHT_BALL
	end
	
IzabeIsland_SecretHouse_Text_Trophie1:
	.string "TROFEO CAMPEÓN JOHTO.\p"
	.string "EQUIPO POKÉMON: GYARADOS, ARCANINE,\n" 
	.string "JYNX, CROBAT, DRAGONITE, TYRANITAR$"
	
IzabeIsland_SecretHouse_Text_Trophie2:
	.string "TROFEO CAMPEÓN KANTO.\p" 
	.string "EQUIPO POKÉMON: SLOWBRO, DUGTRIO,\n" 
	.string "VIKAVOLT, NIDOQUEEN, GOLEM, DARK PIKA$"
	
IzabeIsland_SecretHouse_Text_Planos:
	.string "Parecen planos sobre el gigante.\n"
	.string "Es todo muy complicado.$"

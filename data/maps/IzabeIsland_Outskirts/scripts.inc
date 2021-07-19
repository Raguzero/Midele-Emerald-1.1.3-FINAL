IzabeIsland_Outskirts_MapScripts::
	.byte 0

IzabeIsland_Town_EventScript_ItemOutskirts_SilverPowder::
	finditem ITEM_SILVER_POWDER
	end

IzabeIsland_Town_EventScript_ItemOutskirts_SharpBeak::
	finditem ITEM_SHARP_BEAK
	end

IzabeIsland_Town_EventScript_ItemOutskirts_KingsRock::
	finditem ITEM_KINGS_ROCK
	end

IzabeIsland_Town_EventScript_ItemOutskirts_TwistedSpoon::
	finditem ITEM_TWISTED_SPOON
	end

IzabeIsland_Town_EventScript_ItemOutskirts_BlackBelt::
	finditem ITEM_BLACK_BELT
	end

IzabeIsland_Outskirts_EventScript_Truck::
	lock
	checkitem ITEM_MICOLO_KEY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq IzabeIsland_Outskirts_EventScript_EnterTruck
	msgbox IzabeIsland_Outskirts_Text_Truck, MSGBOX_DEFAULT
	release
	end

IzabeIsland_Outskirts_EventScript_EnterTruck:
	msgbox IzabeIsland_Outskirts_Text_UsedTruckKey, MSGBOX_DEFAULT
	playse SE_PIN 
	waitse
	warp MAP_IZABE_ISLAND_MICOLO_TRUCK, 255, 4, 2
	waitstate
	release
	end

IzabeIsland_Outskirts_EventScript_Youngster::
	trainerbattle_single TRAINER_IZABE_YOUNGSTER, IzabeIsland_Outskirts_Text_YoungsterIntro, IzabeIsland_Outskirts_Text_YoungsterDefeat
	msgbox IzabeIsland_Outskirts_Text_YoungsterPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_YoungsterIntro::
	.string "¿Cuántos RATTATA hacen falta para\n"
	.string "cambiar una bombilla?\p"
	.string "¡Vénceme y te lo diré!$"

IzabeIsland_Outskirts_Text_YoungsterDefeat::
	.string "Mis queridos roedores...$"

IzabeIsland_Outskirts_Text_YoungsterPostBattle::
	.string "Las RATTATA no necesitan bombillas,\n"
	.string "su majestuosidad ilumina hasta la más\l"
	.string "profunda cueva.$"

IzabeIsland_Outskirts_EventScript_Hiker::
	trainerbattle_single TRAINER_IZABE_HIKER, IzabeIsland_Outskirts_Text_HikerIntro, IzabeIsland_Outskirts_Text_HikerDefeat
	msgbox IzabeIsland_Outskirts_Text_HikerPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_HikerIntro::
	.string "No te acerques a la cueva del oeste,\n"
	.string "¡es peligrosa para los niños!$"

IzabeIsland_Outskirts_Text_HikerDefeat::
	.string "¿Es que nadie piensa en los niños?$"

IzabeIsland_Outskirts_Text_HikerPostBattle::
	.string "Dicen que un POKéMON legendario habita\n"
	.string "en la cueva del oeste.$"

IzabeIsland_Outskirts_EventScript_HexManiac::
	trainerbattle_single TRAINER_IZABE_HEXMANIAC, IzabeIsland_Outskirts_Text_HexManiacIntro, IzabeIsland_Outskirts_Text_HexManiacDefeat
	msgbox IzabeIsland_Outskirts_Text_HexManiacPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_HexManiacIntro::
	.string "Prepárate para morir... ¡FLUX!$"

IzabeIsland_Outskirts_Text_HexManiacDefeat::
	.string "¡Sin PM!$"

IzabeIsland_Outskirts_Text_HexManiacPostBattle::
	.string "¿Que cómo hago para llevar esta ropa con\n"
	.string "el frío que hace? Es magia.$"

IzabeIsland_Outskirts_EventScript_Fisherman::
	trainerbattle_single TRAINER_IZABE_FISHERMAN, IzabeIsland_Outskirts_Text_FishermanIntro, IzabeIsland_Outskirts_Text_FishermanDefeat
	msgbox IzabeIsland_Outskirts_Text_FishermanPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_FishermanIntro::
	.string "Mi MAGIKARP tiene hambre...\n"
	.string "Hambre de humanos.$"

IzabeIsland_Outskirts_Text_FishermanDefeat::
	.string "Alabada sea la carpa.$"

IzabeIsland_Outskirts_Text_FishermanPostBattle::
	.string "Esto es insostenible. Mis POKéMON\n"
	.string "necesitan comer un humano por día.\p"
	.string "Creo que ese tal MICOLO me ha estafado...$"

IzabeIsland_Outskirts_EventScript_Pokemaniac::
	trainerbattle_single TRAINER_IZABE_POKEMANIAC, IzabeIsland_Outskirts_Text_PokemaniacIntro, IzabeIsland_Outskirts_Text_PokemaniacDefeat
	msgbox IzabeIsland_Outskirts_Text_PokemaniacPostBattle, MSGBOX_AUTOCLOSE
	end

IzabeIsland_Outskirts_Text_PokemaniacIntro::
	.string "H-hola, ¿quieres ver mi colección de\n"
	.string "figuritas anime articuladas?$"

IzabeIsland_Outskirts_Text_PokemaniacDefeat::
	.string "¡No! ¡Mis figuritas!$"

IzabeIsland_Outskirts_Text_PokemaniacPostBattle::
	.string "Se miran, pero no se tocan, jejeje...$"

IzabeIsland_Outskirts_Text_Truck::
	.string "Un camión azul. Está cerrado.\n"
	.string "Te resulta familiar...$"

IzabeIsland_Outskirts_Text_UsedTruckKey::
	.string "Usaste la LL. CAMIÓN.\n"
	.string "¡La puerta del camión se ha abierto!$"

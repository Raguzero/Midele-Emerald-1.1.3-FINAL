LittlerootTown_DebugRoom_MapScripts:: @ 81F83E3
    .byte 0

@ Bolsa, crea todos los Pokémon en el PC
LittlerootTown_DebugRoom_Script_GiveAllMons::
    special GiveAllMons
    end

@ Dusclops, PC
LittlerootTown_DebugRoom_Script_PC::
    goto EventScript_PC
    end

@ Porygon2 activa eventos, cura,  da dinero y objetos
LittlerootTown_DebugRoom_Script_ActivarTodo::
    addmoney 900000, 0
    special GiveAllItems
    special HealPlayerParty
    setflag FLAG_SYS_POKEMON_GET
    setflag FLAG_SYS_POKEDEX_GET
    setflag FLAG_SYS_POKENAV_GET
    setflag FLAG_HAS_MYSTIC_TICKET
    setflag FLAG_HAS_EON_TICKET
    setflag FLAG_HAS_AURORA_TICKET
    setflag FLAG_HAS_OLD_SEA_MAP
    setflag FLAG_SYS_HAS_EON_TICKET
    setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
    setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
    setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
    setflag FLAG_SYS_GAME_CLEAR
    setflag FLAG_SYS_B_DASH
    setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
    setflag FLAG_ADVENTURE_STARTED
    setflag FLAG_DEFEATED_RUSTBORO_GYM
    setflag FLAG_DEFEATED_DEWFORD_GYM
    setflag FLAG_DEFEATED_MAUVILLE_GYM
    setflag FLAG_DEFEATED_LAVARIDGE_GYM
    setflag FLAG_DEFEATED_PETALBURG_GYM
    setflag FLAG_DEFEATED_FORTREE_GYM
    setflag FLAG_DEFEATED_MOSSDEEP_GYM
    setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
    setflag FLAG_BADGE01_GET
    setflag FLAG_BADGE02_GET
    setflag FLAG_BADGE03_GET
    setflag FLAG_BADGE04_GET
    setflag FLAG_BADGE05_GET
    setflag FLAG_BADGE06_GET
    setflag FLAG_BADGE07_GET
    setflag FLAG_BADGE08_GET
    setflag FLAG_VISITED_LITTLEROOT_TOWN
    setflag FLAG_VISITED_OLDALE_TOWN
    setflag FLAG_VISITED_DEWFORD_TOWN
    setflag FLAG_VISITED_LAVARIDGE_TOWN
    setflag FLAG_VISITED_FALLARBOR_TOWN
    setflag FLAG_VISITED_VERDANTURF_TOWN
    setflag FLAG_VISITED_PACIFIDLOG_TOWN
    setflag FLAG_VISITED_PETALBURG_CITY
    setflag FLAG_VISITED_SLATEPORT_CITY
    setflag FLAG_VISITED_MAUVILLE_CITY
    setflag FLAG_VISITED_RUSTBORO_CITY
    setflag FLAG_VISITED_FORTREE_CITY
    setflag FLAG_VISITED_LILYCOVE_CITY
    setflag FLAG_VISITED_MOSSDEEP_CITY
    setflag FLAG_VISITED_SOOTOPOLIS_CITY
    setflag FLAG_VISITED_EVER_GRANDE_CITY
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	clearflag FLAG_HIDE_LILCOVE_MOTEL_GAME_DESIGNERS
	setflag FLAG_SYS_FRONTIER_PASS
    setflag FLAG_RECEIVED_HM01
    setflag FLAG_RECEIVED_HM02
    setflag FLAG_RECEIVED_HM03
    setflag FLAG_RECEIVED_HM04
    setflag FLAG_RECEIVED_HM05
    setflag FLAG_RECEIVED_HM06
    setflag FLAG_RECEIVED_HM07
    setflag FLAG_RECEIVED_HM08
    setflag FLAG_RECEIVED_SECRET_POWER
    setvar VAR_WEATHER_INSTITUTE_STATE, 2
    clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
    setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
    setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
    setflag FLAG_ENABLE_WATTSON_MATCH_CALL
    setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
    setflag FLAG_ENABLE_WINONA_MATCH_CALL
    setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
    setflag FLAG_ENABLE_JUAN_MATCH_CALL
    special UpdateAllGymLeadersMaxRematches
    setflag FLAG_HAS_MATCH_CALL
    setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
    end

@ Magnemite desactiva eventos
LittlerootTown_DebugRoom_Script_DesactivarMedallas::
    clearflag FLAG_SYS_GAME_CLEAR
    clearflag FLAG_DEFEATED_RUSTBORO_GYM
    clearflag FLAG_DEFEATED_DEWFORD_GYM
    clearflag FLAG_DEFEATED_MAUVILLE_GYM
    clearflag FLAG_DEFEATED_LAVARIDGE_GYM
    clearflag FLAG_DEFEATED_PETALBURG_GYM
    clearflag FLAG_DEFEATED_FORTREE_GYM
    clearflag FLAG_DEFEATED_MOSSDEEP_GYM
    clearflag FLAG_DEFEATED_SOOTOPOLIS_GYM
    clearflag FLAG_BADGE01_GET
    clearflag FLAG_BADGE02_GET
    clearflag FLAG_BADGE03_GET
    clearflag FLAG_BADGE04_GET
    clearflag FLAG_BADGE05_GET
    clearflag FLAG_BADGE06_GET
    clearflag FLAG_BADGE07_GET
    clearflag FLAG_BADGE08_GET
    clearflag FLAG_RECEIVED_HM01
    clearflag FLAG_RECEIVED_HM02
    clearflag FLAG_RECEIVED_HM03
    clearflag FLAG_RECEIVED_HM04
    clearflag FLAG_RECEIVED_HM05
    clearflag FLAG_RECEIVED_HM06
    clearflag FLAG_RECEIVED_HM07
    clearflag FLAG_RECEIVED_HM08
    clearflag FLAG_RECEIVED_SECRET_POWER
    clearflag FLAG_DEFEATED_MEW
	clearflag FLAG_DEFEATED_LATIAS_OR_LATIOS
	clearflag FLAG_DEFEATED_DEOXYS
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_DEFEATED_REGIROCK
	clearflag FLAG_DEFEATED_REGICE
	clearflag FLAG_DEFEATED_REGISTEEL
	clearflag FLAG_DEFEATED_GROUDON
	clearflag FLAG_DEFEATED_KYOGRE
	clearflag FLAG_DEFEATED_RAYQUAZA
    end

@ Leaf te reta a un combate
LittlerootTown_DebugRoom_Script_Combate::
    trainerbattle_single TRAINER_DEBUG, DebugCombateTextInicio, DebugCombateTextFin
    end

@ Estatua es una boss battle.
LittlerootTown_DebugRoom_Script_Boss::
    lockall
    setvar VAR_0x8004, BOSS_BATTLE_CORONA_DEBUG
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq LittlerootTown_DebugRoom_Script_CombateGanado
    releaseall
    end

@ Sudowoodo es un combate contra totem.
LittlerootTown_DebugRoom_Script_Totem::
    lockall
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_SUDOWOODO_DEBUG
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
    compare VAR_RESULT, B_OUTCOME_WON
    call_if_eq LittlerootTown_DebugRoom_Script_CombateGanado
    releaseall
    end

@ Snorlax vende todos los objetos
LittlerootTown_DebugRoom_Script_Vendedor::
    lock
    pokemart DebugShop
    release
    end

LittlerootTown_DebugRoom_Script_CombateGanado::
    msgbox DebugCombateTextFin, MSGBOX_DEFAULT
    return


    .align 2
DebugShop::
    .2byte ITEM_SECRET_POTION
    .2byte ITEM_SWEET_HEART
    .2byte ITEM_GOLDEN_CANDY
    .2byte ITEM_G_HP_UP
    .2byte ITEM_G_PROTEIN
    .2byte ITEM_G_IRON
    .2byte ITEM_G_CARBOS
    .2byte ITEM_G_CALCIUM
    .2byte ITEM_G_ZINC
    .2byte ITEM_DESTINY_KNOT
    .2byte ITEM_MASTER_BALL
    .2byte ITEM_ULTRA_BALL
    .2byte ITEM_GREAT_BALL
    .2byte ITEM_POKE_BALL
    .2byte ITEM_SAFARI_BALL
    .2byte ITEM_NET_BALL
    .2byte ITEM_DIVE_BALL
    .2byte ITEM_NEST_BALL
    .2byte ITEM_REPEAT_BALL
    .2byte ITEM_TIMER_BALL
    .2byte ITEM_LUXURY_BALL
    .2byte ITEM_PREMIER_BALL


    .2byte ITEM_POTION
    .2byte ITEM_ANTIDOTE
    .2byte ITEM_BURN_HEAL
    .2byte ITEM_ICE_HEAL
    .2byte ITEM_AWAKENING
    .2byte ITEM_PARALYZE_HEAL
    .2byte ITEM_FULL_RESTORE
    .2byte ITEM_MAX_POTION
    .2byte ITEM_HYPER_POTION
    .2byte ITEM_SUPER_POTION
    .2byte ITEM_FULL_HEAL
    .2byte ITEM_REVIVE
    .2byte ITEM_MAX_REVIVE
    .2byte ITEM_FRESH_WATER
    .2byte ITEM_SODA_POP
    .2byte ITEM_LEMONADE
    .2byte ITEM_MOOMOO_MILK
    .2byte ITEM_ENERGY_POWDER
    .2byte ITEM_ENERGY_ROOT
    .2byte ITEM_HEAL_POWDER
    .2byte ITEM_REVIVAL_HERB
    .2byte ITEM_ETHER
    .2byte ITEM_MAX_ETHER
    .2byte ITEM_ELIXIR
    .2byte ITEM_MAX_ELIXIR
    .2byte ITEM_LAVA_COOKIE
    .2byte ITEM_BLUE_FLUTE
    .2byte ITEM_YELLOW_FLUTE
    .2byte ITEM_RED_FLUTE
    .2byte ITEM_BLACK_FLUTE
    .2byte ITEM_WHITE_FLUTE
    .2byte ITEM_BERRY_JUICE
    .2byte ITEM_SACRED_ASH
    .2byte ITEM_SHOAL_SALT
    .2byte ITEM_SHOAL_SHELL
    .2byte ITEM_RED_SHARD
    .2byte ITEM_BLUE_SHARD
    .2byte ITEM_YELLOW_SHARD
    .2byte ITEM_GREEN_SHARD
    .2byte ITEM_ABILITY_CAPSULE
    .2byte ITEM_HP_UP
    .2byte ITEM_PROTEIN
    .2byte ITEM_IRON
    .2byte ITEM_CARBOS
    .2byte ITEM_CALCIUM
    .2byte ITEM_RARE_CANDY
    .2byte ITEM_PP_UP
    .2byte ITEM_ZINC
    .2byte ITEM_PP_MAX
    .2byte ITEM_GUARD_SPEC
    .2byte ITEM_DIRE_HIT
    .2byte ITEM_X_ATTACK
    .2byte ITEM_X_DEFEND
    .2byte ITEM_X_SPEED
    .2byte ITEM_X_ACCURACY
    .2byte ITEM_X_SPECIAL
    .2byte ITEM_POKE_DOLL
    .2byte ITEM_FLUFFY_TAIL
    .2byte ITEM_SUPER_REPEL
    .2byte ITEM_MAX_REPEL
    .2byte ITEM_ESCAPE_ROPE
    .2byte ITEM_REPEL
    .2byte ITEM_SUN_STONE
    .2byte ITEM_MOON_STONE
    .2byte ITEM_FIRE_STONE
    .2byte ITEM_THUNDER_STONE
    .2byte ITEM_WATER_STONE
    .2byte ITEM_LEAF_STONE
    .2byte ITEM_DAWN_STONE
    .2byte ITEM_DUSK_STONE
    .2byte ITEM_SHINY_STONE
    .2byte ITEM_ICE_STONE


    .2byte ITEM_TINY_MUSHROOM
    .2byte ITEM_BIG_MUSHROOM
    .2byte ITEM_PEARL
    .2byte ITEM_BIG_PEARL
    .2byte ITEM_STARDUST
    .2byte ITEM_STAR_PIECE
    .2byte ITEM_NUGGET
    .2byte ITEM_HEART_SCALE


    .2byte ITEM_ORANGE_MAIL
    .2byte ITEM_HARBOR_MAIL
    .2byte ITEM_GLITTER_MAIL
    .2byte ITEM_MECH_MAIL
    .2byte ITEM_WOOD_MAIL
    .2byte ITEM_WAVE_MAIL
    .2byte ITEM_BEAD_MAIL
    .2byte ITEM_SHADOW_MAIL
    .2byte ITEM_TROPIC_MAIL
    .2byte ITEM_DREAM_MAIL
    .2byte ITEM_FAB_MAIL
    .2byte ITEM_RETRO_MAIL


    .2byte ITEM_CHERI_BERRY
    .2byte ITEM_CHESTO_BERRY
    .2byte ITEM_PECHA_BERRY
    .2byte ITEM_RAWST_BERRY
    .2byte ITEM_ASPEAR_BERRY
    .2byte ITEM_LEPPA_BERRY
    .2byte ITEM_ORAN_BERRY
    .2byte ITEM_PERSIM_BERRY
    .2byte ITEM_LUM_BERRY
    .2byte ITEM_SITRUS_BERRY
    .2byte ITEM_FIGY_BERRY
    .2byte ITEM_WIKI_BERRY
    .2byte ITEM_MAGO_BERRY
    .2byte ITEM_AGUAV_BERRY
    .2byte ITEM_IAPAPA_BERRY
    .2byte ITEM_RAZZ_BERRY
    .2byte ITEM_BLUK_BERRY
    .2byte ITEM_NANAB_BERRY
    .2byte ITEM_WEPEAR_BERRY
    .2byte ITEM_PINAP_BERRY
    .2byte ITEM_POMEG_BERRY
    .2byte ITEM_KELPSY_BERRY
    .2byte ITEM_QUALOT_BERRY
    .2byte ITEM_HONDEW_BERRY
    .2byte ITEM_GREPA_BERRY
    .2byte ITEM_TAMATO_BERRY
    .2byte ITEM_CORNN_BERRY
    .2byte ITEM_MAGOST_BERRY
    .2byte ITEM_RABUTA_BERRY
    .2byte ITEM_NOMEL_BERRY
    .2byte ITEM_SPELON_BERRY
    .2byte ITEM_PAMTRE_BERRY
    .2byte ITEM_WATMEL_BERRY
    .2byte ITEM_DURIN_BERRY
    .2byte ITEM_BELUE_BERRY
    .2byte ITEM_LIECHI_BERRY
    .2byte ITEM_GANLON_BERRY
    .2byte ITEM_SALAC_BERRY
    .2byte ITEM_PETAYA_BERRY
    .2byte ITEM_APICOT_BERRY
    .2byte ITEM_LANSAT_BERRY
    .2byte ITEM_STARF_BERRY
    .2byte ITEM_ENIGMA_BERRY


    .2byte ITEM_BRIGHT_POWDER
    .2byte ITEM_WHITE_HERB
    .2byte ITEM_MACHO_BRACE
    .2byte ITEM_EXP_SHARE
    .2byte ITEM_QUICK_CLAW
    .2byte ITEM_SOOTHE_BELL
    .2byte ITEM_MENTAL_HERB
    .2byte ITEM_CHOICE_BAND
    .2byte ITEM_KINGS_ROCK
    .2byte ITEM_SILVER_POWDER
    .2byte ITEM_AMULET_COIN
    .2byte ITEM_CLEANSE_TAG
    .2byte ITEM_SOUL_DEW
    .2byte ITEM_DEEP_SEA_TOOTH
    .2byte ITEM_DEEP_SEA_SCALE
    .2byte ITEM_SMOKE_BALL
    .2byte ITEM_EVERSTONE
    .2byte ITEM_FOCUS_BAND
    .2byte ITEM_LUCKY_EGG
    .2byte ITEM_SCOPE_LENS
    .2byte ITEM_METAL_COAT
    .2byte ITEM_LEFTOVERS
    .2byte ITEM_DRAGON_SCALE
    .2byte ITEM_LIGHT_BALL
    .2byte ITEM_SOFT_SAND
    .2byte ITEM_HARD_STONE
    .2byte ITEM_MIRACLE_SEED
    .2byte ITEM_BLACK_GLASSES
    .2byte ITEM_BLACK_BELT
    .2byte ITEM_MAGNET
    .2byte ITEM_MYSTIC_WATER
    .2byte ITEM_SHARP_BEAK
    .2byte ITEM_POISON_BARB
    .2byte ITEM_NEVER_MELT_ICE
    .2byte ITEM_SPELL_TAG
    .2byte ITEM_TWISTED_SPOON
    .2byte ITEM_CHARCOAL
    .2byte ITEM_DRAGON_FANG
    .2byte ITEM_SILK_SCARF
    .2byte ITEM_UP_GRADE
    .2byte ITEM_SHELL_BELL
    .2byte ITEM_SEA_INCENSE
    .2byte ITEM_LAX_INCENSE
    .2byte ITEM_LUCKY_PUNCH
    .2byte ITEM_METAL_POWDER
    .2byte ITEM_THICK_CLUB
    .2byte ITEM_STICK


    .2byte ITEM_RED_SCARF
    .2byte ITEM_BLUE_SCARF
    .2byte ITEM_PINK_SCARF
    .2byte ITEM_GREEN_SCARF
    .2byte ITEM_YELLOW_SCARF


    .2byte ITEM_MACH_BIKE
    .2byte ITEM_COIN_CASE
    .2byte ITEM_ITEMFINDER
    .2byte ITEM_OLD_ROD
    .2byte ITEM_GOOD_ROD
    .2byte ITEM_SUPER_ROD
    .2byte ITEM_SS_TICKET
    .2byte ITEM_CONTEST_PASS
    .2byte ITEM_EON_FLUTE
    .2byte ITEM_WAILMER_PAIL
    .2byte ITEM_DEVON_GOODS
    .2byte ITEM_SOOT_SACK
    .2byte ITEM_BASEMENT_KEY
    .2byte ITEM_ACRO_BIKE
    .2byte ITEM_POKEBLOCK_CASE
    .2byte ITEM_LETTER
    .2byte ITEM_EON_TICKET
    .2byte ITEM_RED_ORB
    .2byte ITEM_BLUE_ORB
    .2byte ITEM_SCANNER
    .2byte ITEM_GO_GOGGLES
    .2byte ITEM_METEORITE
    .2byte ITEM_ROOM_1_KEY
    .2byte ITEM_ROOM_2_KEY
    .2byte ITEM_ROOM_4_KEY
    .2byte ITEM_ROOM_6_KEY
    .2byte ITEM_STORAGE_KEY
    .2byte ITEM_ROOT_FOSSIL
    .2byte ITEM_CLAW_FOSSIL
    .2byte ITEM_DEVON_SCOPE


    .2byte ITEM_TM01
    .2byte ITEM_TM02
    .2byte ITEM_TM03
    .2byte ITEM_TM04
    .2byte ITEM_TM05
    .2byte ITEM_TM06
    .2byte ITEM_TM07
    .2byte ITEM_TM08
    .2byte ITEM_TM09
    .2byte ITEM_TM10
    .2byte ITEM_TM11
    .2byte ITEM_TM12
    .2byte ITEM_TM13
    .2byte ITEM_TM14
    .2byte ITEM_TM15
    .2byte ITEM_TM16
    .2byte ITEM_TM17
    .2byte ITEM_TM18
    .2byte ITEM_TM19
    .2byte ITEM_TM20
    .2byte ITEM_TM21
    .2byte ITEM_TM22
    .2byte ITEM_TM23
    .2byte ITEM_TM24
    .2byte ITEM_TM25
    .2byte ITEM_TM26
    .2byte ITEM_TM27
    .2byte ITEM_TM28
    .2byte ITEM_TM29
    .2byte ITEM_TM30
    .2byte ITEM_TM31
    .2byte ITEM_TM32
    .2byte ITEM_TM33
    .2byte ITEM_TM34
    .2byte ITEM_TM35
    .2byte ITEM_TM36
    .2byte ITEM_TM37
    .2byte ITEM_TM38
    .2byte ITEM_TM39
    .2byte ITEM_TM40
    .2byte ITEM_TM41
    .2byte ITEM_TM42
    .2byte ITEM_TM43
    .2byte ITEM_TM44
    .2byte ITEM_TM45
    .2byte ITEM_TM46
    .2byte ITEM_TM47
    .2byte ITEM_TM48
    .2byte ITEM_TM49
    .2byte ITEM_TM50
    .2byte ITEM_HM01
    .2byte ITEM_HM02
    .2byte ITEM_HM03
    .2byte ITEM_HM04
    .2byte ITEM_HM05
    .2byte ITEM_HM06
    .2byte ITEM_HM07
    .2byte ITEM_HM08


    .2byte ITEM_OAKS_PARCEL
    .2byte ITEM_POKE_FLUTE
    .2byte ITEM_SECRET_KEY
    .2byte ITEM_BIKE_VOUCHER
    .2byte ITEM_GOLD_TEETH
    .2byte ITEM_OLD_AMBER
    .2byte ITEM_CARD_KEY
    .2byte ITEM_LIFT_KEY
    .2byte ITEM_HELIX_FOSSIL
    .2byte ITEM_DOME_FOSSIL
    .2byte ITEM_SILPH_SCOPE
    .2byte ITEM_BICYCLE
    .2byte ITEM_TOWN_MAP
    .2byte ITEM_VS_SEEKER
    .2byte ITEM_FAME_CHECKER
    .2byte ITEM_TM_CASE
    .2byte ITEM_BERRY_POUCH
    .2byte ITEM_TEACHY_TV
    .2byte ITEM_TRI_PASS
    .2byte ITEM_RAINBOW_PASS
    .2byte ITEM_TEA
    .2byte ITEM_MYSTIC_TICKET
    .2byte ITEM_AURORA_TICKET
    .2byte ITEM_POWDER_JAR
    .2byte ITEM_RUBY
    .2byte ITEM_SAPPHIRE


    .2byte ITEM_MAGMA_EMBLEM
    .2byte ITEM_OLD_SEA_MAP
    .2byte ITEM_NONE
    release
    end

DebugCombateTextInicio::
    .string "¿?!1¡áéíóúñç$"

DebugCombateTextFin::
    .string ":D :3 :) n.n o.o uwu$"

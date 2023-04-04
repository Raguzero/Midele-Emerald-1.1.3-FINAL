InsideOfTruck_MapScripts:: @ 823BEDA
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_OnResume
	.byte 0

InsideOfTruck_OnLoad: @ 823BEE5
	setmetatile 4, 1, METATILE_InsideOfTruck_ExitLight_Top, 0
	setmetatile 4, 2, METATILE_InsideOfTruck_ExitLight_Mid, 0
	setmetatile 4, 3, METATILE_InsideOfTruck_ExitLight_Bottom, 0
	end

InsideOfTruck_OnResume: @ 823BF01
	setstepcallback STEP_CB_TRUCK
	end

InsideOfTruck_EventScript_SetIntroFlags:: @ 823BF04
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq InsideOfTruck_EventScript_SetIntroFlagsMale
	compare VAR_RESULT, FEMALE
	goto_if_eq InsideOfTruck_EventScript_SetIntroFlagsFemale
	end

InsideOfTruck_EventScript_SetIntroFlagsMale:: @ 823BF20
	goto_if_set FLAG_UNUSED_0x2AE, MicolandiaModeEnd
	msgbox ElegirMicolandiaMode_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MicolandiaMode
	msgbox NombreVecino_Text, MSGBOX_DEFAULT
	special NameRival
	waitstate
	msgbox NombreVecino_Text2, MSGBOX_DEFAULT
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 3, 10
	releaseall
	end

InsideOfTruck_EventScript_SetIntroFlagsFemale:: @ 823BF46
	goto_if_set FLAG_UNUSED_0x2AE, MicolandiaModeEnd
	msgbox ElegirMicolandiaMode_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MicolandiaMode
	msgbox NombreVecino_Text, MSGBOX_DEFAULT
	special NameRival
	waitstate
	msgbox NombreVecino_Text2, MSGBOX_DEFAULT
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 1
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 12, 10
	releaseall
	end
	
MicolandiaMode::
    setflag FLAG_SYS_POKEMON_GET
    setflag FLAG_SYS_POKEDEX_GET
    setflag FLAG_SYS_POKENAV_GET
    setflag FLAG_SYS_B_DASH
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_SYS_DEXNAV_GET
	setflag FLAG_SYS_DETECTOR_MODE
    additem ITEM_PP_MAX, 999
    additem ITEM_SWEET_HEART, 1
	additem ITEM_ABILITY_CAPSULE, 1
	additem ITEM_SECRET_POTION, 1
    additem ITEM_MUSIC_PLAYER, 1
    additem ITEM_LEVEL_CAP, 1
    //setvar VAR_MUSIC_PLAYER, MUSIC_PLAYER_STATE_FINAL
    addmoney 900000, 0
    additem ITEM_MACH_BIKE, 1
    additem ITEM_COIN_CASE, 1
    additem ITEM_ITEMFINDER, 1
    additem ITEM_OLD_ROD, 1
    additem ITEM_GOOD_ROD, 1
    additem ITEM_SUPER_ROD, 1
    additem ITEM_ACRO_BIKE, 1
	additem ITEM_TM01, 1
	additem ITEM_TM02, 1
	additem ITEM_TM03, 1
	additem ITEM_TM04, 1
	additem ITEM_TM05, 1
	additem ITEM_TM06, 1
	additem ITEM_TM07, 1
	additem ITEM_TM08, 1
	additem ITEM_TM09, 1
	additem ITEM_TM10, 1
	additem ITEM_TM11, 1
	additem ITEM_TM12, 1
	additem ITEM_TM13, 1
	additem ITEM_TM14, 1
	additem ITEM_TM15, 1
	additem ITEM_TM16, 1
	additem ITEM_TM17, 1
	additem ITEM_TM18, 1
	additem ITEM_TM19, 1
	additem ITEM_TM20, 1
	additem ITEM_TM21, 1
	additem ITEM_TM22, 1
	additem ITEM_TM23, 1
	additem ITEM_TM24, 1
	additem ITEM_TM25, 1
	additem ITEM_TM26, 1
	additem ITEM_TM27, 1
	additem ITEM_TM28, 1
	additem ITEM_TM29, 1
	additem ITEM_TM30, 1
	additem ITEM_TM31, 1
	additem ITEM_TM32, 1
	additem ITEM_TM33, 1
	additem ITEM_TM34, 1
	additem ITEM_TM35, 1
	additem ITEM_TM36, 1
	additem ITEM_TM37, 1
	additem ITEM_TM38, 1
	additem ITEM_TM39, 1
	additem ITEM_TM40, 1
	additem ITEM_TM41, 1
	additem ITEM_TM42, 1
	additem ITEM_TM43, 1
	additem ITEM_TM44, 1
	additem ITEM_TM45, 1
	additem ITEM_TM46, 1
	additem ITEM_TM47, 1
	additem ITEM_TM48, 1
	additem ITEM_TM49, 1
	additem ITEM_TM50, 1
	additem ITEM_HM01, 1
	additem ITEM_HM02, 1
	additem ITEM_HM03, 1
	additem ITEM_HM04, 1
	additem ITEM_HM05, 1
	additem ITEM_HM06, 1
	additem ITEM_HM07, 1
	additem ITEM_HM08, 1
    givemon SPECIES_BULBASAUR, 5, ITEM_NONE
    givemon SPECIES_CHARMANDER, 5, ITEM_NONE
    givemon SPECIES_SQUIRTLE, 5, ITEM_NONE
    givemon SPECIES_CATERPIE, 5, ITEM_NONE
    givemon SPECIES_WEEDLE, 5, ITEM_NONE
    givemon SPECIES_PIDGEY, 5, ITEM_NONE
    givemon SPECIES_RATTATA, 5, ITEM_NONE
    givemon SPECIES_SPEAROW, 5, ITEM_NONE
    givemon SPECIES_EKANS, 5, ITEM_NONE
    givemon SPECIES_SANDSHREW, 5, ITEM_NONE
    givemon SPECIES_NIDORAN_F, 5, ITEM_NONE
    givemon SPECIES_NIDORAN_M, 5, ITEM_NONE
    givemon SPECIES_VULPIX, 5, ITEM_NONE
    givemon SPECIES_ZUBAT, 5, ITEM_NONE
    givemon SPECIES_ODDISH, 5, ITEM_NONE
    givemon SPECIES_PARAS, 5, ITEM_NONE
    givemon SPECIES_VENONAT, 5, ITEM_NONE
    givemon SPECIES_DIGLETT, 5, ITEM_NONE
    givemon SPECIES_MEOWTH, 5, ITEM_NONE
    givemon SPECIES_PSYDUCK, 5, ITEM_NONE
    givemon SPECIES_MANKEY, 5, ITEM_NONE
    givemon SPECIES_GROWLITHE, 5, ITEM_NONE
    givemon SPECIES_POLIWAG, 5, ITEM_NONE
    givemon SPECIES_ABRA, 5, ITEM_NONE
    givemon SPECIES_MACHOP, 5, ITEM_NONE
    givemon SPECIES_BELLSPROUT, 5, ITEM_NONE
    givemon SPECIES_TENTACOOL, 5, ITEM_NONE
    givemon SPECIES_GEODUDE, 5, ITEM_NONE
    givemon SPECIES_PONYTA, 5, ITEM_NONE
    givemon SPECIES_SLOWPOKE, 5, ITEM_NONE
    givemon SPECIES_MAGNEMITE, 5, ITEM_NONE
    givemon SPECIES_FARFETCHD, 5, ITEM_NONE
    givemon SPECIES_DODUO, 5, ITEM_NONE
    givemon SPECIES_SEEL, 5, ITEM_NONE
    givemon SPECIES_GRIMER, 5, ITEM_NONE
    givemon SPECIES_SHELLDER, 5, ITEM_NONE
    givemon SPECIES_GASTLY, 5, ITEM_NONE
    givemon SPECIES_ONIX, 5, ITEM_NONE
    givemon SPECIES_DROWZEE, 5, ITEM_NONE
    givemon SPECIES_KRABBY, 5, ITEM_NONE
    givemon SPECIES_VOLTORB, 5, ITEM_NONE
    givemon SPECIES_EXEGGCUTE, 5, ITEM_NONE
    givemon SPECIES_CUBONE, 5, ITEM_NONE
    givemon SPECIES_LICKITUNG, 5, ITEM_NONE
    givemon SPECIES_KOFFING, 5, ITEM_NONE
    givemon SPECIES_RHYHORN, 5, ITEM_NONE
    givemon SPECIES_TANGELA, 5, ITEM_NONE
    //givemon SPECIES_KANGASKHAN, 5, ITEM_NONE
    givemon SPECIES_HORSEA, 5, ITEM_NONE
    givemon SPECIES_GOLDEEN, 5, ITEM_NONE
	givemon SPECIES_STARYU, 5, ITEM_NONE
    //givemon SPECIES_SCYTHER, 5, ITEM_NONE
    //givemon SPECIES_PINSIR, 5, ITEM_NONE
    //givemon SPECIES_TAUROS, 5, ITEM_NONE
    givemon SPECIES_MAGIKARP, 5, ITEM_NONE
    //givemon SPECIES_LAPRAS, 5, ITEM_NONE
    givemon SPECIES_DITTO, 5, ITEM_NONE
    givemon SPECIES_EEVEE, 5, ITEM_NONE
    givemon SPECIES_PORYGON, 5, ITEM_NONE
    givemon SPECIES_OMANYTE, 5, ITEM_NONE
    givemon SPECIES_KABUTO, 5, ITEM_NONE
    //givemon SPECIES_AERODACTYL, 5, ITEM_NONE
    givemon SPECIES_DRATINI, 5, ITEM_NONE
    givemon SPECIES_CHIKORITA, 5, ITEM_NONE
    givemon SPECIES_CYNDAQUIL, 5, ITEM_NONE
    givemon SPECIES_TOTODILE, 5, ITEM_NONE
    givemon SPECIES_SENTRET, 5, ITEM_NONE
    givemon SPECIES_HOOTHOOT, 5, ITEM_NONE
    givemon SPECIES_LEDYBA, 5, ITEM_NONE
    givemon SPECIES_SPINARAK, 5, ITEM_NONE
    givemon SPECIES_CHINCHOU, 5, ITEM_NONE
    givemon SPECIES_PICHU, 5, ITEM_NONE
    givemon SPECIES_CLEFFA, 5, ITEM_NONE
    givemon SPECIES_IGGLYBUFF, 5, ITEM_NONE
    givemon SPECIES_TOGEPI, 5, ITEM_NONE
    givemon SPECIES_NATU, 5, ITEM_NONE
    givemon SPECIES_MAREEP, 5, ITEM_NONE
    givemon SPECIES_HOPPIP, 5, ITEM_NONE
    givemon SPECIES_AIPOM, 5, ITEM_NONE
    givemon SPECIES_SUNKERN, 5, ITEM_NONE
    givemon SPECIES_YANMA, 5, ITEM_NONE
    givemon SPECIES_WOOPER, 5, ITEM_NONE
    givemon SPECIES_MURKROW, 5, ITEM_NONE
    givemon SPECIES_MISDREAVUS, 5, ITEM_NONE
    givemon SPECIES_UNOWN, 5, ITEM_NONE
    //givemon SPECIES_GIRAFARIG, 5, ITEM_NONE
    givemon SPECIES_PINECO, 5, ITEM_NONE
    givemon SPECIES_DUNSPARCE, 5, ITEM_NONE
    givemon SPECIES_GLIGAR, 5, ITEM_NONE
    givemon SPECIES_SNUBBULL, 5, ITEM_NONE
    givemon SPECIES_QWILFISH, 5, ITEM_NONE
    //givemon SPECIES_SHUCKLE, 5, ITEM_NONE
    //givemon SPECIES_HERACROSS, 5, ITEM_NONE
    //givemon SPECIES_SNEASEL, 5, ITEM_NONE
    givemon SPECIES_TEDDIURSA, 5, ITEM_NONE
    givemon SPECIES_SLUGMA, 5, ITEM_NONE
    givemon SPECIES_SWINUB, 5, ITEM_NONE
    //givemon SPECIES_CORSOLA, 5, ITEM_NONE
    givemon SPECIES_REMORAID, 5, ITEM_NONE
    givemon SPECIES_DELIBIRD, 5, ITEM_NONE
    //givemon SPECIES_SKARMORY, 5, ITEM_NONE
    givemon SPECIES_HOUNDOUR, 5, ITEM_NONE
    givemon SPECIES_PHANPY, 5, ITEM_NONE
    //givemon SPECIES_STANTLER, 5, ITEM_NONE
    givemon SPECIES_SMEARGLE, 5, ITEM_NONE
    givemon SPECIES_TYROGUE, 5, ITEM_NONE
    givemon SPECIES_SMOOCHUM, 5, ITEM_NONE
    givemon SPECIES_ELEKID, 5, ITEM_NONE
    givemon SPECIES_MAGBY, 5, ITEM_NONE
    //givemon SPECIES_MILTANK, 5, ITEM_NONE
    givemon SPECIES_LARVITAR, 5, ITEM_NONE
    givemon SPECIES_TREECKO, 5, ITEM_NONE
    givemon SPECIES_TORCHIC, 5, ITEM_NONE
    givemon SPECIES_MUDKIP, 5, ITEM_NONE
    givemon SPECIES_POOCHYENA, 5, ITEM_NONE
    givemon SPECIES_ZIGZAGOON, 5, ITEM_NONE
    givemon SPECIES_WURMPLE, 5, ITEM_NONE
    givemon SPECIES_LOTAD, 5, ITEM_NONE
    givemon SPECIES_SEEDOT, 5, ITEM_NONE
    givemon SPECIES_TAILLOW, 5, ITEM_NONE
    givemon SPECIES_WINGULL, 5, ITEM_NONE
    givemon SPECIES_RALTS, 5, ITEM_NONE
    givemon SPECIES_SURSKIT, 5, ITEM_NONE
    givemon SPECIES_SHROOMISH, 5, ITEM_NONE
    givemon SPECIES_SLAKOTH, 5, ITEM_NONE
    givemon SPECIES_NINCADA, 5, ITEM_NONE
    givemon SPECIES_WHISMUR, 5, ITEM_NONE
    givemon SPECIES_MAKUHITA, 5, ITEM_NONE
    givemon SPECIES_AZURILL, 5, ITEM_NONE
    givemon SPECIES_NOSEPASS, 5, ITEM_NONE
    givemon SPECIES_SKITTY, 5, ITEM_NONE
    givemon SPECIES_SABLEYE, 5, ITEM_NONE
    givemon SPECIES_MAWILE, 5, ITEM_NONE
    givemon SPECIES_ARON, 5, ITEM_NONE
    givemon SPECIES_MEDITITE, 5, ITEM_NONE
    givemon SPECIES_ELECTRIKE, 5, ITEM_NONE
    givemon SPECIES_PLUSLE, 5, ITEM_NONE
    givemon SPECIES_MINUN, 5, ITEM_NONE
    givemon SPECIES_VOLBEAT, 5, ITEM_NONE
    givemon SPECIES_ILLUMISE, 5, ITEM_NONE
    givemon SPECIES_GULPIN, 5, ITEM_NONE
    givemon SPECIES_CARVANHA, 5, ITEM_NONE
    givemon SPECIES_WAILMER, 5, ITEM_NONE
    givemon SPECIES_NUMEL, 5, ITEM_NONE
    //givemon SPECIES_TORKOAL, 5, ITEM_NONE
    givemon SPECIES_SPOINK, 5, ITEM_NONE
    givemon SPECIES_SPINDA, 5, ITEM_NONE
    givemon SPECIES_TRAPINCH, 5, ITEM_NONE
    givemon SPECIES_CACNEA, 5, ITEM_NONE
    givemon SPECIES_SWABLU, 5, ITEM_NONE
    //givemon SPECIES_ZANGOOSE, 5, ITEM_NONE
    //givemon SPECIES_SEVIPER, 5, ITEM_NONE
    //givemon SPECIES_LUNATONE, 5, ITEM_NONE
    //givemon SPECIES_SOLROCK, 5, ITEM_NONE
    givemon SPECIES_BARBOACH, 5, ITEM_NONE
    givemon SPECIES_CORPHISH, 5, ITEM_NONE
    givemon SPECIES_BALTOY, 5, ITEM_NONE
    givemon SPECIES_LILEEP, 5, ITEM_NONE
    givemon SPECIES_ANORITH, 5, ITEM_NONE
    givemon SPECIES_FEEBAS, 5, ITEM_NONE
    //givemon SPECIES_CASTFORM, 5, ITEM_NONE
    //givemon SPECIES_KECLEON, 5, ITEM_NONE
    givemon SPECIES_SHUPPET, 5, ITEM_NONE
    givemon SPECIES_DUSKULL, 5, ITEM_NONE
    //givemon SPECIES_TROPIUS, 5, ITEM_NONE
    //givemon SPECIES_ABSOL, 5, ITEM_NONE
    givemon SPECIES_WYNAUT, 5, ITEM_NONE
    givemon SPECIES_SNORUNT, 5, ITEM_NONE
    givemon SPECIES_SPHEAL, 5, ITEM_NONE
    givemon SPECIES_CLAMPERL, 5, ITEM_NONE
    //givemon SPECIES_RELICANTH, 5, ITEM_NONE
    givemon SPECIES_LUVDISC, 5, ITEM_NONE
    givemon SPECIES_BAGON, 5, ITEM_NONE
    givemon SPECIES_BELDUM, 5, ITEM_NONE
    givemon SPECIES_YAMASK, 5, ITEM_NONE
    givemon SPECIES_SNOVER, 5, ITEM_NONE
    givemon SPECIES_ALOLAN_RATTATA, 5, ITEM_NONE
    givemon SPECIES_ALOLAN_SANDSHREW, 5, ITEM_NONE
    givemon SPECIES_ALOLAN_VULPIX, 5, ITEM_NONE
    givemon SPECIES_ALOLAN_DIGLETT, 5, ITEM_NONE
    givemon SPECIES_ALOLAN_MEOWTH, 5, ITEM_NONE
    givemon SPECIES_ALOLAN_GEODUDE, 5, ITEM_NONE
    givemon SPECIES_ALOLAN_GRIMER, 5, ITEM_NONE
    givemon SPECIES_GALAR_ZIGZAGOON, 5, ITEM_NONE
    givemon SPECIES_GALAR_MEOWTH, 5, ITEM_NONE
    givemon SPECIES_GALAR_FARFETCH, 5, ITEM_NONE
    //givemon SPECIES_GALAR_CORSOLA, 5, ITEM_NONE
    givemon SPECIES_GALAR_YAMASK, 5, ITEM_NONE
    givemon SPECIES_GALAR_PONYTA, 5, ITEM_NONE
    givemon SPECIES_GROOKEY, 5, ITEM_NONE
    givemon SPECIES_TYRUNT, 5, ITEM_NONE
    givemon SPECIES_AMAURA, 5, ITEM_NONE
    givemon SPECIES_DEINO, 5, ITEM_NONE
    givemon SPECIES_JANGMO_O, 5, ITEM_NONE
    givemon SPECIES_DREEPY, 5, ITEM_NONE
    givemon SPECIES_IMPIDIMP, 5, ITEM_NONE
    givemon SPECIES_SKORUPI, 5, ITEM_NONE
    givemon SPECIES_RIOLU, 5, ITEM_NONE
    givemon SPECIES_MILCERY, 5, ITEM_NONE
    givemon SPECIES_TYNAMO, 5, ITEM_NONE
    givemon SPECIES_GRUBBIN, 5, ITEM_NONE
    givemon SPECIES_LITWICK, 5, ITEM_NONE
    givemon SPECIES_ROWLET, 5, ITEM_NONE
    givemon SPECIES_POPPLIO, 5, ITEM_NONE
    givemon SPECIES_SOBBLE, 5, ITEM_NONE
    givemon SPECIES_TURTWIG, 5, ITEM_NONE
    givemon SPECIES_PIPLUP, 5, ITEM_NONE
    givemon SPECIES_PAWNIARD, 5, ITEM_NONE
    givemon SPECIES_SALANDIT, 5, ITEM_NONE
    givemon SPECIES_SANDYGAST, 5, ITEM_NONE
    givemon SPECIES_FERROSEED, 5, ITEM_NONE
    givemon SPECIES_SANDILE, 5, ITEM_NONE
    givemon SPECIES_CROAGUNK, 5, ITEM_NONE
    givemon SPECIES_LILLIPUP, 5, ITEM_NONE
    givemon SPECIES_SIZZLIPEDE, 5, ITEM_NONE
    givemon SPECIES_ROOKIDEE, 5, ITEM_NONE
    //givemon SPECIES_HAWLUCHA, 5, ITEM_NONE
    //givemon SPECIES_DURANT, 5, ITEM_NONE
    givemon SPECIES_SNOM, 5, ITEM_NONE
    givemon SPECIES_TOXEL, 5, ITEM_NONE
    givemon SPECIES_APPLIN, 5, ITEM_NONE
    //givemon SPECIES_DURALUDON, 5, ITEM_NONE
    givemon SPECIES_COTTONEE, 5, ITEM_NONE
    givemon SPECIES_HIPPOPOTAS, 5, ITEM_NONE
    givemon SPECIES_COMBEE, 5, ITEM_NONE
    givemon SPECIES_SILICOBRA, 5, ITEM_NONE
    givemon SPECIES_PANCHAM, 5, ITEM_NONE
    givemon SPECIES_SKRELP, 5, ITEM_NONE
    givemon SPECIES_STUFFUL, 5, ITEM_NONE
    givemon SPECIES_PUMPKABOO, 5, ITEM_NONE
    givemon SPECIES_FRILLISH, 5, ITEM_NONE
    givemon SPECIES_ROCKRUFF, 5, ITEM_NONE
    givemon SPECIES_SNIVY, 5, ITEM_NONE
    givemon SPECIES_BUDEW, 5, ITEM_NONE
    givemon SPECIES_CHINGLING, 5, ITEM_NONE
    givemon SPECIES_BONSLY, 5, ITEM_NONE
    givemon SPECIES_MIMEJR, 5, ITEM_NONE
    givemon SPECIES_HAPPINY, 5, ITEM_NONE
    givemon SPECIES_MUNCHLAX, 5, ITEM_NONE
    givemon SPECIES_MANTYKE, 5, ITEM_NONE
    givemon SPECIES_CHESPIN, 5, ITEM_NONE
    givemon SPECIES_CHIMCHAR, 5, ITEM_NONE
    //givemon SPECIES_WINTASS, 5, ITEM_NONE
    //givemon SPECIES_WOOLOO, 5, ITEM_NONE
    givemon SPECIES_GOOMY, 5, ITEM_NONE
    //givemon SPECIES_STUNFISK, 5, ITEM_NONE
    //givemon SPECIES_GALAR_STUNFISK, 5, ITEM_NONE
    givemon SPECIES_SOLOSIS, 5, ITEM_NONE
    givemon SPECIES_VULLABY, 5, ITEM_NONE
    givemon SPECIES_DRILBUR, 5, ITEM_NONE
    //givemon SPECIES_DHELMISE, 5, ITEM_NONE
    givemon SPECIES_GOLETT, 5, ITEM_NONE
	setrespawn HEAL_LOCATION_MICOLANDIA
	setdynamicwarp MAP_MICOLANDIA_HOUSE1, 2, 0, 0
	setflag FLAG_UNUSED_0x2AE // ACTIVA MICOLANDIA MODE
	releaseall
	end
	
MicolandiaModeEnd::
	releaseall
	end
	
ElegirMicolandiaMode_Text:
	.string "¿Quieres elegir jugar al MODO MIDELE?\p"
	.string "En este modo de juego, empezarás\n"
	.string "directamente el Desafio de la\l"
	.string "MICOLIGA de MICOLANDIA.\p"
	.string "Se te suministrarán 8 cajas llenas\n"
	.string "de POKéMON al Nivel 5 para afrontar\l"
	.string "el desafío, pero ten en cuenta que en\l"
	.string "este modo no podrás ir a HOENN.\p"
	.string "¿Tienes claro que quieres jugar al\n"
	.string "MODO MIDELE?$"
	


InsideOfTruck_EventScript_MovingBox:: @ 823BF6C
	msgbox InsideOfTruck_Text_BoxPrintedWithMonLogo, MSGBOX_SIGN
	end

InsideOfTruck_Text_BoxPrintedWithMonLogo: @ 823BF75
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"
	
NombreVecino_Text:
	.string "By the way, what was my\n"
	.string "new neighbor's name?$"
	
NombreVecino_Text2:
	.string "I remember, the name was {RIVAL}!$"


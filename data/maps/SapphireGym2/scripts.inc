SapphireGym2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SapphireGym2_MapScripts_OnLoad
	.byte 0

SapphireGym2_MapScripts_OnLoad:
	call_if_unset FLAG_DEFEATED_SAPPHIRE_TOTEM, SapphireGym2_BlockTotemPath
	checktrainerflag TRAINER_SAPPH
	call_if_ne SapphireGym2_BlockTitanRoom
	return

SapphireGym2_BlockTotemPath:
	setmetatile 10, 37, 0x23C, 1
	setmetatile 10, 36, 0x234, 1
	return

SapphireGym2_OpenTotemPath:
	setmetatile 10, 37, 0x2C1, 0
	setmetatile 10, 36, 0x2C1, 0
	return

SapphireGym2_BlockTitanRoom:
	setmetatile 9, 3, 0x259, 1
	setmetatile 10, 3, 0x25A, 1
	setmetatile 11, 3, 0x25B, 1
	setmetatile 9, 2, 0x251, 1
	setmetatile 10, 2, 0x252, 1
	setmetatile 11, 2, 0x253, 1
	setmetatile 9, 1, 0x249, 1
	setmetatile 10, 1, 0x24A, 1
	setmetatile 11, 1, 0x24B, 1
	return

SapphireGym2_OpenTitanRoom:
	setmetatile 9, 3, 0x2BA, 1
	setmetatile 10, 3, 0x2BB, 0
	setmetatile 11, 3, 0x2BC, 1
	setmetatile 9, 2, 0x2B2, 1
	setmetatile 10, 2, 0x2B3, 1
	setmetatile 11, 2, 0x2B4, 1
	setmetatile 9, 1, 0x2AA, 1
	setmetatile 10, 1, 0x2AB, 1
	setmetatile 11, 1, 0x2AC, 1
	return

SapphireGym2_EventScript_Totem::
	lockall
	msgbox DesafiarTotem_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SapphireGym2_EventScript_Totem2
	releaseall
	end	
	
SapphireGym2_EventScript_Totem2::	
	playmoncry SPECIES_DARK_PIKACHU, 2
	delay 40
	waitmoncry
	msgbox SapphireGym2_Text_TotemAppears, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_SAPPHIRE
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
	setvar VAR_LAST_TALKED, 2
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	call_if_eq SapphireGym2_EventScript_Totem_Won
	releaseall
	end

SapphireGym2_EventScript_Totem_Won::
	setflag FLAG_DEFEATED_SAPPHIRE_TOTEM
	removeobject 2
	call SapphireGym2_OpenTotemPath
	special DrawWholeMapView
	msgbox SapphireGym2_Text_TotemDisappears
	return

SapphireGym2_EventScript_Sapphire::
	lock
	faceplayer
	checktrainerflag TRAINER_SAPPH
	goto_if_eq SapphireGym2_EventScript_Sapphire_Defeated
	trainerbattle_single TRAINER_SAPPH, SapphireGym_Text_SapphIntro, SapphireGym_Text_SapphLose, SapphireGym2_EventScript_SapphDefeated, NO_MUSIC
	release
	end

SapphireGym2_EventScript_SapphDefeated::
	message SapphireGym2_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SapphireGym2_Text_ExplainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SAPPH_GYM
	delay 30
	playse SE_DOOR
	delay 40
	call SapphireGym2_OpenTitanRoom
	playse SE_RG_W_DOOR
	special DrawWholeMapView
	release
	end
	
SapphireGym2_EventScript_Sapphire_Defeated::
	goto_if_set FLAG_REMATCH_SAPPH, SapphireGym2_EventScript_Sapph_Rematch
	msgbox SapphireGym2_Text_SapphPostBattle, MSGBOX_DEFAULT
	release
	end
	
SapphireGym2_EventScript_Sapph_Rematch::
	trainerbattle_single TRAINER_SAPPH, SapphireGym2_Text_SapphRematchIntro, SapphireGym_Text_SapphLose, SapphireGym2_EventScript_SapphRematchDefeated, NO_MUSIC
	release
	end
	
SapphireGym2_EventScript_SapphRematchDefeated::
	msgbox SapphireGym2_Text_SapphRematchPostBattle, MSGBOX_DEFAULT
	clearflag FLAG_REMATCH_SAPPH
	release
	end

SapphireGym2_Text_TotemAppears:
	.string "DARK PIKA, the TOTEM Pokémon of\n" 
	.string "SAPPHIRE GYM, has appeared!$"

SapphireGym2_Text_TotemDisappears:
	.string "DARK PIKA disappeared...$"

SapphireGym_Text_SapphIntro:
	.string "TEXTO SAPPH INTRO$"

SapphireGym_Text_SapphLose:
	.string "TEXT SAPPH LOSE$"

SapphireGym2_Text_ReceivedBadge:
	.string "TEXTO SAPPH MEDALLA$"

SapphireGym2_Text_ExplainBadgeTakeThis:
	.string "TEXTO EXPLICA MEDALLA$"

SapphireGym2_Text_SapphPostBattle:
	.string "TEXTO POST BATTLE$"
	
SapphireGym2_Text_SapphRematchIntro:
    .string "TEXTO REMATCH INTRO$" 

SapphireGym2_Text_SapphRematchPostBattle:
	.string "TEXTO REMATCH POSTBATTLE$"

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

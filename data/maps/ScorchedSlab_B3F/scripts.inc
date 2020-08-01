ScorchedSlab_B3F_MapScripts::
	.byte 0
	
ScorchedSlab_B3F_EventScript_Entei::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ENTEI, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_ENTEI, 40, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq ScorchedSlab_B3F_EventScript_DefeatedEntei
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq ScorchedSlab_B3F_EventScript_RanFromEntei
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq ScorchedSlab_B3F_EventScript_RanFromEntei
	setflag FLAG_CAUGHT_ENTEI
	release
	end

ScorchedSlab_B3F_EventScript_DefeatedEntei:: @ 82390A1
	setflag FLAG_DEFEATED_ENTEI
	goto Common_EventScript_RemoveStaticPokemon
	end

ScorchedSlab_B3F_EventScript_RanFromEntei:: @ 82390AA
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryFlewAway
	end

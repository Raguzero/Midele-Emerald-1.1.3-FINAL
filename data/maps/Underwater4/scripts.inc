Underwater4_MapScripts:: @ 81F7730
	.byte 0
	
    @ Combate contra totem.
Underwater4_EventScript_Totem::
	lockall
	playmoncry SPECIES_PRIMARINA, 2
	delay 40
	waitmoncry
	msgbox Underwater4_Text_Totemaparece, MSGBOX_DEFAULT
    setvar VAR_0x8004, BOSS_BATTLE_TOTEM_PRIMARINA
    special CreateBossBattleMon
    special BattleSetup_StartBossBattle
    waitstate
    setvar VAR_LAST_TALKED, 1
    specialvar VAR_RESULT, GetBattleOutcome
	removeobject 1
	setflag FLAG_TOTEM_SEAFLOOR_CAVERN_OUTSIDE
    msgbox Underwater4_Text_Totemderrotado
	releaseall
	end
    @ Combate contra totem.	
	
Underwater4_Text_Totemaparece:
	.string "PRIMARINA, the Totem Pokémon\n"
	.string "has appeared!$"

Underwater4_Text_Totemderrotado:
	.string "PRIMARINA disappeared...$"

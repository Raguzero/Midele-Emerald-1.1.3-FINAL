SkyPillar_5F_MapScripts:: @ 82396A2
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_5F_OnTransition
	.byte 0

SkyPillar_5F_OnTransition: @ 82396A8
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_lt SkyPillar_5F_EventScript_CleanFloor
	return

SkyPillar_5F_EventScript_CleanFloor:: @ 82396B4
	setmaplayoutindex LAYOUT_SKY_PILLAR_5F_CLEAN
	return
	
SkyPillar_5F_EventScript_DUNK::
	trainerbattle_single TRAINER_DUNK, SkyPillar_5F_Text_DUNKIntro, SkyPillar_5F_Text_DUNKDefeat
	msgbox SkyPillar_5F_Text_DUNKPostBattle, MSGBOX_AUTOCLOSE
	end
	
SkyPillar_5F_Text_DUNKIntro: 
	.string "¡Alto ahí! ¡No des un paso más!\p"
	
	.string "Sé lo que has venido a hacer...\p"
	
	.string "Vas a despertar a RAYQUAZA, pero...\n"
	.string "¡ESO ES UNA LOCURA! ¡ABORTA MISIÓN YA!\p"
	
	.string "¡No sabemos que efectos causará si lo\n"
	.string "despertamos para calmar a GROUDON y\l"
	.string "KYOGRE!\p"
	
	.string "...\p"
	
	.string "¿Cambio climático? Que tonterias...$"

SkyPillar_5F_Text_DUNKDefeat: 
	.string "Te lo estoy diciendo: ¡No existe\n"
	.string "el cambio climático! ¡Es todo mentira!$"

SkyPillar_5F_Text_DUNKPostBattle:
	.string "Pero... si despiertas a RAYQUAZA...$"


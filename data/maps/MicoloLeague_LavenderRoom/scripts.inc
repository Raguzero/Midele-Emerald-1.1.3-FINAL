MicoloLeague_LavenderRoom_MapScripts::
    map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MicoloLeague_LavenderRoom_OnWarp
    map_script MAP_SCRIPT_ON_RESUME, MicoloLeague_LavenderRoom_OnResume
	.byte 0

MicoloLeague_LavenderRoom_OnResume:
    compare VAR_TEMP_1, 1

   call_if_eq MicoloLeague_LavenderRoom_AddAudience
   end

MicoloLeague_LavenderRoom_OnWarp:
    map_script_2 VAR_TEMP_0, 0, MicoloLeague_LavenderRoom_AddAudience
    .2byte 0

MicoloLeague_LavenderRoom_AddAudience::
	createvobject EVENT_OBJ_GFX_DRAKE, 9, 1, 5, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_PHOEBE, 10, 3, 6, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_CYNDAQUIL_DOLL, 4, 4, 5, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LINK_RS_BRENDAN, 5, 5, 5, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_TATE, 14, 7, 6, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LIZA, 15, 8, 6, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_FAT_MAN, 8, 8, 4, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_LITTLE_GIRL, 11, 10, 6, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_MEW, 6, 11, 4, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_SCIENTIST_1, 7, 12, 5, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_MAXIE, 12, 14, 6, 3, DIR_SOUTH
	createvobject EVENT_OBJ_GFX_ARCHIE, 13, 15, 5, 3, DIR_SOUTH
	return


MicoloLeague_LavenderRoom_AudienceCheer::
	playse SE_W227B
	turnvobject 9, DIR_EAST
	turnvobject 10, DIR_EAST
	turnvobject 5, DIR_EAST
	turnvobject 14, DIR_WEST
	turnvobject 15, DIR_WEST
	turnvobject 8, DIR_WEST
	turnvobject 11, DIR_WEST
	turnvobject 6, DIR_EAST
	turnvobject 7, DIR_EAST
	turnvobject 12, DIR_EAST
	turnvobject 13, DIR_EAST
	delay 20
	turnvobject 9, DIR_SOUTH
	turnvobject 10, DIR_SOUTH
	turnvobject 5, DIR_SOUTH
	turnvobject 14, DIR_SOUTH
	turnvobject 15, DIR_SOUTH
	turnvobject 8, DIR_SOUTH
	turnvobject 11, DIR_SOUTH
	turnvobject 6, DIR_SOUTH
	turnvobject 7, DIR_SOUTH
	turnvobject 12, DIR_SOUTH
	turnvobject 13, DIR_SOUTH
	delay 20
	turnvobject 9, DIR_WEST
	turnvobject 10, DIR_WEST
	turnvobject 5, DIR_WEST
	turnvobject 14, DIR_EAST
	turnvobject 15, DIR_EAST
	turnvobject 8, DIR_EAST
	turnvobject 11, DIR_EAST
	turnvobject 6, DIR_WEST
	turnvobject 7, DIR_WEST
	turnvobject 12, DIR_WEST
	turnvobject 13, DIR_WEST
	delay 20
	turnvobject 9, DIR_SOUTH
	turnvobject 10, DIR_SOUTH
	turnvobject 5, DIR_SOUTH
	turnvobject 14, DIR_SOUTH
	turnvobject 15, DIR_SOUTH
	turnvobject 8, DIR_SOUTH
	turnvobject 11, DIR_SOUTH
	turnvobject 6, DIR_SOUTH
	turnvobject 7, DIR_SOUTH
	turnvobject 12, DIR_SOUTH
	turnvobject 13, DIR_SOUTH
	waitmovement 0
	return


MicoloLeague_LavenderRoom_Recepcionist::
	lock
	checktrainerflag TRAINER_LAVENDER_MICOLANDIA
	goto_if 1, MicoloLeague_LavenderRoom_Recepcionist_2
	msgbox MicoloLeague_LavenderRoom_Recepcionist_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MicoloLeague_LavenderRoom_Recepcionist_5
	msgbox MicoloLeague_LavenderRoom_Recepcionist_Text_2, MSGBOX_DEFAULT
MicoloLeague_LavenderRoom_Recepcionist_1:
	release
	return

MicoloLeague_LavenderRoom_Recepcionist_2:
	msgbox MicoloLeague_LavenderRoom_Recepcionist_Text_0, MSGBOX_NPC
	goto MicoloLeague_LavenderRoom_Recepcionist_1

MicoloLeague_LavenderRoom_Recepcionist_5:
	closemessage
	goto MicoloLeague_LavenderRoom_FightLavender
	goto MicoloLeague_LavenderRoom_Recepcionist_1


MicoloLeague_LavenderRoom_FightLavender::
	applymovement 2, MicoloLeague_LavenderRoom_Movement_Recepcionist
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, MicoloLeague_LavenderRoom_Movement_PlayerEnters
	waitmovement 0
	msgbox MicoloLeague_LavenderRoom_FightLavender_Text_0, MSGBOX_DEFAULT
	waitmessage
	closemessage
	call MicoloLeague_LavenderRoom_AudienceCheer
	applymovement EVENT_OBJ_ID_PLAYER, MicoloLeague_LavenderRoom_Movement_PlayerGoRing
	waitmovement 0
	applymovement 3, Common_Movement_FaceRight
	waitmovement 0
	msgbox MicoloLeague_LavenderRoom_FightLavender_Text_1, MSGBOX_DEFAULT
	waitmessage
	closemessage
	call MicoloLeague_LavenderRoom_AudienceCheer
	applymovement 1, MicoloLeague_LavenderRoom_Movement_LavenderGoRing
	waitmovement 0
	call MicoloLeague_LavenderRoom_AudienceCheer
    setvar VAR_TEMP_1, 1
	trainerbattle_single TRAINER_LAVENDER_MICOLANDIA, MicoloLeague_LavenderRoom_FightLavender_Text_2, MicoloLeague_LavenderRoom_FightLavender_Text_3, MicoloLeague_LavenderRoom_DefeatedLavender, FALSE
	return


MicoloLeague_LavenderRoom_DefeatedLavender::
	call MicoloLeague_LavenderRoom_AudienceCheer
	msgbox MicoloLeague_LavenderRoom_DefeatedLavender_Text_0, MSGBOX_NPC
	applymovement 1, MicoloLeague_LavenderRoom_Movement_LavenderGoesBack
	waitmovement 0
	setobjectxyperm 2, 4, 15
	release
	return


MicoloLeague_LavenderRoom_Reporter::
	lock
	faceplayer
	msgbox MicoloLeague_LavenderRoom_Reporter_Text_0, MSGBOX_NPC
	release
	return


MicoloLeague_LavenderRoom_Lavender::
	lock
	faceplayer
	msgbox MicoloLeague_LavenderRoom_DefeatedLavender_Text_0, MSGBOX_NPC
	release
	return


MicoloLeague_LavenderRoom_Movement_Recepcionist:
	face_right
	lock_facing_direction
	walk_left
	step_end

MicoloLeague_LavenderRoom_Movement_PlayerEnters:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MicoloLeague_LavenderRoom_Movement_PlayerGoRing:
	walk_right
	walk_right
	step_end

MicoloLeague_LavenderRoom_Movement_LavenderGoRing:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

MicoloLeague_LavenderRoom_Movement_LavenderGoesBack:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

MicoloLeague_LavenderRoom_Recepcionist_Text_0:
	.string "TEXTO DERROTASTE A LAVENDER$"

MicoloLeague_LavenderRoom_Recepcionist_Text_1:
	.string "TEXTO LUCHAR CONTRA LAVENDER?$"

MicoloLeague_LavenderRoom_Recepcionist_Text_2:
	.string "TEXTO VUELVE CUANDO QUIERAS$"

MicoloLeague_LavenderRoom_FightLavender_Text_0:
	.string "TEXTO PRESENTAR A PLAYER$"

MicoloLeague_LavenderRoom_FightLavender_Text_1:
	.string "TEXTO PRESENTAR A LAVENDER$"

MicoloLeague_LavenderRoom_FightLavender_Text_2:
	.string "TEXTO COMBATAMOS$"

MicoloLeague_LavenderRoom_FightLavender_Text_3:
	.string "TEXTO DERROTA$"

MicoloLeague_LavenderRoom_DefeatedLavender_Text_0:
	.string "TEXTO ME DERROTASTE$"

MicoloLeague_LavenderRoom_Reporter_Text_0:
	.string "TEXTO BUEN COMBATE$"


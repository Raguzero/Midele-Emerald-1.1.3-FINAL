MicoloLeague_VaderRoom_MapScripts::
	.byte 0

MicoloLeague_VaderRoom_EventScript_Mew::
    lock
    faceplayer 
    waitse
    playmoncry SPECIES_MEW, 0
    msgbox MicoloLeagueLobby_Text_Mew, MSGBOX_DEFAULT
    waitmoncry
    release
    end

MicoloLeagueLobby_Text_Mew:
    .string "MEW: Meeew...$"

MicoloLeague_VaderRoom_EventScript_Vader::
	lockall
	checktrainerflag TRAINER_AVADER_MICOLANDIA
	goto_if 1, MicoloLeague_VaderRoom_EventScript_Vader_2
	msgbox MicoloLeague_VaderRoom_EventScript_Vader_Text_1, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_AVADER_MICOLANDIA, MicoloLeague_VaderRoom_EventScript_Vader_Text_2
	setflag FLAG_TEMP_1
    removeobject 10
    removeobject 11
MicoloLeague_VaderRoom_EventScript_Vader_1:
	releaseall
	return

MicoloLeague_VaderRoom_EventScript_Vader_2:
	msgbox MicoloLeague_VaderRoom_EventScript_Vader_Text_0, MSGBOX_DEFAULT
	goto MicoloLeague_VaderRoom_EventScript_Vader_1


MicoloLeague_VaderRoom_EventScript_Vader_Text_0:
	.string "TEXTO VADER POSTBATTLE$"

MicoloLeague_VaderRoom_EventScript_Vader_Text_1:
	.string "TEXTO VADER INTRO$"

MicoloLeague_VaderRoom_EventScript_Vader_Text_2:
	.string "TEXTO VADER DEFEAT$"
 

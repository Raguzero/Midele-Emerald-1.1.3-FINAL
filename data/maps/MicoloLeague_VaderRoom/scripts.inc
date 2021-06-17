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
 

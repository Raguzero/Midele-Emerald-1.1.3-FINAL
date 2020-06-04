GraniteCave_B2F_MapScripts:: @ 822DC79
	.byte 0

GraniteCave_B2F_EventScript_Davian::
	trainerbattle_single TRAINER_DAVIAN, GraniteCave_B2F_DavianIntro, GraniteCave_B2F_DavianDefeat
	msgbox GraniteCave_B2F_DavianPostBattle, MSGBOX_AUTOCLOSE
	end
	
GraniteCave_B2F_EventScript_Omari:: 
	trainerbattle_single TRAINER_OMARI, GraniteCave_B2F_OmariIntro, GraniteCave_B2F_OmariDefeat
	msgbox GraniteCave_B2F_OmariPostBattle, MSGBOX_AUTOCLOSE
	end
	
GraniteCave_B2F_DavianIntro: 
	.string "I was headed to the Contest\n"
	.string "Spectacular Hall, but I seem\p"
	.string "to have lost my way.$"
	
GraniteCave_B2F_DavianDefeat: 
	.string "What was that?$"
	
GraniteCave_B2F_DavianPostBattle: 
	.string "I was headed to the Contest\n"
	.string "Spectacular Hall, but I seem\p"
	.string "to have lost my way.$"
	
GraniteCave_B2F_OmariIntro: 
	.string "This mural apparently despicts\n"
	.string "events in ancient Hoenn.$"
	
GraniteCave_B2F_OmariDefeat: 
	.string "I learned a lot from that.$"
	
GraniteCave_B2F_OmariPostBattle: 
	.string "This mural apparently despicts\n"
	.string "events in ancient Hoenn.$"



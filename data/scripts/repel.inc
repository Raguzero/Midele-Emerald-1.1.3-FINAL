EventScript_RepelWoreOff:: @ 82A4B2A
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	end

EventScript_ReuseRepel::
	msgbox Text_AskReuseRepel, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_UseAnotherRepel
	closemessage
	end

EventScript_UseAnotherRepel:
	playse SE_TU_SAA
	waitse
	bufferitemname 0, VAR_LAST_USED_REPEL
	msgbox Text_NewRepelUsed, MSGBOX_SIGN
	removeitem VAR_LAST_USED_REPEL, 1
	special ResetLastRepelSteps
	end

EventScript_RepelWoreOffDarkiMap:: @ 82A4B2A
	msgbox Text_RepelWoreOffDarkiMap, MSGBOX_SIGN
	end

EventScript_ReuseRepelDarkiMap::
	msgbox Text_AskReuseRepelDarkiMap, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_UseAnotherRepelDarkiMap
	closemessage
	end

EventScript_UseAnotherRepelDarkiMap:
	playse SE_TU_SAA
	waitse
	bufferitemname 0, VAR_LAST_USED_REPEL
	msgbox Text_NewRepelUsedDarkiMap, MSGBOX_SIGN
	removeitem VAR_LAST_USED_REPEL, 1
	special ResetLastRepelSteps
	end

Text_RepelWoreOff: @ 82A4B33
	.string "REPEL's effect wore off…$"

Text_AskReuseRepel::
	.string "REPEL's effect wore off…\n"
	.string "Use another REPEL?$"

Text_NewRepelUsed::
	.string "{PLAYER} used a {STR_VAR_1}.$"

Text_RepelWoreOffDarkiMap:
	.string "REPEL's effect wore off…\p"
	
	.string "DARKI: Si quieres llegar hasta mi,\n" 
	.string "pulga, deberás confiar en tu propia\l" 
	.string "fuerza o ¿acaso crees que siempre\l"
	.string "podrás confiar en tus repelentes?\l" 	
	.string "¡MUAJAJAJA!$"

Text_AskReuseRepelDarkiMap::
	.string "REPEL's effect wore off…\p"
	
	.string "DARKI: Si quieres llegar hasta mi,\n" 
	.string "pulga, deberás confiar en tu propia\l" 
	.string "fuerza o ¿acaso crees que siempre\l"
	.string "podrás confiar en tus repelentes?\l" 	
	.string "¡MUAJAJAJA!\p"

	.string "Use another REPEL?$"

Text_NewRepelUsedDarkiMap::
	.string "{PLAYER} used a {STR_VAR_1}.$"

EverGrandeCity_MapScripts:: @ 81E7D1B
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition: @ 81E7D21
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign:: @ 81E7D2B
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign:: @ 81E7D34
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign:: @ 81E7D3D
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end
	
EverGrandeCity_EventScript_Kaisser::
	trainerbattle_single TRAINER_KAISSER, Kaisser_AntesBatalla, Kaisser_MensajeDerrota
	msgbox Kaisser_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end

EverGrandeCity_EventScript_SetVisitedEverGrande:: @ 81E7D46
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end
	
Kaisser_AntesBatalla: 
    .string "Acabo de meterme en el google\n"
	.string "earth para ver si había alguien\l"
	.string "pescando en el pantano, pues hoy hace\l" 
	.string "mucho viento y no me apetecía ir a\l"
	.string "lo tonto.\p"
    
	.string "Hasta que has venido a tocar los\n"
	.string "huevos, así que vamos a luchar, pirata.$"
	
Kaisser_MensajeDerrota: 
    .string "Huehuehue$"
	
Kaisser_DespuesDeBatalla:
    .string "Vendo Opel Corsa.\p"

    .string "Siempre en garje, usado por persona\n"
	.string "mayor.$"

EverGrandeCity_Text_EnteringVictoryRoad: @ 81E7D4F
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague: @ 81E7D65
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign: @ 81E7D89
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"

MonocycleRoute_MapScripts::
	.byte 0
	
Monocycle_Road_Sign::
	msgbox Monocycle_Road_Sign_Text, MSGBOX_SIGN
	end
	
Monocycle_Road_EventScript_Constructor::
	lock
	faceplayer
	msgbox Monocycle_Road_Text_Constructor, MSGBOX_DEFAULT
	release
	end

Monocycle_Road_EventScript_MrZero::
	trainerbattle_single TRAINER_MR_ZERO, MrZero_AntesBatalla, MrZero_MensajeDerrota
	msgbox MrZero_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
Monocycle_Road_EventScript_Zzz::
	trainerbattle_single TRAINER_ZZZ, Zzz_AntesBatalla, Zzz_MensajeDerrota
	msgbox Zzz_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
Monocycle_Road_EventScript_PoisonMastahhhh::
	trainerbattle_single TRAINER_POISONMASTAHHHH, PoisonMastahhhh_AntesBatalla, PoisonMastahhhh_MensajeDerrota
	msgbox PoisonMastahhhh_DespuesDeBatalla, MSGBOX_AUTOCLOSE
	end
	
Monocycle_Road_EventScript_Blue::
	trainerbattle_double TRAINER_BLUE_AND_YELLOW, BlueYellow_AntesBatalla, BlueYellow_MensajeDerrota, Monocycle_Road_Text_BlueNotEnoughMons
	msgbox BlueYellow_DespuesDeBatalla, MSGBOX_DEFAULT
	release
	end
	
Monocycle_Road_EventScript_Yellow::
	trainerbattle_double TRAINER_BLUE_AND_YELLOW, BlueYellow_AntesBatalla, BlueYellow_MensajeDerrota, Monocycle_Road_Text_BlueNotEnoughMons
	msgbox BlueYellow_DespuesDeBatalla, MSGBOX_DEFAULT
	release
	end
	
Monocycle_Road_Sign_Text:
	.string "Monocycle Road: Móntate en el\n"
	.string "ACROCYCLE y usa el B + Dirección\l"
	.string "para atravesar todos los caminos.\p"
	
	.string "Y recuerda: Monociclo, porque\n" 
	.string "mono es uno y la vida es un ciclo.$"
	
BlueYellow_AntesBatalla:
	.string "YELLOW: Gran amiga BLUE, ¿me estás\n"
	.string "oyendo? Oh vamos, BLUE, ¡ahora no te\l"
	.string "hagas la tonta! ¿Recuerdas esa foto en\l"
	.string "la que saliste tan sexy como modelo de\l"
	.string "cierta marca de ropa de cierto\l"
	.string "catalago de moda?\p"
	
	.string "Mi amiga BLUE es modelo, ¿sabes?\n"
	.string "No dejare que se acerque a ella ningun\l"
	.string "baboso ni nadie que pueda hacerle algo\l"
	.string "malo.\p"

	.string "BLUE: Amiga YELLOW se te ve\n"
	.string "euforica, baja un poco de las nubes que\l"
	.string "mi vida privada no tiene porque saberla\l"
	.string "nadie.$"

BlueYellow_MensajeDerrota: 
	.string "YELLOW: Perdón, amiga BLUE.$"  
 
BlueYellow_DespuesDeBatalla:
	.string "BLUE: Conozco de sobra los extremos a\n"
	.string "los que puede llegar un chico, no solo\l"
	.string "las fotos la ropa interior que dejas en\l"
	.string "el cesto de la ropa sucia que\l"
	.string "desaparece, la que puedes dejar\l"
	.string "tendida al sol para que se seque y\l"
	.string "despues encontrarla toda arrugada y\l"
	.string "con una rara mancha que desprende un\l"
	.string "desagradable olor.\p"
	
	.string "YELLOW: ¡Debe ser leche desnatada!$"
	
Monocycle_Road_Text_BlueNotEnoughMons:
	.string "BLUE: Si no tienes dos POKéMON,\n"
	.string "no podemos luchar.\p"
	
	.string "¡Solo aceptamos BATALLAS DOBLES!$"
	
Monocycle_Road_Text_YellowNotEnoughMons:
	.string "YELLOW: Pero si no tienes ni dos\n"
	.string "POKéMON listos para luchar...\p"
	
	.string "¡Solo luchamos BATALLAS DOBLES!$"

MrZero_AntesBatalla: 
	.string "Si te preguntasen si te gusta mas\n" 
	.string "ENTEI, RAIKOU, o SUICUNE,\l"
	.string "¿cuál dirías, tu?\p"
	
	.string "Para mi es ENTEI porque me gustan\n"
	.string "los de tipo PLANTA.$" 

MrZero_MensajeDerrota: 
	.string "¡Pero si ENTEI es de tipo PLANTA!$"  
 
MrZero_DespuesDeBatalla:
	.string "¿No te gustan los de tipo PLANTA\n"
	.string "como ENTEI?\p"
	
	.string "Por cierto, me han dicho que LUGIA\n"
	.string "es de tipo AGUA, ¿es cierto?$"
	
Zzz_AntesBatalla: 
	.string "¡¡¡SENSEI RED KROW!!!\p"
	
	.string "¡¡¡DONDE ESTÁS SENSEI RED KROW!!!\p"

	.string "Eh, tu, ¿has visto a mi sensei\n"
	.string "por aquí?$"

Zzz_MensajeDerrota: 
	.string "¡Que decepción para mi sensei!$"  
 
Zzz_DespuesDeBatalla:
	.string "Mi sensei RED KROW era el único\n"
	.string "que aceptaba todos mis retos\l"
	.string "diarios con mi MONOTIPO NORMAL.\p"
	
	.string "Nadie más.$"
	
PoisonMastahhhh_AntesBatalla: 
	.string "Io creo que el megor monotipaso\n" 
	.string "es el veneno poque tiene al\l" 
	.string "tosicroa ese que se cura cuando\l" 
	.string "le lansan agua y ase mucho daño,\l" 
	.string "tamien tienes al dripiñon que no\l"
	.string "le afestan los atacasos de tierra$"

PoisonMastahhhh_MensajeDerrota: 
	.string "Pero el megor monotipaso...$"  
 
PoisonMastahhhh_DespuesDeBatalla:
	.string "El megor monotipaso es el veneno\n"
	.string "te pongas como te pongas.\p"
	
	.string "Un saludo y muy buen floro.$"

Monocycle_Road_Text_Constructor:
	.string "MICOLO ha pagado a mi empresa\n"
	.string "para que se encargue de construir\l" 
	.string "la mejor carretera de monociclos\l"
	.string "que has visto jamás.\p"
	
	.string "¿Por qué no retas algún GYM mientras\n"
	.string "tanto, para hacer tiempo?$"

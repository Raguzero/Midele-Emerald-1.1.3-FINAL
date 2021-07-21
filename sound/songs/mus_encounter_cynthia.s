@ Created by: WiserVisor
@ Original Source: Pokemon D/P/Pt (Junichi Masuda)
@ MIDI Source: https://www.purezc.net/forums/index.php?showtopic=74076
@ VOICE Legend
@ 0 = voice_keysplit voicegroup005, KeySplitTable1
	.include "MPlayDef.s"

	.equ	mus_encounter_cynthia_grp, voicegroup304
	.equ	mus_encounter_cynthia_pri, 0
	.equ	mus_encounter_cynthia_rev, reverb_set+50
	.equ	mus_encounter_cynthia_mvl, 70
	.equ	mus_encounter_cynthia_key, 0
	.equ	mus_encounter_cynthia_tbs, 1
	.equ	mus_encounter_cynthia_exg, 0
	.equ	mus_encounter_cynthia_cmp, 1

	.section .rodata
	.global	mus_encounter_cynthia
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_encounter_cynthia_1:
	.byte	KEYSH , mus_encounter_cynthia_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 201*mus_encounter_cynthia_tbs/2
	.byte		VOICE , 0
	.byte		PAN   , c_v+32
	.byte		VOL   , 98*mus_encounter_cynthia_mvl/mxv
	.byte	W22
	.byte		N44   , Bn3 , v127
	.byte	W48
	.byte		N44   
	.byte	W24
	.byte	W02
@ 001   ----------------------------------------
	.byte	W24
	.byte		N44   
	.byte	W48
	.byte	W02
	.byte		N36   , As3 
	.byte	W22
@ 002   ----------------------------------------
	.byte	W16
	.byte		N07   , As3 , v040
	.byte	W08
	.byte		        As3 , v112
	.byte	W08
	.byte		        As3 , v040
	.byte	W16
	.byte		        Gn3 , v112
	.byte	W08
	.byte		        Gn3 , v040
	.byte	W16
	.byte		        En3 , v112
	.byte	W08
	.byte		        En3 , v040
	.byte	W16
@ 003   ----------------------------------------
mus_encounter_cynthia_1_003:
	.byte		N07   , Cs3 , v112
	.byte	W08
	.byte		        Cs3 , v040
	.byte	W16
	.byte		        En2 , v112
	.byte	W08
	.byte		        En2 , v040
	.byte	W16
	.byte		        As2 , v112
	.byte	W08
	.byte		        As2 , v040
	.byte	W16
	.byte		        Fs3 , v112
	.byte	W08
	.byte		        Fs3 , v040
	.byte	W16
	.byte	PEND
@ 004   ----------------------------------------
mus_encounter_cynthia_1_004:
	.byte	W24
	.byte		N03   , Bn3 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , As3 
	.byte	W08
	.byte		N36   
	.byte	W16
@ 005   ----------------------------------------
	.byte	W24
	.byte		N03   , Bn3 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   
	.byte	W08
	.byte		N36   
	.byte	W16
@ 006   ----------------------------------------
	.byte	W24
	.byte		N03   , Dn4 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Cs4 
	.byte	W08
	.byte		N36   
	.byte	W16
@ 007   ----------------------------------------
mus_encounter_cynthia_1_007:
	.byte	W24
	.byte		N03   , En4 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Dn4 
	.byte	W08
	.byte		N36   
	.byte	W16
	.byte	PEND
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_1_007
@ 009   ----------------------------------------
	.byte	W24
	.byte		N03   , Dn4 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   
	.byte	W08
	.byte		N36   
	.byte	W16
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_1_007
@ 011   ----------------------------------------
	.byte	W24
	.byte		N03   , Cs4 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Dn4 
	.byte	W08
	.byte		N36   
	.byte	W16
@ 012   ----------------------------------------
	.byte	W24
	.byte		N03   , Cs4 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   
	.byte	W08
	.byte		N36   
	.byte	W16
@ 013   ----------------------------------------
	.byte	W24
	.byte		N03   , As3 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   
	.byte	W08
	.byte		N36   
	.byte	W16
@ 014   ----------------------------------------
mus_encounter_cynthia_1_014:
	.byte	W24
	.byte		N03   , Fs3 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   
	.byte	W08
	.byte		N36   
	.byte	W16
	.byte	PEND
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_1_014
@ 016   ----------------------------------------
	.byte	W40
	.byte		N07   , Gn3 , v112
	.byte	W08
	.byte		        Gn3 , v040
	.byte	W16
	.byte		        Fs3 , v112
	.byte	W08
	.byte		        Fs3 , v040
	.byte	W16
	.byte		        En3 , v112
	.byte	W08
@ 017   ----------------------------------------
mus_encounter_cynthia_1_017:
	.byte		N07   , En3 , v040
	.byte	W16
	.byte		        Dn3 , v112
	.byte	W08
	.byte		        Dn3 , v040
	.byte	W16
	.byte		        Cs3 , v112
	.byte	W08
	.byte		        Cs3 , v040
	.byte	W16
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Bn2 , v040
	.byte	W16
	.byte		        As2 , v112
	.byte	W08
	.byte	PEND
@ 018   ----------------------------------------
	.byte		        As2 , v040
	.byte	W16
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Bn2 , v040
	.byte	W16
	.byte		        Cs3 , v112
	.byte	W08
	.byte		N03   , Dn3 , v116
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , As3 
	.byte	W24
@ 019   ----------------------------------------
	.byte		N07   , As3 , v040
	.byte	W40
	.byte		        Gn3 , v112
	.byte	W08
	.byte		        Gn3 , v040
	.byte	W16
	.byte		        Fs3 , v112
	.byte	W08
	.byte		        Fs3 , v040
	.byte	W16
	.byte		        En3 , v112
	.byte	W08
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_1_017
@ 021   ----------------------------------------
	.byte		N07   , As2 , v040
	.byte	W16
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Bn2 , v040
	.byte	W16
	.byte		        Cs3 , v112
	.byte	W08
	.byte		        Cs3 , v040
	.byte	W16
	.byte		        Dn3 , v112
	.byte	W08
	.byte		        Dn3 , v040
	.byte	W16
	.byte		        En3 , v112
	.byte	W08
@ 022   ----------------------------------------
	.byte		N03   , Dn3 , v116
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , Cs3 
	.byte	W24
	.byte		N03   , An3 
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , Gs3 
	.byte	W24
@ 023   ----------------------------------------
	.byte		PAN   , c_v-18
	.byte		N03   , Dn4 
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , Cs4 
	.byte	W24
	.byte		        Dn3 , v112
	.byte	W24
	.byte		        As2 
	.byte	W24
@ 024   ----------------------------------------
	.byte		PAN   , c_v+35
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W24
	.byte		N07   , As3 
	.byte	W08
	.byte		        As3 , v040
	.byte	W16
	.byte		        Gn3 , v112
	.byte	W08
	.byte		        Gn3 , v040
	.byte	W16
	.byte		        En3 , v112
	.byte	W08
	.byte		        En3 , v040
	.byte	W16
@ 033   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_1_003
@ 034   ----------------------------------------
	.byte	GOTO
	.word	mus_encounter_cynthia_1_004
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

mus_encounter_cynthia_2:
	.byte	KEYSH , mus_encounter_cynthia_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		VOL   , 127*mus_encounter_cynthia_mvl/mxv
	.byte		PAN   , c_v+12
	.byte	W22
	.byte		N44   , Fs4 , v127
	.byte	W48
	.byte	W02
	.byte		        Gn4 
	.byte	W24
@ 001   ----------------------------------------
	.byte	W24
	.byte		        Fn4 
	.byte	W48
	.byte		N23   , Fs4 
	.byte	W24
@ 002   ----------------------------------------
	.byte	W24
	.byte		N07   , En5 , v112
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
@ 003   ----------------------------------------
	.byte		        En4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
@ 004   ----------------------------------------
mus_encounter_cynthia_2_004:
	.byte	W24
	.byte		N03   , Dn4 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Cs4 
	.byte	W08
	.byte		N36   
	.byte	W16
	.byte	PEND
@ 005   ----------------------------------------
	.byte	W24
	.byte		N03   , En4 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Dn4 
	.byte	W08
	.byte		N36   
	.byte	W16
@ 006   ----------------------------------------
mus_encounter_cynthia_2_006:
	.byte	W24
	.byte		N03   , Fs4 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , En4 
	.byte	W08
	.byte		N36   
	.byte	W16
	.byte	PEND
@ 007   ----------------------------------------
mus_encounter_cynthia_2_007:
	.byte	W24
	.byte		N03   , Gn4 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Fs4 
	.byte	W08
	.byte		N36   
	.byte	W16
	.byte	PEND
@ 008   ----------------------------------------
	.byte	W24
	.byte		N03   , An4 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Gn4 
	.byte	W08
	.byte		N36   
	.byte	W16
@ 009   ----------------------------------------
	.byte	W24
	.byte		N03   , Fs4 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Gn4 
	.byte	W08
	.byte		N36   
	.byte	W16
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_2_007
@ 011   ----------------------------------------
	.byte	W24
	.byte		N03   , Fn4 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Fs4 
	.byte	W08
	.byte		N36   
	.byte	W16
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_2_006
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_2_004
@ 014   ----------------------------------------
	.byte	W24
	.byte		N03   , Bn3 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , As3 
	.byte	W08
	.byte		N36   
	.byte	W16
@ 015   ----------------------------------------
	.byte	W24
	.byte		N03   , Cs4 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Bn3 
	.byte	W08
	.byte		N36   
	.byte	W16
@ 016   ----------------------------------------
	.byte	W24
	.byte		N07   , Fs5 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
@ 017   ----------------------------------------
	.byte		        Fs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
@ 018   ----------------------------------------
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W07
	.byte		        Dn4 
	.byte	W08
	.byte		        Cs4 , v116
	.byte	W09
	.byte		N03   , Bn3 
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , Fs4 
	.byte	W24
@ 019   ----------------------------------------
	.byte	W24
	.byte		N07   , Fs3 , v112
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
@ 020   ----------------------------------------
	.byte		        Fs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
@ 021   ----------------------------------------
	.byte		        Fs4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        As4 
	.byte	W07
	.byte		        Cs5 
	.byte	W08
	.byte		        En4 , v116
	.byte	W09
	.byte		        Fs4 , v112
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
@ 022   ----------------------------------------
	.byte		N03   , Bn3 , v116
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , As3 
	.byte	W24
	.byte		N03   , Fs4 
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , Fn4 
	.byte	W24
@ 023   ----------------------------------------
	.byte		N03   , Bn4 
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , As4 
	.byte	W24
	.byte		N07   , Fs4 , v112
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
@ 024   ----------------------------------------
	.byte		PAN   , c_v+8
	.byte		N07   , Dn4 
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Gn3 
	.byte	W08
@ 025   ----------------------------------------
	.byte		        En4 , v112
	.byte	W08
	.byte		        Cs4 , v076
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		        Cs4 , v076
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W08
@ 026   ----------------------------------------
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As3 , v112
	.byte	W08
	.byte		        En3 , v080
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As3 , v112
	.byte	W08
	.byte		        En3 , v080
	.byte	W08
	.byte		        Cs3 
	.byte	W08
@ 027   ----------------------------------------
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v076
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W08
@ 028   ----------------------------------------
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		        Cs4 , v080
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W04
	.byte		        Gn3 , v080
	.byte	W12
	.byte		        Fs3 
	.byte	W08
@ 029   ----------------------------------------
	.byte		        Fs4 , v112
	.byte	W08
	.byte		        Cs4 , v080
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Fs4 , v112
	.byte	W08
	.byte		        Cs4 , v080
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Bn3 , v076
	.byte	W08
	.byte		        Fs3 
	.byte	W08
@ 030   ----------------------------------------
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		        As3 , v080
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Gn3 , v080
	.byte	W08
	.byte		        En3 
	.byte	W08
@ 031   ----------------------------------------
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W08
@ 032   ----------------------------------------
	.byte	W24
	.byte		        Fs4 , v112
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
@ 033   ----------------------------------------
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
@ 034   ----------------------------------------
	.byte	GOTO
	.word	mus_encounter_cynthia_2_004
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

mus_encounter_cynthia_3:
	.byte	KEYSH , mus_encounter_cynthia_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		VOL   , 111*mus_encounter_cynthia_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N07   , Fs1 , v116
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N23   , Fs1 , v127
	.byte	W24
	.byte		N07   , Fn1 , v116
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N23   , Fn1 , v127
	.byte	W24
@ 001   ----------------------------------------
	.byte		N07   , Cs1 , v116
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N23   , Cs1 , v127
	.byte	W24
	.byte		N07   , Fs1 , v116
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N23   , Fs1 , v127
	.byte	W24
@ 002   ----------------------------------------
	.byte		PAN   , c_v+32
	.byte		N92   , Fs1 , v112
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
mus_encounter_cynthia_3_004:
	.byte		PAN   , c_v+26
	.byte		N07   , Bn1 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn3 , v127
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Bn1 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 , v127
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
@ 005   ----------------------------------------
mus_encounter_cynthia_3_005:
	.byte		N07   , Bn1 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 , v127
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Bn1 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn3 , v127
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte	PEND
@ 006   ----------------------------------------
mus_encounter_cynthia_3_006:
	.byte		N07   , Bn1 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn3 , v127
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Bn1 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 , v127
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte	PEND
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_3_005
@ 008   ----------------------------------------
	.byte		N07   , En2 , v127
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Gn3 , v127
	.byte	W08
	.byte		        En3 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En2 , v127
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fs3 , v127
	.byte	W08
	.byte		        En3 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
@ 009   ----------------------------------------
	.byte		        En2 , v127
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 , v127
	.byte	W08
	.byte		        En3 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En2 , v127
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Gn3 , v127
	.byte	W08
	.byte		        En3 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
@ 010   ----------------------------------------
	.byte		        Bn1 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn3 , v127
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Bn1 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 , v127
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_3_006
@ 012   ----------------------------------------
	.byte		N07   , Fs1 , v127
	.byte	W08
	.byte		        Cs2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        As2 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Fs1 , v127
	.byte	W08
	.byte		        Cs2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Bn2 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Cs2 
	.byte	W08
@ 013   ----------------------------------------
	.byte		        Fs1 , v127
	.byte	W08
	.byte		        Cs2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        As2 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Fs1 , v127
	.byte	W08
	.byte		        Cs2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Cs3 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Cs2 
	.byte	W08
@ 014   ----------------------------------------
	.byte		        Bn1 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn3 , v127
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Bn1 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 , v127
	.byte	W08
	.byte		        As2 , v112
	.byte	W08
	.byte		        Fs2 
	.byte	W08
@ 015   ----------------------------------------
	.byte		        Bn1 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 , v127
	.byte	W10
	.byte		        Bn2 , v112
	.byte	W06
	.byte		        Fs2 
	.byte	W08
	.byte		        Bn1 , v127
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn3 , v127
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Fs2 , v112
	.byte	W08
@ 016   ----------------------------------------
	.byte		VOL   , 127*mus_encounter_cynthia_mvl/mxv
	.byte		N03   , Fs1 
	.byte	W08
	.byte		N84   , Fs1 , v127
	.byte	W88
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte	W48
	.byte		N07   , Gn1 , v116
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N23   , Fs1 
	.byte	W24
@ 019   ----------------------------------------
	.byte		N03   , Fs1 , v112
	.byte	W08
	.byte		N84   , Fs1 , v127
	.byte	W88
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
	.byte		N07   , Gn1 , v116
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N23   , Fs1 
	.byte	W24
	.byte		N07   , Dn2 
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N23   , Cs2 
	.byte	W24
@ 023   ----------------------------------------
	.byte		N07   , Gn2 
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N23   , Fs2 
	.byte	W72
@ 024   ----------------------------------------
	.byte		PAN   , c_v-20
	.byte		BEND  , c_v+0
	.byte		N07   , Bn1 , v112
	.byte	W08
	.byte		        Fs2 , v080
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 , v112
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Gn2 , v080
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn3 , v112
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte		        Gn2 
	.byte	W08
@ 025   ----------------------------------------
mus_encounter_cynthia_3_025:
	.byte		N07   , As1 , v112
	.byte	W08
	.byte		        En2 , v080
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        As2 , v080
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs2 , v080
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 , v112
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte	PEND
@ 026   ----------------------------------------
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Cs2 , v080
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Gn2 , v112
	.byte	W08
	.byte		        Fs2 , v080
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Cs2 , v080
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        As2 , v112
	.byte	W08
	.byte		        Fs2 , v080
	.byte	W08
	.byte		        Cs2 
	.byte	W08
@ 027   ----------------------------------------
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs2 , v080
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 , v112
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs2 , v080
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 , v112
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte		        Fs2 
	.byte	W08
@ 028   ----------------------------------------
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs2 , v076
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 , v112
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Cs2 , v112
	.byte	W08
	.byte		        Gn2 , v080
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 , v112
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte		        Gn2 
	.byte	W08
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_3_025
@ 030   ----------------------------------------
	.byte		N07   , Fs1 , v112
	.byte	W08
	.byte		        Cs2 , v076
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Gn2 , v112
	.byte	W08
	.byte		        Fs2 , v080
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Cs2 , v080
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        As2 , v112
	.byte	W08
	.byte		        Fs2 , v080
	.byte	W08
	.byte		        Cs2 
	.byte	W08
@ 031   ----------------------------------------
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs2 , v076
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 , v112
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs2 , v080
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Cs3 , v112
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte		        Fs2 
	.byte	W08
@ 032   ----------------------------------------
	.byte		PAN   , c_v-18
	.byte		N92   , Fs1 , v112
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	GOTO
	.word	mus_encounter_cynthia_3_004
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

mus_encounter_cynthia_4:
	.byte	KEYSH , mus_encounter_cynthia_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		PAN   , c_v-32
	.byte		VOL   , 127*mus_encounter_cynthia_mvl/mxv
	.byte		N07   , Fs0 , v127
	.byte	W08
	.byte		        Fs0 , v116
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N23   , Fs0 , v127
	.byte	W24
	.byte		N07   , Fn0 
	.byte	W08
	.byte		        Fn0 , v116
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N21   , Fn0 , v127
	.byte	W24
@ 001   ----------------------------------------
	.byte	W48
	.byte		N07   , Fs0 
	.byte	W08
	.byte		        Fs0 , v116
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N23   , Fs0 , v127
	.byte	W24
@ 002   ----------------------------------------
	.byte		PAN   , c_v-32
	.byte		N92   , Fs0 , v120
	.byte	W96
@ 003   ----------------------------------------
	.byte		VOL   , 111*mus_encounter_cynthia_mvl/mxv
	.byte	W96
@ 004   ----------------------------------------
mus_encounter_cynthia_4_004:
	.byte		PAN   , c_v-13
	.byte		N07   , Bn0 , v127
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Dn2 , v127
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Bn0 , v127
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Cs2 , v127
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
@ 005   ----------------------------------------
mus_encounter_cynthia_4_005:
	.byte		N07   , Bn0 , v127
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        En2 , v127
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Bn0 , v127
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Dn2 , v127
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte	PEND
@ 006   ----------------------------------------
mus_encounter_cynthia_4_006:
	.byte		N07   , Bn0 , v127
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Dn2 , v127
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Bn0 , v127
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Cs2 , v127
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte	PEND
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_4_005
@ 008   ----------------------------------------
	.byte		N07   , En1 , v127
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Gn2 , v127
	.byte	W08
	.byte		        En2 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        En1 , v127
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Fs2 , v127
	.byte	W08
	.byte		        En2 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
@ 009   ----------------------------------------
	.byte		        En1 , v127
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        An2 , v127
	.byte	W08
	.byte		        En2 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        En1 , v127
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Gn2 , v127
	.byte	W08
	.byte		        En2 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
@ 010   ----------------------------------------
	.byte		        Bn0 , v127
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Dn2 , v127
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Bn0 , v127
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        En2 , v127
	.byte	W08
	.byte		        Bn1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_4_006
@ 012   ----------------------------------------
	.byte		N07   , Fs0 , v127
	.byte	W08
	.byte		        Cs1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        As1 , v127
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Fs0 , v127
	.byte	W08
	.byte		        Cs1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Bn1 , v127
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Cs1 
	.byte	W08
@ 013   ----------------------------------------
	.byte		        Fs0 , v127
	.byte	W08
	.byte		        Cs1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        As1 , v127
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Fs0 , v127
	.byte	W08
	.byte		        Cs1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        As1 , v127
	.byte	W08
	.byte		        Fs1 , v112
	.byte	W08
	.byte		        Cs1 
	.byte	W08
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_4_006
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_4_005
@ 016   ----------------------------------------
	.byte		VOL   , 127*mus_encounter_cynthia_mvl/mxv
	.byte		N03   , Fs0 , v112
	.byte	W08
	.byte		N84   , Fs0 , v124
	.byte	W88
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte	W44
	.byte	W02
	.byte		N07   , Gn0 , v116
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W10
	.byte		N23   , Fs0 
	.byte	W24
@ 019   ----------------------------------------
	.byte		N03   , Fs0 , v112
	.byte	W08
	.byte		N84   , Fs0 , v124
	.byte	W88
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W92
	.byte	W02
	.byte		N07   , Gn0 , v116
	.byte	W02
@ 022   ----------------------------------------
	.byte	W06
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W10
	.byte		N21   , Fs0 
	.byte	W22
	.byte		N07   , Dn1 
	.byte	W08
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W10
	.byte		N23   , Cs1 
	.byte	W22
	.byte		N07   , Gn1 
	.byte	W02
@ 023   ----------------------------------------
	.byte	W06
	.byte		N07   
	.byte	W08
	.byte		N07   
	.byte	W10
	.byte		N23   , Fs1 
	.byte	W72
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte		PAN   , c_v-38
	.byte		N92   , Fs0 , v112
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	GOTO
	.word	mus_encounter_cynthia_4_004
	.byte	FINE

@**************** Track 5 (Midi-Chn.5) ****************@

mus_encounter_cynthia_5:
	.byte	KEYSH , mus_encounter_cynthia_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		PAN   , c_v-32
	.byte		VOL   , 98*mus_encounter_cynthia_mvl/mxv
	.byte	W22
	.byte		N44   , Fs3 , v127
	.byte	W48
	.byte		        Gn3 
	.byte	W24
	.byte	W02
@ 001   ----------------------------------------
	.byte	W24
	.byte		        Fn3 
	.byte	W48
	.byte		N36   , Fs3 
	.byte	W24
@ 002   ----------------------------------------
	.byte	W16
	.byte		N07   , Fs3 , v040
	.byte	W08
	.byte		        Fs3 , v112
	.byte	W08
	.byte		        Fs3 , v040
	.byte	W16
	.byte		        En3 , v112
	.byte	W08
	.byte		        En3 , v040
	.byte	W16
	.byte		        Cs3 , v112
	.byte	W08
	.byte		        Cs3 , v040
	.byte	W16
@ 003   ----------------------------------------
mus_encounter_cynthia_5_003:
	.byte		N07   , As2 , v112
	.byte	W08
	.byte		        As2 , v040
	.byte	W16
	.byte		        Cs2 , v112
	.byte	W08
	.byte		        Cs2 , v040
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte		        Fs2 , v040
	.byte	W16
	.byte		        As2 , v112
	.byte	W08
	.byte		        As2 , v040
	.byte	W16
	.byte	PEND
@ 004   ----------------------------------------
mus_encounter_cynthia_5_004:
	.byte	W24
	.byte		N03   , Fs3 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   
	.byte	W08
	.byte		N36   
	.byte	W16
	.byte	PEND
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_5_004
@ 006   ----------------------------------------
mus_encounter_cynthia_5_006:
	.byte	W24
	.byte		N03   , Bn3 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   
	.byte	W08
	.byte		N36   
	.byte	W16
	.byte	PEND
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_5_006
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_5_006
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_5_006
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_5_006
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_5_006
@ 012   ----------------------------------------
	.byte	W24
	.byte		N03   , As3 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   
	.byte	W08
	.byte		N36   
	.byte	W16
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_5_004
@ 014   ----------------------------------------
	.byte	W22
	.byte		N03   , Bn2 , v112
	.byte	W08
	.byte		N36   
	.byte	W42
	.byte		N03   , As2 
	.byte	W08
	.byte		N36   
	.byte	W16
@ 015   ----------------------------------------
	.byte	W24
	.byte		N03   , En3 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N01   , Bn2 
	.byte	W08
	.byte		N15   
	.byte	W16
@ 016   ----------------------------------------
	.byte	W40
	.byte		N07   , En3 
	.byte	W08
	.byte		        En3 , v040
	.byte	W16
	.byte		        Dn3 , v112
	.byte	W08
	.byte		        Dn3 , v040
	.byte	W16
	.byte		        Cs3 , v112
	.byte	W08
@ 017   ----------------------------------------
mus_encounter_cynthia_5_017:
	.byte		N07   , Cs3 , v040
	.byte	W16
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Bn2 , v040
	.byte	W16
	.byte		        As2 , v112
	.byte	W08
	.byte		        As2 , v040
	.byte	W16
	.byte		        Gn2 , v112
	.byte	W08
	.byte		        Gn2 , v040
	.byte	W16
	.byte		        Fs2 , v112
	.byte	W08
	.byte	PEND
@ 018   ----------------------------------------
	.byte		        Fs2 , v040
	.byte	W16
	.byte		        Gn2 , v112
	.byte	W08
	.byte		        Gn2 , v040
	.byte	W16
	.byte		        As2 , v112
	.byte	W08
	.byte		N03   , Bn2 , v116
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , Fs3 
	.byte	W24
@ 019   ----------------------------------------
	.byte		N07   , Fs3 , v040
	.byte	W40
	.byte		        En3 , v112
	.byte	W08
	.byte		        En3 , v040
	.byte	W16
	.byte		        Dn3 , v112
	.byte	W08
	.byte		        Dn3 , v040
	.byte	W16
	.byte		        Cs3 , v112
	.byte	W08
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_5_017
@ 021   ----------------------------------------
	.byte		N07   , Fs2 , v040
	.byte	W16
	.byte		        Gn2 , v112
	.byte	W08
	.byte		        Gn2 , v040
	.byte	W16
	.byte		        As2 , v112
	.byte	W08
	.byte		        As2 , v040
	.byte	W16
	.byte		        Bn2 , v112
	.byte	W08
	.byte		        Bn2 , v040
	.byte	W16
	.byte		        Cs3 , v112
	.byte	W08
@ 022   ----------------------------------------
	.byte		N03   , Bn2 , v116
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , As2 
	.byte	W24
	.byte		N03   , Fs3 
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , Fn3 
	.byte	W24
@ 023   ----------------------------------------
	.byte		PAN   , c_v-34
	.byte		N03   , Bn3 
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , As3 
	.byte	W24
	.byte		        Bn2 , v112
	.byte	W24
	.byte		        Fs2 
	.byte	W24
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W24
	.byte		N07   , Fs3 
	.byte	W08
	.byte		        Fs3 , v040
	.byte	W16
	.byte		        En3 , v112
	.byte	W08
	.byte		        En3 , v040
	.byte	W16
	.byte		        Cs3 , v112
	.byte	W08
	.byte		        Cs3 , v040
	.byte	W16
@ 033   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_5_003
@ 034   ----------------------------------------
	.byte	GOTO
	.word	mus_encounter_cynthia_5_004
	.byte	FINE

@**************** Track 6 (Midi-Chn.6) ****************@

mus_encounter_cynthia_6:
	.byte	KEYSH , mus_encounter_cynthia_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		VOL   , 98*mus_encounter_cynthia_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W24
	.byte		N44   , Dn4 , v127
	.byte	W48
	.byte		N44   
	.byte	W24
@ 001   ----------------------------------------
	.byte	W24
	.byte		        Cs4 
	.byte	W48
	.byte	W02
	.byte		        Dn4 
	.byte	W22
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
mus_encounter_cynthia_6_004:
	.byte		PAN   , c_v-32
	.byte	W24
	.byte		N03   , Cs4 , v112
	.byte	W08
	.byte		N36   
	.byte	W64
@ 005   ----------------------------------------
mus_encounter_cynthia_6_005:
	.byte	W24
	.byte		N03   , Cs4 , v112
	.byte	W08
	.byte		N36   
	.byte	W64
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_6_005
@ 007   ----------------------------------------
mus_encounter_cynthia_6_007:
	.byte	W24
	.byte		N03   , Cs4 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   
	.byte	W08
	.byte		N36   
	.byte	W16
	.byte	PEND
@ 008   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_6_007
@ 009   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_6_007
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_6_007
@ 011   ----------------------------------------
	.byte	W72
	.byte		N03   , Cs4 , v112
	.byte	W08
	.byte		N36   
	.byte	W16
@ 012   ----------------------------------------
	.byte	W24
	.byte		N03   , Gn3 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   
	.byte	W08
	.byte		N36   
	.byte	W16
@ 013   ----------------------------------------
	.byte	W24
	.byte		N03   , Cs4 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Gn3 
	.byte	W08
	.byte		N36   
	.byte	W16
@ 014   ----------------------------------------
mus_encounter_cynthia_6_014:
	.byte	W24
	.byte		N03   , Dn3 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   
	.byte	W08
	.byte		N36   
	.byte	W16
	.byte	PEND
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_6_014
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte	W54
	.byte		N03   , Gn2 , v116
	.byte	W08
	.byte		N03   
	.byte	W10
	.byte		N23   , Cs4 
	.byte	W24
@ 019   ----------------------------------------
	.byte		N01   , Fs2 , v112
	.byte	W08
	.byte		N84   
	.byte	W88
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W92
	.byte	W02
	.byte		N03   , Gn2 , v116
	.byte	W02
@ 022   ----------------------------------------
	.byte	W06
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W10
	.byte		N21   , En3 
	.byte	W22
	.byte		N03   , Dn3 
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W10
	.byte		N23   , Bn3 
	.byte	W22
	.byte		N03   , Gn3 
	.byte	W02
@ 023   ----------------------------------------
	.byte	W06
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W10
	.byte		N23   , En4 
	.byte	W72
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	GOTO
	.word	mus_encounter_cynthia_6_004
	.byte	FINE

@**************** Track 7 (Midi-Chn.7) ****************@

mus_encounter_cynthia_7:
	.byte	KEYSH , mus_encounter_cynthia_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		VOL   , 111*mus_encounter_cynthia_mvl/mxv
	.byte		PAN   , c_v-14
	.byte	W24
	.byte		N44   , En4 , v127
	.byte	W48
	.byte		N44   
	.byte	W24
@ 001   ----------------------------------------
	.byte	W24
	.byte		        Dn4 
	.byte	W48
	.byte	W02
	.byte		N40   , En4 
	.byte	W22
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
mus_encounter_cynthia_7_004:
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte		PAN   , c_v-32
	.byte		VOL   , 98*mus_encounter_cynthia_mvl/mxv
	.byte		N01   , Fs2 , v112
	.byte	W08
	.byte		N84   
	.byte	W88
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
	.byte	W96
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
	.byte	W96
@ 023   ----------------------------------------
	.byte	W96
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	GOTO
	.word	mus_encounter_cynthia_7_004
	.byte	FINE

@**************** Track 8 (Midi-Chn.8) ****************@

mus_encounter_cynthia_8:
	.byte	KEYSH , mus_encounter_cynthia_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		PAN   , c_v-7
	.byte		VOL   , 66*mus_encounter_cynthia_mvl/mxv
	.byte	W24
	.byte	W02
	.byte		N44   , Fs4 , v127
	.byte	W48
	.byte	W02
	.byte		        Gn4 
	.byte	W20
@ 001   ----------------------------------------
	.byte	W28
	.byte		        Fn4 
	.byte	W48
	.byte		N23   , Fs4 
	.byte	W20
@ 002   ----------------------------------------
	.byte	W28
	.byte		N07   , En5 , v112
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W04
@ 003   ----------------------------------------
	.byte	W04
	.byte		        En4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N03   , As3 
	.byte	W04
@ 004   ----------------------------------------
mus_encounter_cynthia_8_004:
	.byte	W28
	.byte		N03   , Dn4 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Cs4 
	.byte	W08
	.byte		N36   
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
	.byte	W28
	.byte		N03   , En4 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Dn4 
	.byte	W08
	.byte		N36   
	.byte	W12
@ 006   ----------------------------------------
mus_encounter_cynthia_8_006:
	.byte	W28
	.byte		N03   , Fs4 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , En4 
	.byte	W08
	.byte		N36   
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
mus_encounter_cynthia_8_007:
	.byte	W28
	.byte		N03   , Gn4 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Fs4 
	.byte	W08
	.byte		N36   
	.byte	W12
	.byte	PEND
@ 008   ----------------------------------------
	.byte	W28
	.byte		N03   , An4 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Gn4 
	.byte	W08
	.byte		N36   
	.byte	W12
@ 009   ----------------------------------------
	.byte	W28
	.byte		N03   , Fs4 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Gn4 
	.byte	W08
	.byte		N36   
	.byte	W12
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_8_007
@ 011   ----------------------------------------
	.byte	W28
	.byte		N03   , Fn4 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Fs4 
	.byte	W08
	.byte		N36   
	.byte	W12
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_8_006
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_encounter_cynthia_8_004
@ 014   ----------------------------------------
	.byte	W28
	.byte		N03   , Bn3 , v112
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , As3 
	.byte	W08
	.byte		N36   
	.byte	W12
@ 015   ----------------------------------------
	.byte	W28
	.byte		N03   , Cs4 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N03   , Bn3 
	.byte	W08
	.byte		N36   
	.byte	W12
@ 016   ----------------------------------------
	.byte	W28
	.byte		N07   , Fs5 
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W04
@ 017   ----------------------------------------
	.byte	W04
	.byte		        Fs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Gn4 
	.byte	W04
@ 018   ----------------------------------------
	.byte	W04
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W07
	.byte		        Dn4 
	.byte	W08
	.byte		        Cs4 , v116
	.byte	W09
	.byte		N03   , Bn3 
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , Fs4 
	.byte	W20
@ 019   ----------------------------------------
	.byte	W28
	.byte		N07   , Fs3 , v112
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W04
@ 020   ----------------------------------------
	.byte	W04
	.byte		        Fs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Gn4 
	.byte	W04
@ 021   ----------------------------------------
	.byte	W04
	.byte		        Fs4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        As4 
	.byte	W07
	.byte		        Cs5 
	.byte	W08
	.byte		        En4 , v116
	.byte	W09
	.byte		        Fs4 , v112
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        As3 
	.byte	W04
@ 022   ----------------------------------------
	.byte	W04
	.byte		N03   , Bn3 , v116
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , As3 
	.byte	W24
	.byte		N03   , Fs4 
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , Fn4 
	.byte	W20
@ 023   ----------------------------------------
	.byte	W04
	.byte		N03   , Bn4 
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N03   
	.byte	W08
	.byte		N23   , As4 
	.byte	W24
	.byte		N07   , Fs4 , v112
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs3 
	.byte	W04
@ 024   ----------------------------------------
	.byte		PAN   , c_v+32
	.byte	W04
	.byte		N07   , Dn4 
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Gn3 
	.byte	W04
@ 025   ----------------------------------------
	.byte	W04
	.byte		        En4 , v112
	.byte	W08
	.byte		        Cs4 , v076
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		        Cs4 , v076
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W04
@ 026   ----------------------------------------
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As3 , v112
	.byte	W08
	.byte		        En3 , v080
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As3 , v112
	.byte	W08
	.byte		        En3 , v080
	.byte	W08
	.byte		        Cs3 
	.byte	W04
@ 027   ----------------------------------------
	.byte	W04
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v076
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W04
@ 028   ----------------------------------------
	.byte	W04
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		        Cs4 , v080
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Gn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W04
@ 029   ----------------------------------------
	.byte	W04
	.byte		        Fs4 , v112
	.byte	W08
	.byte		        Cs4 , v080
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Fs4 , v112
	.byte	W08
	.byte		        Cs4 , v080
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		        Bn3 , v080
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Dn4 , v112
	.byte	W08
	.byte		        Bn3 , v076
	.byte	W08
	.byte		        Fs3 
	.byte	W04
@ 030   ----------------------------------------
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        As3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		        As3 , v080
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Gn3 , v080
	.byte	W08
	.byte		        En3 
	.byte	W04
@ 031   ----------------------------------------
	.byte	W04
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Cs4 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn3 , v112
	.byte	W08
	.byte		        Fs3 , v080
	.byte	W08
	.byte		        Dn3 
	.byte	W04
@ 032   ----------------------------------------
	.byte	W28
	.byte		        Fs4 , v112
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W04
@ 033   ----------------------------------------
	.byte	W04
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N03   , As3 
	.byte	W04
@ 034   ----------------------------------------
	.byte	GOTO
	.word	mus_encounter_cynthia_8_004
	.byte	FINE

@******************************************************@
	.align	2

mus_encounter_cynthia:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_encounter_cynthia_pri	@ Priority
	.byte	mus_encounter_cynthia_rev	@ Reverb.

	.word	mus_encounter_cynthia_grp

	.word	mus_encounter_cynthia_1
	.word	mus_encounter_cynthia_2
	.word	mus_encounter_cynthia_3
	.word	mus_encounter_cynthia_4
	.word	mus_encounter_cynthia_5
	.word	mus_encounter_cynthia_6
	.word	mus_encounter_cynthia_7
	.word	mus_encounter_cynthia_8

	.end

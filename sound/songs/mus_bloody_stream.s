@ Created by: WiserVisor
@ Original Source: JoJos Bizzare Adventure (Coda)
@ MIDI Source: https://www.youtube.com/watch?v=M08-nkD18jA&t=0s
@ VOICE Legend
@ 17 = voice_directsound 60, 0, DirectSoundWaveData_sc88pro_organ2, 255, 0, 255, 165
@ 29 = voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_overdrive_guitar, 128, 0, 255, 214
@ 34 = voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fingered_bass, 255, 253, 0, 149
@ 36 = voice_directsound 60, 0, DirectSoundWaveData_jv1080_slap_bass, 255, 235, 128, 99
@ 48 = voice_keysplit voicegroup006, KeySplitTable2
@ 56 = voice_keysplit voicegroup007, KeySplitTable3 
@ 60 = voice_keysplit voicegroup009, KeySplitTable5
@ 65 = voice_directsound 60, 0, altosax72, 255, 0, 193, 127
@ 96 = voice_keysplit_all voicegroup002 (also put voice_directsound 60, 0, ridecymbal, 255, 235, 0, 165 as the 16th instrument in voicegroup002)
	.include "MPlayDef.s"

	.equ	mus_bloody_stream_grp, voicegroup303
	.equ	mus_bloody_stream_pri, 0
	.equ	mus_bloody_stream_rev, 0
	.equ	mus_bloody_stream_mvl, 77
	.equ	mus_bloody_stream_key, 0
	.equ	mus_bloody_stream_tbs, 1
	.equ	mus_bloody_stream_exg, 0
	.equ	mus_bloody_stream_cmp, 1

	.section .rodata
	.global	mus_bloody_stream
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_bloody_stream_1:
	.byte	KEYSH , mus_bloody_stream_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 132*mus_bloody_stream_tbs/2
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		VOL   , 87*mus_bloody_stream_mvl/mxv
@ 001   ----------------------------------------
mus_bloody_stream_1_001:
	.byte		N05   , Ds3 , v100
	.byte		N05   , Cn4 
	.byte	W05
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , Gn4 
	.byte	W13
	.byte		N11   , As3 
	.byte		N11   , Fs4 
	.byte	W11
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Ds3 
	.byte		N06   , Cn4 
	.byte	W07
	.byte		N11   , Gn3 
	.byte		N11   , Ds4 
	.byte	W11
	.byte		N12   , Gs3 
	.byte		N12   , Fn4 
	.byte	W13
@ 002   ----------------------------------------
	.byte		N05   , Ds3 
	.byte		N05   , Cn4 
	.byte	W05
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Gn3 
	.byte		N06   , Ds4 
	.byte	W07
	.byte		N11   , As3 
	.byte		N11   , Fs4 
	.byte	W11
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Ds3 
	.byte		N06   , Cn4 
	.byte	W07
	.byte		N11   , Gn3 
	.byte		N11   , Ds4 
	.byte	W11
	.byte		N12   , Gs3 
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , Ds3 
	.byte		N06   , Cn4 
	.byte	W01
@ 003   ----------------------------------------
	.byte	W05
	.byte		        Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , Gn4 
	.byte	W13
	.byte		N11   , As3 
	.byte		N11   , Fs4 
	.byte	W11
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Cn3 
	.byte		N06   , Cn4 
	.byte	W07
	.byte		N11   , Ds3 
	.byte		N11   , Ds4 
	.byte	W11
	.byte		N24   , Gn3 
	.byte		N24   , As4 
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W04
@ 004   ----------------------------------------
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		BEND  , c_v-1
	.byte		N03   , As3 , v104
	.byte		N03   , Cn5
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N03   , Gn3
	.byte		N03   , As4
	.byte	W03
	.byte		BEND  , c_v+1
	.byte		N03   , As3
	.byte		N03   , Cn5
	.byte	W03
	.byte		BEND  , c_v+0
	.byte		N03   , Gn3 , v101
	.byte		N03   , As4
	.byte	W04
	.byte		N02   , As3 , v097
	.byte		N02   , Cn5
	.byte	W02
	.byte		N03   , Gn3 , v094
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v090
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v087
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v083
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v080
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v076
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v073
	.byte		N03   , As4 
	.byte	W04
	.byte		N02   , As3 , v069
	.byte		N02   , Cn5 
	.byte	W02
	.byte		N03   , Gn3 , v066
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v062
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v059
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v055
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v052
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v048
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v045
	.byte		N03   , As4 
	.byte	W04
	.byte		N02   , As3 , v041
	.byte		N02   , Cn5 
	.byte	W02
	.byte		N03   , Gn3 , v038
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v034
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v031
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v027
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v024
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v020
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v017
	.byte		N03   , As4 
	.byte	W04
@ 005   ----------------------------------------
	.byte		N02   , As3 , v013
	.byte		N02   , Cn5 
	.byte	W02
	.byte		N03   , Gn3 , v004
	.byte		N03   , As4 
	.byte	W92
	.byte	W02
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W72
	.byte		N23   , Ds3 , v100
	.byte	W23
	.byte		N72   , Fn3 
	.byte	W01
@ 008   ----------------------------------------
	.byte	W72
	.byte		N23   , Gs3 
	.byte	W23
	.byte		N96   , Gn3 
	.byte	W01
@ 009   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        As3 
	.byte	W01
@ 010   ----------------------------------------
	.byte	W28
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W04
@ 011   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N06   , Ds3 , v116
	.byte		N06   , Ds4 
	.byte	W01
@ 012   ----------------------------------------
	.byte	W05
	.byte		        Fn3 , v124
	.byte		N03   , Fn4 
	.byte	W12
	.byte		N06   , Cn3 , v112
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Ds3 , v120
	.byte		N03   , Ds4 
	.byte	W12
	.byte		N06   , Gn2 , v104
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Cn3 , v112
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Cn3 , v092
	.byte	W06
	.byte		        Ds3 , v096
	.byte	W06
	.byte		        Gn3 , v100
	.byte	W06
	.byte		        Cn4 , v108
	.byte	W06
	.byte		        Gn3 , v096
	.byte	W06
	.byte		        Ds3 , v092
	.byte	W06
	.byte		        Cn3 , v084
	.byte	W07
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W68
	.byte	W03
	.byte		N24   , Ds3 , v072
	.byte	W24
	.byte		        Fn3 , v080
	.byte	W01
@ 016   ----------------------------------------
	.byte	W23
	.byte		        Gn3 , v084
	.byte	W24
	.byte		        Ds4 , v104
	.byte	W24
	.byte		        Dn4 , v100
	.byte	W12
	.byte	W03
	.byte	W06
	.byte	W03
	.byte		N96   , Cn4 , v096
	.byte	W01
@ 017   ----------------------------------------
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		        Fn4 , v104
	.byte	W01
@ 018   ----------------------------------------
	.byte	W36
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
@ 019   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N06   , Gn4 , v100
	.byte	W01
@ 020   ----------------------------------------
	.byte	W05
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W07
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
	.byte	W92
	.byte	W03
	.byte		N24   , Cn3 , v084
	.byte	W01
@ 027   ----------------------------------------
	.byte	W23
	.byte		        Dn3 , v088
	.byte	W24
	.byte		        Ds3 , v096
	.byte	W24
	.byte		        Fn3 , v100
	.byte	W24
	.byte		N06   , Gn2 , v104
	.byte		N06   , Gn3 
	.byte	W01
@ 028   ----------------------------------------
	.byte	W05
	.byte		        As2 , v108
	.byte		N06   , As3 
	.byte	W12
	.byte		        Cn3 
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        Dn3 , v112
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        Ds3 , v116
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        Fn3 , v120
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gn3 , v124
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Gs3 
	.byte		N06   , Gs4 
	.byte	W19
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
mus_bloody_stream_1_030:
	.byte	W23
	.byte		N06   , Cn4 , v100
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Cn4 
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N09   , Cn4 
	.byte		N09   , Cn5 
	.byte	W54
	.byte	W01
	.byte	PEND
@ 031   ----------------------------------------
mus_bloody_stream_1_031:
	.byte	W23
	.byte		N06   , As3 , v100
	.byte		N06   , As4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , As4 
	.byte	W12
	.byte		N09   , As3 
	.byte		N09   , As4 
	.byte	W54
	.byte	W01
	.byte	PEND
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_1_030
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_1_031
@ 036   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N06   , Gn3 , v100
	.byte		N06   , Gn4 
	.byte	W01
@ 037   ----------------------------------------
	.byte	W05
	.byte		        Gs3 
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , As4 
	.byte	W06
	.byte		        Ds3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Fn3 
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gn3 
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Cn3 
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn3 
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds3 
	.byte		N06   , Ds4 
	.byte	W12
	.byte		N36   , Fn3 
	.byte		N30   , Fn4 
	.byte	W30
	.byte		N03   , Ds4 , v084
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W04
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_1_030
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_1_031
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N48   , Cn3 , v096
	.byte		N48   , Cn4 
	.byte	W01
@ 042   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		        As2 
	.byte		N48   , As3 
	.byte	W48
	.byte		N96   , Gs2 , v092
	.byte		N96   , Gs3 
	.byte	W01
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W23
	.byte		N06   , Cn2 , v080
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Dn2 
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Fn2 , v088
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Gs2 , v096
	.byte		N06   , Gs3 
	.byte	W12
	.byte		        Cn3 , v100
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        Dn3 , v108
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        Fn3 , v112
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N12   , Gn3 , v124
	.byte		N12   , Gn4 
	.byte	W01
@ 045   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N96   , Gs2 , v060
	.byte		N96   , Gs3 
	.byte	W01
@ 046   ----------------------------------------
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W03
	.byte	W06
	.byte	W09
	.byte	W03
	.byte	W03
	.byte		        As2 , v072
	.byte		N96   , As3 
	.byte	W01
@ 047   ----------------------------------------
	.byte	W08
	.byte	W36
	.byte	W03
	.byte	W48
	.byte		TIE   , Cn3 , v100
	.byte		TIE   , Cn4 
	.byte	W01
@ 048   ----------------------------------------
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W09
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W01
@ 049   ----------------------------------------
	.byte	W48
	.byte		EOT   , Cn3 
	.byte		        Cn4 
	.byte	W48
@ 050   ----------------------------------------
	.byte	GOTO
	.word	mus_bloody_stream_1_001
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

mus_bloody_stream_2:
	.byte	KEYSH , mus_bloody_stream_key+0
@ 000   ----------------------------------------
	.byte		PAN   , c_v+0
@ 001   ----------------------------------------
mus_bloody_stream_2_001:
	.byte	W96
	.byte		VOICE , 65
	.byte		VOL   , 127*mus_bloody_stream_mvl/mxv
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W32
	.byte	W03
	.byte		N30   , Gn3 , v127
	.byte	W36
	.byte	W01
	.byte		N17   
	.byte	W24
@ 005   ----------------------------------------
mus_bloody_stream_2_005:
	.byte		N32   , Fs3 , v127
	.byte	W32
	.byte	W03
	.byte		TIE   , Gn3 
	.byte	W60
	.byte	W01
	.byte	PEND
@ 006   ----------------------------------------
	.byte	W40
	.byte	W01
	.byte		EOT   
	.byte	W07
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
@ 007   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_2_005
@ 008   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		EOT   , Gn3 
	.byte	W24
	.byte	W01
	.byte		N11   , Fn3 , v127
	.byte	W11
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W01
@ 009   ----------------------------------------
	.byte	W11
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W12
	.byte		N18   , Cn3 
	.byte	W18
	.byte		N06   , Ds3 
	.byte	W12
	.byte		        Cn3 
	.byte	W06
	.byte		N54   , Ds3 
	.byte	W07
@ 010   ----------------------------------------
	.byte	W56
	.byte	W03
	.byte		N12   
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N36   , Fs3 
	.byte	W01
@ 011   ----------------------------------------
	.byte	W32
	.byte	W03
	.byte		N84   , Gn3 
	.byte	W60
	.byte	W01
@ 012   ----------------------------------------
	.byte	W36
	.byte	W02
	.byte		N24   
	.byte	W32
	.byte	W01
	.byte		N24   
	.byte	W24
	.byte		N36   , Fs3 
	.byte	W01
@ 013   ----------------------------------------
mus_bloody_stream_2_013:
	.byte	W32
	.byte	W03
	.byte		TIE   , Gn3 , v127
	.byte	W60
	.byte	W01
	.byte	PEND
@ 014   ----------------------------------------
	.byte	W40
	.byte	W01
	.byte		EOT   
	.byte	W06
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		N36   , Fs3 
	.byte	W01
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_2_013
@ 016   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		EOT   , Gn3 
	.byte	W24
	.byte		N12   , Fn3 , v127
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N18   , Cn4 
	.byte	W01
@ 017   ----------------------------------------
	.byte	W23
	.byte		N06   
	.byte	W06
	.byte		        Dn4 
	.byte	W12
	.byte		N18   , Ds4 
	.byte	W18
	.byte		N09   , Dn4 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N54   , Cn4 
	.byte	W07
@ 018   ----------------------------------------
	.byte	W56
	.byte	W03
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        As3 
	.byte	W01
@ 019   ----------------------------------------
	.byte	W11
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N66   , Gn3 
	.byte	W78
	.byte	W01
@ 020   ----------------------------------------
	.byte	W56
	.byte	W03
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W01
@ 021   ----------------------------------------
	.byte	W23
	.byte		N12   
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		N90   , Cn4 
	.byte	W54
	.byte	W01
@ 022   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		N18   
	.byte	W18
	.byte		        Dn4 
	.byte	W18
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N60   , Dn4 
	.byte	W01
@ 023   ----------------------------------------
	.byte	W56
	.byte	W03
	.byte		N12   , As3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N78   , Gn3 
	.byte	W07
@ 024   ----------------------------------------
	.byte	W80
	.byte	W03
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N18   , Fn3 
	.byte	W01
@ 025   ----------------------------------------
	.byte	W17
	.byte		        Gn3 
	.byte	W18
	.byte		N36   
	.byte	W36
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N36   , Ds3 
	.byte	W13
@ 026   ----------------------------------------
	.byte	W32
	.byte	W03
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N18   , Gn3 
	.byte	W18
	.byte		        Gs3 
	.byte	W18
	.byte		N12   , As3 
	.byte	W12
	.byte		N96   , Gn3 
	.byte	W01
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W23
	.byte		N24   
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N12   , Ds4 
	.byte	W01
@ 030   ----------------------------------------
mus_bloody_stream_2_030:
	.byte	W11
	.byte		N06   , Dn4 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gn4 
	.byte	W01
	.byte	PEND
@ 031   ----------------------------------------
	.byte	W11
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N30   , Ds4 
	.byte	W42
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W01
@ 032   ----------------------------------------
mus_bloody_stream_2_032:
	.byte	W11
	.byte		N12   , Cn4 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W01
	.byte	PEND
@ 033   ----------------------------------------
mus_bloody_stream_2_033:
	.byte	W11
	.byte		N06   , Bn3 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N30   , Dn4 
	.byte	W54
	.byte		N12   , Ds4 
	.byte	W01
	.byte	PEND
@ 034   ----------------------------------------
	.byte	W11
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W01
@ 035   ----------------------------------------
	.byte	W32
	.byte	W03
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W01
@ 036   ----------------------------------------
	.byte	W32
	.byte	W03
	.byte		N60   , Ds4 
	.byte	W60
	.byte	W01
@ 037   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N12   
	.byte	W01
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_2_030
@ 039   ----------------------------------------
	.byte	W11
	.byte		N06   , Fn4 , v127
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N30   , Ds4 
	.byte	W42
	.byte		N12   , As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W01
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_2_032
@ 041   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_2_033
@ 042   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_2_030
@ 043   ----------------------------------------
	.byte	W11
	.byte		N06   , Fn4 , v127
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N18   , Ds4 
	.byte	W18
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		TIE   , Gn4 
	.byte	W09
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		        c_v-9
	.byte	W01
@ 044   ----------------------------------------
	.byte	W02
	.byte		        c_v-4
	.byte	W03
	.byte		        c_v+0
	.byte	W90
	.byte		EOT   
	.byte	W01
@ 045   ----------------------------------------
	.byte	W23
	.byte		N36   , Gn3 
	.byte	W36
	.byte		N18   , Dn4 
	.byte	W18
	.byte		        Fn4 
	.byte	W18
	.byte		N06   , Ds4 
	.byte	W01
@ 046   ----------------------------------------
	.byte	W05
	.byte		        Dn4 
	.byte	W12
	.byte		TIE   , Cn4 
	.byte	W78
	.byte	W01
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	W02
	.byte		EOT   
	.byte	W24
	.byte	W68
	.byte	W02
@ 049   ----------------------------------------
	.byte	W96
	.byte	VOICE , 96
	.byte	VOL , 127*mus_bloody_stream_mvl/mxv
	.byte	N12 ,	An2 , v127
@ 050   ----------------------------------------
	.byte	GOTO
	.word	mus_bloody_stream_2_001
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

mus_bloody_stream_3:
	.byte	KEYSH , mus_bloody_stream_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 17
	.byte		PAN   , c_v+0
	.byte		VOL   , 87*mus_bloody_stream_mvl/mxv
@ 001   ----------------------------------------
mus_bloody_stream_3_001:
	.byte		N24   , Cn3 , v100
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		N17   , As2 
	.byte	W17
	.byte		N06   , An2 
	.byte	W18
	.byte		N12   , Gs2 
	.byte	W13
@ 002   ----------------------------------------
	.byte	W11
	.byte		N09   , Cn3 
	.byte	W13
	.byte		N23   , Bn2 
	.byte	W23
	.byte		N06   , As2 
	.byte	W06
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W01
@ 003   ----------------------------------------
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		N17   , As2 
	.byte	W17
	.byte		N06   , An2 
	.byte	W18
	.byte		TIE   , Gn2 
	.byte	W13
@ 004   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		EOT   
	.byte	W01
@ 005   ----------------------------------------
	.byte		N20   , Cn3 
	.byte		N20   , Ds3 
	.byte	W23
	.byte		N12   , Cn3 
	.byte		N12   , Ds3 
	.byte		N12   , Gn3 
	.byte	W18
	.byte		N03   , Cn3 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N12   , Cn3 
	.byte		N12   , Ds3 
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N09   , Cn3 
	.byte		N09   , Ds3 
	.byte		N09   , Gn3 
	.byte	W12
	.byte		N03   , Cn3 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        Cn3 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W07
@ 006   ----------------------------------------
	.byte		N17   , As2 
	.byte		N20   , Ds3 
	.byte	W24
	.byte		N11   , As2 
	.byte		N11   , Ds3 
	.byte		N11   , Gn3 
	.byte	W17
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W12
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N12   , As2 
	.byte		N12   , Ds3 
	.byte		N12   , Gn3 
	.byte	W13
	.byte		N11   , As2 
	.byte		N08   , Ds3 
	.byte		N08   , Gn3 
	.byte	W11
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W07
@ 007   ----------------------------------------
	.byte		N24   , An2 
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N11   , An2 
	.byte		N11   , Dn3 
	.byte		N11   , Gn3 
	.byte	W17
	.byte		N03   , An2 
	.byte		N03   , Dn3 
	.byte		N03   , Gn3 
	.byte	W12
	.byte		        An2 
	.byte		N03   , Dn3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N12   , An2 
	.byte		N12   , Dn3 
	.byte		N12   , Gn3 
	.byte	W13
	.byte		N08   , An2 
	.byte		N08   , Dn3 
	.byte		N11   , Gn3 
	.byte	W11
	.byte		N03   , An2 
	.byte		N03   , Dn3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        An2 
	.byte		N03   , Dn3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N24   , Gs2 
	.byte		N24   , Cs3 
	.byte	W01
@ 008   ----------------------------------------
	.byte	W24
	.byte		N11   , Gs2 
	.byte		N11   , Cs3 
	.byte		N11   , Fn3 
	.byte	W17
	.byte		N03   , Gs2 
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 
	.byte	W12
	.byte		        Gs2 
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N12   , Gs2 
	.byte		N12   , Cs3 
	.byte		N12   , Fn3 
	.byte	W13
	.byte		N11   , Gs2 
	.byte		N11   , Cs3 
	.byte		N11   , Fn3 
	.byte	W11
	.byte		N03   , Gs2 
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 
	.byte	W06
	.byte		        Gs2 
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N24   , Ds2 
	.byte		N24   , Gn2 
	.byte	W01
@ 009   ----------------------------------------
mus_bloody_stream_3_009:
	.byte	W23
	.byte		N12   , Gn2 , v100
	.byte		N12   , Cn3 
	.byte		N12   , Ds3 
	.byte	W18
	.byte		N03   , Gn2 
	.byte		N03   , Cn3 
	.byte		N03   , Ds3 
	.byte	W12
	.byte		        Gn2 
	.byte		N03   , Cn3 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   , Gn2 
	.byte		N12   , Cn3 
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Gn2 
	.byte		N09   , Cn3 
	.byte		N09   , Ds3 
	.byte	W12
	.byte		N03   , Gn2 
	.byte		N03   , Cn3 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        Gn2 
	.byte		N03   , Cn3 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N18   , As2 
	.byte		N21   , Ds3 
	.byte	W01
	.byte	PEND
@ 010   ----------------------------------------
mus_bloody_stream_3_010:
	.byte	W23
	.byte		N12   , As2 , v100
	.byte		N12   , Ds3 
	.byte		N12   , Gn3 
	.byte	W18
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W12
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N12   , As2 
	.byte		N12   , Ds3 
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        As2 
	.byte		N09   , Ds3 
	.byte		N09   , Gn3 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N24   , An2 
	.byte		N24   , Dn3 
	.byte	W01
	.byte	PEND
@ 011   ----------------------------------------
mus_bloody_stream_3_011:
	.byte	W23
	.byte		N12   , An2 , v100
	.byte		N12   , Dn3 
	.byte		N12   , Gn3 
	.byte	W18
	.byte		N03   , An2 
	.byte		N03   , Dn3 
	.byte		N03   , Gn3 
	.byte	W12
	.byte		        An2 
	.byte		N03   , Dn3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N12   , An2 
	.byte		N12   , Dn3 
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N09   , An2 
	.byte		N09   , Dn3 
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N03   , An2 
	.byte		N03   , Dn3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        An2 
	.byte		N03   , Dn3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N24   , Gs2 
	.byte		N24   , Cs3 
	.byte	W01
	.byte	PEND
@ 012   ----------------------------------------
	.byte	W23
	.byte		N12   , Gs2 
	.byte		N12   , Cs3 
	.byte		N12   , Fn3 
	.byte	W18
	.byte		N03   , Gs2 
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 
	.byte	W12
	.byte		        Gs2 
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N12   , Gs2 
	.byte		N12   , Cs3 
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Gs2 
	.byte		N12   , Cs3 
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N03   , Gs2 
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 
	.byte	W06
	.byte		        Gs2 
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N21   , Cn3 
	.byte		N21   , Ds3 
	.byte	W01
@ 013   ----------------------------------------
	.byte	W23
	.byte		N12   , Cn3 
	.byte		N12   , Ds3 
	.byte		N12   , Gn3 
	.byte	W18
	.byte		N03   , Cn3 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W12
	.byte		        Cn3 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N12   , Cn3 
	.byte		N12   , Ds3 
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N09   , Cn3 
	.byte		N09   , Ds3 
	.byte		N09   , Gn3 
	.byte	W12
	.byte		N03   , Cn3 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        Cn3 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N18   , As2 
	.byte		N21   , Ds3 
	.byte	W01
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_3_010
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_3_011
@ 016   ----------------------------------------
	.byte	W23
	.byte		N12   , Gs2 , v100
	.byte		N12   , Cs3 
	.byte		N12   , Fn3 
	.byte	W18
	.byte		N03   , Gs2 
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 
	.byte	W12
	.byte		        Gs2 
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N12   , Gs2 
	.byte		N12   , Cs3 
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Gs2 
	.byte		N12   , Cs3 
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N03   , Gs2 
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 
	.byte	W06
	.byte		        Gs2 
	.byte		N03   , Cs3 
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N24   , Ds2 
	.byte		N24   , Gn2 
	.byte	W01
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_3_009
@ 018   ----------------------------------------
	.byte	W23
	.byte		N12   , As2 , v100
	.byte		N12   , Ds3 
	.byte		N12   , Gn3 
	.byte	W18
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W12
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N12   , As2 
	.byte		N12   , Ds3 
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        As2 
	.byte		N09   , Ds3 
	.byte		N09   , Gn3 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N24   , Ds3 
	.byte		N24   , Gn3 
	.byte	W01
@ 019   ----------------------------------------
	.byte	W23
	.byte		N12   , Ds3 
	.byte		N12   , Gn3 
	.byte		N12   , As3 
	.byte	W18
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte		N03   , As3 
	.byte	W12
	.byte		        Ds3 
	.byte		N03   , Gn3 
	.byte		N03   , As3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte		N12   , Gn3 
	.byte		N12   , As3 
	.byte	W12
	.byte		        Ds3 
	.byte		N12   , Gn3 
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte		N03   , Gn3 
	.byte		N03   , As3 
	.byte	W06
	.byte		        Ds3 
	.byte		N03   , Gn3 
	.byte		N03   , As3 
	.byte	W06
	.byte		N24   , Bn2 
	.byte		N24   , Dn3 
	.byte	W01
@ 020   ----------------------------------------
	.byte	W23
	.byte		N12   , Bn2 
	.byte		N12   , Dn3 
	.byte		N12   , Gn3 
	.byte	W18
	.byte		N03   , Bn2 
	.byte		N03   , Dn3 
	.byte		N03   , Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte		N03   , Dn3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N12   , Bn2 
	.byte		N12   , Dn3 
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte		N12   , Dn3 
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N03   , Bn2 
	.byte		N03   , Dn3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        Bn2 
	.byte		N03   , Dn3 
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N96   , Cn3 
	.byte		N96   , Fn3 
	.byte	W01
@ 021   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        Cs3 
	.byte		N96   , Fn3 
	.byte		N96   , Gs3 
	.byte	W01
@ 022   ----------------------------------------
mus_bloody_stream_3_022:
	.byte	W92
	.byte	W03
	.byte		N96   , Cn3 , v100
	.byte		N96   , Ds3 
	.byte		N96   , Gn3 
	.byte	W01
	.byte	PEND
@ 023   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        As2 
	.byte		N96   , Dn3 
	.byte		N96   , Fn3 
	.byte	W01
@ 024   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        An2 
	.byte		N96   , Dn3 
	.byte		N96   , Fn3 
	.byte	W01
@ 025   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        Gn2 
	.byte		N96   , Cn3 
	.byte		N96   , Ds3 
	.byte	W01
@ 026   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N24   , Ds2 , v084
	.byte		N24   , Gn2 
	.byte		N24   , Cn3 
	.byte	W01
@ 027   ----------------------------------------
	.byte	W23
	.byte		        Fn2 
	.byte		N24   , As2 
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Gn2 
	.byte		N24   , Cn3 
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        As2 
	.byte		N24   , Dn3 
	.byte		N24   , Fn3 
	.byte	W24
	.byte	W01
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_3_022
@ 030   ----------------------------------------
mus_bloody_stream_3_030:
	.byte	W92
	.byte	W03
	.byte		N96   , Gn2 , v100
	.byte		N96   , As2 
	.byte		N96   , Ds3 
	.byte	W01
	.byte	PEND
@ 031   ----------------------------------------
mus_bloody_stream_3_031:
	.byte	W92
	.byte	W03
	.byte		N96   , Ds2 , v100
	.byte		N96   , Gs2 
	.byte		N96   , Cn3 
	.byte	W01
	.byte	PEND
@ 032   ----------------------------------------
mus_bloody_stream_3_032:
	.byte	W92
	.byte	W03
	.byte		N96   , Gn2 , v100
	.byte		N96   , Bn2 
	.byte		N96   , Dn3 
	.byte	W01
	.byte	PEND
@ 033   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_3_022
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_3_030
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_3_031
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_3_032
@ 037   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_3_022
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_3_030
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_3_031
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_3_032
@ 041   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N66   , Cn3 , v100
	.byte		N66   , Ds3 
	.byte		N66   , Gn3 
	.byte	W01
@ 042   ----------------------------------------
	.byte	W68
	.byte	W03
	.byte		N18   , Cn3 
	.byte		N18   , Ds3 
	.byte		N18   , Gn3 
	.byte	W24
	.byte		N44   , Gs2 
	.byte		N44   , Cs3 
	.byte		N44   , Fn3 
	.byte	W01
@ 043   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		        Gs2 
	.byte		N44   , Cs3 
	.byte		N44   , Fn3 
	.byte	W48
	.byte		N96   , Gs2 
	.byte		N96   , Cn3 
	.byte		N96   , Fn3 
	.byte	W01
@ 044   ----------------------------------------
	.byte	W96
@ 045   ----------------------------------------
	.byte	W23
	.byte		N72   , Gn2 
	.byte		N72   , Bn2 
	.byte		N72   , Dn3 
	.byte		N72   , Bn3 
	.byte	W72
	.byte		N96   , Cn3 
	.byte		N96   , Ds3 
	.byte		N96   , Gs3 
	.byte	W01
@ 046   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        Dn3 
	.byte		N96   , Fn3 
	.byte		N96   , As3 
	.byte	W01
@ 047   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		TIE   , Ds3 
	.byte		TIE   , Gn3 
	.byte		TIE   , Cn4 
	.byte	W01
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W48
	.byte		EOT   , Ds3 
	.byte		        Gn3 
	.byte		        Cn4 
	.byte	W48
@ 050   ----------------------------------------
	.byte	GOTO
	.word	mus_bloody_stream_3_001
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

mus_bloody_stream_4:
	.byte	KEYSH , mus_bloody_stream_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte		VOL   , 87*mus_bloody_stream_mvl/mxv
@ 001   ----------------------------------------
mus_bloody_stream_4_001:
	.byte		N05   , Ds3 , v100
	.byte		N05   , Cn4 
	.byte	W05
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , Gn4 
	.byte	W13
	.byte		N11   , As3 
	.byte		N11   , Fs4 
	.byte	W11
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Ds3 
	.byte		N06   , Cn4 
	.byte	W07
	.byte		N11   , Gn3 
	.byte		N11   , Ds4 
	.byte	W11
	.byte		N12   , Gs3 
	.byte		N12   , Fn4 
	.byte	W13
@ 002   ----------------------------------------
	.byte		N05   , Ds3 
	.byte		N05   , Cn4 
	.byte	W05
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Gn3 
	.byte		N06   , Ds4 
	.byte	W07
	.byte		N11   , As3 
	.byte		N11   , Fs4 
	.byte	W11
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Ds3 
	.byte		N06   , Cn4 
	.byte	W07
	.byte		N11   , Gn3 
	.byte		N11   , Ds4 
	.byte	W11
	.byte		N12   , Gs3 
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , Ds3 
	.byte		N06   , Cn4 
	.byte	W01
@ 003   ----------------------------------------
	.byte	W05
	.byte		        Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , Gn4 
	.byte	W13
	.byte		N11   , As3 
	.byte		N11   , Fs4 
	.byte	W11
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Cn3 
	.byte		N06   , Cn4 
	.byte	W07
	.byte		N11   , Ds3 
	.byte		N11   , Ds4 
	.byte	W11
	.byte		N24   , Gn3 
	.byte		N24   , As4 
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W04
@ 004   ----------------------------------------
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		BEND  , c_v-1
	.byte		N03   , As3 , v104
	.byte		N03   , Cn5
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N03   , Gn3
	.byte		N03   , As4
	.byte	W03
	.byte		BEND  , c_v+1
	.byte		N03   , As3
	.byte		N03   , Cn5
	.byte	W03
	.byte		BEND  , c_v+0
	.byte		N03   , Gn3 , v101
	.byte		N03   , As4
	.byte	W04
	.byte		N02   , As3 , v097
	.byte		N02   , Cn5
	.byte	W02
	.byte		N03   , Gn3 , v094
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v090
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v087
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v083
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v080
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v076
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v073
	.byte		N03   , As4 
	.byte	W04
	.byte		N02   , As3 , v069
	.byte		N02   , Cn5 
	.byte	W02
	.byte		N03   , Gn3 , v066
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v062
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v059
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v055
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v052
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v048
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v045
	.byte		N03   , As4 
	.byte	W04
	.byte		N02   , As3 , v041
	.byte		N02   , Cn5 
	.byte	W02
	.byte		N03   , Gn3 , v038
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v034
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v031
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v027
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v024
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v020
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v017
	.byte		N03   , As4 
	.byte	W04
@ 005   ----------------------------------------
	.byte		N02   , As3 , v013
	.byte		N02   , Cn5 
	.byte	W02
	.byte		N03   , Gn3 , v004
	.byte		N03   , As4 
	.byte	W92
	.byte	W02
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W72
	.byte		N23   , Ds3 , v100
	.byte	W23
	.byte		N72   , Fn3 
	.byte	W01
@ 008   ----------------------------------------
	.byte	W72
	.byte		N23   , Gs3 
	.byte	W23
	.byte		N96   , Gn3 
	.byte	W01
@ 009   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        As3 
	.byte	W01
@ 010   ----------------------------------------
	.byte	W40
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W04
@ 011   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N06   , Ds3 , v116
	.byte		N06   , Ds4 
	.byte	W01
@ 012   ----------------------------------------
	.byte	W05
	.byte		        Fn3 , v120
	.byte		N03   , Fn4 
	.byte	W12
	.byte		N06   , Cn3 , v116
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Ds3 , v120
	.byte		N03   , Ds4 
	.byte	W12
	.byte		N06   , Gn2 , v112
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Cn3 , v116
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Cn3 , v100
	.byte	W06
	.byte		        Ds3 , v104
	.byte	W06
	.byte		        Gn3 , v108
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn3 , v100
	.byte	W06
	.byte		        Ds3 , v092
	.byte	W06
	.byte		        Cn3 , v080
	.byte	W07
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W68
	.byte	W03
	.byte		N24   , Ds3 , v072
	.byte	W24
	.byte		        Fn3 , v080
	.byte	W01
@ 016   ----------------------------------------
	.byte	W23
	.byte		        Gn3 , v084
	.byte	W24
	.byte		        Ds4 , v104
	.byte	W24
	.byte		        Dn4 , v100
	.byte	W12
	.byte	W03
	.byte	W06
	.byte	W03
	.byte		N96   , Cn4 , v096
	.byte	W01
@ 017   ----------------------------------------
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		        Fn4 , v104
	.byte	W01
@ 018   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W04
@ 019   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N06   , Gn4 , v100
	.byte	W01
@ 020   ----------------------------------------
	.byte	W05
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W07
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
	.byte	W92
	.byte	W03
	.byte		N24   , Gn2 , v076
	.byte		N24   , Cn3 
	.byte	W01
@ 027   ----------------------------------------
	.byte	W23
	.byte		        As2 , v084
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Cn3 , v088
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        Dn3 , v096
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N06   , Ds3 , v104
	.byte		N06   , Gn3 
	.byte	W01
@ 028   ----------------------------------------
	.byte	W05
	.byte		        Fn3 
	.byte		N06   , As3 
	.byte	W12
	.byte		        Gn3 , v108
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        Gs3 , v112
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        As3 
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        Cn4 , v116
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Ds4 , v120
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Fn4 , v124
	.byte		N06   , Gs4 
	.byte	W19
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
mus_bloody_stream_4_030:
	.byte	W23
	.byte		N06   , Cn4 , v100
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Cn4 
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N09   , Cn4 
	.byte		N09   , Cn5 
	.byte	W54
	.byte	W01
	.byte	PEND
@ 031   ----------------------------------------
mus_bloody_stream_4_031:
	.byte	W23
	.byte		N06   , As3 , v100
	.byte		N06   , As4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , As4 
	.byte	W12
	.byte		N09   , As3 
	.byte		N09   , As4 
	.byte	W54
	.byte	W01
	.byte	PEND
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_4_030
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_4_031
@ 036   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N06   , Gn3 , v100
	.byte		N06   , Gn4 
	.byte	W01
@ 037   ----------------------------------------
	.byte	W05
	.byte		        Gs3 
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , As4 
	.byte	W06
	.byte		        Ds3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Fn3 
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gn3 
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Cn3 
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn3 
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds3 
	.byte		N06   , Ds4 
	.byte	W12
	.byte		N36   , Fn3 
	.byte		N30   , Fn4 
	.byte	W30
	.byte		N03   , Ds4 , v084
	.byte	W03
	.byte		        Dn4 , v060
	.byte	W04
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_4_030
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_4_031
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N48   , Cn3 , v096
	.byte		N48   , Cn4 
	.byte	W01
@ 042   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		        As2 , v088
	.byte		N48   , As3 
	.byte	W48
	.byte		N96   , Gs2 , v084
	.byte		N96   , Gs3 
	.byte	W01
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W23
	.byte		N06   , Cn2 , v096
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Dn2 
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Fn2 , v104
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Gs2 , v108
	.byte		N06   , Gs3 
	.byte	W12
	.byte		        Cn3 , v112
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        Dn3 , v120
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        Fn3 , v124
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N12   , Gn3 , v127
	.byte		N12   , Gn4 
	.byte	W01
@ 045   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N96   , Gs2 , v060
	.byte		N96   , Gs3 
	.byte	W01
@ 046   ----------------------------------------
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W03
	.byte	W06
	.byte	W09
	.byte	W03
	.byte	W03
	.byte		        As2 , v072
	.byte		N96   , As3 
	.byte	W01
@ 047   ----------------------------------------
	.byte	W08
	.byte	W36
	.byte	W03
	.byte	W48
	.byte		TIE   , Cn3 , v100
	.byte		TIE   , Cn4 
	.byte	W01
@ 048   ----------------------------------------
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W09
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W01
@ 049   ----------------------------------------
	.byte	W48
	.byte		EOT   , Cn3 
	.byte		        Cn4 
	.byte	W48
@ 050   ----------------------------------------
	.byte	GOTO
	.word	mus_bloody_stream_4_001
	.byte	FINE

@**************** Track 5 (Midi-Chn.5) ****************@

mus_bloody_stream_5:
	.byte	KEYSH , mus_bloody_stream_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 65
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*mus_bloody_stream_mvl/mxv
@ 001   ----------------------------------------
mus_bloody_stream_5_001:
	.byte		N05   , Ds2 , v100
	.byte		N05   , Cn3 
	.byte	W05
	.byte		N06   , Gn2 
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N06   , Gn3 
	.byte	W13
	.byte		N11   , As2 
	.byte		N11   , Fs3 
	.byte	W11
	.byte		N06   , Gn2 
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Gs2 
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Gs2 
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Ds2 
	.byte		N06   , Cn3 
	.byte	W07
	.byte		N11   , Gn2 
	.byte		N11   , Ds3 
	.byte	W11
	.byte		N12   , Gs2 
	.byte		N12   , Fn3 
	.byte	W13
@ 002   ----------------------------------------
	.byte		N05   , Ds2 
	.byte		N05   , Cn3 
	.byte	W05
	.byte		N06   , Gn2 
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Gn2 
	.byte		N06   , Ds3 
	.byte	W07
	.byte		N11   , As2 
	.byte		N11   , Fs3 
	.byte	W11
	.byte		N06   , Gn2 
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Gs2 
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Gs2 
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Ds2 
	.byte		N06   , Cn3 
	.byte	W07
	.byte		N11   , Gn2 
	.byte		N11   , Ds3 
	.byte	W11
	.byte		N12   , Gs2 
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , Ds2 
	.byte		N06   , Cn3 
	.byte	W01
@ 003   ----------------------------------------
	.byte	W05
	.byte		        Gn2 
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N06   , Gn3 
	.byte	W13
	.byte		N11   , As2 
	.byte		N11   , Fs3 
	.byte	W11
	.byte		N06   , Gn2 
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Gs2 
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Gs2 
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Cn2 
	.byte		N06   , Cn3 
	.byte	W07
	.byte		N11   , Ds2 
	.byte		N11   , Ds3 
	.byte	W11
	.byte		N24   , Gn2 
	.byte		N24   , As3 
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W04
@ 004   ----------------------------------------
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		BEND  , c_v-1
	.byte		N03   , As2 , v104
	.byte		N03   , Cn4
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N03   , Gn2
	.byte		N03   , As3
	.byte	W03
	.byte		BEND  , c_v+1
	.byte		N03   , As2
	.byte		N03   , Cn4
	.byte	W03
	.byte		BEND  , c_v+0
	.byte		N03   , Gn2 , v101
	.byte		N03   , As3
	.byte	W04
	.byte		N02   , As2 , v097
	.byte		N02   , Cn4
	.byte	W02
	.byte		N03   , Gn2 , v094
	.byte		N03   , As3 
	.byte	W03
	.byte		        As2 , v090
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Gn2 , v087
	.byte		N03   , As3 
	.byte	W03
	.byte		        As2 , v083
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Gn2 , v080
	.byte		N03   , As3 
	.byte	W03
	.byte		        As2 , v076
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Gn2 , v073
	.byte		N03   , As3 
	.byte	W04
	.byte		N02   , As2 , v069
	.byte		N02   , Cn4 
	.byte	W02
	.byte		N03   , Gn2 , v066
	.byte		N03   , As3 
	.byte	W03
	.byte		        As2 , v062
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Gn2 , v059
	.byte		N03   , As3 
	.byte	W03
	.byte		        As2 , v055
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Gn2 , v052
	.byte		N03   , As3 
	.byte	W03
	.byte		        As2 , v048
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Gn2 , v045
	.byte		N03   , As3 
	.byte	W04
	.byte		N02   , As2 , v041
	.byte		N02   , Cn4 
	.byte	W02
	.byte		N03   , Gn2 , v038
	.byte		N03   , As3 
	.byte	W03
	.byte		        As2 , v034
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Gn2 , v031
	.byte		N03   , As3 
	.byte	W03
	.byte		        As2 , v027
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Gn2 , v024
	.byte		N03   , As3 
	.byte	W03
	.byte		        As2 , v020
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Gn2 , v017
	.byte		N03   , As3 
	.byte	W04
@ 005   ----------------------------------------
	.byte		N02   , As2 , v013
	.byte		N02   , Cn4 
	.byte	W02
	.byte		N03   , Gn2 , v004
	.byte		N03   , As3
	.byte	W92
	.byte	W02
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W72
	.byte		N23   , Ds2 , v100
	.byte	W23
	.byte		N72   , Fn2 
	.byte	W01
@ 008   ----------------------------------------
	.byte	W72
	.byte		N23   , Gs2 
	.byte	W23
	.byte		N96   , Gn2 
	.byte	W01
@ 009   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        Ds3 
	.byte	W01
@ 010   ----------------------------------------
	.byte	W23
	.byte	W12
	.byte	W06
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W04
@ 011   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N06   , Ds3 , v104
	.byte	W01
@ 012   ----------------------------------------
	.byte	W05
	.byte		N03   , Fn3 , v108
	.byte	W12
	.byte		N06   , Cn3 , v100
	.byte	W06
	.byte		N03   , Ds3 , v104
	.byte	W12
	.byte		N06   , Gn2 , v096
	.byte	W06
	.byte		N03   , Cn3 , v108
	.byte	W12
	.byte		N06   , Cn2 , v088
	.byte	W06
	.byte		        Ds2 , v096
	.byte	W06
	.byte		        Gn2 , v100
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gn2 , v092
	.byte	W06
	.byte		        Ds2 , v080
	.byte	W06
	.byte		        Cn2 , v068
	.byte	W07
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W68
	.byte	W03
	.byte		N24   , Ds2 , v072
	.byte	W24
	.byte		        Fn2 , v080
	.byte	W01
@ 016   ----------------------------------------
	.byte	W23
	.byte		        Gn2 , v084
	.byte	W24
	.byte		        Ds3 , v104
	.byte	W24
	.byte		        Dn3 , v100
	.byte	W12
	.byte	W03
	.byte	W06
	.byte	W03
	.byte		N96   , Cn3 , v096
	.byte	W01
@ 017   ----------------------------------------
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		        Fn3 , v104
	.byte	W01
@ 018   ----------------------------------------
	.byte	W36
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W04
@ 019   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N06   , Gn3 , v100
	.byte	W01
@ 020   ----------------------------------------
	.byte	W05
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W07
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
	.byte	W92
	.byte	W03
	.byte		N24   , Cn2 , v076
	.byte	W01
@ 027   ----------------------------------------
	.byte	W23
	.byte		        Dn2 , v092
	.byte	W24
	.byte		        Ds2 , v100
	.byte	W24
	.byte		        Fn2 , v108
	.byte	W24
	.byte		N06   , Gn2 , v112
	.byte	W01
@ 028   ----------------------------------------
	.byte	W05
	.byte		        As2 , v116
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W12
	.byte		        Ds3 , v124
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 , v127
	.byte	W12
	.byte		        Gs3 
	.byte	W19
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
mus_bloody_stream_5_030:
	.byte	W23
	.byte		N06   , Cn3 , v100
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W54
	.byte	W01
	.byte	PEND
@ 031   ----------------------------------------
mus_bloody_stream_5_031:
	.byte	W23
	.byte		N06   , As2 , v100
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W54
	.byte	W01
	.byte	PEND
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_5_030
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_5_031
@ 036   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N06   , Gn3 , v100
	.byte	W01
@ 037   ----------------------------------------
	.byte	W05
	.byte		        Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W12
	.byte		N30   , Fn3 
	.byte	W30
	.byte		N03   , Ds3 , v056
	.byte	W03
	.byte		        Dn3 
	.byte	W04
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_5_030
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_5_031
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N48   , Cn3 , v100
	.byte	W01
@ 042   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		        As2 , v096
	.byte	W48
	.byte		N96   , Gs2 , v088
	.byte	W01
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W23
	.byte		N06   , Cn2 , v100
	.byte	W06
	.byte		        Dn2 , v092
	.byte	W12
	.byte		        Fn2 , v100
	.byte	W12
	.byte		        Gs2 , v108
	.byte	W12
	.byte		        Cn3 , v112
	.byte	W12
	.byte		        Dn3 , v116
	.byte	W12
	.byte		        Fn3 , v120
	.byte	W06
	.byte		N12   , Gn3 , v124
	.byte	W01
@ 045   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N96   , Gs2 , v060
	.byte	W01
@ 046   ----------------------------------------
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W03
	.byte	W06
	.byte	W09
	.byte	W03
	.byte	W03
	.byte		        As2 , v072
	.byte	W01
@ 047   ----------------------------------------
	.byte	W08
	.byte	W36
	.byte	W03
	.byte	W48
	.byte		TIE   , Cn3 , v100
	.byte	W01
@ 048   ----------------------------------------
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W09
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W01
@ 049   ----------------------------------------
	.byte	W48
	.byte		EOT  
	.byte	W48
@ 050   ----------------------------------------
	.byte	GOTO
	.word	mus_bloody_stream_5_001
	.byte	FINE

@**************** Track 6 (Midi-Chn.6) ****************@

mus_bloody_stream_6:
	.byte	KEYSH , mus_bloody_stream_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 87*mus_bloody_stream_mvl/mxv
@ 001   ----------------------------------------
mus_bloody_stream_6_001:
	.byte		N05   , Ds3 , v100
	.byte		N05   , Cn4 
	.byte	W05
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , Gn4 
	.byte	W13
	.byte		N11   , As3 
	.byte		N11   , Fs4 
	.byte	W11
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Ds3 
	.byte		N06   , Cn4 
	.byte	W07
	.byte		N11   , Gn3 
	.byte		N11   , Ds4 
	.byte	W11
	.byte		N12   , Gs3 
	.byte		N12   , Fn4 
	.byte	W13
@ 002   ----------------------------------------
	.byte		N05   , Ds3 
	.byte		N05   , Cn4 
	.byte	W05
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Gn3 
	.byte		N06   , Ds4 
	.byte	W07
	.byte		N11   , As3 
	.byte		N11   , Fs4 
	.byte	W11
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Ds3 
	.byte		N06   , Cn4 
	.byte	W07
	.byte		N11   , Gn3 
	.byte		N11   , Ds4 
	.byte	W11
	.byte		N12   , Gs3 
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , Ds3 
	.byte		N06   , Cn4 
	.byte	W01
@ 003   ----------------------------------------
	.byte	W05
	.byte		        Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , Gn4 
	.byte	W13
	.byte		N11   , As3 
	.byte		N11   , Fs4 
	.byte	W11
	.byte		N06   , Gn3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gs3 
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Cn3 
	.byte		N06   , Cn4 
	.byte	W07
	.byte		N11   , Ds3 
	.byte		N11   , Ds4 
	.byte	W11
	.byte		N24   , Gn3 
	.byte		N24   , As4 
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W04
@ 004   ----------------------------------------
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		BEND  , c_v-1
	.byte		N03   , As3 , v104
	.byte		N03   , Cn5
	.byte	W03
	.byte		BEND  , c_v+6
	.byte		N03   , Gn3
	.byte		N03   , As4
	.byte	W03
	.byte		BEND  , c_v+1
	.byte		N03   , As3
	.byte		N03   , Cn5
	.byte	W03
	.byte		BEND  , c_v+0
	.byte		N03   , Gn3 , v101
	.byte		N03   , As4
	.byte	W04
	.byte		N02   , As3 , v097
	.byte		N02   , Cn5
	.byte	W02
	.byte		N03   , Gn3 , v094
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v090
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v087
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v083
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v080
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v076
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v073
	.byte		N03   , As4 
	.byte	W04
	.byte		N02   , As3 , v069
	.byte		N02   , Cn5 
	.byte	W02
	.byte		N03   , Gn3 , v066
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v062
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v059
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v055
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v052
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v048
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v045
	.byte		N03   , As4 
	.byte	W04
	.byte		N02   , As3 , v041
	.byte		N02   , Cn5 
	.byte	W02
	.byte		N03   , Gn3 , v038
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v034
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v031
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v027
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v024
	.byte		N03   , As4 
	.byte	W03
	.byte		        As3 , v020
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        Gn3 , v017
	.byte		N03   , As4 
	.byte	W04
@ 005   ----------------------------------------
	.byte		N02   , As3 , v013
	.byte		N02   , Cn5 
	.byte	W02
	.byte		N03   , Gn3 , v004
	.byte		N03   , As4
	.byte	W92
	.byte	W02
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
	.byte	W92
	.byte	W03
	.byte		N06   , Ds3 , v116
	.byte		N06   , Ds4 
	.byte	W01
@ 012   ----------------------------------------
	.byte	W05
	.byte		        Fn3 , v124
	.byte		N03   , Fn4 
	.byte	W12
	.byte		N06   , Cn3 , v112
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Ds3 , v120
	.byte		N03   , Ds4 
	.byte	W12
	.byte		N06   , Gn2 , v104
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Cn3 , v112
	.byte		N03   , Cn4 
	.byte	W12
	.byte		N06   , Cn3 , v092
	.byte	W06
	.byte		        Ds3 , v096
	.byte	W06
	.byte		        Gn3 , v100
	.byte	W06
	.byte		        Cn4 , v108
	.byte	W06
	.byte		        Gn3 , v096
	.byte	W06
	.byte		        Ds3 , v092
	.byte	W06
	.byte		        Cn3 , v084
	.byte	W07
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        Gn4 , v100
	.byte	W01
@ 020   ----------------------------------------
	.byte	W05
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W07
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
	.byte	W92
	.byte	W03
	.byte		        Gn2 , v104
	.byte		N06   , Gn3 
	.byte	W01
@ 028   ----------------------------------------
	.byte	W05
	.byte		        As2 , v108
	.byte		N06   , As3 
	.byte	W12
	.byte		        Cn3 
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        Dn3 , v112
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        Ds3 , v116
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        Fn3 , v120
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gn3 , v124
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Gs3 
	.byte		N06   , Gs4 
	.byte	W19
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
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        Dn4 , v100
	.byte	W01
@ 037   ----------------------------------------
	.byte	W05
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		N36   , Fn5 
	.byte	W36
	.byte	W01
@ 038   ----------------------------------------
	.byte	W96
@ 039   ----------------------------------------
	.byte	W96
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N48   , Cn4 , v080
	.byte	W01
@ 042   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		        As3 , v076
	.byte	W48
	.byte		N96   , Gs3 , v072
	.byte	W01
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W23
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 , v076
	.byte	W12
	.byte		        Gs3 , v080
	.byte	W12
	.byte		        Cn4 , v084
	.byte	W12
	.byte		        Dn4 , v088
	.byte	W12
	.byte		        Fn4 , v092
	.byte	W06
	.byte		N12   , Gn4 , v100
	.byte	W01
@ 045   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N96   , Gs3 , v060
	.byte	W01
@ 046   ----------------------------------------
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W03
	.byte	W06
	.byte	W09
	.byte	W03
	.byte	W03
	.byte		        As3 , v072
	.byte	W01
@ 047   ----------------------------------------
	.byte	W08
	.byte	W36
	.byte	W03
	.byte	W48
	.byte		TIE   , Cn4 , v100
	.byte	W01
@ 048   ----------------------------------------
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W09
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W03
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W01
@ 049   ----------------------------------------
	.byte	W48
	.byte		EOT   
	.byte	W48
@ 050   ----------------------------------------
	.byte	GOTO
	.word	mus_bloody_stream_6_001
	.byte	FINE

@**************** Track 7 (Midi-Chn.8) ****************@

mus_bloody_stream_7:
	.byte	KEYSH , mus_bloody_stream_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 29
	.byte		PAN   , c_v+0
	.byte		VOL   , 87*mus_bloody_stream_mvl/mxv
@ 001   ----------------------------------------
mus_bloody_stream_7_001:
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
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
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
	.byte	W96
@ 020   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N96   , Cn2 , v100
	.byte		N96   , Fn2 
	.byte	W01
@ 021   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        Cs2 
	.byte		N96   , Gs2 
	.byte	W01
@ 022   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        Cn2 
	.byte		N96   , Gn2 
	.byte	W01
@ 023   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        As1 
	.byte		N96   , Fn2 
	.byte	W01
@ 024   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        An1 
	.byte		N96   , Fn2 
	.byte	W01
@ 025   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        Gs1 
	.byte		N96   , Ds2 
	.byte	W01
@ 026   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N24   , Cn2 , v096
	.byte		N24   , Gn2 
	.byte	W01
@ 027   ----------------------------------------
	.byte	W23
	.byte		        Dn2 
	.byte		N24   , As2 
	.byte	W24
	.byte		        Ds2 
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        Fn2 
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N06   , Gn2 
	.byte	W01
@ 028   ----------------------------------------
	.byte	W05
	.byte		N09   , Fn3 , v092
	.byte	W12
	.byte		        Ds3 , v096
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 , v100
	.byte	W12
	.byte		        As2 , v104
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W19
@ 029   ----------------------------------------
	.byte	W14
	.byte	W80
	.byte	W02
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	W96
@ 038   ----------------------------------------
	.byte	W96
@ 039   ----------------------------------------
	.byte	W96
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W96
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	GOTO
	.word	mus_bloody_stream_7_001
	.byte	FINE

@**************** Track 8 (Midi-Chn.9) ****************@

mus_bloody_stream_8:
	.byte	KEYSH , mus_bloody_stream_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 36
	.byte		PAN   , c_v+0
	.byte		VOL   , 107*mus_bloody_stream_mvl/mxv
@ 001   ----------------------------------------
mus_bloody_stream_8_001:
	.byte		N24   , Cn1 , v100
	.byte	W24
	.byte		        Bn0 
	.byte	W24
	.byte		N17   , As0 
	.byte	W17
	.byte		N06   , An0 
	.byte	W18
	.byte		N12   , Gs0 
	.byte	W13
@ 002   ----------------------------------------
	.byte	W11
	.byte		N09   , Cn1 
	.byte	W13
	.byte		N23   , Bn0 
	.byte	W23
	.byte		N06   , As0 
	.byte	W06
	.byte		        An0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Gn0 
	.byte	W12
	.byte		N24   , Cn1 
	.byte	W01
@ 003   ----------------------------------------
	.byte	W24
	.byte		        Bn0 
	.byte	W24
	.byte		N17   , As0 
	.byte	W17
	.byte		N06   , An0 
	.byte	W18
	.byte		N48   , Gn0 
	.byte	W13
@ 004   ----------------------------------------
	.byte	W48
	.byte		N11   
	.byte	W11
	.byte		N36   , Gn1 
	.byte	W36
	.byte	W01
@ 005   ----------------------------------------
	.byte		N23   , Cn1 
	.byte	W23
	.byte		N12   
	.byte	W18
	.byte		N06   , Gn0 
	.byte	W12
	.byte		        As0 
	.byte	W06
	.byte		        Gn0 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W13
@ 006   ----------------------------------------
	.byte		N24   , Ds1 
	.byte	W24
	.byte		N11   
	.byte	W17
	.byte		N06   , As0 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        As0 
	.byte	W13
	.byte		N11   , Ds1 
	.byte	W11
	.byte		N12   , As0 
	.byte	W13
@ 007   ----------------------------------------
	.byte		N24   , Dn1 
	.byte	W24
	.byte		N11   
	.byte	W17
	.byte		N06   , An0 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        An0 
	.byte	W13
	.byte		N11   , Dn1 
	.byte	W11
	.byte		N12   , An0 
	.byte	W12
	.byte		N24   , Cs1 
	.byte	W01
@ 008   ----------------------------------------
	.byte	W24
	.byte		N11   
	.byte	W17
	.byte		N06   , Gs0 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        Gs0 
	.byte	W13
	.byte		N11   , Cs1 
	.byte	W11
	.byte		N12   , Gs0 
	.byte	W12
	.byte		N24   , Cn1 
	.byte	W01
@ 009   ----------------------------------------
mus_bloody_stream_8_009:
	.byte	W23
	.byte		N12   , Cn1 , v100
	.byte	W18
	.byte		N06   , Gn0 
	.byte	W12
	.byte		        As0 
	.byte	W06
	.byte		        Gn0 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		N24   , Ds1 
	.byte	W01
	.byte	PEND
@ 010   ----------------------------------------
mus_bloody_stream_8_010:
	.byte	W23
	.byte		N12   , Ds1 , v100
	.byte	W18
	.byte		N06   , As0 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        As0 
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N24   , Dn1 
	.byte	W01
	.byte	PEND
@ 011   ----------------------------------------
	.byte	W23
	.byte		N12   
	.byte	W18
	.byte		N06   , An0 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        An0 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		N36   , Cs1 
	.byte	W01
@ 012   ----------------------------------------
	.byte	W40
	.byte	W01
	.byte		N06   
	.byte	W18
	.byte		N12   , An0 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , As0 
	.byte	W12
	.byte		N24   , Cn1 
	.byte	W01
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_8_009
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_8_010
@ 015   ----------------------------------------
	.byte	W23
	.byte		N12   , Dn1 , v100
	.byte	W18
	.byte		N06   , An0 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        An0 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		N24   , Cs1 
	.byte	W01
@ 016   ----------------------------------------
	.byte	W23
	.byte		N12   
	.byte	W18
	.byte		N06   , Gs0 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        Gs0 
	.byte	W12
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		N24   , Cn1 
	.byte	W01
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_8_009
@ 018   ----------------------------------------
	.byte	W23
	.byte		N12   , Ds1 , v100
	.byte	W18
	.byte		N06   , As0 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        As0 
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N36   , Gs0 
	.byte	W01
@ 019   ----------------------------------------
	.byte	W40
	.byte	W01
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N36   , Gn0 
	.byte	W01
@ 020   ----------------------------------------
	.byte	W40
	.byte	W01
	.byte		N06   , Bn0 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N24   , Dn1 
	.byte	W24
	.byte		N48   , Fn1 
	.byte	W01
@ 021   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N48   , Cs1 
	.byte	W01
@ 022   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		N06   , Gs0 
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs0 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N48   , Cn1 
	.byte	W01
@ 023   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		N06   , Gn0 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N48   , As0 
	.byte	W01
@ 024   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		N06   , Fn0 
	.byte	W06
	.byte		        As0 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N36   , An0 
	.byte	W01
@ 025   ----------------------------------------
	.byte	W40
	.byte	W01
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn0 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		N36   , Gs0 
	.byte	W01
@ 026   ----------------------------------------
	.byte	W40
	.byte	W01
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		N96   , Gn0 
	.byte	W01
@ 027   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N06   
	.byte	W01
@ 028   ----------------------------------------
	.byte	W05
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Gn0 
	.byte	W19
@ 029   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N12   , Cn1 
	.byte	W01
@ 030   ----------------------------------------
mus_bloody_stream_8_030:
	.byte	W11
	.byte		N24   , Cn1 , v100
	.byte	W30
	.byte		N06   , Fn0 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn0 
	.byte	W12
	.byte		N12   , Gs0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds1 
	.byte	W01
	.byte	PEND
@ 031   ----------------------------------------
mus_bloody_stream_8_031:
	.byte	W11
	.byte		N24   , Ds1 , v100
	.byte	W30
	.byte		N06   , Gs0 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An0 
	.byte	W12
	.byte		N12   , As0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W01
	.byte	PEND
@ 032   ----------------------------------------
mus_bloody_stream_8_032:
	.byte	W11
	.byte		N24   , Gs0 , v100
	.byte	W30
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		N06   , Gn0 
	.byte	W01
	.byte	PEND
@ 033   ----------------------------------------
	.byte	W11
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W01
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_8_030
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_8_031
@ 036   ----------------------------------------
	.byte	W11
	.byte		N24   , Gs0 , v100
	.byte	W30
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W01
@ 037   ----------------------------------------
	.byte	W05
	.byte		        Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W12
	.byte		N30   , Fn1 
	.byte	W36
	.byte		N12   , Cn1 
	.byte	W01
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_8_030
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_8_031
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_8_032
@ 041   ----------------------------------------
	.byte	W11
	.byte		N06   , Gn0 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Fn0 
	.byte	W01
@ 042   ----------------------------------------
	.byte	W11
	.byte		N24   
	.byte	W30
	.byte		N06   , Ds1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Gn0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N24   , Cs1 
	.byte	W01
@ 043   ----------------------------------------
	.byte	W23
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , Gs0 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N03   , Gs0 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W01
@ 044   ----------------------------------------
	.byte	W11
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W01
@ 045   ----------------------------------------
	.byte	W23
	.byte		N72   , Gn0 
	.byte	W72
	.byte		N12   , Gs0 
	.byte	W01
@ 046   ----------------------------------------
	.byte	W11
	.byte		N12   
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N12   , Gs0 
	.byte	W12
	.byte		N18   , Cn1 
	.byte	W18
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        As0 
	.byte	W01
@ 047   ----------------------------------------
	.byte	W11
	.byte		N12   
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N12   , As0 
	.byte	W12
	.byte		N18   , Dn1 
	.byte	W18
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		TIE   , Cn1 
	.byte	W01
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W48
	.byte		EOT 
	.byte   W48
@ 050   ----------------------------------------
	.byte	GOTO
	.word	mus_bloody_stream_8_001
	.byte	FINE

@**************** Track 9 (Midi-Chn.10) ****************@

mus_bloody_stream_9:
	.byte	KEYSH , mus_bloody_stream_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 96
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*mus_bloody_stream_mvl/mxv
@ 001   ----------------------------------------
mus_bloody_stream_9_001:
	.byte		N05   , CsM1, v100
	.byte		N05   , Cn1 
	.byte	W24
	.byte		        CsM1
	.byte		N05   , Cn1 
	.byte	W24
	.byte		        CsM1
	.byte		N05   , Cn1 
	.byte	W17
	.byte		N06   , CsM1
	.byte		N06   , Cn1 
	.byte	W18
	.byte		N06   
	.byte		N06   , Cs2 
	.byte	W13
@ 002   ----------------------------------------
	.byte		N05   , CsM1
	.byte	W11
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W07
	.byte		N05   
	.byte		N05   , Cn1 
	.byte		N05   , En1 
	.byte	W11
	.byte		N06   , CsM1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte		N06   , Cs2 
	.byte	W01
@ 003   ----------------------------------------
	.byte	W11
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W07
	.byte		N05   , CsM1
	.byte		N05   , En1 
	.byte	W05
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W07
	.byte		N05   
	.byte		N05   , Cn1 
	.byte	W05
	.byte		N06   , En1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , En1 
	.byte	W07
	.byte		N05   , CsM1
	.byte		N05   , Cn1 
	.byte	W11
	.byte		N06   
	.byte		N06   , En1 
	.byte	W13
@ 004   ----------------------------------------
	.byte	W48
	.byte		N05   , Cn1 
	.byte	W24
	.byte		        En1 
	.byte	W05
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W07
@ 005   ----------------------------------------
	.byte		N05   , CsM1
	.byte		N05   , Cn1 
	.byte		N05   , An2 
	.byte	W11
	.byte		N06   , CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W07
	.byte		N05   , CsM1
	.byte	W05
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , En1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W07
@ 006   ----------------------------------------
	.byte		N05   
	.byte		N05   , Cn1 
	.byte	W11
	.byte		N06   , CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W07
	.byte		N05   , En1 
	.byte	W11
	.byte		N06   , CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W07
	.byte		N05   , CsM1
	.byte	W05
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W07
	.byte		N05   
	.byte		N05   , En1 
	.byte	W11
	.byte		N06   , CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W07
@ 007   ----------------------------------------
	.byte		N05   
	.byte		N05   , Cn1 
	.byte	W11
	.byte		N06   , CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W07
	.byte		N05   , En1 
	.byte	W11
	.byte		N06   , CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W07
	.byte		N05   , CsM1
	.byte	W05
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W07
	.byte		N05   
	.byte		N05   , En1 
	.byte	W11
	.byte		N06   , CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W01
@ 008   ----------------------------------------
	.byte	W11
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W07
	.byte		N05   , En1 
	.byte	W11
	.byte		N06   , CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W07
	.byte		N05   
	.byte		N05   , En1 
	.byte	W11
	.byte		N06   , CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W01
@ 009   ----------------------------------------
mus_bloody_stream_9_009:
	.byte	W11
	.byte		N06   , CsM1, v100
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , En1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W01
	.byte	PEND
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_009
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_009
@ 012   ----------------------------------------
	.byte	W05
	.byte		N06   , CsM1, v100
	.byte	W12
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W12
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W12
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte		N06   , An2 
	.byte	W01
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_009
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_009
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_009
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_009
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_009
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_009
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_009
@ 020   ----------------------------------------
	.byte	W05
	.byte		N06   , CsM1, v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte		N06   , An2 
	.byte	W01
@ 021   ----------------------------------------
mus_bloody_stream_9_021:
	.byte	W05
	.byte		N06   , CsM1, v100
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W01
	.byte	PEND
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_021
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_021
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_021
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_021
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_021
@ 027   ----------------------------------------
	.byte	W11
	.byte		N06   , CsM1, v088
	.byte	W06
	.byte		        CsM1, v100
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Cn1 
	.byte	W01
@ 028   ----------------------------------------
	.byte	W05
	.byte		N06   
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte		N06   , En1 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , En1 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , En1 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , En1 
	.byte	W19
@ 029   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte		N06   , An2 
	.byte	W01
@ 030   ----------------------------------------
mus_bloody_stream_9_030:
	.byte	W11
	.byte		N06   , CsM1, v100
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W01
	.byte	PEND
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_030
@ 032   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_030
@ 033   ----------------------------------------
	.byte	W11
	.byte		N06   , CsM1, v100
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte		N06   , An2 
	.byte	W01
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_030
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_030
@ 036   ----------------------------------------
	.byte	W11
	.byte		N06   , CsM1, v100
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W01
@ 037   ----------------------------------------
	.byte	W05
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte		N06   , Cs2 
	.byte	W36
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte		N06   , An2 
	.byte	W01
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_030
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_030
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_030
@ 041   ----------------------------------------
	.byte	W11
	.byte		N06   , CsM1, v100
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W01
@ 042   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_030
@ 043   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_030
@ 044   ----------------------------------------
	.byte	W11
	.byte		N06   , CsM1, v100
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W07
@ 045   ----------------------------------------
	.byte	W23
	.byte		        En1 
	.byte		N06   , An2 
	.byte	W12
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte		N06   , An2 
	.byte	W01
@ 046   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_9_030
@ 047   ----------------------------------------
	.byte	W11
	.byte		N06   , CsM1, v100
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , DsM1 
	.byte	W01
@ 048   ----------------------------------------
	.byte	W05
	.byte		N06 ,   DsM1 , v044
	.byte	W06
	.byte		        DsM1 , v080
	.byte	W12
	.byte		        Cn1 , v100
	.byte		N06   , DsM1 
	.byte	W06
	.byte		        DsM1 , v048
	.byte	W06
	.byte		        DsM1 , v080
	.byte	W12
	.byte		        Cn1 , v100
	.byte		N06   , DsM1 
	.byte	W06
	.byte		        DsM1 , v044
	.byte	W06
	.byte		        DsM1 , v080
	.byte	W12
	.byte		        Cn1 , v100
	.byte		N06   , DsM1 
	.byte	W06
	.byte		        DsM1 , v044
	.byte	W06
	.byte		        DsM1 , v080
	.byte	W12
	.byte		        Cn1 , v100
	.byte		N06   , DsM1 
	.byte	W01
@ 049   ----------------------------------------
	.byte	W05
	.byte		        DsM1 , v044
	.byte	W06
	.byte		        DsM1 , v080
	.byte	W12
	.byte		        Cn1 , v100
	.byte		N06   , DsM1 
	.byte	W06
	.byte		        DsM1 , v048
	.byte	W06
	.byte		        DsM1 , v080
	.byte	W12
	.byte		N06 ,	En1 , v127
	.byte		N06 , Cn1 , v127
	.byte	W06
	.byte			En1
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte			En1
	.byte	W06
	.byte			En1
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte	W01
@ 050   ----------------------------------------
	.byte	GOTO
	.word	mus_bloody_stream_9_001
	.byte	FINE

@**************** Track 10 (Midi-Chn.11) ****************@

mus_bloody_stream_10:
	.byte	KEYSH , mus_bloody_stream_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 34
	.byte		PAN   , c_v+0
	.byte		VOL   , 107*mus_bloody_stream_mvl/mxv
@ 001   ----------------------------------------
mus_bloody_stream_10_001:
	.byte		N24   , Cn1 , v100
	.byte	W24
	.byte		        Bn0 
	.byte	W24
	.byte		N17   , As0 
	.byte	W17
	.byte		N06   , An0 
	.byte	W18
	.byte		N12   , Gs0 
	.byte	W13
@ 002   ----------------------------------------
	.byte	W11
	.byte		N09   , Cn1 
	.byte	W13
	.byte		N23   , Bn0 
	.byte	W23
	.byte		N06   , As0 
	.byte	W06
	.byte		        An0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Gn0 
	.byte	W12
	.byte		N24   , Cn1 
	.byte	W01
@ 003   ----------------------------------------
	.byte	W24
	.byte		        Bn0 
	.byte	W24
	.byte		N17   , As0 
	.byte	W17
	.byte		N06   , An0 
	.byte	W18
	.byte		N48   , Gn0 
	.byte	W13
@ 004   ----------------------------------------
	.byte	W48
	.byte		N11   
	.byte	W11
	.byte		N36   , Gn1 
	.byte	W36
	.byte	W01
@ 005   ----------------------------------------
	.byte		N23   , Cn1 
	.byte	W23
	.byte		N12   
	.byte	W18
	.byte		N06   , Gn0 
	.byte	W12
	.byte		        As0 
	.byte	W06
	.byte		        Gn0 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W13
@ 006   ----------------------------------------
	.byte		N24   , Ds1 
	.byte	W24
	.byte		N11   
	.byte	W17
	.byte		N06   , As0 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        As0 
	.byte	W13
	.byte		N11   , Ds1 
	.byte	W11
	.byte		N12   , As0 
	.byte	W13
@ 007   ----------------------------------------
	.byte		N24   , Dn1 
	.byte	W24
	.byte		N11   
	.byte	W17
	.byte		N06   , An0 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        An0 
	.byte	W13
	.byte		N11   , Dn1 
	.byte	W11
	.byte		N12   , An0 
	.byte	W12
	.byte		N24   , Cs1 
	.byte	W01
@ 008   ----------------------------------------
	.byte	W24
	.byte		N11   
	.byte	W17
	.byte		N06   , Gs0 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        Gs0 
	.byte	W13
	.byte		N11   , Cs1 
	.byte	W11
	.byte		N12   , Gs0 
	.byte	W12
	.byte		N24   , Cn1 
	.byte	W01
@ 009   ----------------------------------------
mus_bloody_stream_10_009:
	.byte	W23
	.byte		N12   , Cn1 , v100
	.byte	W18
	.byte		N06   , Gn0 
	.byte	W12
	.byte		        As0 
	.byte	W06
	.byte		        Gn0 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		N24   , Ds1 
	.byte	W01
	.byte	PEND
@ 010   ----------------------------------------
mus_bloody_stream_10_010:
	.byte	W23
	.byte		N12   , Ds1 , v100
	.byte	W18
	.byte		N06   , As0 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        As0 
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N24   , Dn1 
	.byte	W01
	.byte	PEND
@ 011   ----------------------------------------
	.byte	W23
	.byte		N12   
	.byte	W18
	.byte		N06   , An0 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        An0 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		N36   , Cs1 
	.byte	W01
@ 012   ----------------------------------------
	.byte	W40
	.byte	W01
	.byte		N06   
	.byte	W18
	.byte		N12   , An0 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , As0 
	.byte	W12
	.byte		N24   , Cn1 
	.byte	W01
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_10_009
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_10_010
@ 015   ----------------------------------------
	.byte	W23
	.byte		N12   , Dn1 , v100
	.byte	W18
	.byte		N06   , An0 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        An0 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		N24   , Cs1 
	.byte	W01
@ 016   ----------------------------------------
	.byte	W23
	.byte		N12   
	.byte	W18
	.byte		N06   , Gs0 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        Gs0 
	.byte	W12
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		N24   , Cn1 
	.byte	W01
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_10_009
@ 018   ----------------------------------------
	.byte	W23
	.byte		N12   , Ds1 , v100
	.byte	W18
	.byte		N06   , As0 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		        As0 
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N36   , Gs0 
	.byte	W01
@ 019   ----------------------------------------
	.byte	W40
	.byte	W01
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N36   , Gn0 
	.byte	W01
@ 020   ----------------------------------------
	.byte	W40
	.byte	W01
	.byte		N06   , Bn0 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N24   , Dn1 
	.byte	W24
	.byte		N48   , Fn1 
	.byte	W01
@ 021   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N48   , Cs1 
	.byte	W01
@ 022   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		N06   , Gs0 
	.byte	W06
	.byte		        Cs1 
	.byte	W12
	.byte		        Gs0 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N48   , Cn1 
	.byte	W01
@ 023   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		N06   , Gn0 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N48   , As0 
	.byte	W01
@ 024   ----------------------------------------
	.byte	W44
	.byte	W03
	.byte		N06   , Fn0 
	.byte	W06
	.byte		        As0 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N36   , An0 
	.byte	W01
@ 025   ----------------------------------------
	.byte	W40
	.byte	W01
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn0 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		N36   , Gs0 
	.byte	W01
@ 026   ----------------------------------------
	.byte	W40
	.byte	W01
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		N96   , Gn0 
	.byte	W01
@ 027   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N06   
	.byte	W01
@ 028   ----------------------------------------
	.byte	W05
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Gn0 
	.byte	W19
@ 029   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		N12   , Cn1 
	.byte	W01
@ 030   ----------------------------------------
mus_bloody_stream_10_030:
	.byte	W11
	.byte		N24   , Cn1 , v100
	.byte	W30
	.byte		N06   , Fn0 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn0 
	.byte	W12
	.byte		N12   , Gs0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds1 
	.byte	W01
	.byte	PEND
@ 031   ----------------------------------------
mus_bloody_stream_10_031:
	.byte	W11
	.byte		N24   , Ds1 , v100
	.byte	W30
	.byte		N06   , Gs0 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An0 
	.byte	W12
	.byte		N12   , As0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W01
	.byte	PEND
@ 032   ----------------------------------------
mus_bloody_stream_10_032:
	.byte	W11
	.byte		N24   , Gs0 , v100
	.byte	W30
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		N06   , Gn0 
	.byte	W01
	.byte	PEND
@ 033   ----------------------------------------
	.byte	W11
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W01
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_10_030
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_10_031
@ 036   ----------------------------------------
	.byte	W11
	.byte		N24   , Gs0 , v100
	.byte	W30
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W01
@ 037   ----------------------------------------
	.byte	W05
	.byte		        Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W12
	.byte		N30   , Fn1 
	.byte	W36
	.byte		N12   , Cn1 
	.byte	W01
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_10_030
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_10_031
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_bloody_stream_10_032
@ 041   ----------------------------------------
	.byte	W11
	.byte		N06   , Gn0 , v100
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Fn0 
	.byte	W01
@ 042   ----------------------------------------
	.byte	W11
	.byte		N24   
	.byte	W30
	.byte		N06   , Ds1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Gn0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N24   , Cs1 
	.byte	W01
@ 043   ----------------------------------------
	.byte	W23
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , Gs0 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N03   , Gs0 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W01
@ 044   ----------------------------------------
	.byte	W11
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W01
@ 045   ----------------------------------------
	.byte	W23
	.byte		N72   , Gn0 
	.byte	W72
	.byte		N12   , Gs0 
	.byte	W01
@ 046   ----------------------------------------
	.byte	W11
	.byte		N12   
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N12   , Gs0 
	.byte	W12
	.byte		N18   , Cn1 
	.byte	W18
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        As0 
	.byte	W01
@ 047   ----------------------------------------
	.byte	W11
	.byte		N12   
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N12   , As0 
	.byte	W12
	.byte		N18   , Dn1 
	.byte	W18
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		TIE   , Cn1 
	.byte	W01
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W48
	.byte		EOT 
	.byte	W48
@ 050   ----------------------------------------
	.byte	GOTO
	.word	mus_bloody_stream_10_001
	.byte	FINE

@******************************************************@
	.align	2

mus_bloody_stream:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_bloody_stream_pri	@ Priority
	.byte	mus_bloody_stream_rev	@ Reverb.

	.word	mus_bloody_stream_grp

	.word	mus_bloody_stream_1
	.word	mus_bloody_stream_2
	.word	mus_bloody_stream_3
	.word	mus_bloody_stream_4
	.word	mus_bloody_stream_5
	.word	mus_bloody_stream_6
	.word	mus_bloody_stream_7
	.word	mus_bloody_stream_8
	.word	mus_bloody_stream_9
	.word	mus_bloody_stream_10

	.end

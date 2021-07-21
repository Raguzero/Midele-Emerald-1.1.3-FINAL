@ Made by WiserVisor
@ Original Source: Legend of Zelda: Wind Waker (Koji Kondo)
@ MIDI Source: https://www.vgmusic.com/file/6d0cda3a3c3f8f307f4f424a5cd82e1a.html	
@ VOICE Legend
@ 12 = voice_directsound 60, 0, marimba60, 255, 235, 0, 216
@ 14 = voice_directsound 60, 0, DirectSoundWaveData_sc88pro_tubular_bell, 255, 165, 90, 216
@ 17 = voice_directsound 60, 0, DirectSoundWaveData_sc88pro_organ2, 255, 0, 255, 165
@ 24 = voice_directsound 60, 0, DirectSoundWaveData_sc88pro_nylon_str_guitar, 255, 249, 25, 127
@ 46 = voice_directsound 60, 0, DirectSoundWaveData_sc88pro_harp, 255, 246, 0, 235
@ 47 = voice_directsound 60, 0, DirectSoundWaveData_sc88pro_timpani, 255, 165, 154, 235
@ 48 = voice_keysplit voicegroup006, KeySplitTable2
@ 56 = voice_keysplit voicegroup007, KeySplitTable3
@ 60 = voice_keysplit voicegroup009, KeySplitTable5
@ 73 = voice_directsound 60, 0, DirectSoundWaveData_sc88pro_flute, 255, 127, 231, 127
@ 96 = voice_keysplit_all voicegroup002 (Also put voice_directsound 60, 64, eggshaker, 255, 235, 0, 165 as the ninth instrument in voicegroup002)
	.include "MPlayDef.s"

	.equ	mus_molgera_ww_grp, voicegroup305
	.equ	mus_molgera_ww_pri, 0
	.equ	mus_molgera_ww_rev, 0
	.equ	mus_molgera_ww_mvl, 87
	.equ	mus_molgera_ww_key, 0
	.equ	mus_molgera_ww_tbs, 1
	.equ	mus_molgera_ww_exg, 0
	.equ	mus_molgera_ww_cmp, 1

	.section .rodata
	.global	mus_molgera_ww
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_molgera_ww_1:
	.byte	KEYSH , mus_molgera_ww_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 150*mus_molgera_ww_tbs/2
	.byte	W96
@ 001   ----------------------------------------
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
mus_molgera_ww_1_008:
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
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W96
@ 060   ----------------------------------------
	.byte	W96
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte		VOICE , 60
	.byte		VOL , 105*mus_molgera_ww_mvl/mxv
	.byte		N36   , Gs3 , v052
	.byte	W12
	.byte		VOL , 106*mus_molgera_ww_mvl/mxv
	.byte	W24
	.byte		        107*mus_molgera_ww_mvl/mxv
	.byte		N48   , Gn3 , v052
	.byte	W48
	.byte		N60   , Fn3 , v052
	.byte	W12
@ 065   ----------------------------------------
	.byte	W36
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N48   , Fn3 
	.byte	W48
@ 066   ----------------------------------------
	.byte		N36   , Gn3 , v052
	.byte	W36
	.byte		N48   , Fs3 , v052
	.byte	W48
	.byte		N60   , En3 , v052
	.byte	W12
@ 067   ----------------------------------------
	.byte	W36
	.byte		N06   , Cn3 , v064
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N48   , En3 
	.byte	W48
@ 068   ----------------------------------------
	.byte		TIE   , En3 , v032
	.byte		TIE   , Gn3 , v052
	.byte	W96
@ 069   ----------------------------------------
	.byte	W36
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		EOT   , En3 
	.byte		N48   
	.byte	W06
	.byte		        Fn3 
	.byte	W42
	.byte		EOT   , Gn3 
	.byte	W06
@ 070   ----------------------------------------
	.byte		N48   , Cn3 , v032
	.byte		N48   , An3 , v052
	.byte	W48
	.byte		        Bn2 , v032
	.byte		N48   , Gn3 , v052
	.byte	W48
@ 071   ----------------------------------------
	.byte		        Bn2 , v032
	.byte		N48   , Fs3 , v052
	.byte	W36
	.byte		N06   , Cn3 , v064
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N42   , Bn2 , v032
	.byte		N42   , En3 , v052
	.byte	W48
@ 072   ----------------------------------------
	.byte		TIE   , Cn3 , v028
	.byte		TIE   , En3 , v044
	.byte	W96
@ 073   ----------------------------------------
	.byte	W96
@ 074   ----------------------------------------
	.byte	W96
@ 075   ----------------------------------------
	.byte	W96
@ 076   ----------------------------------------
	.byte	W96
@ 077   ----------------------------------------
	.byte	W96
@ 078   ----------------------------------------
	.byte	W96
	.byte		EOT   , Cn3 
	.byte		        En3 
@ 079   ----------------------------------------
	.byte		N96   , Cn3 , v028
	.byte		N96   , En3 , v044
	.byte	W96
@ 080   ----------------------------------------
	.byte	W96
@ 081   ----------------------------------------
	.byte	W96
@ 082   ----------------------------------------
	.byte	W96
@ 083   ----------------------------------------
	.byte	W96
@ 084   ----------------------------------------
	.byte	W96
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte	W96
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte	GOTO
	.word	mus_molgera_ww_1_008
	.byte	FINE

@**************** Track 2 (Midi-Chn.9) ****************@

mus_molgera_ww_2:
	.byte		VOL   , 107*mus_molgera_ww_mvl/mxv
	.byte	KEYSH , mus_molgera_ww_key+0
@ 000   ----------------------------------------
	.byte	W96
@ 001   ----------------------------------------
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
mus_molgera_ww_2_008:
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
mus_molgera_ww_2_048:
	.byte		VOICE , 48
	.byte		N18   , En1 , v127
	.byte	W36
	.byte		        En2 
	.byte		VOICE , 17
	.byte		N09   , Cs3 , v048
	.byte		N09   , En3 , v064
	.byte		N09   , Fs3 , v080
	.byte	W24
	.byte		VOICE , 48
	.byte		N18   , En1 , v127
	.byte	W24
	.byte		N12   , En2 
	.byte	W12
	.byte	PEND
@ 049   ----------------------------------------
mus_molgera_ww_2_049:
	.byte		VOICE , 48
	.byte		N18   , En1 , v127
	.byte	W24
	.byte		        En2 
	.byte	W12
	.byte		VOICE , 17
	.byte		N09   , Cs3 , v044
	.byte		N09   , En3 , v064
	.byte		N09   , Fs3 , v080
	.byte	W12
	.byte		VOICE , 48
	.byte		N18   , En1 , v127
	.byte	W24
	.byte		        En2 
	.byte		VOICE , 17
	.byte		N09   , Cs3 , v044
	.byte		N09   , En3 , v064
	.byte		N09   , Fs3 , v080
	.byte	W24
	.byte	PEND
@ 050   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_2_048
@ 051   ----------------------------------------
mus_molgera_ww_2_051:
	.byte		VOICE , 48
	.byte		N18   , Fn1 , v127
	.byte	W24
	.byte		        Fn2 
	.byte	W12
	.byte		VOICE , 17
	.byte		N09   , Cn3 , v044
	.byte		N09   , En3 , v064
	.byte		N09   , Gn3 , v080
	.byte	W12
	.byte		VOICE , 48
	.byte		N18   , Fn1 , v127
	.byte	W24
	.byte		        Fn2 
	.byte		VOICE , 17
	.byte		N09   , Cn3 , v044
	.byte		N09   , En3 , v064
	.byte		N09   , Gn3 , v080
	.byte	W24
	.byte	PEND
@ 052   ----------------------------------------
mus_molgera_ww_2_052:
	.byte		VOICE , 48
	.byte		N18   , Fs1 , v127
	.byte	W36
	.byte		        Fs2 
	.byte		VOICE , 17
	.byte		N09   , Cs3 , v048
	.byte		N09   , En3 , v064
	.byte		N09   , Fs3 , v080
	.byte	W24
	.byte		VOICE , 48
	.byte		N18   , Fs1 , v127
	.byte	W24
	.byte		N12   , Fs2 
	.byte	W12
	.byte	PEND
@ 053   ----------------------------------------
mus_molgera_ww_2_053:
	.byte		VOICE , 48
	.byte		N18   , Fs1 , v127
	.byte	W24
	.byte		        Fs2 
	.byte	W12
	.byte		VOICE , 17
	.byte		N09   , Cs3 , v044
	.byte		N09   , En3 , v064
	.byte		N09   , Fs3 , v080
	.byte	W12
	.byte		VOICE , 48
	.byte		N18   , Gn1 , v127
	.byte	W24
	.byte		        Gn2 
	.byte		VOICE , 17
	.byte		N09   , Cn3 , v044
	.byte		N09   , Fn3 , v064
	.byte		N09   , Gn3 , v080
	.byte	W24
	.byte	PEND
@ 054   ----------------------------------------
mus_molgera_ww_2_054:
	.byte		VOICE , 48
	.byte		N18   , An1 , v127
	.byte	W36
	.byte		        An2 , v127
	.byte		VOICE , 17
	.byte		N18   , An2 , v072
	.byte		N09   , Bn2 , v064
	.byte		N09   , En3 , v080
	.byte	W24
	.byte		VOICE , 48
	.byte		N18   , Bn1 , v127
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W12
	.byte	PEND
@ 055   ----------------------------------------
mus_molgera_ww_2_055:
	.byte		VOICE , 48
	.byte		N18   , En1 , v127
	.byte	W24
	.byte		        En2 
	.byte	W12
	.byte		VOICE , 17
	.byte		N09   , An2 , v044
	.byte		N09   , Bn2 , v064
	.byte		N09   , En3 , v080
	.byte	W12
	.byte		VOICE , 48
	.byte		N18   , En1 , v127
	.byte	W24
	.byte		        En2 
	.byte		VOICE , 17
	.byte		N09   , An2 , v044
	.byte		N09   , Bn2 , v064
	.byte		N09   , En3 , v080
	.byte	W24
	.byte	PEND
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_2_048
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_2_049
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_2_048
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_2_051
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_2_052
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_2_053
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_2_054
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
mus_molgera_ww_2_064:
	.byte		VOICE , 48
	.byte		N18   , Fn1 , v127
	.byte	W36
	.byte		        Fn2 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		N12   , Fn2 
	.byte	W12
	.byte	PEND
@ 065   ----------------------------------------
mus_molgera_ww_2_065:
	.byte		N18   , Fn1 , v127
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte	PEND
@ 066   ----------------------------------------
mus_molgera_ww_2_066:
	.byte		N18   , En1 , v127
	.byte	W36
	.byte		        En2 
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		N12   , En2 
	.byte	W12
	.byte	PEND
@ 067   ----------------------------------------
mus_molgera_ww_2_067:
	.byte		N18   , En1 , v127
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        En1 
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte	PEND
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_2_064
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_2_065
@ 070   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_2_066
@ 071   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_2_067
@ 072   ----------------------------------------
	.byte		N12   , An1 , v127
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
@ 073   ----------------------------------------
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
@ 074   ----------------------------------------
	.byte		        Gn1 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
@ 075   ----------------------------------------
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
@ 076   ----------------------------------------
	.byte		        Fs1 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
@ 077   ----------------------------------------
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
@ 078   ----------------------------------------
	.byte		        Bn1 
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
@ 079   ----------------------------------------
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
@ 080   ----------------------------------------
	.byte		        En1 , v127
	.byte	W36
	.byte		VOICE , 17
	.byte		N07   , En1 , v064
	.byte		N07   , En2 
	.byte		VOICE , 48
	.byte		N07   , En2 , v104
	.byte		VOICE , 17
	.byte		N04   , En3 , v084
	.byte	W60
@ 081   ----------------------------------------
mus_molgera_ww_2_081:
	.byte	W24
	.byte		VOICE , 17
	.byte		N07   , En1 , v064
	.byte		N07   , En2 
	.byte		N04   , En3 , v084
	.byte		VOICE , 48
	.byte		N07   , En2 , v104
	.byte	W72
	.byte	PEND
@ 082   ----------------------------------------
	.byte	W36
	.byte		VOICE , 17
	.byte		N07   , En1 , v064
	.byte		N07   , En2 
	.byte		N04   , En3 , v084
	.byte		VOICE , 48
	.byte		N07   , En2 , v104
	.byte	W60
@ 083   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_2_081
@ 084   ----------------------------------------
	.byte	W96
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte	W96
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte	GOTO
	.word	mus_molgera_ww_2_008
	.byte	FINE

@**************** Track 3 (Midi-Chn.4) ****************@

mus_molgera_ww_3:
	.byte	KEYSH , mus_molgera_ww_key+0
@ 000   ----------------------------------------
	.byte		VOL   , 127*mus_molgera_ww_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
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
mus_molgera_ww_3_008:
	.byte		VOICE , 24
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
mus_molgera_ww_3_048:
	.byte	W36
	.byte		N06   , En2 , v084
	.byte	W48
	.byte		N06   
	.byte	W12
	.byte	PEND
@ 049   ----------------------------------------
mus_molgera_ww_3_049:
	.byte	W24
	.byte		N06   , En2 , v084
	.byte	W48
	.byte		N06   
	.byte	W24
	.byte	PEND
@ 050   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_048
@ 051   ----------------------------------------
mus_molgera_ww_3_051:
	.byte	W24
	.byte		N06   , Fn2 , v084
	.byte	W48
	.byte		N06   
	.byte	W24
	.byte	PEND
@ 052   ----------------------------------------
mus_molgera_ww_3_052:
	.byte	W36
	.byte		N06   , Fs2 , v084
	.byte	W48
	.byte		N06   
	.byte	W12
	.byte	PEND
@ 053   ----------------------------------------
mus_molgera_ww_3_053:
	.byte	W24
	.byte		N06   , Fs2 , v084
	.byte	W48
	.byte		        Gn2 
	.byte	W24
	.byte	PEND
@ 054   ----------------------------------------
mus_molgera_ww_3_054:
	.byte	W36
	.byte		N06   , An2 , v084
	.byte	W48
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_049
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_048
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_049
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_048
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_051
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_052
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_053
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_054
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_049
@ 064   ----------------------------------------
mus_molgera_ww_3_064:
	.byte	W36
	.byte		N06   , Fn2 , v084
	.byte	W48
	.byte		N06   
	.byte	W12
	.byte	PEND
@ 065   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_051
@ 066   ----------------------------------------
	.byte		PAN   , c_v+19
	.byte	W36
	.byte		N06   , En2 , v084
	.byte	W48
	.byte		N06   
	.byte	W12
@ 067   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_049
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_064
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_051
@ 070   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_048
@ 071   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_049
@ 072   ----------------------------------------
mus_molgera_ww_3_072:
	.byte		VOICE , 12
	.byte		N03   , En3 , v127
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte	PEND
@ 073   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 074   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 075   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 076   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 077   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 078   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 079   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 080   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 081   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 082   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 083   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 084   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 085   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 086   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_3_072
@ 087   ----------------------------------------
	.byte		N03   , En3 , v127
	.byte	W96
@ 088   ----------------------------------------
	.byte	GOTO
	.word	mus_molgera_ww_3_008
	.byte	FINE

@**************** Track 4 (Midi-Chn.7) ****************@

mus_molgera_ww_4:
	.byte	KEYSH , mus_molgera_ww_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 73
	.byte		VOL   , 117*mus_molgera_ww_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
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
	.byte	W84
	.byte		N12   , Bn5 , v118
	.byte	W12
@ 008   ----------------------------------------
mus_molgera_ww_4_008:
	.byte		N18   , Fs5 , v118
	.byte	W18
	.byte		N06   , En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		N24   , En5 
	.byte	W24
	.byte	PEND
@ 009   ----------------------------------------
mus_molgera_ww_4_009:
	.byte		N06   , Bn4 , v118
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		N60   , En5 
	.byte	W60
	.byte		N12   , Bn5 
	.byte	W12
	.byte	PEND
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_008
@ 011   ----------------------------------------
mus_molgera_ww_4_011:
	.byte		N06   , Bn4 , v118
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		N56   , An5 , v095
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 012   ----------------------------------------
mus_molgera_ww_4_012:
	.byte		N15   , Cn6 , v095
	.byte	W18
	.byte		N06   , Bn5 
	.byte	W06
	.byte		        An5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		N18   , Fs5 , v118
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 013   ----------------------------------------
mus_molgera_ww_4_013:
	.byte		N15   , An5 , v118
	.byte	W18
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		N18   , En5 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 014   ----------------------------------------
mus_molgera_ww_4_014:
	.byte		N15   , Gn5 , v118
	.byte	W18
	.byte		N06   , Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N18   , Dn5 
	.byte	W24
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte	PEND
@ 015   ----------------------------------------
mus_molgera_ww_4_015:
	.byte		N12   , En5 , v118
	.byte	W24
	.byte		N56   
	.byte	W60
	.byte		N12   , Bn5 
	.byte	W12
	.byte	PEND
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_008
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_009
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_008
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_011
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_012
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_013
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_014
@ 023   ----------------------------------------
mus_molgera_ww_4_023:
	.byte		N12   , En5 , v118
	.byte	W24
	.byte		N56   
	.byte	W72
	.byte	PEND
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte		PAN   , c_v+5
	.byte	W48
	.byte	W48
@ 026   ----------------------------------------
mus_molgera_ww_4_026:
	.byte	W12
	.byte		N06   , Dn5 , v114
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte	PEND
@ 027   ----------------------------------------
mus_molgera_ww_4_027:
	.byte		N06   , Cn5 , v114
	.byte	W12
	.byte		        An5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        An5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W12
	.byte		VOL   , 118*mus_molgera_ww_mvl/mxv
	.byte		N24   , Bn4 
	.byte	W01
	.byte		VOL   , 110*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        102*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        86*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        78*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        70*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        55*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        47*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        39*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        23*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        15*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        7*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte	PEND
@ 028   ----------------------------------------
	.byte		        0*mus_molgera_ww_mvl/mxv
	.byte	W72
	.byte		        127*mus_molgera_ww_mvl/mxv
	.byte	W24
@ 029   ----------------------------------------
mus_molgera_ww_4_029:
	.byte	W60
	.byte		N06   , Bn5 , v114
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Dn6 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte	PEND
@ 030   ----------------------------------------
mus_molgera_ww_4_030:
	.byte		N06   , Bn5 , v114
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte	PEND
@ 031   ----------------------------------------
mus_molgera_ww_4_031:
	.byte		N06   , En5 , v114
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W12
	.byte	PEND
@ 032   ----------------------------------------
mus_molgera_ww_4_032:
	.byte		N06   , An4 , v106
	.byte	W12
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N30   , Dn5 
	.byte	W36
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N48   , Cn5 
	.byte	W24
	.byte	PEND
@ 033   ----------------------------------------
mus_molgera_ww_4_033:
	.byte	W36
	.byte		N06   , Bn4 , v106
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N24   , Bn4 
	.byte	W24
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte	PEND
@ 034   ----------------------------------------
mus_molgera_ww_4_034:
	.byte		N06   , En5 , v106
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		N36   , An5 
	.byte	W36
	.byte		N12   , Bn5 
	.byte	W12
	.byte		        Cn6 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte	PEND
@ 035   ----------------------------------------
mus_molgera_ww_4_035:
	.byte		N06   , Gn5 , v106
	.byte	W12
	.byte		        En6 , v090
	.byte	W06
	.byte		        Fn6 
	.byte	W06
	.byte		N24   , En6 
	.byte	W24
	.byte		        Dn6 , v095
	.byte	W24
	.byte		N06   , An5 
	.byte	W12
	.byte		        Cn6 
	.byte	W12
	.byte	PEND
@ 036   ----------------------------------------
mus_molgera_ww_4_036:
	.byte		N24   , Dn6 , v095
	.byte	W24
	.byte		N06   , An5 , v106
	.byte	W12
	.byte		        Cn6 
	.byte	W12
	.byte		N18   , En6 , v090
	.byte	W18
	.byte		N06   , Dn6 
	.byte	W06
	.byte		        Cn6 
	.byte	W12
	.byte		        En6 
	.byte	W12
	.byte	PEND
@ 037   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_036
@ 038   ----------------------------------------
mus_molgera_ww_4_038:
	.byte		N06   , Dn6 , v106
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		N12   , Dn6 
	.byte	W12
	.byte		N06   , An5 
	.byte	W12
	.byte		        Cn6 
	.byte	W12
	.byte		N18   , Bn5 
	.byte	W24
	.byte		N18   
	.byte	W24
	.byte	PEND
@ 039   ----------------------------------------
mus_molgera_ww_4_039:
	.byte	W12
	.byte		N06   , Dn6 , v106
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Dn6 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		N24   , Bn5 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte	PEND
@ 040   ----------------------------------------
	.byte		N06   , En6 
	.byte	W96
@ 041   ----------------------------------------
	.byte	W84
	.byte		N12   , Gs5 , v110
	.byte	W12
@ 042   ----------------------------------------
mus_molgera_ww_4_042:
	.byte		N12   , An5 , v110
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        Dn6 
	.byte	W12
	.byte		N06   , En6 
	.byte	W60
	.byte	PEND
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W96
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W84
	.byte		VOL , 117*mus_molgera_ww_mvl/mxv
	.byte		N12   , Bn5 , v118
	.byte	W12
@ 048   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_008
@ 049   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_009
@ 050   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_008
@ 051   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_011
@ 052   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_012
@ 053   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_013
@ 054   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_014
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_015
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_008
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_009
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_008
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_011
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_012
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_013
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_014
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_023
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_026
@ 067   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_027
@ 068   ----------------------------------------
	.byte		VOL   , 0*mus_molgera_ww_mvl/mxv
	.byte	W72
	.byte		        127*mus_molgera_ww_mvl/mxv
	.byte	W24
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_029
@ 070   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_030
@ 071   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_031
@ 072   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_032
@ 073   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_033
@ 074   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_034
@ 075   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_035
@ 076   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_036
@ 077   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_036
@ 078   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_038
@ 079   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_039
@ 080   ----------------------------------------
	.byte		N06   , En6 , v106
	.byte	W96
@ 081   ----------------------------------------
	.byte	W84
	.byte		N12   , Gs5 , v110
	.byte	W12
@ 082   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_4_042
@ 083   ----------------------------------------
	.byte	W96
@ 084   ----------------------------------------
	.byte	W96
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte	W96
@ 087   ----------------------------------------
	.byte	W84
	.byte		N12   , Bn5 , v118
	.byte	W12
@ 088   ----------------------------------------
	.byte	GOTO
	.word	mus_molgera_ww_4_008
	.byte	FINE

@**************** Track 5 (Midi-Chn.8) ****************@

mus_molgera_ww_5:
	.byte	KEYSH , mus_molgera_ww_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 48
	.byte		VOL   , 107*mus_molgera_ww_mvl/mxv
	.byte		PAN   , c_v-21
	.byte	W96
@ 001   ----------------------------------------
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
mus_molgera_ww_5_007:
	.byte	W12
	.byte		N03   , Cs4 , v080
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		N60   , Cs5 
	.byte	W72
	.byte	PEND
@ 008   ----------------------------------------
mus_molgera_ww_5_008:
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
	.byte		VOL , 67*mus_molgera_ww_mvl/mxv
	.byte		N36   , En2 , v088
	.byte		N36   , Fs2 , v052
	.byte		TIE   , Bn2 
	.byte	W01
	.byte		VOL   , 71*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        74*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        77*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        80*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        83*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        86*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        89*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        92*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        95*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        98*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        107*mus_molgera_ww_mvl/mxv
	.byte	W24
	.byte		TIE   , En2 
	.byte		N84   , Fs2 , v088
	.byte	W60
@ 017   ----------------------------------------
mus_molgera_ww_5_017:
	.byte	W24
	.byte		N24   , Gn2 , v088
	.byte	W24
	.byte		N72   , Fs2 , v052
	.byte		N24   , An2 , v088
	.byte	W24
	.byte	PEND
	.byte		EOT   , Bn2 
	.byte		N12   
	.byte	W12
	.byte		        Cn3 
	.byte	W12
@ 018   ----------------------------------------
mus_molgera_ww_5_018:
	.byte		N24   , Bn2 , v088
	.byte	W24
	.byte		N72   , Fs2 
	.byte		N72   , Bn2 , v052
	.byte	W72
	.byte	PEND
	.byte		EOT   , En2 
@ 019   ----------------------------------------
mus_molgera_ww_5_019:
	.byte		N96   , Fn2 , v052
	.byte		N72   , An2 
	.byte		N24   , Dn3 , v088
	.byte	W24
	.byte		        Cn3 
	.byte		N72   , Dn3 , v052
	.byte	W24
	.byte		N24   , Bn2 , v088
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte	PEND
@ 020   ----------------------------------------
mus_molgera_ww_5_020:
	.byte		TIE   , En2 , v052
	.byte		N48   , Fs2 
	.byte		N48   , Bn2 , v088
	.byte		N48   , En3 , v072
	.byte	W48
	.byte		        Fs2 
	.byte		N96   , Bn2 , v052
	.byte		N96   , En3 , v088
	.byte	W48
	.byte	PEND
@ 021   ----------------------------------------
	.byte		N48   , Gn2 , v072
	.byte	W48
	.byte		EOT   , En2 
	.byte		N48   , Fn2 , v052
	.byte		N36   , An2 , v072
	.byte		N18   , Cn3 , v052
	.byte		N18   , Dn3 , v088
	.byte	W18
	.byte		        Cn3 
	.byte	W18
	.byte		N12   , Gn2 
	.byte		N12   , Cn3 , v052
	.byte	W12
@ 022   ----------------------------------------
mus_molgera_ww_5_022:
	.byte		N96   , Fn2 , v052
	.byte		N48   , An2 , v088
	.byte		N48   , Cn3 , v072
	.byte	W48
	.byte		N24   , Gn2 , v088
	.byte		N48   , An2 , v052
	.byte		N48   , Dn3 , v072
	.byte	W24
	.byte		N24   , Fs2 , v088
	.byte	W24
	.byte	PEND
@ 023   ----------------------------------------
mus_molgera_ww_5_023:
	.byte		N96   , En2 , v088
	.byte		N96   , Fs2 , v052
	.byte		N96   , Bn2 
	.byte		N96   , En3 , v072
	.byte	W84
	.byte		N12   , Bn3 , v076
	.byte	W12
	.byte	PEND
@ 024   ----------------------------------------
mus_molgera_ww_5_024:
	.byte		TIE   , Fn2 , v060
	.byte		TIE   , An2 , v024
	.byte		TIE   , Cn3 , v060
	.byte		N18   , Cn4 , v076
	.byte	W18
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N78   , Cn4 
	.byte	W48
	.byte	PEND
@ 025   ----------------------------------------
mus_molgera_ww_5_025:
	.byte	W36
	.byte		N06   , Dn4 , v076
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N30   , Fn4 
	.byte	W30
	.byte		N06   , En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte	PEND
	.byte		EOT   , Fn2 
	.byte		        An2 
	.byte		        Cn3 
	.byte		N06   , Cn4 
	.byte	W06
@ 026   ----------------------------------------
mus_molgera_ww_5_026:
	.byte		N06   , En2 , v036
	.byte		N06   , Gn2 , v016
	.byte		N06   , Bn2 , v036
	.byte		N06   , Bn3 , v076
	.byte	W06
	.byte		TIE   , En2 , v060
	.byte		TIE   , Gn2 , v024
	.byte		TIE   , Bn2 , v060
	.byte	W12
	.byte		N06   , En4 , v076
	.byte	W06
	.byte		TIE   , Fs4 
	.byte	W72
	.byte	PEND
@ 027   ----------------------------------------
	.byte	W84
	.byte		EOT   
	.byte		N12   , Bn3 
	.byte	W12
	.byte		EOT   , En2 
	.byte		        Gn2 
	.byte		        Bn2 
@ 028   ----------------------------------------
mus_molgera_ww_5_028:
	.byte		TIE   , Fn2 , v060
	.byte		TIE   , An2 , v024
	.byte		TIE   , Cn3 , v060
	.byte		N18   , Cn4 , v076
	.byte	W18
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N48   , Cn5 
	.byte	W48
	.byte	PEND
@ 029   ----------------------------------------
mus_molgera_ww_5_029:
	.byte		N48   , Bn4 , v076
	.byte	W48
	.byte		        Gn4 
	.byte	W42
	.byte	PEND
	.byte		EOT   , Fn2 
	.byte		        An2 
	.byte		        Cn3 
	.byte	W06
@ 030   ----------------------------------------
mus_molgera_ww_5_030:
	.byte		N06   , En2 , v036
	.byte		N06   , Gn2 , v016
	.byte		N06   , Bn2 , v036
	.byte		N06   , Bn4 , v076
	.byte	W06
	.byte		TIE   , En2 , v060
	.byte		TIE   , Gn2 , v024
	.byte		TIE   , Bn2 , v060
	.byte	W12
	.byte		N06   , En4 , v076
	.byte	W06
	.byte		TIE   , Fs4 
	.byte	W72
	.byte	PEND
@ 031   ----------------------------------------
	.byte	W54
	.byte		EOT   
	.byte	W42
	.byte		EOT   , En2 
	.byte		        Gn2 
	.byte		        Bn2 
@ 032   ----------------------------------------
mus_molgera_ww_5_032:
	.byte		TIE   , An2 , v064
	.byte		TIE   , Cn3 , v036
	.byte		TIE   , En3 , v064
	.byte	W96
	.byte	PEND
@ 033   ----------------------------------------
	.byte	W96
	.byte		EOT   , An2 
	.byte		        Cn3 
	.byte		        En3 
@ 034   ----------------------------------------
mus_molgera_ww_5_034:
	.byte		TIE   , Gn2 , v064
	.byte		TIE   , An2 , v036
	.byte		TIE   , En3 , v064
	.byte	W96
	.byte	PEND
@ 035   ----------------------------------------
	.byte	W96
	.byte		EOT   , Gn2 
	.byte		        An2 
	.byte		        En3 
@ 036   ----------------------------------------
mus_molgera_ww_5_036:
	.byte		TIE   , Fs2 , v064
	.byte		TIE   , An2 , v036
	.byte		TIE   , En3 , v064
	.byte	W96
	.byte	PEND
@ 037   ----------------------------------------
	.byte	W96
	.byte		EOT   , Fs2 
	.byte		        An2 
	.byte		        En3 
@ 038   ----------------------------------------
mus_molgera_ww_5_038:
	.byte		TIE   , Gs2 , v036
	.byte		TIE   , Bn2 , v064
	.byte		TIE   , En3 
	.byte	W96
	.byte	PEND
@ 039   ----------------------------------------
	.byte	W96
	.byte		EOT   , Gs2 
	.byte		        Bn2 
	.byte		        En3 
@ 040   ----------------------------------------
mus_molgera_ww_5_040:
	.byte		N96   , An4 , v064
	.byte		TIE   , En5 , v056
	.byte	W96
	.byte	PEND
@ 041   ----------------------------------------
	.byte		N96   , Gs4 , v064
	.byte	W96
@ 042   ----------------------------------------
	.byte		        Gn4 
	.byte	W96
@ 043   ----------------------------------------
	.byte		        Fs4 
	.byte	W96
	.byte		EOT   , En5 
@ 044   ----------------------------------------
mus_molgera_ww_5_044:
	.byte		TIE   , Fn4 , v064
	.byte		TIE   , Cn5 
	.byte	W96
	.byte	PEND
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
	.byte		EOT   , Fn4 
	.byte		        Cn5 
@ 047   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_007
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte		N36   , En2 , v088
	.byte		N36   , Fs2 , v052
	.byte		TIE   , Bn2 
	.byte	W36
	.byte		        En2 
	.byte		N84   , Fs2 , v088
	.byte	W60
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_017
	.byte		EOT   , Bn2 
	.byte		N12   , Bn2 , v088
	.byte	W12
	.byte		        Cn3 
	.byte	W12
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_018
	.byte		EOT   , En2 
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_019
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_020
@ 061   ----------------------------------------
	.byte		N48   , Gn2 , v072
	.byte	W48
	.byte		EOT   , En2 
	.byte		N48   , Fn2 , v052
	.byte		N36   , An2 , v072
	.byte		N18   , Cn3 , v052
	.byte		N18   , Dn3 , v088
	.byte	W18
	.byte		        Cn3 
	.byte	W18
	.byte		N12   , Gn2 
	.byte		N12   , Cn3 , v052
	.byte	W12
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_022
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_023
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_024
@ 065   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_025
	.byte		EOT   , Fn2 
	.byte		        An2 
	.byte		        Cn3 
	.byte		N06   , Cn4 , v076
	.byte	W06
@ 066   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_026
@ 067   ----------------------------------------
	.byte	W84
	.byte		EOT   , Fs4 
	.byte		N12   , Bn3 , v076
	.byte	W12
	.byte		EOT   , En2 
	.byte		        Gn2 
	.byte		        Bn2 
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_028
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_029
	.byte		EOT   , Fn2 
	.byte		        An2 
	.byte		        Cn3 
	.byte	W06
@ 070   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_030
@ 071   ----------------------------------------
	.byte	W54
	.byte		EOT   , Fs4 
	.byte	W42
	.byte		        En2 
	.byte		        Gn2 
	.byte		        Bn2 
@ 072   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_032
@ 073   ----------------------------------------
	.byte	W96
	.byte		EOT   , An2 
	.byte		        Cn3 
	.byte		        En3 
@ 074   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_034
@ 075   ----------------------------------------
	.byte	W96
	.byte		EOT   , Gn2 
	.byte		        An2 
	.byte		        En3 
@ 076   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_036
@ 077   ----------------------------------------
	.byte	W96
	.byte		EOT   , Fs2 
	.byte		        An2 
	.byte		        En3 
@ 078   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_038
@ 079   ----------------------------------------
	.byte	W96
	.byte		EOT   , Gs2 
	.byte		        Bn2 
	.byte		        En3 
@ 080   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_040
@ 081   ----------------------------------------
	.byte		N96   , Gs4 , v064
	.byte	W96
@ 082   ----------------------------------------
	.byte		        Gn4 
	.byte	W96
@ 083   ----------------------------------------
	.byte		        Fs4 
	.byte	W96
	.byte		EOT   , En5 
@ 084   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_044
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte	W96
	.byte		EOT   , Fn4 
	.byte		        Cn5 
@ 087   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_5_007
@ 088   ----------------------------------------
	.byte	GOTO
	.word	mus_molgera_ww_5_008
	.byte	FINE

@**************** Track 6 (Midi-Chn.11) ****************@

mus_molgera_ww_6:
	.byte	KEYSH , mus_molgera_ww_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 48
	.byte		VOL   , 102*mus_molgera_ww_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
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
mus_molgera_ww_6_008:
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
	.byte	W48
	.byte		PAN   , c_v-29
	.byte	W48
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W96
@ 060   ----------------------------------------
	.byte	W96
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte		N36   , Ds3 , v048
	.byte	W36
	.byte		N48   , Dn3 , v048
	.byte	W48 
	.byte		N96   , Cn3 , v048
	.byte	W12
@ 065   ----------------------------------------
mus_molgera_ww_6_065:
	.byte	W36
	.byte		N06   , Dn3 , v092
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N48   , Fn3 , v092
	.byte	W48
	.byte	PEND
@ 066   ----------------------------------------
	.byte		N36   , Gn3 , v068
	.byte	W36
	.byte		N48   , Fs3 , v068
	.byte	W48
	.byte		N60   , En3 , v068
	.byte	W12
@ 067   ----------------------------------------
mus_molgera_ww_6_067:
	.byte	W36
	.byte		N06   , Cn3 , v092
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N48   , En3 , v092
	.byte	W48
	.byte	PEND
@ 068   ----------------------------------------
	.byte	W96
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_6_065
@ 070   ----------------------------------------
	.byte	W96
@ 071   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_6_067
@ 072   ----------------------------------------
	.byte	W96
@ 073   ----------------------------------------
	.byte	W96
@ 074   ----------------------------------------
	.byte	W96
@ 075   ----------------------------------------
	.byte	W96
@ 076   ----------------------------------------
	.byte	W96
@ 077   ----------------------------------------
	.byte	W96
@ 078   ----------------------------------------
	.byte	W96
@ 079   ----------------------------------------
	.byte	W96
@ 080   ----------------------------------------
	.byte	W96
@ 081   ----------------------------------------
	.byte	W96
@ 082   ----------------------------------------
	.byte	W96
@ 083   ----------------------------------------
	.byte	W96
@ 084   ----------------------------------------
	.byte	W96
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte	W96
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte	GOTO
	.word	mus_molgera_ww_6_008
	.byte	FINE

@**************** Track 7 (Midi-Chn.10) ****************@

mus_molgera_ww_7:
	.byte	KEYSH , mus_molgera_ww_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 96
	.byte		VOL   , 107*mus_molgera_ww_mvl/mxv
	.byte		PAN   , c_v+23
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
mus_molgera_ww_7_004:
	.byte		N06   , GsM2 , v100
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte	PEND
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_004
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_004
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
mus_molgera_ww_7_008:
	.byte		N01   , FsM2 , v072
	.byte		N06   , GsM2 , v100
	.byte		N01   , Bn4 
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		        FsM2 , v072
	.byte		N06   , GsM2 , v100
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        FsM2 , v072
	.byte		N06   , GsM2 , v084
	.byte		N01   , Bn4 , v080
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        FsM2 , v072
	.byte		N06   , GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte	PEND
@ 009   ----------------------------------------
mus_molgera_ww_7_009:
	.byte		N01   , FsM2 , v072
	.byte		N06   , GsM2 , v100
	.byte		N01   , Bn4 , v080
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        FsM2 , v072
	.byte		N06   , GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        FsM2 , v072
	.byte		N06   , GsM2 , v084
	.byte	W03
	.byte		        FsM2 , v064
	.byte	W03
	.byte		        FsM2 , v060
	.byte		N06   , GsM2 , v100
	.byte	W03
	.byte		        FsM2 , v056
	.byte	W03
	.byte		        FsM2 , v072
	.byte		N06   , GsM2 , v100
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        FsM2 , v072
	.byte		N06   , GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte	PEND
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 013   ----------------------------------------
mus_molgera_ww_7_013:
	.byte		N01   , FsM2 , v072
	.byte		N06   , GsM2 , v100
	.byte		N01   , Bn4 , v080
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		        FsM2 , v072
	.byte		N06   , GsM2 , v100
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        FsM2 , v072
	.byte		N06   , GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        FsM2 , v072
	.byte		N06   , GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte	PEND
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_013
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 025   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 027   ----------------------------------------
mus_molgera_ww_7_027:
	.byte		N01   , FsM2 , v072
	.byte		N06   , GsM2 , v100
	.byte		N01   , Bn4 , v080
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        FsM2 , v072
	.byte		N06   , GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		        GsM2 , v072
	.byte	W06
	.byte		        FsM2 , v072
	.byte		N06   , GsM2 , v084
	.byte	W06
	.byte		        GsM2 , v100
	.byte	W06
	.byte	PEND
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_027
@ 032   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 033   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 034   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 035   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 037   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 041   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 042   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 043   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 044   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 045   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 046   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 047   ----------------------------------------
mus_molgera_ww_7_047:
	.byte		N01   , FsM2 , v072
	.byte		N06   , GsM2 , v080
	.byte		N01   , Bn4 
	.byte	W36
	.byte		        FsM2 , v072
	.byte	W24
	.byte		N01   
	.byte	W03
	.byte		        FsM2 , v064
	.byte	W03
	.byte		        FsM2 , v060
	.byte	W03
	.byte		        FsM2 , v056
	.byte	W03
	.byte		        FsM2 , v072
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte	PEND
@ 048   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 049   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 050   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 051   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 052   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 053   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_013
@ 054   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_013
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 065   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 066   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 067   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_027
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 070   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 071   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_027
@ 072   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 073   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 074   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 075   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 076   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 077   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 078   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 079   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 080   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 081   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 082   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 083   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 084   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 085   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_009
@ 086   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_008
@ 087   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_7_047
@ 088   ----------------------------------------
	.byte	GOTO
	.word	mus_molgera_ww_7_008
	.byte	FINE

@**************** Track 8 (Midi-Chn.12) ****************@

mus_molgera_ww_8:
	.byte	KEYSH , mus_molgera_ww_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 107*mus_molgera_ww_mvl/mxv
	.byte	W96
@ 001   ----------------------------------------
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
	.byte		PAN   , c_v+31
	.byte	W36
	.byte		N04   , En4 , v118
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N18   , Cs5 
	.byte	W24
@ 008   ----------------------------------------
mus_molgera_ww_8_008:
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
	.byte	W96
@ 021   ----------------------------------------
	.byte		PAN   , c_v+20
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
	.byte	W40
	.byte		VOL   , 109*mus_molgera_ww_mvl/mxv
	.byte	W03
	.byte		        107*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        106*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        105*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+14
	.byte		VOL   , 103*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W03
	.byte		        102*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        102*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        100*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        100*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        100*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        99*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        99*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        99*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        99*mus_molgera_ww_mvl/mxv
	.byte	W20
	.byte		N12   , Bn2 , v122
	.byte	W12
@ 028   ----------------------------------------
mus_molgera_ww_8_028:
	.byte		N18   , Cn3 , v122
	.byte	W04
	.byte		VOL   , 99*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        99*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        100*mus_molgera_ww_mvl/mxv
	.byte	W03
	.byte		        100*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        100*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        100*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        102*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W04
	.byte		N06   , Gn3 
	.byte	W02
	.byte		VOL   , 103*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W02
	.byte		N06   , Fs3 
	.byte	W01
	.byte		VOL   , 104*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        105*mus_molgera_ww_mvl/mxv
	.byte	W02
	.byte		        105*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        106*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        106*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        106*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        107*mus_molgera_ww_mvl/mxv
	.byte	W02
	.byte		N06   , En3 
	.byte	W01
	.byte		VOL   , 107*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        107*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        108*mus_molgera_ww_mvl/mxv
	.byte	W04
	.byte		        108*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        108*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        108*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        109*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        109*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        110*mus_molgera_ww_mvl/mxv
	.byte		N48   , Cn4 
	.byte	W01
	.byte		VOL   , 110*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        110*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        111*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        111*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        111*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        112*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        112*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        112*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        113*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        113*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        114*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        114*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        115*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        116*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        116*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        114*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        115*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        115*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        117*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        117*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        118*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        118*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        119*mus_molgera_ww_mvl/mxv
	.byte	W03
	.byte		        119*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        119*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        120*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        120*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        120*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        121*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        121*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        121*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        122*mus_molgera_ww_mvl/mxv
	.byte	W02
	.byte		        122*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        124*mus_molgera_ww_mvl/mxv
	.byte	W11
	.byte	PEND
@ 029   ----------------------------------------
mus_molgera_ww_8_029:
	.byte		N48   , Bn3 , v122
	.byte	W18
	.byte		VOL   , 123*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        122*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        122*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        122*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        122*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        121*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        121*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        121*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        120*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        120*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        119*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        118*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        118*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        117*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        117*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        116*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        116*mus_molgera_ww_mvl/mxv
	.byte	W02
	.byte		        115*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        115*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        114*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        114*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        112*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        112*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        112*mus_molgera_ww_mvl/mxv
	.byte	W04
	.byte		        111*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        111*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        111*mus_molgera_ww_mvl/mxv
	.byte		N48   , Gn3 
	.byte	W02
	.byte		VOL   , 110*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        110*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        110*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        110*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        109*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        109*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        109*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        109*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        109*mus_molgera_ww_mvl/mxv
	.byte	W03
	.byte		        108*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        108*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        108*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        107*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        107*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        107*mus_molgera_ww_mvl/mxv
	.byte	W06
	.byte		        106*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        106*mus_molgera_ww_mvl/mxv
	.byte	W05
	.byte		        105*mus_molgera_ww_mvl/mxv
	.byte	W02
	.byte		        106*mus_molgera_ww_mvl/mxv
	.byte	W03
	.byte		        105*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        105*mus_molgera_ww_mvl/mxv
	.byte	W07
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W03
	.byte	PEND
@ 030   ----------------------------------------
mus_molgera_ww_8_030:
	.byte		N06   , Bn3 , v122
	.byte	W02
	.byte		VOL   , 102*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        102*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        100*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        100*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W11
	.byte		N06   , En3 
	.byte	W06
	.byte		TIE   , Fs3 
	.byte	W02
	.byte		VOL   , 101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        102*mus_molgera_ww_mvl/mxv
	.byte	W07
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W02
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W03
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        105*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        105*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        105*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        105*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        105*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W04
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W04
	.byte		        105*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        106*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        106*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        107*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        107*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        108*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        109*mus_molgera_ww_mvl/mxv
	.byte	W03
	.byte		        109*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        109*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        110*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        110*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        111*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        111*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        111*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        112*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        112*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        113*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        114*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        115*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        116*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        116*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        117*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        118*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        119*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        119*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        120*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        121*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        121*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        123*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        123*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        124*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte	PEND
@ 031   ----------------------------------------
mus_molgera_ww_8_031:
	.byte		VOL   , 123*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        125*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        125*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W09
	.byte		        125*mus_molgera_ww_mvl/mxv
	.byte	W02
	.byte		        125*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        125*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        125*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        125*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        124*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        124*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        124*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        123*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        123*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        123*mus_molgera_ww_mvl/mxv
	.byte	W03
	.byte		        122*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        122*mus_molgera_ww_mvl/mxv
	.byte	W03
	.byte		        121*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        120*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        119*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        119*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        119*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        118*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        117*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        117*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        117*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        116*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        116*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        115*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        114*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        114*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        113*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        111*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        111*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        110*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        109*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        107*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        102*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        99*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        96*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        95*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        93*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        91*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        89*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        86*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        84*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        82*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        67*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        63*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        49*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        41*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        38*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        32*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        30*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        26*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        24*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        20*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        19*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte	PEND
	.byte		EOT   , Fs3 
	.byte		VOL   , 17*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        14*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        10*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        8*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        7*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        3*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        2*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        2*mus_molgera_ww_mvl/mxv
	.byte	W02
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
@ 032   ----------------------------------------
mus_molgera_ww_8_032:
	.byte		VOL   , 127*mus_molgera_ww_mvl/mxv
	.byte		N06   , An2 , v098
	.byte	W12
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N30   , Dn3 
	.byte	W36
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N48   , Cn3 
	.byte	W24
	.byte	PEND
@ 033   ----------------------------------------
mus_molgera_ww_8_033:
	.byte	W36
	.byte		N06   , Bn2 , v098
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PEND
@ 034   ----------------------------------------
mus_molgera_ww_8_034:
	.byte		N06   , En3 , v098
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N36   , An3 
	.byte	W36
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte	PEND
@ 035   ----------------------------------------
mus_molgera_ww_8_035:
	.byte		N06   , Gn3 , v098
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N24   , En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N06   , An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PEND
@ 036   ----------------------------------------
mus_molgera_ww_8_036:
	.byte		N24   , Dn4 , v098
	.byte	W24
	.byte		N06   , An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N18   , En4 
	.byte	W18
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	PEND
@ 037   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_036
@ 038   ----------------------------------------
mus_molgera_ww_8_038:
	.byte		N06   , Dn4 , v098
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N18   , Bn3 
	.byte	W24
	.byte		N18   
	.byte	W24
	.byte	PEND
@ 039   ----------------------------------------
mus_molgera_ww_8_039:
	.byte	W12
	.byte		N06   , Dn4 , v098
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte	PEND
@ 040   ----------------------------------------
	.byte		N06   , En4 
	.byte	W96
@ 041   ----------------------------------------
	.byte	W84
	.byte		N12   , Gs3 , v090
	.byte	W12
@ 042   ----------------------------------------
mus_molgera_ww_8_042:
	.byte		N12   , An3 , v100
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W60
	.byte	PEND
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W96
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
mus_molgera_ww_8_047:
	.byte	W36
	.byte		N04   , En4 , v118
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N18   , Cs5 
	.byte	W24
	.byte	PEND
@ 048   ----------------------------------------
mus_molgera_ww_8_048:
	.byte	W36
	.byte		N06   , Cs3 , v036
	.byte		N06   , En3 , v048
	.byte		N06   , Fs3 , v088
	.byte	W60
	.byte	PEND
@ 049   ----------------------------------------
mus_molgera_ww_8_049:
	.byte	W36
	.byte		N06   , Cs3 , v036
	.byte		N06   , En3 , v048
	.byte		N06   , Fs3 , v088
	.byte	W36
	.byte		        Cs3 , v036
	.byte		N06   , En3 , v048
	.byte		N06   , Fs3 , v088
	.byte	W24
	.byte	PEND
@ 050   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_048
@ 051   ----------------------------------------
mus_molgera_ww_8_051:
	.byte	W36
	.byte		N06   , Cn3 , v036
	.byte		N06   , Fn3 , v048
	.byte		N06   , Gn3 , v088
	.byte	W36
	.byte		        Cn3 , v036
	.byte		N06   , Fn3 , v048
	.byte		N06   , Gn3 , v088
	.byte	W24
	.byte	PEND
@ 052   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_048
@ 053   ----------------------------------------
mus_molgera_ww_8_053:
	.byte	W36
	.byte		N06   , Cs3 , v036
	.byte		N06   , En3 , v048
	.byte		N06   , Fs3 , v088
	.byte	W36
	.byte		        Cn3 , v036
	.byte		N06   , Fn3 , v048
	.byte		N06   , Gn3 , v088
	.byte	W24
	.byte	PEND
@ 054   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_048
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_049
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_048
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_049
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_048
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_051
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_048
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_053
@ 062   ----------------------------------------
	.byte	W36
	.byte		N06   , An2 , v048
	.byte		N06   , Bn2 
	.byte		N06   , En3 , v088
	.byte	W60
@ 063   ----------------------------------------
	.byte	W36
	.byte		        An2 , v048
	.byte		N06   , Bn2 
	.byte		N06   , En3 , v088
	.byte	W36
	.byte	W24
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte		VOL   , 127*mus_molgera_ww_mvl/mxv
	.byte	W40
	.byte		        109*mus_molgera_ww_mvl/mxv
	.byte	W03
	.byte		        107*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        106*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        105*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        104*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        103*mus_molgera_ww_mvl/mxv
	.byte	W03
	.byte		        102*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        102*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        101*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        100*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        100*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        100*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        99*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        99*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        99*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        99*mus_molgera_ww_mvl/mxv
	.byte	W20
	.byte		N12   , Bn2 , v122
	.byte	W12
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_028
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_029
@ 070   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_030
@ 071   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_031
	.byte		EOT   , Fs3 
	.byte		VOL   , 17*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        14*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        10*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        8*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        7*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        3*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        2*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        2*mus_molgera_ww_mvl/mxv
	.byte	W02
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
	.byte		        126*mus_molgera_ww_mvl/mxv
	.byte	W01
@ 072   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_032
@ 073   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_033
@ 074   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_034
@ 075   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_035
@ 076   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_036
@ 077   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_036
@ 078   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_038
@ 079   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_039
@ 080   ----------------------------------------
	.byte		N06   , En4 , v068
	.byte	W96
@ 081   ----------------------------------------
	.byte	W84
	.byte		N12   , Gs3 , v080
	.byte	W12
@ 082   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_042
@ 083   ----------------------------------------
	.byte	W96
@ 084   ----------------------------------------
	.byte	W96
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte	W96
@ 087   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_8_047
@ 088   ----------------------------------------
	.byte	GOTO
	.word	mus_molgera_ww_8_008
	.byte	FINE

@**************** Track 9 (Midi-Chn.15) ****************@

mus_molgera_ww_9:
	.byte		VOL   , 117*mus_molgera_ww_mvl/mxv
	.byte	KEYSH , mus_molgera_ww_key+0
@ 000   ----------------------------------------
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
mus_molgera_ww_9_004:
	.byte		VOICE , 14
	.byte		N24   , Fn2 , v100
	.byte	W60
	.byte		N24   
	.byte	W36
	.byte	PEND
@ 005   ----------------------------------------
mus_molgera_ww_9_005:
	.byte		N24   , Fn2 , v100
	.byte	W72
	.byte		        Cn3 
	.byte	W24
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_004
@ 007   ----------------------------------------
	.byte		N24   , Fn2 , v100
	.byte	W48
	.byte		VOICE , 46
	.byte		N04   , En3 , v127
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W05
	.byte		        Fs4 
	.byte	W23
@ 008   ----------------------------------------
mus_molgera_ww_9_008:
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
mus_molgera_ww_9_016:
	.byte		VOICE , 14
	.byte		N24   , En2 , v100
	.byte	W60
	.byte		N24   
	.byte	W36
	.byte	PEND
@ 017   ----------------------------------------
mus_molgera_ww_9_017:
	.byte		N24   , En2 , v100
	.byte	W72
	.byte		        Bn2 
	.byte	W24
	.byte	PEND
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_016
@ 019   ----------------------------------------
	.byte		N24   , Fn2 , v100
	.byte	W96
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
	.byte	W96
@ 023   ----------------------------------------
mus_molgera_ww_9_023:
	.byte		VOICE , 60
	.byte		N09   , Fs4 , v098
	.byte		N09   , As4 , v104
	.byte	W12
	.byte		        Fs4 , v016
	.byte		N09   , As4 , v032
	.byte	W12
	.byte		        Gn4 , v098
	.byte		N09   , Bn4 , v104
	.byte	W12
	.byte		        Gn4 , v016
	.byte		N09   , Bn4 , v032
	.byte	W12
	.byte		        Ds4 , v098
	.byte		N09   , Gn4 , v104
	.byte	W12
	.byte		        Ds4 , v016
	.byte		N09   , Gn4 , v032
	.byte	W12
	.byte		        En4 , v098
	.byte		N09   , Gs4 , v104
	.byte	W12
	.byte		        En4 , v016
	.byte		N09   , Gs4 , v032
	.byte	W12
	.byte	PEND
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
mus_molgera_ww_9_031:
	.byte	W44
	.byte		VOICE , 46
	.byte	W03
	.byte		N04   , En3 , v127
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W05
	.byte		        Fs4 
	.byte	W24
	.byte	PEND
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
	.byte	PATT
	 .word	mus_molgera_ww_9_031
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_004
@ 045   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_005
@ 046   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_004
@ 047   ----------------------------------------
mus_molgera_ww_9_047:
	.byte		N24   , Fn2 , v100
	.byte	W44
	.byte		VOICE , 46
	.byte	W03
	.byte		N04   , En3 , v127
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W05
	.byte		        Fs4 
	.byte	W24
	.byte	PEND
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_016
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_017
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_016
@ 059   ----------------------------------------
	.byte		N24   , Fn2 , v100
	.byte	W96
@ 060   ----------------------------------------
	.byte	W96
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte		VOICE , 60
	.byte		N09   , Fs4 , v098
	.byte		N09   , As4 , v104
	.byte	W12
	.byte		        Fs4 , v016
	.byte		N09   , As4 , v032
	.byte	W12
	.byte		        Gn4 , v098
	.byte		N09   , Bn4 , v104
	.byte	W12
	.byte		        Gn4 , v016
	.byte		N09   , Bn4 , v032
	.byte	W12
	.byte		        Ds4 , v098
	.byte		N09   , Gn4 , v104
	.byte	W12
	.byte		        Ds4 , v016
	.byte		N09   , Gn4 , v032
	.byte	W12
	.byte		        En4 , v098
	.byte		N09   , Gs4 , v104
	.byte	W12
	.byte		        En4 , v016
	.byte		N09   , Gs4 , v032
	.byte	W12
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W96
@ 069   ----------------------------------------
	.byte	W96
@ 070   ----------------------------------------
	.byte	W96
@ 071   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_031
@ 072   ----------------------------------------
	.byte	W96
@ 073   ----------------------------------------
	.byte	W96
@ 074   ----------------------------------------
	.byte	W96
@ 075   ----------------------------------------
	.byte	W96
@ 076   ----------------------------------------
	.byte	W96
@ 077   ----------------------------------------
	.byte	W96
@ 078   ----------------------------------------
	.byte	W96
@ 079   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_031
@ 080   ----------------------------------------
	.byte	W96
@ 081   ----------------------------------------
	.byte	W96
@ 082   ----------------------------------------
	.byte	W96
@ 083   ----------------------------------------
	.byte	W96
@ 084   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_004
@ 085   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_005
@ 086   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_004
@ 087   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_9_047
@ 088   ----------------------------------------
	.byte	GOTO
	.word	mus_molgera_ww_9_008
	.byte	FINE

@**************** Track 10 (Midi-Chn.16) ****************@

mus_molgera_ww_10:
	.byte	KEYSH , mus_molgera_ww_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 47
	.byte		VOL   , 97*mus_molgera_ww_mvl/mxv
	.byte		N01   , Dn1 , v060
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
@ 001   ----------------------------------------
mus_molgera_ww_10_001:
	.byte		N01   , Dn1 , v060
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
mus_molgera_ww_10_002:
	.byte		N01   , Dn1 , v060
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_001
@ 004   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_002
@ 005   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_001
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_002
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
mus_molgera_ww_10_008:
	.byte		N01   , Dn1 , v060
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte	PEND
@ 009   ----------------------------------------
mus_molgera_ww_10_009:
	.byte		N01   , Dn1 , v060
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte	PEND
@ 010   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 013   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 014   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 015   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 016   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 017   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 018   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 020   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 021   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 024   ----------------------------------------
mus_molgera_ww_10_024:
	.byte		N01   , Dn1 , v060
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte	PEND
@ 025   ----------------------------------------
mus_molgera_ww_10_025:
	.byte		N01   , Dn1 , v060
	.byte		N01   , Ds1 , v076
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte	PEND
@ 026   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_024
@ 027   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_025
@ 028   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_024
@ 029   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_025
@ 030   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_024
@ 031   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_025
@ 032   ----------------------------------------
mus_molgera_ww_10_032:
	.byte		N01   , Dn1 , v060
	.byte		N01   , Ds1 , v076
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte	PEND
@ 033   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_025
@ 034   ----------------------------------------
mus_molgera_ww_10_034:
	.byte		N01   , Dn1 , v060
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte	PEND
@ 035   ----------------------------------------
mus_molgera_ww_10_035:
	.byte		N01   , Dn1 , v060
	.byte		N01   , Ds1 , v076
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte		N01   , Ds1 , v076
	.byte		N01   , Fn1 , v088
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte	PEND
@ 036   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_034
@ 037   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_035
@ 038   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_034
@ 039   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_035
@ 040   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_034
@ 041   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_001
@ 042   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_034
@ 043   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_001
@ 044   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_002
@ 045   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_001
@ 046   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_002
@ 047   ----------------------------------------
mus_molgera_ww_10_047:
	.byte		N01   , Dn1 , v060
	.byte		N01   , Ds1 , v076
	.byte	W96
	.byte	PEND
@ 048   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 049   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 050   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 051   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 052   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 053   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 054   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 055   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 056   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 057   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 058   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 059   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 060   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 061   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 062   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_008
@ 063   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_009
@ 064   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_024
@ 065   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_025
@ 066   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_024
@ 067   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_025
@ 068   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_024
@ 069   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_025
@ 070   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_024
@ 071   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_025
@ 072   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_032
@ 073   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_025
@ 074   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_034
@ 075   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_035
@ 076   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_034
@ 077   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_035
@ 078   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_034
@ 079   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_035
@ 080   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_034
@ 081   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_001
@ 082   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_034
@ 083   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_001
@ 084   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_002
@ 085   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_001
@ 086   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_002
@ 087   ----------------------------------------
	.byte	PATT
	 .word	mus_molgera_ww_10_047
@ 088   ----------------------------------------
	.byte	GOTO
	.word	mus_molgera_ww_10_008
	.byte	FINE

@******************************************************@
	.align	2

mus_molgera_ww:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_molgera_ww_pri	@ Priority
	.byte	mus_molgera_ww_rev	@ Reverb.

	.word	mus_molgera_ww_grp

	.word	mus_molgera_ww_1
	.word	mus_molgera_ww_2
	.word	mus_molgera_ww_3
	.word	mus_molgera_ww_4
	.word	mus_molgera_ww_5
	.word	mus_molgera_ww_6
	.word	mus_molgera_ww_7
	.word	mus_molgera_ww_8
	.word	mus_molgera_ww_9
	.word	mus_molgera_ww_10

	.end

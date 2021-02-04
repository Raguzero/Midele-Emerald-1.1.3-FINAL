	.include "MPlayDef.s"

	.equ	Wild_grp, voicegroup115
	.equ	Wild_pri, 0
	.equ	Wild_rev, 0
	.equ	Wild_mvl, 75
	.equ	Wild_key, 0
	.equ	Wild_tbs, 1
	.equ	Wild_exg, 0
	.equ	Wild_cmp, 1

	.section .rodata
	.global	Wild
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

Wild_1:
	.byte	KEYSH , Wild_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 182*Wild_tbs/2
	.byte		VOICE , 29
	.byte		VOL   , 84*Wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Fn4 , v112
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
@ 001   ----------------------------------------
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
@ 002   ----------------------------------------
	.byte		N24   , Gn4 
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		        Gn3 
	.byte	W24
@ 003   ----------------------------------------
	.byte		        Fn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W48
@ 004   ----------------------------------------
	.byte		        Gs3 
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		        Gs3 
	.byte	W24
@ 005   ----------------------------------------
	.byte		        Fn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N48   , Gs3 
	.byte	W48
@ 006   ----------------------------------------
	.byte		N24   , Gn4 
	.byte	W36
	.byte		        Dn4 
	.byte	W36
	.byte		        Gn4 
	.byte	W24
@ 007   ----------------------------------------
	.byte		        Fn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W48
@ 008   ----------------------------------------
	.byte		        Gs4 
	.byte	W36
	.byte		        Dn4 
	.byte	W36
	.byte		        Gs4 
	.byte	W24
@ 009   ----------------------------------------
	.byte		        Fn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N48   , Gs4 
	.byte	W44
	.byte	W02
Wild_1_B1:
	.byte	W02
@ 010   ----------------------------------------
Wild_1_010:
	.byte		N36   , Gn3 , v112
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
@ 012   ----------------------------------------
	.byte		TIE   , Ds4 
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 014   ----------------------------------------
	.byte	PATT
	 .word	Wild_1_010
@ 015   ----------------------------------------
	.byte		N24   , Cn4 , v112
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
@ 016   ----------------------------------------
	.byte		TIE   , An3 
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 018   ----------------------------------------
Wild_1_018:
	.byte		N36   , Gs3 , v112
	.byte	W36
	.byte		        Ds3 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 020   ----------------------------------------
	.byte		TIE   , En4 
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Wild_1_018
@ 023   ----------------------------------------
	.byte		N24   , Cs4 , v112
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
@ 024   ----------------------------------------
	.byte		TIE   , As3 
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 026   ----------------------------------------
	.byte		N72   , Bn4 
	.byte	W72
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
@ 027   ----------------------------------------
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
@ 028   ----------------------------------------
	.byte		N72   , An4 
	.byte	W72
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
@ 029   ----------------------------------------
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
@ 030   ----------------------------------------
	.byte		N96   , Dn4 
	.byte	W96
@ 031   ----------------------------------------
	.byte		N48   , Gn4 
	.byte	W48
	.byte		        Cn5 
	.byte	W48
@ 032   ----------------------------------------
	.byte		N96   , Bn4 
	.byte	W96
@ 033   ----------------------------------------
	.byte		        Gn4 
	.byte	W96
@ 034   ----------------------------------------
	.byte		N24   , En3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
@ 035   ----------------------------------------
	.byte		N96   , En3 
	.byte	W96
@ 036   ----------------------------------------
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
@ 037   ----------------------------------------
	.byte		N96   , Bn3 
	.byte	W96
	.byte	GOTO
	 .word	Wild_1_B1
Wild_1_B2:
@ 038   ----------------------------------------
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

Wild_2:
	.byte	KEYSH , Wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 81
	.byte		VOL   , 85*Wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Cn4 , v120
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
@ 001   ----------------------------------------
	.byte		        En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
@ 002   ----------------------------------------
	.byte		N24   , Gn3 
	.byte	W36
	.byte		        As2 
	.byte	W36
	.byte		        Dn3 
	.byte	W24
@ 003   ----------------------------------------
	.byte		        Cn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        Dn3 
	.byte	W48
@ 004   ----------------------------------------
	.byte		        Ds3 
	.byte	W36
	.byte		        As2 
	.byte	W36
	.byte		        Ds3 
	.byte	W24
@ 005   ----------------------------------------
	.byte		        Cn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N48   , Ds3 
	.byte	W48
@ 006   ----------------------------------------
	.byte		N24   , Dn4 
	.byte	W36
	.byte		        As3 
	.byte	W36
	.byte		        Dn4 
	.byte	W24
@ 007   ----------------------------------------
	.byte		        Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W48
@ 008   ----------------------------------------
	.byte		        Ds4 
	.byte	W36
	.byte		        As3 
	.byte	W36
	.byte		        Ds4 
	.byte	W24
@ 009   ----------------------------------------
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N48   , Ds4 
	.byte	W44
	.byte	W02
Wild_2_B1:
	.byte	W02
@ 010   ----------------------------------------
Wild_2_010:
	.byte		N36   , Dn3 , v120
	.byte	W36
	.byte		        Bn2 
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte	PEND
@ 011   ----------------------------------------
Wild_2_011:
	.byte		N36   , Fn3 , v120
	.byte	W36
	.byte		        En3 
	.byte	W36
	.byte		N24   , Cn3 
	.byte	W24
	.byte	PEND
@ 012   ----------------------------------------
	.byte		N48   , Gs3 
	.byte	W48
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
@ 013   ----------------------------------------
	.byte		N48   , Cn4 
	.byte	W48
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
@ 014   ----------------------------------------
	.byte	PATT
	 .word	Wild_2_010
@ 015   ----------------------------------------
	.byte		N36   , Fn3 , v120
	.byte	W36
	.byte		        En3 
	.byte	W36
	.byte		N24   , Dn3 
	.byte	W24
@ 016   ----------------------------------------
	.byte		N48   , En3 
	.byte	W48
	.byte		        Dn3 
	.byte	W48
@ 017   ----------------------------------------
	.byte		        Cn3 
	.byte	W48
	.byte		        Fn3 
	.byte	W48
@ 018   ----------------------------------------
Wild_2_018:
	.byte		N36   , Ds3 , v120
	.byte	W36
	.byte		        Cn3 
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte	PEND
@ 019   ----------------------------------------
Wild_2_019:
	.byte		N36   , Fs3 , v120
	.byte	W36
	.byte		        Fn3 
	.byte	W36
	.byte		N24   , Cs3 
	.byte	W24
	.byte	PEND
@ 020   ----------------------------------------
	.byte		N48   , An3 
	.byte	W48
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
@ 021   ----------------------------------------
	.byte		N48   , Cs4 
	.byte	W48
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Wild_2_018
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Wild_2_019
@ 024   ----------------------------------------
	.byte		N48   , Fn3 , v120
	.byte	W48
	.byte		        Ds3 
	.byte	W48
@ 025   ----------------------------------------
	.byte		        Cs3 
	.byte	W48
	.byte		        Fs3 
	.byte	W48
@ 026   ----------------------------------------
	.byte		N36   , En3 
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		N24   , En3 
	.byte	W24
@ 027   ----------------------------------------
	.byte	PATT
	 .word	Wild_2_011
@ 028   ----------------------------------------
	.byte		N48   , Fn3 , v120
	.byte	W48
	.byte		        Cn3 
	.byte	W48
@ 029   ----------------------------------------
	.byte		N36   , En3 
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		N24   , Fn3 
	.byte	W24
@ 030   ----------------------------------------
	.byte		N96   , Gn3 
	.byte	W96
@ 031   ----------------------------------------
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        Gn4 
	.byte	W48
@ 032   ----------------------------------------
	.byte		N96   
	.byte	W96
@ 033   ----------------------------------------
	.byte		        Dn4 
	.byte	W96
@ 034   ----------------------------------------
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
@ 035   ----------------------------------------
	.byte		N96   , Cn3 
	.byte	W96
@ 036   ----------------------------------------
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
@ 037   ----------------------------------------
	.byte		N96   , Gn3 
	.byte	W96
	.byte	GOTO
	 .word	Wild_2_B1
Wild_2_B2:
@ 038   ----------------------------------------
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

Wild_3:
	.byte	KEYSH , Wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 80
	.byte		VOL   , 90*Wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Gn2 , v108
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
@ 001   ----------------------------------------
	.byte		        Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
@ 002   ----------------------------------------
Wild_3_002:
	.byte		N12   , Dn2 , v108
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
Wild_3_003:
	.byte		N12   , Dn2 , v108
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte	PEND
@ 004   ----------------------------------------
Wild_3_004:
	.byte		N12   , Ds2 , v108
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
	.byte		        Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
@ 006   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_003
@ 008   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_004
@ 009   ----------------------------------------
	.byte		N24   , Fn2 , v108
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W10
Wild_3_B1:
	.byte	W02
@ 010   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_002
@ 011   ----------------------------------------
	.byte		N12   , Dn2 , v108
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N24   , Fs2 
	.byte	W24
@ 012   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_004
@ 013   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_004
@ 014   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_002
@ 015   ----------------------------------------
	.byte		N12   , Dn2 , v108
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
@ 016   ----------------------------------------
Wild_3_016:
	.byte		N12   , Cn2 , v108
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte	PEND
@ 017   ----------------------------------------
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
@ 018   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_004
@ 019   ----------------------------------------
	.byte		N12   , Ds2 , v108
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W24
@ 020   ----------------------------------------
Wild_3_020:
	.byte		N12   , En2 , v108
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	PEND
@ 021   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_020
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_004
@ 023   ----------------------------------------
	.byte		N12   , Ds2 , v108
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
@ 024   ----------------------------------------
	.byte		        Cs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
@ 025   ----------------------------------------
	.byte		        Cs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
@ 026   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_002
@ 027   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_002
@ 028   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_016
@ 029   ----------------------------------------
	.byte		N12   , Cn2 , v108
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
@ 030   ----------------------------------------
	.byte		N24   , Dn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
@ 031   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_002
@ 032   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_002
@ 033   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_002
@ 034   ----------------------------------------
	.byte		N12   , Cn2 , v108
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
@ 035   ----------------------------------------
	.byte		        Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
@ 036   ----------------------------------------
	.byte	PATT
	 .word	Wild_3_002
@ 037   ----------------------------------------
	.byte		N12   , Dn2 , v108
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	GOTO
	 .word	Wild_3_B1
Wild_3_B2:
@ 038   ----------------------------------------
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

Wild_4:
	.byte	KEYSH , Wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 17
	.byte		VOL   , 85*Wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Fn5 , v112
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Gn6 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Gn6 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Gn6 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Gn6 
	.byte	W06
@ 001   ----------------------------------------
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Gn6 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Gn6 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Gn6 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Gn6 
	.byte	W06
@ 002   ----------------------------------------
	.byte		N24   , Gn4 
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		        Gn3 
	.byte	W24
@ 003   ----------------------------------------
	.byte		        Fn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W48
@ 004   ----------------------------------------
	.byte		        Gs3 
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		        Gs3 
	.byte	W24
@ 005   ----------------------------------------
	.byte		        Fn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N48   , Gs3 
	.byte	W48
@ 006   ----------------------------------------
	.byte		N24   , Gn4 
	.byte	W36
	.byte		        Dn4 
	.byte	W36
	.byte		        Gn4 
	.byte	W24
@ 007   ----------------------------------------
	.byte		        Fn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W48
@ 008   ----------------------------------------
	.byte		        Gs4 
	.byte	W36
	.byte		        Dn4 
	.byte	W36
	.byte		        Gs4 
	.byte	W24
@ 009   ----------------------------------------
	.byte		        Fn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N48   , Gs4 
	.byte	W44
	.byte	W02
Wild_4_B1:
	.byte	W02
@ 010   ----------------------------------------
Wild_4_010:
	.byte		N36   , Gn3 , v112
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
@ 012   ----------------------------------------
	.byte		TIE   , Ds4 
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 014   ----------------------------------------
	.byte	PATT
	 .word	Wild_4_010
@ 015   ----------------------------------------
	.byte		N24   , Cn4 , v112
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
@ 016   ----------------------------------------
	.byte		TIE   , An3 
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 018   ----------------------------------------
Wild_4_018:
	.byte		N36   , Gs3 , v112
	.byte	W36
	.byte		        Ds3 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
@ 020   ----------------------------------------
	.byte		TIE   , En4 
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Wild_4_018
@ 023   ----------------------------------------
	.byte		N24   , Cs4 , v112
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
@ 024   ----------------------------------------
	.byte		TIE   , As3 
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 026   ----------------------------------------
	.byte		N72   , Bn5 
	.byte	W72
	.byte		N12   , Gn5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
@ 027   ----------------------------------------
	.byte		        Dn6 
	.byte	W12
	.byte		        Cn6 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
@ 028   ----------------------------------------
	.byte		N72   , An5 
	.byte	W72
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
@ 029   ----------------------------------------
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
@ 030   ----------------------------------------
	.byte		N96   , Dn5 
	.byte	W96
@ 031   ----------------------------------------
	.byte		N48   , Gn5 
	.byte	W48
	.byte		        Cn6 
	.byte	W48
@ 032   ----------------------------------------
	.byte		N96   , Bn5 
	.byte	W96
@ 033   ----------------------------------------
	.byte		        Gn5 
	.byte	W96
@ 034   ----------------------------------------
	.byte		N24   , En4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
@ 035   ----------------------------------------
	.byte		N96   , En4 
	.byte	W96
@ 036   ----------------------------------------
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        As4 
	.byte	W24
@ 037   ----------------------------------------
	.byte		N96   , Bn4 
	.byte	W96
	.byte	GOTO
	 .word	Wild_4_B1
Wild_4_B2:
@ 038   ----------------------------------------
	.byte	FINE

@**************** Track 5 (Midi-Chn.5) ****************@

Wild_5:
	.byte	KEYSH , Wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 29
	.byte		VOL   , 82*Wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Gn1 , v127
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
@ 001   ----------------------------------------
	.byte		        Fn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
@ 002   ----------------------------------------
Wild_5_002:
	.byte		N12   , Dn1 , v127
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
@ 004   ----------------------------------------
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N36   , Cs2 
	.byte	W36
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
@ 005   ----------------------------------------
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
@ 006   ----------------------------------------
	.byte	PATT
	 .word	Wild_5_002
@ 007   ----------------------------------------
	.byte		N12   , Dn1 , v127
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
@ 008   ----------------------------------------
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
@ 009   ----------------------------------------
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        As1 
	.byte	W10
Wild_5_B1:
	.byte	W02
@ 010   ----------------------------------------
	.byte		N12   , Dn1 , v127
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
@ 011   ----------------------------------------
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
@ 012   ----------------------------------------
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
@ 013   ----------------------------------------
	.byte		        Ds1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn0 
	.byte		N12   , As1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
@ 014   ----------------------------------------
	.byte		N24   , Dn1 
	.byte	W24
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N18   , Dn1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
@ 015   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		        Gn1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
@ 016   ----------------------------------------
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
@ 017   ----------------------------------------
	.byte		N24   , Cn1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        Gs0 
	.byte	W24
	.byte		N18   , Ds1 
	.byte	W18
	.byte		N03   , Cs1 
	.byte	W03
	.byte		        Cn1 
	.byte	W03
@ 018   ----------------------------------------
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
@ 019   ----------------------------------------
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
@ 020   ----------------------------------------
	.byte		        En1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
@ 021   ----------------------------------------
	.byte		        En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cn1 
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
@ 022   ----------------------------------------
	.byte		N24   , Ds1 
	.byte	W24
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N18   , Ds1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
@ 023   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		        Gs1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W12
@ 024   ----------------------------------------
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Fs1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
@ 025   ----------------------------------------
	.byte		N24   , Cs1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		        An0 
	.byte	W24
	.byte		N18   , En1 
	.byte	W18
	.byte		N03   , Dn1 
	.byte	W03
	.byte		        Cs1 
	.byte	W03
@ 026   ----------------------------------------
	.byte		N11   , Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
@ 027   ----------------------------------------
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
@ 028   ----------------------------------------
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
@ 029   ----------------------------------------
	.byte		N11   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
@ 030   ----------------------------------------
	.byte		N23   , Dn1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
@ 031   ----------------------------------------
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
@ 032   ----------------------------------------
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
@ 033   ----------------------------------------
	.byte		        Cn2 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N12   , En1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
@ 034   ----------------------------------------
	.byte		N05   , Cn1 
	.byte	W06
	.byte		N11   
	.byte	W36
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N05   
	.byte	W06
@ 035   ----------------------------------------
	.byte		        En1 
	.byte	W06
	.byte		N11   , Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N05   , Cn1 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
@ 036   ----------------------------------------
	.byte		        Cn2 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N11   , Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W06
@ 037   ----------------------------------------
	.byte	W06
	.byte		N05   , Dn1 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Bn0 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte	GOTO
	 .word	Wild_5_B1
Wild_5_B2:
@ 038   ----------------------------------------
	.byte	FINE

@**************** Track 6 (Midi-Chn.6) ****************@

Wild_6:
	.byte	KEYSH , Wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 17
	.byte		VOL   , 87*Wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W84
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
@ 001   ----------------------------------------
	.byte		        Cn1 , v124
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte		N48   , Cn3 
	.byte	W24
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        Cn1 , v100
	.byte	W12
@ 002   ----------------------------------------
	.byte		        Cn1 , v127
	.byte		N48   , Gn2 , v108
	.byte	W12
	.byte		N06   , Cn1 , v092
	.byte	W24
	.byte		        Cn1 , v124
	.byte	W24
	.byte		        Cn1 , v092
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
@ 003   ----------------------------------------
Wild_6_003:
	.byte		N06   , Cn1 , v124
	.byte	W12
	.byte		        Cn1 , v092
	.byte	W24
	.byte		        Cn1 , v124
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W24
	.byte		        Fn1 , v124
	.byte	W12
	.byte	PEND
@ 004   ----------------------------------------
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W36
	.byte		        Cn1 , v092
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
@ 005   ----------------------------------------
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        En1 , v124
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Cn2 , v124
	.byte		N24   , Bn2 , v112
	.byte	W06
	.byte		N06   , An1 , v124
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N06   
	.byte	W06
@ 006   ----------------------------------------
	.byte		        Cn1 
	.byte		N48   , Cs2 , v108
	.byte	W12
	.byte		N06   , Cn1 , v092
	.byte	W24
	.byte		        Cn1 , v124
	.byte	W24
	.byte		        Cn1 , v092
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
@ 007   ----------------------------------------
	.byte	PATT
	 .word	Wild_6_003
@ 008   ----------------------------------------
	.byte		N06   , Cn1 , v124
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W24
	.byte		        Cn1 , v124
	.byte	W24
	.byte		        Cn1 , v092
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
@ 009   ----------------------------------------
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Bn0 , v124
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Cs1 , v112
	.byte		N24   , Cs2 , v124
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        Fn1 
	.byte	W04
Wild_6_B1:
	.byte	W02
@ 010   ----------------------------------------
	.byte		N06   , Cn1 , v124
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N06   , Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
@ 011   ----------------------------------------
Wild_6_011:
	.byte		N06   , Cn1 , v124
	.byte	W24
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte	PEND
@ 012   ----------------------------------------
Wild_6_012:
	.byte		N06   , Cn1 , v124
	.byte	W24
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
	.byte	PEND
@ 013   ----------------------------------------
	.byte	PATT
	 .word	Wild_6_011
@ 014   ----------------------------------------
	.byte	PATT
	 .word	Wild_6_012
@ 015   ----------------------------------------
	.byte	PATT
	 .word	Wild_6_011
@ 016   ----------------------------------------
Wild_6_016:
	.byte		N06   , Cn1 , v124
	.byte	W24
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W24
	.byte	PEND
@ 017   ----------------------------------------
	.byte		        Cn1 , v124
	.byte	W24
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Dn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
@ 018   ----------------------------------------
	.byte		        Cn1 
	.byte		N48   , An2 , v112
	.byte	W24
	.byte		N06   , Cs1 
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
@ 019   ----------------------------------------
	.byte	PATT
	 .word	Wild_6_011
@ 020   ----------------------------------------
	.byte	PATT
	 .word	Wild_6_012
@ 021   ----------------------------------------
	.byte	PATT
	 .word	Wild_6_011
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Wild_6_016
@ 023   ----------------------------------------
	.byte		N06   , Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W24
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W24
@ 024   ----------------------------------------
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
	.byte		        Cs1 , v112
	.byte	W12
@ 025   ----------------------------------------
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W24
	.byte		        An1 , v124
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cs1 , v112
	.byte	W06
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W12
@ 026   ----------------------------------------
	.byte		N06   
	.byte		N24   , Bn2 , v124
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        Fn2 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Fn2 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
@ 027   ----------------------------------------
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte		N06   , Fn2 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W24
	.byte		        Cn1 
	.byte		N06   , Fn2 , v112
	.byte	W24
@ 028   ----------------------------------------
Wild_6_028:
	.byte		N06   , Cn1 , v124
	.byte	W24
	.byte		        Fn2 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Fn2 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
	.byte	PEND
@ 029   ----------------------------------------
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 , v112
	.byte		N06   , Fn2 
	.byte	W24
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Fn2 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
@ 030   ----------------------------------------
	.byte		        Cs1 , v112
	.byte		N24   , Gn2 , v124
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        Fn2 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cs1 , v124
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn2 , v100
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
@ 031   ----------------------------------------
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte		N06   , Fn2 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 , v112
	.byte	W24
	.byte		        Cn1 , v124
	.byte		N06   , Fn2 , v112
	.byte	W24
@ 032   ----------------------------------------
	.byte	PATT
	 .word	Wild_6_028
@ 033   ----------------------------------------
	.byte		N06   , Cn1 , v124
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 , v112
	.byte		N06   , Fn2 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 , v124
	.byte		N48   , Cn3 , v112
	.byte	W06
	.byte		N06   , Cn1 , v124
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
@ 034   ----------------------------------------
	.byte		        Cn1 
	.byte		N48   , Cs2 
	.byte	W24
	.byte		N06   , Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
@ 035   ----------------------------------------
	.byte	PATT
	 .word	Wild_6_012
@ 036   ----------------------------------------
	.byte	PATT
	 .word	Wild_6_016
@ 037   ----------------------------------------
	.byte		N06   , Cn1 , v124
	.byte	W24
	.byte		        Cs1 , v112
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte	GOTO
	 .word	Wild_6_B1
Wild_6_B2:
@ 038   ----------------------------------------
	.byte	FINE

@**************** Track 7 (Midi-Chn.7) ****************@

Wild_7:
	.byte	KEYSH , Wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 127
	.byte		VOL   , 78*Wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W12
	.byte		N03   , Cn5 , v060
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Cn5 , v076
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Cn5 , v084
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        Cn5 , v104
	.byte	W06
	.byte		N03   
	.byte	W06
@ 002   ----------------------------------------
Wild_7_002:
	.byte		N03   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
Wild_7_003:
	.byte		N03   , Cn5 , v100
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W24
	.byte		        Cn5 , v092
	.byte	W12
	.byte	PEND
@ 004   ----------------------------------------
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W24
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
@ 005   ----------------------------------------
	.byte		        Cn5 , v100
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v124
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W18
@ 006   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_003
@ 008   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_002
@ 009   ----------------------------------------
	.byte		N03   , Cn5 , v100
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v124
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W16
Wild_7_B1:
	.byte	W02
@ 010   ----------------------------------------
Wild_7_010:
	.byte	W12
	.byte		N03   , Cn5 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v100
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v104
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
@ 011   ----------------------------------------
Wild_7_011:
	.byte		N03   , Cn5 , v108
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v100
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v104
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_011
@ 013   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_011
@ 014   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_011
@ 015   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_011
@ 016   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_011
@ 017   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_011
@ 018   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_010
@ 019   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_011
@ 020   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_011
@ 021   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_011
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_011
@ 023   ----------------------------------------
Wild_7_023:
	.byte		N03   , Cn5 , v108
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v100
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v104
	.byte	W24
	.byte	PEND
@ 024   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_010
@ 025   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_023
@ 026   ----------------------------------------
Wild_7_026:
	.byte		N03   , Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v108
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v108
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v108
	.byte	W12
	.byte	PEND
@ 027   ----------------------------------------
Wild_7_027:
	.byte	W12
	.byte		N03   , Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W24
	.byte		        Cn5 , v096
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte	PEND
@ 028   ----------------------------------------
Wild_7_028:
	.byte		N03   , Cn5 , v124
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W24
	.byte	PEND
@ 029   ----------------------------------------
Wild_7_029:
	.byte		N03   , Cn5 , v124
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	PEND
@ 030   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_026
@ 031   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_027
@ 032   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_028
@ 033   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_029
@ 034   ----------------------------------------
	.byte	PATT
	 .word	Wild_7_010
@ 035   ----------------------------------------
	.byte		N03   , Cn5 , v108
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v100
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v104
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
@ 036   ----------------------------------------
	.byte		        Cn5 , v076
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v100
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v104
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
@ 037   ----------------------------------------
	.byte		        Cn5 , v076
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 , v100
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v104
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	GOTO
	 .word	Wild_7_B1
Wild_7_B2:
@ 038   ----------------------------------------
	.byte	FINE

@**************** Track 8 (Midi-Chn.8) ****************@

Wild_8:
	.byte	KEYSH , Wild_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 126
	.byte		VOL   , 73*Wild_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte		N12   , Gn5 , v076
	.byte	W24
	.byte		        Gn5 , v092
	.byte	W24
	.byte		        Gn5 , v108
	.byte	W24
	.byte		        Gn5 , v124
	.byte	W24
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W72
	.byte		        Gn5 , v108
	.byte	W24
@ 004   ----------------------------------------
	.byte	W24
	.byte		N12   
	.byte	W72
@ 005   ----------------------------------------
	.byte	W84
	.byte		N12   
	.byte	W12
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W72
	.byte		N12   
	.byte	W24
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W92
	.byte	W02
Wild_8_B1:
	.byte	W02
@ 010   ----------------------------------------
	.byte		N12   , Gn5 , v108
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
	.byte		N12   
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
	.byte	W84
	.byte		        Gn5 , v112
	.byte	W12
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W84
	.byte		        Gn5 , v124
	.byte	W12
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
Wild_8_027:
	.byte		N12   , Gn5 , v108
	.byte	W60
	.byte		N12   
	.byte	W36
	.byte	PEND
@ 028   ----------------------------------------
	.byte	W84
	.byte		        Gn5 , v112
	.byte	W12
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	PATT
	 .word	Wild_8_027
@ 032   ----------------------------------------
	.byte	W84
	.byte		N12   , Gn5 , v112
	.byte	W12
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte		        Gn5 , v108
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	W96
	.byte	GOTO
	 .word	Wild_8_B1
Wild_8_B2:
@ 038   ----------------------------------------
	.byte	FINE

@******************************************************@
	.align	2

Wild:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	Wild_pri	@ Priority
	.byte	Wild_rev	@ Reverb.

	.word	Wild_grp

	.word	Wild_1
	.word	Wild_2
	.word	Wild_3
	.word	Wild_4
	.word	Wild_5
	.word	Wild_6
	.word	Wild_7
	.word	Wild_8

	.end

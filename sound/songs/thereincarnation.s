	.include "MPlayDef.s"

	.equ	thereincarnation_grp, voicegroup185
	.equ	thereincarnation_pri, 0
	.equ	thereincarnation_rev, 0
	.equ	thereincarnation_mvl, 103
	.equ	thereincarnation_key, 0
	.equ	thereincarnation_tbs, 1
	.equ	thereincarnation_exg, 0
	.equ	thereincarnation_cmp, 1

	.section .rodata
	.global	thereincarnation
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

thereincarnation_1:
	.byte	KEYSH , thereincarnation_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 154*thereincarnation_tbs/2
	.byte		VOICE , 62
	.byte		VOL   , 109*thereincarnation_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
thereincarnation_1_B1:
@ 003   ----------------------------------------
	.byte		N09   , Bn3 , v127
	.byte	W96
@ 004   ----------------------------------------
	.byte		        Fs3 , v112
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
@ 005   ----------------------------------------
	.byte		N09   , Gs3 , v124
	.byte	W96
@ 006   ----------------------------------------
	.byte		        Ds3 , v112
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
@ 007   ----------------------------------------
	.byte		N09   , En3 , v127
	.byte	W48
	.byte		        En3 , v112
	.byte	W48
@ 008   ----------------------------------------
	.byte		        Ds3 
	.byte	W48
	.byte		N09   
	.byte	W48
@ 009   ----------------------------------------
	.byte		        Gn3 
	.byte	W48
	.byte		N09   
	.byte	W48
@ 010   ----------------------------------------
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N24   
	.byte	W24
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
	.byte		N12   , Gn3 , v124
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		        Ds4 
	.byte	W12
	.byte		        Gn3 
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		        Ds4 
	.byte	W12
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
thereincarnation_1_036:
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W30
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W30
	.byte	PEND
@ 037   ----------------------------------------
thereincarnation_1_037:
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N48   , Bn3 
	.byte	W54
	.byte		N24   , Cs4 
	.byte	W24
	.byte	PEND
@ 038   ----------------------------------------
thereincarnation_1_038:
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N18   , Bn3 
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N18   , Bn3 
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W12
	.byte	PEND
@ 039   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_1_037
@ 040   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_1_036
@ 041   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_1_037
@ 042   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_1_038
@ 043   ----------------------------------------
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N48   , Bn3 
	.byte	W54
	.byte		N24   , An4 , v124
	.byte	W24
@ 044   ----------------------------------------
thereincarnation_1_044:
	.byte		N06   , Bn4 , v124
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , Fs4 
	.byte	W30
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , Fs4 
	.byte	W30
	.byte	PEND
@ 045   ----------------------------------------
thereincarnation_1_045:
	.byte		N06   , Bn4 , v124
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N48   , Fs4 
	.byte	W54
	.byte		N24   , An4 
	.byte	W24
	.byte	PEND
@ 046   ----------------------------------------
thereincarnation_1_046:
	.byte		N06   , Bn4 , v124
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , En5 
	.byte	W12
	.byte	PEND
@ 047   ----------------------------------------
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		N48   , Bn4 
	.byte	W54
	.byte		N24   , Cs5 
	.byte	W24
@ 048   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_1_044
@ 049   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_1_045
@ 050   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_1_046
@ 051   ----------------------------------------
	.byte		N06   , Dn5 , v124
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		N72   , Bn4 
	.byte	W78
	.byte	GOTO
	 .word	thereincarnation_1_B1
thereincarnation_1_B2:
@ 052   ----------------------------------------
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

thereincarnation_2:
	.byte	KEYSH , thereincarnation_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 48
	.byte		VOL   , 103*thereincarnation_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
thereincarnation_2_B1:
@ 003   ----------------------------------------
	.byte		N09   , Bn4 , v127
	.byte	W12
	.byte		N06   , Gs4 , v112
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
@ 004   ----------------------------------------
	.byte		N09   , Fs4 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W24
@ 005   ----------------------------------------
	.byte		N09   , Gs4 , v127
	.byte	W12
	.byte		N06   , En4 , v112
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
@ 006   ----------------------------------------
	.byte		N09   , Ds4 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W24
@ 007   ----------------------------------------
	.byte		N09   , En4 , v127
	.byte	W12
	.byte		N06   , Cs4 , v112
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N09   , En4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
@ 008   ----------------------------------------
	.byte		N09   , Ds4 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N09   , Ds4 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
@ 009   ----------------------------------------
	.byte		N09   , Gn4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N09   , Gn4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
@ 010   ----------------------------------------
	.byte		N09   , As4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W12
	.byte		N24   
	.byte	W24
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
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
@ 027   ----------------------------------------
thereincarnation_2_027:
	.byte		N36   , Ds4 , v112
	.byte	W36
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N18   , Ds4 
	.byte	W18
	.byte		        Cs4 
	.byte	W18
	.byte		N12   , Bn3 
	.byte	W12
	.byte	PEND
@ 028   ----------------------------------------
	.byte		N36   , Cs4 
	.byte	W36
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        As3 
	.byte	W24
@ 029   ----------------------------------------
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N18   , Bn3 
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		N12   , Gs3 
	.byte	W12
@ 030   ----------------------------------------
	.byte		N36   , As3 
	.byte	W36
	.byte		N06   , Ds4 
	.byte	W12
	.byte		N42   
	.byte	W48
@ 031   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_2_027
@ 032   ----------------------------------------
	.byte		N36   , Cs4 , v112
	.byte	W36
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N48   , As4 
	.byte	W48
@ 033   ----------------------------------------
	.byte		N36   , Bn4 
	.byte	W36
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N18   , Bn4 
	.byte	W18
	.byte		        As4 
	.byte	W18
	.byte		N12   , Gs4 
	.byte	W12
@ 034   ----------------------------------------
	.byte		        Gn4 , v124
	.byte	W18
	.byte		        As4 
	.byte	W18
	.byte		        Ds5 
	.byte	W12
	.byte		        Gn4 
	.byte	W18
	.byte		        As4 
	.byte	W18
	.byte		        Ds5 
	.byte	W12
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
thereincarnation_2_044:
	.byte		N06   , Dn5 , v112
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte	PEND
@ 045   ----------------------------------------
thereincarnation_2_045:
	.byte		N06   , Dn5 , v112
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte	PEND
@ 046   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_2_044
@ 047   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_2_045
@ 048   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_2_044
@ 049   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_2_045
@ 050   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_2_044
@ 051   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_2_045
	.byte	GOTO
	 .word	thereincarnation_2_B1
thereincarnation_2_B2:
@ 052   ----------------------------------------
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

thereincarnation_3:
	.byte	KEYSH , thereincarnation_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 80
	.byte		VOL   , 100*thereincarnation_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
thereincarnation_3_B1:
@ 003   ----------------------------------------
	.byte		N09   , Bn3 , v127
	.byte	W96
@ 004   ----------------------------------------
	.byte		        Fs3 , v112
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte		N09   , Ds3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
@ 007   ----------------------------------------
	.byte		N09   , En3 , v127
	.byte	W48
	.byte		        En3 , v112
	.byte	W48
@ 008   ----------------------------------------
	.byte		        Ds3 
	.byte	W48
	.byte		N09   
	.byte	W48
@ 009   ----------------------------------------
	.byte		        Gn3 
	.byte	W48
	.byte		N09   
	.byte	W48
@ 010   ----------------------------------------
	.byte		        Gn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W12
	.byte		N24   
	.byte	W24
@ 011   ----------------------------------------
thereincarnation_3_011:
	.byte		N04   , Bn4 , v088
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_011
@ 013   ----------------------------------------
thereincarnation_3_013:
	.byte		N04   , As4 , v088
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte	PEND
@ 014   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_013
@ 015   ----------------------------------------
thereincarnation_3_015:
	.byte		N04   , Gs4 , v088
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte	PEND
@ 016   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_015
@ 017   ----------------------------------------
thereincarnation_3_017:
	.byte		N04   , Fs4 , v088
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte	PEND
@ 018   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_017
@ 019   ----------------------------------------
thereincarnation_3_019:
	.byte		N04   , Ds4 , v088
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_019
@ 021   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_017
@ 022   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_017
@ 023   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_015
@ 024   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_015
@ 025   ----------------------------------------
	.byte		N04   , As4 , v088
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
@ 026   ----------------------------------------
	.byte		        As4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N04   
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N04   
	.byte	W12
@ 027   ----------------------------------------
thereincarnation_3_027:
	.byte		N04   , Bn4 , v088
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte	PEND
@ 028   ----------------------------------------
thereincarnation_3_028:
	.byte		N04   , As4 , v088
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte	PEND
@ 029   ----------------------------------------
thereincarnation_3_029:
	.byte		N04   , Gs4 , v088
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte	PEND
@ 030   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_028
@ 031   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_027
@ 032   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_028
@ 033   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_029
@ 034   ----------------------------------------
	.byte	W36
	.byte		N12   , Ds4 , v127
	.byte	W12
	.byte		        Gn3 
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		        Ds4 
	.byte	W12
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
thereincarnation_3_044:
	.byte		N06   , Bn4 , v124
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , Fs4 
	.byte	W30
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , Fs4 
	.byte	W30
	.byte	PEND
@ 045   ----------------------------------------
thereincarnation_3_045:
	.byte		N06   , Bn4 , v124
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N48   , Fs4 
	.byte	W54
	.byte		N24   , An4 
	.byte	W24
	.byte	PEND
@ 046   ----------------------------------------
thereincarnation_3_046:
	.byte		N06   , Bn4 , v124
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , En5 
	.byte	W12
	.byte	PEND
@ 047   ----------------------------------------
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		N48   , Bn4 
	.byte	W54
	.byte		N24   , Cs5 
	.byte	W24
@ 048   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_044
@ 049   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_045
@ 050   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_3_046
@ 051   ----------------------------------------
	.byte		N06   , Dn5 , v124
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		N72   , Bn4 
	.byte	W78
	.byte	GOTO
	 .word	thereincarnation_3_B1
thereincarnation_3_B2:
@ 052   ----------------------------------------
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

thereincarnation_4:
	.byte	KEYSH , thereincarnation_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 60
	.byte		VOL   , 97*thereincarnation_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
thereincarnation_4_B1:
@ 003   ----------------------------------------
	.byte		N09   , Bn3 , v127
	.byte	W96
@ 004   ----------------------------------------
	.byte		        Fs3 , v112
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
@ 005   ----------------------------------------
	.byte		N09   , Gs3 , v127
	.byte	W96
@ 006   ----------------------------------------
	.byte		        Ds3 , v112
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
@ 007   ----------------------------------------
	.byte		N09   , En3 , v127
	.byte	W48
	.byte		        En3 , v112
	.byte	W48
@ 008   ----------------------------------------
	.byte		        Ds3 
	.byte	W48
	.byte		N09   
	.byte	W48
@ 009   ----------------------------------------
	.byte		        Gn3 
	.byte	W48
	.byte		N09   
	.byte	W48
@ 010   ----------------------------------------
	.byte		        As3 
	.byte	W12
	.byte		        Ds3 
	.byte		N09   , Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N24   
	.byte	W24
@ 011   ----------------------------------------
	.byte		N48   , Bn3 
	.byte	W48
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
@ 012   ----------------------------------------
	.byte		N48   , Bn3 
	.byte	W48
	.byte		        Ds4 
	.byte	W48
@ 013   ----------------------------------------
	.byte		TIE   , As3 
	.byte	W96
@ 014   ----------------------------------------
	.byte	W84
	.byte		EOT   
	.byte	W12
@ 015   ----------------------------------------
	.byte		N72   , Bn3 
	.byte	W72
	.byte		N24   , Ds4 
	.byte	W24
@ 016   ----------------------------------------
	.byte		N48   , Cs4 
	.byte	W48
	.byte		        Fs4 
	.byte	W48
@ 017   ----------------------------------------
	.byte		TIE   , Cs4 
	.byte	W96
@ 018   ----------------------------------------
	.byte	W12
	.byte		EOT   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
@ 019   ----------------------------------------
	.byte		TIE   , Gs3 
	.byte	W96
@ 020   ----------------------------------------
	.byte	W12
	.byte		EOT   
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
@ 021   ----------------------------------------
	.byte		TIE   , Fs3 
	.byte	W96
@ 022   ----------------------------------------
	.byte	W12
	.byte		EOT   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
@ 023   ----------------------------------------
	.byte		TIE   , Gs3 
	.byte	W96
@ 024   ----------------------------------------
	.byte	W12
	.byte		EOT   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
@ 025   ----------------------------------------
	.byte		TIE   , As3 
	.byte	W96
@ 026   ----------------------------------------
	.byte	W12
	.byte		EOT   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
@ 027   ----------------------------------------
	.byte		N36   , Ds4 
	.byte	W36
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N18   , Ds4 
	.byte	W18
	.byte		        Cs4 
	.byte	W18
	.byte		N12   , Bn3 
	.byte	W12
@ 028   ----------------------------------------
	.byte		N36   , Cs4 
	.byte	W36
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        As3 
	.byte	W24
@ 029   ----------------------------------------
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N18   , Bn3 
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		N12   , Gs3 
	.byte	W12
@ 030   ----------------------------------------
	.byte		N36   , As3 
	.byte	W36
	.byte		N06   , Ds4 
	.byte	W12
	.byte		N42   
	.byte	W48
@ 031   ----------------------------------------
	.byte		N36   
	.byte	W36
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N18   , Ds4 
	.byte	W12
	.byte		N06   , Bn3 , v088
	.byte	W06
	.byte		N18   , Cs4 , v112
	.byte	W18
	.byte		N12   , Bn3 
	.byte	W12
@ 032   ----------------------------------------
	.byte		N36   , Cs4 
	.byte	W36
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N48   , As4 
	.byte	W48
@ 033   ----------------------------------------
	.byte		N36   , Bn4 
	.byte	W36
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N18   , Bn4 
	.byte	W18
	.byte		        As4 
	.byte	W18
	.byte		N12   , Gs4 
	.byte	W12
@ 034   ----------------------------------------
	.byte		        Gn3 , v124
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		        Ds4 
	.byte	W12
	.byte		        Gn3 
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		        Ds4 
	.byte	W12
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
thereincarnation_4_044:
	.byte		N06   , Bn3 , v112
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N24   , Fs3 
	.byte	W30
	.byte		N06   , Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N24   , Fs3 
	.byte	W30
	.byte	PEND
@ 045   ----------------------------------------
thereincarnation_4_045:
	.byte		N06   , Bn3 , v112
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N48   , Fs3 
	.byte	W54
	.byte		N24   , An3 
	.byte	W24
	.byte	PEND
@ 046   ----------------------------------------
thereincarnation_4_046:
	.byte		N06   , Bn3 , v112
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N06   , En4 
	.byte	W12
	.byte	PEND
@ 047   ----------------------------------------
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N48   , Bn3 
	.byte	W54
	.byte		N24   , Cs4 
	.byte	W24
@ 048   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_4_044
@ 049   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_4_045
@ 050   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_4_046
@ 051   ----------------------------------------
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N72   , Bn3 
	.byte	W78
	.byte	GOTO
	 .word	thereincarnation_4_B1
thereincarnation_4_B2:
@ 052   ----------------------------------------
	.byte	FINE

@**************** Track 5 (Midi-Chn.5) ****************@

thereincarnation_5:
	.byte	KEYSH , thereincarnation_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 81
	.byte		VOL   , 123*thereincarnation_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
thereincarnation_5_B1:
@ 003   ----------------------------------------
	.byte		N09   , Bn1 , v127
	.byte	W96
@ 004   ----------------------------------------
	.byte		        Fs1 , v112
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
@ 005   ----------------------------------------
	.byte		N09   , Gs1 
	.byte	W96
@ 006   ----------------------------------------
	.byte		        Ds1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
@ 007   ----------------------------------------
	.byte		N09   , En1 , v127
	.byte	W48
	.byte		        En1 , v112
	.byte	W48
@ 008   ----------------------------------------
	.byte		        Ds1 
	.byte	W48
	.byte		N09   
	.byte	W48
@ 009   ----------------------------------------
	.byte		        Gn1 
	.byte	W48
	.byte		N09   
	.byte	W48
@ 010   ----------------------------------------
	.byte		N21   
	.byte	W24
	.byte		N21   
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N24   
	.byte	W24
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
	.byte		N12   , Ds2 , v052
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N12   , Ds3 
	.byte	W12
@ 032   ----------------------------------------
	.byte		        Cs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N18   , As3 
	.byte	W18
	.byte		        Bn3 
	.byte	W18
	.byte		N12   , As3 
	.byte	W12
@ 033   ----------------------------------------
	.byte		        Bn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
@ 034   ----------------------------------------
	.byte		N04   , Ds1 , v100
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        Ds1 , v104
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        Ds1 , v108
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        Ds1 , v112
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        Ds1 , v116
	.byte	W06
	.byte		        Ds1 , v120
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        Ds1 , v124
	.byte	W06
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
thereincarnation_5_036:
	.byte		N04   , Dn1 , v108
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte	PEND
@ 037   ----------------------------------------
thereincarnation_5_037:
	.byte		N04   , Fs1 , v108
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N04   , En1 
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte		N04   
	.byte	W06
	.byte	PEND
@ 038   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_036
@ 039   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_037
@ 040   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_036
@ 041   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_037
@ 042   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_036
@ 043   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_037
@ 044   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_036
@ 045   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_037
@ 046   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_036
@ 047   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_037
@ 048   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_036
@ 049   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_037
@ 050   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_036
@ 051   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_5_037
	.byte	GOTO
	 .word	thereincarnation_5_B1
thereincarnation_5_B2:
@ 052   ----------------------------------------
	.byte	FINE

@**************** Track 6 (Midi-Chn.6) ****************@

thereincarnation_6:
	.byte	KEYSH , thereincarnation_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 47
	.byte		VOL   , 103*thereincarnation_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W24
	.byte		N03   , Bn1 , v024
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Bn1 , v032
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Bn1 , v040
	.byte	W03
	.byte		        Bn1 , v048
	.byte	W03
	.byte		        Bn1 , v052
	.byte	W03
	.byte		        Bn1 , v056
	.byte	W03
	.byte		        Bn1 , v060
	.byte	W03
	.byte		        Bn1 , v064
	.byte	W03
	.byte		        Bn1 , v068
	.byte	W03
	.byte		        Bn1 , v076
	.byte	W03
	.byte		        Bn1 , v080
	.byte	W03
	.byte		        Bn1 , v084
	.byte	W03
	.byte		        Bn1 , v092
	.byte	W03
	.byte		        Bn1 , v096
	.byte	W03
	.byte		        Bn1 , v100
	.byte	W03
	.byte		        Bn1 , v108
	.byte	W03
	.byte		        Bn1 , v112
	.byte	W03
	.byte		        Bn1 , v116
	.byte	W03
	.byte		        Bn1 , v120
	.byte	W03
thereincarnation_6_B1:
@ 003   ----------------------------------------
	.byte		N09   , Bn1 , v127
	.byte	W96
@ 004   ----------------------------------------
thereincarnation_6_004:
	.byte		N09   , As1 , v108
	.byte	W12
	.byte		        As1 , v112
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        Cs2 , v116
	.byte	W12
	.byte		        Cs2 , v120
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N06   , Ds2 , v124
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds2 , v127
	.byte	W06
	.byte	PEND
@ 005   ----------------------------------------
	.byte		N09   , Gs1 
	.byte	W96
@ 006   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_004
@ 007   ----------------------------------------
	.byte		N09   , Gs1 , v127
	.byte	W48
	.byte		        Gs1 , v112
	.byte	W48
@ 008   ----------------------------------------
	.byte		        Fs1 
	.byte	W48
	.byte		N09   
	.byte	W48
@ 009   ----------------------------------------
	.byte		        As1 
	.byte	W48
	.byte		N09   
	.byte	W24
	.byte		N03   , As1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        As1 , v056
	.byte	W03
	.byte		        As1 , v064
	.byte	W03
	.byte		        As1 , v048
	.byte	W03
	.byte		        As1 , v084
	.byte	W03
	.byte		        As1 , v092
	.byte	W03
	.byte		        As1 , v100
	.byte	W03
@ 010   ----------------------------------------
	.byte		N09   , As1 , v124
	.byte	W12
	.byte		        Gn1 , v112
	.byte	W12
	.byte		        As1 , v124
	.byte	W12
	.byte		        Cs2 , v112
	.byte	W12
	.byte		        Gn1 , v108
	.byte	W12
	.byte		N06   , Cs2 , v124
	.byte	W12
	.byte		N24   , Cs2 , v127
	.byte	W24
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
	.byte		N12   , Gn1 , v084
	.byte	W18
	.byte		        As1 , v104
	.byte	W18
	.byte		        Ds2 , v124
	.byte	W12
	.byte		        Gn1 , v092
	.byte	W18
	.byte		        As1 , v108
	.byte	W18
	.byte		        Ds2 , v124
	.byte	W12
@ 035   ----------------------------------------
	.byte	W48
	.byte		N03   , Bn1 , v024
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Bn1 , v032
	.byte	W03
	.byte		        Bn1 , v040
	.byte	W03
	.byte		        Bn1 , v048
	.byte	W03
	.byte		        Bn1 , v052
	.byte	W03
	.byte		        Bn1 , v056
	.byte	W03
	.byte		        Bn1 , v064
	.byte	W03
	.byte		        Bn1 , v048
	.byte	W03
	.byte		        Bn1 , v080
	.byte	W03
	.byte		        Bn1 , v084
	.byte	W03
	.byte		        Bn1 , v092
	.byte	W03
	.byte		        Bn1 , v100
	.byte	W03
	.byte		        Bn1 , v104
	.byte	W03
	.byte		        Bn1 , v112
	.byte	W03
@ 036   ----------------------------------------
thereincarnation_6_036:
	.byte		N09   , Bn1 , v124
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 037   ----------------------------------------
thereincarnation_6_037:
	.byte		N12   , Bn1 , v124
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte	PEND
@ 038   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_036
@ 039   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_037
@ 040   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_036
@ 041   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_037
@ 042   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_036
@ 043   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_037
@ 044   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_036
@ 045   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_037
@ 046   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_036
@ 047   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_037
@ 048   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_036
@ 049   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_037
@ 050   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_036
@ 051   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_6_037
	.byte	GOTO
	 .word	thereincarnation_6_B1
thereincarnation_6_B2:
@ 052   ----------------------------------------
	.byte	FINE

@**************** Track 7 (Midi-Chn.7) ****************@

thereincarnation_7:
	.byte	KEYSH , thereincarnation_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 80
	.byte		VOL   , 112*thereincarnation_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
thereincarnation_7_B1:
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
thereincarnation_7_011:
	.byte	W06
	.byte		N04   , Bn4 , v060
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_011
@ 013   ----------------------------------------
thereincarnation_7_013:
	.byte	W06
	.byte		N04   , As4 , v060
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte	PEND
@ 014   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_013
@ 015   ----------------------------------------
thereincarnation_7_015:
	.byte	W06
	.byte		N04   , Gs4 , v060
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte	PEND
@ 016   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_015
@ 017   ----------------------------------------
thereincarnation_7_017:
	.byte	W06
	.byte		N04   , Fs4 , v060
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte	PEND
@ 018   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_017
@ 019   ----------------------------------------
thereincarnation_7_019:
	.byte	W06
	.byte		N04   , Ds4 , v060
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_019
@ 021   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_017
@ 022   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_017
@ 023   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_015
@ 024   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_015
@ 025   ----------------------------------------
	.byte	W06
	.byte		N04   , As4 , v060
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
@ 026   ----------------------------------------
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N04   
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N04   
	.byte	W06
@ 027   ----------------------------------------
thereincarnation_7_027:
	.byte	W06
	.byte		N04   , Bn4 , v060
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Ds5 
	.byte	W06
	.byte	PEND
@ 028   ----------------------------------------
thereincarnation_7_028:
	.byte	W06
	.byte		N04   , As4 , v060
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte	PEND
@ 029   ----------------------------------------
thereincarnation_7_029:
	.byte	W06
	.byte		N04   , Gs4 , v060
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W06
	.byte	PEND
@ 030   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_028
@ 031   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_027
@ 032   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_028
@ 033   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_029
@ 034   ----------------------------------------
	.byte	W36
	.byte		N12   , Ds4 , v124
	.byte	W12
	.byte		        Gn3 
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		        Ds4 
	.byte	W12
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
thereincarnation_7_044:
	.byte		N06   , Bn3 , v124
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N24   , Fs3 
	.byte	W30
	.byte		N06   , Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N24   , Fs3 
	.byte	W30
	.byte	PEND
@ 045   ----------------------------------------
thereincarnation_7_045:
	.byte		N06   , Bn3 , v124
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N48   , Fs3 
	.byte	W54
	.byte		N24   , An3 
	.byte	W24
	.byte	PEND
@ 046   ----------------------------------------
thereincarnation_7_046:
	.byte		N06   , Bn3 , v124
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N06   , En4 
	.byte	W12
	.byte	PEND
@ 047   ----------------------------------------
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N48   , Bn3 
	.byte	W54
	.byte		N24   , Cs4 
	.byte	W24
@ 048   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_044
@ 049   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_045
@ 050   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_7_046
@ 051   ----------------------------------------
	.byte		N06   , Dn4 , v124
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N72   , Bn3 
	.byte	W78
	.byte	GOTO
	 .word	thereincarnation_7_B1
thereincarnation_7_B2:
@ 052   ----------------------------------------
	.byte	FINE

@**************** Track 8 (Midi-Chn.8) ****************@

thereincarnation_8:
	.byte	KEYSH , thereincarnation_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 127*thereincarnation_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
thereincarnation_8_B1:
@ 003   ----------------------------------------
	.byte		N09   , Bn4 , v104
	.byte	W96
@ 004   ----------------------------------------
	.byte		        Fs4 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W24
@ 005   ----------------------------------------
	.byte		N09   , Gs4 
	.byte	W96
@ 006   ----------------------------------------
	.byte		        Ds4 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W24
@ 007   ----------------------------------------
	.byte		N09   , En4 
	.byte	W48
	.byte		N09   
	.byte	W48
@ 008   ----------------------------------------
	.byte		        Ds4 
	.byte	W48
	.byte		N09   
	.byte	W48
@ 009   ----------------------------------------
	.byte		        Gn4 
	.byte	W48
	.byte		N09   
	.byte	W48
@ 010   ----------------------------------------
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N24   
	.byte	W24
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
thereincarnation_8_036:
	.byte		N06   , Dn4 , v124
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W30
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W30
	.byte	PEND
@ 037   ----------------------------------------
thereincarnation_8_037:
	.byte		N06   , Dn4 , v124
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N48   , Bn3 
	.byte	W54
	.byte		N24   , Cs4 
	.byte	W24
	.byte	PEND
@ 038   ----------------------------------------
thereincarnation_8_038:
	.byte		N06   , Dn4 , v124
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N18   , Bn3 
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N18   , Bn3 
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W12
	.byte	PEND
@ 039   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_8_037
@ 040   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_8_036
@ 041   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_8_037
@ 042   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_8_038
@ 043   ----------------------------------------
	.byte		N06   , Dn4 , v124
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N48   , Bn3 
	.byte	W54
	.byte		N24   , An4 
	.byte	W24
@ 044   ----------------------------------------
thereincarnation_8_044:
	.byte		N06   , Bn4 , v124
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , Fs4 
	.byte	W30
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , Fs4 
	.byte	W30
	.byte	PEND
@ 045   ----------------------------------------
thereincarnation_8_045:
	.byte		N06   , Bn4 , v124
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N48   , Fs4 
	.byte	W54
	.byte		N24   , An4 
	.byte	W24
	.byte	PEND
@ 046   ----------------------------------------
thereincarnation_8_046:
	.byte		N06   , Bn4 , v124
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , En5 
	.byte	W12
	.byte	PEND
@ 047   ----------------------------------------
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		N48   , Bn4 
	.byte	W54
	.byte		N24   , Cs5 
	.byte	W24
@ 048   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_8_044
@ 049   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_8_045
@ 050   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_8_046
@ 051   ----------------------------------------
	.byte		N06   , Dn5 , v124
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		N72   , Bn4 
	.byte	W78
	.byte	GOTO
	 .word	thereincarnation_8_B1
thereincarnation_8_B2:
@ 052   ----------------------------------------
	.byte	FINE

@**************** Track 9 (Midi-Chn.9) ****************@

thereincarnation_9:
	.byte	KEYSH , thereincarnation_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 14
	.byte		VOL   , 118*thereincarnation_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N72   , En3 , v112
	.byte	W72
	.byte		        Fs3 
	.byte	W24
@ 001   ----------------------------------------
	.byte	W48
	.byte		TIE   , Bn2 
	.byte	W48
@ 002   ----------------------------------------
	.byte	W96
	.byte		EOT   
thereincarnation_9_B1:
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
	.byte		VOICE , 48
	.byte		VOL   , 118*thereincarnation_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W96
@ 027   ----------------------------------------
	.byte		N96   , Bn2 , v096
	.byte	W96
@ 028   ----------------------------------------
	.byte		        As2 
	.byte	W96
@ 029   ----------------------------------------
	.byte		        Bn2 
	.byte	W96
@ 030   ----------------------------------------
	.byte		N48   , As2 
	.byte	W48
	.byte		N24   , Bn2 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
@ 031   ----------------------------------------
	.byte		N96   , Ds3 
	.byte	W96
@ 032   ----------------------------------------
	.byte		        Cs3 
	.byte	W96
@ 033   ----------------------------------------
	.byte		        Ds3 
	.byte	W96
@ 034   ----------------------------------------
	.byte		N12   , Gn5 , v112
	.byte	W18
	.byte		        As5 
	.byte	W18
	.byte		        Ds6 
	.byte	W12
	.byte		        Gn5 
	.byte	W18
	.byte		        As5 
	.byte	W18
	.byte		        Ds6 
	.byte	W12
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
thereincarnation_9_036:
	.byte		N48   , Dn3 , v112
	.byte	W48
	.byte		        En3 
	.byte	W48
	.byte	PEND
@ 037   ----------------------------------------
thereincarnation_9_037:
	.byte		N72   , Fs3 , v112
	.byte	W72
	.byte		N24   , En3 
	.byte	W24
	.byte	PEND
@ 038   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_9_036
@ 039   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_9_037
@ 040   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_9_036
@ 041   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_9_037
@ 042   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_9_036
@ 043   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_9_037
@ 044   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_9_036
@ 045   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_9_037
@ 046   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_9_036
@ 047   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_9_037
@ 048   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_9_036
@ 049   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_9_037
@ 050   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_9_036
@ 051   ----------------------------------------
	.byte		N96   , Fs3 , v112
	.byte	W96
	.byte	GOTO
	 .word	thereincarnation_9_B1
thereincarnation_9_B2:
@ 052   ----------------------------------------
	.byte	FINE

@**************** Track 10 (Midi-Chn.10) ****************@

thereincarnation_10:
	.byte	KEYSH , thereincarnation_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		VOL   , 127*thereincarnation_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W24
	.byte		N03   , Gn2 , v024
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Gn2 , v032
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Gn2 , v040
	.byte	W03
	.byte		        Gn2 , v048
	.byte	W03
	.byte		        Gn2 , v052
	.byte	W03
	.byte		        Gn2 , v056
	.byte	W03
	.byte		        Gn2 , v060
	.byte	W03
	.byte		        Gn2 , v064
	.byte	W03
	.byte		        Gn2 , v068
	.byte	W03
	.byte		        Gn2 , v076
	.byte	W03
	.byte		        Gn2 , v080
	.byte	W03
	.byte		        Gn2 , v084
	.byte	W03
	.byte		        Gn2 , v088
	.byte	W03
	.byte		        Gn2 , v092
	.byte	W03
	.byte		        Gn2 , v100
	.byte	W03
	.byte		        Gn2 , v104
	.byte	W03
	.byte		        Gn2 , v108
	.byte	W03
	.byte		        Gn2 , v112
	.byte	W03
	.byte		        Gn2 , v120
	.byte	W03
thereincarnation_10_B1:
@ 003   ----------------------------------------
	.byte		N96   , En1 , v112
	.byte		N96   , En2 , v124
	.byte	W96
@ 004   ----------------------------------------
	.byte		N06   , En1 , v104
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 , v108
	.byte	W12
	.byte		        En1 , v092
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v104
	.byte	W06
	.byte		        En1 , v108
	.byte	W06
@ 005   ----------------------------------------
	.byte		N96   , En1 , v112
	.byte		N96   , En2 , v127
	.byte	W96
@ 006   ----------------------------------------
	.byte		N06   , En1 , v108
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 , v092
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v104
	.byte	W06
	.byte		        En1 , v108
	.byte	W06
@ 007   ----------------------------------------
	.byte		N12   , En1 , v112
	.byte		N42   , En2 , v127
	.byte	W48
	.byte		N12   , En1 , v112
	.byte		N42   , En2 
	.byte	W48
@ 008   ----------------------------------------
	.byte		N12   , En1 
	.byte		N42   , En2 
	.byte	W48
	.byte		N12   , En1 
	.byte		N42   , En2 
	.byte	W48
@ 009   ----------------------------------------
	.byte		N12   , En1 
	.byte		N42   , En2 
	.byte	W48
	.byte		N12   , En1 
	.byte		N42   , En2 
	.byte	W24
	.byte		N03   , En1 , v040
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		        En1 , v052
	.byte	W03
	.byte		        En1 , v060
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		        En1 , v084
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		        En1 , v108
	.byte	W03
@ 010   ----------------------------------------
	.byte		N06   , En1 , v120
	.byte		N44   , En2 
	.byte	W12
	.byte		N06   , En1 , v100
	.byte	W12
	.byte		        En1 , v124
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v100
	.byte		N21   , En2 
	.byte	W12
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		N18   , En1 , v127
	.byte		TIE   , Gn2 
	.byte	W24
@ 011   ----------------------------------------
	.byte		N06   , En1 , v100
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		EOT   , Gn2 
	.byte	W12
@ 012   ----------------------------------------
thereincarnation_10_012:
	.byte	W12
	.byte		N06   , En1 , v100
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
@ 013   ----------------------------------------
thereincarnation_10_013:
	.byte		N06   , En1 , v100
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W24
	.byte	PEND
@ 014   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_012
@ 015   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_013
@ 016   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_012
@ 017   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_013
@ 018   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_012
@ 019   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_013
@ 020   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_012
@ 021   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_013
@ 022   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_012
@ 023   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_013
@ 024   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_012
@ 025   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_013
@ 026   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_012
@ 027   ----------------------------------------
	.byte		N06   , En1 , v100
	.byte	W96
@ 028   ----------------------------------------
	.byte		N06   
	.byte	W96
@ 029   ----------------------------------------
	.byte		N06   
	.byte	W96
@ 030   ----------------------------------------
	.byte		N06   
	.byte	W96
@ 031   ----------------------------------------
thereincarnation_10_031:
	.byte		N06   , En1 , v100
	.byte		N90   , En2 
	.byte	W96
	.byte	PEND
@ 032   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_031
@ 033   ----------------------------------------
	.byte		N06   , En1 , v100
	.byte		N42   , En2 
	.byte	W48
	.byte		N06   , En1 
	.byte		N42   , En2 
	.byte	W48
@ 034   ----------------------------------------
	.byte		N06   , En1 , v108
	.byte		N36   , En2 
	.byte	W06
	.byte		N06   , En1 , v084
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v108
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v108
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v108
	.byte		N44   , En2 
	.byte	W06
	.byte		N06   , En1 , v084
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v108
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		        En1 , v124
	.byte	W06
	.byte		N24   , En1 , v127
	.byte	W06
@ 035   ----------------------------------------
	.byte	W72
	.byte		N03   , En1 , v024
	.byte		N03   , Gn2 
	.byte	W03
	.byte		        En1 , v032
	.byte		N03   , Gn2 
	.byte	W03
	.byte		        En1 , v048
	.byte		N03   , Gn2 
	.byte	W03
	.byte		        En1 , v060
	.byte		N03   , Gn2 
	.byte	W03
	.byte		        En1 , v048
	.byte		N03   , Gn2 
	.byte	W03
	.byte		        En1 , v088
	.byte		N03   , Gn2 
	.byte	W03
	.byte		        En1 , v100
	.byte		N03   , Gn2 
	.byte	W03
	.byte		        En1 , v116
	.byte		N03   , Gn2 
	.byte	W03
@ 036   ----------------------------------------
thereincarnation_10_036:
	.byte		N06   , En1 , v112
	.byte		N96   , En2 , v127
	.byte	W06
	.byte		N06   , En1 , v092
	.byte	W06
	.byte		        En1 , v088
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v088
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte	PEND
@ 037   ----------------------------------------
thereincarnation_10_037:
	.byte		N06   , En1 , v120
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v068
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		        En1 , v100
	.byte		N24   , Gn2 , v127
	.byte	W06
	.byte		N06   , En1 , v080
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte	PEND
@ 038   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_036
@ 039   ----------------------------------------
thereincarnation_10_039:
	.byte		N06   , En1 , v120
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v068
	.byte	W06
	.byte		        En1 , v100
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		        En1 , v100
	.byte		N24   , Gn2 , v112
	.byte	W06
	.byte		N06   , En1 , v080
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte	PEND
@ 040   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_036
@ 041   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_037
@ 042   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_036
@ 043   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_037
@ 044   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_036
@ 045   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_037
@ 046   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_036
@ 047   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_039
@ 048   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_036
@ 049   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_037
@ 050   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_036
@ 051   ----------------------------------------
	.byte	PATT
	 .word	thereincarnation_10_037
	.byte	GOTO
	 .word	thereincarnation_10_B1
thereincarnation_10_B2:
@ 052   ----------------------------------------
	.byte	FINE

@******************************************************@
	.align	2

thereincarnation:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	thereincarnation_pri	@ Priority
	.byte	thereincarnation_rev	@ Reverb.

	.word	thereincarnation_grp

	.word	thereincarnation_1
	.word	thereincarnation_2
	.word	thereincarnation_3
	.word	thereincarnation_4
	.word	thereincarnation_5
	.word	thereincarnation_6
	.word	thereincarnation_7
	.word	thereincarnation_8
	.word	thereincarnation_9
	.word	thereincarnation_10

	.end

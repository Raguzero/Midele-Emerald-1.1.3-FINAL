	.include "MPlayDef.s"

	.equ	finalbossbreathfire2_grp, voicegroup000
	.equ	finalbossbreathfire2_pri, 0
	.equ	finalbossbreathfire2_rev, 0
	.equ	finalbossbreathfire2_mvl, 87
	.equ	finalbossbreathfire2_key, 0
	.equ	finalbossbreathfire2_tbs, 1
	.equ	finalbossbreathfire2_exg, 0
	.equ	finalbossbreathfire2_cmp, 1

	.section .rodata
	.global	finalbossbreathfire2
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

finalbossbreathfire2_1:
	.byte	KEYSH , finalbossbreathfire2_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 115*finalbossbreathfire2_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 88*finalbossbreathfire2_mvl/mxv
	.byte		PAN   , c_v-1
	.byte	W24
	.byte	TEMPO , 120*finalbossbreathfire2_tbs/2
	.byte	W02
	.byte	TEMPO , 120*finalbossbreathfire2_tbs/2
	.byte	W22
@ 001   ----------------------------------------
	.byte	W36
	.byte		N72   , Cn4 , v072
	.byte	W60
@ 002   ----------------------------------------
	.byte	W36
	.byte		        As3 
	.byte	W60
@ 003   ----------------------------------------
	.byte	W36
	.byte		        Cn4 
	.byte	W60
@ 004   ----------------------------------------
	.byte	W36
	.byte		        As3 
	.byte	W60
@ 005   ----------------------------------------
	.byte	W12
	.byte		        Gn3 
	.byte	W84
@ 006   ----------------------------------------
	.byte	TEMPO , 115*finalbossbreathfire2_tbs/2
	.byte	W96
finalbossbreathfire2_1_B1:
@ 007   ----------------------------------------
	.byte	TEMPO , 129*finalbossbreathfire2_tbs/2
	.byte	W12
	.byte		N48   , Cn3 , v072
	.byte	W48
	.byte		        Ds3 
	.byte	W36
@ 008   ----------------------------------------
finalbossbreathfire2_1_008:
	.byte	W12
	.byte		N48   , Dn3 , v072
	.byte	W48
	.byte		        Fn3 
	.byte	W36
	.byte	PEND
@ 009   ----------------------------------------
finalbossbreathfire2_1_009:
	.byte	W12
	.byte		N48   , Ds3 , v072
	.byte	W48
	.byte		N24   , Cs3 
	.byte	W24
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
@ 010   ----------------------------------------
	.byte	W12
	.byte		N96   , Cn3 
	.byte	W84
@ 011   ----------------------------------------
finalbossbreathfire2_1_011:
	.byte	W12
	.byte		N48   , Cn3 , v072
	.byte	W48
	.byte		        Ds3 
	.byte	W36
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_008
@ 013   ----------------------------------------
finalbossbreathfire2_1_013:
	.byte	W12
	.byte		N48   , Gn3 , v072
	.byte	W48
	.byte		        Bn3 
	.byte	W36
	.byte	PEND
@ 014   ----------------------------------------
	.byte	W12
	.byte		N96   , Cn4 
	.byte	W84
@ 015   ----------------------------------------
finalbossbreathfire2_1_015:
	.byte	W09
	.byte		N12   , Gs3 , v076
	.byte	W12
	.byte		        Gn3 
	.byte	W72
	.byte	W03
	.byte	PEND
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
finalbossbreathfire2_1_017:
	.byte	W09
	.byte		N12   , As3 , v076
	.byte	W12
	.byte		        Gs3 
	.byte	W72
	.byte	W03
	.byte	PEND
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
finalbossbreathfire2_1_019:
	.byte	W09
	.byte		N12   , Gs3 , v076
	.byte	W12
	.byte		        Gn3 
	.byte	W36
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W24
	.byte	W03
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_019
@ 021   ----------------------------------------
finalbossbreathfire2_1_021:
	.byte	W09
	.byte		N12   , Gs3 , v076
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W03
	.byte	PEND
@ 022   ----------------------------------------
finalbossbreathfire2_1_022:
	.byte	W09
	.byte		N12   , Fn3 , v076
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W03
	.byte	PEND
@ 023   ----------------------------------------
finalbossbreathfire2_1_023:
	.byte	W09
	.byte		TIE   , Gn2 , v076
	.byte	W84
	.byte	W03
	.byte	PEND
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W09
	.byte		EOT   
	.byte	W03
	.byte		N48   , Cn3 , v072
	.byte	W48
	.byte		        Ds3 
	.byte	W36
@ 026   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_008
@ 027   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_009
@ 028   ----------------------------------------
	.byte	W12
	.byte		N96   , Cn3 , v072
	.byte	W84
@ 029   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_011
@ 030   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_008
@ 031   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_013
@ 032   ----------------------------------------
	.byte	W12
	.byte		N96   , Cn4 , v072
	.byte	W84
@ 033   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_015
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_017
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_019
@ 038   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_019
@ 039   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_021
@ 040   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_022
@ 041   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_1_023
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W09
	.byte		EOT   , Gn2 
	.byte	GOTO
	 .word	finalbossbreathfire2_1_B1
finalbossbreathfire2_1_B2:
	.byte	FINE

@**************** Track 2 (Midi-Chn.3) ****************@

finalbossbreathfire2_2:
	.byte	KEYSH , finalbossbreathfire2_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 47
	.byte		VOL   , 81*finalbossbreathfire2_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		N03   , Gs1 , v092
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
@ 001   ----------------------------------------
finalbossbreathfire2_2_001:
	.byte		N24   , Cs2 , v092
	.byte	W72
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_001
@ 003   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_001
@ 004   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_001
@ 005   ----------------------------------------
finalbossbreathfire2_2_005:
	.byte		N06   , Cs2 , v092
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cs2 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
finalbossbreathfire2_2_B1:
@ 007   ----------------------------------------
finalbossbreathfire2_2_007:
	.byte		N06   , Cs2 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N24   
	.byte	W84
	.byte	PEND
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_005
@ 011   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_007
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_005
@ 015   ----------------------------------------
finalbossbreathfire2_2_015:
	.byte	W84
	.byte		N06   , Gs1 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 016   ----------------------------------------
finalbossbreathfire2_2_016:
	.byte		N06   , Gs1 , v092
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W36
	.byte	PEND
@ 017   ----------------------------------------
finalbossbreathfire2_2_017:
	.byte	W84
	.byte		N06   , Cs2 , v092
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 018   ----------------------------------------
finalbossbreathfire2_2_018:
	.byte		N06   , Cs2 , v092
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W36
	.byte	PEND
@ 019   ----------------------------------------
finalbossbreathfire2_2_019:
	.byte		N06   , Gs1 , v092
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs2 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_019
@ 021   ----------------------------------------
finalbossbreathfire2_2_021:
	.byte		N06   , Gs1 , v092
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
@ 022   ----------------------------------------
finalbossbreathfire2_2_022:
	.byte		N06   , An1 , v092
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
@ 023   ----------------------------------------
finalbossbreathfire2_2_023:
	.byte		N06   , Gs1 , v092
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 024   ----------------------------------------
finalbossbreathfire2_2_024:
	.byte		N06   , Gs1 , v092
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
@ 025   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_007
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_005
@ 029   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_007
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_005
@ 033   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_015
@ 034   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_016
@ 035   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_017
@ 036   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_018
@ 037   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_019
@ 038   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_019
@ 039   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_021
@ 040   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_022
@ 041   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_023
@ 042   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_2_024
@ 043   ----------------------------------------
	.byte	W09
	.byte	GOTO
	 .word	finalbossbreathfire2_2_B1
finalbossbreathfire2_2_B2:
	.byte	FINE

@**************** Track 3 (Midi-Chn.4) ****************@

finalbossbreathfire2_3:
	.byte	KEYSH , finalbossbreathfire2_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 17
	.byte		VOL   , 98*finalbossbreathfire2_mvl/mxv
	.byte		PAN   , c_v-1
	.byte	W03
	.byte		N03   , Gs1 , v092
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
@ 001   ----------------------------------------
	.byte	W24
	.byte		N72   , Cn3 , v100
	.byte	W72
@ 002   ----------------------------------------
	.byte	W24
	.byte		        As2 
	.byte	W72
@ 003   ----------------------------------------
	.byte	W24
	.byte		        Cn3 
	.byte	W72
@ 004   ----------------------------------------
	.byte	W24
	.byte		        As2 
	.byte	W72
@ 005   ----------------------------------------
	.byte		TIE   , Gn2 
	.byte	W96
@ 006   ----------------------------------------
	.byte	W96
	.byte		EOT   
finalbossbreathfire2_3_B1:
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
finalbossbreathfire2_3_015:
	.byte		N06   , Dn3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 016   ----------------------------------------
finalbossbreathfire2_3_016:
	.byte		N06   , Dn3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 017   ----------------------------------------
finalbossbreathfire2_3_017:
	.byte		N06   , Fn3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 018   ----------------------------------------
finalbossbreathfire2_3_018:
	.byte		N06   , Fn3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 019   ----------------------------------------
finalbossbreathfire2_3_019:
	.byte		N12   , Bn2 , v112
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		        Cn3 
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_3_019
@ 021   ----------------------------------------
finalbossbreathfire2_3_021:
	.byte		N12   , Bn2 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 022   ----------------------------------------
finalbossbreathfire2_3_022:
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte	PEND
@ 023   ----------------------------------------
	.byte		TIE   , Bn1 
	.byte	W96
@ 024   ----------------------------------------
	.byte	W96
	.byte		EOT   
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
	.byte	PATT
	 .word	finalbossbreathfire2_3_015
@ 034   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_3_016
@ 035   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_3_017
@ 036   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_3_018
@ 037   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_3_019
@ 038   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_3_019
@ 039   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_3_021
@ 040   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_3_022
@ 041   ----------------------------------------
	.byte		TIE   , Bn1 , v112
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 043   ----------------------------------------
	.byte	W09
	.byte	GOTO
	 .word	finalbossbreathfire2_3_B1
finalbossbreathfire2_3_B2:
	.byte	FINE

@**************** Track 4 (Midi-Chn.5) ****************@

finalbossbreathfire2_4:
	.byte	KEYSH , finalbossbreathfire2_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 17
	.byte		VOL   , 100*finalbossbreathfire2_mvl/mxv
	.byte		PAN   , c_v-1
	.byte	W48
@ 001   ----------------------------------------
	.byte		N84   , Cn2 , v100
	.byte	W96
@ 002   ----------------------------------------
	.byte		N84   
	.byte	W96
@ 003   ----------------------------------------
	.byte		N84   
	.byte	W96
@ 004   ----------------------------------------
	.byte		N84   
	.byte	W96
@ 005   ----------------------------------------
finalbossbreathfire2_4_005:
	.byte		N06   , Cn2 , v100
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_4_005
finalbossbreathfire2_4_B1:
@ 007   ----------------------------------------
	.byte		N96   , Ds2 , v100
	.byte	W96
@ 008   ----------------------------------------
	.byte		        Fn2 
	.byte	W96
@ 009   ----------------------------------------
finalbossbreathfire2_4_009:
	.byte		N48   , Ds2 , v100
	.byte	W48
	.byte		        Cs2 
	.byte	W48
	.byte	PEND
@ 010   ----------------------------------------
	.byte		N96   , Ds2 
	.byte	W96
@ 011   ----------------------------------------
	.byte		N96   
	.byte	W96
@ 012   ----------------------------------------
	.byte		        Fn2 
	.byte	W96
@ 013   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_4_009
@ 014   ----------------------------------------
finalbossbreathfire2_4_014:
	.byte		N96   , Ds2 , v100
	.byte	W92
	.byte	W03
	.byte		VOL   , 110*finalbossbreathfire2_mvl/mxv
	.byte	W01
	.byte	PEND
@ 015   ----------------------------------------
finalbossbreathfire2_4_015:
	.byte		N06   , Gn3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 016   ----------------------------------------
finalbossbreathfire2_4_016:
	.byte		N06   , Gn3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 017   ----------------------------------------
finalbossbreathfire2_4_017:
	.byte		N06   , Gs3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 018   ----------------------------------------
finalbossbreathfire2_4_018:
	.byte		N06   , Gs3 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W05
	.byte		VOL   , 100*finalbossbreathfire2_mvl/mxv
	.byte	W01
	.byte	PEND
@ 019   ----------------------------------------
finalbossbreathfire2_4_019:
	.byte		N36   , Dn3 , v100
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N36   , Ds3 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_4_019
@ 021   ----------------------------------------
finalbossbreathfire2_4_021:
	.byte		N24   , Dn3 , v100
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte	PEND
@ 022   ----------------------------------------
	.byte	W96
@ 023   ----------------------------------------
	.byte	W96
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte		N96   , Ds2 
	.byte	W96
@ 026   ----------------------------------------
	.byte		        Fn2 
	.byte	W96
@ 027   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_4_009
@ 028   ----------------------------------------
	.byte		N96   , Ds2 , v100
	.byte	W96
@ 029   ----------------------------------------
	.byte		N96   
	.byte	W96
@ 030   ----------------------------------------
	.byte		        Fn2 
	.byte	W96
@ 031   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_4_009
@ 032   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_4_014
@ 033   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_4_015
@ 034   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_4_016
@ 035   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_4_017
@ 036   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_4_018
@ 037   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_4_019
@ 038   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_4_019
@ 039   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_4_021
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W09
	.byte	GOTO
	 .word	finalbossbreathfire2_4_B1
finalbossbreathfire2_4_B2:
	.byte	FINE

@**************** Track 5 (Midi-Chn.6) ****************@

finalbossbreathfire2_5:
	.byte	KEYSH , finalbossbreathfire2_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 17
	.byte		VOL   , 91*finalbossbreathfire2_mvl/mxv
	.byte		PAN   , c_v-1
	.byte	W48
@ 001   ----------------------------------------
	.byte	W24
	.byte		N72   , Fs3 , v100
	.byte	W72
@ 002   ----------------------------------------
	.byte	W24
	.byte		        Ds3 
	.byte	W72
@ 003   ----------------------------------------
	.byte	W24
	.byte		        Fs3 
	.byte	W72
@ 004   ----------------------------------------
	.byte	W24
	.byte		        Ds3 
	.byte	W72
@ 005   ----------------------------------------
	.byte		TIE   , Cn3 
	.byte	W96
@ 006   ----------------------------------------
	.byte	W96
	.byte		EOT   
finalbossbreathfire2_5_B1:
@ 007   ----------------------------------------
	.byte		N96   , Gn2 , v100
	.byte	W96
@ 008   ----------------------------------------
	.byte		        Gs2 
	.byte	W96
@ 009   ----------------------------------------
finalbossbreathfire2_5_009:
	.byte		N48   , Gn2 , v100
	.byte	W48
	.byte		        Fn2 
	.byte	W48
	.byte	PEND
@ 010   ----------------------------------------
	.byte		N96   , Gn2 
	.byte	W96
@ 011   ----------------------------------------
	.byte		N96   
	.byte	W96
@ 012   ----------------------------------------
	.byte		        Gs2 
	.byte	W96
@ 013   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_5_009
@ 014   ----------------------------------------
	.byte		N96   , Gn2 , v100
	.byte	W96
@ 015   ----------------------------------------
finalbossbreathfire2_5_015:
	.byte		N12   , Dn3 , v112
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	PEND
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
finalbossbreathfire2_5_017:
	.byte		N12   , Fn3 , v112
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	PEND
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
finalbossbreathfire2_5_019:
	.byte		N12   , Dn3 , v112
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		        Fn3 
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_5_019
@ 021   ----------------------------------------
finalbossbreathfire2_5_021:
	.byte		N12   , Dn3 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 022   ----------------------------------------
finalbossbreathfire2_5_022:
	.byte		N12   , Dn3 , v112
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte	PEND
@ 023   ----------------------------------------
	.byte		TIE   , Dn2 
	.byte	W96
@ 024   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 025   ----------------------------------------
	.byte		N96   , Gn2 , v100
	.byte	W96
@ 026   ----------------------------------------
	.byte		        Gs2 
	.byte	W96
@ 027   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_5_009
@ 028   ----------------------------------------
	.byte		N96   , Gn2 , v100
	.byte	W96
@ 029   ----------------------------------------
	.byte		N96   
	.byte	W96
@ 030   ----------------------------------------
	.byte		        Gs2 
	.byte	W96
@ 031   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_5_009
@ 032   ----------------------------------------
	.byte		N96   , Gn2 , v100
	.byte	W96
@ 033   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_5_015
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_5_017
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_5_019
@ 038   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_5_019
@ 039   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_5_021
@ 040   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_5_022
@ 041   ----------------------------------------
	.byte		TIE   , Dn2 , v112
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 043   ----------------------------------------
	.byte	W09
	.byte	GOTO
	 .word	finalbossbreathfire2_5_B1
finalbossbreathfire2_5_B2:
	.byte	FINE

@**************** Track 6 (Midi-Chn.7) ****************@

finalbossbreathfire2_6:
	.byte	KEYSH , finalbossbreathfire2_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 48
	.byte		VOL   , 97*finalbossbreathfire2_mvl/mxv
	.byte		PAN   , c_v-1
	.byte	W48
@ 001   ----------------------------------------
	.byte	W24
	.byte		N72   , Cn4 , v100
	.byte	W72
@ 002   ----------------------------------------
	.byte	W24
	.byte		        As3 
	.byte	W72
@ 003   ----------------------------------------
	.byte	W24
	.byte		        Cn4 
	.byte	W72
@ 004   ----------------------------------------
	.byte	W24
	.byte		        As3 
	.byte	W72
@ 005   ----------------------------------------
	.byte		TIE   , Gn3 
	.byte	W96
@ 006   ----------------------------------------
	.byte	W96
	.byte		EOT   
finalbossbreathfire2_6_B1:
@ 007   ----------------------------------------
finalbossbreathfire2_6_007:
	.byte		N48   , Cn3 , v100
	.byte	W48
	.byte		        Ds3 
	.byte	W48
	.byte	PEND
@ 008   ----------------------------------------
finalbossbreathfire2_6_008:
	.byte		N48   , Dn3 , v100
	.byte	W48
	.byte		        Fn3 
	.byte	W48
	.byte	PEND
@ 009   ----------------------------------------
finalbossbreathfire2_6_009:
	.byte		N48   , Ds3 , v100
	.byte	W48
	.byte		N24   , Cs3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte	PEND
@ 010   ----------------------------------------
	.byte		N96   , Cn3 
	.byte	W96
@ 011   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_007
@ 012   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_008
@ 013   ----------------------------------------
finalbossbreathfire2_6_013:
	.byte		N48   , Gn3 , v100
	.byte	W48
	.byte		        Bn3 
	.byte	W48
	.byte	PEND
@ 014   ----------------------------------------
	.byte		N96   , Cn4 
	.byte	W96
@ 015   ----------------------------------------
finalbossbreathfire2_6_015:
	.byte		N12   , Gs3 , v112
	.byte	W12
	.byte		        Gn3 
	.byte	W84
	.byte	PEND
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
finalbossbreathfire2_6_017:
	.byte		N12   , As3 , v112
	.byte	W12
	.byte		        Gs3 
	.byte	W84
	.byte	PEND
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
finalbossbreathfire2_6_019:
	.byte		N12   , Gs3 , v112
	.byte	W12
	.byte		        Gn3 
	.byte	W36
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W36
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_019
@ 021   ----------------------------------------
finalbossbreathfire2_6_021:
	.byte		N12   , Gs3 , v112
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
@ 022   ----------------------------------------
finalbossbreathfire2_6_022:
	.byte		N12   , Fn3 , v112
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
@ 023   ----------------------------------------
	.byte		TIE   , Gn2 
	.byte	W96
@ 024   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 025   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_007
@ 026   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_008
@ 027   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_009
@ 028   ----------------------------------------
	.byte		N96   , Cn3 , v100
	.byte	W96
@ 029   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_007
@ 030   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_008
@ 031   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_013
@ 032   ----------------------------------------
	.byte		N96   , Cn4 , v100
	.byte	W96
@ 033   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_015
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_017
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_019
@ 038   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_019
@ 039   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_021
@ 040   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_6_022
@ 041   ----------------------------------------
	.byte		TIE   , Gn2 , v112
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 043   ----------------------------------------
	.byte	W09
	.byte	GOTO
	 .word	finalbossbreathfire2_6_B1
finalbossbreathfire2_6_B2:
	.byte	FINE

@**************** Track 7 (Midi-Chn.8) ****************@

finalbossbreathfire2_7:
	.byte	KEYSH , finalbossbreathfire2_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 81
	.byte		VOL   , 87*finalbossbreathfire2_mvl/mxv
	.byte		PAN   , c_v-1
	.byte	W48
@ 001   ----------------------------------------
finalbossbreathfire2_7_001:
	.byte		N60   , Cn2 , v100
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_001
@ 003   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_001
@ 004   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_001
@ 005   ----------------------------------------
finalbossbreathfire2_7_005:
	.byte		N06   , Cn2 , v100
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_005
finalbossbreathfire2_7_B1:
@ 007   ----------------------------------------
finalbossbreathfire2_7_007:
	.byte		N06   , Cn2 , v100
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte	PEND
@ 008   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 009   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 010   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 011   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 012   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 013   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 014   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 015   ----------------------------------------
finalbossbreathfire2_7_015:
	.byte		N06   , Gn1 , v100
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte	PEND
@ 016   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_015
@ 017   ----------------------------------------
finalbossbreathfire2_7_017:
	.byte		N06   , Fn1 , v100
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte	PEND
@ 018   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_017
@ 019   ----------------------------------------
finalbossbreathfire2_7_019:
	.byte		N12   , Gn1 , v100
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_019
@ 021   ----------------------------------------
finalbossbreathfire2_7_021:
	.byte		N24   , Gn1 , v100
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte	PEND
@ 022   ----------------------------------------
finalbossbreathfire2_7_022:
	.byte		N12   , Fn1 , v100
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte	PEND
@ 023   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_015
@ 024   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_015
@ 025   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 026   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 027   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 028   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 029   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 030   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 031   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 032   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_007
@ 033   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_015
@ 034   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_015
@ 035   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_017
@ 036   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_017
@ 037   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_019
@ 038   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_019
@ 039   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_021
@ 040   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_022
@ 041   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_015
@ 042   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_7_015
@ 043   ----------------------------------------
	.byte	W09
	.byte	GOTO
	 .word	finalbossbreathfire2_7_B1
finalbossbreathfire2_7_B2:
	.byte	FINE

@**************** Track 8 (Midi-Chn.10) ****************@

finalbossbreathfire2_8:
	.byte	KEYSH , finalbossbreathfire2_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 47
	.byte		VOL   , 100*finalbossbreathfire2_mvl/mxv
	.byte		PAN   , c_v-64
	.byte	W48
@ 001   ----------------------------------------
finalbossbreathfire2_8_001:
	.byte		N06   , An2 , v100
	.byte	W90
	.byte		PAN   , c_v+63
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
finalbossbreathfire2_8_002:
	.byte		N06   , An2 , v100
	.byte	W90
	.byte		PAN   , c_v-64
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_001
@ 004   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_002
@ 005   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_001
@ 006   ----------------------------------------
	.byte		N06   , An2 , v100
	.byte	W42
	.byte		PAN   , c_v-64
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		PAN   , c_v-1
	.byte	W06
finalbossbreathfire2_8_B1:
@ 007   ----------------------------------------
finalbossbreathfire2_8_007:
	.byte		N06   , An2 , v100
	.byte	W30
	.byte		        Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 , v080
	.byte	W06
	.byte		        Gs1 , v100
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 , v080
	.byte	W06
	.byte		        Gs1 , v100
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte	PEND
@ 008   ----------------------------------------
finalbossbreathfire2_8_008:
	.byte		N06   , Gs1 , v080
	.byte	W06
	.byte		        Gs1 , v100
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 , v080
	.byte	W06
	.byte		        Gs1 , v100
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 , v080
	.byte	W06
	.byte		        Gs1 , v100
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 , v080
	.byte	W06
	.byte		        Gs1 , v100
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte	PEND
@ 009   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 010   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 011   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_007
@ 012   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 013   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 014   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 015   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_007
@ 016   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 017   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 018   ----------------------------------------
finalbossbreathfire2_8_018:
	.byte		N06   , Gs1 , v080
	.byte	W06
	.byte		        Gs1 , v100
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 , v080
	.byte	W06
	.byte		        Gs1 , v100
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 , v080
	.byte	W06
	.byte		        Gs1 , v100
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 , v080
	.byte	W06
	.byte		        Gs1 , v100
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte	W06
	.byte	PEND
@ 019   ----------------------------------------
finalbossbreathfire2_8_019:
	.byte		N06   , An2 , v100
	.byte	W42
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N06   
	.byte	W42
	.byte		PAN   , c_v-64
	.byte	W06
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_019
@ 021   ----------------------------------------
finalbossbreathfire2_8_021:
	.byte		N06   , An2 , v100
	.byte	W18
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		PAN   , c_v-64
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		PAN   , c_v-64
	.byte	W06
	.byte	PEND
@ 022   ----------------------------------------
finalbossbreathfire2_8_022:
	.byte		N06   , An2 , v100
	.byte	W18
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		PAN   , c_v-64
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		PAN   , c_v-1
	.byte	W06
	.byte	PEND
@ 023   ----------------------------------------
finalbossbreathfire2_8_023:
	.byte		N06   , An2 , v100
	.byte	W30
	.byte		        Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 , v080
	.byte	W06
	.byte		        Gs1 , v100
	.byte	W06
	.byte		        As1 
	.byte	W12
	.byte		        Gs1 , v080
	.byte	W06
	.byte		        Gs1 , v100
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte	W06
	.byte	PEND
@ 024   ----------------------------------------
finalbossbreathfire2_8_024:
	.byte		N06   , An2 , v100
	.byte	W42
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N06   
	.byte	W42
	.byte		PAN   , c_v-1
	.byte	W06
	.byte	PEND
@ 025   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_007
@ 026   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 027   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 028   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 029   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_007
@ 030   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 031   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 032   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 033   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_007
@ 034   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 035   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_008
@ 036   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_018
@ 037   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_019
@ 038   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_019
@ 039   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_021
@ 040   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_022
@ 041   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_023
@ 042   ----------------------------------------
	.byte	PATT
	 .word	finalbossbreathfire2_8_024
@ 043   ----------------------------------------
	.byte	W09
	.byte	GOTO
	 .word	finalbossbreathfire2_8_B1
finalbossbreathfire2_8_B2:
	.byte	FINE

@******************************************************@
	.align	2

finalbossbreathfire2:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	finalbossbreathfire2_pri	@ Priority
	.byte	finalbossbreathfire2_rev	@ Reverb.

	.word	finalbossbreathfire2_grp

	.word	finalbossbreathfire2_1
	.word	finalbossbreathfire2_2
	.word	finalbossbreathfire2_3
	.word	finalbossbreathfire2_4
	.word	finalbossbreathfire2_5
	.word	finalbossbreathfire2_6
	.word	finalbossbreathfire2_7
	.word	finalbossbreathfire2_8

	.end

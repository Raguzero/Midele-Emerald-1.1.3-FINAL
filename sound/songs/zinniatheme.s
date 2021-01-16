	.include "MPlayDef.s"

	.equ	Zinnia_Theme_grp, voicegroup155
	.equ	Zinnia_Theme_pri, 0
	.equ	Zinnia_Theme_rev, 0
	.equ	Zinnia_Theme_mvl, 85
	.equ	Zinnia_Theme_key, 0
	.equ	Zinnia_Theme_tbs, 1
	.equ	Zinnia_Theme_exg, 0
	.equ	Zinnia_Theme_cmp, 1

	.section .rodata
	.global	Zinnia_Theme
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

Zinnia_Theme_1:
	.byte	KEYSH , Zinnia_Theme_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 185*Zinnia_Theme_tbs/2
	.byte		VOICE , 47
	.byte		PAN   , c_v+40
	.byte		MOD   , 0
	.byte		VOL   , 97*Zinnia_Theme_mvl/mxv
	.byte		BEND  , c_v+0
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
Zinnia_Theme_1_006:
	.byte		N24   , Fs2 , v127
	.byte	W36
	.byte		N24   
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte	PEND
@ 007   ----------------------------------------
Zinnia_Theme_1_007:
	.byte	W12
	.byte		N24   , Fs2 , v127
	.byte	W32
	.byte	W03
	.byte		PAN   , c_v-42
	.byte	W01
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W23
	.byte		PAN   , c_v+45
	.byte	W01
	.byte	PEND
@ 008   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_006
@ 009   ----------------------------------------
Zinnia_Theme_1_009:
	.byte	W12
	.byte		N24   , Fs2 , v127
	.byte	W36
	.byte		PAN   , c_v-42
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W23
	.byte		PAN   , c_v+45
	.byte	W01
	.byte	PEND
@ 010   ----------------------------------------
Zinnia_Theme_1_loop:
	.byte	PATT
	 .word	Zinnia_Theme_1_006
@ 011   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_007
@ 012   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_006
@ 013   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_009
@ 014   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_006
@ 015   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_007
@ 016   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_006
@ 017   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_009
@ 018   ----------------------------------------
Zinnia_Theme_1_018:
	.byte		N24   , Gn2 , v127
	.byte	W36
	.byte		N24   
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte	PEND
@ 019   ----------------------------------------
Zinnia_Theme_1_019:
	.byte	W12
	.byte		N24   , Gn2 , v127
	.byte	W32
	.byte	W03
	.byte		PAN   , c_v-42
	.byte	W01
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W23
	.byte		PAN   , c_v+45
	.byte	W01
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_018
@ 021   ----------------------------------------
Zinnia_Theme_1_021:
	.byte	W12
	.byte		N24   , Gn2 , v127
	.byte	W36
	.byte		PAN   , c_v-42
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W23
	.byte		PAN   , c_v+45
	.byte	W01
	.byte	PEND
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_018
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_019
@ 024   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_018
@ 025   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_021
@ 026   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_018
@ 027   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_019
@ 028   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_018
@ 029   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_021
@ 030   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_018
@ 031   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_019
@ 032   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_018
@ 033   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_021
@ 034   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_018
@ 035   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_019
@ 036   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_018
@ 037   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_021
@ 038   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_018
@ 039   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_019
@ 040   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_018
@ 041   ----------------------------------------
	.byte	W12
	.byte		N24   , Gn2 , v127
	.byte	W36
	.byte		PAN   , c_v-42
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
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
Zinnia_Theme_1_050:
	.byte		PAN   , c_v+45
	.byte		N24   , Dn1 , v127
	.byte	W36
	.byte		N24   
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte	PEND
@ 051   ----------------------------------------
Zinnia_Theme_1_051:
	.byte		PAN   , c_v+45
	.byte	W12
	.byte		N24   , En1 , v127
	.byte	W36
	.byte		PAN   , c_v-42
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte	PEND
@ 052   ----------------------------------------
Zinnia_Theme_1_052:
	.byte		PAN   , c_v+45
	.byte		N24   , Fs1 , v127
	.byte	W36
	.byte		N24   
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte	PEND
@ 053   ----------------------------------------
	.byte		PAN   , c_v+45
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W36
	.byte		PAN   , c_v-42
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
@ 054   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_050
@ 055   ----------------------------------------
Zinnia_Theme_1_055:
	.byte		PAN   , c_v+45
	.byte	W12
	.byte		N24   , Cs1 , v127
	.byte	W36
	.byte		PAN   , c_v-42
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte	PEND
@ 056   ----------------------------------------
	.byte		PAN   , c_v+45
	.byte		N24   , Bn0 
	.byte	W36
	.byte		N24   
	.byte	W36
	.byte		N24   
	.byte	W24
@ 057   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_055
@ 058   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_050
@ 059   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_051
@ 060   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_052
@ 061   ----------------------------------------
Zinnia_Theme_1_061:
	.byte		PAN   , c_v+45
	.byte	W12
	.byte		N24   , Fs1 , v127
	.byte	W36
	.byte		PAN   , c_v-42
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte	PEND
@ 062   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_052
@ 063   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_1_061
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
	.byte		PAN   , c_v-42
	.byte	GOTO
	.word	Zinnia_Theme_1_loop
	.byte	W06
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

Zinnia_Theme_2:
	.byte	KEYSH , Zinnia_Theme_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 60
	.byte		PAN   , c_v-20
	.byte		MOD   , 0
	.byte		VOL   , 127*Zinnia_Theme_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W72
	.byte		N12   , Cs4 , v127
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        En4 
	.byte		N06   , An4 
	.byte	W06
@ 001   ----------------------------------------
	.byte		N96   , Cs4 
	.byte		N96   , Gs4 
	.byte		N96   , Cs5 
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
	.byte	W72
	.byte		N24   , Bn2 , v100
	.byte		N24   , Bn3 
	.byte	W24
@ 010   ----------------------------------------
Zinnia_Theme_2_loop:
	.byte		TIE   , Fs3 
	.byte		TIE   , Fs4 
	.byte	W96
@ 011   ----------------------------------------
	.byte	W06
	.byte		EOT   , Fs3 
	.byte		        Fs4 
	.byte	W06
	.byte		N36   , Gs3 
	.byte		N36   , Gs4 
	.byte	W36
	.byte		N24   , An3 
	.byte		N24   , An4 
	.byte	W24
	.byte		        En4 
	.byte		N24   , En5 
	.byte	W24
@ 012   ----------------------------------------
	.byte		N96   , Cs4 
	.byte		N96   , Cs5 
	.byte	W96
@ 013   ----------------------------------------
	.byte	W12
	.byte		N12   , Bn3 
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Bn3 
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N12   , An3 
	.byte		N12   , An4 
	.byte	W12
	.byte		N06   , Bn3 
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        An3 
	.byte		N06   , An4 
	.byte	W12
	.byte		        Gs3 
	.byte		N06   , Gs4 
	.byte	W12
@ 014   ----------------------------------------
	.byte		N96   , Fs3 
	.byte		N96   , Fs4 
	.byte	W96
@ 015   ----------------------------------------
	.byte	W09
	.byte		N36   , Gs3 
	.byte		N36   , Gs4 
	.byte	W36
	.byte	W03
	.byte		N24   , Fs3 
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        En3 
	.byte		N24   , En4 
	.byte	W24
@ 016   ----------------------------------------
	.byte		TIE   , Cs3 
	.byte		TIE   , Cs4 
	.byte	W96
@ 017   ----------------------------------------
	.byte	W48
	.byte		EOT   , Cs3 
	.byte		        Cs4 
	.byte	W24
	.byte		N24   , Cn3 
	.byte		N24   , Cn4 
	.byte	W24
@ 018   ----------------------------------------
	.byte		TIE   , Gn3 
	.byte		TIE   , Gn4 
	.byte	W96
@ 019   ----------------------------------------
	.byte	W06
	.byte		EOT   , Gn3 
	.byte		        Gn4 
	.byte	W06
	.byte		N36   , An3 
	.byte		N36   , An4 
	.byte	W36
	.byte		N24   , As3 
	.byte		N24   , As4 
	.byte	W24
	.byte		        Fn4 
	.byte		N24   , Fn5 
	.byte	W24
@ 020   ----------------------------------------
	.byte		N96   , Dn4 
	.byte		N96   , Dn5 
	.byte	W96
@ 021   ----------------------------------------
	.byte	W12
	.byte		N12   , Cn4 
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Dn4 
	.byte		N06   , Dn5 
	.byte	W12
	.byte		        Cn4 
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N12   , As3 
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Cn4 
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        As3 
	.byte		N06   , As4 
	.byte	W12
	.byte		        An3 
	.byte		N06   , An4 
	.byte	W12
@ 022   ----------------------------------------
	.byte		N96   , Gn3 
	.byte		N96   , Gn4 
	.byte	W96
@ 023   ----------------------------------------
	.byte	W09
	.byte		N36   , An3 
	.byte		N36   , An4 
	.byte	W36
	.byte	W03
	.byte		N24   , Gn3 
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Fn3 
	.byte		N24   , Fn4 
	.byte	W24
@ 024   ----------------------------------------
	.byte		TIE   , Dn3 
	.byte		TIE   , Dn4 
	.byte	W96
@ 025   ----------------------------------------
	.byte	W48
	.byte		EOT   , Dn3 
	.byte		        Dn4 
	.byte	W48
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
	.byte		N96   , Dn3 
	.byte	W96
@ 043   ----------------------------------------
	.byte		        En3 
	.byte	W96
@ 044   ----------------------------------------
	.byte		        An3 
	.byte	W96
@ 045   ----------------------------------------
	.byte		        Bn3 
	.byte	W96
@ 046   ----------------------------------------
	.byte		N36   , Fs3 
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		N24   , An3 
	.byte	W24
@ 047   ----------------------------------------
	.byte		N36   , En3 
	.byte	W36
	.byte		N60   , Cs3 
	.byte	W60
@ 048   ----------------------------------------
	.byte		N36   , Dn3 
	.byte	W36
	.byte		        En3 
	.byte	W36
	.byte		N24   , Fs3 
	.byte	W24
@ 049   ----------------------------------------
	.byte		N36   , An3 
	.byte	W36
	.byte		N48   , Gs3 
	.byte	W48
	.byte		N06   , En3 , v127
	.byte		N06   , En4 
	.byte		N06   , En5 , v104
	.byte	W06
	.byte		        Fn3 , v127
	.byte		N06   , Fn4 
	.byte		N06   , Fn5 , v104
	.byte	W06
@ 050   ----------------------------------------
	.byte		N72   , Fs3 , v127
	.byte		N72   , Fs4 
	.byte		N72   , Fs5 , v104
	.byte	W72
	.byte		N24   , An3 , v124
	.byte		N24   , An4 
	.byte		N24   , An5 , v104
	.byte	W24
@ 051   ----------------------------------------
	.byte		N36   , Gs3 , v124
	.byte		N36   , Gs4 
	.byte		N36   , Gs5 , v104
	.byte	W36
	.byte		        En3 , v124
	.byte		N36   , En4 
	.byte		N36   , En5 , v104
	.byte	W36
	.byte		N24   , Fs3 , v124
	.byte		N24   , Fs4 
	.byte		N24   , Fs5 
	.byte	W24
@ 052   ----------------------------------------
	.byte		N72   , Cs3 
	.byte		N72   , Cs4 
	.byte		N72   , Cs5 , v100
	.byte	W72
	.byte		N24   , Bn2 , v124
	.byte		N24   , Bn3 
	.byte		N24   , Bn4 , v100
	.byte	W24
@ 053   ----------------------------------------
	.byte		N48   , Cs3 , v124
	.byte		N48   , Cs4 
	.byte		N48   , Cs5 , v100
	.byte	W48
	.byte		N36   , Bn2 , v124
	.byte		N36   , Bn3 
	.byte		N36   , Bn4 , v100
	.byte	W36
	.byte		N06   , Cs3 , v124
	.byte		N06   , Cs4 
	.byte		N06   , Cs5 , v100
	.byte	W06
	.byte		        Bn2 , v124
	.byte		N06   , Bn3 
	.byte		N06   , Bn4 , v100
	.byte	W06
@ 054   ----------------------------------------
	.byte		N72   , Fs2 , v124
	.byte		N72   , Fs3 
	.byte		N72   , Fs4 , v104
	.byte	W72
	.byte		N24   , Cs3 , v124
	.byte		N24   , Cs4 
	.byte		N24   , Cs5 , v100
	.byte	W24
@ 055   ----------------------------------------
	.byte		N36   , Bn2 , v124
	.byte		N36   , Bn3 
	.byte		N36   , Bn4 , v100
	.byte	W36
	.byte		        An2 , v124
	.byte		N36   , An3 
	.byte		N36   , An4 , v096
	.byte	W36
	.byte		N24   , Gs2 , v124
	.byte		N24   , Gs3 
	.byte		N24   , Gs4 , v096
	.byte	W24
@ 056   ----------------------------------------
	.byte		N72   , Fs2 , v124
	.byte		N72   , Fs3 
	.byte		N72   , Fs4 , v096
	.byte	W72
	.byte		N24   , Cs3 , v124
	.byte		N24   , Cs4 
	.byte		N24   , Cs5 , v100
	.byte	W24
@ 057   ----------------------------------------
	.byte		        Bn2 , v124
	.byte		N24   , Bn3 
	.byte		N24   , Bn4 , v100
	.byte	W24
	.byte		        Cs3 , v124
	.byte		N24   , Cs4 
	.byte		N24   , Cs5 , v096
	.byte	W24
	.byte		        Dn3 , v124
	.byte		N24   , Dn4 
	.byte		N24   , Dn5 , v096
	.byte	W24
	.byte		        En3 , v124
	.byte		N24   , En4 
	.byte		N24   , En5 , v096
	.byte	W24
@ 058   ----------------------------------------
	.byte		N72   , Fs3 , v124
	.byte		N72   , Fs4 
	.byte		N72   , Fs5 , v096
	.byte	W72
	.byte		N24   , An3 , v124
	.byte		N24   , An4 
	.byte		N24   , An5 , v096
	.byte	W24
@ 059   ----------------------------------------
	.byte		        Gs3 , v124
	.byte		N24   , Gs4 
	.byte		N24   , Gs5 , v096
	.byte	W24
	.byte		        En3 , v124
	.byte		N24   , En4 
	.byte		N24   , En5 , v096
	.byte	W24
	.byte		        Cs3 , v124
	.byte		N24   , Cs4 
	.byte		N24   , Cs5 , v092
	.byte	W24
	.byte		        Gs3 , v124
	.byte		N24   , Gs4 
	.byte		N24   , Gs5 , v092
	.byte	W24
@ 060   ----------------------------------------
	.byte		TIE   , Fs3 , v124
	.byte		TIE   , Fs4 
	.byte		TIE   , Fs5 , v092
	.byte	W96
@ 061   ----------------------------------------
	.byte	W96
	.byte		EOT   , Fs3 
	.byte		        Fs4 
	.byte		        Fs5 
@ 062   ----------------------------------------
	.byte		N09   , Fs3 , v088
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        An3 
	.byte		N09   , An4 
	.byte	W12
	.byte		        Bn3 
	.byte		N09   , Bn4 
	.byte	W12
	.byte		        An3 
	.byte		N09   , An4 
	.byte	W12
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N09   , An3 
	.byte		N09   , An4 
	.byte	W12
	.byte		        Fs3 
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        En3 
	.byte		N09   , En4 
	.byte	W12
@ 063   ----------------------------------------
	.byte		        Fs3 
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        An3 
	.byte		N09   , An4 
	.byte	W12
	.byte		        Gs3 , v084
	.byte		N09   , Gs4 
	.byte	W12
	.byte		        En3 
	.byte		N09   , En4 
	.byte	W12
	.byte		        Fs3 
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        En3 
	.byte		N09   , En4 
	.byte	W12
	.byte		N21   , Cs3 
	.byte		N21   , Cs4 
	.byte	W24
@ 064   ----------------------------------------
	.byte	W12
	.byte		N09   , Cs3 
	.byte		N09   , Cs4 
	.byte	W12
	.byte		        Fs3 
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        Gn3 
	.byte		N09   , Gn4 
	.byte	W12
	.byte		N21   , An3 
	.byte		N21   , An4 
	.byte	W36
	.byte		N09   , Fs3 
	.byte		N09   , Fs4 
	.byte	W12
@ 065   ----------------------------------------
	.byte		        En3 
	.byte		N09   , En4 
	.byte	W12
	.byte		        Gn3 
	.byte		N09   , Gn4 
	.byte	W12
	.byte		        Fs3 
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        En3 
	.byte		N09   , En4 
	.byte	W12
	.byte		        Fs3 
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        Fs3 
	.byte		N09   , Fs4 
	.byte	W12
	.byte		N18   , En3 
	.byte		N18   , En4 
	.byte	W24
@ 066   ----------------------------------------
	.byte	W12
	.byte		N09   , Cs3 
	.byte		N09   , Cs4 
	.byte	W12
	.byte		        Fs3 , v080
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        Gn3 
	.byte		N09   , Gn4 
	.byte	W12
	.byte		N21   , An3 
	.byte		N21   , An4 
	.byte	W36
	.byte		N09   , Fs3 
	.byte		N09   , Fs4 
	.byte	W12
@ 067   ----------------------------------------
	.byte		        En3 
	.byte		N09   , En4 
	.byte	W12
	.byte		        Gn3 
	.byte		N09   , Gn4 
	.byte	W12
	.byte		        Fs3 
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        En3 
	.byte		N09   , En4 
	.byte	W12
	.byte		        Fs3 
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        Bn3 
	.byte		N09   , Bn4 
	.byte	W12
	.byte		N21   , En3 
	.byte		N21   , En4 
	.byte	W24
@ 068   ----------------------------------------
	.byte	W12
	.byte		N09   , Cs3 
	.byte		N09   , Cs4 
	.byte	W12
	.byte		        Fs3 
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        Gn3 
	.byte		N09   , Gn4 
	.byte	W12
	.byte		N24   , An3 
	.byte		N24   , An4 
	.byte	W36
	.byte		N09   , Fs3 
	.byte		N09   , Fs4 
	.byte	W12
@ 069   ----------------------------------------
	.byte		        Fs3 
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        An3 
	.byte		N09   , An4 
	.byte	W12
	.byte		        Gs3 
	.byte		N09   , Gs4 
	.byte	W12
	.byte		        En3 , v076
	.byte		N09   , En4 
	.byte	W12
	.byte		        Fs3 
	.byte		N09   , Fs4 
	.byte	W12
	.byte		        En3 
	.byte		N09   , En4 
	.byte	W12
	.byte		N24   , Bn2 , v100
	.byte		N24   , Bn3 
	.byte	W24
@ 070   ----------------------------------------
	.byte	GOTO
	.word	Zinnia_Theme_2_loop
	.byte	W06
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

Zinnia_Theme_3:
	.byte	KEYSH , Zinnia_Theme_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 60
	.byte		PAN   , c_v+39
	.byte		MOD   , 0
	.byte		VOL   , 127*Zinnia_Theme_mvl/mxv
	.byte		BEND  , c_v+0
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
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
Zinnia_Theme_3_loop:
	.byte	W06
	.byte		        c_v+0
	.byte		TIE   , Fs4 , v064
	.byte	W90
@ 011   ----------------------------------------
	.byte	W12
	.byte		EOT   
	.byte	W06
	.byte		N36   , Gs4 , v068
	.byte	W36
	.byte		N24   , An4 
	.byte	W24
	.byte		        En5 
	.byte	W18
@ 012   ----------------------------------------
	.byte	W06
	.byte		N96   , Cs5 
	.byte	W90
@ 013   ----------------------------------------
	.byte	W18
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N12   , An4 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
@ 014   ----------------------------------------
	.byte	W06
	.byte		N96   , Fs4 
	.byte	W90
@ 015   ----------------------------------------
	.byte	W15
	.byte		N36   , Gs4 
	.byte	W36
	.byte	W03
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        En4 
	.byte	W18
@ 016   ----------------------------------------
	.byte	W06
	.byte		TIE   , Cs4 
	.byte	W90
@ 017   ----------------------------------------
	.byte	W54
	.byte		EOT   
	.byte	W24
	.byte		N24   , Cn4 , v072
	.byte	W18
@ 018   ----------------------------------------
	.byte	W06
	.byte		TIE   , Gn4 
	.byte	W90
@ 019   ----------------------------------------
	.byte	W12
	.byte		EOT   
	.byte	W06
	.byte		N36   , An4 
	.byte	W36
	.byte		N24   , As4 
	.byte	W24
	.byte		        Fn5 
	.byte	W18
@ 020   ----------------------------------------
	.byte	W06
	.byte		N96   , Dn5 
	.byte	W90
@ 021   ----------------------------------------
	.byte	W18
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W06
@ 022   ----------------------------------------
	.byte	W06
	.byte		N96   , Gn4 
	.byte	W90
@ 023   ----------------------------------------
	.byte	W15
	.byte		N36   , An4 , v076
	.byte	W36
	.byte	W03
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Fn4 
	.byte	W18
@ 024   ----------------------------------------
	.byte	W06
	.byte		TIE   , Dn4 
	.byte	W90
@ 025   ----------------------------------------
	.byte	W54
	.byte		EOT   
	.byte	W42
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
Zinnia_Theme_3_050:
	.byte	W06
	.byte		N72   , Fs5 , v072
	.byte	W72
	.byte		N24   , An5 
	.byte	W18
	.byte	PEND
@ 051   ----------------------------------------
	.byte	W06
	.byte		N36   , Gs5 
	.byte	W36
	.byte		        En5 
	.byte	W36
	.byte		N24   , Fs5 
	.byte	W18
@ 052   ----------------------------------------
	.byte	W06
	.byte		N72   , Cs5 
	.byte	W72
	.byte		N24   , Bn4 
	.byte	W18
@ 053   ----------------------------------------
	.byte	W06
	.byte		N48   , Cs5 
	.byte	W48
	.byte		N36   , Bn4 
	.byte	W36
	.byte		N06   , Cs5 
	.byte	W06
@ 054   ----------------------------------------
	.byte		        Bn4 
	.byte	W06
	.byte		N72   , Fs4 
	.byte	W72
	.byte		N24   , Cs5 
	.byte	W18
@ 055   ----------------------------------------
	.byte	W06
	.byte		N36   , Bn4 
	.byte	W36
	.byte		        An4 
	.byte	W36
	.byte		N24   , Gs4 
	.byte	W18
@ 056   ----------------------------------------
	.byte	W06
	.byte		N72   , Fs4 
	.byte	W72
	.byte		N24   , Cs5 
	.byte	W18
@ 057   ----------------------------------------
	.byte	W06
	.byte		        Bn4 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		        En5 
	.byte	W18
@ 058   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_3_050
@ 059   ----------------------------------------
	.byte	W06
	.byte		N24   , Gs5 , v072
	.byte	W24
	.byte		        En5 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		        Gs5 
	.byte	W18
@ 060   ----------------------------------------
	.byte	W06
	.byte		TIE   , Fs5 
	.byte	W90
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W06
	.byte		EOT   
	.byte		N09   , Fs4 , v044
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N09   , An4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W06
@ 063   ----------------------------------------
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 , v048
	.byte	W12
	.byte		N21   , Cs4 
	.byte	W18
@ 064   ----------------------------------------
	.byte	W18
	.byte		N09   
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W06
@ 065   ----------------------------------------
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N18   , En4 
	.byte	W18
@ 066   ----------------------------------------
	.byte	W18
	.byte		N09   , Cs4 , v052
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W06
@ 067   ----------------------------------------
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N21   , En4 
	.byte	W18
@ 068   ----------------------------------------
	.byte	W18
	.byte		N09   , Cs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N15   , An4 
	.byte	W12
	.byte		N09   , Gn4 , v056
	.byte	W24
	.byte		        Fs4 
	.byte	W06
@ 069   ----------------------------------------
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte	W18
@ 070   ----------------------------------------
	.byte	GOTO
	.word	Zinnia_Theme_3_loop
	.byte	W06
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

Zinnia_Theme_4:
	.byte	KEYSH , Zinnia_Theme_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 56
	.byte		PAN   , c_v-26
	.byte		MOD   , 0
	.byte		VOL   , 110*Zinnia_Theme_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte		N96   , An2 , v100
	.byte		N96   , Cs3 
	.byte		N96   , Fs3 
	.byte	W96
@ 003   ----------------------------------------
	.byte		N84   , Cs3 
	.byte		N84   , En3 
	.byte		N84   , Gs3 
	.byte	W84
	.byte		N06   , Bn2 
	.byte		N06   , Dn3 
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Cs3 
	.byte		N06   , En3 
	.byte		N06   , Gs3 
	.byte	W06
@ 004   ----------------------------------------
	.byte		N84   , Dn3 
	.byte		N84   , Fs3 
	.byte		N84   , An3 
	.byte	W84
	.byte		N06   , Cs3 
	.byte		N06   , En3 
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Ds3 
	.byte		N06   , Fs3 
	.byte		N06   , An3 
	.byte	W06
@ 005   ----------------------------------------
	.byte		N96   , En3 
	.byte		N96   , Gs3 
	.byte		N96   , Bn3 
	.byte	W96
@ 006   ----------------------------------------
	.byte		N72   , Fs3 
	.byte		N72   , An3 
	.byte		N72   , Cs4 
	.byte	W72
	.byte		N24   , An3 
	.byte		N24   , Cs4 
	.byte		N24   , En4 
	.byte	W24
@ 007   ----------------------------------------
	.byte		N72   , Fs3 
	.byte		N72   , An3 
	.byte		N72   , Cs4 
	.byte	W72
	.byte		N24   , Gs3 
	.byte		N24   , Cs4 
	.byte		N24   , En4 
	.byte		N24   , Gs4 
	.byte	W24
@ 008   ----------------------------------------
	.byte		N84   , An3 
	.byte		N84   , Dn4 
	.byte		N84   , Fs4 
	.byte		N84   , An4 
	.byte	W84
	.byte		N06   , Gs3 
	.byte		N06   , Cs4 
	.byte		N06   , En4 
	.byte	W06
	.byte		        As3 
	.byte		N06   , Dn4 
	.byte		N06   , Fs4 
	.byte	W06
@ 009   ----------------------------------------
	.byte		N48   , Bn3 , v104
	.byte		N48   , En4 , v100
	.byte		N48   , Bn4 
	.byte	W48
	.byte		        Cs4 , v104
	.byte		N48   , Fs4 , v100
	.byte		N48   , Cs5 
	.byte	W48
@ 010   ----------------------------------------
Zinnia_Theme_4_loop:
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
	.byte	W90
	.byte		PAN   , c_v+23
	.byte	W06
@ 018   ----------------------------------------
	.byte		N96   , Dn3 , v068
	.byte		N96   , Dn4 , v096
	.byte	W96
@ 019   ----------------------------------------
	.byte		N48   , Cn3 , v068
	.byte		N48   , Cn4 , v096
	.byte	W48
	.byte		N32   , Fn3 , v068
	.byte		N32   , Fn4 , v096
	.byte	W36
	.byte		N06   , En3 , v068
	.byte		N06   , En4 , v096
	.byte	W06
	.byte		        Ds3 , v068
	.byte		N06   , Ds4 , v096
	.byte	W06
@ 020   ----------------------------------------
	.byte		N72   , Dn3 , v068
	.byte		N72   , Dn4 , v096
	.byte	W84
	.byte		N06   , Gn3 , v068
	.byte		N06   , Gn4 , v108
	.byte	W06
	.byte		        An3 , v068
	.byte		N06   , An4 , v108
	.byte	W06
@ 021   ----------------------------------------
	.byte		N36   , As3 , v068
	.byte		N36   , As4 , v108
	.byte	W36
	.byte		        An3 , v068
	.byte		N36   , An4 , v104
	.byte	W36
	.byte		N24   , Fn3 , v068
	.byte		N24   , Fn4 , v104
	.byte	W24
@ 022   ----------------------------------------
	.byte		N84   , Gn3 , v068
	.byte		N84   , Gn4 , v096
	.byte	W84
	.byte		N06   , Fs3 , v064
	.byte		N06   , Fs4 , v092
	.byte	W06
	.byte		        Dn3 , v064
	.byte		N06   , Dn4 , v092
	.byte	W06
@ 023   ----------------------------------------
	.byte		N48   , Cn3 , v064
	.byte		N48   , Cn4 , v092
	.byte	W48
	.byte		        Fn3 , v064
	.byte		N48   , Fn4 , v092
	.byte	W48
@ 024   ----------------------------------------
	.byte		TIE   , Dn3 , v064
	.byte		TIE   , Dn4 , v092
	.byte	W21
	.byte	W28
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W03
	.byte	W01
@ 025   ----------------------------------------
	.byte	W01
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W02
	.byte	W03
	.byte	W02
	.byte	W02
	.byte	W02
	.byte		EOT   , Dn3 
	.byte		        Dn4 
	.byte	W03
	.byte	W19
	.byte		PAN   , c_v-38
	.byte	W14
	.byte		N06   , Gn3 , v100
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        An3 , v096
	.byte		N06   , An4 , v100
	.byte	W06
@ 026   ----------------------------------------
	.byte		N96   , Gn3 , v064
	.byte		N96   , As3 , v096
	.byte		N96   , As4 , v100
	.byte	W96
@ 027   ----------------------------------------
	.byte		N48   , Fs3 , v064
	.byte		N48   , An3 , v100
	.byte		N48   , An4 
	.byte	W48
	.byte		        An3 , v064
	.byte		N48   , Cn4 , v100
	.byte		N48   , Cn5 
	.byte	W48
@ 028   ----------------------------------------
	.byte		        Gs3 , v060
	.byte		N48   , Bn3 , v100
	.byte		N48   , Bn4 
	.byte	W48
	.byte		        En3 , v064
	.byte		N48   , Gn3 , v100
	.byte		N48   , En4 
	.byte	W48
@ 029   ----------------------------------------
	.byte		        Ds3 
	.byte		N48   , Fs3 , v064
	.byte		N48   , Ds4 , v100
	.byte	W48
	.byte		        Gs3 , v064
	.byte		N48   , Bn3 , v100
	.byte		N48   , Gs4 
	.byte	W48
@ 030   ----------------------------------------
	.byte		N84   , Gn3 , v060
	.byte		N96   , As3 , v100
	.byte		N84   , Gn4 
	.byte	W84
	.byte		N06   , Fn3 
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Ds3 
	.byte		N06   , Ds4 
	.byte	W06
@ 031   ----------------------------------------
	.byte		N48   , Dn3 
	.byte		N48   , Gn3 , v064
	.byte		N48   , Dn4 , v100
	.byte	W48
	.byte		        Fn3 
	.byte		N48   , As3 , v064
	.byte		N48   , Fn4 , v100
	.byte	W48
@ 032   ----------------------------------------
	.byte		TIE   , Dn3 
	.byte		TIE   , Gn3 , v064
	.byte		TIE   , Dn4 , v100
	.byte	W96
@ 033   ----------------------------------------
	.byte	W44
	.byte	W01
	.byte		EOT   , Dn3 
	.byte	W03
	.byte		        Gn3 
	.byte		        Dn4 
	.byte	W48
@ 034   ----------------------------------------
	.byte		N96   , As3 
	.byte		N96   , As4 
	.byte	W96
@ 035   ----------------------------------------
	.byte		N48   , An3 
	.byte		N48   , An4 
	.byte	W48
	.byte		N24   , As3 
	.byte		N24   , As4 
	.byte	W24
	.byte		        Cn4 
	.byte		N24   , Cn5 
	.byte	W24
@ 036   ----------------------------------------
	.byte		N06   , An3 
	.byte		N06   , An4 
	.byte	W06
	.byte		N78   , As3 
	.byte		N78   , As4 
	.byte	W78
	.byte		N06   , An3 
	.byte		N06   , An4 
	.byte	W06
	.byte		        Gn3 
	.byte		N06   , Gn4 
	.byte	W06
@ 037   ----------------------------------------
	.byte		N80   , Ds3 
	.byte		N80   , Ds4 
	.byte	W90
	.byte		N06   , Dn3 
	.byte		N06   , Dn4 
	.byte	W06
@ 038   ----------------------------------------
	.byte		N96   , Ds3 
	.byte		N96   , Ds4 
	.byte	W96
@ 039   ----------------------------------------
	.byte		N08   , Cn3 
	.byte		N08   , Cn4 
	.byte	W08
	.byte		        Gn2 
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Cn3 
	.byte		N08   , Cn4 
	.byte	W08
	.byte		        Dn3 
	.byte		N08   , Dn4 
	.byte	W08
	.byte		        Gn2 
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Dn3 
	.byte		N08   , Dn4 
	.byte	W08
	.byte		        Ds3 
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Gn2 
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Ds3 
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Ds3 
	.byte		N08   , Ds4 
	.byte	W08
	.byte		        Fn3 
	.byte		N08   , Fn4 
	.byte	W08
	.byte		        Gn3 
	.byte		N08   , Gn4 
	.byte	W08
@ 040   ----------------------------------------
	.byte		N84   , As3 
	.byte		N84   , As4 
	.byte	W84
	.byte		N06   , Cn4 
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        As3 
	.byte		N06   , As4 
	.byte	W06
@ 041   ----------------------------------------
	.byte		N96   , An3 
	.byte		N96   , An4 
	.byte	W96
@ 042   ----------------------------------------
	.byte		N72   , Fs3 
	.byte		N72   , Fs4 
	.byte	W72
	.byte		N08   , Fs3 
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        Cs3 
	.byte		N08   , Cs4 
	.byte	W08
	.byte		        Fs3 
	.byte		N08   , Fs4 
	.byte	W08
@ 043   ----------------------------------------
	.byte		        Gs3 , v104
	.byte		N08   , Gs4 
	.byte	W08
	.byte		        Cs3 
	.byte		N08   , Cs4 
	.byte	W08
	.byte		        Gs3 
	.byte		N08   , Gs4 
	.byte	W08
	.byte		        An3 
	.byte		N08   , An4 
	.byte	W08
	.byte		        Cs3 
	.byte		N08   , Cs4 
	.byte	W08
	.byte		        An3 
	.byte		N08   , An4 
	.byte	W08
	.byte		        Bn3 
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        Cs3 
	.byte		N08   , Cs4 
	.byte	W08
	.byte		        Bn3 
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        En4 
	.byte		N08   , En5 
	.byte	W08
	.byte		        En3 
	.byte		N08   , En4 
	.byte	W08
	.byte		        Ds3 
	.byte		N08   , Ds4 
	.byte	W08
@ 044   ----------------------------------------
	.byte		N84   , En3 
	.byte		N84   , En4 
	.byte	W84
	.byte		N06   , Dn3 
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cs3 
	.byte		N06   , Cs4 
	.byte	W06
@ 045   ----------------------------------------
	.byte		N48   , Dn3 
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        En3 
	.byte		N48   , En4 
	.byte	W48
@ 046   ----------------------------------------
	.byte		N96   , Fs3 , v100
	.byte		N96   , Dn4 , v104
	.byte		N96   , Fs4 
	.byte	W96
@ 047   ----------------------------------------
	.byte		        En3 , v100
	.byte		N96   , Cs4 , v108
	.byte		N96   , En4 
	.byte	W96
@ 048   ----------------------------------------
	.byte		N44   , Dn3 , v100
	.byte		N48   , Bn3 , v108
	.byte		N48   , Dn4 
	.byte	W48
	.byte		N08   , Bn3 , v112
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        Dn3 
	.byte		N08   , Dn4 
	.byte	W08
	.byte		        Fs3 
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        Bn3 
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        Dn3 
	.byte		N08   , Dn4 
	.byte	W08
	.byte		        Fs3 
	.byte		N08   , Fs4 
	.byte	W08
@ 049   ----------------------------------------
	.byte		N96   , Cs3 , v100
	.byte		N96   , Gs3 , v112
	.byte		N96   , Cs4 
	.byte	W96
@ 050   ----------------------------------------
	.byte		N72   , Fs3 , v072
	.byte		N72   , Cs4 
	.byte	W72
	.byte		N24   , An3 
	.byte		N24   , En4 
	.byte	W24
@ 051   ----------------------------------------
	.byte		N36   , Gs3 
	.byte		N36   , Ds4 
	.byte	W36
	.byte		        En3 
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N24   , Fs3 
	.byte		N24   , Gs3 
	.byte	W24
@ 052   ----------------------------------------
	.byte		N72   , Fs3 
	.byte		N72   , An3 
	.byte	W72
	.byte		N24   , En3 
	.byte		N24   , Fs3 
	.byte	W24
@ 053   ----------------------------------------
	.byte		N48   , En3 
	.byte		N48   , Gn3 
	.byte	W48
	.byte		        En3 
	.byte		N48   , Gn3 
	.byte	W48
@ 054   ----------------------------------------
	.byte		N72   , An3 
	.byte		N72   , Dn4 
	.byte	W72
	.byte		N24   , Cs4 
	.byte		N24   , Fs4 
	.byte	W24
@ 055   ----------------------------------------
	.byte		N36   , Bn3 
	.byte		N36   , En4 
	.byte	W36
	.byte		        An3 
	.byte		N36   , Dn4 
	.byte	W36
	.byte		N24   , Gs3 
	.byte		N24   , Cs4 
	.byte	W24
@ 056   ----------------------------------------
	.byte		N96   , Fs3 
	.byte		N96   , Bn3 
	.byte	W96
@ 057   ----------------------------------------
	.byte		N24   , Bn2 , v068
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        Cs3 
	.byte		N24   , An3 
	.byte	W24
	.byte		        Dn3 
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        En3 
	.byte		N24   , Gs3 
	.byte	W24
@ 058   ----------------------------------------
	.byte		N96   , Fs3 
	.byte		N96   , Dn4 
	.byte	W96
@ 059   ----------------------------------------
	.byte		        Gs3 
	.byte		N96   , En4 
	.byte	W96
@ 060   ----------------------------------------
	.byte		        Fs3 
	.byte		N96   , Bn3 
	.byte	W96
@ 061   ----------------------------------------
	.byte		        Fs3 
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
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
	.byte		PAN   , c_v-38
	.byte	GOTO
	.word	Zinnia_Theme_4_loop
	.byte	W06
	.byte	FINE

@**************** Track 5 (Midi-Chn.5) ****************@

Zinnia_Theme_5:
	.byte	KEYSH , Zinnia_Theme_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 56
	.byte		PAN   , c_v+33
	.byte		MOD   , 0
	.byte		VOL   , 110*Zinnia_Theme_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W06
	.byte		N96   , Fs3 , v072
	.byte	W90
@ 003   ----------------------------------------
	.byte	W06
	.byte		N84   , Gs3 
	.byte	W84
	.byte		N06   , Fs3 
	.byte	W06
@ 004   ----------------------------------------
	.byte		        Gs3 
	.byte	W06
	.byte		N84   , An3 
	.byte	W84
	.byte		N06   , Gs3 
	.byte	W06
@ 005   ----------------------------------------
	.byte		        An3 
	.byte	W06
	.byte		N96   , Bn3 
	.byte	W90
@ 006   ----------------------------------------
	.byte	W06
	.byte		N72   , Cs4 
	.byte	W72
	.byte		N24   , En4 
	.byte	W18
@ 007   ----------------------------------------
	.byte	W06
	.byte		N72   , Cs4 
	.byte	W72
	.byte		N24   , Gs4 , v068
	.byte	W18
@ 008   ----------------------------------------
	.byte	W06
	.byte		N84   , An4 
	.byte	W84
	.byte		N06   , Gs4 
	.byte	W06
@ 009   ----------------------------------------
	.byte		        As4 
	.byte	W06
	.byte		N48   , Bn4 
	.byte	W48
	.byte		        Cs5 
	.byte	W42
@ 010   ----------------------------------------
Zinnia_Theme_5_loop:
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
	.byte	W06
	.byte		N96   , As4 , v120
	.byte	W90
@ 027   ----------------------------------------
	.byte	W06
	.byte		N48   , An4 
	.byte	W48
	.byte		        Cn5 
	.byte	W42
@ 028   ----------------------------------------
	.byte	W06
	.byte		        Bn4 
	.byte	W48
	.byte		        En4 
	.byte	W42
@ 029   ----------------------------------------
	.byte	W06
	.byte		        Ds4 
	.byte	W48
	.byte		        Gs4 
	.byte	W42
@ 030   ----------------------------------------
	.byte	W06
	.byte		N84   , Gn4 
	.byte	W84
	.byte		N06   , Fn4 
	.byte	W06
@ 031   ----------------------------------------
	.byte		        Ds4 
	.byte	W06
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        Fn4 
	.byte	W42
@ 032   ----------------------------------------
	.byte	W06
	.byte		TIE   , Dn4 
	.byte	W90
@ 033   ----------------------------------------
	.byte	W54
	.byte		EOT   
	.byte	W42
@ 034   ----------------------------------------
	.byte	W06
	.byte		N96   , As4 , v112
	.byte	W90
@ 035   ----------------------------------------
	.byte	W06
	.byte		N48   , An4 
	.byte	W48
	.byte		N24   , As4 
	.byte	W24
	.byte		        Cn5 
	.byte	W18
@ 036   ----------------------------------------
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		N78   , As4 
	.byte	W78
	.byte		N06   , An4 
	.byte	W06
@ 037   ----------------------------------------
	.byte		        Gn4 
	.byte	W06
	.byte		N80   , Ds4 
	.byte	W90
@ 038   ----------------------------------------
	.byte	W06
	.byte		N96   
	.byte	W90
@ 039   ----------------------------------------
	.byte	W06
	.byte		N08   , Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W02
@ 040   ----------------------------------------
	.byte	W06
	.byte		N84   , As4 
	.byte	W84
	.byte		N06   , Cn5 
	.byte	W06
@ 041   ----------------------------------------
	.byte		        As4 
	.byte	W06
	.byte		N96   , An4 
	.byte	W90
@ 042   ----------------------------------------
	.byte	W06
	.byte		N72   , Fs4 , v096
	.byte	W72
	.byte		N08   
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W02
@ 043   ----------------------------------------
	.byte	W06
	.byte		        Gs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W02
@ 044   ----------------------------------------
	.byte	W06
	.byte		N84   , En4 
	.byte	W84
	.byte		N06   , Dn4 
	.byte	W06
@ 045   ----------------------------------------
	.byte		        Cs4 
	.byte	W06
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        En4 
	.byte	W42
@ 046   ----------------------------------------
	.byte	W06
	.byte		N96   , Fs4 
	.byte	W90
@ 047   ----------------------------------------
	.byte	W06
	.byte		        En4 
	.byte	W90
@ 048   ----------------------------------------
	.byte	W06
	.byte		N48   , Dn4 
	.byte	W48
	.byte		N08   , Bn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W02
@ 049   ----------------------------------------
	.byte	W06
	.byte		N96   , Cs4 
	.byte	W90
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
	.byte	GOTO
	.word	Zinnia_Theme_5_loop
	.byte	W06
	.byte	FINE

@**************** Track 6 (Midi-Chn.6) ****************@

Zinnia_Theme_6:
	.byte	KEYSH , Zinnia_Theme_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 48
	.byte		PAN   , c_v-40
	.byte		VOL   , 110*Zinnia_Theme_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N06   , Cs4 , v127
	.byte		N06   , Fn4 
	.byte		N06   , Gs4 
	.byte		N06   , Cs5 
	.byte		N06   , Fn5 
	.byte		N06   , Gs5 
	.byte	W06
	.byte		        Bn4 
	.byte		N06   , Bn5 
	.byte	W06
	.byte		        An4 
	.byte		N06   , An5 
	.byte	W06
	.byte		        Gs4 
	.byte		N06   , Gs5 
	.byte	W06
	.byte		        Fs4 
	.byte		N06   , Fs5 
	.byte	W06
	.byte		        An4 
	.byte		N06   , An5 
	.byte	W06
	.byte		N12   , Bn2 
	.byte		N06   , Gs4 
	.byte		N06   , Gs5 
	.byte	W06
	.byte		        Fs4 
	.byte		N06   , Fs5 
	.byte	W06
	.byte		N12   , An2 
	.byte		N06   , En4 
	.byte		N06   , En5 
	.byte	W06
	.byte		        Gs4 
	.byte		N06   , Gs5 
	.byte	W06
	.byte		N12   , Gs2 
	.byte		N06   , Fs4 
	.byte		N06   , Fs5 
	.byte	W06
	.byte		        En4 
	.byte		N06   , En5 
	.byte	W06
	.byte		N12   , Gn2 
	.byte		N06   , Dn4 
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Fs4 
	.byte		N06   , Fs5 
	.byte	W06
	.byte		N12   , Fs2 
	.byte		N06   , En4 
	.byte		N06   , En5 
	.byte	W06
	.byte		        Dn4 
	.byte		N06   , Dn5 
	.byte	W06
@ 001   ----------------------------------------
	.byte		N48   , Dn2 
	.byte		N06   , Cs4 
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        En4 
	.byte		N06   , En5 
	.byte	W06
	.byte		        Dn4 
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Cs4 
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Bn3 
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Dn4 
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Cs4 
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Bn3 
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N48   , En2 
	.byte		N06   , An3 
	.byte		N06   , An4 
	.byte	W06
	.byte		        Cs4 
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Bn3 
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        An3 
	.byte		N06   , An4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Bn3 
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        An3 
	.byte		N06   , An4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Gs4 
	.byte	W06
@ 002   ----------------------------------------
	.byte		TIE   , Fs2 
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
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 010   ----------------------------------------
Zinnia_Theme_6_loop:
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
	.byte		N12   , An2 , v064
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W01
	.byte		PAN   , c_v-7
	.byte	W32
	.byte	W03
	.byte		N12   , An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W36
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W24
@ 065   ----------------------------------------
	.byte	W12
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W36
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W24
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W24
@ 066   ----------------------------------------
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W36
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W36
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W24
@ 067   ----------------------------------------
	.byte	W12
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W36
	.byte		        An2 , v060
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W24
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W24
@ 068   ----------------------------------------
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W36
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W36
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W24
@ 069   ----------------------------------------
	.byte	W12
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W36
	.byte		        An2 
	.byte		N12   , En3 
	.byte		N12   , An3 
	.byte	W24
	.byte		        Bn2 
	.byte		N12   , Fs3 
	.byte		N12   , Bn3 
	.byte	W24
@ 070   ----------------------------------------
	.byte		PAN   , c_v-7
	.byte	GOTO
	.word	Zinnia_Theme_6_loop
	.byte	W06
	.byte	FINE

@**************** Track 7 (Midi-Chn.7) ****************@

Zinnia_Theme_7:
	.byte	KEYSH , Zinnia_Theme_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 80
	.byte		PAN   , c_v+19
	.byte		VOL   , 110*Zinnia_Theme_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte		N12   , An2 , v068
	.byte		N12   , Cs3 
	.byte		N12   , Cs4 , v048
	.byte	W12
	.byte		        Cs3 , v068
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v048
	.byte	W12
	.byte		        Fs3 , v068
	.byte		N12   , An3 
	.byte		N12   , An4 , v048
	.byte	W12
	.byte		        En3 , v068
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v048
	.byte	W12
	.byte		        Dn3 , v068
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v048
	.byte	W12
	.byte		        En3 , v068
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v048
	.byte	W12
	.byte		        Dn3 , v068
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v048
	.byte	W12
	.byte		        Cs3 , v068
	.byte		N12   , En3 
	.byte		N12   , En4 , v048
	.byte	W12
@ 003   ----------------------------------------
	.byte		        An2 , v068
	.byte		N12   , Cs3 
	.byte		N12   , Cs4 , v048
	.byte	W12
	.byte		        Cs3 , v068
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v048
	.byte	W12
	.byte		        En3 , v068
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v048
	.byte	W12
	.byte		        Gs3 , v068
	.byte		N12   , Cs4 
	.byte		N12   , Cs5 , v048
	.byte	W12
	.byte		N06   , Fs3 , v068
	.byte		N06   , Bn3 
	.byte		N06   , Bn4 , v048
	.byte	W06
	.byte		        En3 , v068
	.byte		N06   , An3 
	.byte		N06   , An4 , v048
	.byte	W06
	.byte		N12   , En3 , v068
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v048
	.byte	W12
	.byte		        Dn3 , v068
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v048
	.byte	W12
	.byte		        Cs3 , v068
	.byte		N12   , En3 
	.byte		N12   , En4 , v044
	.byte	W12
@ 004   ----------------------------------------
	.byte		        An2 , v068
	.byte		N12   , Cs3 
	.byte		N12   , Cs4 , v044
	.byte	W12
	.byte		        Cs3 , v068
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        Fs3 , v068
	.byte		N12   , An3 
	.byte		N12   , Fs4 , v044
	.byte		N12   , An4 
	.byte	W12
	.byte		        En3 , v068
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v044
	.byte	W12
	.byte		        Dn3 , v068
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        En3 , v068
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v044
	.byte	W12
	.byte		        Dn3 , v068
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        Cs3 , v068
	.byte		N12   , En3 
	.byte		N12   , En4 , v044
	.byte	W12
@ 005   ----------------------------------------
	.byte		        An2 , v068
	.byte		N12   , Cs3 
	.byte		N12   , Cs4 , v044
	.byte	W12
	.byte		        Cs3 , v068
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        En3 , v068
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v044
	.byte	W12
	.byte		        Gs3 , v068
	.byte		N12   , Cs4 
	.byte		N12   , Gs4 , v044
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , Fs3 , v068
	.byte		N06   , Bn3 
	.byte		N06   , Bn4 , v044
	.byte	W06
	.byte		        En3 , v068
	.byte		N06   , An3 
	.byte		N06   , An4 , v044
	.byte	W06
	.byte		N12   , En3 , v068
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v044
	.byte	W12
	.byte		        Dn3 , v068
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        Cs3 , v068
	.byte		N12   , En3 
	.byte		N12   , En4 , v044
	.byte	W12
@ 006   ----------------------------------------
	.byte		        An2 , v068
	.byte		N12   , Cs3 
	.byte		N12   , Cs4 , v044
	.byte	W12
	.byte		        Cs3 , v068
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        Fs3 , v068
	.byte		N12   , An3 
	.byte		N12   , Fs4 , v044
	.byte		N12   , An4 
	.byte	W12
	.byte		        En3 , v068
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v044
	.byte	W12
	.byte		        Dn3 , v068
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        En3 , v064
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v044
	.byte	W12
	.byte		        Dn3 , v064
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        Cs3 , v064
	.byte		N12   , En3 
	.byte		N12   , En4 , v044
	.byte	W12
@ 007   ----------------------------------------
	.byte		        An2 , v064
	.byte		N12   , Cs3 
	.byte		N12   , Cs4 , v044
	.byte	W12
	.byte		        Cs3 , v064
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        En3 , v064
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v044
	.byte	W12
	.byte		        Gs3 , v064
	.byte		N12   , Cs4 
	.byte		N12   , Cs5 , v044
	.byte	W12
	.byte		N06   , Fs3 , v064
	.byte		N06   , Bn3 
	.byte		N06   , Bn4 , v044
	.byte	W06
	.byte		        En3 , v064
	.byte		N06   , An3 
	.byte		N06   , An4 , v044
	.byte	W06
	.byte		N12   , En3 , v064
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v044
	.byte	W12
	.byte		        Dn3 , v064
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        Cs3 , v064
	.byte		N12   , En3 
	.byte		N12   , En4 , v044
	.byte	W12
@ 008   ----------------------------------------
	.byte		        An2 , v064
	.byte		N12   , Cs3 
	.byte		N12   , Cs4 , v044
	.byte	W12
	.byte		        Cs3 , v064
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        Fs3 , v064
	.byte		N12   , An3 
	.byte		N12   , An4 , v044
	.byte	W12
	.byte		        En3 , v064
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v044
	.byte	W12
	.byte		        Dn3 , v064
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        En3 , v064
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v044
	.byte	W12
	.byte		        Dn3 , v064
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        Cs3 , v064
	.byte		N12   , En3 
	.byte		N12   , En4 , v044
	.byte	W12
@ 009   ----------------------------------------
	.byte		        An2 , v064
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N12   
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        En3 , v064
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v044
	.byte	W12
	.byte		        Gs3 , v064
	.byte		N12   , Cs4 
	.byte		N12   , Cs5 , v044
	.byte	W12
	.byte		N06   , Fs3 , v064
	.byte		N06   , Bn3 
	.byte		N06   , Bn4 , v044
	.byte	W06
	.byte		        En3 , v064
	.byte		N06   , An3 
	.byte		N06   , An4 , v044
	.byte	W06
	.byte		N12   , En3 , v064
	.byte		N12   , Gs3 
	.byte		N12   , Gs4 , v044
	.byte	W12
	.byte		        Dn3 , v064
	.byte		N12   , Fs3 
	.byte		N12   , Fs4 , v044
	.byte	W12
	.byte		        Cs3 , v064
	.byte		N12   , En3 
	.byte		N12   , En4 , v044
	.byte	W12
@ 010   ----------------------------------------
	.byte	FINE

@**************** Track 8 (Midi-Chn.8) ****************@

Zinnia_Theme_8:
	.byte	KEYSH , Zinnia_Theme_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 87
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		VOL   , 79*Zinnia_Theme_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Cs1 , v127
	.byte	W96
@ 001   ----------------------------------------
	.byte		N48   , Dn1 
	.byte	W48
	.byte		        En1 
	.byte	W48
@ 002   ----------------------------------------
	.byte		TIE   , Fs1 
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
	.byte		EOT   
@ 006   ----------------------------------------
Zinnia_Theme_8_006:
	.byte		N12   , Fs0 , v127
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 008   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 009   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 010   ----------------------------------------
Zinnia_Theme_8_loop:
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 011   ----------------------------------------
Zinnia_Theme_8_011:
	.byte		N12   , Fs0 , v127
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 013   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_011
@ 014   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 015   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_011
@ 016   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 017   ----------------------------------------
	.byte		N12   , Fs0 , v127
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Dn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
@ 018   ----------------------------------------
Zinnia_Theme_8_018:
	.byte		N12   , Gn0 , v127
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
Zinnia_Theme_8_019:
	.byte		N12   , Gn0 , v127
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_018
@ 021   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_019
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_018
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_019
@ 024   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_018
@ 025   ----------------------------------------
Zinnia_Theme_8_025:
	.byte		N12   , Gn0 , v127
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn0 
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Gs0 
	.byte		N12   , Gs1 
	.byte	W12
	.byte	PEND
@ 026   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_018
@ 027   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_019
@ 028   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_018
@ 029   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_019
@ 030   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_018
@ 031   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_019
@ 032   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_018
@ 033   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_025
@ 034   ----------------------------------------
Zinnia_Theme_8_034:
	.byte		N12   , Ds0 , v127
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte	PEND
@ 035   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_034
@ 036   ----------------------------------------
	.byte		N12   , Ds0 , v127
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        Gn0 
	.byte		N12   , Fs1 
	.byte	W12
@ 037   ----------------------------------------
Zinnia_Theme_8_037:
	.byte		N12   , Cn0 , v127
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
@ 038   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_037
@ 039   ----------------------------------------
Zinnia_Theme_8_039:
	.byte		N12   , Dn0 , v127
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte	PEND
@ 040   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_039
@ 041   ----------------------------------------
	.byte		N12   , Dn0 , v127
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N48   , Dn0 
	.byte		N48   , Dn1 
	.byte	W48
@ 042   ----------------------------------------
	.byte		N96   , Dn0 
	.byte	W96
@ 043   ----------------------------------------
	.byte		        En0 
	.byte	W96
@ 044   ----------------------------------------
	.byte		        Fs0 
	.byte	W96
@ 045   ----------------------------------------
	.byte		        Gn0 
	.byte	W96
@ 046   ----------------------------------------
	.byte		N36   , Dn1 
	.byte	W36
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		N48   
	.byte	W48
@ 047   ----------------------------------------
	.byte		        Cs1 
	.byte	W48
	.byte		N24   , An0 
	.byte	W24
	.byte		        An1 
	.byte	W24
@ 048   ----------------------------------------
	.byte		N48   , Bn0 
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		        Bn1 
	.byte	W24
@ 049   ----------------------------------------
	.byte		        Cs1 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
@ 050   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_039
@ 051   ----------------------------------------
Zinnia_Theme_8_051:
	.byte		N12   , En0 , v127
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        En0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        En0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        En0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte	PEND
@ 052   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 053   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_018
@ 054   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_039
@ 055   ----------------------------------------
Zinnia_Theme_8_055:
	.byte		N12   , Cs0 , v127
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cs0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cs0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cs0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte	PEND
@ 056   ----------------------------------------
	.byte		        BnM1
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        BnM1
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        BnM1
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        BnM1
	.byte	W12
	.byte		        Bn0 
	.byte	W12
@ 057   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_055
@ 058   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_039
@ 059   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_051
@ 060   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 061   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 062   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 063   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 064   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 065   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 066   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 067   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 068   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 069   ----------------------------------------
	.byte	PATT
	 .word	Zinnia_Theme_8_006
@ 070   ----------------------------------------
	.byte	GOTO
	.word	Zinnia_Theme_8_loop
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

Zinnia_Theme:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	Zinnia_Theme_pri	@ Priority
	.byte	Zinnia_Theme_rev	@ Reverb.

	.word	Zinnia_Theme_grp

	.word	Zinnia_Theme_1
	.word	Zinnia_Theme_2
	.word	Zinnia_Theme_3
	.word	Zinnia_Theme_4
	.word	Zinnia_Theme_5
	.word	Zinnia_Theme_6
	.word	Zinnia_Theme_7
	.word	Zinnia_Theme_8

	.end

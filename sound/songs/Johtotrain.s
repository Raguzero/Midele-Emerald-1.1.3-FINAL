	.include "MPlayDef.s"

	.equ	Strainer_grp, voicegroup012
	.equ	Strainer_pri, 0
	.equ	Strainer_rev, 0
	.equ	Strainer_mvl, 87
	.equ	Strainer_key, 0
	.equ	Strainer_tbs, 1
	.equ	Strainer_exg, 0
	.equ	Strainer_cmp, 1

	.section .rodata
	.global	Strainer
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

Strainer_1:
	.byte	KEYSH , Strainer_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 94*Strainer_tbs/2
	.byte		VOICE , 56
	.byte		VOL   , 118*Strainer_mvl/mxv
	.byte		PAN   , c_v+17
	.byte		N03   , Gs4 , v088
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
@ 001   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte		N09   , An3 
	.byte		N12   , An4 
	.byte	W18
	.byte		N09   , An3 
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N09   
	.byte	W18
	.byte		N09   
	.byte	W18
	.byte		N12   , As3 
	.byte		N12   , As4 
	.byte	W12
@ 002   ----------------------------------------
	.byte		N09   , An3 
	.byte		N12   , An4 
	.byte	W18
	.byte		N09   , An3 
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N09   
	.byte	W18
	.byte		N09   
	.byte	W18
	.byte		N12   , As3 
	.byte		N12   , As4 
	.byte	W12
@ 003   ----------------------------------------
	.byte		N09   , Cn5 
	.byte	W18
	.byte		N09   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N09   
	.byte	W18
	.byte		N09   
	.byte	W18
	.byte		N12   , Cs5 
	.byte	W12
@ 004   ----------------------------------------
	.byte		N09   , Cn5 
	.byte	W18
	.byte		N09   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N09   
	.byte	W18
	.byte		N09   
	.byte	W18
	.byte		N12   , Bn4 
	.byte	W12
@ 005   ----------------------------------------
Strainer_1_005:
	.byte		N18   , An2 , v088
	.byte	W18
	.byte		        En3 
	.byte	W18
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
	.byte		N48   , Fn3 
	.byte	W48
	.byte		        As3 
	.byte	W48
@ 007   ----------------------------------------
	.byte	PATT
	 .word	Strainer_1_005
@ 008   ----------------------------------------
	.byte		N48   , Fn3 , v088
	.byte	W48
	.byte		        Fn2 
	.byte	W48
Strainer_1_B1:
@ 009   ----------------------------------------
	.byte		N06   , En3 , v088
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N36   , Cs4 
	.byte	W36
	.byte		N12   , As3 
	.byte	W12
@ 010   ----------------------------------------
	.byte		N96   , An3 
	.byte	W96
@ 011   ----------------------------------------
	.byte		N06   , An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
@ 012   ----------------------------------------
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
@ 013   ----------------------------------------
	.byte		        Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
@ 014   ----------------------------------------
	.byte		        Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
@ 015   ----------------------------------------
	.byte		N18   , Gn2 
	.byte	W18
	.byte		        Dn3 
	.byte	W18
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
@ 016   ----------------------------------------
	.byte		N96   , Ds3 
	.byte	W96
@ 017   ----------------------------------------
	.byte		N24   , Fn2 
	.byte	W24
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
@ 018   ----------------------------------------
	.byte		N24   , Gs2 
	.byte	W24
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
@ 019   ----------------------------------------
	.byte		N24   , An2 
	.byte	W24
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
@ 020   ----------------------------------------
	.byte		        As2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
@ 021   ----------------------------------------
	.byte		N06   , As2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
@ 022   ----------------------------------------
Strainer_1_022:
	.byte		N03   , Ds4 , v088
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte	PEND
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Strainer_1_022
@ 024   ----------------------------------------
	.byte	PATT
	 .word	Strainer_1_022
@ 025   ----------------------------------------
	.byte	PATT
	 .word	Strainer_1_022
@ 026   ----------------------------------------
	.byte		N12   , Fn3 , v088
	.byte	W12
	.byte		N06   , As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N24   , Fn3 
	.byte	W24
@ 027   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N06   , As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N24   , Fn3 
	.byte	W24
@ 028   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N06   , As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N24   , Gs3 
	.byte	W24
@ 029   ----------------------------------------
	.byte		N24   
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N18   , Gn3 
	.byte	W06
@ 030   ----------------------------------------
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N18   , Gn3 
	.byte	W18
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N18   , Gn3 
	.byte	W06
@ 031   ----------------------------------------
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		        Gn3 
	.byte	W06
@ 032   ----------------------------------------
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N48   , Fn3 
	.byte	W24
@ 033   ----------------------------------------
	.byte	W24
	.byte		        Gs3 
	.byte	W48
	.byte		N18   , Gn3 
	.byte	W18
	.byte		        Ds3 
	.byte	W06
@ 034   ----------------------------------------
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N48   , Fn3 
	.byte	W24
@ 035   ----------------------------------------
	.byte	W24
	.byte		N12   , As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Ds2 
	.byte		N18   , As2 
	.byte	W18
	.byte		N06   , Ds3 
	.byte	W06
@ 036   ----------------------------------------
	.byte		N24   
	.byte	W24
	.byte		        Ds2 
	.byte		N18   , As2 
	.byte	W18
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		        Gn2 
	.byte		N18   , As2 
	.byte	W18
	.byte		N06   , As3 
	.byte	W06
@ 037   ----------------------------------------
	.byte		N24   
	.byte	W24
	.byte		        As2 
	.byte		N18   , Gn3 
	.byte	W18
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		        As3 
	.byte	W24
@ 038   ----------------------------------------
	.byte		N24   
	.byte	W24
	.byte		N18   , Gn3 
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N24   , Ds3 
	.byte	W24
@ 039   ----------------------------------------
	.byte		N24   
	.byte	W24
	.byte		N18   , As3 
	.byte	W18
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N18   , An2 
	.byte	W18
	.byte		        En3 
	.byte	W06
@ 040   ----------------------------------------
Strainer_1_040:
	.byte	W12
	.byte		N06   , Dn3 , v088
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N48   , Fn3 
	.byte	W24
	.byte	PEND
@ 041   ----------------------------------------
	.byte	W24
	.byte		        As3 
	.byte	W48
	.byte		N18   , An2 
	.byte	W18
	.byte		        En3 
	.byte	W06
@ 042   ----------------------------------------
	.byte	PATT
	 .word	Strainer_1_040
@ 043   ----------------------------------------
	.byte	W24
	.byte		N48   , Fn3 , v088
	.byte	W48
	.byte	GOTO
	 .word	Strainer_1_B1
Strainer_1_B2:
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

Strainer_2:
	.byte	KEYSH , Strainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 2
	.byte		VOL   , 101*Strainer_mvl/mxv
	.byte		PAN   , c_v-12
	.byte	W15
	.byte		N03   , Dn3 , v088
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        Cs2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        Cs2 
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Cn2 
	.byte	W03
	.byte		        An1 
	.byte	W03
@ 001   ----------------------------------------
	.byte		N06   , An2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
@ 002   ----------------------------------------
	.byte		        An2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
@ 003   ----------------------------------------
	.byte		        Cn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
@ 004   ----------------------------------------
	.byte		        Cn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
@ 005   ----------------------------------------
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
@ 006   ----------------------------------------
Strainer_2_006:
	.byte		N06   , Fn1 , v088
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte	PEND
@ 007   ----------------------------------------
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
@ 008   ----------------------------------------
	.byte	PATT
	 .word	Strainer_2_006
Strainer_2_B1:
@ 009   ----------------------------------------
	.byte		N06   , En1 , v088
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
@ 010   ----------------------------------------
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
@ 011   ----------------------------------------
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
@ 012   ----------------------------------------
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
@ 013   ----------------------------------------
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
@ 014   ----------------------------------------
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
@ 015   ----------------------------------------
	.byte		N24   , Gn2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
@ 016   ----------------------------------------
	.byte		N06   
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
@ 017   ----------------------------------------
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
@ 018   ----------------------------------------
	.byte		        Cs2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
@ 019   ----------------------------------------
	.byte		        Dn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
@ 020   ----------------------------------------
	.byte		N12   , As2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
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
	.byte	W48
	.byte		N06   , As1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
@ 030   ----------------------------------------
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
@ 031   ----------------------------------------
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
@ 032   ----------------------------------------
Strainer_2_032:
	.byte		N06   , Ds1 , v088
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte	PEND
@ 033   ----------------------------------------
	.byte		        Cs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
@ 034   ----------------------------------------
	.byte	PATT
	 .word	Strainer_2_032
@ 035   ----------------------------------------
	.byte		N06   , Cs1 , v088
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N24   , Ds2 
	.byte	W24
@ 036   ----------------------------------------
	.byte		        Cs2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        As2 
	.byte	W24
@ 037   ----------------------------------------
	.byte		        Gs2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
@ 038   ----------------------------------------
	.byte		N24   
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Gn2 
	.byte	W24
@ 039   ----------------------------------------
	.byte		N24   
	.byte	W24
	.byte		N18   , Ds2 
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		N48   , An1 
	.byte	W24
@ 040   ----------------------------------------
Strainer_2_040:
	.byte	W24
	.byte		N48   , Cn2 , v088
	.byte	W48
	.byte		        As1 
	.byte	W24
	.byte	PEND
@ 041   ----------------------------------------
	.byte	W24
	.byte		        Dn2 
	.byte	W48
	.byte		        An1 
	.byte	W24
@ 042   ----------------------------------------
	.byte	PATT
	 .word	Strainer_2_040
@ 043   ----------------------------------------
	.byte	W24
	.byte		N48   , Dn2 , v088
	.byte	W48
	.byte	GOTO
	 .word	Strainer_2_B1
Strainer_2_B2:
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

Strainer_3:
	.byte	KEYSH , Strainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 60
	.byte		VOL   , 118*Strainer_mvl/mxv
	.byte		PAN   , c_v-8
	.byte	W24
	.byte		N03   , Gn3 , v076
	.byte	W03
	.byte		        Fs3 , v088
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W15
	.byte		        Cn3 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Bn2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
@ 001   ----------------------------------------
	.byte		N09   , En3 
	.byte	W18
	.byte		N09   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N09   , Fn3 
	.byte	W18
	.byte		N12   , Dn3 
	.byte	W12
@ 002   ----------------------------------------
	.byte		N09   , En3 
	.byte	W18
	.byte		        Dn3 
	.byte	W18
	.byte		N06   , En3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N09   , Fn3 
	.byte	W18
	.byte		N12   
	.byte	W12
@ 003   ----------------------------------------
	.byte		N09   , En4 
	.byte	W18
	.byte		N09   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
@ 004   ----------------------------------------
	.byte		N09   , En4 
	.byte	W18
	.byte		N09   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W12
@ 005   ----------------------------------------
Strainer_3_005:
	.byte		N06   , En3 , v088
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte	PEND
@ 006   ----------------------------------------
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N03   , An3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
@ 007   ----------------------------------------
	.byte	PATT
	 .word	Strainer_3_005
@ 008   ----------------------------------------
	.byte		N12   , Fn3 , v088
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
Strainer_3_B1:
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte		N06   , En4 , v088
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N48   , An3 
	.byte	W48
@ 011   ----------------------------------------
	.byte		N18   , Dn3 
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N18   
	.byte	W18
	.byte		N24   
	.byte	W30
@ 012   ----------------------------------------
	.byte		N18   
	.byte	W18
	.byte		N24   
	.byte	W30
	.byte		N06   , An2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
@ 013   ----------------------------------------
	.byte		N18   , Cn3 
	.byte	W18
	.byte		N24   , Dn3 
	.byte	W30
	.byte		N18   , Cn3 
	.byte	W18
	.byte		N24   , Dn3 
	.byte	W30
@ 014   ----------------------------------------
	.byte		N18   , Cn3 
	.byte	W18
	.byte		N24   , Dn3 
	.byte	W30
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte		        Ds3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
@ 017   ----------------------------------------
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
@ 018   ----------------------------------------
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , En3 
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
@ 019   ----------------------------------------
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
@ 020   ----------------------------------------
	.byte		        As2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
Strainer_3_022:
	.byte		N12   , Fn3 , v088
	.byte	W12
	.byte		N06   , As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte	PEND
@ 023   ----------------------------------------
Strainer_3_023:
	.byte		N12   , Fn3 , v088
	.byte	W12
	.byte		N06   , As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 024   ----------------------------------------
	.byte	PATT
	 .word	Strainer_3_022
@ 025   ----------------------------------------
	.byte	PATT
	 .word	Strainer_3_023
@ 026   ----------------------------------------
	.byte		N12   , Fn3 , v088
	.byte	W12
	.byte		N06   , As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N03   , Fn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N24   , Fn3 
	.byte	W24
@ 027   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N06   , As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N24   , Fn3 
	.byte	W24
@ 028   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N06   , As2 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N24   , Gs3 
	.byte	W24
@ 029   ----------------------------------------
	.byte		N24   
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N06   , As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N18   , Gn3 
	.byte	W06
@ 030   ----------------------------------------
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N18   , Gn3 
	.byte	W18
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N18   , Gn3 
	.byte	W06
@ 031   ----------------------------------------
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N18   , Ds4 
	.byte	W18
	.byte		        As4 
	.byte	W06
@ 032   ----------------------------------------
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W24
@ 033   ----------------------------------------
	.byte	W24
	.byte		        Gs4 
	.byte	W48
	.byte		N18   , Ds4 
	.byte	W18
	.byte		        As4 
	.byte	W06
@ 034   ----------------------------------------
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N48   , Cs4 
	.byte	W24
@ 035   ----------------------------------------
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N18   , Gn3 
	.byte	W18
	.byte		N06   , Ds3 
	.byte	W06
@ 036   ----------------------------------------
	.byte		N24   , As3 
	.byte	W24
	.byte		N18   
	.byte	W18
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N18   
	.byte	W18
	.byte		N06   , As3 
	.byte	W06
@ 037   ----------------------------------------
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N18   
	.byte	W18
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N24   , As4 
	.byte	W24
	.byte		N18   , Gn4 
	.byte	W18
	.byte		        As4 
	.byte	W06
@ 038   ----------------------------------------
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N48   , Ds4 
	.byte	W48
	.byte		N18   
	.byte	W18
	.byte		        As4 
	.byte	W06
@ 039   ----------------------------------------
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N48   , Ds4 
	.byte	W48
	.byte		N18   , An3 
	.byte	W18
	.byte		        En4 
	.byte	W06
@ 040   ----------------------------------------
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W24
@ 041   ----------------------------------------
	.byte	W24
	.byte		        As4 
	.byte	W48
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
@ 042   ----------------------------------------
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
@ 043   ----------------------------------------
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte	GOTO
	 .word	Strainer_3_B1
Strainer_3_B2:
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

Strainer_4:
	.byte	KEYSH , Strainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 46
	.byte		VOL   , 103*Strainer_mvl/mxv
	.byte		PAN   , c_v-17
	.byte		N03   , Gs4 , v088
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        As3 
	.byte	W03
@ 001   ----------------------------------------
Strainer_4_001:
	.byte		N18   , An3 , v088
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N12   , As3 
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	Strainer_4_001
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte		N06   , En4 , v088
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W24
@ 005   ----------------------------------------
Strainer_4_005:
	.byte		N06   , En3 , v088
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte	PEND
@ 006   ----------------------------------------
	.byte		N48   , As3 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
@ 007   ----------------------------------------
	.byte	PATT
	 .word	Strainer_4_005
@ 008   ----------------------------------------
	.byte		N12   , Fn3 , v088
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N18   , As3 
	.byte	W18
	.byte		N06   , An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
Strainer_4_B1:
@ 009   ----------------------------------------
	.byte		N06   , En3 , v088
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N36   , Cs4 
	.byte	W36
	.byte		N12   , As3 
	.byte	W12
@ 010   ----------------------------------------
	.byte		N96   , An3 
	.byte	W96
@ 011   ----------------------------------------
	.byte		N06   , An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
@ 012   ----------------------------------------
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        An2 
	.byte	W48
@ 013   ----------------------------------------
	.byte		        Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
@ 014   ----------------------------------------
	.byte		        Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Fn2 
	.byte	W48
@ 015   ----------------------------------------
	.byte		N18   , Gn2 
	.byte	W18
	.byte		        Dn3 
	.byte	W06
	.byte		N24   , Ds3 
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte		N24   , Fn3 
	.byte	W12
	.byte		N12   , Cn3 
	.byte	W12
@ 016   ----------------------------------------
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
@ 017   ----------------------------------------
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
@ 018   ----------------------------------------
	.byte		N24   , En3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
@ 019   ----------------------------------------
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
@ 020   ----------------------------------------
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
@ 021   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
@ 022   ----------------------------------------
Strainer_4_022:
	.byte		N03   , Ds4 , v088
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte	PEND
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Strainer_4_022
@ 024   ----------------------------------------
	.byte	PATT
	 .word	Strainer_4_022
@ 025   ----------------------------------------
	.byte	PATT
	 .word	Strainer_4_022
@ 026   ----------------------------------------
	.byte		N96   , Fn4 , v088
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W72
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N18   
	.byte	W06
@ 030   ----------------------------------------
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N18   
	.byte	W06
@ 031   ----------------------------------------
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N18   
	.byte	W18
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N18   , Gs3 
	.byte	W18
	.byte		        Gn3 
	.byte	W06
@ 032   ----------------------------------------
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
@ 033   ----------------------------------------
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N18   , Gn3 
	.byte	W18
	.byte		        Ds3 
	.byte	W06
@ 034   ----------------------------------------
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
@ 035   ----------------------------------------
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , As2 
	.byte	W24
@ 036   ----------------------------------------
	.byte		        Ds3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        As2 
	.byte	W24
@ 037   ----------------------------------------
	.byte		        As3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N48   
	.byte	W24
@ 038   ----------------------------------------
	.byte	W24
	.byte		        As3 
	.byte	W48
	.byte		        Gn3 
	.byte	W24
@ 039   ----------------------------------------
	.byte	W24
	.byte		        Ds3 
	.byte	W72
@ 040   ----------------------------------------
	.byte	W72
	.byte		        Fn4 
	.byte	W24
@ 041   ----------------------------------------
	.byte	W24
	.byte		        As4 
	.byte	W48
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
@ 042   ----------------------------------------
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
@ 043   ----------------------------------------
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N18   , As3 
	.byte	W18
	.byte		N06   , An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte	GOTO
	 .word	Strainer_4_B1
Strainer_4_B2:
	.byte	FINE

@**************** Track 5 (Midi-Chn.6) ****************@

Strainer_5:
	.byte	KEYSH , Strainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 48
	.byte		VOL   , 103*Strainer_mvl/mxv
	.byte		PAN   , c_v-13
	.byte	W96
@ 001   ----------------------------------------
	.byte		N03   , An3 , v088
	.byte		N06   , An4 
	.byte	W84
	.byte		N12   , As3 
	.byte	W12
@ 002   ----------------------------------------
	.byte		N03   , An3 
	.byte		N06   , An4 
	.byte	W84
	.byte		N12   , Fn3 
	.byte	W12
@ 003   ----------------------------------------
	.byte		N09   , Cn4 
	.byte		N09   , Cn5 
	.byte	W18
	.byte		        Cn4 
	.byte		N09   , Cn5 
	.byte	W18
	.byte		N06   , Cn4 
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N09   , Cn4 
	.byte		N09   , Cn5 
	.byte	W18
	.byte		        Cn4 
	.byte		N09   , Cn5 
	.byte	W18
	.byte		N06   , Cs4 
	.byte		N12   , Cs5 
	.byte	W12
@ 004   ----------------------------------------
	.byte		N09   , Cn4 
	.byte		N09   , Cn5 
	.byte	W18
	.byte		        Cn4 
	.byte		N09   , Cn5 
	.byte	W18
	.byte		N06   , Cn4 
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N09   , Cn4 
	.byte		N09   , Cn5 
	.byte	W18
	.byte		        Cn4 
	.byte		N09   , Cn5 
	.byte	W18
	.byte		N06   , Bn3 
	.byte		N12   , Bn4 
	.byte	W12
@ 005   ----------------------------------------
Strainer_5_005:
	.byte		N18   , An2 , v088
	.byte		N48   , An3 
	.byte	W18
	.byte		N18   , En3 
	.byte	W18
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
	.byte		N48   , Fn3 
	.byte	W48
	.byte		        Dn3 
	.byte		N48   , As3 
	.byte	W48
@ 007   ----------------------------------------
	.byte	PATT
	 .word	Strainer_5_005
@ 008   ----------------------------------------
	.byte		N48   , Fn3 , v088
	.byte		N48   , As3 
	.byte	W48
	.byte		        Fn2 
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
Strainer_5_B1:
@ 009   ----------------------------------------
	.byte		N06   , En3 , v088
	.byte		N18   , An3 
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N18   
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   
	.byte		N06   , As3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N36   , Cs4 
	.byte		N18   , Dn4 
	.byte	W18
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , As3 
	.byte		N06   , Fn4 
	.byte	W06
@ 010   ----------------------------------------
	.byte		N96   , An3 
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W54
@ 011   ----------------------------------------
	.byte		N24   , En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
@ 012   ----------------------------------------
	.byte		        En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
@ 013   ----------------------------------------
Strainer_5_013:
	.byte		N24   , Dn3 , v088
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte	PEND
@ 014   ----------------------------------------
	.byte	PATT
	 .word	Strainer_5_013
@ 015   ----------------------------------------
	.byte		N24   , Dn3 , v088
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
@ 016   ----------------------------------------
	.byte		N48   , Gn3 
	.byte	W48
	.byte		        As3 
	.byte	W48
@ 017   ----------------------------------------
	.byte		        Ds3 
	.byte	W48
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
@ 018   ----------------------------------------
	.byte		N48   , Gs3 
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
@ 019   ----------------------------------------
	.byte		N96   , Dn3 
	.byte		N48   , An3 
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
@ 020   ----------------------------------------
	.byte		N24   , Gn3 
	.byte		N48   , As3 
	.byte	W24
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        As3 
	.byte		N48   , Ds4 
	.byte	W24
	.byte		N24   , Gn3 
	.byte	W24
@ 021   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
@ 022   ----------------------------------------
Strainer_5_022:
	.byte		N24   , Fn3 , v088
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte	PEND
@ 023   ----------------------------------------
Strainer_5_023:
	.byte		N24   , Fn3 , v088
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte	PEND
@ 024   ----------------------------------------
	.byte	PATT
	 .word	Strainer_5_022
@ 025   ----------------------------------------
	.byte	PATT
	 .word	Strainer_5_023
@ 026   ----------------------------------------
	.byte		N12   , Fn3 , v088
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , As2 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Fn3 
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn3 
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fn3 
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Ds3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Dn3 
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Ds3 
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Dn3 
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Ds3 
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N06   , Fn3 
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        As2 
	.byte		N06   , As3 
	.byte	W06
	.byte		N24   , Cn3 
	.byte		N24   , Cn4 
	.byte	W24
@ 027   ----------------------------------------
	.byte		N12   , Fn3 
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , As2 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Fn3 
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn3 
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fn3 
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Ds3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Dn3 
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Ds3 
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Dn3 
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Ds3 
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N06   , Fn3 
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gn3 
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N24   , Fn3 
	.byte		N12   , Fn4 
	.byte	W24
@ 028   ----------------------------------------
	.byte		        Fn3 
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , As2 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Fn3 
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gs3 
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn3 
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fn3 
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Ds3 
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Dn3 
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Ds3 
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Dn3 
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Ds3 
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N06   , Fn3 
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        As2 
	.byte		N06   , As3 
	.byte	W06
	.byte		N48   , Cn3 
	.byte		N48   , Cn4 
	.byte	W24
@ 029   ----------------------------------------
	.byte	W24
	.byte		        Ds3 
	.byte		N48   , Ds4 
	.byte	W48
	.byte		N09   , Gn3 
	.byte	W18
	.byte		N09   
	.byte	W06
@ 030   ----------------------------------------
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N09   , Gn3 
	.byte	W18
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N09   , Gn3 
	.byte	W18
	.byte		N09   
	.byte	W06
@ 031   ----------------------------------------
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N09   , Gn3 
	.byte	W18
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N18   , Ds4 
	.byte	W18
	.byte		        As4 
	.byte	W06
@ 032   ----------------------------------------
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W24
@ 033   ----------------------------------------
	.byte	W24
	.byte		        Gs4 
	.byte	W48
	.byte		N18   , Ds4 
	.byte	W18
	.byte		        As4 
	.byte	W06
@ 034   ----------------------------------------
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N12   , Cs4 
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Cn4 
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        As3 
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Gs3 
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N48   , Cs4 
	.byte	W24
@ 035   ----------------------------------------
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N18   , Gn3 
	.byte	W18
	.byte		N06   , Ds3 
	.byte	W06
@ 036   ----------------------------------------
	.byte		N24   , As3 
	.byte	W24
	.byte		N18   
	.byte	W18
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N18   
	.byte	W18
	.byte		N06   , As3 
	.byte	W06
@ 037   ----------------------------------------
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N18   
	.byte	W18
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N24   , As4 
	.byte	W24
	.byte		N18   , Gn4 
	.byte	W18
	.byte		        As4 
	.byte	W06
@ 038   ----------------------------------------
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N48   , Ds4 
	.byte	W48
	.byte		N18   
	.byte	W18
	.byte		        As4 
	.byte	W06
@ 039   ----------------------------------------
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N48   , Ds4 
	.byte	W72
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W72
	.byte		N18   , An2 
	.byte	W18
	.byte		        En3 
	.byte	W06
@ 042   ----------------------------------------
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N48   , Fn3 
	.byte	W24
@ 043   ----------------------------------------
	.byte	W24
	.byte		N48   
	.byte		N48   , As3 
	.byte	W48
	.byte	GOTO
	 .word	Strainer_5_B1
Strainer_5_B2:
	.byte	FINE

@**************** Track 6 (Midi-Chn.7) ****************@

Strainer_6:
	.byte	KEYSH , Strainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 73
	.byte		VOL   , 101*Strainer_mvl/mxv
	.byte		PAN   , c_v+21
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
Strainer_6_B1:
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
	.byte		N12   , Gn3 , v100
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        As1 
	.byte		N12   , As2 
	.byte	W12
	.byte		        Gn3 
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        As1 
	.byte		N12   , As2 
	.byte	W12
	.byte		        Gn3 
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        As1 
	.byte		N12   , As2 
	.byte	W12
	.byte		        Gn3 
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        As1 
	.byte		N12   , As2 
	.byte	W12
@ 022   ----------------------------------------
Strainer_6_022:
	.byte		N12   , As2 , v100
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , Ds2 
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cs3 
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Cn3 
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        As2 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Gs2 
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        Gn2 
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        Gs2 
	.byte		N03   , Gs3 
	.byte	W03
	.byte		        Gn2 
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        Gs2 
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , As2 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Ds2 
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N24   , Fn2 
	.byte		N24   , Fn3 
	.byte	W24
	.byte	PEND
@ 023   ----------------------------------------
Strainer_6_023:
	.byte		N12   , As2 , v100
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , Ds2 
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cs3 
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Cn3 
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        As2 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Gs2 
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        Gn2 
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        Gs2 
	.byte		N03   , Gs3 
	.byte	W03
	.byte		        Gn2 
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        Gs2 
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , As2 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn3 
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N24   , As2 
	.byte		N24   , As3 
	.byte	W24
	.byte	PEND
@ 024   ----------------------------------------
	.byte	PATT
	 .word	Strainer_6_022
@ 025   ----------------------------------------
	.byte	PATT
	 .word	Strainer_6_023
@ 026   ----------------------------------------
	.byte		N24   , Cs3 , v088
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Cn3 
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        As2 
	.byte		N24   , As3 
	.byte	W24
	.byte		        Gs2 
	.byte		N24   , Gs3 
	.byte	W24
@ 027   ----------------------------------------
	.byte		        Fn2 
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Gn2 
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Gs2 
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , As2 
	.byte		N24   , As3 
	.byte	W24
@ 028   ----------------------------------------
	.byte		        Fn2 
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Gn2 
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Gs2 
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , As2 
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Ds2 
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N48   , Cn3 
	.byte		N24   , Gs3 
	.byte	W24
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
	.byte	W72
	.byte		N18   , Ds4 
	.byte	W18
	.byte		N06   , As3 
	.byte	W06
@ 037   ----------------------------------------
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N18   
	.byte	W18
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N24   , As4 
	.byte	W48
@ 038   ----------------------------------------
	.byte	W72
	.byte		N18   , Ds4 
	.byte	W18
	.byte		        As4 
	.byte	W06
@ 039   ----------------------------------------
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N48   , Ds4 
	.byte	W72
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W72
	.byte	GOTO
	 .word	Strainer_6_B1
Strainer_6_B2:
	.byte	FINE

@**************** Track 7 (Midi-Chn.8) ****************@

Strainer_7:
	.byte	KEYSH , Strainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 46
	.byte		VOL   , 101*Strainer_mvl/mxv
	.byte		PAN   , c_v-11
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
Strainer_7_B1:
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
	.byte		N96   , Ds2 , v100
	.byte	W96
@ 022   ----------------------------------------
	.byte		        As1 
	.byte	W96
@ 023   ----------------------------------------
	.byte		N96   
	.byte	W96
@ 024   ----------------------------------------
	.byte		N96   
	.byte	W96
@ 025   ----------------------------------------
	.byte		N96   
	.byte	W96
@ 026   ----------------------------------------
	.byte		N24   , Cs2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
@ 027   ----------------------------------------
	.byte		        Fn1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        As1 
	.byte	W24
@ 028   ----------------------------------------
	.byte		        Fn1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		N72   , Cn2 
	.byte	W24
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
	.byte	W72
	.byte		N24   , Ds2 , v076
	.byte	W24
@ 036   ----------------------------------------
	.byte		        Cs2 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        As2 
	.byte	W24
@ 037   ----------------------------------------
	.byte		        Gs2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        Fn2 
	.byte	W48
@ 038   ----------------------------------------
	.byte	W96
@ 039   ----------------------------------------
	.byte	W24
	.byte		N48   , Ds3 , v088
	.byte	W72
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W72
	.byte	GOTO
	 .word	Strainer_7_B1
Strainer_7_B2:
	.byte	FINE

@**************** Track 8 (Midi-Chn.10) ****************@

Strainer_8:
	.byte	KEYSH , Strainer_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		VOL   , 90*Strainer_mvl/mxv
	.byte		PAN   , c_v-27
	.byte	W96
@ 001   ----------------------------------------
	.byte		N06   , Dn1 , v088
	.byte		N06   , An2 
	.byte	W18
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte	W18
	.byte		        Bn0 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , An3 
	.byte	W18
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte	W06
@ 002   ----------------------------------------
	.byte		N06   
	.byte		N06   , En1 
	.byte	W48
	.byte		N06   
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , As3 
	.byte	W06
	.byte		        En1 
	.byte		N06   , Fs2 
	.byte		N06   , As3 
	.byte	W18
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
@ 003   ----------------------------------------
	.byte		        Dn1 
	.byte		N03   , As3 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn1 
	.byte		N06   , An3 
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Dn1 
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N03   , As3 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W12
	.byte		N06   , Bn0 
	.byte		N06   , Dn1 
	.byte		N03   , As3 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn0 
	.byte		N06   , Dn1 
	.byte		N03   , As3 
	.byte	W12
@ 004   ----------------------------------------
	.byte		N06   , Dn1 
	.byte		N06   , An2 
	.byte		N03   , As3 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn1 
	.byte		N06   , An3 
	.byte		N03   , As3 
	.byte	W03
	.byte		N06   
	.byte	W03
	.byte		        Dn1 
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N03   , As3 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn1 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N03   , As3 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn1 
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , En1 
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Dn1 
	.byte		N06   , En1 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
@ 005   ----------------------------------------
	.byte		        Bn0 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
@ 006   ----------------------------------------
	.byte		        Bn0 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
@ 007   ----------------------------------------
	.byte		        Bn0 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N03   , Fs2 
	.byte		N06   , As3 
	.byte	W03
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W03
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , Bn0 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Fs2 
	.byte		N06   , As3 
	.byte	W03
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N03   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W03
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
@ 008   ----------------------------------------
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N03   , Fs2 
	.byte		N06   , As3 
	.byte	W03
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
	.byte		        Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
Strainer_8_B1:
@ 009   ----------------------------------------
	.byte		N06   , Dn1 , v088
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W18
	.byte		        Dn1 
	.byte		N06   , As3 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte		N06   , As3 
	.byte	W18
	.byte		        Dn1 
	.byte		N06   , As3 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
@ 010   ----------------------------------------
	.byte		        An3 
	.byte		N06   , As3 
	.byte	W18
	.byte		        Dn1 
	.byte		N06   , As3 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An2 
	.byte		N06   , An3 
	.byte	W36
	.byte		        En1 
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W06
@ 011   ----------------------------------------
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N03   
	.byte	W09
	.byte		N06   
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W18
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
@ 012   ----------------------------------------
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W12
	.byte		N06   
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W12
	.byte		        An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , En1 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		N06   
	.byte		N06   , En1 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
@ 013   ----------------------------------------
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N03   
	.byte	W09
	.byte		N06   
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W18
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn0 
	.byte	W12
	.byte		        Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
@ 014   ----------------------------------------
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W12
	.byte		N06   
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W12
	.byte		        An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , En1 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		N06   
	.byte		N06   , En1 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Dn1 
	.byte		N03   , En1 
	.byte		N06   , As3 
	.byte	W03
	.byte		N03   , Dn1 
	.byte		N03   , En1 
	.byte	W03
@ 015   ----------------------------------------
	.byte		N06   , Fs2 
	.byte		N06   , An2 
	.byte	W24
	.byte		        Bn0 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte		N06   , En1 
	.byte	W24
@ 016   ----------------------------------------
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
@ 017   ----------------------------------------
Strainer_8_017:
	.byte		N06   , Bn0 , v088
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 018   ----------------------------------------
	.byte	PATT
	 .word	Strainer_8_017
@ 019   ----------------------------------------
	.byte		N06   , Bn0 , v088
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte		N06   , As3 
	.byte	W06
@ 020   ----------------------------------------
	.byte		        Dn1 
	.byte		N06   , Fs2 
	.byte		N06   , An2 
	.byte	W42
	.byte		N01   , En1 
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N06   , Dn1 
	.byte		N06   , En1 
	.byte	W24
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W24
@ 021   ----------------------------------------
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
@ 022   ----------------------------------------
Strainer_8_022:
	.byte		N06   , Dn1 , v088
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N01   , En1 
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Strainer_8_022
@ 024   ----------------------------------------
	.byte	PATT
	 .word	Strainer_8_022
@ 025   ----------------------------------------
	.byte		N06   , Dn1 , v088
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N01   , En1 
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		N01   
	.byte	W02
@ 026   ----------------------------------------
	.byte		N06   , Dn1 
	.byte		N06   , En1 
	.byte		N06   , An2 
	.byte	W12
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N01   , Dn1 
	.byte		N01   , En1 
	.byte	W01
	.byte		        Dn1 
	.byte		N01   , En1 
	.byte	W02
	.byte		        Dn1 
	.byte		N01   , En1 
	.byte	W01
	.byte		        Dn1 
	.byte		N01   , En1 
	.byte	W02
	.byte		        Dn1 
	.byte		N01   , En1 
	.byte	W01
	.byte		        Dn1 
	.byte		N01   , En1 
	.byte	W02
	.byte		        Dn1 
	.byte		N01   , En1 
	.byte	W01
	.byte		        Dn1 
	.byte		N01   , En1 
	.byte	W02
	.byte		N06   , Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W06
@ 027   ----------------------------------------
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W12
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
@ 028   ----------------------------------------
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W24
@ 029   ----------------------------------------
	.byte	W24
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W24
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W12
	.byte		        Dn1 
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Dn1 , v100
	.byte		N06   , En1 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
@ 030   ----------------------------------------
	.byte	W12
	.byte		N06   
	.byte		N06   , As3 
	.byte	W12
	.byte		        Dn1 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
@ 031   ----------------------------------------
	.byte	W12
	.byte		        Dn1 , v088
	.byte		N06   , As3 
	.byte	W12
	.byte		        Dn1 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        Bn0 
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N06   
	.byte		N06   , Fs2 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , Fs2 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W06
@ 032   ----------------------------------------
	.byte	W12
	.byte		        Bn0 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 , v100
	.byte	W06
	.byte		        Bn0 , v088
	.byte	W12
	.byte		        Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 , v100
	.byte	W06
@ 033   ----------------------------------------
	.byte	W12
	.byte		        Bn0 , v088
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 , v100
	.byte	W06
	.byte		        Bn0 , v088
	.byte	W18
	.byte		N06   
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 , v100
	.byte	W06
@ 034   ----------------------------------------
	.byte	W12
	.byte		        Bn0 , v088
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 , v100
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Bn0 , v088
	.byte		N06   , Fs2 , v100
	.byte	W12
	.byte		        Bn0 
	.byte		N06   , Dn1 , v088
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W12
	.byte		        Bn0 , v100
	.byte		N06   , Dn1 , v088
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        En1 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 , v100
	.byte	W06
@ 035   ----------------------------------------
	.byte	W12
	.byte		        Bn0 , v088
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 , v100
	.byte	W06
	.byte		        Bn0 , v088
	.byte	W18
	.byte		N06   
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte		N06   , As3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte		N06   , An2 
	.byte	W24
@ 036   ----------------------------------------
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W24
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W24
	.byte		        Bn0 
	.byte		N06   , En1 
	.byte		N06   , Fs2 
	.byte	W24
	.byte		        Bn0 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W24
@ 037   ----------------------------------------
	.byte		        Bn0 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W24
	.byte		        Bn0 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W24
	.byte		        Bn0 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W24
	.byte		        Fs2 
	.byte		N06   , As3 
	.byte	W24
@ 038   ----------------------------------------
	.byte	W24
	.byte		        Fs2 
	.byte		N06   , As3 
	.byte	W24
	.byte		        Bn0 
	.byte	W24
	.byte		        Fs2 
	.byte		N06   , As3 
	.byte	W24
@ 039   ----------------------------------------
	.byte		        Bn0 
	.byte	W24
	.byte		        An3 
	.byte		N06   , As3 
	.byte	W18
	.byte		        Bn0 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W12
	.byte		        Bn0 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W12
	.byte		        Bn0 
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte		N06   , As3 
	.byte	W06
	.byte		        Fs2 
	.byte		N06   , As3 
	.byte	W24
@ 040   ----------------------------------------
	.byte	W24
	.byte		        Fs2 
	.byte		N06   , As3 
	.byte	W48
	.byte		        Fs2 
	.byte		N06   , As3 
	.byte	W24
@ 041   ----------------------------------------
	.byte	W24
	.byte		        Fs2 
	.byte		N06   , As3 
	.byte	W24
	.byte		        Fs2 
	.byte		N06   , As3 
	.byte	W24
	.byte		        En1 
	.byte		N06   , Fs2 
	.byte		N06   , As3 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , An3 
	.byte	W06
@ 042   ----------------------------------------
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , An3 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , An3 
	.byte	W06
@ 043   ----------------------------------------
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte		N06   , Fs2 
	.byte		N06   , An3 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , An3 
	.byte	W12
	.byte		        Bn0 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En1 
	.byte	W06
	.byte	GOTO
	 .word	Strainer_8_B1
Strainer_8_B2:
	.byte	FINE

@******************************************************@
	.align	2

Strainer:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	Strainer_pri	@ Priority
	.byte	Strainer_rev	@ Reverb.

	.word	Strainer_grp

	.word	Strainer_1
	.word	Strainer_2
	.word	Strainer_3
	.word	Strainer_4
	.word	Strainer_5
	.word	Strainer_6
	.word	Strainer_7
	.word	Strainer_8

	.end

	.include "MPlayDef.s"

	.equ	ff6boss_grp, voicegroup000
	.equ	ff6boss_pri, 0
	.equ	ff6boss_rev, 0
	.equ	ff6boss_mvl, 87
	.equ	ff6boss_key, 0
	.equ	ff6boss_tbs, 1
	.equ	ff6boss_exg, 0
	.equ	ff6boss_cmp, 1

	.section .rodata
	.global	ff6boss
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

ff6boss_1:
	.byte	KEYSH , ff6boss_key+0
ff6boss_1_B1:
@ 000   ----------------------------------------
	.byte	TEMPO , 205*ff6boss_tbs/2
	.byte		VOICE , 17
	.byte		VOL   , 122*ff6boss_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		N11   , En4 , v076
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
@ 001   ----------------------------------------
ff6boss_1_001:
	.byte		N11   , An3 , v076
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
ff6boss_1_002:
	.byte		N11   , En4 , v076
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 004   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 005   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 006   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 008   ----------------------------------------
ff6boss_1_008:
	.byte		N20   , An3 , v076
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N11   , Dn4 
	.byte	W12
	.byte		N20   , Cn4 
	.byte	W24
	.byte		N23   , Bn3 
	.byte	W12
	.byte	PEND
@ 009   ----------------------------------------
ff6boss_1_009:
	.byte	W12
	.byte		N11   , Cn4 , v076
	.byte	W12
	.byte		N20   , Dn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte	PEND
@ 010   ----------------------------------------
	.byte		TIE   , An3 
	.byte	W96
@ 011   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 012   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_008
@ 013   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_009
@ 014   ----------------------------------------
	.byte		TIE   , An3 , v076
	.byte	W96
@ 015   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
ff6boss_1_018:
	.byte		N11   , An3 , v076
	.byte	W12
	.byte		        An3 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        An3 , v076
	.byte	W12
	.byte		        An3 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        An3 , v076
	.byte	W12
	.byte		        An3 , v060
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
ff6boss_1_019:
	.byte		N11   , An3 , v060
	.byte	W12
	.byte		        An3 , v076
	.byte	W12
	.byte		        An3 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N20   , An3 , v076
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 021   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_019
@ 022   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 023   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_019
@ 024   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 025   ----------------------------------------
ff6boss_1_025:
	.byte		N11   , An3 , v060
	.byte	W12
	.byte		        An3 , v076
	.byte	W12
	.byte		        An3 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Bn3 , v076
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	PEND
@ 026   ----------------------------------------
ff6boss_1_026:
	.byte		N66   , Fn4 , v092
	.byte	W72
	.byte		N20   , Cn4 
	.byte	W24
	.byte	PEND
@ 027   ----------------------------------------
ff6boss_1_027:
	.byte		N32   , Bn3 , v092
	.byte	W36
	.byte		        Cn4 
	.byte	W36
	.byte		N20   , Dn4 
	.byte	W24
	.byte	PEND
@ 028   ----------------------------------------
ff6boss_1_028:
	.byte		N32   , En4 , v092
	.byte	W36
	.byte		        Fn4 
	.byte	W36
	.byte		N20   , Gn4 
	.byte	W24
	.byte	PEND
@ 029   ----------------------------------------
ff6boss_1_029:
	.byte		N42   , Cn4 , v092
	.byte	W48
	.byte		N32   , Bn3 
	.byte	W36
	.byte		N44   , An3 
	.byte	W12
	.byte	PEND
@ 030   ----------------------------------------
ff6boss_1_030:
	.byte	W36
	.byte		N32   , Fn4 , v092
	.byte	W36
	.byte		N20   , Cn4 
	.byte	W24
	.byte	PEND
@ 031   ----------------------------------------
ff6boss_1_031:
	.byte		N32   , Bn3 , v092
	.byte	W36
	.byte		        An3 
	.byte	W36
	.byte		N20   , Gn3 
	.byte	W24
	.byte	PEND
@ 032   ----------------------------------------
	.byte		N90   , An3 
	.byte	W96
@ 033   ----------------------------------------
ff6boss_1_033:
	.byte		N20   , An3 , v092
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte	PEND
@ 034   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_026
@ 035   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_027
@ 036   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_028
@ 037   ----------------------------------------
ff6boss_1_037:
	.byte		N32   , Fs4 , v092
	.byte	W36
	.byte		        Gn4 
	.byte	W36
	.byte		N20   , An4 
	.byte	W24
	.byte	PEND
@ 038   ----------------------------------------
	.byte		TIE   , Cn5 
	.byte	W96
@ 039   ----------------------------------------
	.byte	W11
	.byte		EOT   
	.byte	W01
	.byte		N11   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
@ 040   ----------------------------------------
	.byte		TIE   , Cn3 
	.byte	W96
@ 041   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 042   ----------------------------------------
	.byte		N90   , Bn3 , v076
	.byte	W96
@ 043   ----------------------------------------
	.byte		        Dn4 
	.byte	W96
@ 044   ----------------------------------------
	.byte		        En4 
	.byte	W96
@ 045   ----------------------------------------
	.byte		        Fn4 
	.byte	W96
@ 046   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 047   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 048   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 049   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 050   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 051   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 052   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 053   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 054   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_008
@ 055   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_009
@ 056   ----------------------------------------
	.byte		TIE   , An3 , v076
	.byte	W96
@ 057   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 058   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_008
@ 059   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_009
@ 060   ----------------------------------------
	.byte		TIE   , An3 , v076
	.byte	W96
@ 061   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 065   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_019
@ 066   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 067   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_019
@ 068   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 069   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_019
@ 070   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 071   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_025
@ 072   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_026
@ 073   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_027
@ 074   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_028
@ 075   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_029
@ 076   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_030
@ 077   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_031
@ 078   ----------------------------------------
	.byte		N90   , An3 , v092
	.byte	W96
@ 079   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_033
@ 080   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_026
@ 081   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_027
@ 082   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_028
@ 083   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_037
@ 084   ----------------------------------------
	.byte		TIE   , Cn5 , v092
	.byte	W96
@ 085   ----------------------------------------
	.byte	W11
	.byte		EOT   
	.byte	W01
	.byte		N11   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
@ 086   ----------------------------------------
	.byte		TIE   , Cn3 
	.byte	W96
@ 087   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 088   ----------------------------------------
	.byte		N90   , Bn3 , v076
	.byte	W96
@ 089   ----------------------------------------
	.byte		        Dn4 
	.byte	W96
@ 090   ----------------------------------------
	.byte		        En4 
	.byte	W96
@ 091   ----------------------------------------
	.byte		        Fn4 
	.byte	W96
@ 092   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 093   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 094   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 095   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 096   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 097   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 098   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 099   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 100   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_008
@ 101   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_009
@ 102   ----------------------------------------
	.byte		TIE   , An3 , v076
	.byte	W96
@ 103   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 104   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_008
@ 105   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_009
@ 106   ----------------------------------------
	.byte		TIE   , An3 , v076
	.byte	W96
@ 107   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 108   ----------------------------------------
	.byte	W96
@ 109   ----------------------------------------
	.byte	W96
@ 110   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 111   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_019
@ 112   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 113   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_019
@ 114   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 115   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_019
@ 116   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 117   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_025
@ 118   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_026
@ 119   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_027
@ 120   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_028
@ 121   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_029
@ 122   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_030
@ 123   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_031
@ 124   ----------------------------------------
	.byte		N90   , An3 , v092
	.byte	W96
@ 125   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_033
@ 126   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_026
@ 127   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_027
@ 128   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_028
@ 129   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_037
@ 130   ----------------------------------------
	.byte		TIE   , Cn5 , v092
	.byte	W96
@ 131   ----------------------------------------
	.byte	W11
	.byte		EOT   
	.byte	W01
	.byte		N11   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
@ 132   ----------------------------------------
	.byte		TIE   , Cn3 
	.byte	W96
@ 133   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 134   ----------------------------------------
	.byte		N90   , Bn3 , v076
	.byte	W96
@ 135   ----------------------------------------
	.byte		        Dn4 
	.byte	W96
@ 136   ----------------------------------------
	.byte		        En4 
	.byte	W96
@ 137   ----------------------------------------
	.byte		        Fn4 
	.byte	W96
@ 138   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 139   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 140   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 141   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 142   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 143   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 144   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_002
@ 145   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_001
@ 146   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_008
@ 147   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_009
@ 148   ----------------------------------------
	.byte		TIE   , An3 , v076
	.byte	W96
@ 149   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 150   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_008
@ 151   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_009
@ 152   ----------------------------------------
	.byte		TIE   , An3 , v076
	.byte	W96
@ 153   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 154   ----------------------------------------
	.byte	W96
@ 155   ----------------------------------------
	.byte	W96
@ 156   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 157   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_019
@ 158   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 159   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_019
@ 160   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 161   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_019
@ 162   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_018
@ 163   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_025
@ 164   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_026
@ 165   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_027
@ 166   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_028
@ 167   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_029
@ 168   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_030
@ 169   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_031
@ 170   ----------------------------------------
	.byte		N90   , An3 , v092
	.byte	W96
@ 171   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_033
@ 172   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_026
@ 173   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_027
@ 174   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_028
@ 175   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_1_037
@ 176   ----------------------------------------
	.byte		TIE   , Cn5 , v092
	.byte	W96
@ 177   ----------------------------------------
	.byte	W11
	.byte		EOT   
	.byte	W01
	.byte		N11   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
@ 178   ----------------------------------------
	.byte		TIE   , Cn3 
	.byte	W96
@ 179   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 180   ----------------------------------------
	.byte		N90   , Bn3 , v076
	.byte	W96
@ 181   ----------------------------------------
	.byte		        Dn4 
	.byte	W96
@ 182   ----------------------------------------
	.byte		        En4 
	.byte	W96
@ 183   ----------------------------------------
	.byte		        Fn4 
	.byte	W90
	.byte	GOTO
	 .word	ff6boss_1_B1
ff6boss_1_B2:
	.byte	W06
@ 184   ----------------------------------------
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

ff6boss_2:
	.byte	KEYSH , ff6boss_key+0
ff6boss_2_B1:
@ 000   ----------------------------------------
	.byte		VOICE , 56
	.byte		VOL   , 121*ff6boss_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N11   , En3 , v092
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
@ 001   ----------------------------------------
ff6boss_2_001:
	.byte		N11   , An2 , v092
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
ff6boss_2_002:
	.byte		N11   , En3 , v092
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 004   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 005   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 006   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 008   ----------------------------------------
ff6boss_2_008:
	.byte		N20   , An2 , v092
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N11   , Dn3 
	.byte	W12
	.byte		N20   , Cn3 
	.byte	W24
	.byte		N23   , Bn2 
	.byte	W12
	.byte	PEND
@ 009   ----------------------------------------
ff6boss_2_009:
	.byte	W12
	.byte		N11   , Cn3 , v092
	.byte	W12
	.byte		N20   , Dn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte	PEND
@ 010   ----------------------------------------
	.byte		TIE   , An2 
	.byte	W96
@ 011   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 012   ----------------------------------------
ff6boss_2_012:
	.byte		N11   , An2 , v092
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
@ 013   ----------------------------------------
ff6boss_2_013:
	.byte		N11   , Gn2 , v092
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	PEND
@ 014   ----------------------------------------
	.byte		TIE   , An2 
	.byte	W96
@ 015   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
ff6boss_2_018:
	.byte		N11   , En3 , v092
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
ff6boss_2_019:
	.byte		N20   , Bn2 , v092
	.byte	W24
	.byte		N11   , Cn3 
	.byte	W12
	.byte		N20   , An2 
	.byte	W24
	.byte		N11   , Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte	PEND
@ 020   ----------------------------------------
ff6boss_2_020:
	.byte		N20   , Dn3 , v092
	.byte	W24
	.byte		N11   , En3 
	.byte	W12
	.byte		N20   , Cn3 
	.byte	W24
	.byte		N11   , En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte	PEND
@ 021   ----------------------------------------
ff6boss_2_021:
	.byte		N11   , Fn3 , v092
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PEND
@ 022   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_018
@ 023   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_019
@ 024   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_020
@ 025   ----------------------------------------
ff6boss_2_025:
	.byte		N11   , Fn3 , v092
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	PEND
@ 026   ----------------------------------------
	.byte		N90   , Cn3 
	.byte	W96
@ 027   ----------------------------------------
	.byte		        Dn3 
	.byte	W96
@ 028   ----------------------------------------
ff6boss_2_028:
	.byte		N32   , En3 , v092
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		N20   , Gn3 
	.byte	W24
	.byte	PEND
@ 029   ----------------------------------------
ff6boss_2_029:
	.byte		N20   , En3 , v092
	.byte	W24
	.byte		N11   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		TIE   , Cn3 
	.byte	W12
	.byte	PEND
@ 030   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 031   ----------------------------------------
ff6boss_2_031:
	.byte		N42   , Dn3 , v092
	.byte	W48
	.byte		        Bn2 
	.byte	W48
	.byte	PEND
@ 032   ----------------------------------------
	.byte		TIE   , Dn3 
	.byte	W96
@ 033   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 034   ----------------------------------------
	.byte		N90   , Cn3 
	.byte	W96
@ 035   ----------------------------------------
	.byte		        Dn3 
	.byte	W96
@ 036   ----------------------------------------
ff6boss_2_036:
	.byte		N32   , Cn3 , v092
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		N20   , En3 
	.byte	W24
	.byte	PEND
@ 037   ----------------------------------------
ff6boss_2_037:
	.byte		N32   , Dn3 , v092
	.byte	W36
	.byte		        En3 
	.byte	W36
	.byte		N20   , Fs3 
	.byte	W24
	.byte	PEND
@ 038   ----------------------------------------
	.byte		TIE   , Fn3 
	.byte	W96
@ 039   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 040   ----------------------------------------
	.byte		TIE   , Ds3 
	.byte	W96
@ 041   ----------------------------------------
	.byte	W11
	.byte		EOT   
	.byte	W01
	.byte		N11   , Cn2 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
@ 042   ----------------------------------------
ff6boss_2_042:
	.byte		N32   , Bn2 , v092
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		N20   , Bn2 
	.byte	W24
	.byte	PEND
@ 043   ----------------------------------------
ff6boss_2_043:
	.byte		N32   , Dn3 , v092
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N20   , Dn3 
	.byte	W24
	.byte	PEND
@ 044   ----------------------------------------
ff6boss_2_044:
	.byte		N32   , En3 , v092
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N20   , En3 
	.byte	W24
	.byte	PEND
@ 045   ----------------------------------------
ff6boss_2_045:
	.byte	W12
	.byte		N11   , Fn3 , v092
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte	PEND
@ 046   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 047   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 048   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 049   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 050   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 051   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 052   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 053   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 054   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_008
@ 055   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_009
@ 056   ----------------------------------------
	.byte		TIE   , An2 , v092
	.byte	W96
@ 057   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 058   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_012
@ 059   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_013
@ 060   ----------------------------------------
	.byte		TIE   , An2 , v092
	.byte	W96
@ 061   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_018
@ 065   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_019
@ 066   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_020
@ 067   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_021
@ 068   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_018
@ 069   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_019
@ 070   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_020
@ 071   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_025
@ 072   ----------------------------------------
	.byte		N90   , Cn3 , v092
	.byte	W96
@ 073   ----------------------------------------
	.byte		        Dn3 
	.byte	W96
@ 074   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_028
@ 075   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_029
@ 076   ----------------------------------------
	.byte	W90
	.byte		EOT   , Cn3 
	.byte	W06
@ 077   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_031
@ 078   ----------------------------------------
	.byte		TIE   , Dn3 , v092
	.byte	W96
@ 079   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 080   ----------------------------------------
	.byte		N90   , Cn3 
	.byte	W96
@ 081   ----------------------------------------
	.byte		        Dn3 
	.byte	W96
@ 082   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_036
@ 083   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_037
@ 084   ----------------------------------------
	.byte		TIE   , Fn3 , v092
	.byte	W96
@ 085   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 086   ----------------------------------------
	.byte		TIE   , Ds3 
	.byte	W96
@ 087   ----------------------------------------
	.byte	W11
	.byte		EOT   
	.byte	W01
	.byte		N11   , Cn2 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
@ 088   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_042
@ 089   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_043
@ 090   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_044
@ 091   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_045
@ 092   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 093   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 094   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 095   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 096   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 097   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 098   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 099   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 100   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_008
@ 101   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_009
@ 102   ----------------------------------------
	.byte		TIE   , An2 , v092
	.byte	W96
@ 103   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 104   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_012
@ 105   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_013
@ 106   ----------------------------------------
	.byte		TIE   , An2 , v092
	.byte	W96
@ 107   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 108   ----------------------------------------
	.byte	W96
@ 109   ----------------------------------------
	.byte	W96
@ 110   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_018
@ 111   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_019
@ 112   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_020
@ 113   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_021
@ 114   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_018
@ 115   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_019
@ 116   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_020
@ 117   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_025
@ 118   ----------------------------------------
	.byte		N90   , Cn3 , v092
	.byte	W96
@ 119   ----------------------------------------
	.byte		        Dn3 
	.byte	W96
@ 120   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_028
@ 121   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_029
@ 122   ----------------------------------------
	.byte	W90
	.byte		EOT   , Cn3 
	.byte	W06
@ 123   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_031
@ 124   ----------------------------------------
	.byte		TIE   , Dn3 , v092
	.byte	W96
@ 125   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 126   ----------------------------------------
	.byte		N90   , Cn3 
	.byte	W96
@ 127   ----------------------------------------
	.byte		        Dn3 
	.byte	W96
@ 128   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_036
@ 129   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_037
@ 130   ----------------------------------------
	.byte		TIE   , Fn3 , v092
	.byte	W96
@ 131   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 132   ----------------------------------------
	.byte		TIE   , Ds3 
	.byte	W96
@ 133   ----------------------------------------
	.byte	W11
	.byte		EOT   
	.byte	W01
	.byte		N11   , Cn2 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
@ 134   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_042
@ 135   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_043
@ 136   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_044
@ 137   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_045
@ 138   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 139   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 140   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 141   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 142   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 143   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 144   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_002
@ 145   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_001
@ 146   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_008
@ 147   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_009
@ 148   ----------------------------------------
	.byte		TIE   , An2 , v092
	.byte	W96
@ 149   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 150   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_012
@ 151   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_013
@ 152   ----------------------------------------
	.byte		TIE   , An2 , v092
	.byte	W96
@ 153   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 154   ----------------------------------------
	.byte	W96
@ 155   ----------------------------------------
	.byte	W96
@ 156   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_018
@ 157   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_019
@ 158   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_020
@ 159   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_021
@ 160   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_018
@ 161   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_019
@ 162   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_020
@ 163   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_025
@ 164   ----------------------------------------
	.byte		N90   , Cn3 , v092
	.byte	W96
@ 165   ----------------------------------------
	.byte		        Dn3 
	.byte	W96
@ 166   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_028
@ 167   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_029
@ 168   ----------------------------------------
	.byte	W90
	.byte		EOT   , Cn3 
	.byte	W06
@ 169   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_031
@ 170   ----------------------------------------
	.byte		TIE   , Dn3 , v092
	.byte	W96
@ 171   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 172   ----------------------------------------
	.byte		N90   , Cn3 
	.byte	W96
@ 173   ----------------------------------------
	.byte		        Dn3 
	.byte	W96
@ 174   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_036
@ 175   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_037
@ 176   ----------------------------------------
	.byte		TIE   , Fn3 , v092
	.byte	W96
@ 177   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 178   ----------------------------------------
	.byte		TIE   , Ds3 
	.byte	W96
@ 179   ----------------------------------------
	.byte	W11
	.byte		EOT   
	.byte	W01
	.byte		N11   , Cn2 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
@ 180   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_042
@ 181   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_043
@ 182   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_2_044
@ 183   ----------------------------------------
	.byte	W12
	.byte		N11   , Fn3 , v092
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W06
	.byte	GOTO
	 .word	ff6boss_2_B1
ff6boss_2_B2:
	.byte	W06
@ 184   ----------------------------------------
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

ff6boss_3:
	.byte	KEYSH , ff6boss_key+0
ff6boss_3_B1:
@ 000   ----------------------------------------
	.byte		VOICE , 38
	.byte		VOL   , 115*ff6boss_mvl/mxv
	.byte		PAN   , c_v+34
	.byte		TIE   , An0 , v092
	.byte	W96
@ 001   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 002   ----------------------------------------
ff6boss_3_002:
	.byte		N11   , An0 , v092
	.byte	W36
	.byte		TIE   
	.byte	W60
	.byte	PEND
@ 003   ----------------------------------------
	.byte	W42
	.byte		EOT   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N11   , En1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
@ 004   ----------------------------------------
ff6boss_3_004:
	.byte		N11   , An0 , v092
	.byte	W36
	.byte		N11   
	.byte	W36
	.byte		N11   
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
ff6boss_3_005:
	.byte	W12
	.byte		N11   , An0 , v092
	.byte	W36
	.byte		N20   
	.byte	W24
	.byte		        Gn0 
	.byte	W24
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 007   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 008   ----------------------------------------
ff6boss_3_008:
	.byte		N42   , Fn0 , v092
	.byte	W48
	.byte		N32   , Gn0 
	.byte	W36
	.byte		N23   , En0 
	.byte	W12
	.byte	PEND
@ 009   ----------------------------------------
ff6boss_3_009:
	.byte	W12
	.byte		N11   , En1 , v092
	.byte	W12
	.byte		N20   , Bn0 
	.byte	W24
	.byte		        Fn0 
	.byte	W24
	.byte		        Gn0 
	.byte	W24
	.byte	PEND
@ 010   ----------------------------------------
ff6boss_3_010:
	.byte		N42   , An0 , v092
	.byte	W48
	.byte		        Bn0 
	.byte	W48
	.byte	PEND
@ 011   ----------------------------------------
ff6boss_3_011:
	.byte		N42   , Cn1 , v092
	.byte	W48
	.byte		        En1 
	.byte	W48
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_008
@ 013   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_009
@ 014   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 015   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 016   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 017   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 018   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 019   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 020   ----------------------------------------
ff6boss_3_020:
	.byte		N11   , Fn0 , v092
	.byte	W36
	.byte		N11   
	.byte	W36
	.byte		        En0 
	.byte	W24
	.byte	PEND
@ 021   ----------------------------------------
ff6boss_3_021:
	.byte	W12
	.byte		N11   , Dn0 , v092
	.byte	W36
	.byte		N20   , En0 
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 022   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 023   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 024   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_020
@ 025   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_021
@ 026   ----------------------------------------
ff6boss_3_026:
	.byte		N66   , Fn0 , v092
	.byte	W72
	.byte		N20   , Fs0 
	.byte	W24
	.byte	PEND
@ 027   ----------------------------------------
ff6boss_3_027:
	.byte		N32   , Gn0 , v092
	.byte	W36
	.byte		        Dn0 
	.byte	W36
	.byte		N20   , Gn0 
	.byte	W24
	.byte	PEND
@ 028   ----------------------------------------
ff6boss_3_028:
	.byte		N32   , An0 , v092
	.byte	W36
	.byte		N54   , Gn0 
	.byte	W60
	.byte	PEND
@ 029   ----------------------------------------
ff6boss_3_029:
	.byte		N32   , En0 , v092
	.byte	W36
	.byte		N42   , Gn0 
	.byte	W48
	.byte		N78   , Fn0 
	.byte	W12
	.byte	PEND
@ 030   ----------------------------------------
	.byte	W72
	.byte		N20   , Fs0 
	.byte	W24
@ 031   ----------------------------------------
ff6boss_3_031:
	.byte		N32   , Gn0 , v092
	.byte	W36
	.byte		        Bn0 
	.byte	W36
	.byte		N20   , Gn0 
	.byte	W24
	.byte	PEND
@ 032   ----------------------------------------
ff6boss_3_032:
	.byte		N32   , Dn0 , v092
	.byte	W36
	.byte		        An0 
	.byte	W36
	.byte		N44   , Dn1 
	.byte	W24
	.byte	PEND
@ 033   ----------------------------------------
ff6boss_3_033:
	.byte	W24
	.byte		N20   , Cn1 , v092
	.byte	W24
	.byte		        Bn0 
	.byte	W24
	.byte		        An0 
	.byte	W24
	.byte	PEND
@ 034   ----------------------------------------
ff6boss_3_034:
	.byte		N66   , Fn0 , v092
	.byte	W72
	.byte		N20   , An0 
	.byte	W24
	.byte	PEND
@ 035   ----------------------------------------
ff6boss_3_035:
	.byte		N32   , En0 , v092
	.byte	W36
	.byte		        En1 
	.byte	W36
	.byte		N20   , Dn1 
	.byte	W24
	.byte	PEND
@ 036   ----------------------------------------
ff6boss_3_036:
	.byte		N32   , Cn1 , v092
	.byte	W36
	.byte		        Gn0 
	.byte	W36
	.byte		N20   , En1 
	.byte	W24
	.byte	PEND
@ 037   ----------------------------------------
ff6boss_3_037:
	.byte		N32   , Dn1 , v092
	.byte	W36
	.byte		        An0 
	.byte	W36
	.byte		N20   , Fs0 
	.byte	W24
	.byte	PEND
@ 038   ----------------------------------------
ff6boss_3_038:
	.byte		N66   , Fn0 , v092
	.byte	W72
	.byte		N20   , Cn1 
	.byte	W24
	.byte	PEND
@ 039   ----------------------------------------
ff6boss_3_039:
	.byte		N20   , Fn1 , v092
	.byte	W24
	.byte		N11   , En1 
	.byte	W12
	.byte		N20   , Fn1 
	.byte	W24
	.byte		N11   , En1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
@ 040   ----------------------------------------
ff6boss_3_040:
	.byte		N66   , Fs0 , v092
	.byte	W72
	.byte		N20   , Cn1 
	.byte	W24
	.byte	PEND
@ 041   ----------------------------------------
ff6boss_3_041:
	.byte		N42   , Ds1 , v092
	.byte	W48
	.byte		        Fs1 
	.byte	W48
	.byte	PEND
@ 042   ----------------------------------------
ff6boss_3_042:
	.byte		N32   , Gn0 , v092
	.byte	W36
	.byte		        Gn1 
	.byte	W36
	.byte		N20   , Fs1 
	.byte	W24
	.byte	PEND
@ 043   ----------------------------------------
ff6boss_3_043:
	.byte		N32   , Fn1 , v092
	.byte	W36
	.byte		N54   , Fn0 
	.byte	W60
	.byte	PEND
@ 044   ----------------------------------------
ff6boss_3_044:
	.byte		N32   , En0 , v092
	.byte	W36
	.byte		        En1 
	.byte	W36
	.byte		N20   , Ds1 
	.byte	W24
	.byte	PEND
@ 045   ----------------------------------------
ff6boss_3_045:
	.byte		N32   , Dn1 , v092
	.byte	W36
	.byte		N54   , Dn0 
	.byte	W60
	.byte	PEND
@ 046   ----------------------------------------
ff6boss_3_046:
	.byte		PAN   , c_v+34
	.byte		TIE   , An0 , v092
	.byte	W96
	.byte	PEND
@ 047   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 048   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_002
@ 049   ----------------------------------------
	.byte	W42
	.byte		EOT   , An0 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N11   , En1 , v092
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
@ 050   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 051   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 052   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 053   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 054   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_008
@ 055   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_009
@ 056   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_010
@ 057   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_011
@ 058   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_008
@ 059   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_009
@ 060   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 061   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 062   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 063   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 064   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 065   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 066   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_020
@ 067   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_021
@ 068   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 069   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 070   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_020
@ 071   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_021
@ 072   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_026
@ 073   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_027
@ 074   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_028
@ 075   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_029
@ 076   ----------------------------------------
	.byte	W72
	.byte		N20   , Fs0 , v092
	.byte	W24
@ 077   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_031
@ 078   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_032
@ 079   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_033
@ 080   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_034
@ 081   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_035
@ 082   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_036
@ 083   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_037
@ 084   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_038
@ 085   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_039
@ 086   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_040
@ 087   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_041
@ 088   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_042
@ 089   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_043
@ 090   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_044
@ 091   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_045
@ 092   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_046
@ 093   ----------------------------------------
	.byte	W90
	.byte		EOT   , An0 
	.byte	W06
@ 094   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_002
@ 095   ----------------------------------------
	.byte	W42
	.byte		EOT   , An0 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N11   , En1 , v092
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
@ 096   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 097   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 098   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 099   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 100   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_008
@ 101   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_009
@ 102   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_010
@ 103   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_011
@ 104   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_008
@ 105   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_009
@ 106   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 107   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 108   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 109   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 110   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 111   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 112   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_020
@ 113   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_021
@ 114   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 115   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 116   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_020
@ 117   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_021
@ 118   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_026
@ 119   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_027
@ 120   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_028
@ 121   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_029
@ 122   ----------------------------------------
	.byte	W72
	.byte		N20   , Fs0 , v092
	.byte	W24
@ 123   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_031
@ 124   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_032
@ 125   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_033
@ 126   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_034
@ 127   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_035
@ 128   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_036
@ 129   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_037
@ 130   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_038
@ 131   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_039
@ 132   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_040
@ 133   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_041
@ 134   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_042
@ 135   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_043
@ 136   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_044
@ 137   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_045
@ 138   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_046
@ 139   ----------------------------------------
	.byte	W90
	.byte		EOT   , An0 
	.byte	W06
@ 140   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_002
@ 141   ----------------------------------------
	.byte	W42
	.byte		EOT   , An0 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N11   , En1 , v092
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
@ 142   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 143   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 144   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 145   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 146   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_008
@ 147   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_009
@ 148   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_010
@ 149   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_011
@ 150   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_008
@ 151   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_009
@ 152   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 153   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 154   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 155   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 156   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 157   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 158   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_020
@ 159   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_021
@ 160   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_004
@ 161   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_005
@ 162   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_020
@ 163   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_021
@ 164   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_026
@ 165   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_027
@ 166   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_028
@ 167   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_029
@ 168   ----------------------------------------
	.byte	W72
	.byte		N20   , Fs0 , v092
	.byte	W24
@ 169   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_031
@ 170   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_032
@ 171   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_033
@ 172   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_034
@ 173   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_035
@ 174   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_036
@ 175   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_037
@ 176   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_038
@ 177   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_039
@ 178   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_040
@ 179   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_041
@ 180   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_042
@ 181   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_043
@ 182   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_3_044
@ 183   ----------------------------------------
	.byte		N32   , Dn1 , v092
	.byte	W36
	.byte		N54   , Dn0 
	.byte	W54
	.byte	GOTO
	 .word	ff6boss_3_B1
ff6boss_3_B2:
	.byte	W06
@ 184   ----------------------------------------
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

ff6boss_4:
	.byte	KEYSH , ff6boss_key+0
ff6boss_4_B1:
@ 000   ----------------------------------------
	.byte		VOICE , 30
	.byte		VOL   , 97*ff6boss_mvl/mxv
	.byte		PAN   , c_v-34
	.byte		N11   , An3 , v076
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
@ 001   ----------------------------------------
ff6boss_4_001:
	.byte		N11   , Cn3 , v076
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
ff6boss_4_002:
	.byte		N11   , An3 , v076
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 004   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 005   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 006   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 008   ----------------------------------------
ff6boss_4_008:
	.byte		N20   , Fn3 , v076
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N11   , Bn3 
	.byte	W12
	.byte		N20   , An3 
	.byte	W24
	.byte		N23   , Gn3 
	.byte	W12
	.byte	PEND
@ 009   ----------------------------------------
ff6boss_4_009:
	.byte	W12
	.byte		N11   , An3 , v076
	.byte	W12
	.byte		N20   , Bn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte	PEND
@ 010   ----------------------------------------
	.byte		TIE   , En3 
	.byte	W96
@ 011   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 012   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_008
@ 013   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_009
@ 014   ----------------------------------------
	.byte		TIE   , En3 , v076
	.byte	W96
@ 015   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
ff6boss_4_018:
	.byte		N11   , En3 , v076
	.byte	W12
	.byte		        En3 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        En3 , v076
	.byte	W12
	.byte		        En3 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        En3 , v076
	.byte	W12
	.byte		        En3 , v060
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
ff6boss_4_019:
	.byte		N11   , En3 , v060
	.byte	W12
	.byte		        En3 , v076
	.byte	W12
	.byte		        En3 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N20   , En3 , v076
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 020   ----------------------------------------
ff6boss_4_020:
	.byte		N11   , Fn3 , v076
	.byte	W12
	.byte		        Fn3 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Fn3 , v076
	.byte	W12
	.byte		        Fn3 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Gn3 , v076
	.byte	W12
	.byte		        Gn3 , v060
	.byte	W12
	.byte	PEND
@ 021   ----------------------------------------
ff6boss_4_021:
	.byte		N11   , Gn3 , v060
	.byte	W12
	.byte		        Fn3 , v076
	.byte	W12
	.byte		        Fn3 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N20   , En3 , v076
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 022   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_018
@ 023   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_019
@ 024   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_020
@ 025   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_021
@ 026   ----------------------------------------
ff6boss_4_026:
	.byte		PAN   , c_v+34
	.byte		N66   , Fn1 , v092
	.byte	W72
	.byte		N20   , Fs1 
	.byte	W24
	.byte	PEND
@ 027   ----------------------------------------
	.byte		N90   , Gn1 
	.byte	W96
@ 028   ----------------------------------------
ff6boss_4_028:
	.byte		N32   , An1 , v092
	.byte	W36
	.byte		N54   , Gn1 
	.byte	W60
	.byte	PEND
@ 029   ----------------------------------------
ff6boss_4_029:
	.byte		N32   , En1 , v092
	.byte	W36
	.byte		N42   , Gn1 
	.byte	W48
	.byte		N78   , Fn1 
	.byte	W12
	.byte	PEND
@ 030   ----------------------------------------
	.byte	W72
	.byte		N20   , Fs1 
	.byte	W24
@ 031   ----------------------------------------
	.byte		N90   , Gn1 
	.byte	W96
@ 032   ----------------------------------------
ff6boss_4_032:
	.byte		N20   , An1 , v076
	.byte	W24
	.byte		N11   , An1 , v060
	.byte	W12
	.byte		N20   , An1 , v076
	.byte	W24
	.byte		N11   , An1 , v060
	.byte	W12
	.byte		N20   , An1 , v076
	.byte	W24
	.byte	PEND
@ 033   ----------------------------------------
ff6boss_4_033:
	.byte		N11   , An1 , v060
	.byte	W12
	.byte		N20   , An1 , v076
	.byte	W24
	.byte		N11   , An1 , v060
	.byte	W12
	.byte		N20   , An1 , v076
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte	PEND
@ 034   ----------------------------------------
ff6boss_4_034:
	.byte		N66   , Fn1 , v076
	.byte	W72
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 035   ----------------------------------------
	.byte		N90   , En1 
	.byte	W96
@ 036   ----------------------------------------
ff6boss_4_036:
	.byte		N32   , Cn2 , v076
	.byte	W36
	.byte		N54   , Gn1 
	.byte	W60
	.byte	PEND
@ 037   ----------------------------------------
ff6boss_4_037:
	.byte		N32   , An1 , v076
	.byte	W36
	.byte		N54   , Fs1 
	.byte	W60
	.byte	PEND
@ 038   ----------------------------------------
ff6boss_4_038:
	.byte		N20   , Fn1 , v076
	.byte	W24
	.byte		N11   , Fn1 , v060
	.byte	W12
	.byte		N20   , Fn1 , v076
	.byte	W24
	.byte		N11   , Fn1 , v060
	.byte	W12
	.byte		N20   , Fn1 , v076
	.byte	W24
	.byte	PEND
@ 039   ----------------------------------------
ff6boss_4_039:
	.byte		N11   , Fn1 , v060
	.byte	W12
	.byte		N20   , Fn1 , v076
	.byte	W24
	.byte		N11   , Fn1 , v060
	.byte	W12
	.byte		N20   , Fn1 , v076
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 040   ----------------------------------------
ff6boss_4_040:
	.byte		N20   , Fs1 , v076
	.byte	W24
	.byte		N11   , Fs1 , v060
	.byte	W12
	.byte		N20   , Fs1 , v076
	.byte	W24
	.byte		N11   , Fs1 , v060
	.byte	W12
	.byte		N20   , Fs1 , v076
	.byte	W24
	.byte	PEND
@ 041   ----------------------------------------
ff6boss_4_041:
	.byte		N11   , Fs1 , v060
	.byte	W12
	.byte		N20   , Fs1 , v076
	.byte	W24
	.byte		N11   , Fs1 , v060
	.byte	W12
	.byte		N20   , Fs1 , v076
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 042   ----------------------------------------
ff6boss_4_042:
	.byte		PAN   , c_v-34
	.byte		N90   , Gn3 , v076
	.byte	W96
	.byte	PEND
@ 043   ----------------------------------------
	.byte		        An3 
	.byte	W96
@ 044   ----------------------------------------
	.byte		        Cn4 
	.byte	W96
@ 045   ----------------------------------------
	.byte		        Dn4 
	.byte	W96
@ 046   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 047   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 048   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 049   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 050   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 051   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 052   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 053   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 054   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_008
@ 055   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_009
@ 056   ----------------------------------------
	.byte		TIE   , En3 , v076
	.byte	W96
@ 057   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 058   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_008
@ 059   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_009
@ 060   ----------------------------------------
	.byte		TIE   , En3 , v076
	.byte	W96
@ 061   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_018
@ 065   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_019
@ 066   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_020
@ 067   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_021
@ 068   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_018
@ 069   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_019
@ 070   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_020
@ 071   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_021
@ 072   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_026
@ 073   ----------------------------------------
	.byte		N90   , Gn1 , v092
	.byte	W96
@ 074   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_028
@ 075   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_029
@ 076   ----------------------------------------
	.byte	W72
	.byte		N20   , Fs1 , v092
	.byte	W24
@ 077   ----------------------------------------
	.byte		N90   , Gn1 
	.byte	W96
@ 078   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_032
@ 079   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_033
@ 080   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_034
@ 081   ----------------------------------------
	.byte		N90   , En1 , v076
	.byte	W96
@ 082   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_036
@ 083   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_037
@ 084   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_038
@ 085   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_039
@ 086   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_040
@ 087   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_041
@ 088   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_042
@ 089   ----------------------------------------
	.byte		N90   , An3 , v076
	.byte	W96
@ 090   ----------------------------------------
	.byte		        Cn4 
	.byte	W96
@ 091   ----------------------------------------
	.byte		        Dn4 
	.byte	W96
@ 092   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 093   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 094   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 095   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 096   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 097   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 098   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 099   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 100   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_008
@ 101   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_009
@ 102   ----------------------------------------
	.byte		TIE   , En3 , v076
	.byte	W96
@ 103   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 104   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_008
@ 105   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_009
@ 106   ----------------------------------------
	.byte		TIE   , En3 , v076
	.byte	W96
@ 107   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 108   ----------------------------------------
	.byte	W96
@ 109   ----------------------------------------
	.byte	W96
@ 110   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_018
@ 111   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_019
@ 112   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_020
@ 113   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_021
@ 114   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_018
@ 115   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_019
@ 116   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_020
@ 117   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_021
@ 118   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_026
@ 119   ----------------------------------------
	.byte		N90   , Gn1 , v092
	.byte	W96
@ 120   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_028
@ 121   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_029
@ 122   ----------------------------------------
	.byte	W72
	.byte		N20   , Fs1 , v092
	.byte	W24
@ 123   ----------------------------------------
	.byte		N90   , Gn1 
	.byte	W96
@ 124   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_032
@ 125   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_033
@ 126   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_034
@ 127   ----------------------------------------
	.byte		N90   , En1 , v076
	.byte	W96
@ 128   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_036
@ 129   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_037
@ 130   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_038
@ 131   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_039
@ 132   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_040
@ 133   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_041
@ 134   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_042
@ 135   ----------------------------------------
	.byte		N90   , An3 , v076
	.byte	W96
@ 136   ----------------------------------------
	.byte		        Cn4 
	.byte	W96
@ 137   ----------------------------------------
	.byte		        Dn4 
	.byte	W96
@ 138   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 139   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 140   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 141   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 142   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 143   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 144   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_002
@ 145   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_001
@ 146   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_008
@ 147   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_009
@ 148   ----------------------------------------
	.byte		TIE   , En3 , v076
	.byte	W96
@ 149   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 150   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_008
@ 151   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_009
@ 152   ----------------------------------------
	.byte		TIE   , En3 , v076
	.byte	W96
@ 153   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 154   ----------------------------------------
	.byte	W96
@ 155   ----------------------------------------
	.byte	W96
@ 156   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_018
@ 157   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_019
@ 158   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_020
@ 159   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_021
@ 160   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_018
@ 161   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_019
@ 162   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_020
@ 163   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_021
@ 164   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_026
@ 165   ----------------------------------------
	.byte		N90   , Gn1 , v092
	.byte	W96
@ 166   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_028
@ 167   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_029
@ 168   ----------------------------------------
	.byte	W72
	.byte		N20   , Fs1 , v092
	.byte	W24
@ 169   ----------------------------------------
	.byte		N90   , Gn1 
	.byte	W96
@ 170   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_032
@ 171   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_033
@ 172   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_034
@ 173   ----------------------------------------
	.byte		N90   , En1 , v076
	.byte	W96
@ 174   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_036
@ 175   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_037
@ 176   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_038
@ 177   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_039
@ 178   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_040
@ 179   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_041
@ 180   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_4_042
@ 181   ----------------------------------------
	.byte		N90   , An3 , v076
	.byte	W96
@ 182   ----------------------------------------
	.byte		        Cn4 
	.byte	W96
@ 183   ----------------------------------------
	.byte		        Dn4 
	.byte	W90
	.byte	GOTO
	 .word	ff6boss_4_B1
ff6boss_4_B2:
	.byte	W06
@ 184   ----------------------------------------
	.byte	FINE

@**************** Track 5 (Midi-Chn.5) ****************@

ff6boss_5:
	.byte	KEYSH , ff6boss_key+0
ff6boss_5_B1:
@ 000   ----------------------------------------
	.byte		VOICE , 17
	.byte		VOL   , 103*ff6boss_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		TIE   , An1 , v092
	.byte	W96
@ 001   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 002   ----------------------------------------
	.byte		N11   
	.byte	W36
	.byte		TIE   
	.byte	W60
@ 003   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 004   ----------------------------------------
ff6boss_5_004:
	.byte		N11   , An1 , v092
	.byte	W36
	.byte		N11   
	.byte	W36
	.byte		N11   
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
ff6boss_5_005:
	.byte	W12
	.byte		N11   , An1 , v092
	.byte	W36
	.byte		N20   
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_004
@ 007   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_005
@ 008   ----------------------------------------
ff6boss_5_008:
	.byte		N42   , Fn1 , v092
	.byte	W48
	.byte		N32   , Gn1 
	.byte	W36
	.byte		TIE   , En1 
	.byte	W12
	.byte	PEND
@ 009   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 010   ----------------------------------------
	.byte		TIE   , An1 
	.byte	W96
@ 011   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 012   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_008
@ 013   ----------------------------------------
	.byte	W90
	.byte		EOT   , En1 
	.byte	W06
@ 014   ----------------------------------------
	.byte		TIE   , An1 , v092
	.byte	W96
@ 015   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
ff6boss_5_018:
	.byte		N11   , An1 , v076
	.byte	W12
	.byte		        An1 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		        An1 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		        An1 , v060
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
ff6boss_5_019:
	.byte		N11   , An1 , v060
	.byte	W12
	.byte		        An1 , v076
	.byte	W12
	.byte		        An1 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N20   , An1 , v076
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte	PEND
@ 020   ----------------------------------------
ff6boss_5_020:
	.byte		N11   , Fn1 , v076
	.byte	W12
	.byte		        Fn1 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Fn1 , v076
	.byte	W12
	.byte		        Fn1 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        En1 , v076
	.byte	W12
	.byte		        En1 , v060
	.byte	W12
	.byte	PEND
@ 021   ----------------------------------------
ff6boss_5_021:
	.byte		N11   , En1 , v060
	.byte	W12
	.byte		        Dn1 , v076
	.byte	W12
	.byte		        Dn1 , v060
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N20   , En1 , v076
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 022   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_018
@ 023   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_019
@ 024   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_020
@ 025   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_021
@ 026   ----------------------------------------
ff6boss_5_026:
	.byte		PAN   , c_v+34
	.byte		N90   , An2 , v076
	.byte	W96
	.byte	PEND
@ 027   ----------------------------------------
	.byte		        Gn2 
	.byte	W96
@ 028   ----------------------------------------
ff6boss_5_028:
	.byte		N32   , Cn3 , v076
	.byte	W36
	.byte		        Bn2 
	.byte	W36
	.byte		N20   , Dn3 
	.byte	W24
	.byte	PEND
@ 029   ----------------------------------------
ff6boss_5_029:
	.byte		N42   , Cn3 , v076
	.byte	W48
	.byte		N32   , Bn2 
	.byte	W36
	.byte		TIE   , An2 
	.byte	W12
	.byte	PEND
@ 030   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 031   ----------------------------------------
ff6boss_5_031:
	.byte		N42   , Bn2 , v076
	.byte	W48
	.byte		        Gn2 
	.byte	W48
	.byte	PEND
@ 032   ----------------------------------------
ff6boss_5_032:
	.byte		N42   , An2 , v076
	.byte	W48
	.byte		        Gn2 
	.byte	W48
	.byte	PEND
@ 033   ----------------------------------------
	.byte		N90   , Fs2 
	.byte	W96
@ 034   ----------------------------------------
	.byte		        An2 
	.byte	W96
@ 035   ----------------------------------------
	.byte		        Gn2 
	.byte	W96
@ 036   ----------------------------------------
ff6boss_5_036:
	.byte		N32   , Gn2 , v076
	.byte	W36
	.byte		N32   
	.byte	W36
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 037   ----------------------------------------
ff6boss_5_037:
	.byte		N32   , An2 , v076
	.byte	W36
	.byte		N32   
	.byte	W36
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 038   ----------------------------------------
	.byte		TIE   
	.byte	W96
@ 039   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 040   ----------------------------------------
	.byte		TIE   
	.byte	W96
@ 041   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 042   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_036
@ 043   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_037
@ 044   ----------------------------------------
ff6boss_5_044:
	.byte		N32   , Cn3 , v076
	.byte	W36
	.byte		N32   
	.byte	W36
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 045   ----------------------------------------
ff6boss_5_045:
	.byte	W12
	.byte		N11   , Dn3 , v076
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	PEND
@ 046   ----------------------------------------
ff6boss_5_046:
	.byte		PAN   , c_v+0
	.byte		TIE   , An1 , v076
	.byte	W96
	.byte	PEND
@ 047   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 048   ----------------------------------------
ff6boss_5_048:
	.byte		N11   , An1 , v076
	.byte	W36
	.byte		TIE   
	.byte	W60
	.byte	PEND
@ 049   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 050   ----------------------------------------
ff6boss_5_050:
	.byte		N11   , An1 , v076
	.byte	W36
	.byte		N11   
	.byte	W36
	.byte		N11   
	.byte	W24
	.byte	PEND
@ 051   ----------------------------------------
ff6boss_5_051:
	.byte	W12
	.byte		N11   , An1 , v076
	.byte	W36
	.byte		N20   
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte	PEND
@ 052   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_050
@ 053   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_051
@ 054   ----------------------------------------
ff6boss_5_054:
	.byte		N42   , Fn1 , v076
	.byte	W48
	.byte		N32   , Gn1 
	.byte	W36
	.byte		TIE   , En1 
	.byte	W12
	.byte	PEND
@ 055   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 056   ----------------------------------------
	.byte		TIE   , An1 
	.byte	W96
@ 057   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 058   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_054
@ 059   ----------------------------------------
	.byte	W90
	.byte		EOT   , En1 
	.byte	W06
@ 060   ----------------------------------------
	.byte		TIE   , An1 , v076
	.byte	W96
@ 061   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_018
@ 065   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_019
@ 066   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_020
@ 067   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_021
@ 068   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_018
@ 069   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_019
@ 070   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_020
@ 071   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_021
@ 072   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_026
@ 073   ----------------------------------------
	.byte		N90   , Gn2 , v076
	.byte	W96
@ 074   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_028
@ 075   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_029
@ 076   ----------------------------------------
	.byte	W90
	.byte		EOT   , An2 
	.byte	W06
@ 077   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_031
@ 078   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_032
@ 079   ----------------------------------------
	.byte		N90   , Fs2 , v076
	.byte	W96
@ 080   ----------------------------------------
	.byte		        An2 
	.byte	W96
@ 081   ----------------------------------------
	.byte		        Gn2 
	.byte	W96
@ 082   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_036
@ 083   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_037
@ 084   ----------------------------------------
	.byte		TIE   , An2 , v076
	.byte	W96
@ 085   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 086   ----------------------------------------
	.byte		TIE   
	.byte	W96
@ 087   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 088   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_036
@ 089   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_037
@ 090   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_044
@ 091   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_045
@ 092   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_046
@ 093   ----------------------------------------
	.byte	W90
	.byte		EOT   , An1 
	.byte	W06
@ 094   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_048
@ 095   ----------------------------------------
	.byte	W90
	.byte		EOT   , An1 
	.byte	W06
@ 096   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_050
@ 097   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_051
@ 098   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_050
@ 099   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_051
@ 100   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_054
@ 101   ----------------------------------------
	.byte	W90
	.byte		EOT   , En1 
	.byte	W06
@ 102   ----------------------------------------
	.byte		TIE   , An1 , v076
	.byte	W96
@ 103   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 104   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_054
@ 105   ----------------------------------------
	.byte	W90
	.byte		EOT   , En1 
	.byte	W06
@ 106   ----------------------------------------
	.byte		TIE   , An1 , v076
	.byte	W96
@ 107   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 108   ----------------------------------------
	.byte	W96
@ 109   ----------------------------------------
	.byte	W96
@ 110   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_018
@ 111   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_019
@ 112   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_020
@ 113   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_021
@ 114   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_018
@ 115   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_019
@ 116   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_020
@ 117   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_021
@ 118   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_026
@ 119   ----------------------------------------
	.byte		N90   , Gn2 , v076
	.byte	W96
@ 120   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_028
@ 121   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_029
@ 122   ----------------------------------------
	.byte	W90
	.byte		EOT   , An2 
	.byte	W06
@ 123   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_031
@ 124   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_032
@ 125   ----------------------------------------
	.byte		N90   , Fs2 , v076
	.byte	W96
@ 126   ----------------------------------------
	.byte		        An2 
	.byte	W96
@ 127   ----------------------------------------
	.byte		        Gn2 
	.byte	W96
@ 128   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_036
@ 129   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_037
@ 130   ----------------------------------------
	.byte		TIE   , An2 , v076
	.byte	W96
@ 131   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 132   ----------------------------------------
	.byte		TIE   
	.byte	W96
@ 133   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 134   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_036
@ 135   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_037
@ 136   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_044
@ 137   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_045
@ 138   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_046
@ 139   ----------------------------------------
	.byte	W90
	.byte		EOT   , An1 
	.byte	W06
@ 140   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_048
@ 141   ----------------------------------------
	.byte	W90
	.byte		EOT   , An1 
	.byte	W06
@ 142   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_050
@ 143   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_051
@ 144   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_050
@ 145   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_051
@ 146   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_054
@ 147   ----------------------------------------
	.byte	W90
	.byte		EOT   , En1 
	.byte	W06
@ 148   ----------------------------------------
	.byte		TIE   , An1 , v076
	.byte	W96
@ 149   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 150   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_054
@ 151   ----------------------------------------
	.byte	W90
	.byte		EOT   , En1 
	.byte	W06
@ 152   ----------------------------------------
	.byte		TIE   , An1 , v076
	.byte	W96
@ 153   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 154   ----------------------------------------
	.byte	W96
@ 155   ----------------------------------------
	.byte	W96
@ 156   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_018
@ 157   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_019
@ 158   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_020
@ 159   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_021
@ 160   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_018
@ 161   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_019
@ 162   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_020
@ 163   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_021
@ 164   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_026
@ 165   ----------------------------------------
	.byte		N90   , Gn2 , v076
	.byte	W96
@ 166   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_028
@ 167   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_029
@ 168   ----------------------------------------
	.byte	W90
	.byte		EOT   , An2 
	.byte	W06
@ 169   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_031
@ 170   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_032
@ 171   ----------------------------------------
	.byte		N90   , Fs2 , v076
	.byte	W96
@ 172   ----------------------------------------
	.byte		        An2 
	.byte	W96
@ 173   ----------------------------------------
	.byte		        Gn2 
	.byte	W96
@ 174   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_036
@ 175   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_037
@ 176   ----------------------------------------
	.byte		TIE   , An2 , v076
	.byte	W96
@ 177   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 178   ----------------------------------------
	.byte		TIE   
	.byte	W96
@ 179   ----------------------------------------
	.byte	W90
	.byte		EOT   
	.byte	W06
@ 180   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_036
@ 181   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_037
@ 182   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_5_044
@ 183   ----------------------------------------
	.byte	W12
	.byte		N11   , Dn3 , v076
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte	GOTO
	 .word	ff6boss_5_B1
ff6boss_5_B2:
	.byte	W06
@ 184   ----------------------------------------
	.byte		PAN   , c_v+0
	.byte	FINE

@**************** Track 6 (Midi-Chn.6) ****************@

ff6boss_6:
	.byte	KEYSH , ff6boss_key+0
ff6boss_6_B1:
@ 000   ----------------------------------------
	.byte		VOICE , 126
	.byte		VOL   , 91*ff6boss_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
ff6boss_6_004:
	.byte		N11   , Fs1 , v092
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte		N11   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N05   
	.byte	W06
	.byte		N05   
	.byte	W06
	.byte	PEND
@ 005   ----------------------------------------
ff6boss_6_005:
	.byte		N11   , Fs1 , v092
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 007   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 008   ----------------------------------------
ff6boss_6_008:
	.byte		N11   , Fs1 , v092
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N20   , As1 
	.byte	W36
	.byte		N11   
	.byte	W12
	.byte		N20   , Fs1 
	.byte	W24
	.byte	PEND
@ 009   ----------------------------------------
ff6boss_6_009:
	.byte		N20   , Fs1 , v092
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		N11   , Fs1 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N20   , As1 
	.byte	W24
	.byte	PEND
@ 010   ----------------------------------------
ff6boss_6_010:
	.byte		N11   , Fs1 , v092
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N20   , As1 
	.byte	W24
	.byte		N11   , Fs1 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N20   , As1 
	.byte	W24
	.byte	PEND
@ 011   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_010
@ 012   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_008
@ 013   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_009
@ 014   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 015   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 016   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 017   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 018   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 019   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 020   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 021   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 022   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 023   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 024   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 025   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 026   ----------------------------------------
ff6boss_6_026:
	.byte		N20   , Fs1 , v092
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N20   
	.byte	W24
	.byte		N11   , As1 
	.byte	W12
	.byte	PEND
@ 027   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 028   ----------------------------------------
ff6boss_6_028:
	.byte	W60
	.byte		N11   , Fs1 , v092
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte	PEND
@ 029   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 030   ----------------------------------------
ff6boss_6_030:
	.byte		N20   , Fs1 , v092
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte	PEND
@ 031   ----------------------------------------
ff6boss_6_031:
	.byte		N20   , Fs1 , v092
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte	PEND
@ 032   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_030
@ 033   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_031
@ 034   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 035   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 036   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 037   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 038   ----------------------------------------
ff6boss_6_038:
	.byte		N20   , Fs1 , v092
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N20   , Fs1 
	.byte	W24
	.byte	PEND
@ 039   ----------------------------------------
ff6boss_6_039:
	.byte		N20   , Fs1 , v092
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte	PEND
@ 040   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_038
@ 041   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_039
@ 042   ----------------------------------------
ff6boss_6_042:
	.byte	W24
	.byte		N20   , Fs1 , v092
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 043   ----------------------------------------
ff6boss_6_043:
	.byte		N20   , Fs1 , v092
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		N11   , Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N20   , Fs1 
	.byte	W24
	.byte	PEND
@ 044   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_042
@ 045   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_043
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 051   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 052   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 053   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 054   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_008
@ 055   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_009
@ 056   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_010
@ 057   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_010
@ 058   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_008
@ 059   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_009
@ 060   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 061   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 062   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 063   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 064   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 065   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 066   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 067   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 068   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 069   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 070   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 071   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 072   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 073   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 074   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 075   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 076   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_030
@ 077   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_031
@ 078   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_030
@ 079   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_031
@ 080   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 081   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 082   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 083   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 084   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_038
@ 085   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_039
@ 086   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_038
@ 087   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_039
@ 088   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_042
@ 089   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_043
@ 090   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_042
@ 091   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_043
@ 092   ----------------------------------------
	.byte	W96
@ 093   ----------------------------------------
	.byte	W96
@ 094   ----------------------------------------
	.byte	W96
@ 095   ----------------------------------------
	.byte	W96
@ 096   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 097   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 098   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 099   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 100   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_008
@ 101   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_009
@ 102   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_010
@ 103   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_010
@ 104   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_008
@ 105   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_009
@ 106   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 107   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 108   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 109   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 110   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 111   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 112   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 113   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 114   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 115   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 116   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 117   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 118   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 119   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 120   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 121   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 122   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_030
@ 123   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_031
@ 124   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_030
@ 125   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_031
@ 126   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 127   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 128   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 129   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 130   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_038
@ 131   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_039
@ 132   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_038
@ 133   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_039
@ 134   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_042
@ 135   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_043
@ 136   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_042
@ 137   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_043
@ 138   ----------------------------------------
	.byte	W96
@ 139   ----------------------------------------
	.byte	W96
@ 140   ----------------------------------------
	.byte	W96
@ 141   ----------------------------------------
	.byte	W96
@ 142   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 143   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 144   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 145   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 146   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_008
@ 147   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_009
@ 148   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_010
@ 149   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_010
@ 150   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_008
@ 151   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_009
@ 152   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 153   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 154   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 155   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 156   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 157   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 158   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 159   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 160   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 161   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 162   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_004
@ 163   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_005
@ 164   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 165   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 166   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 167   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 168   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_030
@ 169   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_031
@ 170   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_030
@ 171   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_031
@ 172   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 173   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_026
@ 174   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 175   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_028
@ 176   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_038
@ 177   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_039
@ 178   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_038
@ 179   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_039
@ 180   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_042
@ 181   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_043
@ 182   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_6_042
@ 183   ----------------------------------------
	.byte		N20   , Fs1 , v092
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		N11   , Fs1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N20   , Fs1 
	.byte	W18
	.byte	GOTO
	 .word	ff6boss_6_B1
ff6boss_6_B2:
	.byte	W06
@ 184   ----------------------------------------
	.byte	FINE

@**************** Track 7 (Midi-Chn.10) ****************@

ff6boss_7:
	.byte	KEYSH , ff6boss_key+0
ff6boss_7_B1:
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		VOL   , 103*ff6boss_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N90   , Bn1 , v092
	.byte		N90   , Cn2 
	.byte		N90   , Fs2 
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
ff6boss_7_002:
	.byte		N90   , Cn2 , v092
	.byte		N90   , Cs2 
	.byte		N32   , Fs2 
	.byte	W36
	.byte		N11   
	.byte	W60
	.byte	PEND
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
ff6boss_7_004:
	.byte		N32   , Fs2 , v092
	.byte	W36
	.byte		N32   
	.byte	W36
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 005   ----------------------------------------
ff6boss_7_005:
	.byte	W12
	.byte		N32   , Fs2 , v092
	.byte	W36
	.byte		N11   , Gn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
ff6boss_7_006:
	.byte		N11   , Gn1 , v092
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
ff6boss_7_007:
	.byte		N11   , Fs2 , v092
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte	PEND
@ 008   ----------------------------------------
ff6boss_7_008:
	.byte		N11   , Gn1 , v092
	.byte		N42   , Cn2 
	.byte		N42   , Cs2 
	.byte	W12
	.byte		N11   , Fs2 
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		        Gn1 
	.byte		N32   , Cn2 
	.byte		N32   , Cs2 
	.byte	W12
	.byte		N11   , Fs2 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		        Gn1 
	.byte		N11   , Cn2 
	.byte		N11   , Cs2 
	.byte	W12
	.byte	PEND
@ 009   ----------------------------------------
ff6boss_7_009:
	.byte	W12
	.byte		N11   , Fs2 , v092
	.byte	W24
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W24
	.byte		        Gn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte	PEND
@ 010   ----------------------------------------
ff6boss_7_010:
	.byte		N11   , Fs2 , v092
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Fs2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
ff6boss_7_011:
	.byte	W12
	.byte		N11   , Fs2 , v092
	.byte	W12
	.byte		        Gn1 
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte	PEND
@ 012   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_008
@ 013   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_009
@ 014   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_004
@ 015   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_005
@ 016   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_004
@ 017   ----------------------------------------
ff6boss_7_017:
	.byte	W12
	.byte		N20   , Fs2 , v092
	.byte	W24
	.byte		N11   , Gn1 
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte		N11   
	.byte	W12
	.byte	PEND
@ 018   ----------------------------------------
ff6boss_7_018:
	.byte		N32   , Fs2 , v092
	.byte	W36
	.byte		N32   
	.byte	W36
	.byte		N20   , Gn1 
	.byte	W24
	.byte	PEND
@ 019   ----------------------------------------
ff6boss_7_019:
	.byte	W12
	.byte		N32   , Fs2 , v092
	.byte	W36
	.byte		N20   
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte	PEND
@ 020   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 021   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 022   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 023   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 024   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 025   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 026   ----------------------------------------
ff6boss_7_026:
	.byte		N90   , Cn2 , v092
	.byte		N90   , Cs2 
	.byte		N20   , Fs2 
	.byte	W24
	.byte		N42   , Gn1 
	.byte	W48
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 027   ----------------------------------------
ff6boss_7_027:
	.byte		N20   , Fs2 , v092
	.byte	W24
	.byte		N11   , Gn1 
	.byte	W12
	.byte		N32   , Fs2 
	.byte	W36
	.byte		N20   , Gn1 
	.byte	W24
	.byte	PEND
@ 028   ----------------------------------------
ff6boss_7_028:
	.byte		N32   , Cn2 , v092
	.byte		N32   , Cs2 
	.byte		N20   , Fs2 
	.byte	W24
	.byte		N11   , Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte		N11   , Cs2 
	.byte		N32   , Fs2 
	.byte	W36
	.byte		N20   , Gn1 
	.byte	W24
	.byte	PEND
@ 029   ----------------------------------------
ff6boss_7_029:
	.byte		N32   , Cn2 , v092
	.byte		N32   , Cs2 
	.byte		N20   , Fs2 
	.byte	W24
	.byte		N11   , Gn1 
	.byte	W12
	.byte		N42   , Cn2 
	.byte		N42   , Cs2 
	.byte		N32   , Fs2 
	.byte	W36
	.byte		N11   , Gn1 
	.byte	W12
	.byte		        Cn2 
	.byte		N11   , Cs2 
	.byte		N11   , Fs2 
	.byte	W12
	.byte	PEND
@ 030   ----------------------------------------
ff6boss_7_030:
	.byte	W24
	.byte		N42   , Gn1 , v092
	.byte	W48
	.byte		N20   
	.byte	W24
	.byte	PEND
@ 031   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 032   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 033   ----------------------------------------
ff6boss_7_033:
	.byte	W24
	.byte		N20   , Gn1 , v092
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte	PEND
@ 034   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 035   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 036   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_028
@ 037   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_028
@ 038   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 039   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 040   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 041   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 042   ----------------------------------------
ff6boss_7_042:
	.byte		N90   , Cn2 , v092
	.byte		N90   , Cs2 
	.byte		N20   , Fs2 
	.byte	W24
	.byte		N11   , Gn1 
	.byte	W12
	.byte		N32   , Fs2 
	.byte	W36
	.byte		N20   , Gn1 
	.byte	W24
	.byte	PEND
@ 043   ----------------------------------------
ff6boss_7_043:
	.byte		N90   , Cn2 , v092
	.byte		N90   , Cs2 
	.byte		N32   , Fs2 
	.byte	W36
	.byte		N32   
	.byte	W36
	.byte		N20   , Gn1 
	.byte	W24
	.byte	PEND
@ 044   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_042
@ 045   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_043
@ 046   ----------------------------------------
ff6boss_7_046:
	.byte		N90   , Cn2 , v092
	.byte		N90   , Cs2 
	.byte		N90   , Fs2 
	.byte	W96
	.byte	PEND
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_002
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_004
@ 051   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_005
@ 052   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_006
@ 053   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_007
@ 054   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_008
@ 055   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_009
@ 056   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_010
@ 057   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_011
@ 058   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_008
@ 059   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_009
@ 060   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_004
@ 061   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_005
@ 062   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_004
@ 063   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_017
@ 064   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 065   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 066   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 067   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 068   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 069   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 070   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 071   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 072   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 073   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 074   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_028
@ 075   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_029
@ 076   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_030
@ 077   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 078   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 079   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_033
@ 080   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 081   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 082   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_028
@ 083   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_028
@ 084   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 085   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 086   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 087   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 088   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_042
@ 089   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_043
@ 090   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_042
@ 091   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_043
@ 092   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_046
@ 093   ----------------------------------------
	.byte	W96
@ 094   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_002
@ 095   ----------------------------------------
	.byte	W96
@ 096   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_004
@ 097   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_005
@ 098   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_006
@ 099   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_007
@ 100   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_008
@ 101   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_009
@ 102   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_010
@ 103   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_011
@ 104   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_008
@ 105   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_009
@ 106   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_004
@ 107   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_005
@ 108   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_004
@ 109   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_017
@ 110   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 111   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 112   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 113   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 114   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 115   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 116   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 117   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 118   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 119   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 120   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_028
@ 121   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_029
@ 122   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_030
@ 123   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 124   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 125   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_033
@ 126   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 127   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 128   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_028
@ 129   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_028
@ 130   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 131   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 132   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 133   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 134   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_042
@ 135   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_043
@ 136   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_042
@ 137   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_043
@ 138   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_046
@ 139   ----------------------------------------
	.byte	W96
@ 140   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_002
@ 141   ----------------------------------------
	.byte	W96
@ 142   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_004
@ 143   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_005
@ 144   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_006
@ 145   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_007
@ 146   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_008
@ 147   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_009
@ 148   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_010
@ 149   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_011
@ 150   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_008
@ 151   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_009
@ 152   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_004
@ 153   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_005
@ 154   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_004
@ 155   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_017
@ 156   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 157   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 158   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 159   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 160   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 161   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 162   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_018
@ 163   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_019
@ 164   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 165   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 166   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_028
@ 167   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_029
@ 168   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_030
@ 169   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 170   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 171   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_033
@ 172   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 173   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 174   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_028
@ 175   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_028
@ 176   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 177   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 178   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_026
@ 179   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_027
@ 180   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_042
@ 181   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_043
@ 182   ----------------------------------------
	.byte	PATT
	 .word	ff6boss_7_042
@ 183   ----------------------------------------
	.byte		N90   , Cn2 , v092
	.byte		N90   , Cs2 
	.byte		N32   , Fs2 
	.byte	W36
	.byte		N32   
	.byte	W36
	.byte		N20   , Gn1 
	.byte	W18
	.byte	GOTO
	 .word	ff6boss_7_B1
ff6boss_7_B2:
	.byte	W06
@ 184   ----------------------------------------
	.byte	FINE

@******************************************************@
	.align	2

ff6boss:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	ff6boss_pri	@ Priority
	.byte	ff6boss_rev	@ Reverb.

	.word	ff6boss_grp

	.word	ff6boss_1
	.word	ff6boss_2
	.word	ff6boss_3
	.word	ff6boss_4
	.word	ff6boss_5
	.word	ff6boss_6
	.word	ff6boss_7

	.end

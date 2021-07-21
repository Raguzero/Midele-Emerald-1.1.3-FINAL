@ Created by: WiserVisor
@ Original Source: Pokemon HeartGold/SoulSilver (Junichi Masuda)
@ MIDI Source: https://www.vgmusic.com/file/441144f0fb82a00c1a225b3c1e8e84e2.html (Base), https://musical-artifacts.com/artifacts/1077 (Used for comparison)
@ voicegrouphgsschamp::
@ voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_overdrive_guitar, 128, 0, 255, 214
@ voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_distortion_guitar_high, 128, 0, 255, 206
@ voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fingered_bass, 255, 253, 0, 149
@ voice_directsound 60, 0, DirectSoundWaveData_sc88pro_harp, 255, 246, 0, 235
@ voice_directsound 60, 0, DirectSoundWaveData_sc88pro_timpani, 255, 165, 154, 235
@ voice_keysplit voicegroup006, KeySplitTable2
@ voice_directsound 60, 0, orchestrahit72, 200, 255, 255, 255
@ voice_keysplit voicegroup007, KeySplitTable3
@ voice_keysplit voicegroup009, KeySplitTable5
@ voice_square_1_alt 60, 0, 0, 1, 0, 1, 4, 1
@ voice_keysplit_all voicegroup002 (also add voice_directsound 60, 0, ridecymbal, 255, 235, 0, 165 as the 16th voice in voicegroup002)
@ voice_directsound 60, 79, DirectSoundWaveData_unknown_open_hihat, 255, 242, 141, 0
	.include "MPlayDef.s"

	.equ	mus_champion_battle_hgss_grp, voicegrouphgsschamp
	.equ	mus_champion_battle_hgss_pri, 0
	.equ	mus_champion_battle_hgss_rev, 0
	.equ	mus_champion_battle_hgss_mvl, 52
	.equ	mus_champion_battle_hgss_key, 0
	.equ	mus_champion_battle_hgss_tbs, 1
	.equ	mus_champion_battle_hgss_exg, 0
	.equ	mus_champion_battle_hgss_cmp, 1

	.section .rodata
	.global	mus_champion_battle_hgss
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

mus_champion_battle_hgss_1:
	.byte	KEYSH , mus_champion_battle_hgss_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 91*mus_champion_battle_hgss_tbs/2
	.byte		VOICE , 5
	.byte		VOL   , 127*mus_champion_battle_hgss_mvl/mxv
	.byte		PAN   , c_v-49
	.byte		N06   , Ds3 , v127
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Dn3 
	.byte	W12
@ 001   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
@ 002   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
@ 003   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
@ 004   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Dn3 
	.byte	W12
@ 005   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
@ 006   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Dn3 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
@ 007   ----------------------------------------
	.byte		        Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
@ 008   ----------------------------------------
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		N48   , En4 
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
@ 009   ----------------------------------------
mus_champion_battle_hgss_1_009:
	.byte		N18   , Ds4 , v127
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte	PEND
@ 010   ----------------------------------------
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        En4 
	.byte	W72
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_1_009
@ 012   ----------------------------------------
	.byte		N24   , En4 , v127
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
@ 013   ----------------------------------------
	.byte		        Ds4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N01   , Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
@ 014   ----------------------------------------
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 015   ----------------------------------------
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
@ 016   ----------------------------------------
	.byte		N96   , Ds3 
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W48
@ 017   ----------------------------------------
	.byte		N48   , Fn3 
	.byte	W48
	.byte		        Fs3 
	.byte	W48
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
	.byte	W96
@ 020   ----------------------------------------
	.byte		        Ds3 
	.byte	W48
	.byte		        Bn3 
	.byte	W48
@ 021   ----------------------------------------
	.byte		        As3 
	.byte	W48
	.byte		        Gs3 
	.byte	W48
@ 022   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
@ 023   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
@ 024   ----------------------------------------
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
@ 025   ----------------------------------------
	.byte		        Ds4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
@ 026   ----------------------------------------
	.byte	GOTO
	.word	mus_champion_battle_hgss_1_009
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

mus_champion_battle_hgss_2:
	.byte	KEYSH , mus_champion_battle_hgss_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 5
	.byte		VOL   , 127*mus_champion_battle_hgss_mvl/mxv
	.byte		PAN   , c_v-19
	.byte		N06   , As2 , v127
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
@ 001   ----------------------------------------
mus_champion_battle_hgss_2_001:
	.byte		N03   , As2 , v127
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_2_001
@ 003   ----------------------------------------
	.byte		N03   , As2 , v127
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , En3 
	.byte	W12
@ 004   ----------------------------------------
mus_champion_battle_hgss_2_004:
	.byte		N03   , As2 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
mus_champion_battle_hgss_2_005:
	.byte		N03   , As2 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte	PEND
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_2_004
@ 007   ----------------------------------------
	.byte		N03   , As2 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , En3 
	.byte	W12
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
@ 008   ----------------------------------------
	.byte		N24   , As3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		N48   , Bn3 
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
@ 009   ----------------------------------------
mus_champion_battle_hgss_2_009:
	.byte		N18   , Fs3 , v127
	.byte	W18
	.byte		        Ds3 
	.byte	W18
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 010   ----------------------------------------
	.byte		N24   , En3 
	.byte	W24
	.byte		        Gs3 
	.byte	W72
@ 011   ----------------------------------------
	.byte		N18   , Fs3 
	.byte	W18
	.byte		        Ds3 
	.byte	W18
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 012   ----------------------------------------
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
@ 013   ----------------------------------------
	.byte		        As3 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N01   , Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
@ 014   ----------------------------------------
	.byte		N03   , As3 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 015   ----------------------------------------
	.byte		N24   , As3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Fs2 
	.byte	W24
@ 016   ----------------------------------------
	.byte		N96   , Bn2 
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W48
@ 017   ----------------------------------------
	.byte		N48   , Cs3 
	.byte	W48
	.byte		        Ds3 
	.byte	W48
@ 018   ----------------------------------------
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 019   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N04   , Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 020   ----------------------------------------
	.byte		N48   , As2 
	.byte	W48
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 021   ----------------------------------------
	.byte		N48   , Ds3 
	.byte	W48
	.byte		        Cs3 
	.byte	W48
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_2_005
@ 023   ----------------------------------------
	.byte		N03   , Cn3 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
@ 024   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
@ 025   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
@ 026   ----------------------------------------
	.byte	GOTO
	.word	mus_champion_battle_hgss_2_009
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

mus_champion_battle_hgss_3:
	.byte	KEYSH , mus_champion_battle_hgss_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 2
	.byte		VOL   , 115*mus_champion_battle_hgss_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Ds1 , v127
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , En1 
	.byte	W12
@ 001   ----------------------------------------
mus_champion_battle_hgss_3_001:
	.byte		N03   , Ds1 , v127
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte	PEND
@ 002   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_3_001
@ 003   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_3_001
@ 004   ----------------------------------------
mus_champion_battle_hgss_3_004:
	.byte		N03   , Ds1 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , An1 
	.byte	W12
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_3_004
@ 007   ----------------------------------------
	.byte		N03   , Ds1 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
@ 008   ----------------------------------------
	.byte		N24   , Ds2 
	.byte	W24
	.byte		        Ds1 
	.byte	W24
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
@ 009   ----------------------------------------
mus_champion_battle_hgss_3_009:
	.byte		N06   , Ds1 , v127
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
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte	PEND
@ 010   ----------------------------------------
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_3_009
@ 012   ----------------------------------------
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   , Fs1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        An1 
	.byte	W03
@ 013   ----------------------------------------
	.byte		        As1 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N01   , Gs1 
	.byte	W03
	.byte		        An1 
	.byte	W03
@ 014   ----------------------------------------
	.byte		N03   , As1 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N09   , Dn2 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 015   ----------------------------------------
	.byte		N24   , As1 
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte		        Ds1 
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte		        Bn1 
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte		        Ds1 
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
@ 016   ----------------------------------------
	.byte		N06   
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
@ 017   ----------------------------------------
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
@ 018   ----------------------------------------
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
@ 019   ----------------------------------------
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
@ 020   ----------------------------------------
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
	.byte		        Bn1 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Ds1 
	.byte	W12
	.byte		N06   
	.byte	W12
@ 021   ----------------------------------------
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		N06   
	.byte	W12
@ 022   ----------------------------------------
	.byte		        Ds1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_3_009
@ 024   ----------------------------------------
	.byte		N06   , Ds1 , v127
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
@ 025   ----------------------------------------
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
@ 026   ----------------------------------------
	.byte	GOTO
	.word	mus_champion_battle_hgss_3_009
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

mus_champion_battle_hgss_4:
	.byte	KEYSH , mus_champion_battle_hgss_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 3
	.byte		VOL   , 118*mus_champion_battle_hgss_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		N03   , Ds3 , v127
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Ds3 , v100
	.byte		N03   , As3 , v127
	.byte	W06
	.byte		        Fs3 , v100
	.byte		N03   , Fs4 , v127
	.byte	W06
	.byte		        As3 , v100
	.byte	W06
	.byte		        Fs4 
	.byte	W18
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Ds3 , v080
	.byte		N03   , As3 , v100
	.byte	W06
	.byte		        Fs3 , v080
	.byte		N03   , Fs4 , v100
	.byte	W06
	.byte		        As3 , v080
	.byte	W06
	.byte		        Fs4 
	.byte	W18
@ 001   ----------------------------------------
	.byte		        Fn3 , v127
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 , v100
	.byte		N03   , Cs4 , v127
	.byte	W06
	.byte		        Gs3 , v100
	.byte		N03   , Fn4 , v127
	.byte	W06
	.byte		        Cs4 , v100
	.byte	W06
	.byte		        Fn4 
	.byte	W18
	.byte		        Fn3 , v100
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 , v080
	.byte		N03   , Cs4 , v100
	.byte	W06
	.byte		        Gs3 , v080
	.byte		N03   , Fn4 , v100
	.byte	W06
	.byte		        Cs4 , v080
	.byte	W06
	.byte		        Fn4 
	.byte	W18
@ 002   ----------------------------------------
	.byte		        Ds3 , v127
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Ds3 , v100
	.byte		N03   , As3 , v127
	.byte	W06
	.byte		        Fs3 , v100
	.byte		N03   , Ds4 , v127
	.byte	W06
	.byte		        As3 , v100
	.byte	W06
	.byte		        Ds4 
	.byte	W18
	.byte		        Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Ds3 , v080
	.byte		N03   , As3 , v100
	.byte	W06
	.byte		        Fs3 , v080
	.byte		N03   , Ds4 , v100
	.byte	W06
	.byte		        As3 , v080
	.byte	W06
	.byte		        Ds4 
	.byte	W18
@ 003   ----------------------------------------
	.byte		        Cs3 , v127
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs3 , v100
	.byte		N03   , Gs3 , v127
	.byte	W06
	.byte		        Fn3 , v100
	.byte		N03   , Cs4 , v127
	.byte	W06
	.byte		        Gs3 , v100
	.byte	W06
	.byte		        Cs4 
	.byte	W18
	.byte		        Cs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs3 , v080
	.byte		N03   , Gs3 , v100
	.byte	W06
	.byte		        Fn3 , v080
	.byte		N03   , Cs4 , v100
	.byte	W06
	.byte		        Gs3 , v080
	.byte	W06
	.byte		        Cs4 
	.byte	W18
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte		VOICE , 11
	.byte		VOL   , 127*mus_champion_battle_hgss_mvl/mxv
	.byte	W01
	.byte		N03   , En1 , v111
	.byte	W03
	.byte		        En1 , v103
	.byte	W02
	.byte		N03 ,  Bn1 , v107
	.byte	W03
	.byte		        Bn1 , v099
	.byte	W03
	.byte		 N03 ,  Fn2 , v107
	.byte	W03
	.byte		        Fn2 , v099
	.byte	W03
	.byte		  N03 ,  As2 , v119
	.byte	W03
	.byte		        As2 , v111
	.byte	W03
	.byte		  N03 , Dn3 , v119
	.byte	W03
	.byte		        Dn3 , v111
	.byte	W03
	.byte		  N03 ,  Gs3 , v119
	.byte	W03
	.byte		        Gs3 , v111
	.byte	W03
	.byte		N03 ,  Cs4 , v123
	.byte	W03
	.byte		        Cs4 , v115
	.byte	W03
	.byte		 N03 ,  En4 , v123
	.byte	W03
	.byte		        En4 , v115
	.byte	W03
	.byte		 N03 ,  Cs4 , v127
	.byte	W03
	.byte		        Cs4 , v119
	.byte	W03
	.byte		 N03 ,  Fs3 , v123
	.byte	W03
	.byte		        Fs3 , v115
	.byte	W03
	.byte		N03 ,  Cn3 , v123
	.byte	W03
	.byte		        Cn3 , v115
	.byte	W03
	.byte		 N03 ,  Gn2 , v123
	.byte	W03
	.byte		        Gn2 , v115
	.byte	W03
	.byte		 N03 ,  Dn2 , v127
	.byte	W03
	.byte		        Dn2 , v119
	.byte	W03
	.byte		 N03 ,  An1 , v127
	.byte	W03
	.byte		        An1 , v119
	.byte	W03
	.byte		  N03 , Ds1 , v127
	.byte	W03
	.byte		        Ds1 , v119
	.byte	W03
	.byte		  N03 ,  Bn0 , v127
	.byte	W03
	.byte		         Bn0 , v119
	.byte	W03
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
mus_champion_battle_hgss_4_009:
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W01
	.byte		N03   , En1 , v111
	.byte	W03
	.byte		        En1 , v103
	.byte	W02
	.byte		N03 ,  Bn1 , v107
	.byte	W03
	.byte		        Bn1 , v099
	.byte	W03
	.byte		 N03 ,  Fn2 , v107
	.byte	W03
	.byte		        Fn2 , v099
	.byte	W03
	.byte		  N03 ,  As2 , v119
	.byte	W03
	.byte		        As2 , v111
	.byte	W03
	.byte		  N03 , Dn3 , v119
	.byte	W03
	.byte		        Dn3 , v111
	.byte	W03
	.byte		  N03 ,  Gs3 , v119
	.byte	W03
	.byte		        Gs3 , v111
	.byte	W03
	.byte		N03 ,  Cs4 , v123
	.byte	W03
	.byte		        Cs4 , v115
	.byte	W03
	.byte		 N03 ,  En4 , v123
	.byte	W03
	.byte		        En4 , v115
	.byte	W03
	.byte		 N03 ,  Cs4 , v127
	.byte	W03
	.byte		        Cs4 , v119
	.byte	W03
	.byte		 N03 ,  Fs3 , v123
	.byte	W03
	.byte		        Fs3 , v115
	.byte	W03
	.byte		N03 ,  Cn3 , v123
	.byte	W03
	.byte		        Cn3 , v115
	.byte	W03
	.byte		 N03 ,  Gn2 , v123
	.byte	W03
	.byte		        Gn2 , v115
	.byte	W03
	.byte		 N03 ,  Dn2 , v127
	.byte	W03
	.byte		        Dn2 , v119
	.byte	W03
	.byte		 N03 ,  An1 , v127
	.byte	W03
	.byte		        An1 , v119
	.byte	W03
	.byte		  N03 , Ds1 , v127
	.byte	W03
	.byte		        Ds1 , v119
	.byte	W03
	.byte		  N03 ,  Bn0 , v127
	.byte	W03
	.byte		         Bn0 , v119
	.byte	W03
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W01
	.byte		N03   , En1 , v111
	.byte	W03
	.byte		        En1 , v103
	.byte	W02
	.byte		N03 ,  Bn1 , v107
	.byte	W03
	.byte		        Bn1 , v099
	.byte	W03
	.byte		 N03 ,  Fn2 , v107
	.byte	W03
	.byte		        Fn2 , v099
	.byte	W03
	.byte		  N03 ,  As2 , v119
	.byte	W03
	.byte		        As2 , v111
	.byte	W03
	.byte		  N03 , Dn3 , v119
	.byte	W03
	.byte		        Dn3 , v111
	.byte	W03
	.byte		  N03 ,  Gs3 , v119
	.byte	W03
	.byte		        Gs3 , v111
	.byte	W03
	.byte		N03 ,  Cs4 , v123
	.byte	W03
	.byte		        Cs4 , v115
	.byte	W03
	.byte		 N03 ,  En4 , v123
	.byte	W03
	.byte		        En4 , v115
	.byte	W03
	.byte		 N03 ,  Cs4 , v127
	.byte	W03
	.byte		        Cs4 , v119
	.byte	W03
	.byte		 N03 ,  Fs3 , v123
	.byte	W03
	.byte		        Fs3 , v115
	.byte	W03
	.byte		N03 ,  Cn3 , v123
	.byte	W03
	.byte		        Cn3 , v115
	.byte	W03
	.byte		 N03 ,  Gn2 , v123
	.byte	W03
	.byte		        Gn2 , v115
	.byte	W03
	.byte		 N03 ,  Dn2 , v127
	.byte	W03
	.byte		        Dn2 , v119
	.byte	W03
	.byte		 N03 ,  An1 , v127
	.byte	W03
	.byte		        An1 , v119
	.byte	W03
	.byte		  N03 , Ds1 , v127
	.byte	W03
	.byte		        Ds1 , v119
	.byte	W03
	.byte		  N03 ,  Bn0 , v127
	.byte	W03
	.byte		         Bn0 , v119
	.byte	W03
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
	.byte	GOTO
	.word	mus_champion_battle_hgss_4_009
	.byte	FINE

@**************** Track 5 (Midi-Chn.6) ****************@

mus_champion_battle_hgss_5:
	.byte	KEYSH , mus_champion_battle_hgss_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 7
	.byte		VOL   , 127*mus_champion_battle_hgss_mvl/mxv
	.byte		PAN   , c_v+11
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte		N03   , Ds3 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Dn3 
	.byte	W12
@ 005   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
@ 006   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Dn3 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
@ 007   ----------------------------------------
	.byte		        Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
mus_champion_battle_hgss_5_009:
	.byte	W96
@ 010   ----------------------------------------
	.byte	W42
	.byte		N03   , Dn3 , v127
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        Ds3 
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        En3 
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        En3 
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N12   
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , En3 
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        En3 
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N12   , Bn3 
	.byte		N12   , Cs4 
	.byte	W12
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W84
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
@ 013   ----------------------------------------
	.byte		        Ds4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 014   ----------------------------------------
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
mus_champion_battle_hgss_5_018:
	.byte		N12   , Ds4 , v127
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N04   , Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_5_018
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
	.byte		N03   , Ds3 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
@ 023   ----------------------------------------
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
@ 024   ----------------------------------------
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
@ 025   ----------------------------------------
	.byte		        Ds4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
@ 026   ----------------------------------------
	.byte	GOTO
	.word	mus_champion_battle_hgss_5_009
	.byte	FINE

@**************** Track 6 (Midi-Chn.7) ****************@

mus_champion_battle_hgss_6:
	.byte	KEYSH , mus_champion_battle_hgss_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 4
	.byte		VOL   , 107*mus_champion_battle_hgss_mvl/mxv
	.byte		PAN   , c_v-29
	.byte		N24   , Ds1 , v127
	.byte	W72
	.byte		N03   , As1 , v032
	.byte	W03
	.byte		        As1 , v040
	.byte	W03
	.byte		        As1 , v052
	.byte	W03
	.byte		        As1 , v064
	.byte	W03
	.byte		        As1 , v072
	.byte	W03
	.byte		        As1 , v084
	.byte	W03
	.byte		        As1 , v096
	.byte	W03
	.byte		        As1 , v108
	.byte	W03
@ 001   ----------------------------------------
	.byte		N24   , Ds1 , v127
	.byte	W84
	.byte		N12   , As1 
	.byte	W12
@ 002   ----------------------------------------
	.byte		N24   , Ds1 
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte		N03   , As1 , v032
	.byte	W03
	.byte		        As1 , v040
	.byte	W03
	.byte		        As1 , v052
	.byte	W03
	.byte		        As1 , v064
	.byte	W03
	.byte		        As1 , v072
	.byte	W03
	.byte		        As1 , v084
	.byte	W03
	.byte		        As1 , v096
	.byte	W03
	.byte		        As1 , v108
	.byte	W03
@ 003   ----------------------------------------
	.byte		N24   , Ds1 , v127
	.byte	W48
	.byte		        As1 
	.byte	W24
	.byte		N03   , Ds1 , v032
	.byte	W03
	.byte		        Ds1 , v040
	.byte	W03
	.byte		        Ds1 , v052
	.byte	W03
	.byte		        Ds1 , v064
	.byte	W03
	.byte		        Ds1 , v072
	.byte	W03
	.byte		        Ds1 , v084
	.byte	W03
	.byte		        Ds1 , v096
	.byte	W03
	.byte		        Ds1 , v108
	.byte	W03
@ 004   ----------------------------------------
	.byte		N24   , Ds1 , v127
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
mus_champion_battle_hgss_6_006:
	.byte		N06   , Ds1 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte	PEND
@ 007   ----------------------------------------
mus_champion_battle_hgss_6_007:
	.byte		N06   , Ds1 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte	PEND
@ 008   ----------------------------------------
	.byte		N24   , Ds2 
	.byte	W96
@ 009   ----------------------------------------
mus_champion_battle_hgss_6_009:
	.byte		VOICE , 8
	.byte		N48   , As2 , v127
	.byte		N48   , Ds3 
	.byte	W48
	.byte		N24   
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N24   
	.byte		N24   , As3 
	.byte	W24
@ 010   ----------------------------------------
mus_champion_battle_hgss_6_010:
	.byte		N48   , Bn2 , v127
	.byte		N48   , En3 
	.byte	W48
	.byte		N24   
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        En3 
	.byte		N24   , Bn3 
	.byte	W24
	.byte	PEND
@ 011   ----------------------------------------
	.byte		N48   , As2 
	.byte		N48   , Ds3 
	.byte	W48
	.byte		N24   
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N24   
	.byte		N24   , As3 
	.byte	W24
@ 012   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_6_010
@ 013   ----------------------------------------
	.byte		VOICE , 4
	.byte		N06   , Ds1 , v127
	.byte	W06
	.byte		N12   , As0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 014   ----------------------------------------
	.byte		N06   , As1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte		VOICE , 9
	.byte		VOL , 97*mus_champion_battle_hgss_mvl/mxv
	.byte		PAN   , c_v-63
	.byte		N02   , Ds3 , v096
	.byte	W01
	.byte		PAN   , c_v-61
	.byte	W01
	.byte		        c_v-60
	.byte	W01
	.byte		        c_v-59
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v-57
	.byte	W01
	.byte		        c_v-56
	.byte	W01
	.byte		        c_v-55
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v-53
	.byte	W01
	.byte		        c_v-52
	.byte	W01
	.byte		        c_v-51
	.byte		N02   , Fn3 , v100
	.byte	W01
	.byte		PAN   , c_v-49
	.byte	W01
	.byte		        c_v-48
	.byte	W01
	.byte		        c_v-47
	.byte		N02   , Ds3 
	.byte	W01
	.byte		PAN   , c_v-45
	.byte	W01
	.byte		        c_v-44
	.byte	W01
	.byte		        c_v-43
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v-41
	.byte	W01
	.byte		        c_v-40
	.byte	W01
	.byte		        c_v-39
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v-37
	.byte	W01
	.byte		        c_v-36
	.byte	W01
	.byte		        c_v-35
	.byte		N02   , Fn3 , v104
	.byte	W01
	.byte		PAN   , c_v-33
	.byte	W01
	.byte		        c_v-32
	.byte	W01
	.byte		        c_v-31
	.byte		N02   , Ds3 
	.byte	W01
	.byte		PAN   , c_v-30
	.byte	W01
	.byte		        c_v-28
	.byte	W01
	.byte		        c_v-27
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v-25
	.byte	W01
	.byte		        c_v-24
	.byte	W01
	.byte		        c_v-23
	.byte		N02   , Fs3 , v108
	.byte	W01
	.byte		PAN   , c_v-22
	.byte	W01
	.byte		        c_v-20
	.byte	W01
	.byte		        c_v-19
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v-17
	.byte	W01
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v-15
	.byte		N02   , Ds3 
	.byte	W01
	.byte		PAN   , c_v-14
	.byte	W01
	.byte		        c_v-12
	.byte	W01
	.byte		        c_v-11
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v-10
	.byte	W01
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v-7
	.byte		N02   , Fs3 , v112
	.byte	W01
	.byte		PAN   , c_v-6
	.byte	W01
	.byte		        c_v-4
	.byte	W01
	.byte		        c_v-3
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		        c_v+1
	.byte		N02   , Ds3 
	.byte	W01
	.byte		PAN   , c_v+2
	.byte	W01
	.byte		        c_v+3
	.byte	W01
	.byte		        c_v+5
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v+6
	.byte	W01
	.byte		        c_v+8
	.byte	W01
	.byte		        c_v+9
	.byte		N02   , Fs3 , v116
	.byte	W01
	.byte		PAN   , c_v+10
	.byte	W01
	.byte		        c_v+11
	.byte	W01
	.byte		        c_v+13
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v+14
	.byte	W01
	.byte		        c_v+16
	.byte	W01
	.byte		        c_v+17
	.byte		N02   , Ds3 
	.byte	W01
	.byte		PAN   , c_v+18
	.byte	W01
	.byte		        c_v+19
	.byte	W01
	.byte		        c_v+21
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v+22
	.byte	W01
	.byte		        c_v+23
	.byte	W01
	.byte		        c_v+25
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v+26
	.byte	W01
	.byte		        c_v+27
	.byte	W01
	.byte		        c_v+29
	.byte		N02   , Fn3 , v120
	.byte	W01
	.byte		PAN   , c_v+30
	.byte	W01
	.byte		        c_v+31
	.byte	W01
	.byte		        c_v+33
	.byte		N02   , Ds3 
	.byte	W01
	.byte		PAN   , c_v+34
	.byte	W01
	.byte		        c_v+35
	.byte	W01
	.byte		        c_v+37
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v+38
	.byte	W01
	.byte		        c_v+39
	.byte	W01
	.byte		        c_v+41
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v+42
	.byte	W01
	.byte		        c_v+43
	.byte	W01
	.byte		        c_v+44
	.byte		N02   , Fn3 , v124
	.byte	W01
	.byte		PAN   , c_v+46
	.byte	W01
	.byte		        c_v+47
	.byte	W01
	.byte		        c_v+49
	.byte		N02   , Ds3 
	.byte	W01
	.byte		PAN   , c_v+50
	.byte	W01
	.byte		        c_v+51
	.byte	W01
	.byte		        c_v+52
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v+54
	.byte	W01
	.byte		        c_v+55
	.byte	W01
	.byte		        c_v+57
	.byte		N02   , Fs3 , v127
	.byte	W01
	.byte		PAN   , c_v+58
	.byte	W01
	.byte		        c_v+59
	.byte	W01
	.byte		        c_v+60
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v+62
	.byte	W01
	.byte		        c_v+63
	.byte	W01
@ 017   ----------------------------------------
	.byte		        c_v+62
	.byte		N02   
	.byte	W01
	.byte		PAN   , c_v+60
	.byte	W01
	.byte		        c_v+59
	.byte	W01
	.byte		        c_v+57
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v+56
	.byte	W01
	.byte		        c_v+55
	.byte	W01
	.byte		        c_v+54
	.byte		N02   , Gs3 
	.byte	W01
	.byte		PAN   , c_v+52
	.byte	W01
	.byte		        c_v+51
	.byte	W01
	.byte		        c_v+49
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v+48
	.byte	W01
	.byte		        c_v+47
	.byte	W01
	.byte		        c_v+46
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v+44
	.byte	W01
	.byte		        c_v+43
	.byte	W01
	.byte		        c_v+41
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		        c_v+39
	.byte	W01
	.byte		        c_v+38
	.byte		N02   , Gs3 
	.byte	W01
	.byte		PAN   , c_v+36
	.byte	W01
	.byte		        c_v+35
	.byte	W01
	.byte		        c_v+33
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v+32
	.byte	W01
	.byte		        c_v+31
	.byte	W01
	.byte		        c_v+30
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v+28
	.byte	W01
	.byte		        c_v+27
	.byte	W01
	.byte		        c_v+25
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v+24
	.byte	W01
	.byte		        c_v+23
	.byte	W01
	.byte		        c_v+22
	.byte		N02   , Gs3 
	.byte	W01
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		        c_v+19
	.byte	W01
	.byte		        c_v+17
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v+16
	.byte	W01
	.byte		        c_v+15
	.byte	W01
	.byte		        c_v+14
	.byte		N02   , Fn3 
	.byte	W01
	.byte		PAN   , c_v+12
	.byte	W01
	.byte		        c_v+11
	.byte	W01
	.byte		        c_v+9
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v+8
	.byte	W01
	.byte		        c_v+7
	.byte	W01
	.byte		        c_v+6
	.byte		N02   , Gs3 
	.byte	W01
	.byte		PAN   , c_v+4
	.byte	W01
	.byte		        c_v+3
	.byte	W01
	.byte		        c_v+1
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v-2
	.byte		N02   
	.byte	W01
	.byte		PAN   , c_v-4
	.byte	W01
	.byte		        c_v-5
	.byte	W01
	.byte		        c_v-7
	.byte		N02   , Gs3 
	.byte	W01
	.byte		PAN   , c_v-8
	.byte	W01
	.byte		        c_v-9
	.byte	W01
	.byte		        c_v-10
	.byte		N02   , As3 
	.byte	W01
	.byte		PAN   , c_v-12
	.byte	W01
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v-15
	.byte		N02   , Gs3 
	.byte	W01
	.byte		PAN   , c_v-16
	.byte	W01
	.byte		        c_v-17
	.byte	W01
	.byte		        c_v-18
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		        c_v-21
	.byte	W01
	.byte		        c_v-23
	.byte		N02   , Gs3 
	.byte	W01
	.byte		PAN   , c_v-24
	.byte	W01
	.byte		        c_v-25
	.byte	W01
	.byte		        c_v-26
	.byte		N02   , As3 
	.byte	W01
	.byte		PAN   , c_v-28
	.byte	W01
	.byte		        c_v-29
	.byte	W01
	.byte		        c_v-31
	.byte		N02   , Gs3 
	.byte	W01
	.byte		PAN   , c_v-32
	.byte	W01
	.byte		        c_v-33
	.byte	W01
	.byte		        c_v-34
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v-36
	.byte	W01
	.byte		        c_v-37
	.byte	W01
	.byte		        c_v-39
	.byte		N02   , Gs3 
	.byte	W01
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		        c_v-41
	.byte	W01
	.byte		        c_v-42
	.byte		N02   , As3 
	.byte	W01
	.byte		PAN   , c_v-44
	.byte	W01
	.byte		        c_v-45
	.byte	W01
	.byte		        c_v-47
	.byte		N02   , Gs3 
	.byte	W01
	.byte		PAN   , c_v-48
	.byte	W01
	.byte		        c_v-49
	.byte	W01
	.byte		        c_v-50
	.byte		N02   , Fs3 
	.byte	W01
	.byte		PAN   , c_v-52
	.byte	W01
	.byte		        c_v-53
	.byte	W01
	.byte		        c_v-55
	.byte		N02   , Gs3 
	.byte	W01
	.byte		PAN   , c_v-56
	.byte	W01
	.byte		        c_v-57
	.byte	W01
	.byte		        c_v-58
	.byte		N02   , As3 
	.byte	W01
	.byte		PAN   , c_v-60
	.byte	W01
	.byte		        c_v-61
	.byte	W01
	.byte		        c_v-63
	.byte		N02   , Gs3 
	.byte	W01
	.byte		PAN   , c_v-64
	.byte	W01
	.byte		        c_v-64
	.byte	W01
@ 018   ----------------------------------------
	.byte		VOICE , 4
	.byte		VOL , 107*mus_champion_battle_hgss_mvl/mxv
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 019   ----------------------------------------
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_6_006
@ 023   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_6_007
@ 024   ----------------------------------------
	.byte		N24   , Ds2 , v127
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	GOTO
	.word	mus_champion_battle_hgss_6_009
	.byte	FINE

@**************** Track 7 (Midi-Chn.9) ****************@

mus_champion_battle_hgss_7:
	.byte	KEYSH , mus_champion_battle_hgss_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 6
	.byte		VOL   , 105*mus_champion_battle_hgss_mvl/mxv
	.byte		PAN   , c_v+51
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte		N12   , Ds4 , v127
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte		N12   
	.byte	W96
@ 007   ----------------------------------------
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
@ 008   ----------------------------------------
	.byte		        Ds5 
	.byte	W96
@ 009   ----------------------------------------
mus_champion_battle_hgss_7_009:
	.byte		N12 ,  Ds4 , v127
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte		N12   
	.byte	W96
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 014   ----------------------------------------
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 015   ----------------------------------------
	.byte		        Ds4 
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
mus_champion_battle_hgss_7_018:
	.byte		N12   , Ds4 , v127
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N04   , Ds4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_7_018
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
	.byte		N06   , Ds4 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
@ 023   ----------------------------------------
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn5 
	.byte	W12
@ 024   ----------------------------------------
	.byte		        Ds5 
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	GOTO
	.word	mus_champion_battle_hgss_7_009
	.byte	FINE

@**************** Track 8 (Midi-Chn.10) ****************@

mus_champion_battle_hgss_8:
	.byte	KEYSH , mus_champion_battle_hgss_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 10
	.byte		VOL   , 102*mus_champion_battle_hgss_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Cn1 , v127
	.byte		N06   , Cs2 
	.byte	W84
	.byte		        Cn1 
	.byte	W12
@ 001   ----------------------------------------
	.byte		N06   
	.byte	W84
	.byte		N06   
	.byte	W12
@ 002   ----------------------------------------
	.byte		N06   
	.byte	W48
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W12
@ 003   ----------------------------------------
	.byte		N06   
	.byte		N06   , En2 
	.byte	W48
	.byte		N12   , Cn1 
	.byte	W18
	.byte		N03   , Cn3 , v012
	.byte	W03
	.byte		N02   , Cn3 , v020
	.byte	W02
	.byte		        Cn3 , v032
	.byte	W01
	.byte		N03   , En0 , v068
	.byte		N03   , En1 
	.byte	W01
	.byte		N01   , Cn3 , v040
	.byte	W02
	.byte		N03   , En0 , v072
	.byte		N03   , En1 
	.byte		N02   , Cn3 , v052
	.byte	W02
	.byte		        Cn3 , v060
	.byte	W01
	.byte		N03   , En0 , v080
	.byte		N03   , En1 
	.byte	W01
	.byte		N01   , Cn3 , v072
	.byte	W01
	.byte		        Cn3 , v080
	.byte	W01
	.byte		N03   , En0 , v084
	.byte		N03   , En1 
	.byte	W01
	.byte		N01   , Cn3 , v092
	.byte	W01
	.byte		N02   , Cn3 , v100
	.byte	W01
	.byte		N03   , En0 , v092
	.byte		N06   , Cn1 , v127
	.byte		N03   , En1 , v092
	.byte	W01
	.byte		N01   , Cn3 , v112
	.byte	W02
	.byte		N03   , En0 , v096
	.byte		N03   , En1 
	.byte		N02   , Cn3 , v120
	.byte	W02
	.byte		N06   , Cn3 , v127
	.byte	W01
	.byte		N03   , En0 , v104
	.byte		N03   , En1 
	.byte	W03
	.byte		        En0 , v112
	.byte		N03   , En1 
	.byte	W03
@ 004   ----------------------------------------
	.byte		N06   , CsM1, v100
	.byte		N06   , Cn1 , v127
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        CsM1, v100
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
	.byte		        FnM1
	.byte	W12
@ 005   ----------------------------------------
	.byte		        CsM1
	.byte		N06   , Cn1 , v127
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        CsM1, v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        FnM1
	.byte	W12
	.byte		        CsM1
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		        FnM1
	.byte	W12
@ 006   ----------------------------------------
	.byte		        Cn1 , v127
	.byte		N06   , Cs2 
	.byte	W12
	.byte		        DsM1
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        DsM1
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        DsM1
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        DsM1
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        DsM1
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        DsM1
	.byte		N06   , Cn1 
	.byte	W12
	.byte		        DsM1
	.byte		N03   , En0 , v092
	.byte		N06   , Cn1 , v127
	.byte		N03   , En1 , v092
	.byte	W03
	.byte		        En0 , v096
	.byte		N03   , En1 
	.byte	W03
	.byte		        En0 , v104
	.byte		N03   , En1 
	.byte	W03
	.byte		        En0 , v112
	.byte		N03   , En1 
	.byte	W03
@ 007   ----------------------------------------
	.byte		N06   , FnM1, v100
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		        FnM1, v100
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		        FnM1, v100
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		        FnM1, v100
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		        FnM1, v100
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        FnM1, v100
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        FnM1, v100
	.byte		N03   , Cn1 , v127
	.byte		N03   , Gn1 , v100
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Gn1 , v100
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Gn1 , v100
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Gn1 , v100
	.byte	W03
	.byte		N06   , FnM1
	.byte		N03   , Cn1 , v127
	.byte		N03   , Gn1 , v100
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Gn1 , v100
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Gn1 , v100
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Gn1 , v100
	.byte	W03
@ 008   ----------------------------------------
	.byte		N06   , Cn1 , v127
	.byte		N06   , En2 
	.byte	W48
	.byte		        Cn1 
	.byte		N06   , Cs2 
	.byte	W24
	.byte		N03   , Bn1 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 
	.byte	W03
	.byte		N03   
	.byte	W03
@ 009   ----------------------------------------
mus_champion_battle_hgss_8_009:
	.byte		N06   , Cn1 , v127
	.byte		N06   , Cs2 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W03
	.byte		        Dn1 
	.byte	W09
	.byte		        Cn1 
	.byte		N06   , Dn1 
	.byte	W12
	.byte	PEND
@ 010   ----------------------------------------
mus_champion_battle_hgss_8_010:
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		N06   
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W03
	.byte		        Dn1 
	.byte	W09
	.byte		        Cn1 
	.byte		N06   , Dn1 
	.byte	W12
	.byte	PEND
@ 011   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_8_010
@ 012   ----------------------------------------
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		N06   
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte		N06   , Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte		N03   , Bn1 
	.byte	W03
	.byte		N06   , Dn1 
	.byte		N03   , Bn1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cn1 
	.byte		N06   , Dn1 
	.byte		N03   , Gn1 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cn1 
	.byte		N03   , Fn1 
	.byte	W03
	.byte		        En1 
	.byte	W03
@ 013   ----------------------------------------
	.byte		N06   , Cn1 
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , An2 
	.byte	W12
	.byte		        FnM1, v112
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		        CsM1, v040
	.byte	W06
	.byte		        FnM1, v112
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		        CsM1, v040
	.byte	W06
	.byte		        FnM1, v112
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		        CsM1, v040
	.byte	W06
	.byte		        FnM1, v112
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		        CsM1, v040
	.byte	W06
	.byte		        FnM1, v112
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		N06   
	.byte		N06   , An2 
	.byte	W12
	.byte		        Cn1 
	.byte		N03   , Bn1 , v112
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Fn1 
	.byte	W06
@ 014   ----------------------------------------
	.byte		N06   , Cn1 , v127
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , An2 
	.byte	W12
	.byte		        FnM1, v112
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		        CsM1, v040
	.byte	W06
	.byte		        FnM1, v112
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		        CsM1, v040
	.byte	W06
	.byte		        FnM1, v112
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		        CsM1, v040
	.byte	W06
	.byte		        FnM1, v112
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		        CsM1, v040
	.byte	W06
	.byte		        FnM1, v112
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		N06   
	.byte		N06   , Cs2 
	.byte		N06   , An2 
	.byte	W12
	.byte		        Cn1 
	.byte		N03   , Bn1 , v112
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Fn1 
	.byte	W06
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte		N06   , Cn1 , v127
	.byte		N06   , An2 
	.byte	W12
	.byte		        Cn1 
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
	.byte		N06   
	.byte	W12
@ 017   ----------------------------------------
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
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
@ 018   ----------------------------------------
	.byte		N06   
	.byte		N06   , An2 , v100
	.byte	W12
	.byte		        Cn1 , v127
	.byte		N06   , En2 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , Cs2 , v100
	.byte	W12
	.byte		        Cn1 , v127
	.byte		N06   , En2 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , An2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , Cs2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , En2 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Cs2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , An2 , v100
	.byte	W12
	.byte		        Cn1 , v127
	.byte		N06   , En2 
	.byte	W12
@ 019   ----------------------------------------
	.byte		        Cn1 
	.byte		N06   , An2 , v100
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , En2 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , An2 , v100
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , En2 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , An2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , Cs2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , En2 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Cs2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , An2 , v100
	.byte	W12
	.byte		        Cn1 , v127
	.byte		N06   , En2 
	.byte	W12
@ 020   ----------------------------------------
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte		N06   , En2 
	.byte	W06
	.byte		        CsM1, v100
	.byte	W06
	.byte		        CsM1, v127
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1, v100
	.byte	W06
	.byte		        CsM1, v127
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1, v100
	.byte	W06
	.byte		        CsM1, v127
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1, v100
	.byte	W06
	.byte		        CsM1, v127
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1, v100
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1, v100
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		N03   , CsM1
	.byte		N06   , Cn1 
	.byte	W03
	.byte		N03   , CsM1, v100
	.byte	W03
	.byte		N06   
	.byte	W06
	.byte		        FnM1
	.byte		N06   , Cn1 , v127
	.byte	W12
@ 021   ----------------------------------------
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1, v100
	.byte	W06
	.byte		        CsM1, v127
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1, v100
	.byte	W06
	.byte		        CsM1, v127
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1, v100
	.byte	W06
	.byte		        CsM1, v127
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1, v100
	.byte	W06
	.byte		        CsM1, v127
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1, v100
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		        CsM1
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        CsM1, v100
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		N03   , CsM1
	.byte		N06   , Cn1 
	.byte	W03
	.byte		N03   , CsM1
	.byte	W03
	.byte		N06   , CsM1, v100
	.byte	W06
	.byte		N03   , Cn1 , v127
	.byte		N03   , Bn1 , v100
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , An1 , v100
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Gn1 , v100
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Fn1 , v100
	.byte	W03
@ 022   ----------------------------------------
	.byte		N06   , Cn1 , v127
	.byte		N06   , An2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , Cs2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , En2 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , An2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , Cs2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , En2 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , An2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , Cs2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , En2 
	.byte	W12
	.byte		        Cn1 
	.byte		N06   , An2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , Cs2 , v100
	.byte	W06
	.byte		        Cn1 , v127
	.byte		N06   , En2 
	.byte	W12
@ 023   ----------------------------------------
	.byte		        Cn1 
	.byte		N03   , Bn1 , v088
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Gn1 , v088
	.byte	W03
	.byte		        Fn1 , v092
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Bn1 , v092
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Gn1 , v096
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Bn1 , v096
	.byte	W03
	.byte		        An1 , v100
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Gn1 , v100
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Bn1 , v104
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Gn1 , v104
	.byte	W03
	.byte		        Fn1 , v108
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Bn1 , v108
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , An1 , v108
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Gn1 , v112
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Fn1 , v112
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Bn1 , v112
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , An1 , v116
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Gn1 , v116
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Fn1 , v116
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Bn1 , v120
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , An1 , v120
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Gn1 , v120
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Fn1 , v124
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Bn1 , v124
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , An1 , v124
	.byte	W03
	.byte		        Cn1 , v127
	.byte		N03   , Gn1 
	.byte	W03
	.byte		        Cn1 
	.byte		N03   , Fn1 
	.byte	W03
@ 024   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_8_009
@ 025   ----------------------------------------
	.byte		N06   , Cn1 , v127
	.byte		N03   , Bn1 , v088
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        Fn1 , v092
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Bn1 , v092
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Gn1 , v096
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Bn1 , v096
	.byte	W03
	.byte		        An1 , v100
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Bn1 , v104
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		        Fn1 , v108
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Bn1 , v108
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Gn1 , v112
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Bn1 , v112
	.byte	W03
	.byte		        An1 , v116
	.byte	W03
	.byte		N06   , Cn1 , v127
	.byte		N03   , Gn1 , v116
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		        En0 , v100
	.byte		N03   , En1 
	.byte	W03
	.byte		        En0 , v104
	.byte		N03   , En1 
	.byte	W03
	.byte		        En0 , v108
	.byte		N03   , En1 
	.byte	W03
	.byte		        En0 , v112
	.byte		N03   , En1 
	.byte	W03
	.byte		        En0 , v116
	.byte		N03   , En1 
	.byte	W03
	.byte		        En0 , v120
	.byte		N03   , En1 
	.byte	W03
	.byte		        En0 , v124
	.byte		N03   , En1 
	.byte	W03
	.byte		        En0 , v127
	.byte		N03   , En1 
	.byte	W03
@ 026   ----------------------------------------
	.byte	GOTO
	.word	mus_champion_battle_hgss_8_009
	.byte	FINE

@**************** Track 9 (Midi-Chn.11) ****************@

mus_champion_battle_hgss_9:
	.byte	KEYSH , mus_champion_battle_hgss_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 0
	.byte		VOL   , 93*mus_champion_battle_hgss_mvl/mxv
	.byte		PAN   , c_v+51
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
	.byte		N03   , Ds3 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N12   , As3 
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N12   , Bn3 
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N12   , Cn4 
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N12   , Cs4 
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
@ 008   ----------------------------------------
	.byte		        c_v-8
	.byte		N24   , Ds4 
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W15
	.byte		        c_v-7
	.byte	W01
	.byte		        c_v-18
	.byte	W01
	.byte		        c_v-28
	.byte	W01
	.byte		        c_v-39
	.byte	W01
	.byte		        c_v-52
	.byte	W01
	.byte		        c_v-63
	.byte	W01
	.byte		        c_v+0
	.byte		N24   , Ds3 
	.byte	W24
	.byte		BEND  , c_v-57
	.byte		N48   , En4 
	.byte	W01
	.byte		BEND  , c_v-47
	.byte	W01
	.byte		        c_v-36
	.byte	W01
	.byte		        c_v-26
	.byte	W01
	.byte		        c_v-13
	.byte	W01
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v+0
	.byte	W36
	.byte		        c_v-10
	.byte	W01
	.byte		        c_v-21
	.byte	W01
	.byte		        c_v-31
	.byte	W01
	.byte		        c_v-42
	.byte	W01
	.byte		        c_v-52
	.byte	W01
	.byte		        c_v-63
	.byte	W01
@ 009   ----------------------------------------
mus_champion_battle_hgss_9_009:
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte		N03   , Ds2 , v127
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-4
	.byte		N12   , En2 
	.byte	W01
	.byte		BEND  , c_v-3
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		        c_v-4
	.byte		N12   
	.byte	W01
	.byte		BEND  , c_v-3
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
@ 014   ----------------------------------------
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-12
	.byte		N12   , Fs2 
	.byte	W01
	.byte		BEND  , c_v-7
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		        c_v-12
	.byte		N12   
	.byte	W01
	.byte		BEND  , c_v-7
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W09
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
mus_champion_battle_hgss_9_018:
	.byte		N12   , Fs3 , v127
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Fn3 
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        En3 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Ds3 
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N04   , Fs3 
	.byte		N04   , Ds4 
	.byte	W06
	.byte		        Fn3 
	.byte		N04   , Dn4 
	.byte	W06
	.byte		        En3 
	.byte		N04   , Cs4 
	.byte	W06
	.byte		        Ds3 
	.byte		N04   , Cn4 
	.byte	W06
	.byte		N12   , Ds3 
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Ds3 
	.byte		N12   , Bn3 
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_9_018
@ 020   ----------------------------------------
	.byte		VOICE , 1
	.byte		N05   , Ds1 , v127
	.byte		N05   , As1 
	.byte	W06
	.byte	W06 
	.byte	W06
	.byte		N05   , Ds1
	.byte		N05   , As1 
	.byte	W06 
	.byte	W06  
	.byte	W06  
	.byte	W06  
	.byte	W06
	.byte		N05   , Ds1
	.byte		N05   , As1 
	.byte	W06
	.byte	W06  
	.byte	W06
	.byte		N05   , Ds1
	.byte		N05   , As1 
	.byte	W06
	.byte	W06  
	.byte	W06  
	.byte	W06  
	.byte	W06
@ 021   ----------------------------------------
	.byte		N05   , En1 
	.byte		N05   , Bn1 
	.byte	W06
	.byte	W06  
	.byte	W06
	.byte		N05   , En1
	.byte		N05   , Bn1 
	.byte	W06
	.byte	W06  
	.byte	W06  
	.byte	W06  
	.byte	W06
	.byte		N05   , En1
	.byte		N05   , Bn1 
	.byte	W06
	.byte	W06  
	.byte	W06
	.byte		N05   , En1
	.byte		N05   , Bn1 
	.byte	W06
	.byte	W06  
	.byte	W06  
	.byte	W06  
	.byte	W06
@ 022   ----------------------------------------
	.byte		VOICE , 0
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N12   , As2 
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N12   , Bn2 
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N12   , As2 
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N12   , An2 
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
@ 023   ----------------------------------------
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N12   , As2 
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N12   , Bn2 
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N12   , Cs3 
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N12   , Dn3 
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W09
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	GOTO
	.word	mus_champion_battle_hgss_9_009
	.byte	FINE

@**************** Track 10 (Midi-Chn.12) ****************@

mus_champion_battle_hgss_10:
	.byte	KEYSH , mus_champion_battle_hgss_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 8
	.byte		VOL   , 88*mus_champion_battle_hgss_mvl/mxv
	.byte		PAN   , c_v-29
	.byte	W96
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
mus_champion_battle_hgss_10_004:
	.byte		N03   , As2 , v127
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   , Bn2 
	.byte		N12   , Dn3 
	.byte	W12
	.byte	PEND
@ 005   ----------------------------------------
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , Fn3 
	.byte	W12
@ 006   ----------------------------------------
	.byte	PATT
	 .word	mus_champion_battle_hgss_10_004
@ 007   ----------------------------------------
	.byte		N03   , As2 , v127
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   , En3 
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte		N12   , Cs4 
	.byte	W12
@ 008   ----------------------------------------
	.byte		N24   , Ds3 
	.byte		N24   , As3 
	.byte	W24
	.byte		        As2 
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N48   , En3 
	.byte		N48   , Bn3 
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
@ 009   ----------------------------------------
mus_champion_battle_hgss_10_009:
	.byte		N06   , Ds3 , v127
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
@ 010   ----------------------------------------
	.byte		N12   , En3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N03 ,   En3 
	.byte	W06
	.byte		N03 ,   En3
	.byte	W06
	.byte		N12 ,   Gs3 
	.byte	W12
	.byte		N03 ,   En3 
	.byte	W06
	.byte		N03 ,   En3
	.byte	W06
	.byte		N12 ,   Bn3 
	.byte	W12
@ 011   ----------------------------------------
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
@ 012   ----------------------------------------
	.byte		N12   , En3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
@ 013   ----------------------------------------
	.byte		        As3
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N01   
	.byte	W03
	.byte		        An3 
	.byte	W03
@ 014   ----------------------------------------
	.byte		N03   , As3 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N12   
	.byte	W12
@ 015   ----------------------------------------
	.byte		N24   , Ds3 
	.byte		N24   , As3 
	.byte	W24
	.byte		        Fs2 
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N24   
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Fs2 
	.byte		N24   , Cs3 
	.byte	W24
@ 016   ----------------------------------------
	.byte		N96   , Bn2 
	.byte		N96   , Ds3 
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W01
	.byte	W48
@ 017   ----------------------------------------
	.byte		N48   , Cs3 
	.byte		N48   , Fn3 
	.byte	W48
	.byte		        Ds3 
	.byte		N48   , Fs3 
	.byte	W48
@ 018   ----------------------------------------
	.byte		N96   , Bn2 
	.byte		N48   , En3 
	.byte	W48
	.byte		        Fs3 
	.byte	W48
@ 019   ----------------------------------------
	.byte		N96   , En3 
	.byte		N48   , Gs3 
	.byte	W48
	.byte		        Bn3 
	.byte	W48
@ 020   ----------------------------------------
	.byte		        Fs2 
	.byte		N48   , Ds3 
	.byte	W48
	.byte		N24   , Fs3 
	.byte		N48   , Bn3 
	.byte	W24
	.byte		N24   , En3 
	.byte	W24
@ 021   ----------------------------------------
	.byte		N48   , Ds3 
	.byte		N48   , As3 
	.byte	W48
	.byte		        Cs3 
	.byte		N48   , Gs3 
	.byte	W48
@ 022   ----------------------------------------
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , An3 
	.byte	W12
@ 023   ----------------------------------------
	.byte		N03   , Cn3 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        Cn3 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Cn3 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        Cn3 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N03   , Cn3 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        Cn3 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N03   , Cn3 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		        Cn3 
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte		N12   , Dn4 
	.byte	W12
@ 024   ----------------------------------------
	.byte		N24   , Ds3 
	.byte		N24   , As3 
	.byte	W24
	.byte		        En3 
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Fs3 
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        En3 
	.byte		N24   , Bn3 
	.byte	W24
@ 025   ----------------------------------------
	.byte		        Ds3 
	.byte		N24   , As3 
	.byte	W24
	.byte		        En3 
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Fs3 
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Gs3 
	.byte		N24   , Ds4 
	.byte	W24
@ 026   ----------------------------------------
	.byte	GOTO
	.word	mus_champion_battle_hgss_10_009
	.byte	FINE

@******************************************************@
	.align	2

mus_champion_battle_hgss:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_champion_battle_hgss_pri	@ Priority
	.byte	mus_champion_battle_hgss_rev	@ Reverb.

	.word	mus_champion_battle_hgss_grp

	.word	mus_champion_battle_hgss_1
	.word	mus_champion_battle_hgss_2
	.word	mus_champion_battle_hgss_3
	.word	mus_champion_battle_hgss_4
	.word	mus_champion_battle_hgss_5
	.word	mus_champion_battle_hgss_6
	.word	mus_champion_battle_hgss_7
	.word	mus_champion_battle_hgss_8
	.word	mus_champion_battle_hgss_9
	.word	mus_champion_battle_hgss_10

	.end

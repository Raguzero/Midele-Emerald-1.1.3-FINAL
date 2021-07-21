
	.align 2
voicegrouphgsschamp::
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_overdrive_guitar, 128, 0, 255, 214
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_distortion_guitar_high, 128, 0, 255, 206
	voice_directsound 60, 0, DirectSoundWaveData_sc88_pick_bass, 255, 253, 0, 149
	voice_directsound 60, 0, DirectSoundWaveData_sc88_harp, 255, 246, 0, 235
	voice_directsound 60, 0, DirectSoundWaveData_sc88_timpani, 255, 165, 154, 235
	voice_keysplit voicegroup006, KeySplitTable2
	voice_directsound 60, 0, orchestrahit72, 200, 255, 255, 255
	voice_keysplit voicegroup007, KeySplitTable3
	voice_keysplit voicegroup009, KeySplitTable5
	voice_square_1_alt 0, 1, 0, 1, 4, 1
	voice_keysplit_all voicegroup002
	voice_directsound 60, 79, DirectSoundWaveData_unknown_open_hihat, 255, 242, 141, 0

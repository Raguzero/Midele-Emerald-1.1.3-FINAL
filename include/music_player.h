#ifndef GUARD_MUSIC_PLAYER_H
#define GUARD_MUSIC_PLAYER_H

// Functions
void StartMusicPlayer(u8 taskId);
u16 TryUseBattleBGM(u16 currentBattleBGM, const struct Trainer* currentTrainer);

// EWRAM
// Guarda el ID de la última canción que ha sido seleccionada en el music player
extern u16 gLastMusicPlayerSong;

#endif

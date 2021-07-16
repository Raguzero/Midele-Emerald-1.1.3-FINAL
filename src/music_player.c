#include "global.h"
#include "data.h"
#include "event_data.h"
#include "event_obj_lock.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "music_player.h"
#include "string_util.h"
#include "script.h"
#include "sound.h"
#include "task.h"
#include "text.h"
#include "window.h"
#include "constants/music_player.h"
#include "constants/songs.h"
#include "constants/trainers.h"

static bool8 HasCustomMusic(const struct Trainer* currentTrainer);
static bool8 IsSpecialTrainerClass(const struct Trainer* currentTrainer);
static void MusicPlayer_SelectSong(u8 taskId);
static void MusicPlayer_DestroyWindow(u8 taskId);
static u16 GetCurrentMusicTable(const u16** musicTablePointer);

#include "data/music_player.h"

// EWRAM vars
EWRAM_DATA u16 gLastMusicPlayerSong = 0;

// Functions

// Devuelve currentBattleBGM o gLastMusicPlayerSong, dependiendo de si el entrenador actual tiene alguna música especial o el music player tiene una canción seleccionada.
u16 TryUseBattleBGM(u16 currentBattleBGM, const struct Trainer* currentTrainer)
{
    if (HasCustomMusic(currentTrainer) || IsSpecialTrainerClass(currentTrainer) || gLastMusicPlayerSong == 0)
    {
        return currentBattleBGM;
    }

    return gLastMusicPlayerSong;
}

// Inicia el music player
void StartMusicPlayer(u8 taskId)
{
    u8 windowId;
    const u16* musicTable;

    HideMapNamePopUpWindow();
    sub_81973A4();
    windowId = AddWindow(&sDebugNumberDisplayWindowTemplate);
    DrawStdWindowFrame(windowId, FALSE);

    CopyWindowToVram(windowId, 3);
    
    // Get music table
    GetCurrentMusicTable(&musicTable);

    //Display initial song ID and name
    StringCopy(gStringVar2, gText_DigitIndicator2[0]);
    ConvertIntToDecimalStringN(gStringVar3, 1, STR_CONV_MODE_LEADING_ZEROS, MUSIC_PLAYER_NUMBER_DIGITS_ITEMS);
    StringCopyPadded(gStringVar1, gStringVar1, CHAR_SPACE, 15);
    StringExpandPlaceholders(gStringVar4, gMusicPlayer_SongId);
    AddTextPrinterParameterized(windowId, 1, gStringVar4, 1, 1, 0, NULL);
    AddTextPrinterParameterized(windowId, 1, sMusicNames[musicTable[0]], 1, 16, 0, NULL);

    gTasks[taskId].func = MusicPlayer_SelectSong;
    gTasks[taskId].data[2] = windowId;
    gTasks[taskId].data[3] = 1;            //Current ID
    gTasks[taskId].data[4] = 0;            //Digit Selected
}

static bool8 HasCustomMusic(const struct Trainer* currentTrainer)
{
    return currentTrainer != NULL && currentTrainer->battleMusic != 0;
}

static bool8 IsSpecialTrainerClass(const struct Trainer* currentTrainer)
{
    u8 i;
    if (currentTrainer == NULL)
    {
        return FALSE;
    }

    for(i = 0; i < ARRAY_COUNT(sSpecialTrainerClasses); i++)
    {
        if (currentTrainer->trainerClass == sSpecialTrainerClasses[i])
        {
            return TRUE;
        }
    }

    return FALSE;
}

static void MusicPlayer_SelectSong(u8 taskId)
{
    const u16* musicTable;
    u16 musicTableSize;
    u16 currentMusicTableId;
    musicTableSize = GetCurrentMusicTable(&musicTable);

    if (gMain.newKeys & DPAD_ANY)
    {
        PlaySE(SE_SELECT);

        if(gMain.newKeys & DPAD_UP)
        {
            gTasks[taskId].data[3] += sPowersOfTen[gTasks[taskId].data[4]];
            if(gTasks[taskId].data[3] > musicTableSize)
                gTasks[taskId].data[3] = musicTableSize;
        }
        if(gMain.newKeys & DPAD_DOWN)
        {
            gTasks[taskId].data[3] -= sPowersOfTen[gTasks[taskId].data[4]];
            if(gTasks[taskId].data[3] < 1)
                gTasks[taskId].data[3] = 1;
        }
        if(gMain.newKeys & DPAD_LEFT)
        {
            if(gTasks[taskId].data[4] > 0)
                gTasks[taskId].data[4] -= 1;
        }
        if(gMain.newKeys & DPAD_RIGHT)
        {
            if(gTasks[taskId].data[4] < MUSIC_PLAYER_NUMBER_DIGITS_ITEMS-1)
                gTasks[taskId].data[4] += 1;
        }

        currentMusicTableId = gTasks[taskId].data[3] - 1;
        // Update initial song ID and name
        StringCopy(gStringVar2, gText_DigitIndicator2[gTasks[taskId].data[4]]);
        StringCopyPadded(gStringVar1, gStringVar1, CHAR_SPACE, 15);
        ConvertIntToDecimalStringN(gStringVar3, gTasks[taskId].data[3], STR_CONV_MODE_LEADING_ZEROS, MUSIC_PLAYER_NUMBER_DIGITS_ITEMS);
        StringExpandPlaceholders(gStringVar4, gMusicPlayer_SongId);
        AddTextPrinterParameterized(gTasks[taskId].data[2], 1, gStringVar4, 1, 1, 0, NULL);
        // Rellenar con espacios para evitar solapar nombres anteriores
        StringCopyPadded(gStringVar1, sMusicNames[musicTable[currentMusicTableId]], CHAR_SPACE, MUSIC_PLAYER_MAIN_MENU_WIDTH + MUSIC_PLAYER_DISPLAY_WIDTH);
        AddTextPrinterParameterized(gTasks[taskId].data[2], 1, gStringVar1, 1, 16, 0, NULL);
    }

    if (gMain.newKeys & A_BUTTON)
    {
        gTasks[taskId].data[5] = gTasks[taskId].data[3];
        gTasks[taskId].data[3] = 1;
        gTasks[taskId].data[4] = 0;
        currentMusicTableId = gTasks[taskId].data[5] - 1;

        StringCopy(gStringVar2, gText_DigitIndicator2[gTasks[taskId].data[4]]);
        ConvertIntToDecimalStringN(gStringVar1, gTasks[taskId].data[3], STR_CONV_MODE_LEADING_ZEROS, MUSIC_PLAYER_NUMBER_DIGITS_ITEM_QUANTITY);
        StringCopyPadded(gStringVar1, gStringVar1, CHAR_SPACE, 15);

        // Cambiar BGM actual y actualizar gLastMusicPlayerSong
        PlayBGM(musicTable[currentMusicTableId]);
        gLastMusicPlayerSong = musicTable[currentMusicTableId];
        gTasks[taskId].func = MusicPlayer_DestroyWindow;
    }
    else if (gMain.newKeys & B_BUTTON)
    {
        PlaySE(SE_SELECT);
        gTasks[taskId].func = MusicPlayer_DestroyWindow;
    }
}

static void MusicPlayer_DestroyWindow(u8 taskId)
{
    ClearStdWindowAndFrame(gTasks[taskId].data[1], TRUE);

    ClearStdWindowAndFrame(gTasks[taskId].data[2], TRUE);

    ScriptUnfreezeEventObjects();
    ScriptContext2_Disable();
    DestroyTask(taskId);
}

// Decide qué tabla de músicas usar dependiendo del estado de VAR_MUSIC_PLAYER.
// El estado se irá actualizando a lo largo de la aventura del juego.
static u16 GetCurrentMusicTable(const u16** musicTablePointer)
{
    switch (VarGet(VAR_MUSIC_PLAYER))
    {
        case MUSIC_PLAYER_STATE_INITIAL:
            *musicTablePointer = sMusicTableInitial;
            return ARRAY_COUNT(sMusicTableInitial);
        case MUSIC_PLAYER_STATE_FINAL:
            *musicTablePointer = sMusicTableFinal;
            return ARRAY_COUNT(sMusicTableFinal);
        default:
            *musicTablePointer = sMusicTableInitial;
            return ARRAY_COUNT(sMusicTableInitial);
    }
}

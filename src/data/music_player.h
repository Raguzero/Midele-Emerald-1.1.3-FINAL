// Music player text
static const u8 gMusicPlayer_SongId[] =                   _("Song Id: {STR_VAR_3}\n\n\n{STR_VAR_2}");
static const u8 gMusicPlayer_SongName[] =                   _("{STR_VAR_1}");
static const u8 gDebugText_Util_PlaySong[] =                _("SONG NAME");

static const u8 digitInidicator_1[] =               _("{LEFT_ARROW}+1{RIGHT_ARROW}        ");
static const u8 digitInidicator_10[] =              _("{LEFT_ARROW}+10{RIGHT_ARROW}       ");
static const u8 digitInidicator_100[] =             _("{LEFT_ARROW}+100{RIGHT_ARROW}      ");
static const u8 digitInidicator_1000[] =            _("{LEFT_ARROW}+1000{RIGHT_ARROW}     ");
static const u8 digitInidicator_10000[] =           _("{LEFT_ARROW}+10000{RIGHT_ARROW}    ");
static const u8 digitInidicator_100000[] =          _("{LEFT_ARROW}+100000{RIGHT_ARROW}   ");
static const u8 digitInidicator_1000000[] =         _("{LEFT_ARROW}+1000000{RIGHT_ARROW}  ");
static const u8 digitInidicator_10000000[] =        _("{LEFT_ARROW}+10000000{RIGHT_ARROW} ");

// Music names
static const u8 gText_Music_Sasageyo[] = _("SASAGEYO");
static const u8 gText_Music_BloodyStream[] = _("BLOODY STREAM");
static const u8 gText_Music_TheReincarnation[] = _("THE REINCARNATION");
static const u8 gText_Music_VSFront[] = _("VS FRONTIER BRAIN");
static const u8 gText_Music_FRLG_VSChampion[] = _("VS FRLG CHAMPION");
static const u8 gText_Music_CruelAngelThesis[] = _("CRUEL ANGEL THESIS");


// Digit indicators
const u8 * const gText_DigitIndicator2[] =
{
    digitInidicator_1,
    digitInidicator_10,
    digitInidicator_100,
    digitInidicator_1000,
    digitInidicator_10000,
    digitInidicator_100000,
    digitInidicator_1000000,
    digitInidicator_10000000
};

static const s32 sPowersOfTen[] =
{
             1,
            10,
           100,
          1000,
         10000,
        100000,
       1000000,
      10000000,
     100000000,
    1000000000,
};

// Menu template
static const struct WindowTemplate sDebugNumberDisplayWindowTemplate =
{
    .bg = 0,
    .tilemapLeft = MUSIC_PLAYER_MAIN_MENU_WIDTH,
    .tilemapTop = 1,
    .width = MUSIC_PLAYER_DISPLAY_WIDTH,
    .height = 2 * MUSIC_PLAYER_DISPLAY_HEIGHT,
    .paletteNum = 15,
    .baseBlock = 1,
};

// Special music trainer classes
// Trainer classes a las que no se debe sobreescribir su música
static const u8 sSpecialTrainerClasses[] = {
    TRAINER_CLASS_LEADER,
    TRAINER_CLASS_LEADER_MIDELE,
    TRAINER_CLASS_ELITE_FOUR,
    TRAINER_CLASS_ELITE_FOUR_MIDELE,
    TRAINER_CLASS_CHAMPION,
    TRAINER_CLASS_RANDOM,
    TRAINER_CLASS_PKMN_TRAINER_3
};

// Music tables
// Tablas de músicas que controlan qué músicas están disponibles en el music player.

static const u16 sMusicTableInitial[] = {
    SASAGEYO,
    MUS_BLOODY_STREAM,
    CRUELANGELSTHESIS
};

static const u16 sMusicTableFinal[] = {
    SASAGEYO,
    MUS_BLOODY_STREAM,
    THEREINCARNATION,
    MUS_VS_FRONT,
    MUS_RG_VS_LAST
};

// Music name table
// Asocia IDs de músicas con sus nombres
const u8* const sMusicNames[] = {
    [SASAGEYO] = gText_Music_Sasageyo,
    [MUS_BLOODY_STREAM] = gText_Music_BloodyStream,
    [THEREINCARNATION] = gText_Music_TheReincarnation,
    [MUS_VS_FRONT] = gText_Music_VSFront,
    [MUS_RG_VS_LAST] = gText_Music_FRLG_VSChampion,
    [CRUELANGELSTHESIS] = gText_Music_CruelAngelThesis
};

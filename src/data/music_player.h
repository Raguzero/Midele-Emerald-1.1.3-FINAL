// Music player text
static const u8 gMusicPlayer_SongId[] =                   _("Option ID: {STR_VAR_3}\n\n\n{STR_VAR_2}");
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
static const u8 gText_Music_NoMusic[]                = _("POWER OFF \nTURN OFF MUSIC PLAYER");

static const u8 gText_Music_VSFront[]                = _("POKéMON RSE \nVS FRONTIER BRAIN");
static const u8 gText_Music_FRLG_VSChampion[]        = _("POKéMON FRLG \nVS FRLG CHAMPION");

static const u8 gText_Music_WildBW2Final[]           = _("POKéMON BW2          \nWILD BATTLE");
static const u8 gText_Music_Wild[]                   = _("POKéMON GSC          \nWILD BATTLE");
static const u8 gText_Music_FF6Boss[]                = _("FINAL FANTASY VI     \nBOSS BATTLE");
static const u8 gText_Music_FF7Jenova[]              = _("FINAL FANTASY VII    \nJENOVA");
static const u8 gText_Music_SeqBaPoke[]              = _("POKéMON DPPt         \nWILD BATTLE");
static const u8 gText_Music_BattleTowerSwSh[]        = _("POKÉMON SWORD&SHIELD \nBATTLE TOWER");
static const u8 gText_Music_ButterflyDigimon[]       = _("DIGIMON ADVENTURE    \nBUTTERFLY");
static const u8 gText_Music_CruelAngelThesis[]       = _("EVANGELION           \nCRUEL ANGEL THESIS");
static const u8 gText_Music_TheReincarnation[]       = _("TOUHOU               \nTHE REINCARNATION");
static const u8 gText_Music_DPPtCyrus[]              = _("POKéMON DPPt         \nCYRUS BATTLE");
static const u8 gText_Music_XYWild[]                 = _("POKéMON XY           \nWILD BATTLE");
static const u8 gText_Music_ZinniaTheme[]            = _("POKéMON ORAS         \nZINNIA THEME");
static const u8 gText_Music_SMWildBattle[]           = _("POKéMON SM           \nWILD BATTLE");
static const u8 gText_Music_ThemeOfEncounter[]       = _("FIRE EMBLEM          \nTHEME OF ENCOUNTER");
static const u8 gText_Music_EINZUG_DER_GLADIATOREN[] = _("FUCIK                \nEINZUG DER GLADIATOREN");
static const u8 gText_Music_DialgaPalkia[]           = _("POKéMON DPPt         \nVS DIALGA AND PALKIA");
static const u8 gText_Music_Megalovania[]            = _("UNDERTALE            \nMEGALOVANIA");
static const u8 gText_Music_ThatPersonNameIs[]       = _("BRAVELY DEFAULT      \nTHAT PERSON NAME IS");
static const u8 gText_Music_LiyueBattleThemeMain[]   = _("GENSHIN IMPACT       \nLIYUEBATTLETHEMEIMAIN");
static const u8 gText_Music_Bonetrousle[]            = _("UNDERTALE            \nBONETROUSLE");
static const u8 gText_Music_WallyBattle[]            = _("POKéMON ORAS         \nWALLY BATTLE");
static const u8 gText_Music_BloodyStream[]           = _("JOJO                 \nBLOODY STREAM");
static const u8 gText_Music_Umineko[]                = _("UMINEKO              \nORGAN 600M C MINOR");
static const u8 gText_Music_JohtoTrainer[]           = _("POKéMON GSC          \nJOHTO TRAINER");
static const u8 gText_Music_MirorB[]                 = _("POKéMON COLOSSEUM    \nMIROR B");
static const u8 gText_Music_IncomingX2[]             = _("XENOBLADE 2          \nINCOMING!");
static const u8 gText_Music_Sasageyo[]               = _("ATTACK ON TITAN      \nSHINZO WO SASAGEYO!");
static const u8 gText_Music_Goldy[]                  = _("POKéMON VEGA         \nTRAINER BATTLE");
static const u8 gText_Music_EncounterCynthia[]       = _("POKéMON DPPt         \nCYNTHIA ENCOUNTER");
static const u8 gText_Music_ZanzaTheme[]             = _("XENOBLADE            \nZANZA BATTLE");
static const u8 gText_Music_DeltaruneChaosk[]        = _("DELTARUNE            \nCHAOS KING");
static const u8 gText_Music_SwordShieldWild[]        = _("POKÉMON SWORD&SHIELD \nWILD BATTLE");
static const u8 gText_Music_Shum[]                   = _("GO A                 \nSHUM");
static const u8 gText_Music_BreathOfFire2FinalBoss[] = _("BREATH OF FIRE 2     \nFINAL BOSS");
static const u8 gText_Music_JackRoom[]               = _("DELTARUNE            \nTHE CIRCUS");


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
    MUS_DUMMY,
    WILDBW2_FINAL, 
    WILD, 
    FF6BOSS, 
    JENOVA, 
    SEQ_BA_POKE, 
    BATTLE_TOWER_SWSH, 
    BUTTERFLYWADAKOUJI, 
    BATTLECYRUS, 
    XYWILDBATTLE, 
    ZINNIATHEME, 
    SMWILDBATTLE, 
    THEMEOFENCOUNTER, 
    EINZUG_DER_GLADIATOREN, 
    DIALGAPALKIABATTLE, 
    UNDERTALEMEGALOVANIA, 
    THATPERSONSNAMEIS, 
    CRUELANGELSTHESIS, 
    THEREINCARNATION, 
    LIYUEBATTLETHEMEIMAIN, 
    BONETROUSLEUNDERTALE, 
    WALLYBATTLETHEME, 
    MUS_BLOODY_STREAM, 
    UMINEKONONAKUKORO, 
    JOHTOTRAIN, 
    MIRORBCOLO, 
    INCOMINGX2,
    SASAGEYO, 
    MUSICAVEGAGOLDY, 
    MUS_ENCOUNTER_CYNTHIA, 
    ZANZATHEME, 
    DELTARUNCHAOSK, 
    SWORDSHIELDWILD, 
    SHUM, 
    FINALBOSSBREATHFIRE2, 
    JACKROOM, 
};

static const u16 sMusicTableFinal[] = {
    MUS_DUMMY, // Power off music player
    SASAGEYO,
    MUS_BLOODY_STREAM,
    THEREINCARNATION,
    MUS_VS_FRONT,
    MUS_RG_VS_LAST
};

// Music name table
// Asocia IDs de músicas con sus nombres
const u8* const sMusicNames[] = {
    [MUS_DUMMY] = gText_Music_NoMusic,
    [MUS_VS_FRONT] = gText_Music_VSFront,
    [MUS_RG_VS_LAST] = gText_Music_FRLG_VSChampion,

    [WILDBW2_FINAL] = gText_Music_WildBW2Final,
    [WILD] = gText_Music_Wild,
    [FF6BOSS] = gText_Music_FF6Boss,
    [JENOVA] = gText_Music_FF7Jenova,
    [SEQ_BA_POKE] = gText_Music_SeqBaPoke,
    [BATTLE_TOWER_SWSH] = gText_Music_BattleTowerSwSh,
    [BUTTERFLYWADAKOUJI] = gText_Music_ButterflyDigimon,
    [CRUELANGELSTHESIS] = gText_Music_CruelAngelThesis,
    [THEREINCARNATION] = gText_Music_TheReincarnation,
    [BATTLECYRUS] = gText_Music_DPPtCyrus,
    [XYWILDBATTLE] = gText_Music_XYWild,
    [ZINNIATHEME] = gText_Music_ZinniaTheme,
    [SMWILDBATTLE] = gText_Music_SMWildBattle,
    [THEMEOFENCOUNTER] = gText_Music_ThemeOfEncounter,
    [EINZUG_DER_GLADIATOREN] = gText_Music_EINZUG_DER_GLADIATOREN,
    [DIALGAPALKIABATTLE] = gText_Music_DialgaPalkia,
    [UNDERTALEMEGALOVANIA] = gText_Music_Megalovania,
    [THATPERSONSNAMEIS] = gText_Music_ThatPersonNameIs,
    [LIYUEBATTLETHEMEIMAIN] = gText_Music_LiyueBattleThemeMain,
    [BONETROUSLEUNDERTALE] = gText_Music_Bonetrousle,
    [WALLYBATTLETHEME] = gText_Music_WallyBattle,
    [MUS_BLOODY_STREAM] = gText_Music_BloodyStream,
    [UMINEKONONAKUKORO] = gText_Music_Umineko,
    [JOHTOTRAIN] = gText_Music_JohtoTrainer,
    [MIRORBCOLO] = gText_Music_MirorB,
    [INCOMINGX2] = gText_Music_IncomingX2,
    [SASAGEYO] = gText_Music_Sasageyo,
    [MUSICAVEGAGOLDY] = gText_Music_Goldy,
    [MUS_ENCOUNTER_CYNTHIA] = gText_Music_EncounterCynthia,
    [ZANZATHEME] = gText_Music_ZanzaTheme,
    [DELTARUNCHAOSK] = gText_Music_DeltaruneChaosk,
    [SWORDSHIELDWILD] = gText_Music_SwordShieldWild,
    [SHUM] = gText_Music_Shum,
    [FINALBOSSBREATHFIRE2] = gText_Music_BreathOfFire2FinalBoss,
    [JACKROOM] = gText_Music_JackRoom,
};

#ifndef GUARD_CONSTANTS_BATTLE_AI_H
#define GUARD_CONSTANTS_BATTLE_AI_H

// battlers
#define AI_TARGET 0
#define AI_USER 1
#define AI_TARGET_PARTNER 2
#define AI_USER_PARTNER 3

// get_type command
#define AI_TYPE1_TARGET 0
#define AI_TYPE1_USER 1
#define AI_TYPE2_TARGET 2
#define AI_TYPE2_USER 3
#define AI_TYPE_MOVE 4

// type effectiveness
#define AI_EFFECTIVENESS_x4     160
#define AI_EFFECTIVENESS_x2     80
#define AI_EFFECTIVENESS_x1     40
#define AI_EFFECTIVENESS_x0_5   20
#define AI_EFFECTIVENESS_x0_25  10
#define AI_EFFECTIVENESS_x0     0

// ai weather
#define AI_WEATHER_NONE 0
#define AI_WEATHER_SUN 1
#define AI_WEATHER_RAIN 2
#define AI_WEATHER_SANDSTORM 3
#define AI_WEATHER_HAIL 4

// get_how_powerful_move_is
#define MOVE_POWER_DISCOURAGED_AND_NOT_MOST_POWERFUL 1
#define MOVE_NOT_MOST_POWERFUL                       2
#define MOVE_POWER_DISCOURAGED                       3
#define MOVE_MOST_POWERFUL                           4

// if_hp_condition
#define TARGET_HAS_1_HP                0
#define TARGET_WITH_LEFTIES_WONT_LOSE_HP_IF_WE_USE_ENDEAVOR 1
#define TARGET_CANNOT_USE_SUB          2
#define USER_CANNOT_USE_SUB            3
#define TARGET_HAS_1_MAX_HP            4

#define AI_NHKO_PESSIMISTIC 4

// get_possible_categories_of_foes_attacks
#define AI_PHYSICAL_ONLY 0
#define AI_ONLY_PHYSICAL_KNOWN 1
#define AI_BOTH_PHYSICAL_AND_SPECIAL 2
#define AI_ONLY_SPECIAL_KNOWN 3
#define AI_SPECIAL_ONLY 4
#define AI_UNKNOWN_CATEGORIES_PROBABLY_PHYSICAL 5
#define AI_UNKNOWN_CATEGORIES 6
#define AI_UNKNOWN_CATEGORIES_PROBABLY_SPECIAL 7
#define AI_NO_DAMAGING_MOVES 8

// script's table id to bit
#define AI_SCRIPT_CHECK_BAD_MOVE (1 << 0)
#define AI_SCRIPT_TRY_TO_FAINT (1 << 1)
#define AI_SCRIPT_CHECK_VIABILITY (1 << 2)
#define AI_SCRIPT_SETUP_FIRST_TURN (1 << 3)
#define AI_SCRIPT_RISKY (1 << 4)
#define AI_SCRIPT_PREFER_STRONGEST_MOVE (1 << 5)
#define AI_SCRIPT_PREFER_BATON_PASS (1 << 6)
#define AI_SCRIPT_DOUBLE_BATTLE (1 << 7)
#define AI_SCRIPT_HP_AWARE (1 << 8)
#define AI_SCRIPT_UNKNOWN (1 << 9)
#define AI_SCRIPT_USE_PERISH_SONG_EVEN_IF_LAST_POKEMON (1 << 10)
// 11 - 28 are not used
#define AI_SCRIPT_ROAMING (1 << 29)
#define AI_SCRIPT_SAFARI (1 << 30)
#define AI_SCRIPT_FIRST_BATTLE (1 << 31)

#endif // GUARD_CONSTANTS_BATTLE_AI_H

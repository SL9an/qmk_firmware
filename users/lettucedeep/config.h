#pragma once
// master handedness for split keyboards
#define MASTER_RIGHT

// user tap/hold settings
#undef TAPPING_TERM
#define TAPPING_TERM 250
#undef CHORDAL_HOLD
#define CHORDAL_HOLD
#undef PERMISSIVE_HOLD
#define PERMISSIVE_HOLD
#undef TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD
#undef TAPPING_TOGGLE
//#define TAPPING_TOGGLE 2  don't really use tapping toggle
#undef QUICK_TAP_TERM
#define QUICK_TAP_TERM 90  // allow quick double-tapping to access hold function

// user mouse key settings
#ifdef MOUSEKEY_ENABLE
  #undef MOUSEKEY_DELAY
  #define MOUSEKEY_DELAY 0
  #undef MOUSEKEY_MAX_SPEED
  #define MOUSEKEY_MAX_SPEED 15
  #undef MOUSEKEY_INTERVAL
  #define MOUSEKEY_INTERVAL 15
  #undef MOUSEKEY_TIME_TO_MAX
  #define MOUSEKEY_TIME_TO_MAX 80
  #undef MOUSEKEY_WHEEL_DELAY
  #define MOUSEKEY_WHEEL_DELAY 150
  #undef MOUSEKEY_WHEEL_INTERVAL
  #define MOUSEKEY_WHEEL_INTERVAL 100
  #undef MOUSEKEY_WHEEL_TIME_TO_MAX
  #define MOUSEKEY_WHEEL_TIME_TO_MAX 30
  #undef MOUSEKEY_WHEEL_MAX_SPEED
  #define MOUSEKEY_WHEEL_MAX_SPEED 10
#endif

// split keyboard oled data transfer
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

// oled timeout (in ms)
// fade out 15 adds 50s, 3.33s per level
#ifdef OLED_ENABLE
#  define OLED_TIMEOUT 10000
#  define OLED_FADE_OUT
#  define OLED_FADE_OUT_INTERVAL 12
#endif

// rgb matrix timeout (in ms)
#ifdef RGB_MATRIX_ENABLE
#  define RGB_MATRIX_TIMEOUT 50000
#endif

// rgb backlight timeout (in ms)
#ifdef RGBLIGHT_ENABLE
#  define RGBLIGHT_TIMEOUT 50000
#endif

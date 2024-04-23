#pragma once
// master handedness for split keyboards
#define MASTER_RIGHT

// user tap/hold settings
#undef TAPPING_TERM
#define TAPPING_TERM 350
#undef IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
#define PERMISSIVE_HOLD
#undef TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2
#undef QUICK_TAP_TERM
#define QUICK_TAP_TERM 0

// user mouse key settings
#ifdef MOUSEKEY_ENABLE
  #define MOUSEKEY_DELAY 0
  #define MOUSEKEY_MAX_SPEED 15
  #define MOUSEKEY_INTERVAL 15
  #define MOUSEKEY_TIME_TO_MAX 80
  #define MOUSEKEY_WHEEL_DELAY 150
  #define MOUSEKEY_WHEEL_INTERVAL 100
  #define MOUSEKEY_WHEEL_TIME_TO_MAX 30
  #define MOUSEKEY_WHEEL_MAX_SPEED 10
#endif

// split keyboard oled data transfer
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE

// oled timeout (in ms)
#ifdef OLED_ENABLE
#  define OLED_TIMEOUT 50000
#endif

// rgb matrix timeout (in ms)
#ifdef RGB_MATRIX_ENABLE
#  define RGB_MATRIX_TIMEOUT 50000
#endif

// rgb backlight timeout (in ms)
#ifdef RGBLIGHT_ENABLE
#  define RGBLIGHT_TIMEOUT 50000
#endif

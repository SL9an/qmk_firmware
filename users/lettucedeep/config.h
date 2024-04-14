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

// oled timeout (in ms)
#ifdef OLED_ENABLE
#  define OLED_TIMEOUT 30000
#endif

// rgb matrix timeout (in ms)
#ifdef RGB_MATRIX_ENABLE
#  define RGB_MATRIX_TIMEOUT 30000
#endif

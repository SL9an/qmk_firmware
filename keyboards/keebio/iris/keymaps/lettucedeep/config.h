/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// #define USE_I2C
#define EE_HANDS
#define RGBLIGHT_SLEEP

#undef TAPPING_TERM
#define TAPPING_TERM 200
#undef IGNORE_MOD_TAP_INTERRUPT
/* #define IGNORE_MOD_TAP_INTERRUPT */
#undef PERMISSIVE_HOLD
#define PERMISSIVE_HOLD
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

#define MOUSEKEY_DELAY 0
#define MOUSEKEY_MAX_SPEED 15
#define MOUSEKEY_INTERVAL 15
#define MOUSEKEY_TIME_TO_MAX 80

#define MOUSEKEY_WHEEL_DELAY 150
#define MOUSEKEY_WHEEL_INTERVAL 100
#define MOUSEKEY_WHEEL_TIME_TO_MAX 30
#define MOUSEKEY_WHEEL_MAX_SPEED 10 

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTLOADER = atmel-dfu      # lily58 parent rules spec caterina, use dfu instead
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight. 
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
OLED_DRIVER_ENABLE = yes    # OLED display
WPM_ENABLE = no             # supplies get_current_wpm function for bongocat

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

KEYBOARD_lily58_rev1 = no

TAP_DANCE_ENABLE = no
STENO_ENABLE = no
TERMINAL_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
KEY_LOCK_ENABLE = no
AUDIO_ENABLE = no
CONSOLE_ENABLE = no
VELOCIKEY_ENABLE = no

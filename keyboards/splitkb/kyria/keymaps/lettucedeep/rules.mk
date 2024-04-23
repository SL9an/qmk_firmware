OLED_ENABLE = yes          # Enables the use of OLED displays
ENCODER_ENABLE = no        # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
RGBLIGHT_ANIMATIONS = no

BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
WPM_ENABLE = yes            # supplies get_current_wpm function for bongocat

MODULAR_BONGOCAT_ENABLE = yes # dake's modular bongocat
KYRIA_LOGO_ENABLE = yes       # modular bongocat
QMK_LOGO_ENABLE = yes         # modular bongocat

# Modular Bongocat
MODULAR_BONGOCAT_ENABLE ?= no
ifeq ($(strip $(MODULAR_BONGOCAT_ENABLE)), yes)
    SRC += modular_bongocat.c
    OPT_DEFS += -DMODULAR_BONGOCAT_ENABLE

    QMK_LOGO_ENABLE ?= yes
    KYRIA_LOGO_ENABLE ?= yes
    ifeq ($(strip $(QMK_LOGO_ENABLE)), yes)
         OPT_DEFS += -DQMK_LOGO_ENABLE
    endif
    ifeq ($(strip $(KYRIA_LOGO_ENABLE)), yes)
         OPT_DEFS += -DKYRIA_LOGO_ENABLE
    endif

    OLED_ENABLE = yes
    OLED_DRIVER_ENABLE = yes
endif

# added from j-inc
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

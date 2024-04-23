#include QMK_KEYBOARD_H
#include <string.h>


enum layers {
    _BASE = 0,
    _NUMBER,
    _SYMBOL,
    _NAV,
    _MEDIA,
    _RGB,
};


// slave side info
static void render_billboard(const char line_1[], const char line_2[], const char line_3[]) {
    // board info
    oled_write_P(line_1, false);
    oled_write_P(line_2, false);
    oled_write_P(line_3, false);
    // mod status
    uint8_t mods = get_mods();
    char active[19];
    char inactive[19];
    active[0] = '\0';
    inactive[0] = '\0';
    if (mods & MOD_MASK_CTRL) {
        strcat(active, "CTRL ");
    } else {
        strcat(inactive, "     ");
    }
    if (mods & MOD_MASK_ALT) {
        strcat(active, "ALT ");
    } else {
        strcat(inactive, "    ");
    }
    if (mods & MOD_MASK_SHIFT) {
        strcat(active, "SHIFT ");
    } else {
        strcat(inactive, "      ");
    }
    if (mods & MOD_MASK_GUI) {
        strcat(active, "GUI");
    } else {
        strcat(inactive, "   ");
    }
    strcat(active, inactive);
    oled_write(active, false);
    // oled_write_P(PSTR(active), false);

    /*
    oled_write_P((mods & MOD_MASK_CTRL) ? PSTR("CTRL ") : PSTR("     "), false);
    oled_write_P((mods & MOD_MASK_ALT) ? PSTR("ALT ") : PSTR("    "), false);
    oled_write_P((mods & MOD_MASK_SHIFT) ? PSTR("SHIFT ") : PSTR("      "), false);
    oled_write_P((mods & MOD_MASK_GUI) ? PSTR("GUI") : PSTR("   "), false);
    */
    //oled_write_P(PSTR("\n"), false);
}


// Render Master OLED display
static void render_status(void) {

    // Layer indicator
    oled_write_P(PSTR("   layer:  "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("BASE"), false);
            break;
        case _NUMBER:
            oled_write_P(PSTR("NUMBER"), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("SYMBOL"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("MEDIA"), false);
            break;
        case _RGB:
            oled_write_P(PSTR("RGB"), false);
            break;
       default:
           oled_write_P(PSTR("undefined"), false);
           break;
    }
    //oled_write_P(PSTR("\n"), false);

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(PSTR("\n   numlck: "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("ON") : PSTR("--"), false);
    oled_write_P(PSTR("\n   caplck: "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("ON") : PSTR("--"), false);
    oled_write_P(PSTR("\n   scrlck: "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("ON") : PSTR("--"), false);
}

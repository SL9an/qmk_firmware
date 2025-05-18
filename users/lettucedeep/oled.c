#include QMK_KEYBOARD_H
#include <string.h>


// Render Slave OLED (billboard and ctrl/alt/shift/gui modifier status)
static void render_billboard(const char line_1[], const char line_2[], const char line_3[]) {
    // board info
    oled_write_P(line_1, false);
    oled_write_P(line_2, false);
    oled_write_P(line_3, false);
    // mod status left aligned
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

    // mod status static positions
    /*
    oled_write_P((mods & MOD_MASK_CTRL) ? PSTR("CTRL ") : PSTR("     "), false);
    oled_write_P((mods & MOD_MASK_ALT) ? PSTR("ALT ") : PSTR("    "), false);
    oled_write_P((mods & MOD_MASK_SHIFT) ? PSTR("SHIFT ") : PSTR("      "), false);
    oled_write_P((mods & MOD_MASK_GUI) ? PSTR("GUI") : PSTR("   "), false);
    */
    //oled_write_P(PSTR("\n"), false);
}


// Render Master OLED display (layers and num/cap/scroll lock status)
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
    oled_write_P(PSTR("\n   numlck: "), false);
    oled_write_P(host_keyboard_led_state().num_lock ? PSTR("ON") : PSTR("--"), false);
    oled_write_P(PSTR("\n   caplck: "), false);
    oled_write_P(host_keyboard_led_state().caps_lock ? PSTR("ON") : PSTR("--"), false);
    oled_write_P(PSTR("\n   scrlck: "), false);
    oled_write_P(host_keyboard_led_state().scroll_lock ? PSTR("ON") : PSTR("--"), false);
}

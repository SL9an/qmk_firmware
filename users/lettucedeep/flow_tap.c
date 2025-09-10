#include QMK_KEYBOARD_H


bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        //case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}


uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
    if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
        // a lower value here makes holds more permissive
	switch (keycode) {
	    case LSFT_T(KC_D):
	    case RSFT_T(KC_K):
	        //return FLOW_TAP_TERM - 85;
		return 10;

	    default:
		return FLOW_TAP_TERM;
	}
    }
    // returning 0 disables flow tap
    return 0;
}

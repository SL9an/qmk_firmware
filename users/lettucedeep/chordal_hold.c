#include QMK_KEYBOARD_H

// per-chord customization
// @SEE https://docs.qmk.fm/tap_hold#chordal-hold
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
	// nav layer
	case MO(_NAV):
	    return true;
	    break;
	    
	// media layer
	case MO(_MEDIA):
	    return true;
	    break;

	// rgb layer
	case MO(_RGB):
	    return true;
	    break;

	// number layer
        case LT(_NUMBER, KC_SPC):
	    return true;
            break;
	
	// symbol layer
	case LT(_SYMBOL, KC_BSPC):
	    return true;
	    break;
	
	// left-handed cmd/gui chords
	case LGUI_T(KC_F):
	    if (other_keycode == KC_TAB) {
	        return true;
	    }

	// left-handed space-cadet ctrl chords
	case LCTL_T(KC_ESC):
	    if (other_keycode == KC_TAB ||
                other_keycode == KC_Q) {
                return true;
	    }
	    break;

	// common left-handed ctrl chords
	case LCTL_T(KC_A):
	    if (other_keycode == KC_X ||
		other_keycode == KC_C ||
		other_keycode == KC_V ||
		other_keycode == KC_F ||
		other_keycode == KC_D ||
		other_keycode == KC_T ||
		other_keycode == KC_G ||
		other_keycode == KC_R ||
		other_keycode == KC_W) {
                return true;
	    }
	    break;
    }
    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}

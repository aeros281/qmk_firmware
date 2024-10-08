#include QMK_KEYBOARD_H

#define HOME_SLASH KC_SLSH

// #define HOME_A LGUI_T(KC_A)
// #define HOME_S LALT_T(KC_S)
// #define HOME_D LCTL_T(KC_D)
// #define HOME_F LSFT_T(KC_F)

// #define HOME_J LSFT_T(KC_J)
// #define HOME_K LCTL_T(KC_K)
// #define HOME_L LALT_T(KC_L)
// #define HOME_SCLN LGUI_T(KC_SCLN)

#define HOME_A KC_A
#define HOME_S KC_S
#define HOME_D KC_D
// #define HOME_F KC_F
#define HOME_F LSFT_T(KC_F)

// #define HOME_J KC_J
#define HOME_J LSFT_T(KC_J)
#define HOME_K KC_K
#define HOME_L KC_L
#define HOME_SCLN KC_SCLN

#define M_SPACE KC_SWAP_ENTER
#define M_ENTER KC_SWAP_SPACE

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_se_swap_active = true;

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_COLEMAK,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_DWORD,
    KC_TGUK,
    KC_MTASK,
    KC_NXTTAB,
    KC_PRVTAB,
    KC_VIMSEARCH,
    KC_SWAP_SPACE,
    KC_SWAP_ENTER,
    KC_SWAP_SE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Enter | /LOWER  /       \RAISE \  |SPACE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  MT(MOD_LCTL, KC_ESC),   HOME_A,   HOME_S,    HOME_D,    HOME_F,    KC_G,             KC_H,    HOME_J,    HOME_K,    HOME_L, HOME_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,      KC_MTASK,           KC_TGUK, KC_N,    KC_M, KC_COMM,  KC_DOT, HOME_SLASH,  KC_RSFT,
  KC_LGUI,  KC_LALT,KC_LCTRL, M_ENTER,        KC_LOWER,             KC_RAISE,  M_SPACE, KC_RCTRL, KC_RALT, KC_RGUI
),

/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |ENTER | /LOWER  /       \RAISE \  |SPACE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAK] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                                KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_BSPC,
  KC_ESC,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                                KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,     KC_MUTE,      XXXXXXX,     KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTRL,M_ENTER, KC_LOWER,     KC_RAISE,  M_SPACE, KC_RCTRL, KC_RALT, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   =  |   (  |   )  |   {  |   }  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   | COPY | PASTE|   }  |-------|    |-------|   +  |   [  |   ]  |   ]  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |ENTER | /LOWER  /       \RAISE \  | Bspc | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  KC_MTASK,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_EQL, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_PIPE,
  _______,  KC_EQL, KC_MINS, KC_COPY, KC_PASTE, KC_RCBR, _______,       _______, KC_PLUS, KC_LBRC, KC_RBRC, KC_RBRC, KC_BSLS, _______,
                    _______, _______, _______, _______, _______,       _______, KC_DLINE, _______, _______, _______
),

/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  | LAt  | LCtl |LShift| VIMS | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------| Bspc | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |ENTER | / LOWER /      \RAISE \   |SPACE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,KC_DLINE, KC_BSPC,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  KC_VIMSEARCH, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
  _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  KC_BSPC, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|COLMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      | LANG |      |-------.    ,-------|      | TAB | MTASK  | TAB  |      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT | VIMSE|      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  RESET  , XXXXXXX,KC_QWERTY,KC_COLEMAK,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    KC_TGUK,  XXXXXXX,                     XXXXXXX, KC_PRVTAB, KC_MTASK, KC_NXTTAB, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     KC_SWAP_SE, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_VIMSEARCH, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }
    if (is_se_swap_active) {
        oled_write_ln_P(PSTR("SWAP"), false);
    } else {
        oled_write_ln_P(PSTR("N-SWP"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SWAP_SE:
            if (record->event.pressed) {
                is_se_swap_active = !is_se_swap_active;
            }
            return false;
        case KC_SWAP_ENTER:
            if (record->event.pressed) {
                if (is_se_swap_active) {
                    register_code(KC_SPC);
                } else {
                    register_code(KC_ENT);
                }
            } else {
                if (is_se_swap_active) {
                    unregister_code(KC_SPC);
                } else {
                    unregister_code(KC_ENT);
                }
            }
            return false;
        case KC_SWAP_SPACE:
            if (record->event.pressed) {
                if (is_se_swap_active) {
                    register_code(KC_ENT);
                } else {
                    register_code(KC_SPC);
                }
            } else {
                if (is_se_swap_active) {
                    unregister_code(KC_ENT);
                } else {
                    unregister_code(KC_SPC);
                }
            }
            return false;
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                } else {
                    register_mods(mod_config(MOD_LCTL));
                }
                register_code(KC_BSPC);
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                }
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
        case KC_TGUK:
            if (keymap_config.swap_lctl_lgui) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_SLSH);
                } else {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_SLSH);
                }
            } else {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LSFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LSFT);
                }
            }
            return false;
        case KC_MTASK:
            if (keymap_config.swap_lctl_lgui) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_TAB);
                } else {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_TAB);
                }
            } else {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_SPC);
                } else {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_SPC);
                }
            }
            return false;
        case KC_NXTTAB:
            if (keymap_config.swap_lctl_lgui) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LCTL));
                    register_mods(mod_config(MOD_LSFT));
                    register_code(KC_RCBR);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_mods(mod_config(MOD_LSFT));
                    unregister_code(KC_RCBR);
                }
            } else {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_PAGE_DOWN);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_PAGE_DOWN);
                }
            }
            return false;
        case KC_PRVTAB:
            if (keymap_config.swap_lctl_lgui) {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LCTL));
                    register_mods(mod_config(MOD_LSFT));
                    register_code(KC_LCBR);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_mods(mod_config(MOD_LSFT));
                    unregister_code(KC_LCBR);
                }
            } else {
                if (record->event.pressed) {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_PAGE_UP);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_PAGE_UP);
                }
            }
            return false;
        case KC_VIMSEARCH:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_BSLS) SS_DELAY(100) SS_TAP(X_BSLS) SS_DELAY(100) SS_TAP(X_S));
            }
            return false;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return 300;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state|default_layer_state) > 0) {
        if (!clockwise) {
            tap_code16(C(KC_TAB));
        } else {
            tap_code16(S(C(KC_TAB)));
        }
    } else { /* Layer 0 */
        if (index == 0) {
            if (!clockwise) {
                if (keymap_config.swap_lctl_lgui) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code16(C(G(KC_RGHT)));
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code16(C(G(KC_LEFT)));
                }
            }
        } else if (index == 1) {
            if (!clockwise) {
                if (keymap_config.swap_lctl_lgui) {
                    tap_code(KC_PGDOWN);
                } else {
                    if (!is_alt_tab_active) {
                        is_alt_tab_active = true;
                        register_code(KC_LALT);
                    }
                    alt_tab_timer = timer_read();
                    tap_code16(KC_TAB);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    tap_code(KC_PGDOWN);
                } else {
                    if (!is_alt_tab_active) {
                        is_alt_tab_active = true;
                        register_code(KC_LALT);
                    }
                    alt_tab_timer = timer_read();
                    tap_code16(S(KC_TAB));
                }
            }
        }
    }
    return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1250) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

#endif

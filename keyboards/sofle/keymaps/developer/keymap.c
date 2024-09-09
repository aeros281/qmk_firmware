// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#define M_SPACE LT(RAISE, KC_SPC)
#define M_SPCM LT(RAISE_MAC, KC_SPC)
#define M_BSPC LT(LOWER, KC_BSPC)
#define M_MSEN LT(MOUSE, KC_ENT)
#define M_TMUX LT(MACROS, LCTL(KC_B))

#define W_DELW LCTL(KC_BSPC)
#define W_PREVW LCTL(KC_LEFT)
#define W_NEXTW LCTL(KC_RGHT)
#define W_PREVT LCTL(LSFT(KC_TAB))
#define W_NEXTT LCTL(KC_TAB)

#define M_NEXTT LGUI(LALT(KC_RGHT))
#define M_PREVT LGUI(LALT(KC_LEFT))
#define M_NEXTW LALT(KC_RGHT)
#define M_PREVW LALT(KC_LEFT)
#define M_DELW LALT(KC_BSPC)

#define M_ESC MT(MOD_LCTL, KC_ESC)
#define M_ESCM MT(MOD_LGUI, KC_ESC)
#define HOME_A MT(MOD_LGUI, KC_A)
#define HOME_S MT(MOD_LALT, KC_S)
#define HOME_D MT(MOD_LCTL, KC_D)
#define HOME_F LSFT_T(KC_F)

#define HOME_K MT(MOD_LCTL, KC_K)
#define HOME_L MT(MOD_LALT, KC_L)
#define HOME_SCLN MT(MOD_LGUI, KC_SCLN)
#define HOME_J LSFT_T(KC_J)

enum layers {
    QWERTY, // 0
    MACOS, // 1
    RAISE, // 2
    LOWER, // 3
    RAISE_MAC, // 4
    MOUSE, // 5
    MACROS, // 6
    SYSTEM, // 7
};

enum custom_keycodes {
    KC_TMUX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
  M_ESC,    HOME_A, HOME_S,  HOME_D,  HOME_F,  KC_G,                     KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_MUTE ,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTL, M_MSEN, M_BSPC,      M_SPACE,  M_TMUX, KC_RCTL, KC_RALT, TO(MACOS)
),


[RAISE] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,QK_BOOT,
  _______, _______ , W_PREVT , _______ , W_NEXTT , _______,                           KC_PGUP,  W_PREVW  , KC_UP  ,  W_NEXTW ,  _______ ,_______,
  _______, _______ , _______ , _______ , _______ , KC_CAPS_LOCK,                      KC_PGDN,  KC_LEFT  , KC_DOWN,  KC_RGHT ,  _______ ,_______,
  _______,_______, KC_VOLD, KC_MUTE, KC_VOLU, _______,  _______,       _______,  _______, _______, _______, _______,   _______, _______,
                         _______, _______, _______, CW_TOGG, W_DELW,       _______, _______, _______, _______, _______
),

[RAISE_MAC] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,QK_BOOT,
  _______, _______ , M_PREVT , _______ , M_NEXTT , _______,                           KC_PGUP,  M_PREVW  , KC_UP  ,  M_NEXTW ,  _______ ,_______,
  _______, _______ , _______ , _______ , _______ , KC_CAPS_LOCK,                      KC_PGDN,  KC_LEFT  , KC_DOWN,  KC_RGHT ,  _______ ,_______,
  _______,_______, KC_VOLD, KC_MUTE, KC_VOLU, _______,  _______,       _______,  _______, _______, _______, _______,   _______, _______,
                         _______, _______, _______, CW_TOGG, M_DELW,       _______, _______, _______, _______, _______
),

[LOWER] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,    KC_F7,     KC_F8,    KC_F9,     KC_F10,  KC_F11,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,     KC_7,      KC_8,     KC_9,      KC_0,    KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_EQL,   KC_LPRN,   KC_RPRN,  KC_LCBR ,  KC_RCBR ,KC_PIPE,
  _______, KC_CIRC, KC_AMPR, KC_LT,   KC_GT,   KC_ASTR,  _______,        _______,  KC_PLUS,  KC_LBRC,   KC_RBRC,  _______,   _______, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

[MACOS] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSLS,
  M_ESCM,    HOME_A, HOME_S,  HOME_D,  HOME_F,  KC_G,                     KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_MUTE ,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTL, M_MSEN, M_BSPC,      M_SPCM,   M_TMUX, KC_RCTL, KC_RALT, TO(QWERTY)
),

[MOUSE] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , KC_LGUI,  KC_LALT,   KC_LCTL,  KC_LSFT, XXXXXXX,                     KC_WH_U, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,  XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX,                     KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     KC_BTN1, _______, KC_BTN3, _______, _______
  ),

[MACROS] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______  ,  _______ ,  _______ ,_______,
  _______, _______ , _______ , _______ , _______ , _______,                      _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,_______, _______, _______, _______, _______,  _______,       _______,  _______, _______, _______, _______,   _______, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

[SYSTEM] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,QK_BOOT,
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______  ,  _______ ,  _______ ,_______,
  _______, _______ , _______ , _______ , _______ , _______,                      _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,_______, _______, _______, _______, _______,  _______,       _______,  _______, _______, _______, _______,   _______, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_TMUX:
            if (record->tap.count && record->event.pressed) {
                tap_code16(C(KC_B));
                return false;
            }
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif

#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
};


enum tap_dance_codes {
  DANCE_0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    MT(MOD_LGUI, KC_GRAVE),KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           LCTL(LSFT(KC_TAB)),                                LCTL(KC_TAB),   KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           TG(5),                                          TG(3),          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,      
    MT(MOD_LCTL, KC_ESCAPE),KC_A,           KC_S,           KC_D,           MT(MOD_LSFT, KC_F),KC_G,           ALL_T(KC_PGDOWN),                                                                MEH_T(KC_PGUP), KC_H,           MT(MOD_RSFT, KC_J),KC_K,           KC_L,           LT(6,KC_SCOLON),MT(MOD_LGUI, KC_QUOTE),
    OSL(2),         KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       OSL(2),         
    TO(7),          LGUI(LSFT(KC_S)),LALT(KC_LSHIFT),LCTL(KC_BSPACE),LT(2,KC_ENTER), TD(DANCE_0),                                                                                                    KC_DELETE,      LT(3,KC_SPACE), TG(6),          KC_LBRACKET,    KC_RBRACKET,    TG(6),          
    KC_BSPACE,      CAPS_WORD,      KC_LGUI,                        KC_LCTRL,       LCTL(KC_B),     KC_LALT
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 TG(4),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MT(MOD_LGUI, KC_ESCAPE),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MT(MOD_LALT, KC_QUOTE),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LALT(LSFT(KC_S)),KC_LCTRL,       KC_LALT,        KC_TRANSPARENT, LALT(KC_TAB),                                                                                                   KC_TRANSPARENT, LT(4,KC_SPACE), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_LCTRL
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_F12,         
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_EQUAL,       KC_LPRN,        KC_RPRN,        KC_LCBR,        KC_RCBR,        KC_PIPE,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_PLUS,        KC_LBRACKET,    KC_RBRACKET,    KC_LABK,        KC_RABK,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 LCTL(KC_B),     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LALT(KC_SPACE), LALT(KC_F4),    LCTL(LSFT(KC_TAB)),ST_MACRO_0,     LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PGUP,        LCTL(KC_LEFT),  KC_UP,          LCTL(KC_RIGHT), KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_1,     KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_2,     ST_MACRO_3,     KC_PC_COPY,     KC_PC_PASTE,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_HOME,        KC_TRANSPARENT, KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(LCTL(KC_LEFT)),LGUI(LCTL(KC_RIGHT)),KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LCTL(KC_BSPACE),KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LALT(KC_TAB),   LGUI(KC_Q),     LCTL(LSFT(KC_TAB)),ST_MACRO_4,     LCTL(KC_TAB),   KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PGUP,        LALT(KC_LEFT),  KC_UP,          LALT(KC_RIGHT), KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_5,     KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_6,     ST_MACRO_7,     KC_MAC_COPY,    KC_MAC_PASTE,   KC_TRANSPARENT,                                 KC_TRANSPARENT, LGUI(KC_LEFT),  KC_TRANSPARENT, LGUI(KC_RIGHT), KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    LALT(KC_BSPACE),KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_KP_SLASH,    KC_KP_MINUS,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP,          KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_HASH,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_GRAVE,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_DOWN,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_TILD,                                        KC_AMPR,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_COMMA,       HSV_0_255_255,  HSV_86_255_128, HSV_172_255_255,RGB_MOD,                                                                                                        RGB_TOG,        KC_TRANSPARENT, KC_TRANSPARENT, KC_0,           KC_EQUAL,       KC_TRANSPARENT, 
    KC_TRANSPARENT, RGB_VAI,        TOGGLE_LAYER_COLOR,                RGB_SLD,        RGB_HUD,        KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET,          
    MU_TOG,         KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, RGB_VAI,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, TO(0),          TO(1),          TO(7),          KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    RGB_VAD,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN3,     KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_TRANSPARENT,                                 KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [7] = LAYOUT_moonlander(
    KC_9,           KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_F4),    
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_7,                                           KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,      
    KC_LCTRL,       KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_8,                                                                           KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,       
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_BSPACE,      KC_I,           KC_O,           OSL(9),         KC_SPACE,       KC_LALT,                                                                                                        TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MO(8),          KC_ESCAPE,      KC_0,                           TG(9),          KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [8] = LAYOUT_moonlander(
    KC_F9,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_F6,                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_N,           KC_J,           KC_I,           KC_O,           KC_H,           KC_P,           KC_F7,                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_4,           KC_1,           KC_2,           KC_3,           KC_5,           KC_L,           KC_F8,                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_M,           KC_TRANSPARENT, KC_TRANSPARENT, KC_U,           KC_K,           KC_Y,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CAPSLOCK,                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_K,           TO(0),                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [9] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_ENTER,       KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {130,218,204}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {253,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {130,218,204}, {188,255,255}, {130,218,204}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {130,218,204}, {188,255,255}, {188,255,255}, {130,218,204}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {34,255,255}, {130,218,204}, {188,255,255}, {130,218,204}, {24,218,204}, {188,255,255}, {80,255,255} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {219,255,255}, {141,244,247}, {0,0,0}, {0,0,0}, {0,245,245}, {219,255,255}, {141,244,247}, {0,0,0}, {0,0,0}, {0,245,245}, {219,255,255}, {141,244,247}, {0,0,0}, {0,0,0}, {0,245,245}, {219,255,255}, {141,244,247}, {0,0,0}, {0,0,0}, {0,245,245}, {219,255,255}, {141,244,247}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,245,245}, {74,255,255}, {0,0,0}, {0,0,0}, {0,245,245}, {219,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,245,245}, {219,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,245,245}, {219,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,245,245}, {219,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,245,245}, {219,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {139,193,83} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,248}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {161,255,255}, {161,255,255}, {161,255,255}, {0,0,0}, {0,0,0}, {161,255,255}, {161,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {161,255,255}, {161,255,255}, {161,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {156,244,247}, {156,244,247}, {156,244,247}, {0,0,0}, {0,0,0}, {156,244,247}, {156,244,247}, {156,244,247}, {0,0,0}, {0,0,0}, {156,244,247}, {156,244,247}, {156,244,247}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {130,218,204}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {130,218,204}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {130,218,204}, {28,218,204}, {28,218,204}, {28,218,204}, {0,0,0}, {130,218,204}, {28,218,204}, {28,218,204}, {28,218,204}, {0,0,0}, {130,218,204}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {130,218,204}, {130,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {74,255,255}, {0,0,0}, {74,255,255}, {74,255,255}, {253,255,255}, {253,255,255}, {253,255,255}, {253,255,255}, {130,218,204}, {253,255,255}, {253,255,255}, {253,255,255}, {74,255,255}, {130,218,204}, {253,255,255}, {253,255,255}, {253,255,255}, {0,0,0}, {130,218,204}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {57,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {161,255,255}, {130,218,204}, {0,0,0}, {0,0,0}, {161,255,255}, {161,255,255}, {130,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {161,255,255}, {130,218,204}, {161,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {208,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {208,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {186,218,204}, {161,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {186,218,204}, {161,255,255}, {130,218,204}, {208,218,204}, {0,0,0}, {186,218,204}, {161,255,255}, {130,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {130,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [7] = { {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {0,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,218,204}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [8] = { {186,218,204}, {156,244,247}, {0,218,204}, {0,0,0}, {0,0,0}, {186,218,204}, {156,244,247}, {0,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {156,244,247}, {0,218,204}, {0,0,0}, {0,0,0}, {186,218,204}, {156,244,247}, {0,218,204}, {0,0,0}, {0,0,0}, {186,218,204}, {156,244,247}, {0,218,204}, {0,0,0}, {0,0,0}, {186,218,204}, {156,244,247}, {156,244,247}, {156,244,247}, {186,218,204}, {186,218,204}, {186,218,204}, {156,244,247}, {156,244,247}, {0,0,0}, {74,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [9] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {156,244,247}, {0,0,0}, {0,0,0}, {0,0,0}, {156,244,247}, {156,244,247}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {156,244,247}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {156,244,247}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
    case 9:
      set_layer_color(9);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_L)) SS_DELAY(100) SS_LSFT(SS_TAP(X_5)) SS_DELAY(100) SS_TAP(X_SPACE));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_BSLASH) SS_DELAY(100) SS_TAP(X_BSLASH) SS_DELAY(100) SS_TAP(X_S));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(100) SS_LSFT(SS_TAP(X_EQUAL)));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(100) SS_LSFT(SS_TAP(X_EQUAL)) SS_DELAY(100) SS_TAP(X_P));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_L)) SS_DELAY(100) SS_LSFT(SS_TAP(X_5)) SS_DELAY(100) SS_TAP(X_SPACE));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_BSLASH) SS_DELAY(100) SS_TAP(X_BSLASH) SS_DELAY(100) SS_TAP(X_S));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(100) SS_LSFT(SS_TAP(X_EQUAL)));

    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_QUOTE)) SS_DELAY(100) SS_LSFT(SS_TAP(X_EQUAL)) SS_DELAY(100) SS_TAP(X_P));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
  }
  return true;
}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LALT(KC_SPACE));
        tap_code16(LALT(KC_SPACE));
        tap_code16(LALT(KC_SPACE));
    }
    if(state->count > 3) {
        tap_code16(LALT(KC_SPACE));
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(LALT(KC_SPACE)); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(LALT(KC_SPACE)); register_code16(LALT(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LALT(KC_SPACE)); register_code16(LALT(KC_SPACE));
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LALT(KC_SPACE)); break;
    }
    dance_state[0].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};


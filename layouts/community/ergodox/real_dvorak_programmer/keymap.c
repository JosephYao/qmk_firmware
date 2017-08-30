
#include QMK_KEYBOARD_H
#include "led.h"
#include "debug.h"
#include "action_layer.h"
#include "action_code.h"

#define BASE    0 // default layer
#define SHIFT 1
#define SHELL_NAV 2
#define KEY_NAV 3 // key navigation layer
#define KEY_SEL 4 // key selection layer
#define NUMBER  5  // number layer
#define SYMBOL  6
#define BRACKETS  7
#define SHORTCUTS 8
#define MOUSE 9

// macros
#define MC_COPY_LINE  0
#define MC_CUT_LINE   1
#define MC_PASTE_LINE 2
#define MC_NEW_SEARCH_TAB 3
#define SCREEN_TAB_LEFT 4
#define SCREEN_TAB_RIGHT 5
#define SCREEN_NEW_TAB 6
#define SWITCH_NDS 7
#define SCREEN_COPY_MODE 8
#define SCREEN_PASTE 9
#define OPEN_CLOSE_PAREN 10
#define OPEN_CLOSE_BRACKET 11
#define OPEN_CLOSE_CURLY 12
#define OPEN_CLOSE_SINGLE_QUOTE 13
#define OPEN_CLOSE_DOUBLE_QUOTE 14
#define SHELL_RECALL_LAST_ARG_REMOVE_FIRST_COMMAND 15
#define SEMICOLON_NEWLINE 16
#define END_NEWLINE 17


const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// base layer
[BASE] =
LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_DLR, KC_AMPR, KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_EQL,
        KC_TAB, KC_SCLN, KC_COMM, KC_DOT, KC_P, KC_Y, KC_TRNS,
        KC_ESC, KC_A, KC_O, KC_E, KC_U, KC_I,
        MO(SHIFT), KC_QUOT, KC_Q, KC_J, KC_K, KC_X, KC_TRNS,
        KC_TRNS, KC_LEFT, KC_LCTL, KC_LALT, KC_LGUI,
// thumb cluster
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_SPC, KC_TRNS, KC_TRNS,
// right hand
        KC_ASTR, KC_RPRN, KC_PLUS, KC_RBRC, KC_EXLM, KC_HASH, KC_BSPC,
        KC_TRNS, KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
        KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS,
        KC_TRNS, KC_B, KC_M, KC_W, KC_V, KC_Z, MO(SHIFT),
// lower keys - browser tab control
        KC_UP, KC_DOWN, KC_AT, KC_RIGHT, KC_BSLASH,
// thumb cluster
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_ENT
),


// shift layer
[SHIFT] =
LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_TILD, KC_PERC, KC_7, KC_5, KC_3, KC_1, KC_9,
        KC_TAB, KC_COLN, S(KC_COMM), S(KC_DOT), S(KC_P), S(KC_Y), KC_TRNS,
        KC_ESC, S(KC_A), S(KC_O), S(KC_E), S(KC_U), S(KC_I),
        KC_TRNS, S(KC_QUOT), S(KC_Q), S(KC_J), S(KC_K), S(KC_X), KC_TRNS,
        KC_TRNS, KC_LEFT, KC_LCTL, KC_LALT, KC_LGUI,
// thumb cluster
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_SPC, KC_TRNS, KC_TRNS,
// right hand
        KC_0, KC_2, KC_4, KC_6, KC_8, KC_GRV, KC_BSPC,
        KC_TRNS, S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L), KC_QUES,
        S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S), KC_UNDS,
        KC_TRNS, S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z), KC_TRNS,
// lower keys - browser tab control
        KC_UP, KC_DOWN, KC_CIRC, KC_RIGHT, KC_PIPE,
// thumb cluster
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_ENT
),

};

bool any_shift_mod_keys(uint16_t kc) {
    return kc == KC_TAB || kc == KC_ESC;
}

bool process_record_user(uint16_t kc, keyrecord_t *rec) {
    if (biton32(layer_state) == SHIFT && rec->event.pressed && any_shift_mod_keys(kc))
        register_mods(MOD_LSFT);
    else
        unregister_mods(MOD_LSFT);
    return true;
}


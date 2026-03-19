#include QMK_KEYBOARD_H
#include "keymap_uk.h"

enum layers {
    _BASE = 0,
    _MAC,
    _SHIFT,
    _MAC_SHIFT,
    _NAV,
    _MAC_NAV,
    _NUM,
    _SYM,
    _MAC_SYM,
    _FUNCTION,
    _MEDIA,
    _ADJUST,
};

#define EXPAND  LCTL(KC_QUOTE)
#define MEXPAND LGUI(KC_QUOTE)
#define SHRINK  LCTL(LALT(LGUI(KC_QUOTE)))
#define LC_LB   MT(MOD_LCTL, KC_LBRC)
#define LG_LB   MT(MOD_LGUI, KC_LBRC)
#define CAG_RB  MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_RBRC)
#define PIPE    LSFT(KC_NUBS)

#define NAV_SP  LT(_NAV, KC_SPC)
#define MNAV_SP  LT(_MAC_NAV, KC_SPC)
#define SFT_BSP LT(_SHIFT, KC_BSPC)
#define MSFT_BSP LT(_MAC_SHIFT, KC_BSPC)
#define NUM_ENT LT(_NUM, KC_ENT)
#define SYM_ENT LT(_SYM, KC_TAB)
#define MSYM_ENT LT(_MAC_SYM, KC_TAB)
#define MEDIA   MO(_MEDIA)

#define CTL_TAB  LCTL(KC_TAB)
#define ALT_TAB  LALT(KC_TAB)
#define GUI_TAB  LGUI(KC_TAB)
#define GUI_NUBS LGUI(KC_NUBS)
#define CTL_F12  LCTL(KC_F12)
#define GUI_F12  LGUI(KC_F12)
#define CAG_SPC  LCTL(LALT(LGUI(KC_SPC)))

#define LOAD QK_BOOTLOADER
#define LOCK LCTL(LGUI(KC_Q))

const uint16_t PROGMEM combo_z[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_Z[] = {KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_ctl[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo_shift_ctl[] = {KC_A, KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM combo_alt[] = {KC_N, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM combo_alt_ctl[] = {KC_N, KC_E, KC_I, KC_O, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_z, KC_Z),
    COMBO(combo_Z, S(KC_Z)),
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_ctl, OSM(MOD_LCTL)),
    COMBO(combo_shift_ctl, OSM(MOD_LCTL | MOD_LSFT)),
    COMBO(combo_alt, OSM(MOD_LALT)),
    COMBO(combo_alt_ctl, OSM(MOD_LALT | MOD_LCTL)),
};

// clang-format on
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
// ╭────────┬────────┬────────┬────────┬────────┬────────╮                                      ╭────────┬────────┬────────┬────────┬────────┬────────╮
    EXPAND,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                           KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, QK_REP,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                                      ├────────┼────────┼────────┼────────┼────────┼────────┤
    LC_LB,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                           KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    CAG_RB,
// ├────────┼────────┼────────┼────────┼────────┼────────┤────────┬────────╮  ╭────────┬────────┼────────┼────────┼────────┼────────┼────────┤────────┤
    KC_LSFT, KC_LPRN, KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX, LOAD,       LOAD,    XXXXXXX, KC_K,    KC_H,    KC_COMMA, KC_DOT, KC_RPRN, XXXXXXX,
// ╰────────┴────────┴────────┼────────┼────────┼────────┤────────┤────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
                               XXXXXXX, MEDIA,   NAV_SP,  SYM_ENT, KC_TAB,     XXXXXXX, NUM_ENT, SFT_BSP, UG_NEXT, UG_TOGG
//                            ╰────────┴────────┴────────┴────────┴────────╯  ╰────────┴────────┴────────┴────────┴────────╯
    ),

    [_MAC] = LAYOUT(
// ╭────────┬────────┬────────┬────────┬────────┬────────╮                                      ╭────────┬────────┬────────┬────────┬────────┬────────╮
    MEXPAND, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                                      ├────────┼────────┼────────┼────────┼────────┼────────┤
    LG_LB,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                           KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    CAG_RB,
// ├────────┼────────┼────────┼────────┼────────┼────────┤────────┬────────╮  ╭────────┬────────┼────────┼────────┼────────┼────────┼────────┤────────┤
    LOCK,    KC_LPRN,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX, LOAD,       LOAD,    XXXXXXX, KC_K,    KC_H,    KC_COMMA, KC_DOT, KC_RPRN, XXXXXXX,
// ╰────────┴────────┴────────┼────────┼────────┼────────┤────────┤────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
                               XXXXXXX, MEDIA,   MNAV_SP, MSYM_ENT,KC_TAB,     XXXXXXX, NUM_ENT, MSFT_BSP,UG_NEXT, UG_TOGG
//                            ╰────────┴────────┴────────┴────────┴────────╯  ╰────────┴────────┴────────┴────────┴────────╯
    ),

    [_SHIFT] = LAYOUT(
// ╭────────┬────────┬────────┬────────┬────────┬────────╮                                      ╭────────┬────────┬────────┬────────┬────────┬────────╮
    SHRINK,  S(KC_Q),    S(KC_W),    S(KC_F),    S(KC_P),    S(KC_B),                                           S(KC_J),    S(KC_L),    S(KC_U),    S(KC_Y),    KC_AT,   S(KC_BSPC),
// ├────────┼────────┼────────┼────────┼────────┼────────┤                                      ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_GRV,   S(KC_A),    S(KC_R),    S(KC_S),    S(KC_T),    S(KC_G),                                           S(KC_M),    S(KC_N),    S(KC_E),    S(KC_I),    S(KC_O),    KC_EQL,
// ├────────┼────────┼────────┼────────┼────────┼────────┤────────┬────────╮  ╭────────┬────────┼────────┼────────┼────────┼────────┼────────┤────────┤
    S(KC_LSFT),KC_LCBR,    S(KC_X),    S(KC_C),    S(KC_D),    S(KC_V),    XXXXXXX, LOAD,       LOAD,    XXXXXXX, S(KC_K),    S(KC_H),    KC_SCLN, KC_COLN,  KC_RCBR, XXXXXXX,
// ╰────────┴────────┴────────┼────────┼────────┼────────┤────────┤────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
                               XXXXXXX, XXXXXXX, NAV_SP,  S(KC_ENT), S(KC_TAB),    XXXXXXX, NUM_ENT, SFT_BSP, XXXXXXX, BL_BRTG
//                            ╰────────┴────────┴────────┴────────┴────────╯  ╰────────┴────────┴────────┴────────┴────────╯
    ),

    [_MAC_SHIFT] = LAYOUT(
// ╭────────┬────────┬────────┬────────┬────────┬────────╮                                      ╭────────┬────────┬────────┬────────┬────────┬────────╮
    SHRINK,  S(KC_Q),    S(KC_W),    S(KC_F),    S(KC_P),    S(KC_B),                                           S(KC_J),    S(KC_L),    S(KC_U),    S(KC_Y),    KC_AT,   S(KC_BSPC),
// ├────────┼────────┼────────┼────────┼────────┼────────┤                                      ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_NUBS, S(KC_A),    S(KC_R),    S(KC_S),    S(KC_T),    S(KC_G),                                           S(KC_M),    S(KC_N),    S(KC_E),    S(KC_I),    S(KC_O),    KC_EQL,
// ├────────┼────────┼────────┼────────┼────────┼────────┤────────┬────────╮  ╭────────┬────────┼────────┼────────┼────────┼────────┼────────┤────────┤
    S(KC_LSFT),KC_LCBR,    S(KC_X),    S(KC_C),    S(KC_D),    S(KC_V),    XXXXXXX, LOAD,       LOAD,    XXXXXXX, S(KC_K),    S(KC_H),    KC_SCLN, KC_COLN,  KC_RCBR, XXXXXXX,
// ╰────────┴────────┴────────┼────────┼────────┼────────┤────────┤────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
                               XXXXXXX, XXXXXXX, NAV_SP,  S(KC_ENT), S(KC_TAB),    XXXXXXX, NUM_ENT, SFT_BSP, XXXXXXX, BL_BRTG
//                            ╰────────┴────────┴────────┴────────┴────────╯  ╰────────┴────────┴────────┴────────┴────────╯
    ),


    [_NAV] = LAYOUT(

// ╭────────┬────────┬────────┬────────┬────────┬────────╮                                      ╭────────┬────────┬────────┬────────┬────────┬────────╮
    XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_END,  XXXXXXX,                                        XXXXXXX, KC_F12,  KC_UP,   CTL_F12, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                                      ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, CTL_TAB, ALT_TAB, KC_PGUP, KC_PGDN, XXXXXXX,                                        XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤────────┬────────╮  ╭────────┬────────┼────────┼────────┼────────┼────────┼────────┤────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  XXXXXXX,
// ╰────────┴────────┴────────┼────────┼────────┼────────┤────────┤────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, CAG_SPC, XXXXXXX, XXXXXXX
//                            ╰────────┴────────┴────────┴────────┴────────╯  ╰────────┴────────┴────────┴────────┴────────╯
// TODO: alt-tab, caps word
    ),

    [_MAC_NAV] = LAYOUT(
// ╭────────┬────────┬────────┬────────┬────────┬────────╮                                      ╭────────┬────────┬────────┬────────┬────────┬────────╮
    XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_END,  XXXXXXX,                                        XXXXXXX, KC_F12,  KC_UP,   GUI_F12, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                                      ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, GUI_NUBS,GUI_TAB, KC_PGUP, KC_PGDN, XXXXXXX,                                        XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤────────┬────────╮  ╭────────┬────────┼────────┼────────┼────────┼────────┼────────┤────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  XXXXXXX,
// ╰────────┴────────┴────────┼────────┼────────┼────────┤────────┤────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, CAG_SPC, XXXXXXX, XXXXXXX
//                            ╰────────┴────────┴────────┴────────┴────────╯  ╰────────┴────────┴────────┴────────┴────────╯
    ),

    [_NUM] = LAYOUT(
// ╭────────┬────────┬────────┬────────┬────────┬────────╮                                      ╭────────┬────────┬────────┬────────┬────────┬────────╮
    XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,                                        XXXXXXX, KC_DOT,  KC_EQL,  KC_UNDS, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                                      ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_PAST, KC_0,    KC_1,    KC_2,    KC_3,    XXXXXXX,                                        XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PMNS, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤────────┬────────╮  ╭────────┬────────┼────────┼────────┼────────┼────────┼────────┤────────┤
    XXXXXXX, KC_PSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCLN, KC_COLN, KC_PPLS,  XXXXXXX,
// ╰────────┴────────┴────────┼────────┼────────┼────────┤────────┤────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
                               XXXXXXX, XXXXXXX, KC_SPC,  XXXXXXX, XXXXXXX,    XXXXXXX, KC_PENT, XXXXXXX, XXXXXXX, XXXXXXX
//                            ╰────────┴────────┴────────┴────────┴────────╯  ╰────────┴────────┴────────┴────────┴────────╯
    ),

    [_SYM] = LAYOUT(

// ╭────────┬────────┬────────┬────────┬────────┬────────╮                                      ╭────────┬────────┬────────┬────────┬────────┬────────╮
    XXXXXXX, KC_PIPE, KC_EXLM, KC_PERC, KC_NUHS, XXXXXXX,                                        XXXXXXX, KC_AMPR, KC_DLR,  KC_CIRC, KC_GRV,  XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                                      ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_HASH, KC_QUES, KC_COLN, KC_EQL,  PIPE,    XXXXXXX,                                        XXXXXXX, KC_LT,   KC_ASTR,  KC_GT,   KC_UNDS, KC_DQUO,
// ├────────┼────────┼────────┼────────┼────────┼────────┤────────┬────────╮  ╭────────┬────────┼────────┼────────┼────────┼────────┼────────┤────────┤
    XXXXXXX, KC_NUBS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCLN, KC_COLN, KC_SLSH, XXXXXXX,
// ╰────────┴────────┴────────┼────────┼────────┼────────┤────────┤────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_PLUS, KC_MINS, XXXXXXX, XXXXXXX
//                            ╰────────┴────────┴────────┴────────┴────────╯  ╰────────┴────────┴────────┴────────┴────────╯
    ),

    [_MAC_SYM] = LAYOUT(
// ╭────────┬────────┬────────┬────────┬────────┬────────╮                                      ╭────────┬────────┬────────┬────────┬────────┬────────╮
    XXXXXXX, KC_PIPE, KC_EXLM, KC_PERC, KC_NUHS, XXXXXXX,                                        XXXXXXX, KC_AMPR, KC_DLR,  KC_CIRC, KC_GRV,  XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                                      ├────────┼────────┼────────┼────────┼────────┼────────┤
    KC_HASH, KC_QUES, KC_COLN, KC_EQL,  KC_TILD,    XXXXXXX,                                        XXXXXXX, KC_LT,   KC_ASTR,  KC_GT,   KC_UNDS, KC_DQUO,
// ├────────┼────────┼────────┼────────┼────────┼────────┤────────┬────────╮  ╭────────┬────────┼────────┼────────┼────────┼────────┼────────┤────────┤
    XXXXXXX, KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCLN, KC_COLN, KC_SLSH, XXXXXXX,
// ╰────────┴────────┴────────┼────────┼────────┼────────┤────────┤────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_PLUS, KC_MINS, XXXXXXX, XXXXXXX
//                            ╰────────┴────────┴────────┴────────┴────────╯  ╰────────┴────────┴────────┴────────┴────────╯
    ),


    [_FUNCTION] = LAYOUT(
// ╭────────┬────────┬────────┬────────┬────────┬────────╮                                      ╭────────┬────────┬────────┬────────┬────────┬────────╮
    XXXXXXX, XXXXXXX, KC_F5,   KC_F8,   KC_F12,  XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                                      ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, KC_F10,  KC_F2,   XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤────────┬────────╮  ╭────────┬────────┼────────┼────────┼────────┼────────┼────────┤────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ╰────────┴────────┴────────┼────────┼────────┼────────┤────────┤────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
//                            ╰────────┴────────┴────────┴────────┴────────╯  ╰────────┴────────┴────────┴────────┴────────╯
    ),

    [_MEDIA] = LAYOUT(

// ╭────────┬────────┬────────┬────────┬────────┬────────╮                                      ╭────────┬────────┬────────┬────────┬────────┬────────╮
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤                                      ├────────┼────────┼────────┼────────┼────────┼────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, PDF(_BASE), PDF(_MAC), XXXXXXX,                                   XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX,
// ├────────┼────────┼────────┼────────┼────────┼────────┤────────┬────────╮  ╭────────┬────────┼────────┼────────┼────────┼────────┼────────┤────────┤
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// ╰────────┴────────┴────────┼────────┼────────┼────────┤────────┤────────┤  ├────────┼────────┼────────┼────────┼────────┼────────┴────────┴────────╯
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_MSTP, KC_MPLY, KC_MUTE, XXXXXXX
//                            ╰────────┴────────┴────────┴────────┴────────╯  ╰────────┴────────┴────────┴────────┴────────╯
    ),

/*
 * Adjust Layer: Default layer settings, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |QWERTY|      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |Dvorak|      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |Colmak|      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                    _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                    RM_TOGG, RM_SATU, RM_HUEU, RM_VALU, RM_NEXT, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RM_SATD, RM_HUED, RM_VALD, RM_PREV, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),
};

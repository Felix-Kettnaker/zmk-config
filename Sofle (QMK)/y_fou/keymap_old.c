// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include <keymap_german.h>
#include <sendstring_german.h>

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _YFOU,
    _SYMBOL1,
    _SYMBOL2,
    _PUNCTUATION,
    _NAVIGATION,
    _LNUMBER,
    _UMLAUT,
    _QWERTZ,
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
    CIRCUM,
    FTICK,
    BTICK,
    CDEBLCK,
    CDELINE
};

// Tap Dance declarations
enum {
    TD_LAYOUT_SWITCH,
};


#define REDO LCTL(DE_Y)
#define UNDO LCTL(DE_Z)
#define SELALL LCTL(KC_A)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define SAVE LCTL(KC_S)

#define LAT_S LALT_T(KC_S)
#define LGT_T LGUI_T(KC_T)
#define LST_R LSFT_T(KC_R)
#define LCT_D LCTL_T(KC_D)
#define RCT_N RCTL_T(KC_N)
#define RST_E RSFT_T(KC_E)
#define RGT_I RGUI_T(KC_I)
#define RAT_A RALT_T(KC_A)

#define SPC_PCT LT(_PUNCTUATION, KC_SPC)
#define ENT_NAV LT(_NAVIGATION, KC_ENT)
#define BSPC_SYM LT(_SYMBOL1, KC_BSPC)
#define DEL_SYM LT(_SYMBOL1, KC_DEL)
#define TAB_NUM LT(_LNUMBER, KC_TAB)
#define ______ _______
#define XXXXXX XXXXXXX

#define L_UMLT MO(_UMLAUT)
#define L_SYMBL1 MO(_SYMBOL1)
#define L_SYMBL2 MO(_SYMBOL2)
#define L_SWTCH TD(TD_LAYOUT_SWITCH)
#define CTRL_ESC MT(MOD_LCTL,KC_ESC)
#define OSM_SFT OSM(KC_LSFT)


// Modifier+Key Overrides: specify overrides as consts, then add them to the array bellow
//const key_override_t delete_key_override            = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t eszett_key_override            = ko_make_basic(MOD_MASK_SHIFT, DE_SS, MEH(DE_SS));
const key_override_t backspace_symbol_key_override  = ko_make_basic(MOD_MASK_SHIFT, BSPC_SYM, KC_BSPC);
const key_override_t delete_symbol_key_override     = ko_make_basic(MOD_MASK_SHIFT, DEL_SYM, KC_DEL);

const key_override_t **key_overrides = (const key_override_t *[]){
	//&delete_key_override,
    &eszett_key_override,
    &backspace_symbol_key_override,
    &delete_symbol_key_override,
	NULL
};


// rotary encoders with normal key cap functions
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(DT_DOWN, DT_UP)  },
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(DT_DOWN, DT_UP)  },
    [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(DT_DOWN, DT_UP)  },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(DT_DOWN, DT_UP)  },
    [4] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(DT_DOWN, DT_UP)  },
    [5] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(DT_DOWN, DT_UP)  },
    [6] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(DT_DOWN, DT_UP)  },
    [7] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(DT_DOWN, DT_UP)  },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * YFOU
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * | CapsL|  F1  |  F2  |  F3  |  F4  |  F5  |                            |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |  Tab |   V  |   M  |   L  |   C  |   K  |                            |   Y  |   F  |   O  |   U  |   X  | Bspc |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |   ,  |   S  |   T  |   R  |   D  |   P  |  ,----.            ,----.  |   B  |   N  |   E  |   I  |   A  |  .   |
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |  ESC |   Z  |   Q  |   W  |   G  |   J  |  `----´            `----´  |   Ö  |   H  |   -  |   Ä  |   Ü  |      |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |      |  Tab | /Space /,-----.          ,-----.\ Enter\ |Umlaut|   +  |   /  |
 *               '----------------------------'/ Bspc /          \  Del \'----------------------------'
 *                           +LeftNum  +Punctn'------'            '------' +Navi
 *                                             +Symbl              +Symbl              */
[_YFOU] = LAYOUT(
  KC_CAPS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                        KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F12,
  KC_TAB, KC_V,   KC_M,   KC_L,   KC_C,   KC_K,                         DE_Y,   KC_F,   KC_O,   KC_U,   DE_X,   KC_BSPC,
  KC_COMM,LAT_S,  LGT_T,  LST_R,  LCT_D,  KC_P,                         KC_B,   RCT_N,  RST_E,  RGT_I,  RAT_A,  KC_DOT,
  KC_ESC, DE_Z,   KC_Q,   KC_W,   KC_G,   KC_J,    KC_MUTE,    DT_PRNT, DE_ODIA,KC_H,   DE_MINS,DE_ADIA,DE_UDIA,XXXXXX,
                  L_SWTCH,XXXXXX, TAB_NUM,SPC_PCT,BSPC_SYM,    DEL_SYM, ENT_NAV,L_UMLT, DE_PLUS,DE_SLSH
),


/* SYMBOL1
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * | CapsW|  F1  |  F2  |  F3  |  F4  |  F5  |                            |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |Cdelne|   (  |   #  |   _  |   )  |                            |   -  |   7  |   8  |   9  |   /  |   %  |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |   |  |   @  |   !  |   :  |   =  |   %  |  ,----.            ,----.  |   +  |   4  |   5  |   6  |   *  |   €  |
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |  ESC |   §  |   [  |   *  |   /  |   ]  |  `----´            `----´  |   0  |   1  |   2  |   3  |   .  |   $  |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |   .  |   \  | /Space  /,-----.         ,-----.\ Enter\ |   ,  |   ²  |   ³  |
 *               '----------------------------'/Symbl2/          \Symbl2\'----------------------------'
 *                                            '------'            '------'      */
[_SYMBOL1] = LAYOUT(
  CW_TOGG,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                        KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, XXXXXX,
  XXXXXX, CDELINE,DE_LPRN,KC_BSLS,DE_UNDS,DE_RPRN,                      KC_PMNS,KC_7,   KC_8,   KC_9,   KC_PSLS,DE_PERC,
  DE_PIPE,DE_AT,  DE_EXLM,DE_COLN,DE_EQL, DE_PERC,                      KC_PPLS,KC_4,   KC_5,   KC_6,   KC_PAST,DE_EURO,
  ______, DE_SECT,DE_LBRC,DE_ASTR,DE_SLSH,DE_RBRC,KC_MUTE,     DT_PRNT, KC_0,   KC_1,   KC_2,   KC_3,   KC_DOT, DE_DLR,
                  XXXXXX, XXXXXX, DE_BSLS,______, L_SYMBL2,    L_SYMBL2,______, KC_COMM,DE_SUP2,DE_SUP3
),


/* SYMBOL2
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * | CapsW|  F11 |  F12 |  F13 |  F14 |  F15 |                            |  F16 |  F17 |  F18 |  F19 |  F20 |  F21 |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |Cdeblk|   {  |   "  |   '  |   }  |                            |   V  |   V  |   V  |   V  |   V  |  F22 |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |   ´  |   ^  |   ?  |   ;  |   `  |   $  |  ,----.            ,----.  |   V  |   V  |   V  |   V  |   V  |  F23 |
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |  ESC |   ~  |   <  |   =  |   -  |   >  |  `----´            `----´  |   V  |   V  |   V  |   V  |   V  |  F24 |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |   &  |   /  | /Space /,-----.          ,-----.\      \ |   V  |   V  |   V  |
 *               '----------------------------'/Symbl1/          \Symbl1\'----------------------------'
 *                                            '------'            '------'      */
[_SYMBOL2] = LAYOUT(
  ______, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,                       KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21,
  XXXXXX, CDEBLCK,DE_LCBR,DE_DQUO,DE_QUOT,DE_RCBR,                      ______, ______, ______, ______, ______, KC_F22,
  FTICK,  CIRCUM, DE_QUES,DE_SCLN,BTICK,  DE_DLR,                       ______, ______, ______, ______, ______, KC_F23,
  ______, DE_TILD,DE_LABK,DE_EQL, DE_MINS,DE_RABK,KC_MUTE,     DT_PRNT, ______, ______, ______, ______, ______, KC_F24,
                  XXXXXX, DE_AMPR,DE_SLSH,______, L_SYMBL1,    L_SYMBL1,______, ______, ______, ______
),


/* Punctuation
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * | CapsW|  F1  |  F2  |  F3  |  F4  |  F5  |                            |  F6  |  F7  |  F8  |  F9  |  F10 |  (´) | <- dead
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                            |   /  |   (  |   )  |   &  |   @  |  (`) | <- dead
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * | CapsW|   ß  |      | Space| Space| Save |  ,----.            ,----.  |   "  |   ,  |   .  |   ?  |   '  |   ^  |
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |  ESC | Ctl+Z| Ctl+Y|  Cut | Copy | Paste|  `----´            `----´  |   %  |   ;  |   :  |   !  |   *  |  (^) | <_ dead
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |select| Enter| /      /,-----.          ,-----.\Enter \ |   °  |   #  |   ~  |
 *               '--------all------------------'/      /          \      \'----------------------------'
 *                                            '------'            '------'      */
 [_PUNCTUATION] = LAYOUT(
  CW_TOGG,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                        KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, DE_ACUT,
  XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,                       DE_SLSH,DE_LPRN,DE_RPRN,DE_AMPR,DE_AT,  DE_GRV,
  CW_TOGG,DE_SS,  XXXXXX, KC_SPC, KC_SPC, SAVE,                         DE_DQUO,DE_COMM,DE_DOT, DE_QUES,DE_QUOT,CIRCUM,
  KC_ESC, UNDO,   REDO,   CUT,    COPY,   PASTE,  XXXXXX,       XXXXXX, DE_PERC,DE_SCLN,DE_COLN,DE_EXLM,DE_ASTR,DE_CIRC,
                  XXXXXX, SELALL, KC_ENT,______, XXXXXX,       XXXXXX, ______, DE_DEG, KC_BSLS,DE_TILD
 ),


 /* NAVIGATION
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * |      |      |      |      |      |      |                            |      |      | Calc |      |      |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                            |  PG↑ | Pos1 |   ↑  |  End |      |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |  Alt |  GUI | Shift| Ctrl | Save |  ,----.            ,----.  |  PG↓ |   ←  |   ↓  |   →  |      | Play |
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |      | Undo | Redo |  Cut | Copy | Paste|  `----´            `----´  |      | Bckwd|      |  Fwd |      | Stop |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |select|  Tab | /Space /,-----.          ,-----.\      \ | Enter|      |      |
 *               '--------all-----------------'/      /          \      \'----------------------------'
 *                                            '------'            '------'      */
 [_NAVIGATION] = LAYOUT(
  XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,                       XXXXXX, XXXXXX, KC_CALC,XXXXXX, XXXXXX, XXXXXX,
  XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,                       KC_PGUP,KC_HOME,KC_UP,  KC_END, XXXXXX, XXXXXX,
  XXXXXX, KC_LALT,KC_LGUI,KC_LSFT,KC_LCTL,SAVE,                         KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXX, KC_MPLY,
  XXXXXX, UNDO,   REDO,   CUT,    COPY,   PASTE,  XXXXXX,       XXXXXX, XXXXXX, KC_WBAK,XXXXXX, KC_WFWD,XXXXXX, KC_MSTP,
                  XXXXXX, SELALL, KC_TAB, ______, XXXXXX,       XXXXXX, ______, KC_ENT, XXXXXX, XXXXXX
 ),


/* Left Numbers
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * |      |      |   X  |   Y  |   Z  |      |                            |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |   %  |   *  |   7  |   8  |   9  |   +  |                            |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |   €  |   /  |   4  |   5  |   6  |   -  |  ,----.            ,----.  |      |      |      |      |      |      |
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |   $  |   .  |   1  |   2  |   3  |   0  |  `----´            `----´  |      |      |      |      |      |      |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |   ,  |      | /      /,-----.          ,-----.\      \ |      |      |      |
 *               '----------------------------'/      /          \      \'----------------------------'
 *                                            '------'            '------'      */
 [_LNUMBER] = LAYOUT(
  XXXXXX, XXXXXX, DE_X,   DE_Y,   DE_Z,   XXXXXX,                       XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
  DE_PERC,KC_PSLS,KC_7,   KC_8,   KC_9,   KC_PMNS,                      XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
  DE_EURO,KC_PAST,KC_4,   KC_5,   KC_6,   KC_PPLS,                      XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
  DE_DLR, KC_DOT, KC_1,   KC_2,   KC_3,   KC_0,   XXXXXX,       XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
                  XXXXXX, DE_COMM,XXXXXX, XXXXXX, XXXXXX,       XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX
 ),
 

/* UMLAUT
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * |      |      |      |      |      |      |                            |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                            |      |      |   Ö  |   Ü  |      |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |   ß  |      |      |      |      |  ,----.            ,----.  |      |      |      |      |   Ä  |      |
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  `----´            `----´  |      |      |      |      |      |      |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |      |      | /      /,-----.          ,-----.\      \ |      |      |      |
 *               '----------------------------'/      /          \      \'----------------------------'
 *                                            '------'            '------'      */
 [_UMLAUT] = LAYOUT(
  KC_CAPS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                        KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F12,
  KC_TAB, KC_V,   KC_M,   KC_L,   KC_C,   KC_K,                         DE_Y,   KC_F,   DE_ODIA,DE_UDIA,DE_X,   KC_BSPC,
  KC_COMM,DE_SS,  LGT_T,  LST_R,  LCT_D,  KC_P,                         KC_B,   RCT_N,  RST_E,  RGT_I,  DE_ADIA,KC_DOT,
  KC_ESC, DE_Z,   KC_Q,   KC_W,   KC_G,   KC_J,   KC_MUTE,     DT_PRNT, DE_ODIA,KC_H,   DE_MINS,DE_ADIA,DE_UDIA,XXXXXX,
                  XXXXXX, XXXXXX, KC_TAB, KC_SPC, KC_BSPC,     KC_DEL,  KC_ENT, L_UMLT, DE_PLUS,DE_SLSH
 ),


  /* QWERTZ
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                            |   6  |   7  |   8  |   9  |   0  |   ß  |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |                            |   Z  |   U  |   I  |   O  |   P  |   Ü  |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |  ,----.            ,----.  |   H  |   J  |   K  |   L  |   Ö  |   Ä  |
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * | Ctrl |   Y  |   X  |   C  |   V  |   B  |  `----´            `----´  |   N  |   M  |   ,  |   .  |   -  |   +  |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |   <  |  Alt | / Space/,-----.          ,-----.\Enter \ |  (´) |   #  |  (^) |
 *               '----------------------------'/ Bspc /          \ Del  \'----------------------------'
 *                                            '------'            '------'      */
 [_QWERTZ] = LAYOUT(
  KC_ESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                         KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   DE_SS,
  KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                         DE_Z,   KC_U,   KC_I,   KC_O,   KC_P,   DE_UDIA,
  KC_LSFT,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                         KC_H,   KC_J,   KC_K,   KC_L,   DE_ODIA,DE_ADIA,
  KC_LCTL,DE_Y,   KC_X,   KC_C,   KC_V,   KC_B,   XXXXXX,       XXXXXX, KC_N,   KC_M,   DE_COMM,DE_DOT, DE_MINS,DE_PLUS,
                  L_SWTCH,DE_LABK,KC_LALT,KC_SPC, KC_BSPC,      KC_DEL, KC_ENT, DE_ACUT,DE_HASH,DE_CIRC
 ),


  /* ADJUST
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * |      |      |      |      |      |      |                            |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                            |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  ,----.            ,----.  |      |      |      |      |      |      |
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  `----´            `----´  |      |      |      |      |      |      |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |      |      | /      /,-----.          ,-----.\      \ |      |      |      |
 *               '----------------------------'/      /          \      \'----------------------------'
 *                                            '------'            '------'      */
 /*
 [_NAVIGATION] = LAYOUT(
  XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,                       XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
  XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,                       XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
  XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,                       XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
  XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,       XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
                  XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,       XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX
 ),
*/
};


// Tap dance functions
void layout_switch(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            layer_move(_YFOU);
            break;
            //reset_tap_dance(state);
        case 2:
            layer_move(_QWERTZ);
            break;
    }
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LAYOUT_SWITCH] = ACTION_TAP_DANCE_FN(layout_switch),
};


// Caps word
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case DE_MINS:
        case DE_ADIA:
        case DE_UDIA:
        case DE_ODIA:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
        case DE_SS:
            add_weak_mods(MOD_BIT(KC_MEH));  // shift "ß" to "ẞ" and not "?".
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// send string
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CIRCUM:
            if (record->event.pressed) {
                SEND_STRING("^");
            }
            return false;
        case FTICK:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_EQL)" ");
            }
            return false;
        case BTICK:
            if (record->event.pressed) {
                SEND_STRING("`");
            }
            return false;
        case CDEBLCK:
            if (record->event.pressed) {
                SEND_STRING("```\n");
            }
            else{
                SEND_STRING("\n```" SS_TAP(X_UP));
            }
            return false;
        case CDELINE:
            if (record->event.pressed) {
                SEND_STRING("`");
            }
            else{
                SEND_STRING("`" SS_TAP(X_LEFT));
            }
            return false;
    }

    return true;
};


/* bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
    }
    return true;
} */

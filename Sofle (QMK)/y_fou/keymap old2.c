// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include <keymap_german.h>
#include <sendstring_german.h>

int lastkey[] = {0, 0};
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
    CDELINE,
    CONTXT2
};

// Tap Dance declarations
enum {
    TD_LAYOUT_SWITCH,
};

#define ______ _______
#define XXXXXX XXXXXXX
#define CONTXT QK_AREP

#define REDO LCTL(DE_Y)
#define UNDO LCTL(DE_Z)
#define SELALL LCTL(KC_A)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define SAVE LCTL(KC_S)
#define FIND LCTL(KC_F)

#define LSH_S LSFT_T(DE_S)
#define LAL_L LALT_T(KC_L)
#define LCT_R LCTL_T(KC_R)
#define LGU_Y LGUI_T(DE_Y)
#define RSH_A RSFT_T(KC_A)
#define RAL_O RALT_T(KC_O)
#define RCT_E RCTL_T(KC_E)
#define RGU_B RGUI_T(KC_B)
#define LSH_SS LSFT_T(DE_SS)
#define RSH_AE RSFT_T(DE_ADIA)

#define TAB_NUM LT(_LNUMBER, KC_TAB)
#define SPC_PCT LT(_PUNCTUATION, KC_SPC)
#define SPC_SYM1 LT(_SYMBOL1, KC_SPC)
#define BSPC_SYM2 LT(_SYMBOL2, KC_BSPC)
#define DOT_SYM1 LT(_SYMBOL1, KC_DOT)
#define ENT_NAV LT(_NAVIGATION, KC_ENT)
#define ENT_SYM2 LT(_SYMBOL2, KC_ENT)
#define QUOT_UML LT(_UMLAUT, DE_QUOT)

#define L_SWTCH TD(TD_LAYOUT_SWITCH)


// Modifier+Key Overrides: specify overrides as consts, then add them to the array bellow
const key_override_t delete_key_override            = ko_make_basic(MOD_MASK_SHIFT, BSPC_SYM2, KC_DEL);
const key_override_t eszett_key_override            = ko_make_basic(MOD_MASK_SHIFT, DE_SS, MEH(DE_SS));
//const key_override_t backspace_symbol_key_override  = ko_make_basic(MOD_MASK_SHIFT, BSPC_SYM2, KC_BSPC);
//const key_override_t delete_symbol_key_override     = ko_make_basic(MOD_MASK_SHIFT, DEL_SYM1, KC_DEL);

const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_key_override,
    &eszett_key_override,
    //&backspace_symbol_key_override,
    //&delete_symbol_key_override,
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
 * |  Tab |   V  |   M  |a  L  |   C  |   K  |                            |   X  |   F  |a  O  |   U  |   Q  | Bspc |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |Repeat|s  S  |   T  |c  R  |   D  |g  Y  |  ,----.            ,----.  |g  B  |   N  |c  E  |   I  |s  A  |Repeat|
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |  ESC |   Z  |Contxt|   W  |   G  |   J  |  `----´            `----´  |   P  |   H  |   -  |   ,  |Contxt|      |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |      |  Tab | /Space /,-----.          ,-----.\ Enter\ |   '  |   +  |   /  |
 *               '----------------------------'/ Bspc /          \   .  \'----------------------------'
 *                           +LeftNum  +Punctn'------'            '------' +Navi  +Umlaut
 *                                             +Symbl2             +Symbl1      */
[_YFOU] = LAYOUT(
  KC_CAPS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                        KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F12, 
  KC_TAB, KC_V,   KC_M,   LAL_L,  KC_C,   KC_K,                         KC_X,   KC_F,   RAL_O,  KC_U,   DE_Q,   KC_BSPC,
  QK_REP, LSH_S,  KC_T,   LCT_R,  KC_D,   LGU_Y,                        RGU_B,  KC_N,   RCT_E,  KC_I,   RSH_A,  QK_REP,
  KC_ESC, DE_Z,   CONTXT, KC_W,   KC_G,   KC_J,    KC_MUTE,    XXXXXX,  KC_P,   KC_H,   DE_MINS,DE_COMM,CONTXT, XXXXXX,
                  L_SWTCH,XXXXXX, TAB_NUM,SPC_PCT,BSPC_SYM2,   DOT_SYM1,ENT_NAV,QUOT_UML,DE_PLUS,DE_SLSH
),


/* SYMBOL1
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * | CapsW|  F11 |  F12 |  F13 |  F14 |  F15 |                            |  F16 |  F17 |  F18 |  F19 |  F20 |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |Cdelne|   {  |   #  |   _  |   }  |                            |   -  |   8  |   9  |   /  |   ,  |   $  |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |   `  |   @  |   !  |   :  |   =  |   %  |  ,----.            ,----.  |   +  |   0  |   1  |   2  |   3  |Repeat|
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |  ESC |   §  |   [  |   /  |   *  |   ]  |  `----´            `----´  |   *  |   4  |   5  |   6  |   7  |   €  |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |      |   \  | /Space  /,-----.         ,-----.\ Enter\ |   .  |   ,  |      |
 *               '----------------------------'/ Enter/          \      \'----------------------------'
 *                                            '------'            '------'      
                                               +Symbl2                          */
[_SYMBOL1] = LAYOUT(
  CW_TOGG,KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,                       KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, XXXXXX,
  XXXXXX, CDELINE,DE_LCBR,KC_BSLS,DE_UNDS,DE_RCBR,                      KC_PMNS,KC_8,   KC_9,   KC_PSLS,DE_COMM,DE_DLR,
  BTICK,  DE_AT,  DE_EXLM,DE_COLN,DE_EQL, DE_PERC,                      KC_PPLS,KC_0,   KC_1,   KC_2,   KC_3,   QK_REP,
  ______, DE_SECT,DE_LBRC,DE_SLSH,DE_ASTR,DE_RBRC,KC_MUTE,     XXXXXX,  KC_PAST,KC_4,   KC_5,   KC_6,   KC_7,   DE_EURO,
                  XXXXXX, XXXXXX, DE_BSLS,KC_SPC, ENT_SYM2,    XXXXXX,  KC_ENT, DE_DOT, DE_COMM,XXXXXX
),


/* SYMBOL2
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * | CapsW|  F21 |  F22 |  F23 |  F24 |      |                            |  F16 |  F17 |  F18 |  F19 |  F20 |  F21 |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |Cdeblk|   (  |   "  |   '  |   )  |                            |   -  |   7  |   8  |   9  |   /  |  F22 |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |   |  |   ~  |   <  |   -  |   =  |   >  |  ,----.            ,----.  |   +  |   4  |   5  |   6  |   *  |  F23 |
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |  ESC |   ^  |   ?  |   /  |   &  |   $  |  `----´            `----´  |   0  |   1  |   2  |   3  |   .  |  F24 |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |      |   ´  | /Space /,-----.          ,-----.\ Enter\ |   ,  |   ²  |   ³  |
 *               '----------------------------'/      /          \Space \'----------------------------'
 *                                            '------'            '------'      
                                                                   +Symbl1      */
[_SYMBOL2] = LAYOUT(
  ______, KC_F21, KC_F22, KC_F23, KC_F24, XXXXXX,                       KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, XXXXXX,
  XXXXXX, CDEBLCK,DE_LPRN,DE_DQUO,DE_QUOT,DE_RPRN,                      KC_PMNS,KC_8,   KC_9,   KC_PSLS,DE_COMM,DE_DLR,
  DE_PIPE,DE_TILD,DE_LABK,DE_MINS,DE_EQL, DE_RABK,                      KC_PPLS,KC_0,   KC_1,   KC_2,   KC_3,   QK_REP,
  ______, CIRCUM, DE_QUES,DE_SLSH,DE_AMPR,DE_DLR, KC_MUTE,     XXXXXX,  KC_PAST,KC_4,   KC_5,   KC_6,   KC_7,   DE_EURO,
                  XXXXXX, XXXXXX, FTICK,  KC_SPC, XXXXXX,      SPC_SYM1,KC_ENT, DE_DOT, DE_COMM,XXXXXX
),


/* Punctuation (+Shortcuts)
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * | CapsW|  F1  |  F2  |  F3  |  F4  |  F5  |                            |  F6  |  F7  |  F8  |  F9  |  F10 |  (´) | <- dead
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                            |   /  |   (  |   )  |   &  |   @  |  (`) | <- dead
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * | CapsW|      |      | Space| Find | Save |  ,----.            ,----.  |   "  |   ,  |   .  |   ?  |   '  |   ^  |
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |  ESC | Undo | Redo |  Cut | Copy | Paste|  `----´            `----´  |   %  |   ;  |   :  |   !  |   *  |  (^) | <_ dead
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |select| Enter| /      /,-----.          ,-----.\Enter \ |   °  |   #  |   ~  |
 *               '--------all-----------------'/ Enter/          \      \'----------------------------'
 *                                            '------'            '------'      */
 [_PUNCTUATION] = LAYOUT(
  CW_TOGG,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,                        KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, DE_ACUT,
  XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,                       DE_SLSH,DE_LPRN,DE_RPRN,DE_AMPR,DE_AT,  DE_GRV,
  CW_TOGG,XXXXXX, XXXXXX, KC_SPC, FIND,   SAVE,                         DE_DQUO,DE_COMM,DE_DOT, DE_QUES,DE_QUOT,CIRCUM,
  KC_ESC, UNDO,   REDO,   CUT,    COPY,   PASTE,  XXXXXX,       XXXXXX, DE_PERC,DE_SCLN,DE_COLN,DE_EXLM,DE_ASTR,DE_CIRC,
                  XXXXXX, SELALL, KC_ENT, ______, KC_ENT,       XXXXXX, ______, DE_DEG, KC_BSLS,DE_TILD
 ),


 /* NAVIGATION
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * |      |      |      |      |      |      |                            |      |      | Calc |      |      |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |      |      |  Alt |      |      |                            |  PG↑ | Pos1 |   ↑  |  End | Play | Stop |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |Repeat| Shift|      | Ctrl |      |  Gui |  ,----.            ,----.  |  PG↓ |   ←  |   ↓  |   →  |      |Repeat|
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |      |      |Cntxt2|      |      |      |  `----´            `----´  |      | Enter| Bckwd|  Fwd |Cntxt2|      |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |      |  Tab | /Space /,-----.          ,-----.\      \ |      |      |      |
 *               '----------------------------'/      /          \      \'----------------------------'
 *                                            '------'            '------'      */
 [_NAVIGATION] = LAYOUT(
  XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,                       XXXXXX, XXXXXX, KC_CALC,XXXXXX, XXXXXX, XXXXXX,
  XXXXXX, XXXXXX, XXXXXX, KC_LALT,XXXXXX, XXXXXX,                       KC_PGUP,KC_HOME,KC_UP,  KC_END, KC_MPLY,KC_MSTP,
  ______, KC_LSFT,XXXXXX, KC_LCTL,XXXXXX, KC_LGUI,                      KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,XXXXXX, ______,
  XXXXXX, XXXXXX, CONTXT2,XXXXXX, XXXXXX, XXXXXX, XXXXXX,       XXXXXX, XXXXXX, KC_ENT, KC_WBAK,KC_WFWD,CONTXT2,XXXXXX,
                  XXXXXX, XXXXXX, KC_TAB, ______, XXXXXX,       XXXXXX, ______, XXXXXX, XXXXXX, XXXXXX
 ),


/* Left Numbers
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * |      |      |   X  |   Y  |   Z  |      |                            |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |   $  |   ,  |   /  |   9  |   8  |   -  |                            |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |Repeat|   3  |   2  |   1  |   0  |   +  |  ,----.            ,----.  |      |      |      |      |      |      |
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |   €  |   7  |   6  |   5  |   4  |   *  |  `----´            `----´  |      |      |      |      |      |      |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |   ,  |      | /   .  /,-----.          ,-----.\      \ |      |      |      |
 *               '----------------------------'/      /          \      \'----------------------------'
 *                                            '------'            '------'      */
 [_LNUMBER] = LAYOUT(
  XXXXXX, XXXXXX, DE_X,   DE_Y,   DE_Z,   XXXXXX,                       XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
  DE_DLR, DE_COMM,KC_PSLS,KC_9,   KC_8,   KC_PMNS,                      XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
  QK_REP, KC_3,   KC_2,   KC_1,   KC_0,   KC_PPLS,                      XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
  DE_EURO,KC_7,   KC_6,   KC_5,   KC_4,   KC_PAST,XXXXXX,       XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,
                  XXXXXX, DE_COMM,XXXXXX, DE_DOT, XXXXXX,       XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX
 ),
 

/* UMLAUT
 * ,-----------------------------------------.                            ,-----------------------------------------.
 * |      |      |      |      |      |      |                            |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                            |      |      |   Ö  |   Ü  |      |      |
 * |------+------+------+------+------+------|                            |------+------+------+------+------+------|
 * |      |   ß  |      |      |      |      |  ,----.            ,----.  |      |      |      |      |   Ä  |      |
 * |------+------+------+------+------+------| ( MUTE )          (DTTPRT) |------+------+------+------+------+------|
 * |      |      |Cntxt2|      |      |      |  `----´            `----´  |      |      |      |      |Cntxt2|      |
 * `-------------+------+------+------|'',------.                      ,--+---.''|------+------+------+------+------'
 *               |      |      |      | /      /,-----.          ,-----.\      \ |      |      |      |
 *               '----------------------------'/      /          \      \'----------------------------'
 *                                            '------'            '------'      */
 [_UMLAUT] = LAYOUT(
  ______, ______, ______, ______, ______, ______,                       ______, ______, ______, ______, ______, ______,
  ______, ______, ______, ______, ______, ______,                       ______, ______, DE_ODIA,DE_UDIA,______, ______,
  ______, LSH_SS, ______, ______, ______, ______,                       ______, ______, ______, ______, RSH_AE, ______,
  ______, ______, CONTXT2,______, ______, ______, ______,      ______,  ______, ______, ______, ______, CONTXT2,______,
                  ______, ______, KC_TAB, KC_SPC, KC_BSPC,     KC_DEL,  KC_ENT, ______, ______, ______
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

// Alt repeat (Context / anti-SFB)
static void process_context2(uint16_t keycode, uint8_t mods){
    switch (keycode) {
        case KC_W: tap_code16(KC_L); break;
        case LAL_L: tap_code16(KC_W); break;
        case RCT_E: tap_code16(KC_U); break;
        case KC_U: tap_code16(KC_E); break;
        case KC_F: tap_code16(KC_H); break;
        case KC_H: tap_code16(KC_F); break;
        case KC_N: tap_code16(KC_H); break;
        case KC_T: tap_code16(KC_V); break;
        case KC_I: tap_code16(KC_Q); break;
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
        case QUOT_UML:
            if (record->tap.count && record->event.pressed) {
                tap_code16(DE_QUOT); // Send DE_QUOT on tap
                return false;
            }
            break;
        case CONTXT2:
            if (record->event.pressed) {
                process_context2(get_last_keycode(), get_last_mods());
            }
            return false;
    }

    return true;
};

// Alt repeat (Context / anti-SFB)
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    if ((mods & MOD_MASK_CTRL)) {  // Was Ctrl held?
        switch (keycode) {
            case KC_Y: return C(KC_Z);  // Ctrl + Y reverses to Ctrl + Z.
            case KC_Z: return C(KC_Y);  // Ctrl + Z reverses to Ctrl + Y. auf
        }
    }
    else {
        switch (keycode) {
            // Same-finger-bigrams 
            case RAL_O: return KC_E;
            case RCT_E: return KC_O;
            case KC_U: return KC_I;
            case KC_I: return KC_U;
            case KC_T: return KC_M;
            case KC_M: return KC_T;
            case LCT_R: return KC_L;
            case LAL_L: return KC_R;
            case KC_N: return KC_F;
            case KC_F: return KC_N;
            case KC_D: return KC_G;
            case KC_G: return KC_D;
            case LSH_S: return DE_Z;
            case DE_Z: return KC_S;

            case KC_W: return KC_R;
            case KC_K: return DE_Y;
            case KC_H: return KC_N;
            case KC_X: return KC_P;
        }
    }

    return KC_TRNS;  // Defer to default definitions.
}

// Altrep2 (Context2)
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case CONTXT:
        case CONTXT2:
        case QK_REP:
            return false;  // Ignore ALTREP/Context keys.
    }

    return true;  // Other keys can be repeated.
}


#include "ergodox.h"
#include "led.h"
#include "debug.h"
#include "action_layer.h"
#include "action_code.h"

#define BASE    0 // default layer
#define SHELL_NAV 1
#define KEY_NAV 3 // key navigation layer
#define KEY_SEL 4 // key selection layer
#define NUMBER  5  // number layer
#define SYMBOL  6
#define BRACKETS  7
#define SHORTCUTS 8

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


const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(KEY_NAV), // FN1 - keynav layer
  [2] = ACTION_LAYER_TAP_TOGGLE(NUMBER), // FN2 - number layer
  [3] = ACTION_MODS_ONESHOT(MOD_LSFT),   // FN3 - shift modifier / oneshot
  [4] = ACTION_MODS_ONESHOT(MOD_LCTL),   // FN4 - ctrl modifier / oneshot
  [5] = ACTION_MODS_ONESHOT(MOD_LALT),   // FN5 - alt modifier / oneshot
};

//Tap Dance Declarations
enum {
  TD_SHIFT_CAPSLOCK = 0,
  TD_BRK_LEFT = 1,
  TD_BRK_RIGHT = 2
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// base layer
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_ESC,                    KC_F1,          KC_F2,       KC_F3,        KC_F4,       KC_F5,       KC_F6,
        LT(BRACKETS,KC_TAB),                    KC_QUOT,        KC_COMM,     KC_DOT,       KC_P,        KC_Y,        MO(KEY_SEL),
        MO(SHELL_NAV),             KC_A,           KC_O,        KC_E,         KC_U,        KC_I,
        KC_FN3,                    KC_SCLN,        KC_Q,        KC_J,         KC_K,        KC_X,        MO(KEY_NAV),
                   OSL(SHORTCUTS),KC_FN4, KC_FN5,OSL(SYMBOL),MO(NUMBER),  
                                              // thumb cluster
                                                       RCTL(KC_F), RCTL(KC_S),
                                                                   RCTL(KC_DEL),
                                               KC_BSPC,RCTL(KC_BSPC),KC_DEL,
        // right hand
             KC_F7,       KC_F8,       KC_F9,       KC_F10,        KC_F11,       KC_F12,       KC_BSLS,
             KC_PGUP,     KC_F,        KC_G,        KC_C,          KC_R,         KC_L,         KC_SLSH,
                          KC_D,        KC_H,        KC_T,          KC_N,         KC_S,         KC_MINS,
             KC_PGDN,     KC_B,        KC_M,        KC_W,          KC_V,         KC_Z,         TD(TD_SHIFT_CAPSLOCK),
                                  // lower keys - browser tab control
                                  RSFT(RCTL(KC_TAB)), RCTL(KC_TAB), RCTL(KC_T), RCTL(KC_K), RCTL(KC_W),
             // thumb cluster
             M(SEMICOLON_NEWLINE), M(END_NEWLINE),
             KC_UP,
             KC_DOWN,KC_ENT, KC_SPC
    ),
     

// shell navigation layer
[SHELL_NAV] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               LALT(KC_D),
                               KC_TRNS,RCTL(KC_W),KC_TRNS,
       // right hand
       KC_TRNS,    KC_TRNS,        KC_TRNS,             KC_TRNS,         KC_TRNS,         KC_TRNS,        KC_TRNS,
       RCTL(KC_L), RCTL(KC_W),     KC_HOME,             KC_UP,           KC_END,          LALT(KC_D),     RCTL(KC_R),
                   LALT(KC_B),     KC_LEFT,             KC_DOWN,         KC_RIGHT,        LALT(KC_F),     LALT(KC_DOT),
       RCTL(KC_C), RCTL(KC_U),     M(SCREEN_COPY_MODE), M(SCREEN_PASTE), HYPR(KC_V),      RCTL(KC_K),     M(SHELL_RECALL_LAST_ARG_REMOVE_FIRST_COMMAND),
                // bottom row
                 M(SCREEN_TAB_LEFT), M(SCREEN_TAB_RIGHT), M(SCREEN_NEW_TAB),  KC_TRNS,    KC_TRNS,
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

    
// key navigation layer
[KEY_NAV] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,
       KC_TRNS, KC_PGDN,        KC_HOME,    KC_UP,      KC_END,     KC_PGUP,        M(MC_COPY_LINE),
                RCTL(KC_LEFT),  KC_LEFT,    KC_DOWN,    KC_RIGHT,   RCTL(KC_RIGHT), M(MC_CUT_LINE),
       KC_TRNS, KC_TRNS,        RCTL(KC_C), RCTL(KC_X), RCTL(KC_V), KC_TRNS,        M(MC_PASTE_LINE),
                // bottom row
                KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

// key selection layer
[KEY_SEL] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,       KC_TRNS,             KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,              KC_TRNS,
       RSFT(KC_PGUP), RSFT(KC_PGDN),       RSFT(KC_HOME), RSFT(KC_UP),   RSFT(KC_END),   RSFT(KC_PGUP),        M(MC_COPY_LINE),
                      RSFT(RCTL(KC_LEFT)), RSFT(KC_LEFT), RSFT(KC_DOWN), RSFT(KC_RIGHT), RSFT(RCTL(KC_RIGHT)), M(MC_CUT_LINE),
       RSFT(KC_PGDN), KC_TRNS,             RCTL(KC_C),    RCTL(KC_X),    RCTL(KC_V),     KC_TRNS,              M(MC_PASTE_LINE),
                // bottom row
                KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

// number layer
[NUMBER] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               // bottom row
               KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       // thumb cluster
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_PLUS,  KC_7,    KC_8,    KC_9,     KC_ASTR, KC_TRNS,
                KC_MINS,  KC_4,    KC_5,    KC_6,     KC_SLSH, KC_TRNS,
       KC_TRNS, KC_EQUAL, KC_1,    KC_2,    KC_3,     KC_COLN, KC_TRNS,
                               // bottom row
                                KC_0, KC_DOT, KC_COMMA, KC_TRNS,  KC_TRNS,
       // thumb cluster
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),


[SYMBOL] = KEYMAP(
       // left hand
       KC_NO,KC_F1,  KC_F2,                 KC_F3,   KC_F4,   KC_F5,                     KC_F6,
       KC_TRNS,KC_TRNS,             M(OPEN_CLOSE_PAREN),   KC_LPRN, KC_RPRN, KC_TRNS,                   KC_TRNS,
       KC_TRNS,KC_TRNS,             M(OPEN_CLOSE_BRACKET), KC_LBRC, KC_RBRC, M(OPEN_CLOSE_DOUBLE_QUOTE),
       KC_TRNS,M(SEMICOLON_NEWLINE),M(OPEN_CLOSE_CURLY),   KC_LCBR, KC_RCBR, M(OPEN_CLOSE_SINGLE_QUOTE),KC_TRNS,       
       KC_TRNS,                     KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_TRNS,
       KC_TRNS, KC_PLUS, KC_AMPR, KC_ASTR, KC_GRAVE,KC_TILD, KC_TRNS,
                KC_MINS, KC_DLR,  KC_PERC, KC_CIRC, KC_PIPE, KC_TRNS,
       KC_TRNS, KC_EQUAL,KC_EXLM, KC_AT,   KC_HASH, KC_TRNS, KC_TRNS,
                         KC_LBRC, KC_RBRC, TD(TD_BRK_LEFT), TD(TD_BRK_RIGHT), KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

[BRACKETS] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS, KC_TRNS, M(OPEN_CLOSE_BRACKET),M(OPEN_CLOSE_PAREN),M(OPEN_CLOSE_CURLY),KC_TRNS,KC_TRNS,
                KC_TRNS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS, KC_TRNS, 
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

[SHORTCUTS] = KEYMAP(
       // left hand
       KC_NO,  HYPR(KC_F1),    HYPR(KC_F2), HYPR(KC_F3),  HYPR(KC_F4), HYPR(KC_F5), HYPR(KC_F6),
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,       
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       HYPR(KC_F7), HYPR(KC_F8), HYPR(KC_F9), HYPR(KC_F10),  HYPR(KC_F11), HYPR(KC_F12),  M(SWITCH_NDS),
       KC_TRNS, HYPR(KC_A), HYPR(KC_B),    HYPR(KC_C),    HYPR(KC_D),    HYPR(KC_E), HYPR(KC_F),
                HYPR(KC_G), HYPR(KC_H),    HYPR(KC_I),    HYPR(KC_J),    HYPR(KC_K), HYPR(KC_L),
       KC_TRNS, HYPR(KC_M), HYPR(KC_N),    HYPR(KC_O),    HYPR(KC_P),    HYPR(KC_Q), HYPR(KC_R),
                             LALT(KC_LEFT),LALT(KC_RIGHT),KC_F5, LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RIGHT)),
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),


};



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case MC_COPY_LINE:
            if (record->event.pressed) {
                return MACRO( T(HOME), D(LSFT), T(END), U(LSFT), D(LCTL), T(C), U(LCTL), END);
            }
            break;
        case MC_CUT_LINE:
            if (record->event.pressed) {
                return MACRO( T(HOME), D(LSFT), T(END), U(LSFT), D(LCTL), T(X), U(LCTL), END);
            }        
            break;
        case MC_PASTE_LINE:
            if (record->event.pressed) {
                return MACRO( T(END), T(ENTER), D(LCTL), T(V), U(LCTL), END);
            }                
            break;
        case MC_NEW_SEARCH_TAB:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(T), T(K), U(LCTL), END);
            }
            break;
        case SCREEN_TAB_LEFT:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(P), END);
            }        
            break;
        case SCREEN_TAB_RIGHT:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(N), END);
            }                    
            break;
        case SCREEN_NEW_TAB:
             if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(C), END);
            }                                
        break;
        case SCREEN_COPY_MODE:
            if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(ESC), END);
            }
        break;
        case SCREEN_PASTE:
            if (record->event.pressed) {
                return MACRO( D(LCTL), T(A), U(LCTL), T(RBRC), END); 
            }
        break;        
        case SWITCH_NDS:
             if (record->event.pressed) {
                return MACRO( D(LSFT), T(F11), U(LSFT), W(500), D(LALT), T(TAB), U(LALT), END); 
            }                                
        break;        
        case OPEN_CLOSE_PAREN:
            if (record->event.pressed) {
                return MACRO( D(LSFT), T(LPRN), T(RPRN), U(LSFT), T(LEFT), END);
            }
        break;
        case OPEN_CLOSE_BRACKET:
            if (record->event.pressed) {
                return MACRO( T(LBRC), T(RBRC), T(LEFT), END);
            }
        break;        
        case OPEN_CLOSE_CURLY:
            if (record->event.pressed) {
                return MACRO( D(LSFT), T(LCBR), T(RCBR), U(LSFT), T(LEFT), END);
            }
        break;                
        case OPEN_CLOSE_SINGLE_QUOTE:
            if (record->event.pressed) {
                return MACRO( T(QUOT), T(QUOT), T(LEFT), END);
            }
        break;        
        case OPEN_CLOSE_DOUBLE_QUOTE:
            if (record->event.pressed) {
                return MACRO( D(LSFT), T(QUOT), T(QUOT), U(LSFT), T(LEFT), END);
            }
        break;                        
        case SHELL_RECALL_LAST_ARG_REMOVE_FIRST_COMMAND:
            if (record->event.pressed) {
                return MACRO( T(UP), T(HOME), D(LALT), T(D), U(LALT), END);
            }
        break;                                
		case SEMICOLON_NEWLINE:
            if (record->event.pressed) {
                return MACRO( T(END), T(SCLN), T(ENTER), END);
            }		
		break;
		case END_NEWLINE:
            if (record->event.pressed) {
                return MACRO( T(END), T(ENTER), END);
            }		
		break;		
        
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

    return;
};

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SHIFT_CAPSLOCK]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPSLOCK),
  [TD_BRK_LEFT]  = ACTION_TAP_DANCE_DOUBLE (KC_LPRN, KC_LCBR),
  [TD_BRK_RIGHT] = ACTION_TAP_DANCE_DOUBLE (KC_RPRN, KC_RCBR)

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case NUMBER:
        case SYMBOL:
            ergodox_right_led_2_on();
            break;
        case KEY_NAV:
        case KEY_SEL:
            ergodox_right_led_3_on();
            break;        
        case SHORTCUTS:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            // none
            break;
    } 
    return;
};

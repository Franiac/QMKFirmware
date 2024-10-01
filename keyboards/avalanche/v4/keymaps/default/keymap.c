#include QMK_KEYBOARD_H

enum custom_keycodes {
    UC = SAFE_RANGE,
    AE,
    OE,
    UE,
    SZ,
    EU
};

enum layer {
    N1,
    N2,
    N3,
    G1,
    G2,
    G3
};

typedef union {
    uint32_t raw;
    struct {
        bool mode :1;
    };
} user_config_t;

user_config_t user_config;

#define MO_N2 MO(N2)
#define MO_N3 MO(N3)
#define MO_G2 MO(G2)
#define MO_G3 MO(G3)
#define TO_N1 TO(N1)
#define TO_G1 TO(G1)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[N1] = LAYOUT(
                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                                KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
        KC_NO,   KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
                 KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,  TO_G1,            TO_G1,   KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                                            KC_LGUI, KC_LALT, KC_LSFT, KC_SPC,  KC_ESC,           KC_ENT,  MO_N2,   MO_N3,   KC_RALT, KC_APP
),
[N2] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_0,    KC_1,    KC_2,    KC_3,    KC_LPRN,                                              KC_RPRN, KC_HOME, KC_UP,   KC_END,  KC_NO,   KC_NO,
        KC_CAPS, KC_TRNS, KC_0,    KC_4,    KC_5,    KC_6,    KC_DEL,                                               KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, KC_EQL,  KC_NUM,
                 KC_TRNS, KC_0,    KC_7,    KC_8,    KC_9,    KC_LCBR, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_RCBR, KC_PGDN, KC_INS,  KC_PGUP, KC_NO,   KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[N3] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_LPRN,                                              KC_RPRN, KC_EXLM, KC_AT,   KC_HASH, UE,      SZ,
        UC,      KC_TRNS, KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_DEL,                                               KC_BSPC, KC_DLR,  KC_PERC, KC_CIRC, AE,      OE,      KC_NO,
                 KC_TRNS, KC_P0,   KC_P7,   KC_P8,   KC_P9,   KC_LBRC, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_RBRC, KC_AMPR, KC_ASTR, KC_NO,   EU,      KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[G1] = LAYOUT(
                 KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                 KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,   KC_NO,
        KC_ESC,  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                 KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,   KC_ENT,
                 KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_H,    TO_N1,            TO_N1,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_J,    KC_K,    KC_LALT, KC_SPC,  KC_L,             KC_NO,   MO_G2,   MO_G3,   KC_NO,   KC_NO
),
[G2] = LAYOUT(
                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                                KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                 KC_NO,   KC_0,    KC_1,    KC_2,    KC_3,    KC_NO,                                                KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_0,    KC_4,    KC_5,    KC_6,    KC_NO,                                                KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_0,    KC_7,    KC_8,    KC_9,    KC_NO,   KC_NO,   KC_TRNS,          KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_NO
),
[G3] = LAYOUT(
                 KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_NO,                                                KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_NO,                                                KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,
                 KC_NO,   KC_P0,   KC_P7,   KC_P8,   KC_P9,   KC_NO,   KC_NO,   KC_TRNS,          KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                            KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_NO
)
};

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods();
    uint8_t shift = mods & MOD_MASK_SHIFT;

    switch (keycode) {
        case UC:
            clear_mods();

            if (record->event.pressed) {
                user_config.mode ^= 1;
                eeconfig_update_user(user_config.raw);
            }

            set_mods(mods);

            return false;
        case AE:
            clear_mods();

            if (record->event.pressed) {
                if (user_config.mode){
                    if (shift) {
                        SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_U)SS_TAP(X_P0)SS_TAP(X_P0)SS_TAP(X_C)SS_TAP(X_P4))));
                    }
                    else {
                        SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_U)SS_TAP(X_P0)SS_TAP(X_P0)SS_TAP(X_E)SS_TAP(X_P4))));
                    }
                }
                else {
                    if (shift) {
                        SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P1)SS_TAP(X_P9)SS_TAP(X_P6)));
                    }
                    else {
                        SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P2)SS_TAP(X_P8)));
                    }
                }
            }

            set_mods(mods);

            return false;
        case OE:
            clear_mods();

            if (record->event.pressed) {
                if (user_config.mode){
                    if (shift) {
                        SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_U)SS_TAP(X_P0)SS_TAP(X_P0)SS_TAP(X_D)SS_TAP(X_P6))));
                    }
                    else {
                        SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_U)SS_TAP(X_P0)SS_TAP(X_P0)SS_TAP(X_F)SS_TAP(X_P6))));
                    }
                }
                else {
                    if (shift) {
                        SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P1)SS_TAP(X_P4)));
                    }
                    else {
                        SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P4)SS_TAP(X_P6)));
                    }
                }
            }

            set_mods(mods);

            return false;
        case UE:
            clear_mods();

            if (record->event.pressed) {
                if (user_config.mode){
                    if (shift) {
                        SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_U)SS_TAP(X_P0)SS_TAP(X_P0)SS_TAP(X_D)SS_TAP(X_C))));
                    }
                    else {
                        SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_U)SS_TAP(X_P0)SS_TAP(X_P0)SS_TAP(X_F)SS_TAP(X_C))));
                    }
                }
                else {
                    if (shift) {
                        SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P2)SS_TAP(X_P0)));
                    }
                    else {
                        SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P5)SS_TAP(X_P2)));
                    }
                }
            }

            set_mods(mods);

            return false;
        case SZ:
            clear_mods();

            if (record->event.pressed) {
                if (user_config.mode){
                    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_U)SS_TAP(X_P0)SS_TAP(X_P0)SS_TAP(X_D)SS_TAP(X_F))));
                }
                else {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P2)SS_TAP(X_P3)));
                }
            }

            set_mods(mods);

            return false;

        case EU:
            clear_mods();

            if (record->event.pressed) {
                if (user_config.mode){
                    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_U)SS_TAP(X_P2)SS_TAP(X_P0)SS_TAP(X_A)SS_TAP(X_C))));
                }
                else {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P1)SS_TAP(X_P2)SS_TAP(X_P8)));
                }
            }

            set_mods(mods);

            return false;
    }

    return true;
}

#include QMK_KEYBOARD_H

enum unicode_names {
    AEL,
    AEU,
    OEL,
    OEU,
    UEL,
    UEU,
    SZ,
    EUR,
    DEG
};

const uint32_t PROGMEM unicode_map[] = {
    [AEL] = 0x00E4,  // ä
    [AEU] = 0x00C4,  // Ä
    [OEL] = 0x00F6,  // ö
    [OEU] = 0x00D6,  // Ö
    [UEL] = 0x00FC,  // ü
    [UEU] = 0x00DC,  // Ü
    [SZ]  = 0x00DF,  // ß
    [EUR] = 0x20AC,  // €
    [DEG] = 0x00B0   // °
};

enum layer {
    N1,
    N2,
    N3,
    G1,
    G2,
    G3
};

#define MO_N2 MO(N2)
#define MO_N3 MO(N3)
#define MO_G2 MO(G2)
#define MO_G3 MO(G3)
#define TO_N1 TO(N1)
#define TO_G1 TO(G1)

#define AE UP(0, 1)
#define OE UP(2, 3)
#define UE UP(4, 5)
#define SZ UM(6)
#define EUR UM(7)
#define DEG UM(8)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[N1] = LAYOUT(
                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                                KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
        KC_BSLS, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
                 KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,  TO_G1,            TO_G1,   KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                                            KC_LGUI, KC_LALT, KC_LSFT, KC_SPC,  KC_ESC,           KC_ENT,  MO_N2,   MO_N3,   KC_RALT, KC_APP
),
[N2] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_0,    KC_1,    KC_2,    KC_3,    KC_LPRN,                                              KC_RPRN, KC_HOME, KC_UP,   KC_END,  KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_0,    KC_4,    KC_5,    KC_6,    KC_DEL,                                               KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, KC_EQL,  KC_TRNS,
                 KC_TRNS, KC_0,    KC_7,    KC_8,    KC_9,    KC_LCBR, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_RCBR, KC_PGDN, KC_INS,  KC_PGUP, KC_NO,   KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[N3] = LAYOUT(
                 UC_LINX, UC_MAC,  UC_WIN,  KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_LPRN,                                              KC_RPRN, KC_EXLM, KC_AT,   KC_HASH, UE,      SZ,
        KC_CAPS, KC_TRNS, KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_DEL,                                               KC_BSPC, KC_DLR,  KC_PERC, KC_CIRC, AE,      OE,      KC_NUM,
                 KC_TRNS, KC_P0,   KC_P7,   KC_P8,   KC_P9,   KC_LBRC, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_RBRC, KC_AMPR, KC_ASTR, KC_NO,   EUR,     DEG,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[G1] = LAYOUT(
                 KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
        KC_BSLS, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
                 KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,  TO_N1,            TO_N1,   KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                                            KC_LGUI, KC_LALT, KC_SPC,  KC_RALT, KC_ESC,           KC_ENT,  MO_G2,   MO_G3,   KC_RALT, KC_APP
),
[G2] = LAYOUT(
                 KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                                KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
                 KC_TRNS, KC_0,    KC_1,    KC_2,    KC_3,    KC_LPRN,                                              KC_RPRN, KC_HOME, KC_UP,   KC_END,  KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_0,    KC_4,    KC_5,    KC_6,    KC_DEL,                                               KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINS, KC_EQL,  KC_TRNS,
                 KC_TRNS, KC_0,    KC_7,    KC_8,    KC_9,    KC_LCBR, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_RCBR, KC_PGDN, KC_INS,  KC_PGUP, KC_NO,   KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),
[G3] = LAYOUT(
                 UC_LINX, UC_MAC,  UC_WIN,  KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_LPRN,                                              KC_RPRN, KC_EXLM, KC_AT,   KC_HASH, UE,      SZ,
        KC_CAPS, KC_TRNS, KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_DEL,                                               KC_BSPC, KC_DLR,  KC_PERC, KC_CIRC, AE,      OE,      KC_NUM,
                 KC_TRNS, KC_P0,   KC_P7,   KC_P8,   KC_P9,   KC_LBRC, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_RBRC, KC_AMPR, KC_ASTR, KC_NO,   EUR,     DEG,
                                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mode = get_unicode_input_mode();

    if (mode != UNICODE_MODE_WINDOWS) {
        return true;
    }

    uint8_t mods = get_mods();
    uint8_t shift = mods & MOD_MASK_SHIFT;

    switch (keycode) {
        case AE:
            clear_mods();

            if (record->event.pressed) {
                if (shift) {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_DELAY(10)SS_TAP(X_P1)SS_DELAY(10)SS_TAP(X_P9)SS_DELAY(10)SS_TAP(X_P6)));
                }
                else {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_DELAY(10)SS_TAP(X_P2)SS_DELAY(10)SS_TAP(X_P2)SS_DELAY(10)SS_TAP(X_P8)));
                }
            }

            set_mods(mods);

            return false;
        case OE:
            clear_mods();

            if (record->event.pressed) {
                if (shift) {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_DELAY(10)SS_TAP(X_P2)SS_DELAY(10)SS_TAP(X_P1)SS_DELAY(10)SS_TAP(X_P4)));
                }
                else {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_DELAY(10)SS_TAP(X_P2)SS_DELAY(10)SS_TAP(X_P4)SS_DELAY(10)SS_TAP(X_P6)));
                }
            }

            set_mods(mods);

            return false;
        case UE:
            clear_mods();

            if (record->event.pressed) {
                if (shift) {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_DELAY(10)SS_TAP(X_P2)SS_DELAY(10)SS_TAP(X_P2)SS_DELAY(10)SS_TAP(X_P0)));
                }
                else {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_DELAY(10)SS_TAP(X_P2)SS_DELAY(10)SS_TAP(X_P5)SS_DELAY(10)SS_TAP(X_P2)));
                }
            }

            set_mods(mods);

            return false;
        case SZ:
            clear_mods();

            if (record->event.pressed) {
                SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_DELAY(10)SS_TAP(X_P2)SS_DELAY(10)SS_TAP(X_P2)SS_DELAY(10)SS_TAP(X_P3)));
            }

            set_mods(mods);

            return false;

        case EUR:
            clear_mods();

            if (record->event.pressed) {
                SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_DELAY(10)SS_TAP(X_P1)SS_DELAY(10)SS_TAP(X_P2)SS_DELAY(10)SS_TAP(X_P8)));
            }

            set_mods(mods);

            return false;

        case DEG:
            clear_mods();

            if (record->event.pressed) {
                SEND_STRING(SS_RALT(SS_TAP(X_P2)SS_DELAY(10)SS_TAP(X_P4)SS_DELAY(10)SS_TAP(X_P8)));
            }

            set_mods(mods);

            return false;
    }

    return true;
}

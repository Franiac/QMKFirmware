# Avalanche

## Compile

```PS
qmk compile -kb avalanche/v4 -km default
```

## Flash

### For DFU Bootloader

```PS
qmk flash -kb avalanche/v4 -km default -bl dfu-split-[left|right]
```

### For Caterina Bootloader

```PS
qmk flash -kb avalanche/v4 -km default -bl avrdude-split-[left|right]
```

## Enable Debug Mode

Modify `keyboard.json`:

```JSON
{
  "console": true
}
```

Use `keyboard_post_init_user` in `keymap.c`:

```C
void keyboard_post_init_user(void) {
    debug_enable=true;
}
```

## Log Key Info

Include `print.h` in `keymap.c`:

```C
#include "print.h"
```

Print key info:

```C
uprintf("KC: 0x%04X, MOD: 0x%04X, COL: %2u, ROW: %2u, PRESSED: %u, TIME: %5u, INT: %u, COUNT: %u\n", keycode, get_mods() & MOD_MASK_SHIFT, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
```

## Unicode

### Windows-1252 Codepage

Define macro enum:

```C
enum custom_keycodes {
    AE = SAFE_RANGE,
    OE,
    UE,
    SZ,
    EU
};
```

Implement macros:

```C
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods();
    uint8_t shift = mods & MOD_MASK_SHIFT;

    switch (keycode) {
        case AE:
            clear_mods();

            if (record->event.pressed) {
                if (shift) {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P1)SS_TAP(X_P9)SS_TAP(X_P6)));
                }
                else {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P2)SS_TAP(X_P8)));
                }
            }

            set_mods(mods);

            return false;
        case OE:
            clear_mods();

            if (record->event.pressed) {
                if (shift) {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P1)SS_TAP(X_P4)));
                }
                else {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P4)SS_TAP(X_P6)));
                }
            }

            set_mods(mods);

            return false;
        case UE:
            clear_mods();

            if (record->event.pressed) {
                if (shift) {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P2)SS_TAP(X_P0)));
                }
                else {
                    SEND_STRING(SS_RALT(SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P5)SS_TAP(X_P2)));
                }
            }

            set_mods(mods);

            return false;
        case SZ:
            clear_mods();

            if (record->event.pressed) {
                SEND_STRING(SS_DOWN(X_RALT)SS_TAP(X_P0)SS_TAP(X_P2)SS_TAP(X_P2)SS_TAP(X_P3)SS_UP(X_RALT));
            }

            set_mods(mods);

            return false;

        case EU:
            clear_mods();

            if (record->event.pressed) {
                SEND_STRING(SS_RALT(SS_TAP(X_P8)SS_TAP(X_P3)SS_TAP(X_P6)SS_TAP(X_P4)));
            }

            set_mods();

            return false;
    }

    return true;
}
```

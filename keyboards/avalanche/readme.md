# Avalanche

## Sync Fork

1. On GitHub select the `master` branch and `sync fork`
2. Pull `master` and sub-repos locally
3. Merge `master` into `franiac`
4. Run `git clean -fdx` in order to prevent build errors

## Compile

```PS
qmk compile -kb avalanche/v4 -km default
```

## Flash

### For DFU Bootloader (Sea Micro)

```PS
qmk flash -kb avalanche/v4 -km default -bl dfu-split-[left|right]
```

### For Caterina Bootloader (Pro Micro)

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

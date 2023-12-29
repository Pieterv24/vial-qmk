# Keymap with deej functionality

This keymap needs a special version of deej to support HID devices, this can be found [here](https://github.com/Pieterv24/deej/tree/qmk).  

## Usage (QMK)
To make a keymap for a QMK keyboard you need to do the following.  

- Enable raw hid communication, you do this by adding `ENABLE_RAW = true` to your rules.mk file
- Add the deej.h and deej.c files to your keymap folder
- Link them in to your keymap by adding `SRC += deej.c` to your rules.mk
- (Recommended) Define `RAW_USAGE_PAGE` and `RAW_USAGE_ID` in your config.h, this makes sure you know what usage page and usage should be used on the deej side.
```c
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
```
- Add the following to your keymap.c
```c
// Process a keypress and send it to the deej function
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_deej(keycode, record);
}

// Process a encoder change and send it to deej for processing
void encoder_update_user(uint8_t index, bool clockwise) {
    encoder_update_deej(index, clockwise);
}
```

## Usage (Deej)
- Build the version of deej with support for QMK on your prefered OS.  
- Add line `enable_hid_listen: true` to deej config.yaml
- Add the vendor_id, product_id, usage_page and usage to your deej config.yaml
```yaml
# settings for hid_listen (qmk)
enable_hid_listen: true

# settings for connecting to HID device
vendor_id: 0x23F2
product_id: 0x78F8
usage_page: 0xFF60
usage: 0x61
```
- run deej

## Advanced QMK configuration
If you want more than the 4 sliders provided in this example, you can edit the deej.c and deej.h files to suit your needs.  

### Add slider
To add a slider, you need to do the following:
- Add an slider name to the deej_sliders enum in deej.c
```c
enum deej_sliders {
    MASTER,
    SPOTIFY,
    GAME,
    MIC,
    NEW_SLIDER /* Added new slider in deej_sliders */
};
```
- Add a entry to the deej_keycodes in deej.h to make a new custom keycode for it. (Place the entry before `NEW_SAFE_RANGE`)
```c
enum deej_keycodes {
    DEEJ_VD = SAFE_RANGE,
    DEEJ_VU,
    DEEJ_MASTER,
    DEEJ_SPOTIFY,
    DEEJ_GAME,
    DEEJ_MIC,
    DEEJ_NEW_SLIDER, /* Added new slider keycode */
    NEW_SAFE_RANGE
};
```
- Add a switch case to `bool process_record_deej` in deej.c
```c
bool process_record_deej(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case DEEJ_VU:
                deej_volu();
                break;
            ....
            case DEEJ_NEW_SLIDER: /* Name of keycode you created */
                currentSlider = NEW_SLIDER; /* Set currentSlider to new Slider */
                break;
            default:
                return true;
        }
    }
    return true;
}
```
- Use your new keycode in your keymap
- ......
- Profit

### Use in combination with own custom keycodes

You can use this deej code in tandem with your own custom keycodes.  
To do so you can add custom keycodes like you usually do, but with 2 changes.

- Use `NEW_SAFE_RANGE` instead of `SAFE_RANGE` when defining new keycodes
- Make sure `process_record_deej` is called from `process_record_user`.

#### When using encoders
You can also programm your own encoder behavior, just make sure `encoder_update_deej` is called from `encoder_update_user` when a deej action should be performed

## Notes
This example has code for [VIA](https://caniusevia.com) and [VIAL](https://get.vial.today)

Read the respective sites if this interests you

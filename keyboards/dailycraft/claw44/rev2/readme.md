# WhiteFox

A compact 65% keyboard.

<<<<<<<< HEAD:keyboards/input_club/whitefox/readme.md
* Keyboard Maintainer: QMK Community
* Hardware Supported: Whitefox PCB
* Hardware Availability: https://input.club/whitefox/

Make example for this keyboard (after setting up your build environment):

    make input_club/whitefox:default

Flashing example for this keyboard:

    make input_club/whitefox:default:flash
========
A split keyboard with 3x6 vertically staggered keys and 4 thumb keys.

* Keyboard Maintainer: [yfuku](https://github.com/yfuku)
* Hardware Supported: Claw44 PCB, ProMicro
* Hardware Availability: https://shop.dailycraft.jp/

Make example for this keyboard (after setting up your build environment):

    make dailycraft/claw44:default

Flashing example for this keyboard:

    make dailycraft/claw44:default:flash
>>>>>>>> yfuku/topic-claw44-rev2~12:keyboards/dailycraft/claw44/rev2/readme.md

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: Briefly press the button on the PCB
* **Keycode in layout**: Press the key mapped to `RESET` if it is available

# QMK 
This is a fork of [framework qmk firmware](https://github.com/FrameworkComputer/qmk_firmware) which is a fork of [qmk_firmware](https://github.com/qmk/qmk_firmware) this included modifications for building firmware for my personal macropad layout.


## Instructions for how you can build a custom layout for your macropad

most of this could also apply to any framework keyboard but I will be including specific instructions for the RGB macropad. I am also going to use the name of the layout that I made `fuzpad` but this can be replaced with any name.

- clone [framework qmk firmware](https://github.com/FrameworkComputer/qmk_firmware), you could also just clone this repo but using the most recent official release from framework is the best idea
- make a copy of [keyboards/framework/macropad/keymaps/default](keyboards/framework/macropad/keymaps/default) and call it whatever you want
- in your new directory change the layout however you like
- if you want to create custom RGB patterns or be able to have per key rgb lighting (at time of writing this is the only way to get per key RGB control) follow the following steps, if not skip the next set of steps
  - in [keyboards/framework/macropad/rules.mk](keyboards/framework/macropad/rules.mk) add `RGB_MATRIX_CUSTOM_USER = yes`
  - create [keyboards/framework/macropad/keymaps/fuzpad/rgb_matrix_user.inc](keyboards/framework/macropad/keymaps/fuzpad/rgb_matrix_user.inc) details for how to define custom RGB patterns can be found [here](https://docs.qmk.fm/features/rgb_matrix#custom-rgb-matrix-effects)
- once your new layout is ready you can build it, an example command to build is `RUNTIME="podman" util/docker_build.sh framework/macropad:fuzpad:build` you might want to change the runtime to docker and update the name of your key map
- this will create `framework_macropad_fuzpad.uf2` in the project directory root
- there are a few ways to get your macropad into the bootloader, I recommend cloning and building [qmk_hid](https://github.com/FrameworkComputer/qmk_hid) then run `qmk_hid --vid=32ac --pid=0013 via --bootloader`
- you should now see a new usb storage device, mount this and copy `framework_macropad_fuzpad.uf2` into it, don't worry about doing anything special just copy it to the top level directory and unmount the drive
- you might need to reset the eeprom, especialy if you have used the via framework web config tool, to do so just run `qmk_hid --vid=32ac --pid=0013 via --eeprom-reset`
- your new custom layout should be working now

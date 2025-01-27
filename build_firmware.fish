#!/bin/env fish

set old_path $PWD
cd /home/fuzzy/DevSSD/qmk/framework_qmk_firmware
RUNTIME="podman" util/docker_build.sh framework/macropad:fuzpad:build
cd $old_path

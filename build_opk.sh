#!/bin/sh

cd src 
make -j$(nproc) || exit
cd ..
chmod +x dist/alert

convert dist/alert.png  -filter point -resize 32x32! dist/icon.png

mksquashfs \
    dist/*         \
    default.gcw0.desktop alert-$(date '+%s').opk -noappend

#!/bin/sh
NAME_EXEC=main

find ./libs/* -exec adb push {} /data/local/tmp  \;


find build/$NAME_EXEC -exec adb push {} /data/local/tmp \;
adb shell LD_LIBRARY_PATH="/data/local/tmp:/vendor/lib:/system/lib" /data/local/tmp/$NAME_EXEC /sdcard/cynny_samples 1


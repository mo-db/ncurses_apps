#!/bin/bash

set -xe

CFLAGS="-g -Wall"
LIBS="-lncurses"

FILE="simple_playback_sine"

clang $CFLAGS -o "./out/$FILE" "./$FILE.c" $LIBS

"./out/$FILE"

#!/bin/bash

set -xe

CFLAGS="-g"
LIBS="-lncurses -L/usr/local/lib -lSDL3 -L/opt/homebrew/Cellar/sdl2/2.30.3/lib -lSDL2"

FILE="mun"
PROJECT="decimal_knob"

clang $CFLAGS -o "./out/$FILE" "./$FILE.c" $LIBS

"./out/$FILE"

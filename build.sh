#!/bin/bash

set -xe

CFLAGS="-g"
LIBS="-lncurses ./decimal_knob//lib/libraylib.a"

FILE="main"
PROJECT="decimal_knob"

clang $CFLAGS -o "./$PROJECT/out/$FILE" "./$PROJECT/$FILE.c" $LIBS

"./$PROJECT/out/$FILE"

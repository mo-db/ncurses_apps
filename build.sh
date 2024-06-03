#!/bin/bash

set -xe

CFLAGS="-g"
LIBS="lncurses"

FILE="worm"
PROJECT="decimal_knob"

clang $CFLAGS -o "./$PROJECT/out/$FILE" "./$PROJECT/$FILE.c" -$LIBS

"./$PROJECT/out/$FILE"

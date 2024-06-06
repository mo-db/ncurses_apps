#!/bin/bash

set -xe

CFLAGS="-g"
LIBS="lncurses"

FILE="main"
PROJECT="decimal_knob"

clang $CFLAGS -o "./$PROJECT/out/$FILE" "./$PROJECT/$FILE.c" -$LIBS

"./$PROJECT/out/$FILE"

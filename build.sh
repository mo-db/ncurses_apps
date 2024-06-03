#!/bin/bash

set -xe

CFLAGS="-g"
LIBS=""

FILE="main"
PROJECT="decimal_knob"

clang $CFLAGS -o ./$PROJECT/out/$FILE ./$PROJECT/$FILE.c

"./$PROJECT/out/$FILE"

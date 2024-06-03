@echo off

SET "CFLAGS=-g"
SET "LIBS="
SET "FILE=5-0_pointer"

gcc %CFLAGS% src\%FILE%.c -o output\%FILE% 

output\%FILE%.exe
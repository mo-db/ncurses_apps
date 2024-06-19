CC=Clang #Clang
INCDIRS=-I.
OPT=-O0
CFLAGS=-Wall -Wextra -g $(INDIRS) $(OPT)

OBJECTS=samplib.o

BINARY=bin

all: $(BINARY)

$(BINARY): main.c samplib.o
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ samplib.c

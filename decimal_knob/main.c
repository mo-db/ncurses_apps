#include <ncurses.h>
#define MINIAUDIO_IMPLEMENTATION
#include "../libs/miniaudio-0.11.21/miniaudio.h"

int main()
{
	printf("miniaudio version: %d\n", MA_VERSION_MINOR);
	printf("ncurses version: %d,%d,%d \n", NCURSES_VERSION_MAJOR, NCURSES_VERSION_MINOR, NCURSES_VERSION_PATCH);
	printf("hello world!\n");
	return 0;
}

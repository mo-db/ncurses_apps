#define MINIAUDIO_IMPLEMENTATION
#include "../libs/miniaudio-0.11.21/miniaudio.h"
#include "./include/raylib.h"
#include <ncurses.h>
//#include "../libs/SDL2-2.30.3/include/SDL.h"

int main()
{
	printf("miniaudio version: %d\n", MA_VERSION_MINOR);
	printf("raylib version: %d\n", RAYLIB_VERSION_MAJOR);
	printf("ncurses version: %d,%d,%d \n", NCURSES_VERSION_MAJOR, NCURSES_VERSION_MINOR, NCURSES_VERSION_PATCH);
	printf("hello world!\n");
	float val = 0.0;
	while (1) {
		if (IsKeyDown(KEY_LEFT)) {
			val -= 0.01;
			printf("%f\n", val);
		}
		if (IsKeyDown(KEY_RIGHT)) {
			val += 0.01;
			printf("%f\n", val);
		}
		if (IsKeyDown(KEY_B)) {
			break;
			printf("exitting program!");
		}
	}
	return 0;
}

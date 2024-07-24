#define MINIAUDIO_IMPLEMENTATION
#include "../libs/miniaudio-0.11.21/miniaudio.h"
#include <signal.h>
#include <stdlib.h>
#include "../libs/raylib/include/raylib.h"
#include <ncurses.h>

static void finish(int sig);

int
main(int argc, char *argv[])
{
    int num = 0;

    /* initialize your non-curses data structures here */

    (void) signal(SIGINT, finish);      /* arrange interrupts to terminate */

    (void) initscr();      /* initialize the curses library */
    keypad(stdscr, TRUE);  /* enable keyboard mapping */
    (void) nonl();         /* tell curses not to do NL->CR/NL on output */
    (void) cbreak();       /* take input chars one at a time, no wait for \n */
    (void) halfdelay(5);
    (void) noecho();         /* echo input - in color */

    int c = ERR;
    printf("rayversion: %c\n", RAYLIB_VERSION_MAJOR);
    for (;;)
    {
        num += 1;
        if (IsKeyDown(KEY_RIGHT)) {
            move(num,1);
            //addch('s'); 
            printf("%d\n", num);
        }
        /* process the command keystroke */

    }

    finish(0);               /* we are done */
}

static void finish(int sig)
{
    endwin();

    /* do your non-curses wrapup here */

    exit(0);
}

#include <stdio.h>
#include "../libs/raylib/include/raylib.h"

int main(int argc, char *argv[])
{
    int num = 0;

    printf("rayversion: %c\n", RAYLIB_VERSION_MAJOR);
    for (;;)
    {
        num += 1;
        if (IsKeyDown(KEY_RIGHT)) {
            printf("%d\n", num);
        }
        if (IsKeyDown(KEY_ESCAPE)) break;
        /* process the command keystroke */

    }
    return 0;
}

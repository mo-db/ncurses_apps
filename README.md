### To get raylib working on macos follow wiki and compile with the following if copied into dir.

Clang main.c  -L lib/ -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL lib/libraylib.a -o compiled-raylib-game

### To make ncurses find the lib
export PATH="/opt/homebrew/opt/ncurses/bin:$PATH"
export LDFLAGS="-L/opt/homebrew/opt/ncurses/lib"
export CPPFLAGS="-I/opt/homebrew/opt/ncurses/include"
export CPATH="/opt/homebrew/opt/include:$CPATH"

# important to include right version, not the macos provided lib
export C_INCLUDE_PATH="/opt/homebrew/opt/ncurses/include:$C_INCLUDE_PATH" 

### the fucking order of including libs matters, cantinclude ncurses bevore raylib why the fuck ever this is the case!!!!!!! fuck u

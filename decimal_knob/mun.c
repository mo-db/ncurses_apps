
/*
 * SDL2 mousebutton test
 * 
 * build with:
 * $ gcc $(sdl2-config --cflags) -o sdl2test sdl2test.c $(sdl2-config --libs)
 */
#include <SDL_events.h>
#include <stdio.h>
//#include <SDL2/SDL.h>
#include <SDL3/SDL.h>
#include <stdlib.h>

void eventloop(FILE* outfile) {
	while(1) {
		SDL_Event ev;
		if(SDL_PollEvent(&ev) == 0) {
			//printf(".\n");
			SDL_Delay(1);
			continue;
		}
		
		switch(ev.type) {
			case SDL_EVENT_QUIT:
				fprintf(outfile, "Received SDL_QUIT - bye!\n");
				return;
				
			case SDL_EVENT_MOUSE_BUTTON_UP:
				fprintf(outfile, "SDL_MOUSEBUTTONUP, button %d clicks %d\n", ev.button.button, (int)ev.button.clicks);
				break;
				
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				fprintf(outfile, "SDL_MOUSEBUTTONDOWN, button %d clicks %d\n", ev.button.button, (int)ev.button.clicks);
				break;
				
			case SDL_EVENT_KEY_UP:
			case SDL_EVENT_KEY_DOWN:
				if(ev.type == SDL_EVENT_KEY_UP)
					fprintf(outfile, "SDL_KEYUP: ");
				else
					fprintf(outfile, "SDL_KEYDOWN: ");
				
				fprintf(outfile, "Keycode: %s (%d) Scancode: %s (%d)\n", 
					   SDL_GetKeyName(ev.key.keysym.sym), ev.key.keysym.sym,
					   SDL_GetScancodeName(ev.key.keysym.scancode),
					   ev.key.keysym.scancode);
				
				if(ev.key.keysym.sym == SDLK_q) {
					fprintf(outfile, "You pressed Q - bye!\n");
					return;
				}
				
				break;

			case SDL_EVENT_MOUSE_WHEEL:
				fprintf(outfile, "MouseWheel: x: %d, y: %d\n", ev.wheel.x, ev.wheel.y);
				break;
				
			case SDL_EVENT_TEXT_INPUT:
				fprintf(outfile, "SDL_TEXTINPUT: %s\n", ev.text.text ? ev.text.text : "<NULL>");
				break;
			
			case SDL_EVENT_JOYSTICK_BUTTON_DOWN:
				fprintf(outfile, "SDL_JOYBUTTONDOWN dev %d button %d state %d\n",
						(int)ev.jbutton.which, (int)ev.jbutton.button, (int)ev.jbutton.state);
				break;
			case SDL_EVENT_JOYSTICK_BUTTON_UP:
				fprintf(outfile, "SDL_JOYBUTTONUP dev %d button %d state %d\n",
						(int)ev.jbutton.which, (int)ev.jbutton.button, (int)ev.jbutton.state);
				break;
			
			case SDL_EVENT_MOUSE_MOTION:
			case SDL_EVENT_FINGER_DOWN:
			case SDL_EVENT_FINGER_UP: 
			case SDL_EVENT_FINGER_MOTION:
				break; // ignore
			
			case SDL_WINDOWEVENT:
				break;
			
			default:
				// fprintf(outfile, "SDL_Event of type: 0x%x received\n", ev.type);
				break;
		}
	}
}


int main(int argc, char** argv) {
	//SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
	SDL_Init(SDL_INIT_EVENTS);
	
	//SDL_StartTextInput();
	
	SDL_Joystick* gGameController = NULL;
	
	SDL_Window* win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	
	//SDL_SetRelativeMouseMode(1);
	//SDL_SetWindowGrab(win, 1);
	
	SDL_SetWindowTitle(win, "SDL input test");
	
	// fill the window with black, so it shows something deterministic
	// (and works with wayland)
	{
		SDL_Surface *s = SDL_GetWindowSurface(win);
		Uint32 black = SDL_MapRGB(s->format, 0, 0, 0);
		
		SDL_FillRect(s, NULL, black);
		SDL_UpdateWindowSurface(win);
	}
	
	if( SDL_NumJoysticks() < 1 )
	{
		printf( "Warning: No joysticks connected!\n" );
	}
	else
	{
		//Load joystick
		gGameController = SDL_JoystickOpen( 0 );
		if( gGameController == NULL )
		{
			printf( "Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError() );
		}
	}
	
#ifdef _WIN32
	// output debug prints to file on windows
	const char* filename = "sdl2_test_out.txt";
#else
	// output debug prints to stdout on other OS
	const char* filename = "-";
#endif
	FILE* output = NULL;
	if(argc > 1) {
		filename = argv[1];
	}
	
	if(strcmp(filename, "-") == 0)
		output = stdout;
	else
		output = fopen(filename, "w");
	
	if(!output) {
		fprintf(stderr, "Couldn't create debug output file!\n");
		exit(1);
	}
	eventloop(output);
	
	if(strcmp(filename, "-") != 0)
		fclose(output);
	
	SDL_JoystickClose( gGameController );
	gGameController = NULL;
	
	SDL_DestroyWindow(win);

	SDL_Quit();
	
	return 0;
}


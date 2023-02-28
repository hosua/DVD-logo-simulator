#include "dvd.h"

int main(){
	GFX* gfx = new GFX();
	gfx->clearScreen();
	if (SDL_Init(SDL_INIT_EVERYTHING)){ 
		fprintf(stderr, "Fatal error: Failed to initialize SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	while (1){
		SDL_Event event;
		while (SDL_PollEvent(&event)){
			switch(event.key.keysym.sym){
				case SDLK_ESCAPE:
					gfx->cleanQuit();
					break;
			}
		}
		gfx->_dvd_logo.updatePos();
		gfx->clearScreen();
		gfx->render();
		gfx->renderPresent();
	}
}

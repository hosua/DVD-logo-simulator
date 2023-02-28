#include "dvd.h"

int main(int argc, char *argv[]){

	if (SDL_Init(SDL_INIT_EVERYTHING)){ 
		fprintf(stderr, "Fatal error: Failed to initialize SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	GFX* gfx = new GFX();

	while (1){
		SDL_Event event;

		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT || 
					(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
				gfx->cleanQuit();
		}


		gfx->_dvd_logo.updatePos();
		gfx->clearScreen();
		gfx->render();
		gfx->renderPresent();
	}
}

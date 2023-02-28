#include "dvd.h"

int main(){
	GFX* gfx = new GFX();
	gfx->clearScreen();
	if (SDL_Init(SDL_INIT_EVERYTHING)){ 
		fprintf(stderr, "Fatal error: Failed to initialize SDL: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	while (1){
		gfx->_dvd_logo.updatePos();
		gfx->clearScreen();
		gfx->render();
		gfx->renderPresent();
	}
}

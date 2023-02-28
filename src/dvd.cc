#include "dvd.h"

void GFX::init(){
	_window = SDL_CreateWindow("Maze", 
			SDL_WINDOWPOS_CENTERED, 
			SDL_WINDOWPOS_CENTERED, 
			SCREEN_W, SCREEN_H, 
			0);

	if (not _window){
		fprintf(stderr, "Fatal Error: Window failed to initialize\n");
		fprintf(stderr, "SDL2 Error: %s\n", SDL_GetError());
		cleanQuit(false);
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	_texture = NULL;

	_surface = SDL_GetWindowSurface(_window);

	if (not _surface){
		fprintf(stderr, "Failed to get _surface from _window.\n");
		fprintf(stderr, "SDL2 Error: %s", SDL_GetError());
		cleanQuit(false);
	}

	// Allows for transparent rendering
	SDL_SetRenderDrawBlendMode(_renderer, SDL_BLENDMODE_BLEND);
}

void GFX::cleanQuit(bool success){
	printf("Quitting, goodbye!\n");
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
	return (success) ? exit(EXIT_SUCCESS) : exit(EXIT_FAILURE);
}

void GFX::clearScreen(){
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255); // draw black screen
	SDL_RenderClear(_renderer);
}

void GFX::render(){
	SDL_Rect dest = { .x=_dvd_logo._x, .y=_dvd_logo._y, .w=LOGO_W, .h=LOGO_H };
	_surface = IMG_Load(DVD_FILENAME);
	_texture = SDL_CreateTextureFromSurface(_renderer, _surface);
	SDL_SetTextureColorMod(_texture, _dvd_logo._r, _dvd_logo._g, _dvd_logo._b);
	SDL_FreeSurface(_surface);
	SDL_RenderCopy(_renderer, _texture, NULL, &dest);
	SDL_DestroyTexture(_texture);
}

void GFX::renderPresent(){
	SDL_RenderPresent(_renderer);
}

// What the hell am I doing with my life
void GFX::DVDLogo::updatePos(){
	// TODO: To be implemented	
	if (_x < 0 || _x+LOGO_W > SCREEN_W){
		_x_dir *= -1;
		setRandomColor();
	}
	if (_y < 0 || _y+LOGO_H > SCREEN_H){
		_y_dir *= -1;
		setRandomColor();
	}
	_x += _x_dir;
	_y += _y_dir;
	std::this_thread::sleep_for(std::chrono::milliseconds(5));
}

void GFX::DVDLogo::setRandomColor(){
	_r = (std::rand() % (255+1));
	_g = (std::rand() % (255+1));
	_b = (std::rand() % (255+1));
}

#ifndef DVD_H
#define DVD_H

#include <SDL2/SDL_scancode.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <bits/stdc++.h>
using namespace std;

#define DVD_FILENAME "img/dvd-logo.png"
#define SCREEN_W 1280
#define SCREEN_H 720
#define LOGO_W 230 // dvd-logo-2 (original: 335x150)
#define LOGO_H 102


class GFX {
public:
	SDL_Window* _window;
	SDL_Surface* _surface;
	SDL_Renderer* _renderer;
	SDL_Texture* _texture;

	// Not using this anywhere else so I'm just gonna throw this here
	struct DVDLogo {
		int _x, _y;
		int _x_dir, _y_dir;
		uint8_t _r, _g, _b;
		DVDLogo(): _x(SCREEN_W/2), _y(SCREEN_H/2), _x_dir(1), _y_dir(1) { setRandomColor(); }
		void setRandomColor(); // TODO
		void updatePos();
	};

	DVDLogo _dvd_logo;

	GFX(): _window(nullptr), _surface(nullptr), _renderer(nullptr), _texture(nullptr){ init(); }
	void init();
	void cleanQuit(bool flag=true);
	void clearScreen();
	void render();
	void renderPresent();
};

#endif // DVD_H

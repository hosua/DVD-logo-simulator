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

#define LOGO_W 230 // 335x150
#define LOGO_H 102
#define LOGO_VEL 3

#define FPS 60

extern int g_corner_bounce_counter;

class GFX {
	public:
		mutable SDL_Window* _window;
		mutable SDL_Surface* _surface;
		mutable SDL_Renderer* _renderer;
		mutable SDL_Texture* _texture;

		struct DVDLogo {
			int x, y;
			int x_dir, y_dir;
			uint8_t r, g, b;
			DVDLogo(): x(SCREEN_W/2), y(SCREEN_H/2), x_dir(1), y_dir(1) { setRandomColor(); }
			void setRandomColor(); 
			void updatePos();
		};

		DVDLogo _dvd_logo;

		GFX(): _window(nullptr), _surface(nullptr), _renderer(nullptr), 
		_texture(nullptr) { init(); }

		void init();
		void cleanQuit(bool flag=true) const;
		void clearScreen() const;
		void render() const;
		void renderPresent() const;
};

#endif // DVD_H

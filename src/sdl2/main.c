#include <stdio.h>
#include <stdlib.h>
#include "rom.h"
#include <SDL2/SDL.h>

	SDL_Window *win;
	SDL_Renderer *rend;
	SDL_Texture *tex;

static bool platform_init() 
{
	uint32_t render_flags;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0) {
		printf("Coud not initialize sdl2 properly");

		return false;
	}
	/*video*/
	win = SDL_CreateWindow("chip8n64", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

	if (win == NULL) {
		printf("Cannot create window: %s\n", SDL_GetError());
		SDL_Quit();

		return false;
	}

	render_flags = SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED;
	rend = SDL_CreateRenderer(win, -1, render_flags);

	if (rend == 0) {
		printf("Error creating renderer");
		SDL_DestroyWindow(win);
		SDL_Quit();

		return false;
	}

	tex = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STATIC, 64, 32);

	if (tex == 0) {
		printf("Could not create texture");
		SDL_DestroyRenderer(rend);
		SDL_DestroyWindow(win);
		SDL_Quit();

		return false;
	}	
}

int main(int argc, char *argv[])
{

	if (argc < 2) {
		fprintf(stderr, "Usage: %s [rom name]\n", argv[0]);
		return EXIT_FAILURE;
	}

	printf("Hello World, casual\n");

	if (load_rom(argv[1]) == false) 
		return EXIT_FAILURE;

	platform_init();
	cpu_reset();
	cpu_step();
	cpu_step();
	cpu_step();
	cpu_step();
	cpu_step();
		
	return EXIT_SUCCESS;
}

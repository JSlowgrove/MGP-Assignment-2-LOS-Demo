#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "JAM/Texture.h"
#include "JAM/StateManager.h"

#include "Game.h"

int main(int argc, char *argv[])
{

#ifdef _WIN32

	/*Initialise SDL needed for desktop*/
	if (SDL_Init(SDL_INIT_VIDEO) < 0) //Check SDL initialisation
	{
		//Failed initialisation
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialise SDL");
		return -1;
	}

#endif

	/*Initialise SDL_ttf*/
	if (TTF_Init() < 0) /*Check SDL_ttf initialisation*/
	{
		/*Failed initialisation*/
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialise SDL_ttf");
		return -1;
	}

	/*Initialise SDL_mixer*/
	Mix_Init(MIX_INIT_OGG);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		/*Failed initialisation*/
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialise SDL_Mixer");
		return -1;
	}

	/*Initialize PNG loading*/
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		/*Failed initialisation*/
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to initialise SDL_image");
		return -1;
	}

	/*Time Check*/
	unsigned int lastTime = SDL_GetTicks();

	SDL_Window* window;
	SDL_Renderer* renderer;
	int winWidth;
	int winHeight;

#ifdef __ANDROID__

	if(SDL_CreateWindowAndRenderer(0, 0, 0, &window, &renderer) < 0)
		exit(2);

	SDL_GetWindowSize(window, &winWidth, &winHeight);

#elif _WIN32

	/*Create Window*/
	int winPosX = 100;
	int winPosY = 100;
	winWidth = 640;
	winHeight = 480;
	window = SDL_CreateWindow("MGPDemoLOS",  /*The first parameter is the window title*/
		winPosX, winPosY,
		winWidth, winHeight,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	/*Create Renderer from the window*/
	renderer = SDL_CreateRenderer(window, -1, 0);

#endif

	/*setup state manager*/
	JAM_StateManager * stateManager = new JAM_StateManager();
	/*set the initial state*/
	stateManager->addState(new Game(stateManager, renderer, winWidth, winHeight));

	/*Start Game Loop*/
	bool go = true;
	while (go)
	{
		/*Time Check*/
		unsigned int current = SDL_GetTicks();
		float deltaTime = (float)(current - lastTime) / 1000.0f;
		lastTime = current;

		/*handle the current state inputs*/
		go = stateManager->input();

		/*update the current state*/
		stateManager->update(deltaTime);

		/*set draw colour to black*/
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

		/*Clear the entire screen to the set colour*/
		SDL_RenderClear(renderer);

		/*draw the states*/
		stateManager->draw();

		/*display renderer*/
		SDL_RenderPresent(renderer);

		/*Time Limiter*/
		if (deltaTime < (1.0f / 50.0f))
		{
			SDL_Delay((unsigned int)(((1.0f / 50.0f) - deltaTime)*1000.0f));
		}
	}
	/*destroy data*/
	delete stateManager;
	SDL_DestroyWindow(window);
	SDL_Quit();
	exit(0);
	return 0;
}
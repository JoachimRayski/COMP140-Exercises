// COMP140Collections.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Sprite.h"

#include "Object.h"
#include "Body.h"

int main(int, char**)
{
	int windowWidth = 800;
	int windowHeight = 640;
	//Initialise the Video Part of SDL2
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		//Print out an error message to the screen if this fails
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	//Initalise the font library
	if (TTF_Init() != 0)
	{
		std::cout << "Unable to load SDL TTF " << TTF_GetError() << std::endl;
	}
	
	//Initialise IMG Library
	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	if (IMG_Init(flags) != flags)
	{
		std::cout << "Unable to load IMG Library " << IMG_GetError() << std::endl;
	}

	//Creare a 800x640
	SDL_Window *window = SDL_CreateWindow("Inheritance", 100, 100, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		//Print out error if this fails
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		TTF_Quit();
		SDL_Quit();
		return 1;
	}

	//Create a renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		//Print error and cleanup
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window);
		TTF_Quit();
		SDL_Quit();
		return 1;
	}



	Object* testObject = new Object(renderer, "assets/sprites/roguelikeChar_transparent.png");
	testObject->CreateSprite(0, 8);

	//Controls the game loop
	bool quit = false;
	//Holds events coming from SDL
	SDL_Event event;
	//Game Loop, while quit is false
	while (!quit)
	{
		//Check for Messages from SDL
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
				//Quit Message
				case SDL_QUIT:
				{
					quit = true;
					break;
				}
				//Key Down
				case SDL_KEYDOWN:
				{
					//if we have pressed the escape key
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						quit = true;
					}
					break;
				}
			}
		}

		//Clear the renderer
		SDL_RenderClear(renderer);



		//Display the work the renderer has been doing, this make something appear on the screen

		//Draw the sprite!
		testObject->Draw();
		
		SDL_RenderPresent(renderer);
	}

	delete testObject;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();

    return 0;
}


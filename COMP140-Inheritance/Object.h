#pragma once

#include "Sprite.h"

class Object
{
public:
	Object(SDL_Renderer *renderer, char* filePath);
	~Object();

	SDL_Renderer * objectRenderer;
	Sprite * objectSprite;

	virtual void Draw();

private:
	SDL_Texture * charactersTexture;
};


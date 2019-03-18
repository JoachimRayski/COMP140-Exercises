#pragma once

#include "Sprite.h"

class Object
{
public:
	Object();
	Object(SDL_Renderer *renderer, char* filePath);
	~Object();

	SDL_Renderer * objectRenderer;
	Sprite * objectSprite;

	void CreateSprite(int x, int y);
	virtual void Draw();

private:
	SDL_Texture * charactersTexture;
};


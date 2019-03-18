#include "stdafx.h"
#include "Object.h"


Object::Object()
{
}

Object::Object(SDL_Renderer *renderer, char* filePath)
{
	objectRenderer = renderer;
	//Load any assets, we first have to load into a surface and then create a texture
	SDL_Surface * charactersSurf = IMG_Load(filePath);
	charactersTexture = SDL_CreateTextureFromSurface(renderer, charactersSurf);
	//We can now delete the surface
	SDL_FreeSurface(charactersSurf);
}


Object::~Object()
{
	//cleanup!
	if (objectSprite)
	{
		delete objectSprite;
		objectSprite = nullptr;
	}
	SDL_DestroyTexture(charactersTexture);
}

void Object::CreateSprite(int x, int y)
{
	//Create a test sprite, you will be deriving new classes from this
	objectSprite = new Sprite();
	//set the texture we are using, please note we are using one big texture and indexing
	//using the source rectangel
	objectSprite->SetTexture(charactersTexture);
	//we are taking a slice of the texture from 0,85 on x and y with a width of 16, 16
	//see spritesheetInfo in assets/sprites folder for details
	x *= 18 - 1;
	y *= + 18 - 1;
	objectSprite->SetSourceRectangle(x, y, 16, 16);
	//we are drawing thje sprite at 200,200 and 32, 32
	objectSprite->SetDestinationRectangle(200, 200, 32, 32);
}

void Object::Draw()
{
	SDL_RenderCopy(objectRenderer, objectSprite->GetTexture(), &objectSprite->GetSourceRectangle(), &objectSprite->GetDestinationRectangle());
}

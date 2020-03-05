#include "Sprite.h"

Sprite::Sprite()
{
}

Sprite::Sprite(SDL_Renderer* renderer, const char* filename, int sizeX, int sizeY)
{
	g_pSpriteTex = IMG_LoadTexture(renderer, filename);

	SDL_QueryTexture(g_pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;

	dst.x = 0;
	dst.y = 0;
	dst.w = sizeX;
	dst.h = sizeY;
}

Sprite::~Sprite()
{
}

void Sprite::cleanup()
{
	SDL_DestroyTexture(g_pSpriteTex);
}

void Sprite::setPosition(int x, int y)
{
	dst.x = x;
	dst.y = y;
}

void Sprite::setSize(int x, int y)
{
	dst.w = x;
	dst.h = y;
}

void Sprite::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, g_pSpriteTex, &src, &dst);
}

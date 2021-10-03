#include "Texture.h"
Texture::Texture()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Texture::~Texture()
{
	free();
}

void Texture::free()
{
	if (mTexture != NULL)
	{
		mHeight = 0;
		mWidth = 0;
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
	}
}

bool Texture::loadFromFile(string name)
{
	free();
	SDL_Surface* loadImg = IMG_Load(name.c_str());
	if (loadImg == NULL)
	{
		cout << "cant load img: " << IMG_GetError();
		return false;
	}
	SDL_SetColorKey(loadImg, SDL_TRUE, SDL_MapRGB(loadImg->format, 0, 255, 255));
	mTexture = SDL_CreateTextureFromSurface(globVar.Render, loadImg);
	if (mTexture == NULL)
	{
		cout << "cant create texture from loaded img: " <<name<< SDL_GetError();
		return false;
	}
	mWidth = loadImg->w;
	mHeight = loadImg->h;
	SDL_FreeSurface(loadImg);
	return true;
}

void Texture::render(int x, int y, SDL_Rect* rect)
{
	SDL_Rect renderQuad{ x, y, mWidth, mHeight };
	if (rect != NULL)
	{
		renderQuad.w = rect->w;
		renderQuad.h = rect->h;
	}
	SDL_RenderCopy(globVar.Render, mTexture, rect,&renderQuad);
}

int Texture::getWigth()
{
	return mWidth;
}

int Texture::getHeight()
{
	return mHeight;
}
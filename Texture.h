#pragma once
#include "GlobalVar.h"
#include<SDL_image.h>
#include<string>
#include <iostream>
using namespace std;
class Texture
{
public:
	GlobVar globVar;
	Texture();
	~Texture();
	void free();
	bool loadFromFile(string name);
	void render(int x, int y, SDL_Rect* rect = NULL);
	int getWigth();
	int getHeight();
private:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
};
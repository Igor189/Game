#pragma once
#include<SDL.h>
struct GlobVar
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	SDL_Renderer* Render;
	SDL_Window* Window;
};
struct Pos
{
	int posX, posY;
	bool operator==(Pos &pos2)
	{
		return(posX == pos2.posX && posY == pos2.posY);
	}
};
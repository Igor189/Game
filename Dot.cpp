#include"Dot.h"
void Dot::render()
{
	dotTexture.render(pos.posX,pos.posY);
}
Dot::Dot(int x, int y)
{
	pos.posX = x;
	pos.posY = y;
	velX = 0;
	velY = 0;
}
void Dot::handleEvent(SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP: velY -= VEL; break;
		case SDLK_DOWN: velY += VEL; break;
		case SDLK_RIGHT: velX += VEL; break;
		case SDLK_LEFT: velX -= VEL; break;
		}
	}
	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:velY += VEL; break;
		case SDLK_DOWN: velY -= VEL; break;
		case SDLK_RIGHT: velX -= VEL; break;
		case SDLK_LEFT: velX += VEL; break;
		}
	}
}
void Dot::move()
{
	pos.posX += velX;
	if (pos.posX<0 || pos.posX + DOT_WIDTH>dotTexture.globVar.SCREEN_WIDTH)
	{
		pos.posX -= velX;
	}
	pos.posY += velY;
	if (pos.posY<0 || pos.posY + DOT_HEIGHT>dotTexture.globVar.SCREEN_HEIGHT)
	{
		pos.posY -= velY;
	}
}

Pos Dot::getPos()
{
	return pos;
}

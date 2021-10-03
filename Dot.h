#pragma once
#include"Texture.h"
class Dot
{
private:
	Pos pos;
	int velX, velY;
public:
	Texture dotTexture;
	static const int VEL = 1;
	static const int DOT_HEIGHT = 20;
	static const int DOT_WIDTH = 20;
	void render();
	Dot(int x, int y);
	void handleEvent(SDL_Event& e);
	void move();
	Pos getPos();
};

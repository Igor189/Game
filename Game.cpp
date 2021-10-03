#include"Dot.h"
using namespace std;
Dot dot(0, 0);
bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cerr << "cant init SDL: " << SDL_GetError();
		success = false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			cerr << "Warning: Linear texture filtering not enabled!";
		}
		dot.dotTexture.globVar.Window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, dot.dotTexture.globVar.SCREEN_WIDTH, dot.dotTexture.globVar.SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
		if (dot.dotTexture.globVar.Window == NULL)
		{
			cerr << "Window could not be crated: " << SDL_GetError();
			success = false;
		}
		else
		{
			dot.dotTexture.globVar.Render = SDL_CreateRenderer(dot.dotTexture.globVar.Window, -1, SDL_RENDERER_PRESENTVSYNC);
			if (dot.dotTexture.globVar.Render == NULL)
			{
				cerr << "Render could not be created: " << SDL_GetError();
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(dot.dotTexture.globVar.Render, 255, 255, 255, 255);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}
bool loadMedia()
{
	bool success = true;
	if (!dot.dotTexture.loadFromFile("C:/sdl/28_per-pixel_collision_detection/28_per-pixel_collision_detection/dot.bmp"))
	{
		success = false;
	}
	return success;
}
void close()
{
	SDL_DestroyRenderer(dot.dotTexture.globVar.Render);
	SDL_DestroyWindow(dot.dotTexture.globVar.Window);
	dot.dotTexture.globVar.Window = NULL;
	dot.dotTexture.globVar.Render = NULL;
	IMG_Quit();
	SDL_Quit();
}
int main(int argc, char* args[])
{
	if (!init())
	{
		cerr << "Cannot init libraries";
	}
	else if (!loadMedia())
	{
		cerr << "Cannot load media";
	}
	else
	{
		Pos isExit{ 620,460 };
		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
				}
				dot.handleEvent(e);
			}
			dot.move();
			SDL_SetRenderDrawColor(dot.dotTexture.globVar.Render, 255, 255, 255, 255);
			SDL_RenderClear(dot.dotTexture.globVar.Render);
			SDL_SetRenderDrawColor(dot.dotTexture.globVar.Render, 0, 0, 255, 255);
			SDL_RenderDrawLine(dot.dotTexture.globVar.Render, 0, 20, 200, 20);
			SDL_RenderDrawLine(dot.dotTexture.globVar.Render, 200, 20, 200, 400);
			dot.render();
			SDL_RenderPresent(dot.dotTexture.globVar.Render);
			if (dot.getPos() == isExit)
			{
				cout << "end";
				quit = true;
			}
		}
	}
	close();
	return 0;
}
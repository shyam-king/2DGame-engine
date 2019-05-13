#include<SDL.h>
#include<SDL_image.h>
#include<Sprite.h>
#include<iostream>

#define FPS 30

void onQuit();

int main(int argc, char *argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = NULL;
	window = SDL_CreateWindow("Shyam",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	640, 480,
	SDL_WINDOW_MOUSE_FOCUS);

	uint32_t ticks, timeElapsed;

	if (!window)
		std::cerr << "OOPS: " << SDL_GetError();

	SDL_Event event;
	bool gameRunning = true;

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 255, 0 ,0 ,0);
	//SDL_RenderClear(renderer);

	Sprite A(renderer, "image.png", 2);
	SDL_Rect dest;


	dest.x = dest.y = 0;
	dest.w = dest.h = 64;
	

	uint8_t f = 0;

	while (gameRunning == true){
		ticks = SDL_GetTicks();
		//event-handling
		if (SDL_PollEvent(&event))
			switch(event.type) {
				case SDL_QUIT:
					onQuit();
					gameRunning = false;
					break;
		}

		//game
		SDL_RenderFillRect(renderer, NULL);
		A.drawFrame(f, &dest);
		f = 1 - f;

		timeElapsed = SDL_GetTicks() - ticks;
		if (timeElapsed  < 1000/FPS) 
			SDL_Delay(1000/FPS - timeElapsed);
		SDL_RenderPresent(renderer);
		timeElapsed = SDL_GetTicks() - ticks;
		std::cout << "FPS: " << 1000/timeElapsed << "\n";
	}

	SDL_Quit();
	return 0;
}

void onQuit() {
	std::cout << "quiting.\n";
}
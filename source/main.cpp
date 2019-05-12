#include<SDL.h>
#include<SDL_image.h>
#include<Sprite.h>
#include<iostream>

void onQuit();

int main(int argc, char *argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = NULL;
	window = SDL_CreateWindow("Shyam",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	640, 480,
	SDL_WINDOW_MOUSE_FOCUS);

	if (!window)
		std::cerr << "OOPS: " << SDL_GetError();

	SDL_Event event;
	bool gameRunning = true;

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED);
	SDL_Rect rect;
	rect.x = rect.y = 0;
	rect.h = 100;
	rect.w = 100;

	SDL_SetRenderDrawColor(renderer, 255,0,0,0);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);

	SDL_Surface *img = IMG_Load("image.png");
	SDL_Texture *image = SDL_CreateTextureFromSurface(renderer, img);
	SDL_FreeSurface(img);

	SDL_RenderCopy(renderer, image, NULL, &rect);
	SDL_RenderPresent(renderer);

	Sprite A(10);
	A.print();

	while (gameRunning == true){
		//event-handling
		if (SDL_PollEvent(&event))
			switch(event.type) {
				case SDL_QUIT:
					onQuit();
					gameRunning = false;
					break;
			}
	}

	SDL_Quit();
	return 0;
}

void onQuit() {
	std::cout << "quiting.\n";
}

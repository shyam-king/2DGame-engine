#include<SDL.h>
#include<iostream>

void onQuit();

int main(int argc, char *argv[]){
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *window = NULL;
	window = SDL_CreateWindow("Shyam", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_MOUSE_FOCUS);

	if (!window)
		std::cerr << "OOPS: " << SDL_GetError();

	SDL_Event event;
	bool gameRunning = true;

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
	std::cout << "quitiing.\n";
}

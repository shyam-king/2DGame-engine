#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<vector>

#include "Sprite.h"

using namespace std;

Sprite::Sprite(SDL_Renderer *Renderer, const char* ImageStrip, uint8_t n){
  SDL_Surface *sur = IMG_Load(ImageStrip);
  nFrames = n;
  renderer = Renderer;
  int w = sur->w / nFrames;
  int h = sur->h;
  for (int i = 0; i < nFrames; i++){
    SDL_Surface *f = SDL_CreateRGBSurface(0, w, h, 
    sur->format->BitsPerPixel, 
    sur->format->Rmask, 
    sur->format->Gmask,
    sur->format->Bmask, 
    sur->format->Amask);

    SDL_Rect src;
    src.x = w * i;
    src.y = 0;
    src.w = w;
    src.h = h;
    SDL_BlitSurface(sur, &src, f, NULL);
    frames.push_back(SDL_CreateTextureFromSurface(renderer, f));
    SDL_FreeSurface(f);
  }
  frames.push_back(SDL_CreateTextureFromSurface(renderer, sur));
  SDL_FreeSurface(sur);
}

Sprite::Sprite(SDL_Renderer* Renderer, const char *files[], uint8_t n){
  nFrames = n;
  renderer = Renderer;
  for (int i = 0; i < n; i++){
    SDL_Surface *sur = IMG_Load(files[i]);
    frames.push_back(SDL_CreateTextureFromSurface(renderer, sur));
    SDL_FreeSurface(sur);
  }
}

Sprite::~Sprite(){

}

void Sprite::drawFrame(uint8_t f, SDL_Rect *dest){
  SDL_RenderCopy(renderer, frames.at(f), NULL, dest);
}

#ifndef SPRITE_H
#define SPRITE_H

#include<vector>

class Sprite {
private:
  std::vector<SDL_Texture*> frames;
  uint8_t nFrames;
  SDL_Renderer *renderer;
public:
  Sprite(SDL_Renderer*, const char *, uint8_t);
  Sprite(SDL_Renderer*, const char *files[], uint8_t);
  void drawFrame(uint8_t, SDL_Rect *);
  ~Sprite();
};

#endif

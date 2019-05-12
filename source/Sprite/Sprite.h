#ifndef SPRITE_H
#define SPRITE_H

class Sprite {
private:
  SDL_Texture *frames;
  uint8_t nFrames;
  int a;
public:
  Sprite(int x);
  void print();
};

#endif

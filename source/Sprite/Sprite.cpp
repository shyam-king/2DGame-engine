#include<SDL.h>
#include<SDL_image.h>
#include<iostream>

#include "Sprite.h"

using namespace std;

Sprite::Sprite(int x){
  a = x;
}

void Sprite::print(){
  cout << a << endl;
}

cmake_minimum_required(VERSION 2.8)
project(2DGameEngine)

add_library(Sprite Sprite.cpp)
target_include_directories(Sprite PUBLIC "/usr/include/SDL2")
target_link_libraries(Sprite LINK_PUBLIC "SDL2" "SDL2_image")

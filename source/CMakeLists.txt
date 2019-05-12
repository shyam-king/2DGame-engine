cmake_minimum_required(VERSION 2.8)
project(2DGameEngine)

add_subdirectory("Sprite")

add_executable(main main.cpp)
target_include_directories(main PUBLIC "/usr/include/SDL2" "Sprite")
target_link_libraries(main LINK_PUBLIC "SDL2" "SDL2_image" Sprite)

cmake_minimum_required(VERSION 2.8)
project(2DGameEngine)

add_executable(main main.cpp)
target_include_directories(main PUBLIC "/usr/include/SDL2")
target_link_libraries(main LINK_PUBLIC "SDL2")

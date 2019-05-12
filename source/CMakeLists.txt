cmake_minimum_required(VERSION 2.8)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CPP_COMPILER g++)

project(2DGameEngine)

add_executable(main main.cpp)
target_include_directories(main PUBLIC "/usr/include/SDL2")
target_link_libraries(main LINK_PUBLIC "SDL2" "SDL2_image")

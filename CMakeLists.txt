cmake_minimum_required(VERSION 3.21)
project(project2 C)

set(CMAKE_C_STANDARD 11)
link_libraries(SDL2  SDL2_image SDL2_ttf m)
add_executable(project2 main.c
        resource.c resource.h
        main-function.c main-function.h
        global.h
        event.c event.h)

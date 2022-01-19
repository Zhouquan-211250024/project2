
#include <SDL2/SDL.h>
#include "event.h"
void event(){
    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return;
            }
        }
    }
}
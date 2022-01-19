#include "main-function.h"
#include "global.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>

SDL_Window *win;
SDL_Texture *back_tex;
SDL_Renderer *ren;
SDL_Surface *back;
SDL_Texture *my_tex;
SDL_Surface *my;

void CreatePlayWindow(){
    if (SDL_Init(SDL_INIT_VIDEO)) {//init a window , if there's no problem, it's return is 0
        SDL_Log("Can not init video ,%s", SDL_GetError());//SDL_Log is printf ,GetError get the wrong information
        return ;
    }
    // found a simple window
    win = SDL_CreateWindow(
            "Hello World",// title
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, //position
            Width, Height, // width and height
            SDL_WINDOW_SHOWN); // a flag?
    if (win == NULL) {
        SDL_Log("can not create a window, %s", SDL_GetError());
        return ;
    }
    ren = SDL_CreateRenderer(win,-1,SDL_RENDERER_SOFTWARE);
    if (ren == NULL){
        SDL_Log("Can not create a renderer");
        return ;
    }
    back = SDL_LoadBMP(background);
    back_tex = SDL_CreateTextureFromSurface(ren,back);
    SDL_SetRenderDrawColor(ren,0,0,0,255);
    SDL_RenderClear(ren);

    //SDL_QueryTexture(back_tex,NULL,NULL,&w,&h);
    SDL_Rect src = {0,0,600,900};
    SDL_RenderCopy(ren,back_tex,NULL,&src);
    SDL_RenderPresent(ren);
}
void Destroy(){
    SDL_DestroyRenderer(ren);
    SDL_DestroyTexture(back_tex);
    SDL_FreeSurface(back);
}
void CreateMyPlane(){
    my = IMG_Load(mypp);
    my_tex = SDL_CreateTextureFromSurface(ren,my);
    int w, h;
    SDL_QueryTexture(my_tex,NULL,NULL,&w,&h);
    SDL_RenderSetScale(ren,0.25,0.25);
    SDL_Rect src = {900,3200,w,h};
    SDL_RenderCopyEx(ren,my_tex,NULL,&src,0,NULL,SDL_FLIP_VERTICAL);
    SDL_RenderPresent(ren);
}
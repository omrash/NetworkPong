#include <stdio.h>
#include <stdlib.h>

#include "SDL.h"

#include "netpong.h"

int main(int argc, char* argv[]) {

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not be initialized: %s", SDL_GetError());
        exit(1);
    }

    SDL_Window* window;

    window = SDL_CreateWindow("SDL2Test", 0, 0, 640, 480, SDL_WINDOW_SHOWN);

    SDL_Event e;
    int run = 1;
    while (run) {
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                run = 0;
            }
            if (e.type == SDL_KEYDOWN){
                run = 0;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                run = 0;
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;

}

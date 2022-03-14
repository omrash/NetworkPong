#include <stdio.h>
#include <stdlib.h>

#include "SDL.h"

#include "netpong.h"

#define SCREEN_WIDTH 640 //default screen width
#define SCREEN_HEIGHT 480 //default screen height

void game_init(game_state_t* game_state) {

    ball_t game_ball;
    paddle_t l_paddle;
    paddle_t r_paddle;

    game_ball.x = SCREEN_WIDTH / 2;
    game_ball.y = SCREEN_HEIGHT / 2;
    game_ball.width = game_ball.height = 10;
    game_ball.d_x = game_ball.d_y = 0;

    l_paddle.x = 20;
    l_paddle.y = SCREEN_HEIGHT / 2;
    l_paddle.width = 20;
    l_paddle.height = 100;

    r_paddle.x = SCREEN_WIDTH - 20;
    r_paddle.y = SCREEN_HEIGHT / 2;
    r_paddle.width = 20;
    r_paddle.height = 100;

    game_state->score[0] = game_state->score[1] = 0;
    game_state->game_ball = game_ball;
    game_state->l_paddle = l_paddle;
    game_state->r_paddle = r_paddle;

}

int main(int argc, char* argv[]) {

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL initialization failed: %s", SDL_GetError());
        exit(1);
    }

    game_state_t game_state;
    game_init(&game_state);

    printf("L_Paddle position is %d, %d", game_state.l_paddle.x, game_state.l_paddle.y);
    printf("R_Paddle position is %d, %d", game_state.r_paddle.x, game_state.r_paddle.y);

    SDL_Window* window;

    window = SDL_CreateWindow("NET PONG", 
        0, 
        0, 
        SCREEN_WIDTH, 
        SCREEN_HEIGHT, 
        SDL_WINDOW_SHOWN);

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "SDL.h"

#include "netpong.h"

#define SCREEN_WIDTH 640 //default screen width
#define SCREEN_HEIGHT 480 //default screen height
#define TIMESTEP 15 //timestep in ms used to calculate tickrate
#define BUFF_SIZE 200
#define PORT_NO 2300

void refresh_screen(game_state_t* game_state) {

}

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

    // Check if args are valid
    if (argc < 2) {
        printf("No arguments supplied, please check documentation on how to start\n");
        exit(1);
    }
    int port_no = PORT_NO;
    if (argc > 2) {
        port_no = atoi(argv[2]);
        if (port_no > 65535 || port_no < 1023) {
            printf("Invalid port number argument supplied\n");
            exit(1);
        }
    }

    // Initiate SDL, print error message and exit if init fails
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("SDL initialization failed: %s\n", SDL_GetError());
        exit(1);
    }

    // Set default game state in game_state struct
    game_state_t game_state;
    game_state.is_host = 0;
    game_init(&game_state);

    // Game window
    SDL_Window* window;
    window = SDL_CreateWindow("NET PONG", 
        0, 
        0, 
        SCREEN_WIDTH, 
        SCREEN_HEIGHT, 
        SDL_WINDOW_SHOWN);

    // Getting address information for later use
    int sockfd;
    struct sockaddr_in host_addr;
    char buffer[BUFF_SIZE];
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        printf("Socket creation failed\n");
        exit(1);
    }

    // Determining host/client and establishing connection
    if (strcmp(argv[1], "HOST") == 0) {
        game_state.is_host = 1;
        stuct sockaddr_in client_addr;
    }
    else {
    
    }
    
    // Event loop
    SDL_Event e;
    int step = TIMESTEP;
    int run = 1;
    while (run) {
        int start = SDL_GetTicks();
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
        int elapsed = SDL_GetTicks() - start;
        if (elapsed < step) {
            SDL_Delay(step - elapsed);
        }
    }

    // Destroy window and quit SDL
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

}

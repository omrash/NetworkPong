typedef struct ball {
    int x, y;
    int width, height;
    int d_x, d_y; 
} ball_t;

typedef struct paddle {
    int x,y;
    int width, height;
} paddle_t;

typedef struct game_state {
    int score[2];
    ball_t game_ball;
    paddle_t l_paddle;
    paddle_t r_paddle;
    int is_host;
    int client_connected;
} game_state_t;

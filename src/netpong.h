typedef struct ball {
    int x, y;
    int width, height;
    int d_x, d_y; 
} ball_t;

typedef struct paddle {
    int x,y;
    int w,h;
} paddle_t;

typedef struct game_state {
    int score[2];
    ball_t* game_ball;
    paddle_t* l_paddle, r_paddle;
} game_state_t;

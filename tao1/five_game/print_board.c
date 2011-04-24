#include <stdio.h>
#include "main.h"
#include <string.h>
extern char chess_board[B_X*B_Y];
extern fbscr_t fb_v;
extern u32_t current_color;
extern char current_player;
int  print_board(void)
{

    int i = 0;
    int j = 0;
//board de print    
    memset((u32_t *)fb_v.memo,0,fb_v.w*fb_v.h*fb_v.bpp/8);
    memset(chess_board,0,B_X*B_Y);
    current_player = 1;
    current_color = BLACK;
    for (j = 10; j <ST_Y+(SPACE*B_Y) ; j++) 
    {
        for (i = 20; i < ST_X+(SPACE*B_X); i++) 
        {
            fb_one_pixel(i,j,YELLOW);
        }
    }
//line de print
    for (i = 0; i < B_Y; i++) 
    {
        fb_line(ST_X,ST_Y+i*SPACE,ST_X+(B_X-1)*SPACE,ST_Y+i*SPACE,BLACK);
    }
    for (i = 0; i < B_X; i++) 
    {
        fb_line(ST_X+i*SPACE,ST_Y,ST_X+i*SPACE,ST_Y+(B_Y-1)*SPACE,BLACK);
    }


     fb_circle(60,100,20,BLACK);
     fb_circle(60,500,20,WHITE);
    return 0;

}

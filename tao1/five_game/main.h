#ifndef  _MAIN_H_
#define _MAIN_H_

#define  ST_X  100
#define  ST_Y  40
#define  B_X   29
#define  B_Y   24
#define  SPACE 30

#define  YELLOW 0x00eebb00
#define  BLACK  0x00
#define  WHITE  0x00ffffff

#define  VORD  0x0000ffff
#define  V___  0x000000ff
#define  A___  0x00ff0000
/*#define  T___  0x00eebb00*/
#define T___ 0x00ff0000
#define  BORD  0x0f
/*#define  X___  0xff00f00f*/
#define X___ 0xff0000ff
#define  C_W   10
#define  C_H   17
#define  C_A   12
#define  C_B   56

typedef unsigned int u32_t;
typedef unsigned char u8_t;

typedef struct
{
    int w;
    int h;
    int bpp;

    void *memo;

} fbscr_t;

typedef struct
{
    int dx;
    int dy;
    int dz;
    char button;

} mouse_event;

int init_screen(void);
int fb_one_pixel(int x, int y , u32_t color);
int fb_line(int x1,int y1,int x2,int y2,u32_t color);
void swap(int *a,int *b);
int fb_circle(int x0,int y0,int r,u32_t color);
int print_board(void);
int draw_cursor(int x,int y);
int save_bg(int x,int y);
int restore(int x,int y);
int mouse_doing(void);
int chess_do(void);
int check_win(void);
int chess_do(void);
int draw_winner(int x, int y);
int check_one(int x, int y);
#endif

#ifndef  _MAIN_H_
#define  _MAIN_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fb.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#define C_WIDTH  13
#define C_HEIGHT 17
#define D_X	 100
#define D_Y	 50
#define T___     0XFFFFFFFF
#define BORD     0x0
#define X___     0xFFFF

#define x_start_l	100	/*开始X左*/
#define x_start_r	200	/*开始X右*/
#define y_start_l	150	/*开始Y左*/
#define y_start_r	200	/*开始Y右*/

#define x_list_l	100	/*列表X左*/
#define x_list_r	200	/*列表X右*/
#define y_list_l	300	/*列表Y左*/
#define y_list_r	350	/*列表Y右*/

#define x_quit_l	100	/*退出X左*/
#define x_quit_r	200	/*退出X右*/
#define y_quit_l	450	/*退出Y左*/
#define y_quit_r	500	/*退出Y右*/

#if 1

static unsigned long cursor_pixel[C_WIDTH * C_HEIGHT] = {
    	BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    	BORD,BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    	BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    	BORD,X___,X___,BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    	BORD,X___,BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___,T___,
    	BORD,X___,BORD,BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___,
    	BORD,X___,BORD,T___,BORD,X___,BORD,T___,T___,T___,T___,T___,T___,
    	BORD,X___,BORD,T___,T___,BORD,X___,BORD,T___,T___,T___,T___,T___,
    	BORD,X___,BORD,T___,T___,T___,BORD,X___,BORD,T___,T___,T___,T___,
    	BORD,X___,BORD,T___,T___,T___,T___,BORD,X___,BORD,T___,T___,T___,
    	BORD,X___,BORD,T___,T___,BORD,BORD,BORD,BORD,X___,BORD,T___,T___,
    	BORD,X___,BORD,T___,BORD,X___,X___,X___,X___,X___,X___,BORD,T___,
    	BORD,X___,BORD,BORD,X___,BORD,BORD,BORD,BORD,BORD,BORD,BORD,BORD,
    	BORD,X___,BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___,T___,
    	BORD,X___,X___,BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    	BORD,X___,BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,
    	BORD,BORD,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___,T___
};

#endif

static unsigned long mouse_save_cursor[C_WIDTH * C_HEIGHT];
static unsigned long pic_save_cursor[D_X * D_Y];

typedef unsigned int u32_t;
typedef unsigned short u16_t;
typedef unsigned char u8_t;
#if 1
typedef struct
{
	int fd;
    struct fb_var_screeninfo fb_var;
	void * fb_mem;
	int w;
	int h;
	int bpp;
}fb_info_t, *pfb_info_t;

#endif

typedef struct
{
	int dx;
	int dy;
	int dz;
	int button;
}mevent_t;
		            

extern void fb_pixel(pfb_info_t pfb, int x, int y, u32_t color);
extern void put_s(pfb_info_t pfb, u32_t color);
extern void put_l(pfb_info_t pfb, u32_t color);
extern void put_q(pfb_info_t pfb, u32_t color);
extern void put1(pfb_info_t pfb, u32_t color);
extern void put2(pfb_info_t pfb, u32_t color);
extern void put3(pfb_info_t pfb, u32_t color);
extern void mouse_save(pfb_info_t pfb, int x, int y);
extern void mouse_restore(pfb_info_t pfb, int x, int y);
extern int pic_save(pfb_info_t pfb, int x, int y);
extern void pic_restore(pfb_info_t pfb, int x, int y);
extern void mouse_draw(pfb_info_t pfb, int x, int y);
extern int mouse_parse(int fd, mevent_t *pmevent);
extern int mouse_doing();

#endif

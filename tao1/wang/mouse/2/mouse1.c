#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fb.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
//#include "main.h"

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

static unsigned long mouse_save_cursor[C_WIDTH * C_HEIGHT];
static unsigned long pic_save_cursor[D_X * D_Y];

typedef unsigned int u32_t;
typedef unsigned short u16_t;
typedef unsigned char u8_t;
typedef struct
{
	int fd;
	struct fb_var_screeninfo fb_var;
	void * fb_mem;
	int w;
	int h;
	int bpp;
}fb_info_t, *pfb_info_t;

typedef struct
{
	int dx;
	int dy;
	int dz;
	int button;
}mevent_t;
		;            
void fb_pixel(pfb_info_t pfb, int x, int y, u32_t color)
{
	u32_t *p = (u32_t *)pfb->fb_mem + x + y*pfb->w;
	*p = color;

	return ;
}

void put_s(pfb_info_t pfb, u32_t color)
{
	int i, j;
	for(i = x_start_l; i < x_start_r; i++)
	{
		for(j = y_start_l; j < y_start_r; j++)
		{
			fb_pixel(pfb, i, j, color);
		}
	}
}
void put_l(pfb_info_t pfb, u32_t color)
{
	int i, j;
	for(i = x_list_l; i < x_list_r; i++)
	{
		for(j = y_list_l; j < y_list_r; j++)
		{
			fb_pixel(pfb, i, j, color);
		}
	}
}
void put_q(pfb_info_t pfb, u32_t color)
{
	int i, j;
	for(i = x_quit_l; i < x_quit_r; i++)
	{
		for(j = y_quit_l; j < y_quit_r; j++)
		{
			fb_pixel(pfb, i, j, color);
		}
	}
}
void put1(pfb_info_t pfb, u32_t color)
{
	int i, j;
	for(i = x_start_l; i < x_start_r; i = i + 3)
	{
		for(j = y_start_l; j < y_start_r; j = j + 3)
		{
			fb_pixel(pfb, i, j, color);
		}
	}
}

void put2(pfb_info_t pfb, u32_t color)
{
	int i, j;
	for(i = x_list_l; i < x_list_r; i = i + 3)
	{
		for(j = y_list_l; j < y_list_r; j = j + 3)
		{
			fb_pixel(pfb, i, j, color);
		}
	}
}

void put3(pfb_info_t pfb, u32_t color)
{
	int i, j;
	for(i = x_quit_l; i < x_quit_r; i = i + 3)
	{
		for(j = y_quit_l; j < y_quit_r; j = j + 3)
		{
			fb_pixel(pfb, i, j, color);
		}
	}
}

void mouse_save(pfb_info_t pfb, int x, int y)
{
	int i, j;
	
	for(j = 0; j < C_HEIGHT; j++)
		for(i = 0; i < C_WIDTH; i++)
			mouse_save_cursor[i+j*C_WIDTH] = 
		*((u32_t *)pfb->fb_mem + (x+i) +(y+j)*pfb->w);
	return;
}

void mouse_restore(pfb_info_t pfb, int x, int y)
{
	int i, j;
	
	for(j = 0; j < C_HEIGHT; j++)
		for(i = 0; i < C_WIDTH; i++)
			fb_pixel(pfb, x+i, y+j, mouse_save_cursor[i+j*C_WIDTH]); 
	return;
}

int pic_save(pfb_info_t pfb, int x, int y)
{
	int i, j;
	
	for(j = 0; j < D_Y; j++)
		for(i = 0; i < D_X; i++)
			pic_save_cursor[i+j*D_X] = 
		*((u32_t *)pfb->fb_mem + (x+i) +(y+j)*pfb->w);
	return 1;
}

void pic_restore(pfb_info_t pfb, int x, int y)
{
	int i, j;
	
	for(j = 0; j < D_Y; j++)
		for(i = 0; i < D_X; i++)
			fb_pixel(pfb, x+i, y+j, pic_save_cursor[i+j*D_X]); 
	return;
}


void mouse_draw(pfb_info_t pfb, int x, int y)
{
	int i, j;

	for(i = 0;i < C_WIDTH; i++)
		for(j = 0;j < C_HEIGHT; j++)
		{
			if(cursor_pixel[i+j*C_WIDTH] != T___)
			{
				fb_pixel(pfb, x+i, y+j, cursor_pixel[i+j*C_WIDTH]);
			}
		}
}

int mouse_parse(int fd, mevent_t *pmevent)
{
	int n;
	char buf[8];

	if((n = read(fd, buf, 8)) > 0)
	{
		pmevent->button = buf[0] & 0x07;
		pmevent->dx = buf[1];
		pmevent->dy = -buf[2];
		pmevent->dz = buf[3];
	}
	else
		return -1;

	return 0;
}
int main()
{
	fb_info_t fb;
	mevent_t mevent;
	
	int fd, mfd;

	int m_x, m_y;

	int s = 0;
	int l = 0;
	int q = 0;

	if((fd = open("/dev/fb0", O_RDWR)) < 0)
	{
		perror("open /dev/fb0 error:");
		exit(1);
	}
	if(-1 == ioctl(fd, FBIOGET_VSCREENINFO, &(fb.fb_var)))
	{
		printf("ioctl FBIOGET_VSCREENINFO\n");
		exit(1);
	}
	fb.w = fb.fb_var.xres;
	fb.h = fb.fb_var.yres;
	fb.bpp = fb.fb_var.bits_per_pixel;
	fb.fd = fd;
	fb.fb_mem = mmap(NULL, fb.w*fb.h*fb.bpp/8, PROT_READ|PROT_WRITE, MAP_SHARED, fb.fd,0);
	if(MAP_FAILED == fb.fb_mem)
	{
		printf("mmap error!");
		exit(1);
	}

	m_x = fb.w / 2;
	m_y = fb.h / 2;
	put_s(&fb, 0XFF);
	put_l(&fb, 0XFF);
	put_q(&fb, 0XFF);
	//Step 1	
	mouse_save(&fb, m_x, m_y);
	//Step 2
	mouse_draw(&fb, m_x, m_y);

	mfd = open("/dev/input/mice", O_RDWR | O_NONBLOCK);
	if(mfd < 0)
	{
		perror("open /dev/input/mice error:");
		exit(1);
	}


	while(1)
	{
		if(mouse_parse(mfd, &mevent) == 0)
		{
			//Step 3
			mouse_restore(&fb, m_x, m_y);

			m_x += mevent.dx;
			m_y += mevent.dy;
			
			if(m_x < 0)
				m_x = 0;
			if(m_x > (fb.w-C_WIDTH-1))
				m_x = fb.w - C_WIDTH-1;
			if(m_y < 0)
				m_y = 0;
			if(m_y > (fb.h-C_HEIGHT-1))
				m_y = fb.h-C_HEIGHT-1;
			if((m_x > x_start_l)&&(m_x < x_start_r)&&(m_y > y_start_l)&&(m_y < y_start_r))
			{
				if(s == 0)
					s = pic_save(&fb, x_start_l, y_start_l);
				put1(&fb,0xFFFFFFFF);
				if(mevent.button == 1)
				{
				/*开始*/
				printf("star\n");
			//	exit(1);
				}
			}
			else if((m_x > x_list_l)&&(m_x < x_list_r)&&(m_y > y_list_l)&&(m_y < y_list_r))
			{
				if(l == 0)
					l = pic_save(&fb, x_list_l, y_list_l);

				put2(&fb,0xFFFFFFFF);
				if(mevent.button == 1)
				{
				/*列表*/
				printf("list\n");
			//	exit(1);
				}	
			}
			else if((m_x > x_quit_l)&&(m_x < x_quit_r)&&(m_y > y_quit_l)&&(m_y < y_quit_r))
			{
				if(q == 0)
					q = pic_save(&fb, x_quit_l, y_quit_l);

				put3(&fb,0xFFFFFFFF);
				if(mevent.button == 1)
				{
				/*退出*/
				printf("exit\n");
			//	exit(1);
				}
			}
			else
			{
	
				if(s == 1)
					pic_restore(&fb, x_start_l, y_start_l);
				if(l == 1)
					pic_restore(&fb, x_list_l, y_list_l);
				if(q == 1)
					pic_restore(&fb, x_quit_l, y_quit_l);
            }				

			mouse_save(&fb, m_x, m_y);	
			mouse_draw(&fb, m_x, m_y);
			
		}
	}
	close(fb.fd);
	munmap(fb.fb_mem,fb.w*fb.h*fb.bpp/8);
	return 0;	

}	


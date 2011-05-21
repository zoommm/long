#ifndef _MAIN_H_
#define _MAIN_H_
#include <linux/fb.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
typedef struct fbdev
{
    int fb;
    char dev[20];
    int w;
    int h;
    int bpp;
    struct fb_var_screeninfo fb_var;
    unsigned long fb_mem;
    int len;
}FBDEV,*PFBDEV;

void fb_print(char *p);
int fb_open(PFBDEV pFbdev);
void fb_close(PFBDEV pFbdev);
void fb_drawpixel(PFBDEV pFbdev,int x, int y,u32_t color);

#endif 

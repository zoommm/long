#include <stdio.h>
#include <linux/fb.h>
#include <sys/types.h>
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
    void * fb_mem;
    int fb_len;
}FBDEV,*PFBDEV;
#define TURE 1
#define FALSE 0

typedef unsigned char u8_t;
typedef unsigned short int u16_t;
typedef unsigned long int u32_t;
/*
void fb_print(char *p)
{
    int i,j;
    for (i = 0; i < 10; i++) 
    {
        for (j = 0; j < 10; j++) 
        {
            fb_pixel(info,i,j);
        }
    }
}
*/

int fb_open(PFBDEV pFbdev)
{
    
    pFbdev->fb = open(pFbdev->dev,O_RDWR);
    if (pFbdev->fb < 0) 
    {
        perror("open /dev/fb0/ error");
        return FALSE;
    }
    if (-1L == ioctl(pFbdev->fb,FBIOGET_VSCREENINFO,&(pFbdev->fb_var))) 
    {
        perror("ioctl pfbdev->fb");
        return FALSE;
    }
    pFbdev->w = fb_var.w;
    pFbdev->h = fb_var.h;
    pFbdev->bpp = fb_var.bites_per_pixel;
    pFbdev->fb_len = pFbdev->w*pFbdev->h*pFbdev->bpp/8;
    pFbdev->fb_mem =(unsigned long int)mmap(NULL,pFbdev->fb_len,PROT_WRITE | PROT_READ,MAP_SHARED,pFbdev->fb,0);
    if (pFbdev->fb_mem == MAP_FAILED) 
    {
        perror("mmap error");
        return FALSE;
    }

    return TURE;
}
void fb_close(PFBDEV pFbdev)
{
    close(pFbdev->fb);
    pFbdev->fb = -1;
}
void fb_drawpixel(PFBDEV pFbdev,int x, int y,u32_t color)
{
    int i;
    u32_t *p = (u32_t)pFbdev->fb_mem;
    i = x + y*pFbdev->fb_var.xres;
    p[i] = color;
    return ;
}

int main(int argc, const char *argv[])
{
    FBDEV fbdev;
    memset(&fbdev,0,sizeof(FBDEV));
    strcpy(fbdev.dev,"/dev/fb0");
    if(fb_open(fbdev) == FALSE)
    {
        printf("open fail\n");
        return FAlSE;
    }
    fb_drawpixel(&fbdev,300,500,0x00ff00);
    fb_close(&fbdev);
    munmap(pFbdev->fb_mem,pFbdev->fb_len);
    return 0;
}

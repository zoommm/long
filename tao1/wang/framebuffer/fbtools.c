#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/user.h>
#include "fbtools.h"
#define TRUE 1
#define FALSE 0 
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
typedef unsigned short int u16_t;
typedef unsigned long int u32_t;
int fb_open(PFBDEV pFbdev)
{
    pFbdev->fb = open(pFbdev->dev,O_RDWR);
    if (pFbdev->fb < 0) 
    {
        printf("Error opening %s:%m.Check kernel config\n",pFbdev->dev);
        return FALSE;
    }
    if (-1 == ioctl(pFbdev->fb,FBIOGET_VSCREENINFO,&(pFbdev->fb_var))) 
    {
        printf("ioctl FBIOGET_VSCREENINFO\n");
        return FALSE;
    }
    if (-1 == ioctl(pFbdev->fb,FBIOGET_FSCREENINFO,&(pFbdev->fb_fix))) 
    {
        printf("ioctl FBIOGET_FSCREENINFO\n");
        return FALSE;
    }
    pFbdev->fb_mem = (unsigned long)(pFbdev->fb_fix.smem_start) &(~PAGE_MASK);
    pFbdev->fb_mem = (unsigned long int)mmap(NULL,pFbdev->fb_fix.smem_len+pFbdev->fb_mem_offset, PROT_READ|PROT_WRITE,MAP_SHARED,pFbdev->fb,0);
    if (-1L == (long)pFbdev->fb_mem) 
    {
        printf("mmap error ! mem :%lx  offset:%lx\n", pFbdev->fb_mem,pFbdev->fb_mem_offset);
        return FALSE;
    }
    return TRUE;
}
int fb_close(PFBDEV pFbdev)
{
    close(pFbdev->fb);
    pFbdev->fb = -1;
}
int get_display_depth(PFBDEV pFbdev)
{
    if (pFbdev->fb <= 0) 
    {
        printf("fb device not open,open it first\n");
        return FALSE;
    }
    return pFbdev->fb_var.bits_per_pixel;
}
void fb_memset(void *addr,int c,size_t len)
{
    memset(addr,c,len);
}

void fb_drawpixel(PFBDEV pFbdev,int x,int y,u32_t color  )
{
    int i;
    u32_t *p = (u32_t *)pFbdev->fb_mem;
    //转换x，y坐标对应得p数组得下标。 
    i = x + y*pFbdev->fb_var.xres;
    p[i] = color;
    return;
}
void fb_drawline(PFBDEV pFbdev,int x,int y,u32_t color)
{
    int i;
    int j;
    for (i = 0; i < pFbdev->fb_var.yres; i++) 
    {
        fb_drawpixel(pFbdev,x,i,color);
    }

    for (i = 0; i < pFbdev->fb_var.xres; i++) 
    {
        fb_drawpixel(pFbdev,i,y,color);
    }

    for (i = y; i < pFbdev->fb_var.yres-y; i++) 
    {
        for (j = x; j < pFbdev->fb_var.xres-x; j++) 
        {
            if (i%10==9) 
            {
               fb_drawpixel(pFbdev,j,i,0x00ff0000);
            }
           else if (j%10==9) 
            {
                fb_drawpixel(pFbdev,j,i,0x00ff0000);
            }

            else 
            {
                fb_drawpixel(pFbdev,j,i,color);
            }
        }
    }


}
            
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int fb_line(PFBDEV pFbdev,int x1,int y1,int x2,int y2,u32_t color)
{
    int p = 0;
    int dx = x2-x1;
    int dy = y2-y1;
    int inc = ((dx*dy<0)?-1:1);
    if (abs(dx)>abs(dy)) 
    {
      if (dx < 0) 
      {   
       swap(&x1,&x2);
       swap(&y1,&y2);
       dx = -dx;
       dy = -dy;
      }
      dy =abs(dy); 
      p = 2*dy-dx;
 
      while(x1 <= x2)
       {
        fb_drawpixel(pFbdev,x1,y1,color);
        x1++;
        if (p<0) 
        {
            p += 2*dy;
        }
        if (p>=0) 
        {
            y1 += inc;
            p += 2*(dy-dx);
        }
      }
    }
    else
    {
      if (dy < 0) 
      {   
       swap(&x1,&x2);
       swap(&y1,&y2);
       dx = -dx;
       dy = -dy;
      }
      dx =abs(dx); 
      p = 2*dx-dy;
 
      while(y1 <= y2)
       {
        fb_drawpixel(pFbdev,x1,y1,color);
        y1++;
        if (p<0) 
        {
            p += 2*dx;
        }
        if (p>=0) 
        {
            x1 += inc;
            p += 2*(dx-dy);
        }
      }
        
    
    }
    return 0;

}
int fb_circle(PFBDEV pFbdev,int x0,int y0,int r,u32_t color)
{
    int x = 0;
    int y = r;
    int p = 3-2*r;
    
    while(x <= y)
    {
       
        //fb_line(pFbdev,x0+x,y0+y,x0-x,y0+y,color);
        //fb_line(pFbdev,x0+y,y0+x,x0-y,y0+x,color);
        //fb_line(pFbdev,x0+x,y0-y,x0-x,y0-y,color);
        //fb_line(pFbdev,x0+y,y0-x,x0-y,y0-x,color);
        
        fb_drawpixel(pFbdev,x0+x,y0+y,color);
        fb_drawpixel(pFbdev,x0-y,y0+x,color);
        fb_drawpixel(pFbdev,x0+x,y0-y,color);
        fb_drawpixel(pFbdev,x0-y,y0-x,color);
        fb_drawpixel(pFbdev,x0-x,y0+y,color);
        fb_drawpixel(pFbdev,x0+y,y0+x,color);
        fb_drawpixel(pFbdev,x0-x,y0-y,color);
        fb_drawpixel(pFbdev,x0+y,y0-x,color);
  
        if (p<0) 
        {
            p += 4*x+6;
        }
        else
        {
            y--;
            p += 4*(x-y)+10;
        }
        x++;
    }

    return 0;
}
void fb_draw_currle(PFBDEV pFbdev,int x,int y,int r,u32_t color)
{
    


}
#define DEBUG
#ifdef  DEBUG

void main(void)
{
    FBDEV fbdev;
    memset(&fbdev,0,sizeof(FBDEV));
    strcpy(fbdev.dev,"/dev/fb0");
    if (fb_open(&fbdev) == FALSE) 
    {
        printf("open frame buffer error\n");
        return ;
    }
    fb_memset((void *)(fbdev.fb_mem + fbdev.fb_mem_offset),0,fbdev.fb_fix.smem_len);
    //画点得函数：
    fb_drawpixel(&fbdev,512,384,0x00ff0000);
    fb_drawpixel(&fbdev,513,384,0x00ff0000);
    fb_drawpixel(&fbdev,512,385,0x00ff0000);
    fb_drawpixel(&fbdev,513,385,0x00ff0000);
    //画直线得函数：
    //fb_drawline(&fbdev,200,100,0x0000ff00);
    fb_line(&fbdev,100,200,300,500,0x000000ff);
    fb_circle(&fbdev,512,348,50,0x00ff0000);
    fb_close(&fbdev);
    getchar();
}

#endif

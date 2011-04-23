#include <stdio.h>
#include "main.h"
#include <stdlib.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int fb_line(int x1,int y1,int x2,int y2,u32_t color)
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
        fb_one_pixel(x1,y1,color);
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
        fb_one_pixel(x1,y1,color);
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
int fb_circle(int x0,int y0,int r,u32_t color)
{
    int x = 0;
    int y = r;
    int p = 3-2*r;
    
    while(x <= y)
    {
        //fb_one_pixel(x0+x,y0+y,color);
        //fb_one_pixel(x0+y,y0+x,color);
        fb_line(x0+x,y0+y,x0-x,y0+y,color);
        fb_line(x0+y,y0+x,x0-y,y0+x,color);
        fb_line(x0+x,y0-y,x0-x,y0-y,color);
        fb_line(x0+y,y0-x,x0-y,y0-x,color);
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


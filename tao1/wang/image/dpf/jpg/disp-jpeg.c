
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "common.h"

#define DEBUG 0
#if DEBUG
#endif

int display_jpeg(char *filename, fb_info fb_inf)
{

	fb_info original_jpeg;	  /* original size */
	fb_info new_jpeg;

	new_jpeg = fb_inf; 		  /* screen size */
	
	u8_t *buf24 = decode_jpeg(filename, &original_jpeg);
	u8_t * scale_buf = scale24(buf24, new_jpeg, original_jpeg);
	u32_t *buf32 = rgb24to32(scale_buf, new_jpeg);
//////////////up to down//////////
/*
	int i, j;
	for(i = 0; i < new_jpeg.h; ++i){
		for (j = 0; j < new_jpeg.w; ++j){
			fb_pixel(fb_inf, j, i, buf32[j + i * new_jpeg.w]);
		}
       usleep(10000);
	}
*/
////////////left to right///////
/*
    int i,j;
    for (i = 0; i < new_jpeg.w; i++) 
    {
        for (j = 0; j < new_jpeg.h; j++) 
        {
            fb_pixel(fb_inf,i,j,buf32[i+j*new_jpeg.w]);
        }
        usleep(10000);
    }
*/
////////////leftup to rightdown/////////
/*
    int i,j;
    for (i = 0; i < new_jpeg.h; i+=1) 
    {
        for (j = 0; j < new_jpeg.w; j+=5) 
        {
            fb_pixel(fb_inf,j,i,buf32[j+i*new_jpeg.w]);
        }
        usleep(100);
        for (j = 1; j < new_jpeg.w; j+=5) 
        {
            fb_pixel(fb_inf,j,i,buf32[j+i*new_jpeg.w]);
        }
        usleep(1000);
    }

    for (i = 1; i < new_jpeg.h; i+=1) 
    {
        for (j = 1; j < new_jpeg.w; j+=1) 
        {
            fb_pixel(fb_inf,j,i,buf32[j+i*new_jpeg.w]);
        }
        usleep(1000);
    }
*///////////////////////////////////////////////
/*    
    int i,j;
   for (i = 0; i < new_jpeg.w/2; i++) 
    {
        for (j = 0; j < new_jpeg.h/2; j++) 
        {
            fb_pixel(fb_inf,i,j,buf32[i+j*new_jpeg.w]);
        }
        usleep(1000);
    }
    for (i = 0; i < new_jpeg.w/2; i++) 
    {
        for (j = new_jpeg.h/2; j < new_jpeg.h; j++) 
        {
            fb_pixel(fb_inf,i,j,buf32[i+j*new_jpeg.w]);
        }
        usleep(1000);
    }
    for (i = new_jpeg.w/2; i < new_jpeg.w; i++) 
    {
    
        for (j = 0; j < new_jpeg.h/2; j++) 
        {
            fb_pixel(fb_inf,i,j,buf32[i+j*new_jpeg.w]);
        }
        usleep(1000);
    }
    for (i = new_jpeg.w/2; i < new_jpeg.w; i++) 
    {
        for (j = new_jpeg.h/2; j < new_jpeg.h; j++) 
        {
            fb_pixel(fb_inf,i,j,buf32[i+j*new_jpeg.w]);
        }
        usleep(1000);
        
    }
*//////////////////four quai///////////
      
    
/////////////////////////////////////
	free(buf24);
	free(scale_buf);
	free(buf32);
	
	return 0;
}

#include <stdio.h>
#include "main.h"
int main(int argc, const char *argv[])
{
    init_screen();
    //fb_line(100,200,100,400,0x000000ff);        
    //fb_line(100,200,300,400,0x000000ff);        
    //fb_line(200,300,200,500,0x0000ffff);        
    //fb_line(200,300,400,500,0x0000ffff);        
    //fb_line(300,400,500,600,0x0000ff00);        
    //fb_line(300,400,300,600,0x0000ff00);        
    //fb_line(400,500,400,700,0x00ffffff);        
    //fb_line(400,500,600,700,0x00ffffff);        
    fb_circle(100,200,13,0x00ffffff);         
    fb_circle(200,300,13,0x0000ff00);         
    fb_circle(300,400,13,0x0000ffff);         
    fb_circle(400,500,13,0x00ff0000);         
    fb_circle(500,600,13,0x00ffff00);         
    print_board();    
        
 //fb_one_pixel(i,j,0x0000ff00);
    return 0;

}

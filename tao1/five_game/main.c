#include <stdio.h>
#include "main.h"
int main(int argc, const char *argv[])
{
    init_screen();
    int i=0;
    int j=0;
    for (i = 0; i < 100; i++) 
    {
        for (j = 0; j < 100; j++) 
        {
            
         
             fb_one_pixel(i,j,0x0000ff00);
        
        }
    }    
    return 0;

}

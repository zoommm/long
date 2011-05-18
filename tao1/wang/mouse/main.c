#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"
/*
#define C_WIDTH 10
#define C_HEIGHT 17
#define T___ 0xFFFFFFFF
#define BORD 0x0
#define X___ 0xFFFF

static u32_t cursor_pixel[C_WIDTH*C_HEIGHT]={
    BORD,BORD,BORD,BORD,BORD,BORD,BORD,BORD,BORD,BORD,
    BORD,T___,T___,T___,T___,T___,T___,T___,T___,BORD,
    BORD,T___,T___,T___,T___,T___,T___,T___,T___,BORD,
    BORD,T___,T___,T___,T___,T___,T___,T___,T___,BORD,
    X___,BORD,T___,T___,T___,T___,T___,T___,BORD,X___,
    X___,X___,BORD,T___,T___,T___,T___,BORD,X___,X___,
    X___,X___,X___,BORD,T___,T___,BORD,X___,X___,X___,
    X___,X___,X___,BORD,T___,T___,BORD,X___,X___,X___,
    X___,X___,X___,BORD,T___,T___,BORD,X___,X___,X___,
    X___,X___,X___,BORD,T___,T___,BORD,X___,X___,X___,
    X___,X___,BORD,T___,T___,T___,T___,BORD,X___,X___,
    X___,BORD,T___,T___,T___,T___,T___,T___,BORD,X___,
    BORD,T___,T___,T___,T___,T___,T___,T___,T___,BORD,
    BORD,T___,T___,T___,T___,T___,T___,T___,T___,BORD,
    BORD,T___,T___,T___,T___,T___,T___,T___,T___,BORD,
    BORD,T___,T___,T___,T___,T___,T___,T___,T___,BORD,
    BORD,BORD,BORD,BORD,BORD,BORD,BORD,BORD,BORD,BORD,
};
*/
static u32_t save_cursor[C_WIDTH*C_HEIGHT];
int mouse_test(pinfo_t fb)                                              //fb->bpp.and fb->x and fb->y
{
    int fd;
    if ((fd = mouse_open("/dev/input/mice"))<0) 
    {
        fprintf(stderr,"Error mouse open :%s\n",strerror(errno));
        exit(1);
    }
    mevent_t mevent;
    int m_x = fb->w/2;
    int m_y = fb->h/2;
    mouse_draw(fb,m_x,m_y);
    u8_t buf[]=={0xF3,0xC8,0xF3,0x64,0xF3,0x50};
    if (write(fd,buf,sizeof(buf)) < sizeof(buf)) 
    {
        fprintf(stderr,"Error write to mice devie:%s\n",strerror(errno));
        fprintf(stderr,"鼠标将不支持滚轮\n");            
    }
    while(1)
    {
        if (mouse_parse(fd,&mevent)==0)                                   // mouse parse jie xi mouse action .. 
        {
            printf("dx=%d\tdy=%d\tdz=%d\t",mevent.dx,mevent.dy,mevent.dz);
            mouse_restore(fb,m_x,m_y);                                   //restore function...huifu
            m_x +=mevent.dx;
            m_y +=mevent.dy;
            mouse_draw(fb,m_x,m_y);                                      //chonghua mouse....
            printf("mx=%d\tmy=%d\n",m_x,m_y);
            switch(mevent.button)
            {
                case 1:
                        printf("left button\n");
                        break;
                case 2:
                        printf("right button\n");
                        break;
                case 4:
                        printf("middle button\n");
                        break;
                case 0:
                        printf("no button\n");
                        break;
                default:
                        break;
            }
        }
        else
            ;                                                            //error read mouse..
    }
    close(fd);
    return 0;
}

int mouse_open(const char *mdev)
{
    if (mdev == NULL) 
    {
        mdev = "/dev/input/mice";
    }
    return (open(mdev,O_RDWR|O_NONBLOCK));
}
#define READ_MOUSE 8
int mouse_parse(int fd,mevent_t *mevent)
{
    s8_t buf[READ_MOUSE];
    int n;
    if ((n=read(fd,buf,READ_MOUSE)) > 0) 
    {
        mevent->button = buf[0]&0x07;
        mevent->dx = buf[1];
        mevent->dy = -buf[2];
        mevent->dz = buf[3];
    }
    else
        return -1;
    return 0;
}

static int mouse_save(const pinfo_t fb,int x,int y)
{
    int i,j;
    for (j = 0; j < C_HEIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            save_cursor[i+j*C_WIDTH]=*(u32_t)(fb->fb_mem+((x+i)+(y+j)*fb->w)*fb->bpp/8);
        }
    }
    return 0;
}

int mouse_draw(const pinfo_t fb,int x,int y)
{
    int i,j;
    mouse_save(fb,x,y);                                     //save mouse draw before do..
    for (j = 0; j < C_HEIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            if (cursor_pixel[i+j*C_WIDTH]!=T___)
            {
                fb_pixel(fb,x+i,y+i,&cursor_pixel[i+j*C_WIDTH]);
            }
        }
    }
    return 0;
}
int  mouse_restore(const pinfo_t fb,int x,int y)
{
    int i,j;
    for (j = 0; j < C_HEIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            fb_pixel(fb,x+i,y+j,&save_cursor[i+j*C_WIDTH]);
        }
    }
    return 0;
}
int main(int argc, const char *argv[])
{
    printf("1\n");
    mouse_open();
    printf("2\n");
    mouse_test();
    printf("3\n");
    return 0;
}

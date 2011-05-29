#include "mouse.h"
#include <stdlib.h>

static u32_t save_cursor[C_WIDTH*C_HEIGHT];

int mouse_test(pinfo_t fb)
{
    int fd;
    if ((fd = mouse_open("/dev/input/mice"))<0) 
    {
        fprintf(stderr,"Error mouse open:%s\n",strerror(errno));
        exit(1);
    }
    mevent_t mevent;
    int m_x = fb->w/2;
    int m_y = fb->h/2;
    mouse_draw(fb,m_x,m_y);
    u8_t buf[]={0xF3,0xC8,0xF3,0x064,0xF3,0x50};
    if (write(fd,buf,sizeof(buf))<sizeof(buf))
    {
        fprintf(stderr,"Error write to mice devie:%s\n",strerror(errno));
        fprintf(stderr,"bu zhi chi ");
    }
    //fb_line(&fb,400,300,600,300,0x00ffff00);
    //fb_line(&fb,400,300,400,600,0x00ffff00);
    //fb_line(&fb,400,600,600,600,0x00ffff00);
    //fb_line(&fb,600,300,600,600,0x00ffff00);
    while(1)
    {
        mevent.button = 0;
        if (mouse_parse(fd,&mevent)==0) 
        {
            //printf("dx=%d\tdy=%d\tdz=%d\t",mevent.dx,mevent.dy,mevent.dz);
        
        mouse_restore(fb,m_x,m_y);
        m_x +=mevent.dx;
        m_y +=mevent.dy;
        mouse_draw(fb,m_x,m_y);
        printf("mx=%d\tmy=%d\n",m_x,m_y);
        switch(mevent.button)
        {
            case 1:
                    //printf("left button\n");
                    if (m_x < 450 && m_x > 400) 
                    {
                        if (m_y < 350 && m_y > 300) 
                        {
                            exit(1);
                        }
                    }

                    break;
            case 2:
                    //printf("right button\n");
                    break;
            case 4:
                    //printf("middle button\n");
                    break;
            case 0:
                    //printf("no button\n");
                    break;
            default:
                    break;
        }
        }
        else
            ;
    }
    close(fd);
    return 0;
}
int fb_init(pinfo_t fb)
{
    int fd;
    if ((fd = open("/dev/fb0",O_RDWR))<0) 
    {
        perror("open /dev/fb0:");
        exit(1);
    }
    if(-1== ioctl(fd,FBIOGET_VSCREENINFO,&(fb->fb_var)))
    {
        perror("ioctl error");
        exit(1);
    }
    fb->fd = fd;
    fb->w = fb->fb_var.xres;
    fb->h = fb->fb_var.yres;
    fb->bpp = fb->fb_var.bits_per_pixel;
    fb->fb_mem = mmap(NULL,(fb->w)*(fb->h)*(fb->bpp)/8,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
    if (fb->fb_mem == MAP_FAILED) 
    {
        perror("mmap error: ");
        return -1;
    }
   return 0;
}


void fb_drawpixel(pinfo_t fb,int x,int y,u32_t color)
{
    int i;
    u32_t *p = (u32_t *)fb->fb_mem;
    //转换x，y坐标对应得p数组得下标。 
    i = x + y*fb->fb_var.xres;
    p[i] = color;
    return;
}
void fb_close(pinfo_t fb)
{
    close(fb->fd);
    munmap(fb->fb_mem,(fb->w)*(fb->h)*(fb->bpp)/8);
    return;
}
int mouse_open(const char *mdev)
{
    if (mdev == NULL) 
    {
        mdev = "/dev/input/mice";
    }
    return (open(mdev,O_RDWR | O_NONBLOCK));
}
int mouse_parse(int fd,mevent_t *mevent)
{
    s8_t buf[READ_MOUSE];
    int n;
    if ((n = read(fd,buf,READ_MOUSE)) > 0) 
    {
/* 1:left key *2:right key
 * 4:middle key *0 no button key
 */
        mevent->button = buf[0] & 0x07;
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
            save_cursor[i+j*C_WIDTH] = *(u32_t *)(fb->fb_mem + ((x+i) + (y+j)*fb->w)*fb->bpp/8);
        }
    }
    return 0;
}
int mouse_draw(const pinfo_t fb,int x, int y)
{
    int i,j;
    mouse_save(fb,x,y);
    for (j = 0; j < C_HEIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            if (cursor_pixel[i+j*C_WIDTH]!=T___) 
            {
                fb_drawpixel(fb,x+i,y+j,cursor_pixel[i+j*C_WIDTH]);
            }
        }
    }
    return 0;
}
int mouse_restore(const pinfo_t fb,int x, int y)
{
    int i,j;
    for (j = 0; j < C_HEIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            fb_drawpixel(fb,x+i,y+j,save_cursor[i+j*C_WIDTH]);
        }
    }
    return 0;
}
void swap(int *p,int *q)
{
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
    
}
int fb_line(const pinfo_t fb,int x1, int y1,int x2,int y2,u32_t color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p;
    int inc;
    inc = ((dx*dy)>=0)?1:-1;
    if (abs(dx)>abs(dy)) 
    {
        if (dx < 0) 
        {
            swap(&x1,&x2);
            dx = -dx;
            dy = -dy;
        }
        dy = (dy>0)?dy:-dy;
        p = 2*dy-dx;
        while(x1++ <= x2)
        {
            fb_drawpixel(fb,x1-1,y1,color);
            if (p < 0) 
            {
                p += 2*dy;
            }
            else
            {
                y1 += inc;
                p += 2*(dy - dx);

            }
        }
    }
    else
    {
        if (dy < 0) 
        {
            swap(&x1,&x2);
            dx = -dx;
            dy = -dy;
        }
        dx = (dx >0)? dx:-dx;
        p = 2*dx-dy;
        while(y1++<y2)
        {
            fb_drawpixel(fb,x1,y1-1,color);
            if (p < 0) 
            {
                p += 2*dx;
            }
            else
            {
                x1 += inc;
                p +=2 * (dx-dy);
            }
        }
    }
    return 0;
}
int main(int argc, const char *argv[])
{
    info_t fb;
    fb_init(&fb);
    fb_line(&fb,400,300,450,300,0x00ffff00);
    fb_line(&fb,400,300,400,350,0x00ffff00);
    fb_line(&fb,400,350,450,350,0x00ffff00);
    fb_line(&fb,450,300,450,350,0x00ffff00);

    mouse_test(&fb); 
    //fb_drawpixel(&fb,300,500,0x00ff00);
    //fb_drawpixel(&fb,301,500,0x0000ff);
    //fb_drawpixel(&fb,302,500,0x00ff00);
    //fb_drawpixel(&fb,303,500,0x0000ff);
    //fb_drawpixel(&fb,304,500,0x00ff00);
    //fb_drawpixel(&fb,305,500,0x0000ff);

    fb_close(&fb);
    return 0;
}

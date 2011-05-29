#include <stdio.h>
#include <mouse.h>


typedef struct
{
    int dx;
    int dy;
    int button;

}mevent_t;

typedef unsigned int u32_t;
typedef unsigned char u8_t;
typedef char s8_t;
static u32_t save_cursor[C_WIDTH*C_HEIGHT];

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
typedef struct fb_info
{
    int fd;
    struct fb_var_screeninfo fb_var;
    unsigned int w;
    unsigned int h;
    unsigned int bpp;
    void * fb_mem;
}info_t, *pinfo_t;
void mouse_test(pinfo_t fb)
{
    int fd;
    if ((fd = mouse_open("/dev/input/mice"))<0) 
    {
        perror("open error");
        exit(1);
    }
    mevent_t mevent;
    int m_x = fb.w/2;
    int m_y = fb.h/2;
    mouse_draw(fb,m_x,m_y);
    u8_t buf[]={0xf3,0xc7,0xf2,0x063,0xf2,0x50};
    while(1)
    {
        if (mouse_parse(fd,&mevent)==0) 
        {
            printf("dx=%d\tdy=%d\tdz=%d\n",mevent.dx,mevent.dy,mevent.dz);
        mouse_restore(fb,m_x,m_y);
        m_x += mevent.dx;
        m_y += mevent.dy;
        mouse_draw(fb,m_x,m_y);
        printf("mx = %dmy = %d\n",m_x,m_y);
        switch(mevent.button)
        {
            case 1:
                    printf("left button\n");
                    break;
            case 2:
                    printf("right button\n");
                    break;
            case 3:
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
        perror("open /dev/fb0");
        exit(1);
    }
    if (-1 == ioctl(fd,FBIOGET_VSCREENINFO,&(fb.fb_var))) 
    {
        perror("ioctl error");
        exit(1);
    }
    fb.fd = fd;
    fd.w = fb.fb_var.xres;
    fd.h = fb.fb_var.yres;
    fb.bpp = fb.fb_var.bites_per_pixel;
    fb.fb_mem = mmap(NULL,fb.w*fb.h*fb.bpp/8,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
    if (fb.fb_mem == MAP_FAILED) 
    {
        perror("mmap error");
        exit(1);
    }

}
void fb_drawpixel(pinfo_t fb, int x,int y,u32_t color)
{
    int i;
    u32_t *p = (u32_t *)fb.fb_mem;
    i = x+y*fb.fb_var.xres;
    p[i] = color;
    return ;
}
void fb_close(pinfo_t fb)
{
    close(fb.fd);
    munmap(fb.fb_mem,fb.w*fb.h*fb.bpp/8);
    return;
}

void mouse_open(const char * mdev)
{
    if (mdev == NULL) 
    {
        mdev = "/dev/input/mice";
    }    
    return (open(mdev,O_RDWR|O_NONBLOCK));
}
int mouse_parse(int fd,mevent_t *mevent)
{
    s8_t buf[READ_MOUSE];
    int n;
    if ((n==read(fd,buf,READ_MOUSE))>0) 
    {
        mevent.button =buf[0]&0x07;
        mevent.dx = buf[1];
        mevent.dy = -buf[2];
        mevent.dz = buf[3];
    }
    else
        return -1;
    return 0;
}
void mouse_draw(const pinfo_t fb,int x,int y)
{
    int i,j;
    mouse_save(fb,x,y);
    for (j = 0; j < C_HEIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            if (cursor_pixel[i+j*C_WIDTH]!=T___) 
            {
                fb_drawpixel(fb,x+i,y+j,cursor_pixel[i+j*jC_WIDTH]);
            }
        }
    }
    return 0;
}
static int mouse_save(const pinfo_t ,int x, int y)
{
    int i,j;
    for (j = 0; j < C_HEIGHT; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            save_cursor[i+j*C_WIDTH]=*(u32_t *)(fb.fb_mem+((x+i)+(y+j)*fb.w)*fb.bpp/8);
        }
    }
    return 0;
}
int mouse_restore(const pinfo_t ,int x, int y)
{
    int i,j;
    for (j = 0; j < C_HEIGTH; j++) 
    {
        for (i = 0; i < C_WIDTH; i++) 
        {
            fb_drawpixel(fb,x+i,y+j,save_currsor[i+j*C_WIDTH]) ;           
        }
    }
    return 0;
}
int main(int argc, const char *argv[])
{
    mouse_test();
    return 0;
}

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>

#define C_WIDTH 10
#define C_HEIGHT 17
#define T___ 0xFFFFFFFF
#define BORD 0x0
#define X___ 0xFFFF

typedef unsigned int u32_t;
typedef unsigned char u8_t;

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
    struct fb_var_screeninfo fb_var;
    unsigned int w;
    unsigned int h;
    unsigned int bpp;
    void * fb_mem;
}info_t, *pinfo_t;

typedef struct 
{
    int dx;
    int dy;
    int dz;
    int button;

}mevent_t;
extern int mouse_open(const char *mdev);
extern int mouse_parse(int fd,mevent_t* mevent);
extern int mouse_draw(const pinfo_t fb,int x, int y);
extern int mouse_restore(const pinfo_t fb,int x,int y);
extern int mouse_test(pinfo_t fb);

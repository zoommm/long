#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

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

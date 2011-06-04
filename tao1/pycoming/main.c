#include <stdio.h>

struct point
{
    int x;
    int y;
    struct point *p;
}Point;
int main(int argc, const char *argv[])
{
    Point pt;
    pt.x = 5;
    pt.y = 9;
    pt.point->p = NULL;
    return 0;
}

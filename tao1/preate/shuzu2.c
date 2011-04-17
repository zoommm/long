#include <stdio.h>

int main(int argc, const char *argv[])
{
    int array[4][5];
    int *p =array[0];
    int (*s)[];
    int **ptr;
    int *x[10];
    ptr=x;
    s=array;

    return 0;
}

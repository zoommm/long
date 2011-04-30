#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a;
    short b;
    int c;
    long d;
    char e[10];
    int f[2];
    char name[5][10];
    long long g ;
    int h[10]={1,2,3};
    int *q=h;
    printf("%x ",(unsigned int )q);
    q++;
    printf("%x ",(unsigned int )q);


    printf("char a%d\n",sizeof(a));
    printf("short b%d\n",sizeof(b));
    printf("int c%d\n",sizeof(c));
    printf("char e[10]%d\n",sizeof(e));
    printf("name[5][10] a%d\n",sizeof(name));

    printf("long d %d\n",sizeof(d));
    printf("long long%d\n",sizeof(g));
    return 0;
}

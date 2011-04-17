#include <stdio.h>

int main(int argc, const char *argv[])
{
    char *a;
    int b,c;
    printf("%d\n",sizeof a);
    printf("%d\n",sizeof *a);
    b=1;
    c=1;
    printf("%d\n",sizeof(++b));
    printf("%d\n",sizeof(int));
    printf("%u\n",0xFFFFFFFF);
    printf("%u\n",-1);
    printf("%d\n",-1);

    return 0;
}

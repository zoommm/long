#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a[4096];

    printf("%d\n",sizeof(0x30));
    a[4096]='0x30';
    printf("%s\n",a);
    return 0;
}

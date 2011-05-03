#include <stdio.h>
int a,b = 1;

int main(int argc, const char *argv[])
{
    push('e');
    push('f');
    push('d');

    while(!is_empty())
    {
        putchar(pop());
    }
    printf("\n");

    return 0;
}

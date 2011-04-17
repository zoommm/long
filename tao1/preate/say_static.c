#include <stdio.h>
#define N 10
int main(int argc, const char *argv[])
{
    int array[N];
    init_static(array,N);
    say_static(array,N);
    return 0;
}
void init_static(int *p ,int n)
{
    for (i = 0; i < N; i++) 
    {
         scanf("%c",&p[i]);
         
    }
}
void say_static(int *p ,int n)
{   
    int i=0;

    while()
    {

        if (p[i]=' ') 
        {
            printf("%c\n"p[i]);
        }
    }
    printf("\n");
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 30
int print_a(int *p);
int  init_a(int *p) ;
void sort_a(int *p);
int main(int argc, const char *argv[])
{   
    int a[N];
    init_a(a);
    printf("priginal:\n");
    print_a(a);

    sort_a(a);
    printf("sort:\n");
    print_a(a);
    return 0;
}
int print_a(int *p)
{   
    int i=0;
    for (i = 0; i < N; i++) 
    {
        if (p[i]>0) 
        {
        printf("%5d",p[i]);
        }
    }
      printf("\n");
}
int  init_a(int *p) 
{
    int i=0;
    srand(time(NULL));
    for (i = 0; i < N; i++) 
    {
       p[i]=(rand()%20);       
    }
}
void sort_a(int *p)
{
    int i=0;
    int j=0;
    for (i = 0; i < N-1; i++) 
    {
        if (p[i]>0) 
        {
            for (j = i+1; j < N; j++) 
            {
                if (p[j]==p[i]) 
                {
                    p[j]=-1;
                }
            }
        }
    }
}

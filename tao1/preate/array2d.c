#include <stdio.h>
#define M 10
#define N 10
int main(int argc, const char *argv[])
{
    int array[M][N];
    int i=0;
    int j=0;
    
    for (i = 0; i < M; i++) 
    {
        for (j = 0; j < N; j++) 
        {
            array[j][i]=j*M+i+1;
        }
    }
    for (j = 0; j < N; j++) 
    {
        for (i = 0; i < M; i++) 
        {
            printf("%5d ",array[j][i]);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#define M  5
#define N  5
int main(int argc, const char *argv[])
{
    int array[M][N]={{1,34,2,82,76},
                     {2,3,23,63,62},
                     {22,86,4,78,43},
                     {56,5,32,96,6},
                     {100,6,67,8,9}};
    int temp;
    int i=0;
    int j=0;
    int **tem;
    int k=0;
    int y=0;
    printf("before array the number:\n");
    for (i = 0; i < M; i++) 
    {
        for (j = 0; j < N; j++) 
        {
            printf("%5d",array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("after array the number:\n");
    for (i = 0; i < M; i++) 
    {
        for (j = 0; j < N; j++) 
        {   
            y=i++;
            k=j++;
            if (array[i][j]>array[i][k]) 
            {
                tem=array[i][j];
                array[i][j]=array[i][k];
                array[i][k]=tem;

            }
            if (array[i][j]>array[y][j]) 
            {
                temp=array[i][j];
                array[i][j]=array[y][j];
                array[y][j]=temp;
            }
        }
    }
    for (i = 0; i < M; i++) 
    {
        for (j = 0; j < N; j++) 
        {
            printf("%5d",array[i][j]);
        }
        printf("\n");
    }
    return 0;
}

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define M   10  
#define N   10  
int quick_sort(int (*p) ,int x ,int y);

int main(int argc, const char *argv[])
{
    int i=0;
    int j=0;
    int temp;
    int array[M][N];
    srand(time(NULL));
    for (i = 0; i <( M*N-1); i++) 
    {
         array[0][i]=(rand()%(M*N));
    }
    for (i = 0; i < M; i++) 
    {
        for (j = 0; j < N; j++) 
        {
            printf("%5d",array[i][j]);
        }
        printf("\n");


    }
   quick_sort(array,0,N-1);
    return 0;

}
int quick_sort(int (*p) ,int x ,int y)
{
    int i=x;
    int j=y;
    int mid=p[0][(x+y)/2];
    int temp;


    while(i<=j)
    {
        while(p[0][i]<mid)i++;
        while(p[0][j]>mid)j--;
        if (i<=j)    
        {
           temp=p[0][i];
           p[0][i]=p[0][j];
           p[0][j]=temp;
           i++;
           j--;

        }
    }
    if (x<p[0][j]) 
    {
        quick_sort(p,x,j);
    }
    if (p[0][i]>y)   
    {
        quick_sort(p,i,y);
    }
}


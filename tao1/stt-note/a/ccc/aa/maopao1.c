#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i;
    int j;
    int k;
    int tem;
    int array[10]={4,7,1,2,3,-6,-9,0,55,31};
    for (i = 0; i < 10; i++) 
    {

        printf("%5d",array[i]);
    }
    printf("\n");
    for (i = 0; i < 9; i++) 
    {
        k=i;
        for (j = i+1; j < 10; j++) 
        {
            if (array[i]>array[j]) 
            {
                k=j;                
                 tem=array[i];
                array[i]=array[j];
                array[j]=tem;
            }

        }
    }
    for (i = 0; i < 10; i++) 
    {
        printf("%d\n",array[i]);
    }
    return 0;
}

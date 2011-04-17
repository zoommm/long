
#include <stdio.h>
#include<stdlib.h>
#define N  100
int init_array(int p[],int n);
int bublle_array(int p[],int n);
int print_array(int p[],int n);

int main(int argc, const char *argv[])
{
    int array[N];
    init_array(array,N);
    printf("original:\n");
    print_array(array,N);
    getchar();
    printf("sorted:\n");
    
    bubble_array(array,N);
    print_array(array,N);

    return 0;
}
int init_array(int p[],int n)
{
    int i=0;
    srand(time(NULL));
    for (i = 0; i < n; i++) 
    {
        p[i]=(rand()%200);
    }
}
int bubble_array(int p[],int n)
{
    int i=0;
    int j=0;
    int tem=0;
    for (i = 0; i < n-1; i++) 
    {
        for (j = i+1; j < n; j++) 
        {
           if (p[i]>p[j]) 
           {
               tem=p[i];
               p[i]=p[j];
               p[j]=tem;
           }
        }
    }

}
int  print_array(int p[],int n)
{
   int i=0;
   for (i = 0; i < n; i++) 
   {
       if ((i%10)==0) 
       {
        printf("\n");
       }
          printf("%5d",p[i]);
   }
   printf("\n");
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define M 8
int init_array(int *p)
{
    int i = 0;
    srand(time(NULL));
    for (i = 0; i < M; i++) 
    {
        p[i]=(rand()%100);
    }
    return 0;
}
int print_array(int *p)
{
    int i = 0;
    for (i = 0; i < M; i++) 
    {
        printf("%d%c",p[i],(i%5!=4)?'\t':'\n');
    }
    printf("\n");
    return 0;
}
int pai_array(int *p)
{
    int i = 0;
    int j = 0;
    int tem = 0;
    int tmp = 0;
    int count = 0; 
    int k = 0;
    int m = 0;
    int a = 0;
    int b = 0;
    for (i = 0,j = M; i < j; i++) 
    {
      if (p[i]%2==0) 
      {
            while(p[j]%2==0) 
            {
                    j--;   
            } 
            tem = p[i];
            p[i] = p[j];
            p[j] = tem;

       }      
       count++;
    }
    for (i = 0; i <= count; i++) 
    {
        if (p[i]<p[i+1]) 
        {
            tem = p[i];
            p[i] = p[i+1];
            p[i+1]= p[i];
        }
    }
    for (j = count; j < M; j++) 
    {
        if (p[j]>p[j+1]) 
        {
            tmp = p[j];
            p[j]=p[j+1];
            p[j+1]=tmp;
        }
    }
    printf("%d\n",count);
    return 0;
}
int pai_array2(int *p)
{
    
}
void insert_odd(int i)
{
    int k = 0;
    int tmp;
    while(arr[k]<arr[i])
        k++;
    tmp = arr[i];
    memmove(&arr[k+1],&arr[k],i-k);
    arr[k] = tmp;
}
void insert_even(int i)
{
    int j;
    int tmp;
    while(arr[j]>arr[i])
        j++;
    tmp = arr[i];
    memmove(&arr[i],&arr[i+1],j-i);
    arr[j] = tmp;
}
int main(int argc, const char *argv[])
{
    int a[M];
    int arr[M]
    init_array(a);
    init_array(arr);
    printf("pai lie qian :\n");
    print_array(a);
    printf("pai lie hou :\n");
    pai_array(a);
    print_array(a);
    printf("pai lie hou 2:\n");
    pai_array2(arr);
    print_array(arr);
    printf("\n");
    return 0;
}


#include <stdio.h>

int main(int argc, const char *argv[])
{
    int k=0;
    int j=0; 
    int i=0;
    int a[20]={1,2,5,3,4,6,9,11,10,8,7,13,19,18};
 
    for (i = 0; i < 20; i++) 
     {
       j=a[i];
       for (k = 0; k < 20; k++) 
        {
            if (j<a[k]) 
            {
               j=a[k];
            }
        }  
       
    }   
       printf("%d\n",j);
    

    return 0;
}

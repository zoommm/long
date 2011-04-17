#include <stdio.h>
#define M 10
int main(int argc, const char *argv[])
{
    int a[M];
    int i=0;
    int *p;
    int *pt;
    int j=0;
    p=a[M];
    pt=a[M];
    for (i = 0; i < M; i++) 
    {
        a[i]=i+1;
        printf("%5d",a[i]);
    }
    printf("\n");
    printf("yuesefuhuan:\n");
    getchar();
////////////////////////////////////////////////////////
//
//
//
//////////////////////////////////////////////////////
    for (i = 0; i <20 ; i++) 
    {   
       j=j+3;
        if (a[j]<a[M]) 
        {   
            if (a[j]=a[i]) 
            {
                j++;
                
            }
        
        printf("%d out ",a[j]);
        printf("\n");
        }
        else
        if (a[j]>a[M]) 
        {
          a[j]=a[j%10];
           if (a[j]=a[i]) 
           {
                i++;
               a[i];
           }
           printf("%d  out", a[i]);
        }
       
       }
    return 0;
}
////////////////////////////////////////
//     for (i = 0; i < M*M; i++) 
//
////          {
//          pt+3;
//          if (pt<a[M]) 
  //        {
 //           printf("%5   ",&pt);
//            
   //       }
//
     
 //    }










///////////////////////////////////////      
 


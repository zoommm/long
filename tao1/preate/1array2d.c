#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define M 10
#define N 10
int main(int argc, const char *argv[])
{
    int i=0;
    int j=0;
    int temp=0;
    int array[N][M];
////////init///////////////////////////////////////////    
    
    srand(time(NULL));
    for (i = 0; i < M*N; i++) 
    {
        array[0][i]=rand()%(M*N);
    }
////////////////////////////////////////////////////
////////////print//////////////////////////////////
   
    for (j = 0; j < N; j++) 
    {
        for (i = 0; i < M; i++) 
        {
            printf("%5d",array[j][i]);
        }
        printf("\n");
    }
    printf("\n");
 ////////////////////////////////////////////////
 ///////////sort//////////////////////////////
/*    
    for (i = 0; i < M; i++) 
    {
        for (j = i+1; j < N; j++) 
        {
            if (array[0][i]>array[0][j]) 
            {
                temp=array[0][i];
                array[0][i]=array[0][j];
                array[0][j]=temp;
            }
        }
    }
*/
//////////////////sort11111//////////////////////////////////////
      getchar();
       for (i = 0; i < (M*N-1); i++) 
       {
           for (j = i+1 ; j < M*N; j++) 
           {
               if (array[0][i]>array[0][j]) 
               {
                   temp=array[0][i];
                   array[0][i]=array[0][j];
                   array[0][j]=temp;

               }
           }
       }



////print////////////////////////////////////////////////////
   
  
    for (i = 0; i < M; i++) 
    {
        for (j = 0; j < N; j++) 
        {
            printf("%5d",array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
//////////////////////////////////   
    return 0;
}

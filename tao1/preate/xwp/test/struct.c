#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define M 50

struct WER_int
{
    int a;
    int num;
};
int sort_bit(int a[])
{
    int i = 0;
    int j = 0;
    int p = 0;
    struct WER_int b[M];
    struct WER_int tem;
    for (i = 0; i < M; i++) 
    {
        b[i].a = a[i];
    }
    for (i = 0; i < M; i++) 
    {
        for (j = 0; j < M; j++) 
        {
            if (a[i]&0x1) 
            {
                p++;
            }
            a[i]=a[i]>>1;
        }
        b[i].num=p;
        p = 0;
        
    }   
    printf("\n");
    for (i = 0; i < M; i++) 
    {
         for (j = i+1; j < M; j++) 
         {
             if (b[i].num>b[j].num) 
             {
                tem.num = b[j].num;
                tem.a = b[j].a;
                b[j].num = b[i].num;
                b[j].a = b[i].a;
                b[i].num = tem.num;
                b[i].a = tem.a;
             }
             if (b[i].num == b[j].num) 
             {
                if(b[i].a>b[j].a) 
                {  
                    tem.num = b[j].num;
                    tem.a = b[j].a;
                    b[j].num = b[i].num;
                    b[j].a = b[i].a;
                    b[i].num =tem.num;
                    b[i].a = tem.a;
                }
            }
 
         }
    }   
/*    
    printf("this is num:\n");
    for (i = 0; i < M; i++) 
    {
        printf("%d%c",b[i].num,(i%10!=9)?'\t':'\n');
    }
    
    printf("this is a:\n");
    for (i = 0; i < M; i++) 
    {
        printf("%d%c",b[i].a,(i%10!=9)?'\t':'\n');
    
    }

    printf("fu zhu gei a[]\n");
*/
    for (i = 0; i < M; i++) 
    {
        a[i]=b[i].a;
    }

}
void rand_array(int a[])
{
    int i = 0 ;
    srand(time(NULL));
    for (i = 0; i < M; i++) 
    {
        a[i]=(rand()%50);
    }
    for (i = 0; i < M; i++) 
    {
        
        printf("%d%c",a[i],(i%10!=9)?'\t':'\n');
    }
}
int main(int argc, const char *argv[])
{
    int a[M];
    int i = 0;
    printf("this is rand array:\n");
    rand_array(a);
    printf("this is roll:\n");
    sort_bit(a);
    printf("\n");
    for (i = 0; i < M; i++) 
    {
        printf("%d%c",a[i],(i%10!=9)?'\t':'\n');
    }
    return 0;
}

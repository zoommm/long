#include <stdio.h>
struct WER_int
{
    int a;
    int num;
};
void quict_array(int a[])
{
    
}

void comp_array(int a[])
{
    int i = 0;
}

int sort_bit(int a[])
{
    int i = 0;
    int j = 0;
    int p;
    int tem = 0;
    struct WER_int b[10];
    for (i = 0; i < 10; i++) 
    {
        b[i].a = a[i];
    }

    for (i = 0; i < 10; i++) 
    {
        for (j = 0; j < 10; j++) 
        {
            if (a[i]&0x1) 
            {
                p++;
            }
            a[i]=a[i]>>1;
        }
        b[i].num=p;
        printf("%d\n",b[i].num);
        p = 0;
    }   
    printf("\n");
    for (i = 0; i < 10; i++) 
    {
         for (j = i+1; j < 10; j++) 
         {
             if (b[i].num>b[j].num) 
             {
                tem = b[j].num;
                b[j].num = b[i].num;
                b[i].num = tem;
             }
             
         }
    }   
    for (i = 0; i < 10; i++) 
    {
        printf("%d%c",b[i].num,(i%5!=4)?'\t':'\n');
    }
    printf("\n");

}
int main(int argc, const char *argv[])
{
    int a[10]={1,3,9,6,11,12,22,122,5,5};
    sort_bit(a);
    return 0;
}

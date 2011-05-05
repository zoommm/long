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
    struct WER_int int b[10];
    for (i = 0; i < 10; i++) 
    {
        b[i].a = a[i];
    }
    int p;
    int j = 0;
    int i = 0;
    for (i = 0; i < 10; i++) 
    {
        for (j = 0; j < 10; j++) 
        {
            
        
            if (a[i]&0x1) 
            {
                p++;
            }
            a[i]=>>1;
        }
        b[i].num=p;
        printf("%d\n",b[i].num);
    }
    
}
int main(int argc, const char *argv[])
{
    int a[100]={1,3,9,6,11}
    sort_bit(a);
    return 0;
}

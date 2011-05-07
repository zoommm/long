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
   

}
int main(int argc, const char *argv[])
{
    int a[100]={1,3,9,6,11,12,22,120};
    sort_bit(a);
    return 0;
}

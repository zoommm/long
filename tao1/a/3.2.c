#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a[50];
    int i;
    int oddsum = 0 ,evesum = 0 ;

    srand((unsigned)time(NULL));
    for (i = 0; i < 50; i++) 
    {
        a[i]=rand()%30;
        printf("%d%c",a[i],(i%5!=4)?'\t':'\n');
    }
    for (i = 0; i < 50; i++) 
    {
        if (a[i]%2) 
        {
            evesum++;
        }
        else
        {
            oddsum++;
        }
    }
    printf("In array a,%d numbers are even,%d number are odd!\n",evesum,oddsum);
    if (15%4==15/4) 
    {
        printf("equal\n");
    }
    else
    {
        printf("not equal\n");
    }
    return 0;
}

#include <stdio.h>


struct A
{
    short i;
    short j;
    char* ptr;
    long array[100];
    char b[4];
    char* c;
};
#define PRINT_ME  (char *)&(((struct A *)0)->c)
    
    
int main(int argc, const char *argv[])
{
    printf("%d\n",PRINT_ME);    
    return 0;
    
}

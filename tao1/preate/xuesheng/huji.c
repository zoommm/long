#include <stdio.h>
#include"print_test.h"
struct  node
{
    int number;
    char name[20];
    char address[100];
    struct node *next;

};
typedef struct node V_NODE;
void print_word();
void print_sys();
int main(int argc, const char *argv[])
{
    int flag = 0;
    print_word();
    print_sys();
    while(!flag)
    {
    
    
    }
    return 0;
}
void print_sys()
{
    printf("1.ADD link\n");
    printf("2.delete link\n");
    printf("3.print link\n");
    printf("4.load link\n");
    printf("5.save link\n");    
    printf("6.exit link\n");
    return 0;
}

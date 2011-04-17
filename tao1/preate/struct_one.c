#include <stdio.h>
#include <string.h>
struct  node
{
    int num;
    char name[20];
    char score;
}; 
typedef struct  node V_NODE;

int main(int argc, const char *argv[])
{
    int i=0;
    V_NODE stu;
    V_NODE *ptr = NULL;
//这是用给stu用指针来变量；
//这真用->而变量stu用点num来变量
    ptr = &stu;

    printf("input a number:\n");
    scanf("%d",&ptr->num);
    printf("input a score\n");
    getchar();
    scanf("%c",&ptr->score);

    printf("input a name:\n",ptr->name);
//name 就不用＆得符号了，因为name本身就是个地址，所以不用＆取地址符号。
    scanf("%s",ptr->name);
//    strcpy(ptr->name,"骚东是猪");
    for (i = 0; i < 10; i++) 
    {
         printf("number:%3d\tscore: %c\n",ptr->num,ptr->score);
         printf("name: %s\n",stu.name);
    }
    printf ("this is oo function\n");


    return 0;
}

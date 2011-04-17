#include <stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int number;

    char name[20];
//在结构体中定义自己得指针；
    struct node *next;

};
typedef struct node V_NODE;
void print_link(V_NODE *p);
V_NODE *link_add(V_NODE *head);
V_NODE *delete_link(V_NODE *head);

V_NODE *create_link (int n);
int main(int argc, const char *argv[])
{
    V_NODE *head=NULL;
    int n=0;
    printf("input a number:\n");
    scanf("%d",&n);
    head = create_link(n);
    print_link(head);
    head = link_add(head);
    print_link(head);
    head =delete_link(head);
    print_link(head);
    return 0;
}
V_NODE *create_link(int n)
{
//在建立链表得时候首地址，一般都不能动，否则地址得内容会丢失了；
    V_NODE *p=NULL;
    V_NODE *head=NULL;
    int i=0;
 //malloc是给程序员设计得堆空间，这个空间不是因为函数结束而结束，而是进程结束或者
 //free掉这个空间。才能释放掉这个空间。
    p = head = malloc (sizeof(V_NODE));
    if (p==NULL) 
    {
  //perror();一般是打印错误信息得函数，它会打印出哪得信息出现错误，但是你给它一个参。
        perror("malloc");
        exit(0);

    }

    p->number =0;
    strcpy( p->name,"sao");
    p->next =NULL;
    for (i = 0; i < n; i++) 
    {
        p->next = malloc (sizeof(V_NODE));
        if (p->next == NULL) 
        {
            perror ("malloc");
            exit(0);
        }
        p->next->number = i+1;
        strcpy( p->next->name,"ASS");
        p->next->next=NULL;
        p = p->next;
    }
    return head;
}

////打印得函数
////
void print_link(V_NODE *p)
{
    while(p!=NULL)
    {
         printf("%d\t%s\n",p->number,p->name);
         p = p->next;
    
         printf("\n");
    }
}
////链表得添加
V_NODE *link_add(V_NODE *head)
{
    V_NODE *p = NULL;
    V_NODE *ptr =head;
    p = malloc(sizeof(V_NODE));
    if (p==NULL) 
    {
        perror("malloc");
        exit(0);
    }
    
    printf("input a number:");
    scanf("%d",&p->number);
    printf("input a name:");
    scanf("%s",p->name);
    p->next = NULL;
    if (ptr==NULL) 
    {
        return p;
    }
    if (p->number<=ptr->number) 
    {
        p->next=ptr;
        head=p;
        return head;
    }
    while((ptr->next!=NULL)&&(p->number>ptr->next->number))
    {
    ptr = ptr->next;
     
    } 
    p->next=ptr->next;
    ptr->next=p;
    
    return head;

}
//链表得删除；
V_NODE *delete_link(V_NODE *head)
{
//判断有没有要找得链表。
   int num=0;
   V_NODE *p=head;
   V_NODE *ptr;
//head就一个所以要新定一个指针来释放。
   if (head==NULL) 
   {
       printf("empty link !\n");
       return NULL;
   }
   printf("PLease input number of node to delete:\n");
   scanf("%d",&num);
//要释放空间了，要free得函数。用man free，没有得话，man 2 free  或者 man 3
//free。
   if (num==head->number) 
   {
       head=head->next;
       free(p);
       return head;
   }
//查找地方
   while((p->next!=NULL)&&(p->next->number!=num))
    {
        p=p->next;      
    }
//时刻注意你得==号还是=号，否者容易出错，已经是2回了
    if (p->next==NULL) 
    {
        printf("No number match!\n");
    }
//删除操作  还需要用ptr得指针来释放链表丢下得

    else
    {
        ptr =p->next;
        p->next=p->next->next;
        free(ptr);
    }

   return head;
}


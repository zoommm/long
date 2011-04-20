#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int number;
    char name[20];
    struct node *next;
};
typedef struct node V_NODE;

V_NODE *link_add(V_NODE *head);
V_NODE *delete_link(V_NODE *head) ;
void print_list(V_NODE *p);
V_NODE *create_link(int n);
int get_choice(void);
void print_list(void);
int main(int argc, const char *argv[])
{
    V_NODE *head = NULL;
    char flag=0;
    while(!flag)
    {
        print_list();
        switch(get_choice());
        {
        case 1:head = link_add(head);break;
        case 2:head = delete_link(head);break;
        case 3:print_list(head);break;
        case 4:flag=1;break;
        default : break;
        }
        getchar();
        getchar();
    }
    return 0;
}
void print_list(void)
{
    printf("Please make a choice :\n");
    printf("1.ADD node\n");
    printf("2.delete node \n");
    printf("3.print link\n");
    printf("4.exit \n");    

}
int get_choice(void)
{
    char choice[20];
    scanf("%s",&choice);
    return atoi(choice);
}
V_NODE *create_link(int n)
{
    V_NODE *p = NULL;
    V_NODE *head = NULL;
    int i=0;
    p = head = malloc (sizeof(V_NODE));
    if (p==NULL) 
    {
       perror("malloc");
       exit(0);
    }
    p->number = 0;
    strcpy(p->name,"sao");
    p->next = NULL;
    for (i = 0; i < n; i++) 
    {
        p->next = malloc (sizeof(V_NODE));
        if (p->next == NULL) 
        {
            perror("malloc");
            exit(0);
        }
        p->next->number=i+1;
        strcpy(p->next->name,"add");
        p->next->next=NULL;
        p=p->next;
    }
    return head;
}
void print_list(V_NODE *p)
{
    printf("\n");
    printf("student formantion:\n");
    printf("number\tname\n");
    if (p==NULL) 
    {
        printf("no char node\n");
    }
    while(p!=NULL)
    {
    printf("%d\t%s\n",p->number,p->name);
    p = p->next;
    }
}
V_NODE *link_add(V_NODE *head)
{
    V_NODE *p = NULL;
    V_NODE *ptr = head;
    p = malloc(sizeof(V_NODE));
    if (p==NULL) 
    {
        perror("malloc");
        exit(0);

    }
    printf("input a number:\n");
    scanf("%d",&p->number);
    printf("input a name :\n");
    scanf("%s",p->name);
    p->next = NULL;
    if (ptr==NULL) 
    {
        return p;   
    }
    if (p->number<=ptr->number) 
    {
        p->next=ptr;
        head = p;
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
V_NODE *delete_link(V_NODE *head) 
{
    int num = 0;
    V_NODE *p = head;
    V_NODE *ptr;
    if (head==NULL) 
    {
        printf("empty link !\n");
        return NULL;
    }
    printf("Please input number of node to delete :\n");
    scanf("%d",&num);
    if (num==head->number) 
    {
        head=head->next;
        free(p);
        return head;
    }
    while((p->next!=NULL)&&(p->next->number!=num))
    {
        p=p->next;
    }
    if (p-next==NULL) 
    {
        printf("NO number matce\n");
    }
    else
    {
    ptr = p->next;
    p->next=p->next->next;
    free(ptr);

    }
    return head;
}

#include<stdio.h>
#include<stdlib.h>
typedef struct stack_LL
{
    int data;
    struct stack_LL *next;
}sll;
void ini(sll **top)
{
    *top=NULL;
}
int is_empty(sll *top)
{
    return (top==NULL);
}
void push(sll **top,int n)
{
    sll *temp =(sll*)malloc(sizeof(sll));
    temp->data=n;
    temp->next=*top;
    *top=temp;
}
void pop(sll **top)
{
    if(*top==NULL)
    {
        printf("\nStack is empty\n");
        return;
    }
    sll *t;
    t=*top;
    int n=t->data;
    *top=(*top)->next;
    free(t);
    printf("%d deleted from stack.",n);
}
void display(sll *top)
{
    if(top==NULL)
    {
        printf("\nStack is empty\n");
        return;
    }
    while(top!=NULL)
    {
        printf("%d ",top->data);
        top=top->next;
    }
}
int main()
{
    sll *top;
    int c;
    ini(&top);
    while(1)
    {
        printf("\nEnter: \n1 to push\n2 to pop\n3 to check if stack is empty\n4 to display stack\n5 to exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                int n;
                printf("Enter number to insert: ");
                scanf("%d",&n);
                push(&top,n);
                break;
            }
            case 2:
            {
                pop(&top);
                break;
            }
            case 3:
            {
                if(is_empty(top))
                printf("\nStack is empty\n");
                else
                printf("\nStack is not empty\n");
                break;
            }
            case 4:display(top);break;
            case 5:return 0;
            default:printf("Wrong input");
        }
    }
}

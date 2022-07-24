#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int top;
    int size;
    int *arr;   
}stack;
void initialisation(stack *s)
{
    s->top=-1;
}
int is_empty(stack *s)
{
    return (s->top==-1);
}
int is_full(stack *s)
{
    return (s->top==s->size-1);
}
void push(stack *s,int n)
{
    if(is_full(s))
    {
        printf("\nStack is Full!\n");
        return;
    }
    s->arr[++(s->top)]=n;
}
void pop(stack *s)
{
    if(is_empty(s))
    {
        printf("\nStack is Empty!\n");
        return;
    }
    printf("%d deleted from stack.\n",s->arr[(s->top)--]);
}
void display(stack *s)
{
    if(s->top>-1)
    {
        for(int i=0;i<=s->top;i++)
        printf("%d ",s->arr[i]);
    }
    else
    printf("\nStack is empty\n");
}
int main()
{
    stack *s=(stack*)malloc(sizeof(stack));
    int i=0,c;
    initialisation(s);
    printf("Enter size of the stack: ");
    scanf("%d",&s->size);
    s->arr=(int*)malloc(s->size*sizeof(int)); 
    while(1)
    {
        printf("\nEnter: \n1 to check if stack is empty or not\n2 to check if stack is full or not\n3 to push a number in the stack\n4 to pop a number from the stack\n5 to display the stack\n6 to exit\n");
        scanf("%d",&c);
        switch (c)
        {
            case 1:
            {
                printf(is_empty(s)?"\nStack is empty\n":"\nStack is full\n");
                break;
            }
            case 2:
            {
                printf(is_full(s)?"\nStack is full\n":"\nStack is empty\n");
                break;
            }
            case 3:
            {
                int r;
                printf("Enter a number to insert: ");
                scanf("%d",&r);
                push(s,r);
                break;
            }
            case 4:
            {
                pop(s);
                break;
            }
            case 5:display(s);break;
            case 6:return 0;
            default:
            {
                printf("Wrong Choice!");
            }
        }
    }

}
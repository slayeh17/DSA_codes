#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int data;
    struct queue *next;
}queuell;
void ini(queuell **f,queuell **r)
{
    *f=NULL;
    *r=NULL;
}
int isEmpty(queuell *f)
{
    return (f==NULL);
}
void enqueue(queuell **f,queuell **r,int n)
{
    queuell *temp=(queuell*)malloc(sizeof(queuell));
    temp->data=n;
    temp->next=NULL;
    if(isEmpty(*f))
    {
        *f=temp;
        *r=temp;
    }
    else
    {
        (*r)->next=temp;
        *r=temp;
    }
}
void dequeue(queuell **f)
{
    if(isEmpty(*f))
        printf("\nThe queue is empty");
    else
    {
        queuell *temp;
        temp=*f;
        printf("\n%d dequeued from the queue",temp->data);
        *f=temp->next;
        free(temp);
    }
    printf("\n");
}
void display(queuell **f,queuell **r)
{
    if(isEmpty(*f))
        printf("\nThe queue is empty");
    else
    {
        queuell *cur;
        for(cur=*f;cur!=(*r)->next;cur=cur->next)
            printf("%d ",cur->data);
    }
    printf("\n");
}
int main(){
    queuell *f,*r;
    ini(&f,&r);
    while(1)
    {
        int c;
        printf("Enter:\n1 to enqueue\n2 to dequeue\n3 to display\n4 to exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                {
                    int h;
                    printf("Enter the number: ");
                    scanf("%d",&h);
                    enqueue(&f,&r,h);
                    break;
                }
            case 2:
                {
                    dequeue(&f);
                    break;
                }
            case 3:
                {
                    display(&f,&r);
                    break;
                }
            case 4:
                {
                    return 0;
                }
            default:
                {
                    printf("\nWrong Choice!!!\n");
                    break;
                }
        }
    }
}

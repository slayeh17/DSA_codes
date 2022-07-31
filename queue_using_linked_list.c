#include<stdio.h>
#include<stdlib.h>
typedef struct queue_ll
{
    int data;
    struct queue_ll *next;
}qll;
int isempty(qll *head)
{
    if(head==NULL)
        return 1;
    return 0;
}
void enqueue(qll **head,int n)
{
    qll *temp = (qll*)malloc(sizeof(qll)),*cur,*prv;
    temp->data=n;
    temp->next = NULL;
    for(cur=*head,prv=NULL;cur!=NULL;cur=cur->next)
        prv=cur;
    if(prv==NULL)
        *head=temp;
    else
        prv->next=temp;
}
void dequeue(qll **head)
{
    if(isempty(*head)==0)
    {
        qll *nxt=(*head)->next;
        printf("\n%d dequeued from queue",(*head)->data);
        *head=nxt;
    }
    else
        printf("\nThe queue is empty");
    printf("\n");

}
void display(qll *head)
{
    if(isempty(head)==0)
    {
        while(head!=NULL)
        {
            printf("%d ",head->data);
            head=head->next;
        }
    }
    else
       printf("\nThe queue is empty");
    printf("\n");
}
int main(){
    qll *head;
    head=NULL;
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
                    enqueue(&head,h);
                    break;
                }
            case 2:
                {
                    dequeue(&head);
                    break;
                }
            case 3:
                {
                    display(head);
                    break;
                }
            case 4:
                {
                    return 0;
                }
            default:
                {
                    printf("Wrong Choice!!!");
                    break;
                }
        }
    }
}

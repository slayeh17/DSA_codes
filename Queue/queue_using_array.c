#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
    int size,f,r,*arr;
}queue;
int isfull(queue *q)
{
    if(q->r==(q->size-1))
        return 1;
    else
        return 0;
}
int isempty(queue *q)
{
    if(q->f==q->r)
        return 1;
    else
        return 0;
}
void enqueue(queue **qq,int n)
{
    if(isfull(*qq)==0)
        (*qq)->arr[++(*qq)->r]=n;
    else
        printf("\nThe queue is full.\n");
}
void dequeue(queue **qq)
{
    if(isempty(*qq)==0)
    {
        (*qq)->f++;
        printf("\n%d dequeued from queue",(*qq)->arr[(*qq)->f]);
    }
    else
        printf("\nThe queue is empty.");
    printf("\n");
}
void display(queue *q)
{
    if(isempty(q)==0)
    {
        for(int i=q->f+1;i<=q->r;i++)
            printf("%d ",q->arr[i]);
    }
    else
        printf("\nThe queue is empty.");
        printf("\n");
}
int main(){
    queue *q;
    q=(queue*)malloc(sizeof(queue));
    q->f=q->r=-1;
    printf("Enter the size of the queue: ");
    scanf("%d",&q->size);
    q->arr=(int*)malloc(q->size*(sizeof(int)));
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
                    enqueue(&q,h);
                    break;
                }
            case 2:
                {
                    dequeue(&q);
                    break;
                }
            case 3:
                {
                    display(q);
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

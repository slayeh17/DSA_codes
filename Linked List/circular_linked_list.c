#include<stdio.h>
#include<stdlib.h>
typedef struct circular_linked_list
{
    int data;
    struct circular_linked_list *next;
}cll;
void sequential_insertion(cll **head,int n)
{
    cll *cur,*temp;
    temp=(cll*)malloc(sizeof(cll));
    temp->data=n;
    if(*head==NULL)
    {
        *head=temp;
        temp->next=*head;
        return;
    }
    for(cur=*head;cur->next!=*head;cur=cur->next);
    cur->next=temp;
    temp->next=*head;
}
void sorted_insertion(cll **head,int n)
{
    cll *cur,*prv,*temp,*h=NULL;
    temp=(cll*)malloc(sizeof(cll));
    temp->data=n;
    if(*head==NULL)
    {
        *head=temp;
        temp->next=*head;
        return;
    }
    for(cur=*head,prv=NULL;cur!=h && cur->data<n;cur=cur->next)
    {
        h=*head;
        prv=cur;
    }
    temp->next=cur;
    if(prv==NULL)
    {
        cll *last;
        for(last=*head;last->next!=*head;last=last->next);
        *head=temp;
        last->next=*head;
    }
    else
    {
        prv->next=temp;
    }
}
int findnum(cll **head,int n)
{
    cll *cur=*head;
    do
    {
        if(cur->data==n)
        return 1;
        cur=cur->next;
    }while(cur!=*head);
    return 0;
}
void deletion(cll **head,int n)
{
    if(*head==NULL)
    {
        printf("\nEmpty List\n");
        return;
    }
    if(findnum(head,n)==0)
    {
        printf("\n%d is not in the list\n",n);
        return;
    }
    else
    printf("\n%d deleted from the list\n",n);
    cll *last,*cur,*prv;
    if((*head)->data==n)
    {
        for(last=*head;last->next!=*head;last=last->next);
        if(last==*head)
        {
            *head=NULL;
            return;
        }
        *head=(*head)->next;
        last->next=*head;
    }
    else
    {
        for(cur=*head,prv=NULL;cur->data!=n;cur=cur->next)
        prv=cur;
        prv->next=cur->next;
    }
}
void display(cll *head)
{
    if(head==NULL)
    {
        printf("\nEmpty List\n");
        return;
    }
    cll *cur=head;
    do
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
    while(cur!=head);
}
int main()
{
    cll *head=NULL;
    while(1)
    {
        int c;
        printf("\nEnter:\n1 to insert sequentially\n2 to insert in sorted order\n3 to delete\n4 to display\n5 to exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                int d;
                printf("Enter a number: ");
                scanf("%d",&d);
                sequential_insertion(&head,d);
                break;
            }
            case 2:
            {
                int d;
                printf("Enter a number: ");
                scanf("%d",&d);
                sorted_insertion(&head,d);
                break;
            }
            case 3:
            {
                int d;
                printf("Enter a number: ");
                scanf("%d",&d);
                deletion(&head,d);
                break;
            }
            case 4:display(head);break;
            case 5:return 0;
            default:printf("Wrong Choice!!!");break;
        }
    }
}

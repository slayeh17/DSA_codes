#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
void ini(node **head)
{
    *head=NULL;
}
void sorted_insertion(node **head,int n)//1
{
    node *cur,*prv,*temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=n;
    for(cur=*head,prv=NULL;cur!=NULL && n>cur->data;cur=cur->next)
    prv=cur;
    temp->next=cur;
    if(prv==NULL)
    *head=temp;
    else
    prv->next=temp;
}
void recursive_sorted_insertion(node **head,int n)//2
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=n;
    temp->next=NULL;
    if(*head==NULL)
    *head=temp;
    else if(n<(*head)->data)
    {
        temp->next=*head;
        *head=temp;
    }
    else
    recursive_sorted_insertion(&((*head)->next),n);  
}
void sequential_insertion(node **head,int n)//3
{
    node *cur,*prv,*temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=n;
    temp->next=NULL;
    for(cur=*head,prv=NULL;cur!=NULL;cur=cur->next)
    prv=cur;
    if(prv==NULL)
    *head=temp;
    else
    prv->next=temp;
}
void recursive_sequential_insertion(node **head,int n)//4
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=n;
    temp->next=NULL;
    if(*head==NULL)
    *head=temp;
    else
    recursive_sequential_insertion(&((*head)->next),n);

}
void display(node *head)//5
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }   
}
void recursive_display(node *head)//6
{
    if(head==NULL)
    return;
    printf("%d ",head->data);
    return recursive_display(head->next);
}
void delete_node(node **head,int n)//7
{
    node *cur,*prv;
    for(cur=*head,prv=NULL;cur!=NULL && cur->data!=n;cur=cur->next)
    prv=cur;
    if(cur==NULL)
    {
        printf("\nElement Not Found!\n");
        return;
    }
    prv->next=cur->next;
    free(cur);
}
void reverse(node **head)//8
{
    node *cur,*prv,*t;
    for(cur=*head,prv=NULL;cur!=NULL;cur=t)
    {
        t=cur->next;
        cur->next=prv;
        prv=cur;
    }
    *head=prv;
}
void recursive_reverse_display(node *head)//9
{
    if(head==NULL)
    return;
    recursive_reverse_display(head->next);
    printf("%d ",head->data);
}
void count(node *head)//10
{
    int c=0;
    while(head!=NULL)
    {
        c++;
        head=head->next;
    }

    printf("\nNumber of elements in the Linked List: %d",c);
}
int recursive_count(node* head)//11
{
    if(head==NULL)
    return 0;

    return 1+recursive_count(head->next);
}
void split_even_odd(node **head,node *heade,node *heado)//12
{
    node *cur;
    for(cur=*head;cur!=NULL;cur=cur->next)
    {
        if(cur->data%2==0)
        sequential_insertion(&heade,cur->data);
        else
        sequential_insertion(&heado,cur->data);
    }
    printf("\n");
    display(heade);
    printf("\n");
    display(heado);
}
void merge_sorted(node *head1,node *head2,node *headnew)//13
{
    node *cur1,*cur2,*curnew;
    for(cur1=head1,cur2=head2;cur1!=NULL&&cur2!=NULL;)
    {
        if(cur1->data<cur2->data)
        {
            sequential_insertion(&headnew,cur1->data);
            cur1=cur1->next;
        }
        else
        {
            sequential_insertion(&headnew,cur2->data);
            cur2=cur2->next;
        }
    }
    for(;cur1!=NULL;cur1=cur1->next)
    sequential_insertion(&headnew,cur1->data);
    for(;cur2!=NULL;cur2=cur2->next)
    sequential_insertion(&headnew,cur2->data);
    display(headnew);
}
void search(node *head,int n)//14
{
    while(head!=NULL)
    {
        if(n==(head->data))
        {
            printf("\nElement Found");
            return;
        }
        head=head->next;
    }
    printf("\nElement Not Found");
}
int main()
{
    node *head,*head1,*head2;
    ini(&head);
    ini(&head1);
    ini(&head2);
    int n,d;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&d);
        recursive_sequential_insertion(&head,d);
    }
    // while(n--)
    // {
    //     scanf("%d",&d);
    //     recursive_sorted_insertion(&head1,d);
    // }
    // scanf("%d",&n);
    // while(n--)
    // {
    //     scanf("%d",&d);
    //     recursive_sorted_insertion(&head2,d);
    // }
    // int s;
    // scanf("%d",&s);
    // search(head,s);
    //reverse(&head);
    //recursive_reverse_display(head);
    //merge_sorted(head1,head2,NULL);
    //int c= recursive_count(head);
    //printf("\nNumber of elements in the Linked List: %d",c);
    // delete_node(&head,69);
    // printf("\n");
    //recursive_display(head);
}
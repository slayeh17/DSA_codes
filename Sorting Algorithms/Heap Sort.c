#include<stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int heap[],int i,int n)
{
    int largest=i;
    int leftChild=2*i+1;
    int rightChild=2*i+2;

    if(leftChild<n && heap[largest]<heap[leftChild])
    largest=leftChild;

    if(rightChild<n && heap[largest]<heap[rightChild])
    largest=rightChild;


    if(largest!=i)
    {
        swap(&heap[i],&heap[largest]);

        heapify(heap,largest,n);
    }
}

void heapSort(int heap[],int n)
{
    //making a MAX HEAP
    for(int i=n/2-1; i>=0; i--)
    heapify(heap,i,n);

    //deleting from MAX HEAP in order to sort the array heap[]
    for(int i=n-1;i>=0;i--)
    {
        swap(&heap[0],&heap[i]);

        heapify(heap,0,i);
    }
}

void display(int heap[],int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",heap[i]);
}

int main()
{
    int n;
    printf("Enter the size of the array(heap): ");
    scanf("%d",&n);
    int heap[n];
    printf("Enter the numbers you want to sort:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&heap[i]);
    heapSort(heap,n);
    display(heap,n);
}

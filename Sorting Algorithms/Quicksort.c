#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;*a=*b;*b=t;
}
int partition(int arr[],int lb,int ub)
{
	int pivot=arr[lb];
	int start=lb,end=ub;
	while(start<end)
	{
		while(arr[start]<=pivot)
		start++;
		while(arr[end]>pivot)
		end--;
		if(start<end)
		swap(&arr[start],&arr[end]);
	}
	swap(&arr[end],&arr[lb]);
	return end;
}
void quicksort(int arr[],int lb,int ub)
{
	if(lb<ub)
	{
		int pos=partition(arr,lb,ub);
		quicksort(arr,lb,pos-1);
		quicksort(arr,pos+1,ub);
	}	
}
void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",arr[i]);
}
int main()
{
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements: ");
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	quicksort(arr,0,n-1);
	display(arr,n);
}

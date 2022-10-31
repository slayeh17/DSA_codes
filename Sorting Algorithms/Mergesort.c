#include<stdio.h>
void merge(int arr[],int lb,int mid,int ub)
{
	int i=lb,j=mid+1,k=lb;
	int b[ub+1];
	while(i<=mid && j<=ub)
	{
		if(arr[i]<=arr[j])
		{
			b[k]=arr[i];
			i++;k++;
		}
		else
		{
			b[k]=arr[j];
			j++;k++;
		}
	}
	while(i<=mid)
	{
		b[k]=arr[i];
		i++;k++;
	}
	while(j<=ub)
	{
		b[k]=arr[j];
		j++;k++;
	}
	for(k=lb;k<=ub;k++)
	arr[k]=b[k];
}
void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	printf("%d ",arr[i]);
}
void mergesort(int arr[],int lb,int ub)
{
	if(lb<ub)
	{
		int mid=(lb+ub)/2;
		mergesort(arr,lb,mid);
		mergesort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}
int main()
{	
	int n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	int arr[n];
	for(int i=0;i<n;i++)
	scanf("%d",&arr[i]);
	mergesort(arr,0,n-1);
	display(arr,n);
}

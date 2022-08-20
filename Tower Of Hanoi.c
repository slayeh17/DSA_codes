#include<stdio.h>
void toh(int *steps,int n,char source,char helper,char destination)
{
	if(n==0)
	return;
	
	toh(steps,n-1,source,destination,helper);
	printf("Step %d: Move disk %d from %c to %c\n",++(*steps),n,source,destination);
	toh(steps,n-1,helper,source,destination);
}
int main()
{
	int n;
	printf("Enter the number of disks: ");
	scanf("%d",&n);
	int *steps;
	*steps=0;
	toh(steps,n,'A','B','C');
	return 0;
}

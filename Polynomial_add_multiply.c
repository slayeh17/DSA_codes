#include<stdio.h>
#include<stdlib.h>
typedef struct poly
{
	int coeff,exp;
	struct poly *next;
}poly;
void descending_insertion_without_duplication(poly **p,int c,int e)
{
	poly *cur,*prv,*temp;
	if(c==0)
	return;
	for(cur=*p;cur!=NULL && e<cur->exp;cur=cur->next)
	prv=cur;
	if(cur!=NULL && e==cur->exp)
	{
		cur->coeff+=c;
		if(cur->coeff==0)
		{
			if(prv!=NULL)
			prv->next=cur->next;
			else
			*p=cur->next;
			free(cur);
		}
		return;
	}
	temp=(poly*)malloc(sizeof(poly));
	temp->coeff=c;
	temp->exp=e;
	temp->next=cur;
	if(prv==NULL)
	*p=temp;
	else
	prv->next=temp;
}
void add(poly *p1,poly *p2,poly **padd)
{
	*padd=NULL;
	poly *cur;
	for(cur=p1;cur!=NULL;cur=cur->next)
	descending_insertion_without_duplication(padd,cur->coeff,cur->exp);
	for(cur=p2;cur!=NULL;cur=cur->next)
	descending_insertion_without_duplication(padd,cur->coeff,cur->exp);
}
void multiply(poly *p1,poly *p2,poly **pmul)
{
	*pmul=NULL;
	poly *cur;
	for(;p1!=NULL;p1=p1->next)
	{
		for(cur=p2;cur!=NULL;cur=cur->next)
		descending_insertion_without_duplication(pmul,p1->coeff*p2->coeff,p1->exp+p2->exp);
	}
}
void input(poly **p)
{
	int c,e;
	char choice='Y';
	while(choice=='Y')
	{
		printf("Enter the coefficient: ");
		scanf("%d",&c);
		fflush(stdin);
		printf("Enter the exponent: ");
		scanf("%d",&e);
		fflush(stdin);
		descending_insertion_without_duplication(p,c,e);
		printf("\nDo you want to enter more polynomials -> Y or N: ");
		scanf("%*c %c", &choice);
	}
}
void display(poly *p)
{
	printf("%dx^%d",p->coeff,p->exp);
	p=p->next;
	while(p!=NULL)
	{
		if(p->coeff>0)
		printf("+%dx^%d",p->coeff,p->exp);
		else
		printf("%dx^%d",p->coeff,p->exp);
		p=p->next;
	}
}
int main()
{
		poly *p1=NULL,*p2=NULL,*p=NULL;
		printf("\nEnter polynomial 1:\n");
		input(&p1);
		printf("\nEnter polynomial 2:\n");
		input(&p2);
		while(1)
		{
			printf("\nEnter:\n1 to add\n2 to multiply\n3 to display after addition or multiplication\n4 to exit\n");
			int choice;
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:add(p1,p2,&p);break;
				case 2:multiply(p1,p2,&p);break;
				case 3:display(p);break;
				case 4:return 0;
				default:printf("Wrong Choice!!!");break;
			}
		}
}		

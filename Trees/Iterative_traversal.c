#include<stdio.h>
#include<stdlib.h>
typedef struct bst
{
	int data;
	struct bst *left,*right;
}bst;
void iterative_insertion(bst **root,int n)
{
	bst *par,*cur=*root;
	bst *temp=(bst*)malloc(sizeof(bst));
	temp->data=n;
	temp->left=temp->right=NULL;
	if(*root==NULL)
	{
		*root=temp;
		return;
	}
	for(par=NULL;cur;)
	{
		par=cur;
		if(cur->data>n)
		cur=cur->left;
		else
		cur=cur->right;
	}
	if(par->data>n)
	par->left=temp;
	else
	par->right=temp;
}
void inorder(bst *root)
{
	bst **stack=(bst**)malloc(sizeof(bst*)*100);
	int top=-1;
	while(1)
	{
		while(root)
		{
			stack[++top]=root;
			root=root->left;
		}
		if(top!=-1)
		{
			root=stack[top--];
			printf("%d ",root->data);
			root=root->right;
		}
		else
		break;
	}
}
void preorder(bst *root)
{
	bst **stack=(bst**)malloc(sizeof(bst*)*100);
	int top=-1;
	while(1)
	{
		while(root)
		{
			printf("%d ",root->data);
			stack[++top]=root;
			root=root->left;
		}
		if(top!=-1)
		{
			root=stack[top--];
			root=root->right;
		}
		else
		break;
	}
}
void postorder(bst *root)
{
	bst **stack=(bst**)malloc(sizeof(bst*)*100);
	bst *cur=root;
	int top=-1;
	while(cur!=NULL || top!=-1)
	{
		if(cur!=NULL)
		{
			stack[++top]=cur;
			cur=cur->left;
		} 
		else
		{
			bst *temp=stack[top]->right;
			if(temp==NULL)
			{
				temp=stack[top--];
				printf("%d ",temp->data);
				while(top!=-1 &&  stack[top]->right==temp)
				{
					temp=stack[top--];
					printf("%d ",temp->data);
				}
			}
			else
			{
				cur=temp;
			}
		}
	}
}
int main()
{
	bst *root=NULL;
	int c;
	while(1)
	{
		printf("Enter \n1 to insert \n2 to display Inorder \n3 to display Preorder \n4 to display Postorder \n5 to 	exit:\n");
	scanf("%d",&c);
		switch(c)
		{	
			case 1:
			{	
				int d;
				printf("Enter: ");
				scanf("%d",&d);
				iterative_insertion(&root,d);
				break;
			}
			case 2:inorder(root);break;
			case 3:preorder(root);break;
			case 4:postorder(root);break;
			case 5:return 0;
		}
	}
}	

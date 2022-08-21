#include<stdio.h>
#include<stdlib.h>
typedef struct bst
{
	int data;
	struct bst *left,*right;
}bst;
void recursive_insertion(bst **root,int n)
{
	if(*root==NULL)
	{
		*root=(bst*)malloc(sizeof(bst));
		(*root)->data=n;
		(*root)->left=(*root)->right=NULL;		
	}
	else if(n<(*root)->data)
	recursive_insertion(&(*root)->left,n);
	else
	recursive_insertion(&(*root)->right,n);
}
void inorder(bst *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void postorder(bst *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		inorder(root->right);
		printf("%d ",root->data);
	}
}
void preorder(bst *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		inorder(root->left);
		inorder(root->right);
	}
}
int recursive_search(bst *root,int n)
{
	if(root!=NULL)
	{
		if(root->data==n)
		return 1;
		else if(n<root->data)
		recursive_search(root->left,n);
		else
		recursive_search(root->right,n);
	}
	else
	return 0;
}
int main()
{
	bst *root=NULL;
	while(1)
	{
		int c;
		printf("\nEnter:\n1 to insert\n2 to display in inorder sequence\n3 to display in preorder sequence\n4 to display in postorder sequence\n5 to search an element\n6 to exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			{
				int d;
				printf("Enter a number: ");
				scanf("%d",&d);
				recursive_insertion(&root,d);
				break;
			}
			case 2:
			{
				inorder(root);
				break;
			}
			case 3:
			{
				preorder(root);
				break;
			}
			case 4:
			{
				postorder(root);
				break;
			}
			case 5:
			{
				int x;
				printf("Enter a number: ");
				scanf("%d",&x);
				int found = recursive_search(root,x);
				if(found==1)
				printf("\nNumber present\n");
				else
				printf("\nNumber not present\n");
				break;
			}
			case 6: return 0;
			default: printf("Wrong Choice!!!");break;
		}
	}
}

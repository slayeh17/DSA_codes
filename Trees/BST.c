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
void search_node(bst **root,bst **par,bst **xnode,int *found,int n)
{
	bst *q=*root;
	*par=NULL;
	*found=0;
	while(q!=NULL)
	{
		if(n==q->data)
		{
			*xnode=q;
			*found=1;
			return;
		}
		else if(n<q->data)
		{
			*par=q;
			q=q->left;
		}	
		else
		{
			*par=q;
			q=q->right;
		}
	}
}
void deletion(bst **root,int n)
{
	bst *par,*xnode;
	int found=0;
	if(*root==NULL)
	{
		printf("Tree is empty!!!");
		return;
	}
	par=xnode=NULL;
	search_node(root,&par,&xnode,&found,n);
	if(found==0)
	{
		printf("Element not found!!!");
		return;
	}
	if(xnode->left!=NULL && xnode->right!=NULL)
	{
		par=xnode;
		bst *inorder_succ;
		inorder_succ=xnode->right;
		while(inorder_succ->left!=NULL)
		{
			par=inorder_succ;
			inorder_succ=inorder_succ->left;
		}
		xnode->data=inorder_succ->data;
		xnode=inorder_succ;
	}
	if(xnode->left==NULL && xnode->right==NULL)
	{
		if(xnode==*root)
		*root=NULL;
		else if(par->left==xnode)
		par->left=NULL;
		else
		par->right=NULL;
		free(xnode);
		return;
	}
	if(xnode->left!=NULL && xnode->right==NULL)
	{
		if(xnode==*root)
		*root=(*root)->left;
		else if(par->left==xnode)
		par->left=xnode->left;
		else
		par->right=xnode->left;
		free(xnode);
		return;
	}
	if(xnode->left==NULL && xnode->right!=NULL)
	{
		if(xnode==*root)
		*root=(*root)->right;
		else if(par->left==xnode)
		par->left=xnode->right;
		else
		par->right=xnode->right;
		free(xnode);
		return;
	}
}
int main()
{
	bst *root=NULL;
	while(1)
	{
		int c;
		printf("\nEnter:\n1 to insert\n2 to display in inorder sequence\n3 to display in preorder sequence\n4 to display in postorder sequence\n5 to delete a node\n6 to search an element\n7 to exit\n");
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
				deletion(&root,x);
				break;
			}
			case 6:
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
			case 7: return 0;
			default: printf("Wrong Choice!!!");break;
		}
	}
}

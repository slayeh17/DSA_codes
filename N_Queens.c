#include<stdio.h>
int is_safe(int x,int y,int n,char board[n][n])
{
	//checking column
	for(int row=x;row>=0;row--)
	{
		if(board[row][y]=='Q')
		return 0;
	}
	//checking left diagonal
	int row=x;
	int col=y;
	while(row>=0 && col>=0)
	{
		if(board[row][col]=='Q')
		return 0;
		row--;
		col--;
	}
	//checking right diagonal
	row=x;
	col=y;
	while(row>=0 && col<=(n-1))
	{
		if(board[row][col]=='Q')
		return 0;
		row--;
		col++;
	}
	return 1;
}
void display_board(int n,char board[n][n],int *count)
{
	*count=*count+1;
	printf("\nSolution %d:\n",*count);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		printf("%c ",board[i][j]);
		printf("\n");
	}	
}
int nQueen(int x,int n,char board[n][n])
{
	if(x==n)
	{	
		static int count=0;
		display_board(n,board,&count);
	}	
	for(int col=0;col<n;col++)
	{
		if(is_safe(x,col,n,board))
		{
			board[x][col]='Q';
			if(nQueen(x+1,n,board))
			return 1;
			
			board[x][col]='-';
		}
	}
	return 0;
}
int main()
{
	int n;
	scanf("%d",&n);
	char board[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		board[i][j]='-';
	}
	nQueen(0,n,board);
	return 0;
}

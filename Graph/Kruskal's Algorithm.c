#include<stdio.h>
#include<stdlib.h>
typedef struct graph
{
	int nE,nV,vertex[100][100];
}graph;
typedef struct edge_c_wt
{
	int a,b,wt;
}edgeCwt;
void sort(edgeCwt E[],int n)
{
	for(int i=1;i<n;i++)
	{
		edgeCwt cur=E[i];
		int j=i-1;
		while(j>=0 && cur.wt<E[j].wt)
		{
			E[j+1]=E[j];
			j--;
		}
		E[j+1]=cur;
	}
}
int areFriends(int i,int j,int n,int friends[n][n])
{
	return friends[i][j];
}
void checkAndMakeFriends(int a,int b,int n,int friends[n][n])
{
	for(int i=0;i<n;i++)
	{
		if(i!=b && (friends[a][i]==1 && friends[b][i]==0))
		{
			friends[b][i]==1;
			friends[i][b]==1;
			printf("Fuck You 1\n");
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=a && (friends[b][i]==1 && friends[a][i]==0))
		{
			friends[a][i]==1;
			friends[i][a]==1;
			printf("Fuck You 2\n");
		}
		
	}
}
void init(int n,int arr[n][n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		arr[i][j]=0;
	}
}
void display(edgeCwt mst[],int n)
{
	printf("Minimum Spanning Tree: \n");
	for(int i=0;i<n;i++)
	{
		printf("%d - %d: %d\n",mst[i].a,mst[i].b,mst[i].wt);
	}
}
void Kruskal(edgeCwt E[],graph G)
{
	sort(E,G.nE);
	int friends[G.nV][G.nV];
	init(G.nV,friends);
	edgeCwt mst[G.nV-1];
	for(int i=0;i<G.nV-1;i++)
	{
		//checkAndMakeFriends(E[i].a,E[i].b,G.nV,friends);
		
		if(friends[E[i].a][E[i].b]==0)//to check for cycle
		{
			mst[i]=E[i];
			friends[E[i].a][E[i].b]=1;
			friends[E[i].b][E[i].a]=1;
		}
		checkAndMakeFriends(E[i].a,E[i].b,G.nV,friends);
		for(int j=0;j<G.nV;j++)
		{
			for(int k=0;k<G.nV;k++)
			printf("%d ",friends[j][k]);
			printf("\n");
		}
		printf("\n");
	}
	display(mst,G.nV-1);
}
void create_graph(graph G,int i,int j,int wt)
{
	G.vertex[i][j]=wt;
	G.vertex[j][i]=wt;
}
int main()
{
	graph G;
	int k=0;
	printf("Enter the number of vertices and edges: ");
	scanf("%d%d",&G.nV,&G.nE);
	edgeCwt E[G.nE];
	int t=G.nE;
	while(t--)
	{
		printf("Enter the adjacent vertices and weights(* * *): ");
		int i,j,wt;
		scanf("%d%d%d",&i,&j,&wt);
		create_graph(G,i,j,wt);
		E[k].a=i;E[k].b=j;E[k].wt=wt;
		k++;
	}
	Kruskal(E,G);
	sort(E,G.nE);
	for(int i=0;i<G.nE;i++)
	{
		printf("%d - %d:%d",E[i].a,E[i].b,E[i].wt);
		printf("\n");
	}
}	

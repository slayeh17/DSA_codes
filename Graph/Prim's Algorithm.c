// 3 arrays are used:
// keys-> ini INF, mst-> ini 0 or false, parent-> ini -1.
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INF INT_MAX
typedef struct graph
{
	int nE,nV,vertex[100][100];
}graph;
int min(int keys[],int mst[],int n)
{
	int min=INF,min_index;
	for(int i=0;i<n;i++)
	{
		if(mst[i]==0 && keys[i]<min)
		{
			min=keys[i];
			min_index=i;
		}
	}
	return min_index;
}
void adj(graph G,int keys[],int ind,int parent[],int mst[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(G.vertex[ind][i]<keys[i] && G.vertex[ind][i]!=0 && mst[i]!=1)
		{
			keys[i]=G.vertex[ind][i];
			parent[i]=ind;
		}
	}
}
void display(int keys[],int parent[],int n,int start_v)
{
	int sum=0;
	printf("V - V: W\n");
	for(int i=0;i<n;i++)
	{
		if(parent[i]!=-1)
		printf("%d - %d: %d\n",parent[i],i,keys[i]);
		sum=sum+keys[i];
	}
	printf("\nMinimum Cost: %d\n",sum);
}
int Prim(graph G,int start_v)
{
	int n=G.nV;
	int keys[n],*mst=(int*)calloc(n,sizeof(int)),parent[n];
	for(int i=0;i<n;i++)
	{
		keys[i]=INF;
		parent[i]=-1;
	}
	keys[start_v]=0;
	//parent[start_v]=-1;
	for(int i=0;i<n;i++)
	{
		int ind=min(keys,mst,n);
		mst[ind]=1;
		adj(G,keys,ind,parent,mst,n);
	}
	display(keys,parent,n,start_v);
}
void create_graph(graph *G,int i,int j,int wt)
{
	G->vertex[i][j]=wt;
	G->vertex[j][i]=wt;
}
int main()
{
	graph G;
	printf("Enter the number of vertices and edges: ");
	scanf("%d%d",&G.nV,&G.nE);
	int t=G.nE;
	while(t--)
	{
		int i,j,wt;
		printf("Enter the adjacent vertices and its weights (* * *): ");
		scanf("%d%d%d",&i,&j,&wt);
		create_graph(&G,i,j,wt);
	}
	Prim(G,0);
}	

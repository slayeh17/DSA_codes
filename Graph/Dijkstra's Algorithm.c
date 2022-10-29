// visited array 
// shortest path array
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define INF INT_MAX
typedef struct graph
{
	int nE,nV,vertex[100][100];
}graph;
void create_graph(graph *G,int i,int j,int wt)
{
	G->vertex[i][j]=wt;
	G->vertex[j][i]=wt;	
}
int min(int sd[],int visited[],int n)
{
	int min=INF,min_index;
	for(int i=0;i<n;i++)
	{
		if(visited[i]!=1 && min>sd[i])
		min=sd[i],min_index=i;
	}
	return min_index;
}
void display(int sd[],int n,int source)
{
	for(int i=0;i<n;i++)
	{
		printf("Distance of %d from %d: %d\n",source,i,sd[i]);
	}
}
void Dijkstra(graph G,int source)
{
	int sd[G.nV],visited[G.nV];//sd -> shortest distance
	for(int i=0;i<G.nV;i++)
	{
		sd[i]=INF;
		visited[i]=0;
	}
	sd[source]=0;
	for(int i=0;i<G.nV-1;i++)
	{
		int ind=min(sd,visited,G.nV);
		visited[ind]=1;
		for(int j=0;j<G.nV;j++)
		{
			if(G.vertex[ind][j]!=0 && visited[j]!=1 && sd[ind]!= INF && sd[ind]+G.vertex[ind][j] < sd[j])
			sd[j]=sd[ind]+G.vertex[ind][j];
		}
	}
	display(sd,G.nV,source);
}
int main()
{
	graph G;
	printf("Enter the number of vertices and edges: ");
	scanf("%d%d",&G.nV,&G.nE);
	int i,j,wt;
	int t=G.nE;
	while(t--)
	{
		printf("Enter the adjacent vertices and weights(* * *): ");
		scanf("%d%d%d",&i,&j,&wt);
		create_graph(&G,i,j,wt);
	}
	Dijkstra(G,0);
}

//-1 = unvisited
// 0 = put in the queue/stack
// 1 = visited
#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	int top,*arr;
}stack;
typedef struct graph
{
	int nE,nV;
	int vertex[100][100];
}graph;
void stack_init(stack *s)
{
	s->top=-1;
}
void push(stack *s,int n)
{
	s->arr[++s->top]=n;
}
int pop(stack *s)
{
	return s->arr[s->top--];
}
void create_graph(graph *G,int i,int j)
{
	G->vertex[i][j]=1;
	G->vertex[j][i]=1;
}
int detect_cycle(graph G,int start_v)
{
	int visited[G.nV];
	stack s;
	stack_init(&s);
	s.arr=(int*)malloc(G.nV*sizeof(int));
	for(int i=0;i<G.nV;i++)
		visited[i]=-1;
	push(&s,start_v);
	visited[start_v]=0;
	while(s.top!=-1)
	{
		int p=pop(&s);
		visited[p]=1;
		for(int i=0;i<G.nV;i++)
		{
			if(visited[i]==0 && G.vertex[p][i]==1)
				return 1;
			if(visited[i]==-1 && G.vertex[p][i]==1)
			{
				push(&s,i);
				visited[i]=0;
			}
		}
	}
	return 0;
}
int main()
{
	graph G;
	printf("Enter the number of vertices and edges: ");
	scanf("%d%d",&G.nV,&G.nE);
	int t=G.nE;
	int i,j;
	while(t--)
	{
		printf("Enter the adjacent vertices: ");
		scanf("%d%d",&i,&j);
		create_graph(&G,i,j);
	}
	if(detect_cycle(G,0))
		printf("Graph has cycle\n");
	else
		printf("Graph does not have any cycle\n");
}

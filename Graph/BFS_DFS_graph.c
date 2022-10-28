#include<stdio.h>
#include<stdlib.h>
typedef struct queue//creating a structure for implementing queue
{
	int f,r,*arr;
}queue;
typedef struct stack//creating a structure for implementing stack
{
	int top,*arr;
}stack;
typedef struct graph//creating a structure for implementing graph
{
	int nE,n;//nE is the number of edges and n is the number of vertices
	int vertex[100][100];
}graph;
//For stack data stucture
void stack_init(stack *s)
{
	s->top=-1;
}
void push(stack *s,int n)
{
	s->arr[++(s->top)]=n;
}
int pop(stack *s)
{
	return s->arr[(s->top)--];
}
//For queue data stucture
void queue_init(queue *q)
{
	q->f=q->r=-1;
}
void enqueue(queue *q,int n)
{
	q->arr[++(q->r)]=n;
}
int dequeue(queue *q)
{
	return q->arr[++(q->f)];
}
void BFS(graph *G,int start_v)
{
	int *visited=(int*)calloc(G->n,sizeof(int));//creating a visited array with ini value 0
	queue q;
	queue_init(&q);
	q.arr=(int*)malloc(G->n*sizeof(int));
	visited[start_v]=1;//visiting the starting vertex
	enqueue(&q,start_v);
	printf("Visited BFS: ");
	while(q.f!=q.r)//running the loop until queue is empty
	{
		int p=dequeue(&q);
		printf("%d ",p);//printing visited vertices
		for(int i=0;i<G->n;i++)
		{
			if(visited[i]==0 && G->vertex[p][i]!=0)//checking if the vertex is visited or not and it has a connection or not
			{
				enqueue(&q,i);
				visited[i]=1;//marking the visited vertices
			}
		}
	}
	free(visited);
}	
void DFS(graph *G,int start_v)
{
	int *visited=(int*)calloc(G->n,sizeof(int));
	stack s;
	stack_init(&s);
	s.arr=(int*)malloc(G->n*sizeof(int));
	visited[start_v]=1;
	push(&s,start_v);
	printf("Visited DFS: ");
	while(s.top!=-1)//running the loop until stack is empty
	{
		int p=pop(&s);
		printf("%d ",p);
		for(int i=0;i<G->n;i++)
		{
			if(visited[i]==0 && G->vertex[p][i]!=0)
			{
				push(&s,i);
				visited[i]=1;
			}
		}
	}
}
void create_graph(graph *G,int i,int j)
{
	G->vertex[i][j]=1;
	G->vertex[j][i]=1;
}
void display(graph G)
{	
	printf("Edge Connections: \n");
	for(int i=0;i<G.n;i++)
	{
		printf("%d",i);
		for(int j=0;j<G.n;j++)
		{
			if(G.vertex[i][j]==1)
				printf(" - %d",j);
		}
		printf("\n");
	}
	printf("\nAdjacency Matrix: \n");
	for(int i=0;i<G.n;i++)
	{
		for(int j=0;j<G.n;j++)
		printf("%d ",G.vertex[i][j]);
		printf("\n");
	}
}
int main()
{
	graph G;
	int i,j;
	printf("Enter the number of vertices and edges: ");
	scanf("%d%d",&G.n,&G.nE);
	int t=G.nE;
	while(t--)
	{
		printf("Enter the adjacent vertices: ");
		scanf("%d%d",&i,&j);
		create_graph(&G,i,j);
	}
	display(G);
	printf("\n");
	BFS(&G,0);
	printf("\n");
	DFS(&G,0);
}

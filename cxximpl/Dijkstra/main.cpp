/*
5
11
0 1 8
0 2 32
1 0 12
1 2 16
1 3 15
2 1 29
2 4 13
3 1 21
3 4 7
4 2 27
4 3 19
*/


#include <stdio.h>
#include <stdlib.h>

#define MAXINT 200

typedef struct
{
	int vexnum;
	int arcnum;
//	char vexs[VNUM];
	int** arcs;
}Graph;//邻接矩阵存储

void createGraph(Graph &G);
void DFS(Graph G,int visit[],int v0);
void Dijkstra(Graph G,int dist[],int path[],int v0);
void dispCost(Graph G,int dist[],int path[]);

int main()
{
	Graph G;
	createGraph(G);
	int *dist,*path;
	dist = (int*)malloc(G.vexnum*sizeof(int));
	path = (int*)malloc(G.vexnum*sizeof(int));
	Dijkstra(G,dist,path,0);
	dispCost(G,dist,path);
	return 1;
}

void createGraph(Graph &G)
{
	int i,j,start,end,weight;
	printf("图中的顶点数:");
	scanf("%d",&G.vexnum);
	G.arcs = (int**)malloc(G.vexnum*sizeof(int*));
	for(i=0;i<G.vexnum;i++)
	{
		G.arcs[i]=(int*)malloc(G.vexnum*sizeof(int));
		//邻接矩阵初始化
		for(j=0;j<G.vexnum;j++)
		{
			G.arcs[i][j]=MAXINT;
		}
	}
	printf("图中的边数:");
	scanf("%d",&G.arcnum);
	printf("请输入图中的边[起点 终点 权值]:\n");
	for(i=0;i<G.arcnum;i++)
	{
		scanf("%d %d %d",&start,&end,&weight);
		G.arcs[start][end]=weight;
	}
}

//Dijkstra算法求最短路径
void Dijkstra(Graph G,int dist[],int path[],int v0)//v0为起点
{
	//初始化dist和path
	int i;
	int *s;
	s = (int*)malloc(G.vexnum*sizeof(int));
	for(i=0;i<G.vexnum;i++)
	{
		dist[i]=G.arcs[v0][i];
		s[i]=0;
		if(dist[i]==MAXINT)
		{
			path[i]=-1;
		}else
		{
			path[i]=v0;
		}
	}
	//主要代码
	dist[v0]=0;
	s[v0]=1;
	for(i=0;i<G.vexnum;i++)
	{
		//找到最小的边
		int min=MAXINT;
		int j;
		int k=v0;
		for(j=0;j<G.vexnum;j++)
		{
			if(s[j]==0 && dist[j]<min)
			{
				k = j;
				min = dist[j];
			}
		}
		if(k==v0)
		{
			break;
		}
		//加入集合中
		s[k]=1;
		for(j=0;j<G.vexnum;j++)
		{
			if(s[j]==0 && (dist[j]>dist[k]+G.arcs[k][j]))
			{
				dist[j] = dist[k]+G.arcs[k][j];
				path[j] = k;
			}
		}
	}
}

void printPath(int path[],int end)
{
	if(path[end] == -1)
	{
		printf(" %d",end);
		return;
	}
	else
	{
		printPath(path,path[end]);
		printf(" %d",end);
	}
}

void dispCost(Graph G,int dist[],int path[])
{
	int i,v0;
	for(i=0;i<G.vexnum;i++)
	{
		if(dist[i]==0)
		{
			v0 = i;
			break;
		}
	}
	for(i=0;i<G.vexnum;i++)
	{
		if(i!=v0)
		{
			printf("%d--->%d:",v0,i);
			printPath(path,i);
			printf("\n");
		}
	}
}

//深度优先遍历
void DFS(Graph G,int visit[],int v0)
{
	int i;
	printf("%d ",v0);
	visit[v0]=1;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.arcs[v0][i]!=MAXINT)
		{
			if(visit[i]==0)
			{
				DFS(G,visit,i);
			}
		}
	}
}

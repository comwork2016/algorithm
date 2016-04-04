/*
6
10
0 1 6
0 2 1
0 3 5
1 2 5
1 4 3
2 3 5
2 4 6
2 5 4
3 5 2
4 5 6
*/
#include "stdio.h"
#include "stdlib.h"

#define MAXINT 100

typedef struct
{
    int vexnum;
    int arcnum;
    int **arcs;
} MGraph; //无向图邻接矩阵

typedef struct
{
    int isIn;
    int weight;
    int u,v;//u为边的起点，v为边的终点，起点的值小于终点的值
} Edge; //边的信息

void createGraph(MGraph &G)
{
    int i,j,start,end,weight;
    printf("图中的顶点数:");
    scanf("%d",&G.vexnum);
    G.arcs = (int**)malloc(G.vexnum*sizeof(int*));
    for(i=0; i<G.vexnum; i++)
    {
        G.arcs[i]=(int*)malloc(G.vexnum*sizeof(int));
        //邻接矩阵初始化
        for(j=0; j<G.vexnum; j++)
        {
            G.arcs[i][j] = MAXINT;
        }
    }
    printf("图中的边数:");
    scanf("%d",&G.arcnum);
    printf("请输入图中的边[起点 终点 权值]:\n");
    for(i=0; i<G.arcnum; i++)
    {
        scanf("%d %d %d",&start,&end,&weight);
        G.arcs[start][end] = weight;
        G.arcs[end][start] = weight;
    }
};

void kruskal(MGraph G,Edge edges[])
{
    //将边的信息存储在edges[]中
    int i,j;
    int e = 0;
    for(i=0; i<G.vexnum; i++)
    {
        for(j=i+1; j<G.vexnum; j++)
        {
            if(G.arcs[i][j]!=MAXINT)
            {
                edges[e].weight = G.arcs[i][j];
                edges[e].u = i;
                edges[e].v = j;
                edges[e].isIn = 0;
                e++;
            }
        }
    }
    int *t;
    t = (int*)malloc(G.arcnum*sizeof(int));
    //最小生成树用双亲表示法存储
    for(i=0; i<G.vexnum; i++)
    {
        t[i] = i;//初始化双亲为自己;
    }
    while(1)
    {
        //选取最小的一条边
        int min = MAXINT;
        int k = -1;
        for(i=0; i<G.arcnum; i++)
        {
            if(edges[i].isIn ==0 && edges[i].weight < min)
            {
                min = edges[i].weight;
                k = i;
            }
        }
        if(k == -1)
        {
            break;
        }
        //判断加入该边后是否构成回路
        int u = edges[k].u;
        while(t[u]!=u)
        {
            u = t[u];
        }
        int v = edges[k].v;
        while(t[v]!=v)
        {
            v = t[v];
        }
        if(u!=v)//没有构成回路
        {
            //将该边的两个端点加入到最小生成树中
            t[v] = u;
            edges[k].isIn = 1;
        }
        else//构成回路
        {
            edges[k].weight = MAXINT;
        }
    }
}

int main()
{
    MGraph G;
    createGraph(G);
    Edge *edges = (Edge*)malloc(G.arcnum*sizeof(Edge));
    kruskal(G,edges);
    printf("最小生成树包含的边的信息如下：\n");
    int i;
    for(i=0; i<G.arcnum; i++)
    {
        if(edges[i].isIn == 1)
        {
            printf("%d->%d:%d\n",edges[i].u+1,edges[i].v+1,edges[i].weight);
        }
    }
    return 1;
}

#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;

struct Node
{
    int index;
    int weight;
    Node(int i,int w):index(i),weight(w){}
    friend bool operator<(Node n1,Node n2)
    {
        return n1.weight > n2.weight;
    }
};

struct Path
{
    int pre;
    int weight;
    Path():pre(-1),weight(INT_MAX){};
};

class ShortestPath
{
private:
    vector<vector<int> > m_Graph;
    int m_NodeCount;
    int m_NoEdge;
    int m_StartNode;
    int m_EndNode;
    vector<int> m_ShortestPath;
    int m_ShortestWeight;

public:
    ShortestPath(vector<vector<int> > graph,int startNode,int endNode)
    {
        this->m_Graph = graph;
        this->m_NodeCount = graph.size();
        this->m_NoEdge = -1;
        this->m_StartNode = startNode;
        this->m_EndNode = endNode;
    }

    void getShortestPath()
    {
        vector<Path> vec_Path(this->m_NodeCount);
        priority_queue<Node,vector<Node> > pq;
        pq.push(Node(this->m_StartNode,0));
        while(!pq.empty())
        {
            Node top = pq.top();//取出路径最短的结点
            pq.pop();
            if(top.index == this->m_EndNode)//最终的结点
            {
                break;
            }
            //广度优先遍历
            for(int i=0;i<this->m_NodeCount;i++)
            {
                if(this->m_Graph[top.index][i]!=this->m_NoEdge && top.weight+this->m_Graph[top.index][i] < vec_Path[i].weight)
                {
                    pq.push(Node(i,top.weight+this->m_Graph[top.index][i]));
                    vec_Path[i].pre = top.index;
                    vec_Path[i].weight = top.weight+this->m_Graph[top.index][i];
                }
            }
        }
        //保存最短路径
        this->m_ShortestWeight = vec_Path[this->m_EndNode].weight;
        int index = this->m_EndNode;
        while(index!=-1)
        {
            this->m_ShortestPath.push_back(index);
            index = vec_Path[index].pre;
        }
    }

    void printShortestPath()
    {
        cout<<"minimum weight:"<<this->m_ShortestWeight<<endl;
        cout<<"Path:";
        copy(this->m_ShortestPath.rbegin(),this->m_ShortestPath.rend(),ostream_iterator<int>(cout," "));
        cout<<endl;
    }
};

int main()
{
    const int n_NodeCount = 11;
	int i;
    vector<vector<int> > graph (n_NodeCount);
    for (i = 0;i < n_NodeCount; ++ i) {
        graph[i].resize (n_NodeCount);
    }
    for (i = 0;i < n_NodeCount; ++ i) {
        for (int j = 0;j < n_NodeCount; ++ j) {
            graph[i][j] = -1;//init edges
        }
    }
    graph[0][1] = 2;
    graph[0][2] = 3;
    graph[0][3] = 4;
    graph[1][2] = 3;
    graph[1][5] = 2;
    graph[1][4] = 7;
    graph[2][5] = 9;
    graph[2][6] = 2;
    graph[3][6] = 2;
    graph[4][7] = 3;
    graph[4][8] = 3;
    graph[5][6] = 1;
    graph[5][8] = 3;
    graph[6][9] = 1;
    graph[6][8] = 5;
    graph[7][10] = 3;
    graph[8][10] = 2;
    graph[9][8] = 2;
    graph[9][10] = 2;

    ShortestPath* sp = new ShortestPath(graph,0,10);
    sp->getShortestPath();
    sp->printShortestPath();
    delete sp;
    return 0;
}

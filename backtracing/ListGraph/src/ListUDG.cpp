#include "ListUDG.h"

/*
 * 创建邻接表对应的图(用已提供的数据)
 */
ListUDG::ListUDG(char vexs[], int vlen, char edges[][2], int elen)
{
        // 初始化"顶点数"和"边数"
        this->m_VexNum = vlen;
        this->m_EdgNum = elen;
        this->m_Vexs = new VNode[this->m_VexNum];
        char c1, c2;
        int p1, p2;
        ENode *node1, *node2;
        // 初始化"邻接表"的顶点
        for(int i=0; i<this->m_VexNum; i++)
        {
                this->m_Vexs[i].data = vexs[i];
                this->m_Vexs[i].firstEdge = nullptr;
        }

        // 初始化"邻接表"的边
        for(int i=0; i<this->m_EdgNum; i++)
        {
                // 读取边的起始顶点和结束顶点
                c1 = edges[i][0];
                c2 = edges[i][1];

                p1 = getPosition(c1);
                p2 = getPosition(c2);
                // 初始化node2
                node2 = new ENode();
                node2->ivex = p2;
                // 将node2链接到"p1所在链表的末尾"
                if(this->m_Vexs[p1].firstEdge == nullptr)
                {
                        this->m_Vexs[p1].firstEdge = node2;
                }
                else
                {
                        //用头插法插入到邻接表中
                        ENode* firstnode = this->m_Vexs[p1].firstEdge;
                        node2->nextEdge = firstnode;
                        this->m_Vexs[p1].firstEdge = node2;
                }

                // 初始化node1
                node1 = new ENode();
                node1->ivex = p1;
                // 将node1链接到"p2所在链表的末尾"
                if(this->m_Vexs[p2].firstEdge == nullptr)
                {
                        this->m_Vexs[p2].firstEdge = node1;
                }
                else
                {
                        ENode* firstnode = this->m_Vexs[p2].firstEdge;
                        node1->nextEdge = firstnode;
                        this->m_Vexs[p2].firstEdge = node1;
                }
        }
}

/*
 * 返回ch的位置
 */
int ListUDG::getPosition(char ch)
{
        for(int i=0; i<this->m_VexNum; i++)
        {
                if(this->m_Vexs[i].data==ch)
                {
                        return i;
                }
        }
        return -1;
}


/*
 * 深度优先搜索遍历图的递归实现
 */
void ListUDG::DFS(int i, int* visited)
{
        visited[i] = 1;
        std::cout << this->m_Vexs[i].data << " ";
        ENode *node = this->m_Vexs[i].firstEdge;
        while (node != nullptr)
        {
                if (!visited[node->ivex])
                {
                        DFS(node->ivex, visited);
                }
                node = node->nextEdge;
        }
}


/*
 * 深度优先搜索遍历图
 */
void ListUDG::DFS()
{
        int* visited = new int[this->m_VexNum];       // 顶点访问标记
        // 初始化所有顶点都没有被访问
        for (int i = 0; i < this->m_VexNum; i++)
        {
                visited[i] = 0;
        }
        std::cout << "DFS: ";
        for (int i = 0; i < this->m_VexNum; i++)
        {
                if (!visited[i])
                {
                        DFS(i, visited);
                }
        }
        std::cout << std::endl;
}


/*
 * 广度优先搜索（类似于树的层次遍历）
 */
void ListUDG::BFS()
{
        std::queue<int> queue_Nodes;
        int* visited = new int[this->m_VexNum];   // 顶点访问标记
        for (int i = 0; i < this->m_VexNum; i++)
        {
                visited[i] = 0;
        }
        std::cout << "BFS: ";
        for (int i = 0; i < this->m_VexNum; i++)
        {
                if (!visited[i])
                {
                        visited[i] = 1;
                        queue_Nodes.push(i);
                }
                while(!queue_Nodes.empty())
                {
                        int j = queue_Nodes.front();
                        queue_Nodes.pop();
                        std::cout << this->m_Vexs[j].data << " ";
                        ENode *node = this->m_Vexs[j].firstEdge;
                        while (node != nullptr)
                        {
                                int k = node->ivex;
                                if (!visited[k])
                                {
                                        visited[k] = 1;
                                        queue_Nodes.push(k);
                                }
                                node = node->nextEdge;
                        }
                }
        }
        std::cout << std::endl;
}

/*
 * 打印邻接表图
 */
void ListUDG::print()
{
        std::cout << "List Graph:" << std::endl;
        ENode *node;
        for (int i = 0; i < this->m_VexNum; i++)
        {
                std::cout << this->m_Vexs[i].data << "--->: ";
                node = this->m_Vexs[i].firstEdge;
                while (node != nullptr)
                {
                        std::cout << this->m_Vexs[node->ivex].data << "-->";
                        node = node->nextEdge;
                }
                std::cout << " nullptr;" << std::endl;
        }
}


ListUDG::~ListUDG()
{
        //dtor
        for(int i=0;i<this->m_VexNum;i++)
        {
                VNode vnode = this->m_Vexs[i];
                ENode* node = vnode.firstEdge;
                while(node->nextEdge!=nullptr)
                {
                        ENode* temp = node->nextEdge;
                        delete node;
                        node = temp;
                }
        }
        delete[] this->m_Vexs;
}

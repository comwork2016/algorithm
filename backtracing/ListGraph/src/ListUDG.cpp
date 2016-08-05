#include "ListUDG.h"

/*
 * �����ڽӱ��Ӧ��ͼ(�����ṩ������)
 */
ListUDG::ListUDG(char vexs[], int vlen, char edges[][2], int elen)
{
        // ��ʼ��"������"��"����"
        this->m_VexNum = vlen;
        this->m_EdgNum = elen;
        this->m_Vexs = new VNode[this->m_VexNum];
        char c1, c2;
        int p1, p2;
        ENode *node1, *node2;
        // ��ʼ��"�ڽӱ�"�Ķ���
        for(int i=0; i<this->m_VexNum; i++)
        {
                this->m_Vexs[i].data = vexs[i];
                this->m_Vexs[i].firstEdge = nullptr;
        }

        // ��ʼ��"�ڽӱ�"�ı�
        for(int i=0; i<this->m_EdgNum; i++)
        {
                // ��ȡ�ߵ���ʼ����ͽ�������
                c1 = edges[i][0];
                c2 = edges[i][1];

                p1 = getPosition(c1);
                p2 = getPosition(c2);
                // ��ʼ��node2
                node2 = new ENode();
                node2->ivex = p2;
                // ��node2���ӵ�"p1���������ĩβ"
                if(this->m_Vexs[p1].firstEdge == nullptr)
                {
                        this->m_Vexs[p1].firstEdge = node2;
                }
                else
                {
                        //��ͷ�巨���뵽�ڽӱ���
                        ENode* firstnode = this->m_Vexs[p1].firstEdge;
                        node2->nextEdge = firstnode;
                        this->m_Vexs[p1].firstEdge = node2;
                }

                // ��ʼ��node1
                node1 = new ENode();
                node1->ivex = p1;
                // ��node1���ӵ�"p2���������ĩβ"
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
 * ����ch��λ��
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
 * ���������������ͼ�ĵݹ�ʵ��
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
 * ���������������ͼ
 */
void ListUDG::DFS()
{
        int* visited = new int[this->m_VexNum];       // ������ʱ��
        // ��ʼ�����ж��㶼û�б�����
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
 * ����������������������Ĳ�α�����
 */
void ListUDG::BFS()
{
        std::queue<int> queue_Nodes;
        int* visited = new int[this->m_VexNum];   // ������ʱ��
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
 * ��ӡ�ڽӱ�ͼ
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

#ifndef LISTUDG_H
#define LISTUDG_H

#include <iostream>
#include <queue>

class ListUDG
{
    public:
        ListUDG(char vexs[], int vlen, char edges[][2], int elen);// 创建邻接表对应的图(用已提供的数据)
        virtual ~ListUDG();

        // 深度优先搜索遍历图
        void DFS();
        // 广度优先搜索（类似于树的层次遍历）
        void BFS();
        // 打印邻接表图
        void print();


    protected:
        // 返回ch的位置
        int getPosition(char ch);
        // 递归深度遍历
        void DFS(int i, int* visited);

    private:
        // 邻接表中表对应的链表的顶点
        class ENode
        {
            public:
                int ivex;           // 该边所指向的顶点的位置
                ENode *nextEdge;    // 指向下一条弧的指针
        };

        // 邻接表中表的顶点
        class VNode
        {
            public:
                char data;          // 顶点信息
                ENode *firstEdge;   // 指向第一条依附该顶点的弧
        };

        int m_VexNum;             // 图的顶点的数目
        int m_EdgNum;             // 图的边的数目
        VNode* m_Vexs;        // 图的顶点数组
};

#endif // LISTUDG_H

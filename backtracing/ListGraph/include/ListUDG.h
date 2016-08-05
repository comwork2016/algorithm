#ifndef LISTUDG_H
#define LISTUDG_H

#include <iostream>
#include <queue>

class ListUDG
{
    public:
        ListUDG(char vexs[], int vlen, char edges[][2], int elen);// �����ڽӱ��Ӧ��ͼ(�����ṩ������)
        virtual ~ListUDG();

        // ���������������ͼ
        void DFS();
        // ����������������������Ĳ�α�����
        void BFS();
        // ��ӡ�ڽӱ�ͼ
        void print();


    protected:
        // ����ch��λ��
        int getPosition(char ch);
        // �ݹ���ȱ���
        void DFS(int i, int* visited);

    private:
        // �ڽӱ��б��Ӧ������Ķ���
        class ENode
        {
            public:
                int ivex;           // �ñ���ָ��Ķ����λ��
                ENode *nextEdge;    // ָ����һ������ָ��
        };

        // �ڽӱ��б�Ķ���
        class VNode
        {
            public:
                char data;          // ������Ϣ
                ENode *firstEdge;   // ָ���һ�������ö���Ļ�
        };

        int m_VexNum;             // ͼ�Ķ������Ŀ
        int m_EdgNum;             // ͼ�ıߵ���Ŀ
        VNode* m_Vexs;        // ͼ�Ķ�������
};

#endif // LISTUDG_H

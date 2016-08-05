#include <iostream>
#include "ListUDG.h"

using namespace std;

int main()
{

    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'C'},
        {'A', 'D'},
        {'A', 'F'},
        {'B', 'C'},
        {'C', 'D'},
        {'E', 'G'},
        {'F', 'G'}};
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    ListUDG* pG = new ListUDG(vexs, vlen, edges, elen);
    pG->print();   // ��ӡͼ
    pG->DFS();     // ������ȱ���
    pG->BFS();     // ������ȱ���
    return 0;
}


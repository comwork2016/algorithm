/**
����1��n��n������Χ��һ��Բ��������������2�����ڵ�������ӣ������Ϊ��������ô������ͳ�Ϊ��������
��������1��ʼ���
*/

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int M = 40;
int isPrime[M];
/**
    ���1-40�����е�����
*/
void prime()
{
    int i, j;
    for(i=1; i<M; ++i)
    {
        int ok = 1;
        for(j=2; j*j<=i; ++j)
        {
            if(i%j == 0)
            {
                ok = 0;
                break;
            }
        }
        isPrime[i] = ok;
    }
}

void dfs(int cur, int n,int* result,int* visited)
{
    //ֹͣ������cur���������n
    if(cur==n && isPrime[result[n-1]+result[0]])
    {
        //������
        for(int i=0;i<n;i++)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }else
    {
        for(int i=2;i<=n;i++)//���Դ�2��ʼ��ÿһ������
        {
            if(!visited[i] && isPrime[result[cur-1]+i])
            {
                result[cur] = i;
                visited[i] = 1;
                dfs(cur+1,n,result,visited);
                //������ɹ�������ݣ�����־����
                visited[i] = 0;
            }
        }
    }
}

int main()
{
    prime();
    int n;
    int cnt = 0;
    while(cin>>n)
    {
        ++cnt;
        cout<<"Case "<<cnt<<endl;
        int* visited = new int[n+1];
        int* result = new int[n];
        memset(visited, 0, sizeof(int)*(n+1));
        result[0] = 1;
        dfs(1, n,result,visited);
        cout<<endl;
        delete[] result;
        delete[] visited;
    }
    return 0;
}

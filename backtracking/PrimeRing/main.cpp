/**
将从1到n这n个整数围成一个圆环，若其中任意2个相邻的数字相加，结果均为素数，那么这个环就成为素数环。
素数环从1开始输出
*/

#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

const int M = 40;
int isPrime[M];
/**
    求出1-40内所有的素数
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
    //停止条件：cur到达最大数n
    if(cur==n && isPrime[result[n-1]+result[0]])
    {
        //输出结果
        for(int i=0;i<n;i++)
        {
            cout<<result[i]<<" ";
        }
        cout<<endl;
    }else
    {
        for(int i=2;i<=n;i++)//尝试从2开始的每一个数字
        {
            if(!visited[i] && isPrime[result[cur-1]+i])
            {
                result[cur] = i;
                visited[i] = 1;
                dfs(cur+1,n,result,visited);
                //如果不成功，则回溯，将标志重置
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

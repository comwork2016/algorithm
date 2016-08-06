/**
    8皇后问题
    递归和非递归算法
*/

#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

/**
    查看第k行的皇后能不能放在第arr[k]列
*/
bool place(int k,int* arr,int n)
{
    bool b_Place = true;
    for(int i=0; i<k; i++)
    {
        if(arr[k] == arr[i] || abs(arr[k] - arr[i]) == abs(k-i))
        {
            b_Place = false;
            return b_Place;
        }
    }
    return b_Place;
}

void print(int* arr,int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i] == j)
            {
                cout<<"⊙";
            }
            else
            {
                cout<<"▇";
            }
        }
        cout<<endl;
    }
}

/**
    递归形式
*/
void NQueen1(int cur,int* arr,int n,int &count)
{
    if(cur == n)//放满了8个皇后，输出
    {
        count++;
        cout<<endl<<"solution "<<count<<endl;
        print(arr,n);
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            arr[cur] = i;//放置到第i列，再判断
            if(place(cur,arr,n))
            {
                NQueen1(cur+1,arr,n,count);
            }
        }
    }
}

/**
    非递归形式的回溯法
*/
void NQueen2(int* arr,int n,int& count)
{
    int row=0;
    int col=0;
    while(row>=0)//第一行的结果遍历完了
    {
        while(col<n)
        {
            arr[row] = col;
            if(place(row,arr,n))//如果能放置到col列，则继续到下一行
            {
                col = 0;//下一行从第0列开始
                break;
            }
            col++;
        }
        if(col==n)//如果没有可以放置的列，则向上回溯
        {
            if(row == 0)//已经回溯到第一层了，没有结果
            {
                break;
            }
            //将上一行中的皇后向后移一列
            row--;
            col = arr[row]+1;
            continue;
        }
        if(row == n-1)//如果已经是最后一行，则输出结果
        {
            count++;
            cout<<endl<<"solution "<<count<<endl;
            print(arr,n);
        }
        row++;
    }
}

void NQueen(int n)
{
    int* arr = new int[n];
    memset(arr,-1,sizeof(int)*n);
    int count = 0;
    //NQueen1(0,arr,n,count);
    NQueen2(arr,n,count);
    cout<<"solution count:"<<count<<endl;
    delete[] arr;
}

int main()
{
    int n;
    cout << "input number of queen(s):";
    while(cin >> n)
    {
        NQueen(n);
        cout<<endl << "input number of queen(s):";
    }
    return 0;
}

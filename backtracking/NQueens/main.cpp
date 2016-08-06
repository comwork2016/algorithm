/**
    8�ʺ�����
    �ݹ�ͷǵݹ��㷨
*/

#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

/**
    �鿴��k�еĻʺ��ܲ��ܷ��ڵ�arr[k]��
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
                cout<<"��";
            }
            else
            {
                cout<<"�~";
            }
        }
        cout<<endl;
    }
}

/**
    �ݹ���ʽ
*/
void NQueen1(int cur,int* arr,int n,int &count)
{
    if(cur == n)//������8���ʺ����
    {
        count++;
        cout<<endl<<"solution "<<count<<endl;
        print(arr,n);
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            arr[cur] = i;//���õ���i�У����ж�
            if(place(cur,arr,n))
            {
                NQueen1(cur+1,arr,n,count);
            }
        }
    }
}

/**
    �ǵݹ���ʽ�Ļ��ݷ�
*/
void NQueen2(int* arr,int n,int& count)
{
    int row=0;
    int col=0;
    while(row>=0)//��һ�еĽ����������
    {
        while(col<n)
        {
            arr[row] = col;
            if(place(row,arr,n))//����ܷ��õ�col�У����������һ��
            {
                col = 0;//��һ�дӵ�0�п�ʼ
                break;
            }
            col++;
        }
        if(col==n)//���û�п��Է��õ��У������ϻ���
        {
            if(row == 0)//�Ѿ����ݵ���һ���ˣ�û�н��
            {
                break;
            }
            //����һ���еĻʺ������һ��
            row--;
            col = arr[row]+1;
            continue;
        }
        if(row == n-1)//����Ѿ������һ�У���������
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
	int weight;
	int parent,lchild,rchild;
}HNode;

HNode* Huffman(int s[],int n)
{
	int i;
	HNode *ht;
	ht = (HNode*)malloc(2*n*sizeof(HNode));//0号单元不用
	for(i=0;i<n;i++)
	{
		ht[i+1].weight = s[i];
		ht[i+1].parent = 0;
		ht[i+1].lchild = 0;
		ht[i+1].rchild = 0;
	}
	int j;
	for(j=0;j<n-1;j++)//n-1次合并结点
	{
		//寻找权值最小的两个结点
		int min1,min2;
		int p1,p2;
		min1 = min2 = MAX;
		p1 = p2 = -1;
		int k;
		for(k=1;k<=n+j;k++)
		{
			if(ht[k].parent == 0)
			{
				if(ht[k].weight < min1)
				{
					min2 = min1;
					min1 = ht[k].weight;
					p2 = p1;
					p1 = k;
				}
				else if(ht[k].weight < min2)
				{
					min2 = ht[k].weight;
					p2 = k;
				}
			}
		}
		//将两个结点组成一个新的结点
		i++;
		ht[i].lchild = p1;
		ht[i].rchild = p2;
		ht[i].parent = 0;
		ht[i].weight = ht[p1].weight + ht[p2].weight;
		ht[p1].parent = i;
		ht[p2].parent = i;
	}
	return ht;
}

char** HuffmanCode(HNode ht[],int n)
{
	char **codes = (char**)malloc((n+1)*sizeof(char*));
	char *c;
	c = (char*)malloc(n*sizeof(char));
	c[n-1] = '\0';
	int i;
	for(i=1;i<=n;i++)
	{
		int start = n-1;
		int n = i;//当前工作指示区域的指针
		int p = ht[n].parent;
		while(p!=0)
		{
			start--;
			if(ht[p].lchild == n)
			{
				c[start] = '0';
			}
			else if(ht[p].rchild == n)
			{
				c[start] = '1';
			}
			n = p;
			p = ht[n].parent;
		}
		codes[i] = (char*)malloc((n-start)*sizeof(char));
		strcpy(codes[i],&c[start]);
	}
	return codes;
}

void dispCodes(HNode *ht,char **codes,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%2d codes:%s\n",ht[i].weight,codes[i]);
	}
}

int main()
{
	int s[11]={4,3,6,2,1,21,34,23,12,9,7};
	HNode *ht;
	ht = Huffman(s,11);
	char **codes = HuffmanCode(ht,11);
	dispCodes(ht,codes,11);
	return 1;
}

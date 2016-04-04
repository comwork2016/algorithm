#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	float starttime;
	float endtime;
}confer;

void arrangeConfer(confer c[],int YN[],int n);
void sortByEndTime(confer c[],int h,int t);
void dispConfer(confer c[],int YN[],int n);

int main()
{
	confer c[5]={{(float)8.5,(float)9.1},{(float)9.6,(float)16},{(float)15,(float)20},{(float)10,(float)11},{(float)8,(float)9}};
	int YN[5]={0,0,0,0,0};
	sortByEndTime(c,0,4);
	arrangeConfer(c,YN,5);
	dispConfer(c,YN,5);
	return 1;
}

void arrangeConfer(confer c[],int YN[],int n)
{
	int i,last;
	YN[0]=1;
	last = 0;
	for(i=1;i<n;i++)
	{
		if(c[i].starttime>=c[last].endtime)
		{
			YN[i]=1;
			last = i;
		}
	}
}

void sortByEndTime(confer c[],int h,int t)
{
	int i=h;
	int j=t;
	confer temp;
	if(h>=t)
	{
		return;
	}
	temp.starttime = c[i].starttime;
	temp.endtime = c[i].endtime;
	while(i<j)
	{
		while(i<j && temp.endtime<=c[j].endtime)
		{
			j--;
		}
		c[i].starttime = c[j].starttime;
		c[i].endtime = c[j].endtime;
		while(i<j && temp.endtime>c[i].endtime)
		{
			i++;
		}
		c[j].starttime = c[i].starttime;
		c[j].endtime = c[i].endtime;
	}
	c[i].starttime = temp.starttime;
	c[i].endtime = temp.endtime;
	sortByEndTime(c,h,i-1);
	sortByEndTime(c,i+1,t);
}

void dispConfer(confer c[],int YN[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(YN[i])
		{
			printf("confer[%d]\tstarttime:%3f\tendtime:%3f\n",i,c[i].starttime,c[i].endtime);
		}
	}
}


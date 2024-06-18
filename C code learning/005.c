#include<stdio.h>
#include<stdlib.h>
void Random(int a[])
{
	for(int i=0;i<30;i++)
	{
		a[i]=0;//全部赋初值0
	}
	int x;
	for(int i=1;i<30;)
	{
		x=rand()%30;//随机下标
		if(a[x]==0)
		{
			a[x]=i;//为初始值更新
		}
		else
		{
			continue;
		}
		i++;
	}//剩余的下标还是初始值
}
void Print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n");
}
int main()
{
	int a[30];
	for(int n=0;n<5;n++)
	{
		Random(a);
		Print(a,30);
	}
}

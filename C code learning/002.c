#include<stdio.h>
#include<stdlib.h>//包含随机函数的头文件
void Random(int a[],int n)//随机函数 插入随机数
{
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%100;//调用随机函数
	}
}
void Print(int a[],int n)//打印函数
{
	for(int i=0;i<n;i++)
	{
		printf("original random array display %3d\n",a[i]);
		//原随机数组显示
	}
}
void Restrict(int a[],int n)//限制函数
{
	int b[50];//最大值空间
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=60)//限制大小
		{
			b[j]=a[i];
			j++;
		}
	}
	for(int i=0;i<j;i++)
	{
		printf("Numbers greater than 60 are %d\n",b[i]);
		//大于60的数字为
	}
	
}
int main()
{
	int a[50];
	Random(a,50);
	Print(a,50);
	Restrict(a,50);
}

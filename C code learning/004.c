/*生成一个从小到大的抽奖的程序*/
#include<stdio.h>
#include<stdlib.h>
void BubbleSort(int *a,int n)
{
    int i,j;
    int temp;
    for(i=n-1;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void BubbleSort1(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				int temp;
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
void Print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%02d ",a[i]);//个位数前置0
	}
	printf("\b-The winning number is %02d\n",rand()%(16)+1);//中奖的数字为
}
int Random1(int a[],int x,int n)
{
	for(int i=0;i<=n;i++)
	{
		if(x==a[i])//否定系统随机值
		{
			return 1;
		}
	}
	return 0;
}
void Random(int a[],int n)
{
	int x;
	for(int i=0;i<n;i++)
	{
		while(Random1(a,x=rand()%33+1,i)==1);//随机生成x 返回值为1时刷新x
		a[i]=x;//确定随机值x
	}
	BubbleSort(a,n);//冒泡排序函数
}
int main()
{
	int a[6];
	for(int i=0;i<10;i++)
	{
		Random(a,6);
		Print(a,6);
	}
}

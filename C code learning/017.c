#include<stdio.h>
int Minimum(int a[],int n)//最小数
{
	int min;
	if(n==1)
	{
		return a[0];
	}
	min=Minimum(a+1,n-1);
	if(a[0]>min)//与每次递归时的第一个数比较
	{
		return min;
	}
	return a[0];
}
int Greatest_Common_Divisor(int a[],int n)
{
	int i;
	int min=Minimum(a,n);
	while(min)
	{
		for(i=0;i<n;i++)
		{
			if(a[i]%min!=0)
			{
				break;
			}
		}
		if(i==n)//满循环返回否则min递减
		{
			return min;
		}
		min--;
	}
}
int main()
{
	int a[]={36,12,18,24};
	printf("%d",Greatest_Common_Divisor(a,4));
}

#include<stdio.h>
int Greatest_Common_Divisor(int a,int b)
{
	int min;
	min=a>b?b:a;//找出最小值
	while(min)
	{
		if(a%min==0&&b%min==0)//满足条件后返回值
		{
			return min;
		}
		min--;
	}
}
int Greatest_Common_Divisor1(int a,int b)
{
	int start=1;//起始值递增查找
	int temp;
	while(start<=a&&start<=b)
	{
		if(a%start==0&&b%start==0)
		{
			temp=start;//缓存
		}
		start++;
	}
	return temp;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",Greatest_Common_Divisor1(a,b));
}

#include<stdio.h>
float sumfun(int n)
{
	if(n==1)//递归出口
	{
		return 1.0;
	}
	int flag;
	if(n%2==1)//奇数正，偶数负
	{
		flag=1;
	}
	else
	{
		flag=-flag;
	}
	return sumfun(n-1)+flag*1.0/n;//递归入口 回溯时累加返回
}
int main()
{
	printf("%f",sumfun(2));
}

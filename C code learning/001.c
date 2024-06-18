#include<stdio.h>//求某个数的阶乘
int Stratum(int n)
{
	if(n==1||n==0) return 1;
	return Stratum(n-1)*n;//回溯时相乘
}
int Stratum1(int n)
{
	int s=1;
	for(int i=1;i<=n;i++)
	{
		s=s*i;
	}
	return s;
}
int Stratum2(int n)
{
	int s=1;
	int i=2;
	while(i<=n)
	{
		s=s*i;
		i++;
	}
	return s;
}
int main()
{
	printf("%d",Stratum(3));
}

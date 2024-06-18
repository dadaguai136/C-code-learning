#include<stdio.h>
int Prime_Numbers(int n)
{
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	printf("To split a number into the sum of two prime numbers\n");
	int n;
	int s;
	scanf("%d",&n);
	printf("%d=",n);
	for(int i=2;i<n;i++)//从最小的素数二开始
	{
		if(Prime_Numbers(i))
		{
			s=n-i;
			if(Prime_Numbers(s))//判断差值是否为素数
			{
				printf("%d+%d",i,s);
				break;
			}
		}
	}
}

#include<stdio.h>
int Fun(int n)
{
	printf("%d=",n);
	int i;
	for(i=2;i<n; )
	{
		if(n%i==0)
		{
			printf("%d*",i);
			n=n/i;
			continue;
		}
		i++;
	}
	printf("%d\n",i);
}
int Fun1(int n)
{
	printf("%d=",n);
	for(int i=2;i<n;i++)
	{
		while(n%i==0&&i<n)
		{
			printf("%d*",i);
			n=n/i;
		}
	}
	printf("%d\n",n);
}
int Fun2(int n)
{
	int i=2;
	while(n%i!=0)
	{
		i++;
	}
	if(n==i)
	{
		printf("%d",n);
		return 1;
	}
	printf("%d*",i);
	Fun2(n/i);
}
int main()
{
	int n=90;
	Fun2(n);
}

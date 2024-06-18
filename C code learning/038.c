#include<stdio.h>
int Determined_Value(long n,int i)
{
	if(n%1000==i)
	{
		return 1;
	}
	while(n)
	{
		if(n/10%1000==i)
		{
			return 1;
		}
		n/=10;
	}
	return 0;
}
int Data(long n)
{
	for(int i=999;i>100;i--)
	{
		if(Determined_Value(n,i))
		{
			return i;
		}
	}
	return 0;
}
int Recursion(long n)
{
	if(n<100)
	{
		return 0;
	}
	int m=Recursion(n/10);
	if(m>n%1000)
	{
		return m;
	}
	return n%1000;
}
int main()
{
	printf("Maximum three digits of the input number\n");
	long n;
	scanf("%ld",&n);
	printf("%d",Recursion(n));
}

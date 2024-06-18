#include<stdio.h>
long Recursion(int n)
{
	long pre;
	int cur;
	if(n<10)
	{
		return n;
	}
	pre=Recursion(n/10);
	cur=pre%10;
	return (pre/10*10+n%10)*10+cur;
}
/*
long Recursion(long 12)
{
	long pre;
	int cur;
	if(12<10)
	{
		return 12;
	}
	pre=fun(12/10);
}
long Recursion(long 1)
{
	long pre;
	int cur;
	if(1<10)
	{
		return 1;
	}
}
long Recursion(long 12)
{
	long pre;
	int cur;
	if(12<10)
	{
		return 12;
	}
	pre=12;
	cur=1%10;
	return (1/10*10+12%10)*10+1;
}
*/
int main()
{
	printf("First digit followed by\n");
	long n;
	scanf("%ld",&n);
	printf("%ld\n",n=Recursion(n));
}

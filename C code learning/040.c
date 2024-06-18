#include<stdio.h>
long Even_number_first(long pre,int cur)
{
	long n=pre,flag=1;
	while(n&&n%10%2==1)
	{
		flag=flag*10;
		n=n/10;
	}
	return (n*10+cur)*flag+pre%flag;
}
long Recursion(long n)
{
	long pre;
	if(n<10)
	{
		return n;
	}
	pre=Recursion(n/10);
	if(n%10%2==1)
	{
		return pre*10+n%10;
	}
	return Even_number_first(pre,n%10);
}
int main()
{
	printf("Sort by Even Before Odd After\n");
	long n;
	scanf("%ld",&n);
	printf("%ld",Recursion(n));
}

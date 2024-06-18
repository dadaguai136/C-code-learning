#include<stdio.h>
long Sort(long ahead,int back)
{
	long front=ahead;
	long flag=1;
	while(front%10>back&&front)
	{
		flag=flag*10;
		front=front/10;
	}
	return (front*10+back)*flag+ahead%flag;
}
long Argument(long n)
{
	long m;
	if(n<10)
	{
		return n;
	}
	m=Argument(n/10);
	return Sort(m,n%10);
}
int main()
{
	printf("Enter digits to sort in place\n");
	long n;
	scanf("%ld",&n);
	printf("%ld",Argument(n));
}

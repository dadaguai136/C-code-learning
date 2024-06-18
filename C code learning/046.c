#include<stdio.h>
int Calculate(int m,int n)
{
	int s=1;
	for(int i=1;i<=n;i++)
	{
		s=s*m%1000;
	}
	return s;
}
int main()
{
	printf("The last three digits of the nth power of m\n");
	printf("%d",Calculate(11,11));
}

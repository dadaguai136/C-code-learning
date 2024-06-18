#include<stdio.h>
int Sum(int n)
{
	int s=0;
	while(n)
	{
		s=s+n%10;
		n/=10;
	}
	return s;
}
int main()
{
	printf("A number with a sum of 15\n");
	for(int n=10;n<1000;n++)
	{
		if(Sum(n)==15)
		{
			printf("%d\n",n);
		}
	}
}

#include<stdio.h>
int Sequential_Number(long n)
{
	if(n<10)
	{
		return 1;
	}
	if(n/10%10-1==n%10&&Sequential_Number(n/10))
	{
		return 1;
	}
	return 0;
}
int main()
{
	for(long n=100;n<10000000;n++)
	{
		if(Sequential_Number(n))
		{
			printf("%ld\n",n);
		}
	}
}

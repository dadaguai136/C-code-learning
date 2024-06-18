#include<stdio.h>
int Narcissus_Number(int n)
{
	int a,b,c;
	a=n/100;
	b=n/10%10;
	c=n%10;
	if(a*a*a+b*b*b+c*c*c==n)
	{
		return 1;
	}
	return 0;
}
int main()
{
	for(int n=100;n<1000;n++)
	{
		if(Narcissus_Number(n))
		{
			printf("%d\n",n);
		}
	}
}

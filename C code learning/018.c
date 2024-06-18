#include<stdio.h>
int Sequential_Number(int n)
{
	int a=n/100,b=n/10%10,c=n%10;
	if(a+1==b&&b+1==c)
	{
		return 1;
	}
	return 0;
}
int Sequential_Number1(int n)
{
	int final=n%10;
	n=n/10;
	while(n)
	{
		if(n%10+1!=final)
		{
			return 0;
		}
		final=n%10;//Ë¢ĞÂÖµ
		n/=10;
	}
	return 1;
}
int main()
{
	for(int n=100;n<2000;n++)
	{
		if(Sequential_Number1(n))
		{
			printf("%5d",n);
		}
	}
}

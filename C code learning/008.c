#include<stdio.h>
#include<math.h>
int Prime_Number(int n)//½ÏÂı
{
	for(int i=2;i<n;i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int Prime_Number1(int n)//½Ï¿ì
{
	for(int i=2;i<sqrt(n);i++)
	{
		if(n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	for(int n=3;n<100;n++)
	{
		if(Prime_Number(n))
		{
			printf("%3d",n);
		}
	}
}

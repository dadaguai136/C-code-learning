#include<stdio.h>
int Divide_The_Fish(int n)
{
	int x=1;
	for(int i=0;i<n-1;i++)
	{
		x=(x+1)*2;
	}
	return x;
}
int Divide_The_Fish1(int n)
{
	for(int x=3; ;x++)
	{
		int m=x;
		for(int i=0;i<n-1;i++)
		{
			m=m/2-1;
		}
		if(m==1)
		{
			return x;
		}
	}
}
int Divide_The_Fish2(int n)
{
	if(n==1)
	{
		return 1;
	}
	return (Divide_The_Fish(n-1)+1)*2;
}
int main()
{
	printf("%d",Divide_The_Fish2(3));
}

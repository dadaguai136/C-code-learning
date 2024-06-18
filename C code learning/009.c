#include<stdio.h>
#include<stdlib.h>
void Random(int a[],int n)
{
	int x;
	for(int i=1;i<=n;)
	{
		x=rand()%33;
		if(a[x]==0)
		{
			a[x]=i;
		}
		else
		{
			continue;
		}
		i++;
	}
}
void Print(int a[])
{
	for(int *p=a;p<a+33;p++)
	{
		if(*p)
		{
			printf("%5d",*p);
		}
	}
}
int main()
{
	int a[33]={0};
	Random(a,33);
	Print(a);
}

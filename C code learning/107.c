#include<stdio.h>
#define M 6
void Martrix(int a[][M],int n)
{
	int (*p)[M],*q;
	int (*h)[M],k=1;
	for(q=*a;q<*a+n;q++)
	{
		h=(int(*)[M])q;
		if((q-*a)%2==0)
		{
			for(p=h;p<h+n;p++)
			{
				**p=k++;
			}
		}
		else
		{
			for(p=h+n-1;p>=a;p--)
			{
				**p=k++;
			}
		}
	}
}
void Print(int a[][M],int n)
{
	int (*p)[M],*q;
	for(p=a;p<a+n;p++,printf("\n"))
	{
		for(q=*p;q<*p+n;q++)
		{
			printf("%3d",*q);
		}
	}
}
int main()
{
	int a[M][M];
	Martrix(a,M);
	Print(a,M);
}

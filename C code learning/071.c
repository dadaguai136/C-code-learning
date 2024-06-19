#include<stdio.h>
#include"print.h"
void Assignment(int array[],int ret[],int n)
{
	for(int *p=array;p<array+n;p++)
	{
		*ret++=*p;
	}
}
int Recursion(int a[],int b[],int c[],int n,int n1)
{
	if(n==0&&n1==0)
	{
		return 0;
	}
	if(n==0)
	{
		Assignment(b,c,n1);
	}
	if(n1==0)
	{
		Assignment(a,c,n);
	}
	if(*a<*b)
	{
		*c=*a;
		Recursion(a+1,b,c+1,n-1,n1);
	}
	else
	{
		*c=*b;
		Recursion(a,b+1,c+1,n,n1-1);
	}
}
int main()
{
	int a[]={1,3,5,7,9};
	int b[]={2,4,6,8,10};
	int c[10];
	Recursion(a,b,c,5,5);
	Int_Print(c,10);
}

#include<stdio.h>
void Print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n");
}
int Position(int a[],int n)
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+a[i];
		if(sum==n)
		{
			return i+1;
		}
	}
	return 0;
}
void Recursion(int a[],int k,int m,int n)
{
	int x;
	if(m<=0)
	{
		if(x=Position(a,n))
		{
			Print(a,x);
		}
		return;
	}
	for(int i=1;i<=10;i++)
	{
		a[k]=i;
		Recursion(a,k+1,m-i,n);
	}
}
int main()
{
	int a[10]={0};
	Recursion(a,0,10,10);
}

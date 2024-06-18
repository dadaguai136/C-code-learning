#include<stdio.h>
int Fibonacci_Sequence(int a[],int n)
{
	for(int i=2;i<n;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
}
int Fibonacci_Sequence1(int *a,int n)
{
	for(int *p=a+2;p<a+n;p++)
	{
		*p=*(p-1)+*(p-2);
	}
}
int main()
{
	int a[10]={1,1};
	Fibonacci_Sequence1(a,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
}

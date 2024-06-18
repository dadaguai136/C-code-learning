#include<stdio.h>
int Max_Number(int a[],int n)
{
	int max=a[0];
	for(int i=1;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	return max;
}
int Max_Number1(int a[],int n)
{
	int k=0;
	for(int i=1;i<n;i++)
	{
		if(a[k]<a[i])
		{
			k=i;
		}
	}
	return a[k];
}
int Max_Number2(int a[],int n)
{
	int *p,*max;
	p=max=a;
	for(p=a;p<a+n;p++)
	{
		if(*max<*p)
		{
			max=p;
		}
	}
	return *max;
}
int Max_Number3(int a[],int n)
{
	int m;
	if(n<=1)
	{
		return *a;
	}
	m=Max_Number3(a+1,n-1);
	if(*a>m)
	{
		return *a;
	}
	return m;
}
int *Max_Number4(int a[],int n)
{
	int *m;
	if(n<=1)
	{
		return a;
	}
	m=Max_Number4(a+1,n-1);
	if(*a>*m)
	{
		return a;
	}
	return m;
}
int main()
{
	int a[]={1,2,3,14,6,0};
	printf("%3d",*Max_Number4(a,6));
}

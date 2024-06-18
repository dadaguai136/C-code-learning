#include<stdio.h>
int Lookup(int a[],int n,int x)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			return 1;
		}
	}
	return 0;
}
int Lookup1(int a[],int n,int x)
{
	int i,j,mid;
	i=0;
	j=n-1;
	mid=(i+j)/2;
	while(i<=j)
	{
		if(a[mid]==x)
		{
			return 1;
		}
		if(a[mid]<x)
		{
			i=mid+1;
		}
		else
		{
			j=mid-1;	
		}
		mid=(i+j)/2;
	}
	return 0;
}
int Lookup2(int a[],int n,int x)
{
	int *p,*q,*mid;
	p=a;
	q=a+n-1;
	mid=p+(q-p)/2;
	while(p<=q)
	{
		if(*mid==x)
		{
			return 1;
		}
		if(*mid<x)
		{
			p=mid+1;
		}
		else
		{
			q=mid-1;
		}
		mid=p+(q-p)/2;
	}
	return 0;
}
int Lookup3(int a[],int i,int j,int x)
{
	int mid;
	if(i>j)
	{
		return 0;
	}
	mid=(i+j)/2;
	if(a[mid]==x)
	{
		return 1;
	}
	if(a[mid]<x)
	{
		Lookup3(a,mid+1,j,x);
	}
	else
	{
		Lookup3(a,i,mid-1,x);
	}
}
int Lookup4(int a[],int n,int x)
{
	int mid;
	if(n<1)
	{
		return 0;
	}
	mid=(n-1)/2;
	if(*(a+mid)==x)
	{
		return 1;
	}
	if(*(a+mid)<x)
	{
		Lookup4(a+mid+1,n-mid-1,x);
	}
	else
	{
		Lookup4(a,mid,x);
	}
}
int main()
{
	printf("Find numbers in an ascending array\n");
	int a[]={1,2,3,4,5,6,7,8,9};
	int n;
	scanf("%d",&n);
	if(Lookup4(a,sizeof(a)/4,n))
	{
		printf("Find");
	}
	else
	{
		printf("No find");
	}
}

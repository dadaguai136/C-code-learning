#include<stdio.h>
#include"Print.h"
int Delete(int a[],int n,int x)
{
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]!=x)
		{
			a[j++]=a[i];
		}
	}
	return j;
}
int Delete1(int *a,int n,int x)
{
	int *q=a;
	for(int *p=a;p<a+n;p++)
	{
		if(*p!=x)
		{
			*q++=*p;
		}
	}
	return q-a;
}
int Delete2(int a[],int n,int x)
{
	int m,t;
	if(n<1)
	{
		return 0;
	}
	m=Delete2(a+1,n-1,x);
	if(*a==x)
	{
		t=*a,
		*a=*(a+m);
		*(a+m)=t;
		return m;
	}
	return m+1;
}
/*1 1 1 2 2 2 1 1 12 2
1 1 1 2 2 12 1 1 2 2
1 1 1 2 1 12 1 2 2 2
1 1 1 1 1 12 2 2 2 2*/
int main()
{
	printf("Delete input numbers\n");
	int a[]={1,2,3,2,2,2,6,7,8,3,24,6,2,76};
	int n;
	scanf("%d",&n);
	n=Delete2(a,sizeof(a)/4,n);
	printf("%d\n",n);
	Int_Print(a,n);
}

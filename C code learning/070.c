#include<stdio.h>
#include"print.h"
#include<malloc.h>
int *Sort(int a[],int b[],int n,int n1)
{
	int *p;
	int i,j,k;
	i=j=k=0;
	p=(int *)malloc(sizeof(int)*(n+n1));
	while(i<n&&j<n1)
	{
		if(a[i]<b[j])
		{
			p[k++]=a[i++];
		}
		else
		{
			p[k++]=b[j++];
		}
	}
	if(i==n)
	{
		while(j<n1)
		{
			p[k++]=b[j++];
		}
	}
	if(j==n1)
	{
		while(i<n)
		{
			p[k++]=a[i++];
		}
	}
	return p;
}
int main()
{
	printf("Merge two ascending arrays\n");
	int a[]={1,3,5,7},b[]={2,4,6,8};
	int *p;
	p=Sort(a,b,4,4);
	Int_Print(p,8);
}

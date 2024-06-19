#include<stdio.h>
#include"print.h"
int Sort(int a[],int n)
{
	int t;
	int i=n-2;
	t=a[n-1];
	while(i>=0&&t<=a[i])
	{
		a[i+1]=a[i];
		i--;
	}
	a[i+1]=t;
}
int Sort1(int a[],int n)
{
	int i;
	i=0;
	int t;
	t=a[n-1];
	while(i<n-1&&a[i]<t)
	{
		i++;
	}
	int j=n-1;
	while(j>i)
	{
		a[j]=a[j-1];
		j--;
	}
	a[j]=t;
}
int main()
{
	printf("Insertion sorting\n");
	int a[6]={1,3,5,7,9};
	scanf("%d",a+5);
	Sort1(a,6);
	Int_Print(a,6);
}

#include<stdio.h>
#include"print.h"
void Recursion(int a[],int n)
{
	if(n<2)
	{
		return;
	}
	int i,t;
	Recursion(a,n-1);
	i=n-2;
	t=a[n-1];
	while(i>=0&&t<a[i])
	{
		a[i+1]=a[i];
		i--;
	}
	a[i+1]=t;
}
void Recursion1(int a[],int n)
{
	if(n<2)
	{
		return;
	}
	int *p=a,t;
	Recursion1(a+1,n-1);
	while(p<a+n-1&&*p>*(p+1))
	{
		t=*p;
		*p=*(p+1);
		*(p+1)=t;
		p++;
	}
}
int main()
{
	printf("Recursive sorting\n");
	int a[]={1,11,5,7,9,13,0};
	Recursion1(a,7);
	Int_Print(a,7);
}

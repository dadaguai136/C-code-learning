#include<stdio.h>
#include"Print.h"
void Recursion(int a[],int n)
{
	int t;
	if(n<2)
	{
		return;
	}
	Recursion(a+1,n-1);
	t=*a;
	*a=*(a+1);
	*(a+1)=t;
}
int main()
{
	int a[]={1,2,3,4,5,6};
	Recursion(a,6);
	Int_Print(a,6);
}

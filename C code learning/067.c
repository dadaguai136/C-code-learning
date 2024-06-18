#include<stdio.h>
#include"print.h"
void Sort(int a[],int n)
{
	int i=n-1;
	int t;
	while(i>0&&a[i]<a[i-1])
	{
		t=a[i];
		a[i]=a[i-1];
		a[i-1]=t;
		i--;
	}
}
int main()
{
	int a[6]={1,3,5,7,9};
	scanf("%d",&a[5]);
	Sort(a,6);
	Int_Print(a,6);
}

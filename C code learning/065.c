#include<stdio.h>
#include"print.h"
int Formula(int a[],int n)
{
	int m;
	for(int i=2;i<n;i++)
	{
		m=a[i-1]*a[i-2];
		if(m>=10)
		{
			a[i]=m/10;
			a[i+1]=m%10;
			i++;
		}
		else
		{
			a[i]=m;
		}
	}
}
int Formula1(int *a,int n)
{
	int m;
	for(int *p=a+2;p<a+n;p++)
	{
		m=*(p-1)**(p-2);
		if(m>=10)
		{
			*p=m/10;
			p++;
			*p=m%10;
		}
		else
		{
			*p=m;
		}
	}
}
int main()
{
	int a[15]={3,6};
	Formula(a,sizeof(a)/4);
	Int_Print(a,sizeof(a)/4);
}

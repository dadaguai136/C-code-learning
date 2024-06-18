#include<stdio.h>
#include"print.h"
void Recursion(int a[],int n)
{
	int *p=a;
	int t;
	if(n==1)
	{
		return ;
	}
	Recursion(a+1,n-1);
	if(*a%2==1)
	{
		return ;
	}
	while(*(p+1)%2==1&&p<a+n)
	{
		t=*p;
		*p=*(p+1);
		*(p+1)=t;
		p++;
	}
}
void Sort(int a[],int n)
{
	int t;
	int *q;
	for(int *p=a;p<a+n-1;p++)
	{
		if(*p%2==0)
		{
			for(q=p+1;q<a+n;q++)
			{
				if(*q%2==1)
				{
					t=*p;
					*p=*q;
					*q=t;
					break;
				}
			}
			if(q==a+n)
			{
				return ;
			}
		}
	}
}
int main()
{
	printf("The integers in the array are sorted by odd,even,and last\n");
	int a[]={3,45,76,8,0,21,1,2,6,8,33,3};
	Sort(a,sizeof(a)/4);
	Int_Print(a,sizeof(a)/4);
}

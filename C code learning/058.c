#include<stdio.h>
#include"Print.h"
void Character(int a[],int n)
{
	int i=0,j=n-1;
	int t;
	while(i<j)
	{
		t=a[i];
		a[i]=a[j];
		a[j]=t;
		i++;
		j--;
	}
}
void Character1(int a[],int n)
{
	int *p=a+n-1;
	int t;
	while(a<p)
	{
		t=*a;
		*a=*p;
		*p=t;
		a++;
		p--;
	}
}
void Character2(int a[],int n)
{
	if(n<=1)
	{
		return;
	}
	char t;
	Character2(a+1,n-2);
	t=*a;
	*a=*(a+n-1);
	*(a+n-1)=t;
}
void Character3(int a[],int n)
{
	if(n<=1)
	{
		return;
	}
	int t,*p;
	Character3(a+1,n-1);
	t=*a;
	p=a;
	while(p<a+n-1)
	{
		*p=*(p+1);
		p++;
	}
	*p=t;
}
int main()
{
	printf("Character inversion in character array\n");
	int a[]={1,2,3,4,5,6};
	Character3(a,6);
	Int_Print(a,6);
}

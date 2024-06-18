#include<stdio.h>
int Move(int a[],int n)
{
	int t;
	int i;
	t=a[0];
	for(i=0;i<n-1;i++)
	{
		a[i]=a[i+1];
	}
	a[i]=t;
}
void Print(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%3d",a[i]);
	}
}
int Move1(int *a,int n)
{
	int t,*p;
	t=*a;
	for(p=a;p<a+n-1;p++)
	{
		*p=*(p+1);
	}
	*p=t;
}
void Print1(int *a,int n)
{
	for(int *p=a;p<a+n;p++)
	{
		printf("%3d",*p);
	}
}
int main()
{
	printf("Place the first number in the array at the tail\n");
	int a[]={1,2,3,4,5};
	Move1(a,5);
	Print1(a,5);
}

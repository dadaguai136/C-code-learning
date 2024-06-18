#include<stdio.h>
void Calculate(int a[],int n)
{
	int *p=a+n-1;
	int t=*p;
	while(p>a)
	{
		*p=*(p-1);
		p--;
	}
	*p=t;
}
void Print(int a[],int n)
{
	for(int *p=a;p<a+n;p++)
	{
		printf("%3d",*p);
	}
}
int main()
{
	printf("Leading trailing digits\n");
	int a[]={1,2,3,4,5,6};
	Calculate(a,6);
	Print(a,6);
}

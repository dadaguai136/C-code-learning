#include<stdio.h>
void Recursion(int a[],int n)
{
	int t;
	if(n<2)
	{
		return;
	}
	Recursion(a+1,n-1);
	t=*a;
	*a=*(a+n-1);
	*(a+n-1)=t;
}
void PrintRecursion(int a[],int n)
{
	if(n<2)
	{
		printf("%3d",*a);
		return;
	}
	printf("%3d",*a);
	PrintRecursion(a+1,n-1);
}
int main()
{
	printf("Place the first number in the arry at the tail\n");
	int a[]={1,2,3,4,5,6};
	Recursion(a,6);
	PrintRecursion(a,6);
}

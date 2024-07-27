#include<stdio.h>
int Max(int a,int b)
{
	return a>b?a:b;
}
int Add(int a,int b)
{
	return a+b;
}
int Function(int a,int b,int (*p)(int ,int))
{
	return p(a,b);
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",Function(a,b,Add));
}

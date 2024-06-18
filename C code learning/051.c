#include<stdio.h>
int Space(int *a,int n)
{
	printf("%d",sizeof(a));
}
int main()
{
	int a[]={1,2,3,4,5,6};
	printf("%d\n",sizeof(a));
	Space(a,6);
}

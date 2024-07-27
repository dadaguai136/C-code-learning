#include<stdio.h>
int main()
{
	int b[3]={1,2,3};
	int *a[3]={b,b+1,b+2};
	for(int i=0;i<3;i++)
	{
		printf("%d",*a[i]);
	}
}

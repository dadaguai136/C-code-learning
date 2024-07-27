#include<stdio.h>
#include<stdlib.h>
void Triangle(int n)
{
	int **p,*q,**a;
	a=(int **)malloc(sizeof(int *)*n);
	for(p=a;p<a+n;p++)
	{
		*p=(int *)malloc(sizeof(int)*(p-a+1));
	}
	for(p=a;p<a+n;p++,printf("\n"))
	{
		for(q=*p;q<=*p+(p-a);q++)
		{
			if(q-*p==0||q-*p==p-a)
			{
				*q=1;
			}
			else
			{
				*q=*(*(p-1)+(q-*p))+*(*(p-1)+(q-*p-1));
			}
			printf("%3d",*q);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	Triangle(n);
}

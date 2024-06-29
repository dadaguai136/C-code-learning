#include<stdio.h>
#define M 3
int Sore(int a[][M],int i,int j,int n)
{
	int k;
	for(k=0;k<n;k++)
	{
		if(a[i][k]>a[i][j])
		{
			return 0;
		}
	}
	for(k=0;k<n;k++)
	{
		if(a[k][j]<a[i][j])
		{
			return 0;
		}
	}
	return 1;
}
int Sore1(int a[][M],int i,int j,int n)
{
	int (*p)[M],*q;
	p=a+i;
	for(q=*p;q<*p+n;q++)
	{
		if(*q>*(*(a+i)+j))
		{
			return 0;
		}
	}
	p=(int (*)[M])(*a+j);
	while(p<a+n)
	{
		if(**p<*(*(a+i)+j))
		{
			return 0;
		}
		p++;
	}
	return 1;
}
int main()
{
	int a[][M]={1,2,3,4,5,6,7,8,9};
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(Sore1(a,i,j,M))
			{
				printf("%d:(%d,%d)",a[i][j],i+1,j+1);
			}
		}
	}
}

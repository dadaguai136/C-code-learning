#include<stdio.h>
#define M 7
void Matrix(int a[][M],int k,int n)
{
	if(n<=0)
	{
		return;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0||j==0||i==n-1||j==n-1)
			{
				a[i][j]=k;
			}
		}
	}
	Matrix(*(a+1)+1,k+1,n-2);	
}
int main()
{
	int a[M][M]={0};
	Matrix(a,1,M);
	for(int i=0;i<M;i++,printf("\n"))
	{
		for(int j=0;j<M;j++)
		{
			printf("%3d",a[i][j]);
		}
	}
}

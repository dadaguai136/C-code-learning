#include<stdio.h>
#define M 6
void Spiral_Matrix(int a[][M],int k,int n)
{
	int i;
	if(n<=0)
	{
		return;
	}
	for(i=0;i<n;i++)
	{
		a[i][0]=k++;
	}
	for(i=1;i<n;i++)
	{
		a[n-1][i]=k++;
	}
	for(i=n-2;i>=0;i--)
	{
		a[i][n-1]=k++;
	}
	for(i=n-2;i>0;i--)
	{
		a[0][i]=k++;
	}
	Spiral_Matrix(*(a+1)+1,k,n-2);
}
void Spiral_Matrix1(int a[][M],int k,int n)
{
	int i;
	if(n<=0)
	{
		return;
	}
	for(i=0;i<n;i++)
	{
		a[0][i]=k++;
	}
	for(i=1;i<n;i++)
	{
		a[i][n-1]=k++;
	}
	for(i=n-2;i>=0;i--)
	{
		a[n-1][i]=k++;
	}
	for(i=n-2;i>0;i--)
	{
		a[i][0]=k++;
	}
	Spiral_Matrix1(*(a+1)+1,k,n-2);
}
int main()
{
	int a[M][M]={0};
	Spiral_Matrix1(a,1,M);
	for(int i=0;i<M;i++,printf("\n"))
	{
		for(int j=0;j<M;j++)
		{
			printf("%4d",a[i][j]);
		}
	}
}

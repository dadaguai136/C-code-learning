#include<stdio.h>
#define M 5
void Matrix(int a[][M],int n)
{
	int t;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			t=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=t;
		}
	}
}
void Matrix1(int a[][M],int n)
{
	int k=n/2;
	int t;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
		{
			t=a[i][j];
			a[i][j]=a[n-1-i][j];
			a[n-1-i][j]=t;
		}
	}
}
void Matrix2(int a[][M],int n)
{
	int k=n/2;
	int t;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			t=a[i][j];
			a[i][j]=a[i][n-1-j];
			a[i][n-1-j]=t;
		}
	}
}
void Matrix3(int a[][M],int n)
{
	int k=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=k++;
		}
	}
}
void Print(int a[][M],int n)
{
	for(int i=0;i<n;i++,printf("\n"))
	{
		for(int j=0;j<n;j++)
		{
			printf("%3d",a[i][j]);
		}
	}
}
int main()
{
	int a[M][M];
	Matrix3(a,M);
	Print(a,M);
	printf("---------------\n");
	Matrix1(a,M);
	Print(a,M);
	printf("---------------\n");
	Matrix2(a,M);
	Print(a,M);
	printf("----------------\n");
	Matrix(a,M);
	Print(a,M);
}

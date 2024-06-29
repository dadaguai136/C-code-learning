#include<stdio.h>
#define M 5
void Martrix(int a[][M],int n)
{
	int i;
	int k=1;
	for(int j=0;j<n;j++)
	{
		if(j%2==0)
		{
			for(i=0;i<n;i++)
			{
				a[i][j]=k++;
			}
		}
		else
		{
			for(i=n-1;i>=0;i--)
			{
				a[i][j]=k++;
			}
		}
	}
}
void Print(int a[][M],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int a[M][M]={0};
	Martrix(a,M);
	Print(a,M);
}

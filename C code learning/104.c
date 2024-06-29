#include<stdio.h>
#define M 5
void Matrix(int a[][M],int n)
{
	int i,j,k,s=1;
	k=0;
	while(k<2*n-1)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i+j==k)
				{
					if((i+j)%2==1)
					{
						a[j][i]=s++;
					}
					else
					{
						a[i][j]=s++;
					}
				}
			}
		}
		k++;
	}
}
int main()
{
	int a[M][M]={0};
	Matrix(a,M);
	for(int i=0;i<M;i++,printf("\n"))
	{
		for(int j=0;j<M;j++)
		{
			printf("%3d",a[i][j]);
		}
	}
}

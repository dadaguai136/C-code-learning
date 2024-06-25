#include<stdio.h>
#include<malloc.h>
int **Triangle(int **a,int n)
{
	a=(int **)malloc(sizeof(int *)*n);
	int i,j;
	for(i=0;i<n;i++)
	{
		a[i]=(int *)malloc(sizeof(int)*(i+1));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j==0||i==j)
			{
				a[i][j]=1;
			}
			else
			{
				a[i][j]=a[i-1][j]+a[i-1][j-1];
			}
		}
	}
	return a;
}
int main()
{
	printf("Yang Hui Triangle\n");
	int **a;
	a=Triangle(a,10);
	for(int i=0;i<10;i++,printf("\n"))
	{
		for(int j=0;j<=i;j++)
		{
			printf("%5d",a[i][j]);
		}
	}
}

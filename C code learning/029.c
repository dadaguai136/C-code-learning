#include<stdio.h>
void Fun(int n)
{
	int m=n*n*n;
	printf("%d*%d*%d=",n,n,n);
	int k,s;
	for(int i=1; ;i+=2)
	{
		k=i;
		s=0;
		for(int j=0;j<n;j++)
		{
			s=s+k;
			k=k+2;
		}
		if(s==m)
		{
			k=i;
			for(int j=0;j<n-1;j++,k+=2)
			{
				printf("%d+",k);
			}
			printf("%d",k);
			break;
		}
	}
	printf("\n");
}
int main()
{
	printf("The cube of a number is equal to several odd numbers want to add\n");
	for(int n=2;n<10;n++)
	{
		Fun(n);
	}
}

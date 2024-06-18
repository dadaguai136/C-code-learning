#include<stdio.h>
int Fun(int i,int j)
{
	if(j==0||i==j)
	{
		return 1;
	}
	return Fun(i-1,j)+Fun(i-1,j-1);
}
int main()
{
	printf("Symmetric Yang Hui triangle\n");
	for(int i=0;i<9;i++,printf("\n"))
	{
		for(int j=0;j<=i;j++)
		{
			printf("%3d",Fun(i,j));
		}
	}
	for(int i=7;i>=0;i--,printf("\n"))
	{
		for(int j=0;j<=i;j++)
		{
			printf("%3d",Fun(i,j));
		}
	}
}

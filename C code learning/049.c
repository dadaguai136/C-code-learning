#include<stdio.h>
int Traitor(int a[],int n)
{
	int m=n;
	int i,k=0;
	for(i=0;m>1;i++)
	{
		if(i==n)
		{
			i=0;
		}
		if(a[i]==1)
		{
			k++;
		}
		if(k==3)
		{
			a[i]=0;
			k=0;
			m--;
		}
	}
	for(i=0;i<n;i++)
	{
		if(a[i])
		{
			return i+1;
		}
	}
}
int main()
{
	printf("Which person is the Traitor of Jesus\n");
	int hash[10]={1,1,1,1,1,1,1,1,1,1};
	printf("%d",Traitor(hash,10));
}

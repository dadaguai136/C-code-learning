#include<stdio.h>
int Quantity(int a[],int n,int i)
{
	int s=0;
	for(int j=0;j<n;j++)
	{
		if(a[j]>a[i])
		{
			s++;	
		}
	}
	return s;
}
int main()
{
	int a[]={86,45,62,12,34,90,100};
	for(int i=0;i<sizeof(a)/4;i++)
	{
		printf("%d:%d\n",a[i],Quantity(a,sizeof(a)/4,i));
	}
}

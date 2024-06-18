#include<stdio.h>
int Same(int n)
{
	int a[3];
	int k=0;
	int count=1;
	while(n)
	{
		a[k++]=n%10;
		n/=10;
	}
	for(int i=0;i<k-1;i++)//留个位置给j
	{
		for(int j=i+1;j<k;j++)//j在i的后面
		{
			if(a[i]==a[j])
			{
				count++;
			}
		}
	}
	if(count==2)
	{
		return 1;
	}
	return 0;
}
int main()
{
	printf("Any two numbers are the same\n");
	for(int i=10;i<1000;i++)
	{
		if(Same(i))
		{
			printf("%d\n",i);
		}
	}
}

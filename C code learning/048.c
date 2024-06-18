#include<stdio.h>
float Score(int a[],int n)
{
	float sum;
	int min,max;
	sum=min=max=a[0];
	for(int i=1;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
		if(min>a[i])
		{
			min=a[i];
		}
		sum=sum+a[i];
	}
	sum=sum-min-max;
	return sum/(n-2);
}
int main()
{
	printf("Scoring of Classic Competitions\n");
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	printf("%f",Score(a,10));
}

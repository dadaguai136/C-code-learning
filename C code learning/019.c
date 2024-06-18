#include<stdio.h>
int Same(int n)
{
	int one,two,three;
	one=n/100;
	two=n/10%10;
	three=n%10;
	if(one==two&&two==three)
	{
		return 0;
	}
	if(one==two||one==three||two==three)
	{
		return 1;
	}
	return 1;
}
int main()
{
	printf("Any two numbers are the same");
	for(int n=100;n<1000;n++)
	{
		if(Same(n))
		{
			printf("%d\n",n);
		}
	}
}

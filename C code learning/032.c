#include<stdio.h>
int main()
{
	printf("A hundred bucks for a hundred chickens\n");
	for(int a=1;a<20;a++)
	{
		for(int b=1;b<33;b++)
		{
			int c=100-b-a;
			if(a*5+b*3+c/3.0==100)
			{
				printf("%d,%d,%d\n",a,b,c);
			}
		}
	}
}

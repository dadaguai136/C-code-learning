#include<stdio.h>
int main()
{
	extern x;
	{
		int x=6;
	}
	printf("%d",x);
}
int x=5;

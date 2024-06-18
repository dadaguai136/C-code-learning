#include<stdio.h>
int Reverse_Order(int n)
{
	int s=0;
	while(n)
	{
		s=s*10+n%10;
		n=n/10;
	}
	return s;
}
int main()
{
	printf("The reverse order of nine times a certain number is himself\n");
	for(int n=1000;n<100000;n++)
	{
		if(n==Reverse_Order(n*9))
		{
			printf("%d\n",n);
		}
	}
}

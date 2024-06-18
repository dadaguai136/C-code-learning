#include<stdio.h>
int Fibonacci_Sequence(int n)
{
	if(n==1||n==2)
	{
		return 1;
	}
	return Fibonacci_Sequence(n-1)+Fibonacci_Sequence(n-2);
}
int main()
{
	for(int n=1;n<=10;n++)
	{
		printf("%d ",Fibonacci_Sequence(n));
	}
}

#include<stdio.h>
int Greatest_Common_Divisor(int a,int b)
{
	int c;
	c=a%b;
	while(c)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
int main()
{
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=Greatest_Common_Divisor(a,b);
	printf("The minimum common multiple is %d",a*b/c);
}

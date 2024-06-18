#include<stdio.h>
int Greatest_Common_Divisor(int a,int b)//求最大公约数
{
	int c;
	c=a%b;
	while(c)//辗转相除法
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d",Greatest_Common_Divisor(a,b));
}

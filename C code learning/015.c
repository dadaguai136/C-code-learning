#include<stdio.h>
int Greatest_Common_Divisor(int a,int b)//�����Լ��
{
	int c;
	c=a%b;
	while(c)//շת�����
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

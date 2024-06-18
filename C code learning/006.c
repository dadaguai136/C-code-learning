/*1-1/2-1/3-1/4-1/5…*/
#include<stdio.h>
float sumfun(int n)
{
	float c;//每次的确定值
	int flag=1;//数值符号
	float sum=0;//累加
	for(int i=1;i<=n;i++)
	{
		c=flag*1.0/i;
		flag=-flag;
		sum+=c;
	}
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%f",sumfun(n));
}

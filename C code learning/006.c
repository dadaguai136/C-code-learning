/*1-1/2-1/3-1/4-1/5��*/
#include<stdio.h>
float sumfun(int n)
{
	float c;//ÿ�ε�ȷ��ֵ
	int flag=1;//��ֵ����
	float sum=0;//�ۼ�
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

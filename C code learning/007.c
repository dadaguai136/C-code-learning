#include<stdio.h>
float sumfun(int n)
{
	if(n==1)//�ݹ����
	{
		return 1.0;
	}
	int flag;
	if(n%2==1)//��������ż����
	{
		flag=1;
	}
	else
	{
		flag=-flag;
	}
	return sumfun(n-1)+flag*1.0/n;//�ݹ���� ����ʱ�ۼӷ���
}
int main()
{
	printf("%f",sumfun(2));
}

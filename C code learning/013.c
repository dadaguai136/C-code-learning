#include<stdio.h>
int Perfect_Number(int n)//����ȫ��
{
	int s=0;
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			s=s+i;
		}
	}
	if(s==n)
	{
		return 1;
	}
	return 0;
}
void Print(int n)//��ӡ��ȫ��
{
	printf("%d=",n);
	for(int i=1;i<n;i++)
	{
		if(n%i==0)
		{
			printf("%d+",i);
		}
	}
	printf("\b \n");
}
int main()
{
	for(int n=1;n<100;n++)
	{
		if(Perfect_Number(n))
		{
			Print(n);
		}
	}
}

#include<stdio.h>
int Fun(int count,int n)
{
	int sum;
	if(count==1)
	{
		return n;
	}
	sum=Fun(count-1,n)*10+n;//���ݣ�1+11+111
	return sum;
}
int Count(int count,int n)
{
	int s;
	if(count==1)
	{
		return 1;//count=1ʱ ����1
	}
	s=Count(count-1,n)+Fun(count,n);//����:1+11+111
}
int main()
{
	printf("%d",Count(3,1));
}

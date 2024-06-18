#include<stdio.h>
int m=0;
void Sixteen_Bit_Binary(int n)
{
	m++;//计数
	if(m>16)//大于16位直接返回无
	{
		return ;
	}
	Sixteen_Bit_Binary(n/2);
	printf("%d",n%2);
}
int main()
{
	Sixteen_Bit_Binary(6);
}

#include<stdio.h>
int m=0;
void Sixteen_Bit_Binary(int n)
{
	m++;//����
	if(m>16)//����16λֱ�ӷ�����
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

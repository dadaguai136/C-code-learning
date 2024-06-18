#include<stdio.h>
void Sixteen_Bit_Binary(int n)
{
	int a[16]={0};
	int i=15;
	while(n)
	{
		a[i--]=n%2;
		n/=2;
	}
	for(i=0;i<16;i++)
	{
		printf("%d",a[i]);
	}
}
int main()
{
	Sixteen_Bit_Binary(9);
}

#include<stdio.h>
int main()
{
	int m,n;
	for(int i=5;i<=100;i+=5)
	{
		m=i;
		while(m%5==0)
		{
			m=m/5;
			n++;
		}
	}
	printf("%d",n);
}

#include<stdio.h>
float Ball_Bounce(float h,int n)
{
	float s=0;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			s=h;
		}
		else
		{
			s=s+2*h;
		}
		h=h/2;
	}
	return s;
}
float Ball_Bounce1(float h,int n)
{
	if(n==1)
	{
		return h;
	}
	return Ball_Bounce1(h/2,n-1)+h/2*3;
}
int main()
{
	printf("%f",Ball_Bounce1(100,2));
}

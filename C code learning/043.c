#include<stdio.h>
#include<math.h>
float Formula(float x)
{
	return x*x*x-5*x*x+16*x-80;
}
float Sove(float x1,float x2)
{
	float x,y;
	x=(x1+x2)/2;
	y=Formula(x);
	if(y==0)
	{
		return x;
	}
	while(fabs(y)>=1e-5)
	{
		if(y*Formula(x2)<0)
		{
			x1=x;
		}
		else
		{
			x2=x;
		}
		x=(x1+x2)/2;
		y=Formula(x);
	}
	return x;
}
int main()
{
	printf("The value of x :x*x*x-5*x*x+16*x-80=0\n");
	printf("%f",Sove(-10,10));
}

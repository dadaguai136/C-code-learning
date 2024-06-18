#include<stdio.h>
#include<math.h>
float Calculate(float x,float n)
{
	float x1;
	x1=1.0/2*(x+n/x);
	if(fabs(x-x1)<1e-5)
	{
		return x;
	}
	return Calculate(x1,n);
}
float Mysqrt(float n)
{
	return Calculate(2,n);
}
int main()
{
	printf("%f\n",Mysqrt(10));
	printf("%f",sqrt(10));
}

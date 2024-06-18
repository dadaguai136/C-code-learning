#include<stdio.h>
int Leap_year(int n)
{
	return (n%4==0&&n%100!=0)||n%400==0;
}
int main()
{
	for(int n=2000;n<3000;n++)
	{
		if(Leap_year(n))
		{
			printf("Leap year is %3d\n",n);
		}
	}
}

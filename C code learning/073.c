#include<stdio.h>
void Position(char a[],char x)
{
	int i=0;
	while(*a)
	{
		i++;
		if(i==4)
		{
			i=0;
			*a=x;
		}
		a++;
	}
}
void Assignment(char a[],char b[])
{
	while(*a)
	{
		if(*b!=',')
		{
			*b=*a;
			b++;
			a++;
		}
		else
		{
			b++;
		}
	}
	*b=0;
}
int main()
{
	char a[]="209679026";
	char b[]="jgajgspreougojhsgb";
	Position(b,',');
	Assignment(a,b);
	puts(b);
}

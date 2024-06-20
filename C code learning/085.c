#include<stdio.h>
int Quantity(char a[])
{
	char *p=a;
	int number=0,flag=0;
	while(*p)
	{
		if(*p==' ')
		{
			flag=0;
		}
		else if(flag==0)
		{
			number++;
			flag=1;
		}
		p++;
	}
	return number;
}
int Quantity1(char a[])
{
	int number=0;
	char *p=a;
	while(*p)
	{
		while(*p&&*p==' ')
		{
			p++;
		}
		if(*p)
		{
			number++;
		}
		while(*p&&*p!=' ')
		{
			p++;
		}
	}
	return number;
}
int Quantity2(char a[])
{
	char *p=a;
	int number=0;
	while(*p&&*p==' ')
	{
		p++;
	}
	if(*p==0)
	{
		return number;
	}
	if(*p)
	{
		number=1;
	}
	while(*p&&*p!=' ')
	{
		p++;
	}
	return number+Quantity2(p);
}
int main()
{
	printf("Count the number of words\n");
	char a[]="    da    da   guai   136";
	printf("%d",Quantity2(a));
}

#include<stdio.h>
void Uppercase(char a[])
{
	char *p=a;
	int flag=0;
	while(*p)
	{
		if(*p==' ')
		{
			flag=0;
		}
		else if(flag==0)
		{
			if(*p>='a'&&*p<='z')
			{
				*p=*p-32;
			}
			flag=1;
		}
		p++;
	}
}
void Uppercase1(char a[])
{
	char *p=a;
	if(*a==0)
	{
		return;
	}
	while(*p&&*p==' ')
	{
		p++;
	}
	if(*p!=0)
	{
		if(*p>='a'&&*p<='z')
		{
			*p=*p-32;
		}
	}
	while(*p&&*p!=' ')
	{
		p++;
	}
	Uppercase1(p);
}
int main()
{
	printf("title case\n");
	char a[]=" da da guai 136 ";
	Uppercase(a);
	puts(a);
}

#include<stdio.h>
#include<string.h>
char *Position(char a[])
{
	char *p=a;
	int num=0;
	while(*p)
	{
		p++;
	}
	p--;
	while(p>=a&&*p==' ')
	{
		p--;
	}
	if(p>=a)
	{
		num++;
		*(p+1)=0;
	}
	while(p>=a&&*p!=' ')
	{
		p--;
	}
	if(num==1&&p>=a)
	{
		return p+1;
	}
	return 0;
}
int Find(char a[],char b[])
{
	char *p=b;
	if(*a==0||*b==0)
	{
		return 0;
	}
	while(*a&&*a==' ')
	{
		a++;
	}
	while(*a&&*b&&*a==*b)
	{
		a++;
		b++;
	}
	if(*b==0&&(*a==0||*a==' '))
	{
		return 1;
	}
	while(*a&&*a!=' ')
	{
		a++;
	}
	return Find(a,p);
}
void Recursion(char a[])
{
	char *p=a,*back;
	back=Position(a);
	if(back==0)
	{
		return;
	}
	*(back-1)=0;
	Recursion(a);
	if(Find(a,back))
	{
		return;
	}
	while(*p)
	{
		p++;
	}
	*p=' ';
	strcpy(p+1,back);
}
int main()
{
	char a[]="  da  da  guai da guai 136 136 da guai";
	Recursion(a);
	puts(a);
}

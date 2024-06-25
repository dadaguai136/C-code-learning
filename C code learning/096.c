#include<stdio.h>
#include<string.h>
int Number(char a[])
{
	int num=0;
	while(*a)
	{
		while(*a&&*a==' ')
		{
			a++;
		}
		if(*a)
		{
			num++;
		}
		while(*a&&*a!=' ')
		{
			a++;
		}
	}
	return num;
}
char *Position(char a[],int n)
{
	int s=0;
	char *h;
	while(*a)
	{
		while(*a&&*a==' ')
		{
			a++;
		}
		if(*a)
		{
			s++;
			h=a;
		}
		while(*a&&*a!=' ')
		{
			a++;
		}
		if(s==n)
		{
			return h;
		}
	}
}
int Cmp(char a[],char b[])
{
	while(*a&&*b&&*a==*b)
	{
		a++;
		b++;
	}
	if((*b==0||*b==' ')&&(*a==0||*a==' '))
	{
		return 0;
	}
	return *a-*b;
}
void Recursion(char a[])
{
	char *h,*p,t[100];
	int num;
	int i=1;
	num=Number(a);
	if(num<=1)
	{
		return;
	}
	h=Position(a,Number(a));
	*(h-1)=0;
	Recursion(a);
	while(i<num&&Cmp(p=Position(a,i),h)<0)
	{
		i++;
	}
	if(i<num)
	{
		strcpy(t,p);
		strcpy(p,h);
		while(*p)
		{
			p++;
		}
		*p=' ';
		*(p+1)=0;
		strcat(a,t);
	}
	else
	{
		*(h-1)=' ';
	}
}
int main()
{
	printf("Word comparison sorting\n");
	char a[]=" guai da da ";
	Recursion(a);
	puts(a);
}

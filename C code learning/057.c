#include<stdio.h>
#include"Print.h"
void Remove(char a[])
{
	char *p=a;
	while(*a)
	{
		if(*a>='0'&&*a<='9')
		{
			*p=*a;
			p++;
		}
		a++;
	}
	*p=0;
}
void Remove1(char a[])
{
	char *p=a;
	if(*a==0)
	{
		return;
	}
	Remove1(a+1);
	if(*a>='0'&&*a<='9')
	{
		return;
	}
	while(*(p+1))
	{
		*p=*(p+1);
		p++;
	}
	*p=0;
}
int Remove2(char a[])
{
	char t;
	char *p=a;
	int n;
	if(*a==0)
	{
		return 0;
	}
	while(*(p+1))
	{
		p++;
	}
	t=*p;
	*p=0;
	n=Remove2(a);
	if(t>='0'&&t<='9')
	{
		a=a+n;
		*a=t;
		*(a+1)=0;
		return n+1;
	}
}
int main()
{
	printf("Keep only numbers in a string of characters\n");
	char a[]="0BBa38400##jdkjt989%11  3";
	//Remove(a);
	//Char_Print(a);
	printf("%d\n",Remove2(a));
	Char_Print(a);
}

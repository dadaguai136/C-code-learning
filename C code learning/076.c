#include<stdio.h>
void Reversal(char a[])
{
	char *p=a;
	if(*a==0||*(a+1)==0)
	{
		return;
	}
	while(*p)
	{
		p++;
	}
	p--;
	char t,temp;
	t=*p;
	*p=0;
	Reversal(a+1);
	temp=*a;
	*a=t;
	*p=temp;
}
void Recursion(char a[])
{
	char *p;
	int flag=1;
	while(*a&&*a==' ')
	{
		a++;
	}
	p=a;
	if(*a==0)
	{
		return;
	}
	while(*a&&*a!=' ')
	{
		a++;
	}
	if(*a==' ')
	{
		*a=0;
		flag=0;
	}
	Reversal(p);
	if(flag==0)
	{
		Recursion(a+1);
		*a=' ';
	}
}
int main()
{
	printf("Word reversal\n");
	char a[]="this is a book";
	Recursion(a);
	puts(a);
}

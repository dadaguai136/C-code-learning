#include<stdio.h>
#include<string.h>
void Recursion(char a[])
{
	char *p=a,*q;
	while(*p&&*p!=',')
	{
		p++;
	}
	q=p-3;
	if(q<=a)
	{
		return;
	}
	while(*p)
	{
		p++;
	}
	while(p>q)
	{
		*p=*(p-1);
		p--;
	}
	*q=',';
	Recursion(a);
}
int main()
{
	char a[100]="276027604989";
	Recursion(a);
	puts(a);
}

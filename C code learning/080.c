#include<stdio.h>
char *Mycpy(char a[],char b[])
{
	char *head=a;
	while(*b)
	{
		*a=*b;
		a++;
		b++;
	}
	*a=0;
	return head;
}
char *Mycpy1(char a[],char b[])
{
	int i=0;
	while(b[i])
	{
		a[i]=b[i];
		i++;
	}
	a[i]=0;
	return a;
}
char *Mycpy2(char a[],char b[])
{
	if(*b==0)
	{
		*a=0;
		return a;
	}
	*a=*b;
	Mycpy2(a+1,b+1);
}
int main()
{
	char a[10]="abcdef";
	char b[]="123";
	Mycpy2(a,b);
	puts(a);
}

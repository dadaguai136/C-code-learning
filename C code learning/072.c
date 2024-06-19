#include<stdio.h>
#include<string.h>
void Character(char a[],char b[],char c[])
{
	if(*a==0)
	{
		strcpy(c,b);return;
	}
	if(*b==0)
	{
		strcpy(c,a);return;
	}
	if(*a==0&&*b==0)
	{
		return;
	}
	if(*a<*b)
	{
		*c=*a;
		Character(a+1,b,c+1);
	}
	else
	{
		*c=*b;
		Character(a,b+1,c+1);
	}
}
int main()
{
	char a[]="13579";
	char b[]="2468";
	char c[10];
	Character(a,b,c);
	puts(c);
}

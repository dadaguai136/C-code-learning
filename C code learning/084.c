#include<stdio.h>
#include<string.h>
void Remove(char a[])
{
	char *p=a;
	while(*p&&*p==' ')
	{
		p++;
	}
	if(*p==0)
	{
		*a=0;
		return;
	}
	strcpy(a,p);
	p=a;
	while(*p&&*p!=' ')
	{
		p++;
	}
	Remove(p+1);
}
int main()
{
	printf("Remove all excess spaces\n");
	char a[]=" da     da    guai  136 ";
	puts(a);
	Remove(a);
	printf("%s",a);
}

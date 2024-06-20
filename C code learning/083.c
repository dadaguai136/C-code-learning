#include<stdio.h>
#include<string.h>
int Front(char a[])
{
	char *head=a;
	while(*a&&*a==' ')
	{
		a++;
	}
	strcpy(head,a);
}
int After(char a[])
{
	char *p=a;
	while(*p)
	{
		p++;
	}
	p--;
	while(*p==' '&&p>=a)
	{
		p--;
	}
	*(p+1)=0;
}
int main()
{
	printf("Remove excess spaces before and after\n");
	char a[]="    da da guai 136    ";
	puts(a);
	Front(a);
	After(a);
	printf("%s",a);
}

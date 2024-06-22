#include<stdio.h>
#include<string.h>
int Find(char a[],char b[])
{
	char *h,*p;
	h=a;
	p=b;
	if(*a==0)
	{
		return 0;
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
	return Find(h+1,p);
}
void Remove(char a[])
{
	char *h,*p;
	h=p=a;
	if(*a==0)
	{
		return;
	}
	while(*p&&*p==' ')
	{
		p++;
	}
	if(*p)
	{
		h=p;
	}
	while(*p&&*p!=' ')
	{
		p++;
	}
	char *space=p;
	char temp=*space;
	*space=0;
	Remove(space+1);
	if(Find(space+1,h))
	{
		*space=temp;
		strcpy(a,space+1);
	}
	else
	{
		*space=temp;
	}
}
int main()
{
	printf("Remove duplicate words\n");
	char a[]="da da guai guai 136 136 da guai 136  ";
	Remove(a);
	puts(a);
}

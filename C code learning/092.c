#include<stdio.h>
#include<string.h>
char *Back_Word(char a[],int n)
{
	char *p=a;
	char *h=NULL;
	int s=0;
	while(*p)
	{
		while(*p&&*p==' ')
		{
			p++;
		}
		if(*p)
		{
			s++;
		}
		if(s==n)
		{
			h=p;
			break;
		}
		while(*p&&*p!=' ')
		{
			p++;
		}
	}
	return h;
}
int Number(char a[])
{
	char *p=a;
	int n=0;
	while(*p)
	{
		while(*p&&*p==' ')
		{
			p++;
		}
		if(*p)
		{
			n++;
		}
		while(*p&&*p!=' ')
		{
			p++;
		}
	}
	return n;
}
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
	while(*h&&*h!=' ')
	{
		h++;
	}
	while(*h&&*h==' ')
	{
		h++;
	}
	return Find(h,p);
}
void Remove(char a[])
{
	
	int n=Number(a);
	if(n<=1)
	{
		return ;
	}
	char *p=Back_Word(a,n);
	*(p-1)=0;
	int m;
	Remove(a);
	m=strlen(a);
	if(Find(a,p))
	{
		return;
	}
	*(a+m)=' ';
	strcpy(a+m+1,p);
}
int main()
{
	char a[]="da da guai guai da 136 da guai da da guai 136";
	puts(a);
	Remove(a);
	puts(a);
}

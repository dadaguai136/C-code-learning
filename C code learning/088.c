#include<stdio.h>
#include<string.h>
int Word(char a[],char b[])
{
	while(*a&&*b&&*a==*b)
	{
		a++;
		b++;
	}
	if(*b==0)
	{
		return 1;
	}
	return 0;
}
void Find(char a[],char b[])
{
	char *p=a;
	while(*p)
	{
		if(Word(p,b))
		{
			strcpy(p,p+strlen(b));
			continue;
		}
		p++;
	}
}
void Recursion(char a[],char b[])
{
	char *h=a,*p=b;
	if(*a==0)
	{
		return;
	}
	while(*a&&*b&&*a==*b)
	{
		a++;
		b++;
	}
	if(*b==0)
	{
		Recursion(a,p);
		strcpy(h,a);
	}
	else
	{
		Recursion(h+1,p);
	}
}
int main()
{
	char a[]="  dadaddada dad adda",b[]="da";
	puts(a);
	Recursion(a,b);
	puts(a);
}

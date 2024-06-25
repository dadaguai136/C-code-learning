#include<stdio.h>
#include<string.h>
char *MaxWord(char a[])
{
	int num=0,maxlen=0;
	char *h;
	while(*a)
	{
		while(*a&&*a==' ')
		{
			a++;
		}
		if(*a)
		{
			num=0;
		}
		while(*a&&*a!=' ')
		{
			num++;
			a++;
		}
		if(maxlen<num)
		{
			maxlen=num;
			h=a-num;
		}
	}
	*(h+maxlen)=0;
	return h;
}
char *Back(char a[])
{
	char *p=a;
	int num=0;
	while(*p)
	{
		p++;
	}
	p--;
	while(p>=a&&*p==' ')
	{
		p--;
	}
	if(p>=a)
	{
		num++;
		*(p+1)=0;
	}
	while(p>=a&&*p!=' ')
	{
		p--;
	}
	if(num==1&&p>a)
	{
		return p+1;
	}
	return 0;
}
char *Recursion(char a[])
{
	char *h,*p;
	h=Back(a);
	if(h==0)
	{
		return a;
	}
	*(h-1)=0;
	p=Recursion(a);
	if(strlen(p)<strlen(h))
	{
		return h;
	}
	return p;
}

int main()
{
	printf("The longest word\n");
	char a[]="  da da guai 136   ";
	char *p;
	p=Recursion(a);
	puts(p);
}

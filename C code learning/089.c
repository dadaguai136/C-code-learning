#include<stdio.h>
#include<string.h>
void Replace(char a[],char b[],char c[])
{
	char *h=a,*p=b,t[100];
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
		Replace(a,p,c);
		strcpy(t,a);
		strcpy(h,c);
		strcat(h,t);
	}
	else
	{
		Replace(h+1,p,c);
	}
}
int main()
{
	char a[]="������˧������˧",b[]="����",c[]="�ϵ�";
	puts(a);
	Replace(a,b,c);
	puts(a);
}

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
	char a[]="老伍最帅老伍最帅",b[]="老伍",c[]="老邓";
	puts(a);
	Replace(a,b,c);
	puts(a);
}

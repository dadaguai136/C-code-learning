#include<stdio.h>
int mylen(char a[])
{
	int i=0;
	while(a[i])
	{
		i++;
	}
	return i;
}
int mylen1(char a[])
{
	char *p=a;
	while(*p)
	{
		p++;
	}
	return p-a;
}
int mylen2(char a[])
{
	if(*a==0)
	{
		return 0;
	}
	return mylen2(a+1)+1;
}
int main()
{
	char a[]="1234567";
	printf("%d",mylen2(a));
}

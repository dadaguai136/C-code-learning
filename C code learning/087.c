#include<stdio.h>
int Recursion(char a[],char b[])
{
	char *h=a,*p=b;
	if(*a==0)
	{
		return 0;
	}
	while(*a&&*b&&*a==*b)
	{
		a++;
		b++;
	}
	if(*b==0)
	{
		return 1+Recursion(a,p);
	}
	return Recursion(h+1,p);
}
int main()
{
	char a[]="dada d a  da dd aa dad da ",b[]="da";
	printf("%d",Recursion(a,b));
}

#include<stdio.h>
int Mycmp(char a[],char b[])
{
	while(*a&&b&&*a==*b)
	{
		a++;
		b++;
	}
	return *a-*b;
}
int Mycmp1(char a[],char b[])
{
	int i,j;
	i=j=0;
	while(a[i]&&b[j]&&a[i]==b[j])
	{
		i++;
		j++;
	}
	return a[i]-b[j];
}
int Mycmp2(char a[],char b[])
{
	if(*a==0||*b==0||*a!=*b)
	{
		return *a-*b;
	}
	Mycmp2(a+1,b+1);
}
int main()
{
	char a[]="abc";
	char b[]="abcd";
	printf("%d",Mycmp2(a,b));
}

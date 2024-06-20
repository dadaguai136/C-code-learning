#include<stdio.h>
char *Mycat(char a[],char b[])
{
	char *head=a;
	while(*a)
	{
		a++;
	}
	while(*b)
	{
		*a++=*b++;
	}
	*a=0;
	return head;
}
char *Mycat1(char a[],char b[])
{
	int i,j;
	i=j=0;
	while(a[i])
	{
		i++;
	}
	while(b[j])
	{
		a[i]=b[j];
		i++;
		j++;
	}
	a[i]=0;
	return a;
}
void Mycat2(char a[],char b[])
{
	if(*b==0)
	{
		*a=0;
		return;
	}
	while(*a)
	{
		a++;
	}
	*a=*b;
	Mycat2(a+1,b+1);
}
int main()
{
	char a[100]="abc";
	char b[]="123";
	//Mycat2(a,b);
	//puts(a);
	char *h=Mycat(a,b);
	puts(h);
}

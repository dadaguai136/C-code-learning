#include<stdio.h>
#include<string.h>
void Reversal(char array[])
{
	char *p=array;
	while(*p)
	{
		p++;
	}
	p--;
	char t;
	while(array<p)
	{
		t=*array;
		*array=*p;
		*p=t;
		array++;
		p--;
	}
}
void Position(char array[])
{
	int i=0;
	while(*array)
	{
		i++;
		if(i==4)
		{
			*array=',';
			i=0;
		}
		array++;
	}
}
void Assignment(char a[],char b[])
{
	while(*a)
	{
		while(*b&&*b==',')
		{
			b++;
		}
		*b++=*a;
		a++;
	}
	*b=0;
}
int main()
{
	char a[100]="12345678";
	char b[100]="djfioaggj;ajgiei";
	Reversal(a);
	Position(b);
	Assignment(a,b);
	Reversal(b);
	puts(b);
}

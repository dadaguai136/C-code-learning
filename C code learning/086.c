#include<stdio.h>
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
int Find(char a[],char b[])
{
	char *p=a;
	int number=0;
	while(*p)
	{
		if(Word(p,b))
		{
			number++;
		}
		p++;
	}
	return number;
}
int main()
{
	printf("Find how many such words there are\n");
	char a[]="  da d  a  guai  1  3 6",b[]="da";
	printf("%d",Find(a,b));
}

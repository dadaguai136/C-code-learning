#include<stdio.h>
#include<string.h>
int Number(char a[])
{
	int num=0;
	while(*a)
	{
		while(*a&&*a==' ')
		{
			a++;
		}
		if(*a)
		{
			num++;
		}
		while(*a&&*a!=' ')
		{
			a++;
		}
	}
	return num;
}
char *Position(char a[],int n)
{
	int num=0;
	char *h=a;
	while(*a)
	{
		while(*a&&*a==' ')
		{
			a++;
		}
		if(*a)
		{
			num++;
			h=a;
		}
		while(*a&&*a!=' ')
		{
			a++;
		}
		if(num==n)
		{
			return h;
		}
	}
	return NULL;
}
void End(char a[])
{
	while(*a&&*a!=' ')
	{
		a++;
	}
	*a=0;
}
void Sort(char a[][5],int n)
{
	char t[10];
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(a[i],a[j])>0)
			{
				strcpy(t,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],t);
			}
		}
	}
}
int main()
{
	printf("Word comparison sorting\n");
	char a[]=" guai da da ";
	char b[5][5];
	int n=Number(a);
	for(int i=0;i<n;i++)
	{
		strcpy(b[i],Position(a,i+1));
		End(b[i]);
		puts(b[i]);
	}
	printf("--------------\n");
	Sort(b,n);
	for(int i=0;i<n;i++)
	{
		puts(b[i]);
	}
}

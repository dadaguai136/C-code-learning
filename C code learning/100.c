#include<stdio.h>
#include<malloc.h>
#include<string.h>
char **Place(char a[],int *n)
{
	char **ret;
	char *p;
	int i=0;
	ret=(char **)malloc(sizeof(char *)*10);
	while(*a)
	{
		while(*a&&*a==' ')
		{
			a++;
		}
		if(*a)
		{
			p=a;
		}
		while(*a&&*a!=' ')
		{
			a++;
		}
		if(*a==' ')
		{
			*a=0;
			ret[i]=(char *)malloc(sizeof(char)*strlen(p)+1);
			strcpy(ret[i],p);
			a++;
			i++;
		}
		else
		{
			ret[i]=(char*)malloc(sizeof(char)*strlen(p)+1);
			strcpy(ret[i],p);
			i++;
		}
	}
	*n=i;
	return ret;
}
int main()
{
	char a[]=" da da guai 136 ";
	char **p;
	int n;
	p=Place(a,&n);
	for(int i=0;i<n;i++)
	{
		puts(p[i]);
	}
}

#include<stdio.h>
#include<string.h>
#include<malloc.h>
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
void Sort(char **a,int n)
{
	char *t;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(a[i],a[j])>0)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
int main()
{
	printf("Word comparison sorting\n");
	char a[]="guai da da ";
	char **ret,*h,t[15];
	int n=Number(a);
	ret=(char **)malloc(sizeof(char *)*n);
	for(int i=0;i<n;i++)
	{
		h=Position(a,i+1);
		strcpy(t,h);
		End(t);
		ret[i]=(char *)malloc(sizeof(char)*(strlen(t)+1));
		strcpy(ret[i],t);
		puts(ret[i]);
	}
	printf("---------\n");
	Sort(ret,n);
	for(int i=0;i<n;i++)
	{
		puts(ret[i]);
	}
}

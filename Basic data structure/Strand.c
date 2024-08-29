#include<stdio.h>
#include<string.h>
int main()
{
	char str1[50]="Hello, ";
	char str2[50]="World!";
	char str3[50];
	int str1len=strlen(str1);
	int str2len=strlen(str2);
	printf("str1len is %d\n",str1len);
	printf("str2len is %d\n",str2len);
	for(int i=0;i<str1len;i++)
	{
		printf("%d %c\n",i,str1[i]);
	}
	strcpy(str3,str1);
	if(strcmp(str1,"Hello, ")==0)
	{
		printf("Equal!\n");
	}
	else
	{
		printf("Not Equal!\n");
	}
	strcat(str3,str2);
	printf("str3: %s\n",str3);
}

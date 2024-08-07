#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *FileName(int n)
{
	char *p,*h;
	h=p=(char *)malloc(sizeof(char)*0);
	strcpy(h,"000.c");
	p=p+2;
	while(n)
	{
		*p--=n%10+48;
		n=n/10;
	}
	return h;
}
int main()
{
	char *name,c;
	FILE *fp1,*fp2;
	fp1=fopen("E:\\abc.txt","w");
	for(int n=1;n<1000;n++)
	{
		name=FileName(n);
		fp2=fopen(name,"r");
		if(fp2==NULL)
		{
			continue;
		}
		fputs(name,fp1);
		fputc('\n',fp1);
		while((c=fgetc(fp2))!=EOF)
		{
			fputc(c,fp1);
		}
		fputc('\n',fp1);
		fclose(fp2);
	}
	fclose(fp1);
}

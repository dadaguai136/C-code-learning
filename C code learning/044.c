#include<stdio.h>
#include<malloc.h>
char *File_Name(int n)
{
	char *a,*p;
	a=(char *)malloc(6);
	a[0]=a[1]=a[2]='0';
	a[3]='.';
	a[4]='c';
	a[5]=0;
	//001.c
	p=a+2;
	while(n)
	{
		*p=n%10+48;
		p--;
		n/=10;
	}
	return a;
}
int main()
{
	printf("Output the source code to a txt document based on the file name\n");
	FILE *fp1,*fp2;
	char c,*a;
	fp1=fopen("E:\\abc.txt","w");
	for(int n=1;n<=1000;n++)
	{
		a=File_Name(n);
		fp2=fopen(a,"r");
		if(fp2==0)
		{
			continue;
		}
		fputs(a,fp1);
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

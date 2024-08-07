#include<stdio.h>
int main()
{
	FILE *fp;
	int s=0,e=-1;
	int length,length1;
	char c,c1;
	fp=fopen("E:\\abc.txt","r+");
	while(1)
	{
		fseek(fp,s,SEEK_SET);
		length=ftell(fp);
		c=fgetc(fp);
		fseek(fp,e,SEEK_END);
		length1=ftell(fp);
		c1=fgetc(fp);
		if(length>length1)
		{
			break;
		}
		fseek(fp,e,SEEK_END);
		if(c!='\n')
		{
			fputc(c,fp);
		}
		fseek(fp,s,SEEK_SET);
		if(c1!='\n')
		{
			fputc(c1,fp);
		}
		s++;
		e--;
	}
}

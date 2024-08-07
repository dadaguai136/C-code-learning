#include<stdio.h>
void Copy(FILE *fp1,FILE *fp2)
{
	FILE *fp;
	char c;
	fp=fopen("e:\\003.jpg","wb");
	while(!feof(fp2))
	{
		c=fgetc(fp2);
		fputc(c,fp);
	}
	while(!feof(fp1))//ÎÞÐ§
	{
		c=fgetc(fp1);
		fputc(c,fp);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp);
}
int main()
{
	FILE *fp1,*fp2;
	fp1=fopen("E:\\001.jpg","rb");
	fp2=fopen("E:\\002.jpg","rb");
	Copy(fp1,fp2);
}

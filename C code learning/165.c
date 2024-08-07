#include<stdio.h>
int main()
{
	FILE *fp1,*fp2;
	char c;
	fp1=fopen("E:\\abc.jpg","rb+");
	fp2=fopen("E:\\temp.txt","wb");
	c=fgetc(fp1);
	fputc(c,fp2);
	rewind(fp1);
	fputc(' ',fp1);
	fclose(fp1);
	fclose(fp2);
}

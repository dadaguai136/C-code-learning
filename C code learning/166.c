#include<stdio.h>
int main()
{
	FILE *fp1,*fp2;
	char c;
	fp1=fopen("E:\\abc.jpg","rb+");
	fp2=fopen("E:\\temp.txt","rb");
	c=fgetc(fp2);
	fputc(c,fp1);
	fclose(fp1);
	fclose(fp2);
}

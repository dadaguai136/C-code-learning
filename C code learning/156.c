#include<stdio.h>
int main()
{
	FILE *fp1,*fp2;
	char c;
	fp1=fopen("abc.txt","r");
	fp2=fopen("E:\\abc.txt","w");
	while((c=fgetc(fp1))!=EOF)
	{
		fputc(c,fp2);//�Ḳ��ԭ������
	}
	fclose(fp1);
	fclose(fp2);
}

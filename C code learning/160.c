#include<stdio.h>
int main()
{
	FILE *fp;
	char a[100]="da\nda\nguai";
	fp=fopen("E:\\abc.txt","w");
	fputs(a,fp);
	fclose(fp);
}

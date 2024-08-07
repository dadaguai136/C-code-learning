#include<stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("E:\\abc.txt","w");
	putw(1100,fp);
	fclose(fp);
}

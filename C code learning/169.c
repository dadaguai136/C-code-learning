#include<stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("E:\\abc.txt","r");
	printf("%d",getw(fp));
	fclose(fp);
}

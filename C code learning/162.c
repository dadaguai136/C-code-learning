#include<stdio.h>
int Quantity(FILE *fp)
{
	int num=0;
	while(fgetc(fp)!=EOF)
	{
		num++;
	}
	return num;
}
int main()
{
	FILE *fp;
	int num;
	fp=fopen("E:\\abc.txt","r");
	num=Quantity(fp);
	fclose(fp);
	printf("%d",num);
}

#include<stdio.h>
int main()
{
	FILE *fp;
	int x=10;
	fp=fopen("E:\\abc.txt","r+");
	fseek(fp,0,2);
	fputs(" ",fp);
	fprintf(fp,"%d",x);
}

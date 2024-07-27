#include<stdio.h>
int main()
{
	char x;
	FILE *fp;
	fp=fopen("E:\\abc.txt","r");
	while((x=fgetc(fp))!=EOF)
	{
		putchar(x);
	}
}

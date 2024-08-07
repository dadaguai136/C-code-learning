#include<stdio.h>
int main()
{
	FILE *fp;
	char a[100];
	int n;
	fp=fopen("E:\\abc.txt","r");
	scanf("%d",&n);
	while(n)
	{
		fgets(a,7,fp);
		n--;
	}
	puts(a);
	fclose(fp);
}

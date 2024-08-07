#include<stdio.h>
void Myputw(int n,FILE *fp)
{
	char *p;
	p=(char *)&n;
	fputc(p[0],fp);
	fputc(p[1],fp);
}
int Mygetw(FILE *fp)
{
	char a[2];
	int *p;
	a[0]=fgetc(fp);
	a[1]=fgetc(fp);
	p=(int *)a;
	return *p;
}
int main()
{
	int n;
	FILE *fp;
	scanf("%d",&n);
	fp=fopen("E:\\abc.txt","r+");
	Myputw(n,fp);
	//printf("%d",Mygetw(fp));
	fclose(fp);
}

#include<stdio.h>
void Transposition(char a[])
{
	char t;
	if(*a==0||*(a+1)==0)
	{
		return;
	}
	Transposition(a+2);
	t=*a;
	*a=*(a+1);
	*(a+1)=t;
}
int main()
{
	FILE *fp;
	char a[100];
	char c;
	int i=0;
	fp=fopen("E:\\001.txt","r");
	while((c=fgetc(fp))!=EOF)
	{
		a[i++]=c;
	}
	a[i]=0;
	fclose(fp);
	Transposition(a);
	fp=fopen("E:\\001.txt","w");
	i=0;
	while(a[i])
	{
		fputc(a[i],fp);
		i++;
	}
	fclose(fp);
}

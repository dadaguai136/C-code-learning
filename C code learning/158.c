#include<stdio.h>
void Move(char a[])
{
	char t;
	if(*a==0||*(a+1)==0)
	{
		return;
	}
	Move(a+2);
	t=*a;
	*a=*(a+1);
	*(a+1)=t;
}
int main()
{
	char a[100];
	FILE *fp;
	fp=fopen("E:\\abc.txt","r+");
	fgets(a,100,fp);
	rewind(fp);
	Move(a);
	fputs(a,fp);
	fclose(fp);
}

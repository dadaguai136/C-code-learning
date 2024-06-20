#include<stdio.h>
int main()
{
	char *p="abc";
	*(p+1)='c';
	//char a[]="abc";
	//*(a+1)='c';
	puts(p);
	//指针没有用但数组可以
}

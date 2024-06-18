#include<stdio.h>
int main()//指针站四个字节
{
	int *x;
	char *y;
	float *z;
	double *p;
	printf("%d %d %d %d ",sizeof(x),sizeof(y),sizeof(z),sizeof(p));
}

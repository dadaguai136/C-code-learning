#include<stdio.h>
#define M 3
int main()
{
	int a[][M]={1,2,3,4,5,6};
	printf("%d",a[1][1]);
	printf("%d",*(*(a+1)+1));
	printf("%d",*(*a+M+M/2));
	printf("%d",*(a[1]+1));
	printf("%d",(*(a+1))[1]);
	printf("%d",1[a][1]);
	printf("%d",1[1[a]]);
}

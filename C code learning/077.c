#include<stdio.h>
int main()
{
	char a[]="12345\0";
	printf("%d %d",strlen(a),sizeof(a));
}

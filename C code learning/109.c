#include<stdio.h>
struct node
{
	int num;
	struct node *next;
};
int main()
{
	struct node x;
	x.num=1;
	printf("%d",x.num);
}

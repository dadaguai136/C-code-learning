#include<stdio.h>
struct node
{
	int num;
	struct node *next;
};
void Print(struct node *head)
{
	while(head!=NULL)
	{
		printf("%3d",head->num);
		head=head->next;
	}
}
int main()
{
	struct node a,b,c;
	a.num=1;
	b.num=2;
	c.num=3;
	a.next=&b;
	b.next=&c;
	c.next=NULL;
	Print(&a);
}

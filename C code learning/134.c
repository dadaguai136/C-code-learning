#include<stdio.h>
#include"Linked_List.h"
struct node *Remove(struct node **p1,struct node *p2)
{
	*p1=p2;
}
int main()
{
	struct node *p1,*p2;
	p1=Linked_List1();
	p2=Linked_List1();
	Remove(&p1->next,p2);
	Print(p1);
}

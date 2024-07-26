#include<stdio.h>
#include"Linked_List.h"
struct node *Remove(struct node *p1,struct node *p2)
{
	if(p1==NULL)
	{
		return p2;
	}
	if(p2==NULL)
	{
		return p1;
	}
	p1->next=Remove(p2,p1->next);
	return p1;
}
int main()
{
	struct node *p1,*p2;
	p1=Linked_List1();
	p2=Linked_List1();
	p1=Remove(p1,p2);
	Print(p1);
}

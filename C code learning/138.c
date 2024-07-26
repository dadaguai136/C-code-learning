#include<stdio.h>
#include"Linked_List.h"
struct node *Remove(struct node *p1,struct node *p2)
{
	struct node *h;
	if(p1==NULL)
	{
		return p2;
	}
	if(p2==NULL)
	{
		return p1;
	}
	if(p1->num<=p2->num)
	{
		h=p1;
		h->next=Remove(p1->next,p2);
	}
	else
	{
		h=p2;
		h->next=Remove(p2->next,p1);
	}
	return h;
}
int main()
{
	struct node *p1,*p2;
	p1=Linked_List1();
	p2=Linked_List1();
	p1=Remove(p1,p2);
	Print(p1);
}

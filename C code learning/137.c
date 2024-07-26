#include<stdio.h>
#include"Linked_List.h"
struct node *Remove(struct node *p1,struct node *p2)
{
	struct node *h,*k;
	if(p1==NULL)
	{
		return p2;
	}
	if(p2==NULL)
	{
		return p1;
	}
	h=k=p1;
	p1=p1->next;
	while(p1&&p2)
	{
		k=k->next=p2;
		p2=p2->next;
		k=k->next=p1;
		p1=p1->next;
	}
	if(p1==NULL)
	{
		k->next=p2;
	}
	else
	{
		k->next=p1;
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

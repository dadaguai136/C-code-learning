#include<stdio.h>
#include"Linked_List.h"
struct node *Compare(struct node *head,struct node *p)
{
	struct node *p1,*p2;
	if(p->num<=head->num)
	{
		p->next=head;
		return p;
	}
	p1=p2=head;
	while(p1&&p1->num<p->num)
	{
		p2=p1;
		p1=p1->next;
	}
	p2->next=p;
	p->next=p1;
	return head;
}
struct node *Sort(struct node *head)
{
	struct node *p,*h;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	h=head;
	head=head->next;
	h->next=NULL;
	while(head)
	{
		p=head->next;
		h=Compare(h,head);
		head=p;
	}
	return h;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Sort(head);
	Print(head);
}

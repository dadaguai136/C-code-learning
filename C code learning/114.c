#include<stdio.h>
#include"Linked_List.h"
struct node *Reverse(struct node *head)
{
	struct node *p,*p1;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	p=p1=head;
	while(p->next!=NULL)
	{
		p1=p;
		p=p->next;
	}
	p1->next=NULL;
	p->next=Reverse(head);
	return p;
}
struct node *Reverse1(struct node *head)
{
	struct node *p,*p1,*p2;
	if(head==NULL||head->next==NULL)
	{
		return NULL;
	}
	p=NULL;
	p1=head;
	p2=p1->next;
	while(p2)
	{
		p1->next=p;
		p=p1;
		p1=p2;
		p2=p2->next;
	}
	p1->next=p;
	return p1;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Reverse1(head);
	Print(head);
}

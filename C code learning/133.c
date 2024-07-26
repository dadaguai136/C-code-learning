#include<stdio.h>
#include"Linked_List.h"
struct node *Remove(struct node *head)
{
	struct node *p,*h;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	h=p=Remove(head->next);
	if(head->num%2==1)
	{
		head->next=h;
		return head;
	}
	while(p->next)
	{
		p=p->next;
	}
	p->next=head;
	head->next=NULL;
	return h;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Remove(head);
	Print(head);
}

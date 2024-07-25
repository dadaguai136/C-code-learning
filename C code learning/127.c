#include<stdio.h>
#include"Linked_List.h"
struct node *Remove(struct node *head)
{
	struct node *p,*h;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	h=p=head;
	head=head->next;
	while(p->next)
	{
		p=p->next;
	}
	p->next=h;
	h->next=NULL;
	return head;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Remove(head);
	Print(head);
}

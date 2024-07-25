#include<stdio.h>
#include"Linked_List.h"
struct node *Remove(struct node *head)
{
	struct node *p,*q;
	p=q=head;
	while(p->next)
	{
		q=p;
		p=p->next;
	}
	q->next=NULL;
	p->next=head;
	return p;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Remove(head);
	Print(head);
}

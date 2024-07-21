#include<stdio.h>
#include"Linked_List.h"
struct node *Delete(struct node *head,int num)
{
	struct node *p,*h,*q;
	if(head==NULL)
	{
		return NULL;
	}
	h=p=NULL;
	h->next=head;
	q=head;
	while(q)
	{
		if(q->num!=num)
		{
			p=p->next=q;
		}
		q=q->next;
	}
	p->next=NULL;
	return h->next;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Delete(head,1);
	Print(head);
}

#include<stdio.h>
#include"Linked_List.h"
struct node *Delete(struct node *head,int num)
{
	struct node *p,*q;
	if(head==NULL)
	{
		return NULL;
	}
	while(head&&head->num==num)
	{
		head=head->next;
	}
	p=q=head;
	while(p)
	{
		q=p;
		p=p->next;
		while(p&&p->num==num)
		{
			p=p->next;
		}
		q->next=p;
	}
	return head;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Delete(head,1);
	Print(head);
}

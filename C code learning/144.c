#include<stdio.h>
#include"Linked_List.h"
int Length(struct node *head)
{
	if(head==NULL)
	{
		return 0;
	}
	return 1+Length(head->next);
}
struct node *Find(struct node *head)
{
	struct node *p,*q,*h;
	int m=0;
	if(Length(head)<3)
	{
		return NULL;
	}
	while(head)
	{
		m=0;
		h=p=head;
		q=p->next;
		while(q&&q->num==p->num+1)
		{
			p=p->next;
			q=q->next;
			m++;
		}
		if(m>=2)
		{
			p->next=NULL;
			return h;
		}
		head=head->next;
	}
	return NULL;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Find(head);
	Print(head);
}

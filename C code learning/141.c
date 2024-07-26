#include<stdio.h>
#include"Linked_List.h"
int Same(struct node *head)
{
	struct node *p,*q;
	if(head==NULL||head->next==NULL)
	{
		return 1;
	}
	while(head)
	{
		p=q=head;
		while(p->next)
		{
			q=p;
			p=p->next;
		}
		if(head->num!=p->num)
		{
			return 0;
		}
		q->next=NULL;
		head=head->next;
	}
	return 1;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	if(Same(head))
	{
		printf("Same");
	}
	else
	{
		printf("No same");
	}
}

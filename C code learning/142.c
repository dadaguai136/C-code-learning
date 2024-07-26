#include<stdio.h>
#include"Linked_List.h"
int Same(struct node *head)
{
	struct node *p,*q,*k;
	int m;
	if(head->next==NULL||head==NULL)
	{
		return 1;
	}
	p=q=k=head;
	while(q->next)
	{
		k=q;
		q=q->next;
	}
	k->next=NULL;
	m=p->num==q->num&&Same(p->next);
	k->next=q;
	return m;
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
	Print(head);
}

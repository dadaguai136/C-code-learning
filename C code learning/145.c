#include<stdio.h>
#include"Linked_List.h"
void Myfree(struct node *head)
{
	if(head==NULL)
	{
		return;
	}
	Myfree(head->next);
	free(head);
}
void Myfree1(struct node *head)
{
	struct node *p,*q;
	if(head==NULL)
	{
		return;
	}
	q=head;
	p=head->next;
	while(p)
	{
		free(q);
		q=p;
		p=p->next;
	}
	free(q);
}
void Myfree2(struct node *head)
{
	while(head)
	{
		struct node *temp=head;
		head=head->next;
		free(temp);
	}
}
int main()
{
	struct node *head;
	head=Linked_List1();
	Print(head);
	Myfree2(head);
	printf("\n");
	Print(head);
}

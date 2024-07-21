#include<stdio.h>
#include"Linked_List.h"
struct node *Min(struct node *head)
{
	struct node *p;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	p=Min(head->next);
	if(head->num<p->num)
	{
		return head;
	}
	return p;
}
struct node *Min1(struct node *head)
{
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	struct node *p;
	p=head->next;
	while(p)
	{
		if(head->num>p->num)
		{
			head=p;
		}
		p=p->next;
	}
	return head;
}
int main()
{
	struct node *head,*min;
	head=Linked_List1();
	min=Min1(head);
	printf("%d\n",min->num);
	Print(head);
}

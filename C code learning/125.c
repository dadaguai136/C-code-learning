#include<stdio.h>
#include"Linked_List.h"
struct node *Remove(struct node *head)
{
	struct node *p,*q;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	p=q=Remove(head->next);
	while(q)
	{
		if(head->num==q->num)
		{
			return p;
		}
		q=q->next;
	}
	head->next=p;
	return head;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Remove(head);
	Print(head);
}

#include<stdio.h>
#include"Linked_List.h"
struct node *Reverse(struct node *head)
{
	struct node *p;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	p=Reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return p;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Reverse(head);
	Print(head);
}

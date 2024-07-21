#include<stdio.h>
#include"Linked_List.h"
struct node *Delete(struct node *head,int num)
{
	struct node *p;
	if(head==NULL)
	{
		return NULL;
	}
	p=Delete(head->next,num);
	if(head->num==num)
	{
		return p;
	}
	head->next=p;
	return head;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Delete(head,1);
	Print(head);
}

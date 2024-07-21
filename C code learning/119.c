#include<stdio.h>
#include"Linked_List.h"
struct node *Sort(struct node *head,struct node *pre)
{
	struct node *p1,*p2;
	pre->next=NULL;
	if(head==NULL)
	{
		return pre;
	}
	if(pre->num<=head->num)
	{
		pre->next=head;
		return pre;
	}
	p1=p2=head;
	while(p1&&p1->num<pre->num)
	{
		p2=p1;
		p1=p1->next;
	}
	p2->next=pre;
	pre->next=p1;
	return head;
}
struct node *Recursion(struct node *head)
{
	struct node *p;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	p=Recursion(head->next);
	return Sort(p,head);
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Recursion(head);
	Print(head);
}

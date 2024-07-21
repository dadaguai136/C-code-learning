#include<stdio.h>
#include"Linked_List.h"
struct node *Min(struct node *head)
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
struct node *Delete(struct node *head,int num)
{
	if(head==NULL)
	{
		return head;
	}
	if(num==head->num)
	{
		return head->next;
	}
	struct node *p1,*p2;
	p1=p2=head;
	while(p1)
	{
		if(p1->num==num)
		{
			break;
		}
		p2=p1;
		p1=p1->next;
	}
	if(p1==NULL)
	{
		return head;
	}
	p2->next=p1->next;
	return head;
}
struct node *Sort(struct node *head)
{
	struct node *p,*k,*h;
	int flag=0;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	while(head)
	{
		p=Min(head);
		head=Delete(head,p->num);
		p->next=NULL;
		if(flag==0)
		{
			h=k=p;
		}
		else
		{
			k=k->next=p;
		}
		flag++;
	}
	return h;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Sort(head);
	Print(head);
}

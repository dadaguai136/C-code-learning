#include<stdio.h>
#include"Linked_List.h"
struct node *Reverse()
{
	struct node *head,*p,*q;
	int m;
	scanf("%d",&m);
	if(m==-1)
	{
		return NULL;
	}
	p=q=Reverse();
	head=(struct node *)malloc(sizeof(struct node));
	head->num=m;
	head->next=NULL;
	if(p==NULL)
	{
		return head;
	}
	else
	{
		while(q->next)
		{
			q=q->next;
		}
		q->next=head;
		return p;
	}
}
int main()
{
	struct node *head;
	head=Reverse();
	Print(head);
}

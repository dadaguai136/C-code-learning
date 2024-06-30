#include<stdio.h>
#include"Linked_List.h"
struct node *Reverse()
{
	struct node *head,*p,*p1;
	int x;
	scanf("%d",&x);
	if(x==-1)
	{
		return NULL;
	}
	head=(struct node *)malloc(sizeof(struct node));
	head->num=x;
	head->next=NULL;
	p=p1=Reverse();
	if(p)
	{
		while(p1->next)
		{
			p1=p1->next;
		}
		p1->next=head;
		return p;
	}
	return head;
}
int main()
{
	struct node *head;
	head=Reverse();
	Print(head);
}

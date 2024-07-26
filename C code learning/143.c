#include<stdio.h>
#include"Linked_List.h"
struct node *Copy(struct node *head)
{
	struct node *p;
	if(head==NULL)
	{
		return NULL;
	}
	p=(struct node *)malloc(sizeof(struct node));
	p->num=head->num;
	p->next=Copy(head->next);
	return p;
}
struct node *Reversal(struct node *head)
{
	struct node *p;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	p=Reversal(head->next);
	head->next->next=head;
	head->next=NULL;
	return p;
}
int Compare(struct node *p1,struct node *p2)
{
	while(p1&&p2&&p1->num==p2->num)
	{
		p1=p1->next;
		p2=p2->next;
	}
	return p1->num-p2->num;
}
int main()
{
	struct node *head,*p;
	head=Linked_List1();
	p=Copy(head);
	p=Reversal(p);
	if(Compare(head,p)==0)
	{
		printf("Number of palindromes");
	}
	else
	{
		printf("No");
	}
}

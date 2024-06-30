#include<stdio.h>
#include"Linked_List.h"
struct node *Reverse(int n)
{
	struct node *p,*p1;
	if(n<1)
	{
		return NULL;
	}
	p=p1=NULL;
	while(n)
	{
		p1=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&p1->num);
		p1->next=p;
		p=p1;
		n--;
	}
	return p1;	
}
struct node *Reverse1(int n)
{
	struct node *head,*p;
	if(n<1)
	{
		return NULL;
	}
	p=Reverse1(n-1);	
	head=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&head->num);
	head->next=p;
	return head;
}
int main()
{
	struct node *head;
	head=Reverse1(5);
	Print(head);
}

#include<stdio.h>
#include<stdlib.h>
#include"Linked_List.h"
struct node *Newnode(int n)
{
	struct node *head;
	if(n==0)
	{
		return NULL;
	}
	head=(struct node *)malloc(sizeof(struct node));
	head->num=1;
	head->next=Newnode(n-1);
	return head;
}
struct node *Triangle(int n)
{
	int i=0;
	struct node *h,*head,*p,*q;
	h=head=(struct node *)malloc(sizeof(struct node));
	h->num=1;
	h->next=NULL;
	i++;
	while(i<n)
	{
		p=head;
		head=q=Newnode(i+1);
		while(q)
		{
			if(q==head||q->next==NULL)
			{
				q->num=1;
			}
			else
			{
				q->num=p->num+p->next->num;
				p=p->next;
			}
			q=q->next;
		}
		p->next=head;
		i++;
	}
	return h;
}
void Print1(struct node *head)
{
	for(int i=0;head;i++,printf("\n"))
	{
		for(int j=0;j<=i;j++)
		{
			printf("%5d",head->num);
			head=head->next;
		}
	}
}
int main()
{
	struct node *head;
	head=Triangle(10);
	Print1(head);
}

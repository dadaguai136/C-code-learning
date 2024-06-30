#include<stdio.h>
#include"Linked_List.h"
struct node *Reverse()
{
	struct node *p,*p1;
	int x;
	p=p1=NULL;
	while(1)
	{
		scanf("%d",&x);
		if(x==-1)
		{
			break;
		}
		p1=(struct node *)malloc(sizeof(struct node));
		p1->num=x;
		p1->next=p;
		p=p1;
	}
	return p1;
}
int main()
{
	struct node *head;
	head=Reverse();
	Print(head);
}

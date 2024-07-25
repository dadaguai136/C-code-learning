#include<stdio.h>
#include"Linked_List.h"
struct node *Sort(struct node *head)
{
	struct node *h1,*h2,*p1,*p2;
	struct node *p;
	int m=head->num,s1=0,s2=0;
	if(head==NULL||head->next==NULL)
	{
		return head;
	}
	p=head->next;
	while(p)
	{
		if(p->num<m)
		{
			if(s1==0)
			{
				h1=p1=p;
			}
			else
			{
				p1=p1->next=p;
			}
			s1++;
		}
		else
		{
			if(s2==0)
			{
				h2=p2=p;
			}
			else
			{
				p2=p2->next=p;
			}
			s2++;
		}
		p=p->next;
	}
	p1->next=NULL;
	p2->next=NULL;
	Print(h1);
	printf("\n");
	Print(h2);
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Sort(head);
}

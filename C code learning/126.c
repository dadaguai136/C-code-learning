#include<stdio.h>
#include"Linked_List.h"
struct node *Remove(struct node *head)
{
	struct node *p,*h,*p1,*p2;
	int flag=0;
	for(p1=head;p1;p1=p1->next)
	{
		for(p2=head;p2!=p1;p2=p2->next)
		{
			if(p2->num==p1->num)
			{
				break;
			}
		}
		if(p1==p2)
		{
			if(flag==0)
			{
				h=p=p1;
			}
			else
			{
				p=p->next=p1;
			}
			flag++;
		}
	}
	p->next=NULL;
	return h;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	head=Remove(head);
	Print(head);
}

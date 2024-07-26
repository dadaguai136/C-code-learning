#include<stdio.h>
#include"Linked_List.h"
struct node *Traitor(struct node *head)
{
	struct node *p1,*p2;
	int flag=0;
	int n=10;
	p1=p2=head;
	while(n>1)
	{
		p2=p1;
		p1=p1->next;
		flag++;
		if(flag==2)
		{
			p2->next=p1->next;
			p1=p1->next;
			flag=0;
			n--;
		}
	}
	return p1;
}
int main()
{
	struct node *head,*end;
	head=end=Linked_List1();
	while(end->next)
	{
		end=end->next;
	}
	end->next=head;
	head=Traitor(head);
	head->next=NULL;
	Print(head);
}

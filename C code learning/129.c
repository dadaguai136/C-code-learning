#include<stdio.h>
#include"Linked_List.h"
int Length(struct node *head)
{
	if(head==NULL)
	{
		return 0;
	}
	return Length(head->next)+1;
}
int Length1(struct node *head)
{
	int s=0;
	if(head==NULL)
	{
		return 0;
	}
	while(head)
	{
		head=head->next;
		s++;
	}
	return s;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	printf("%d",Length1(head));
}

#include<stdio.h>
#include"Linked_List.h"
int Incremental_Increase(struct node *head)
{
	if(head==NULL)
	{
		return NULL;
	}
	while(head->next)
	{
		if(head->next->num<head->num)
		{
			return 0;
		}
		head=head->next;
	}
	return 1;
}
int Incremental_Increase1(struct node *head)
{
	int m;
	if(head==NULL)
	{
		return 0;
	}
	if(head->next==NULL)
	{
		return 1;
	}
	m=Incremental_Increase1(head->next);
	return m&&head->num<head->next->num;
}
int main()
{
	struct node *head;
	head=Linked_List1();
	printf("%d",Incremental_Increase1(head));
}

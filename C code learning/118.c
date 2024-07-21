#include<stdio.h>
#include"Linked_List.h"
struct node *Reverse(struct node *pre)
{
	struct node *cur;
	int m;
	scanf("%d",&m);
	if(m==-1)
	{
		return pre;
	}
	cur=(struct node *)malloc(sizeof(struct node));
	cur->num=m;
	cur->next=pre;
	return Reverse(cur);
}
struct node *Fun()
{
	return Reverse(NULL);
}
int main()
{
	struct node *head;
	head=Fun();
	Print(head);
}

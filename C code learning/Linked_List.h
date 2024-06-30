#include<malloc.h>
struct node
{
	int num;
	struct node *next;
};
void Print(struct node *head)
{
	while(head)
	{
		printf("%3d",head->num);
		head=head->next;
	}
}
struct node *Linked_List(int n)
{
	struct node *head;
	if(n<1)
	{
		return NULL;
	}
	head=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&head->num);
	head->next=Linked_List(n-1);
	return head;
}
struct node *Linked_List1()
{
	struct node *head;
	int num;
	scanf("%d",&num);
	if(num==-1)
	{
		return NULL;
	}	
	head=(struct node*)malloc(sizeof(struct node));
	head->num=num;
	head->next=Linked_List1();
	return head;
}

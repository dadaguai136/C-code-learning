#include<stdio.h>
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
	struct node *head,*p1,*p2;
	head=p1=p2=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&head->num);
	n--;
	while(n)
	{
		p2=p1;
		p1=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&p1->num);
		p2->next=p1;
		n--;
	}
	p1->next=NULL;
	return head;
}
struct node *Linked_List1(void)
{
	struct node *head=NULL,*p1,*p2;
	p1=p2=(struct node *)malloc(sizeof(struct node));
	int count=0;
	scanf("%d",&p1->num);
	while(p1->num!=-1)
	{
		count++;
		if(count==1)
		{
			p1->next=head;
			p2=p1;
			head=p1;
		}
		else
		{
			p1->next=NULL;
			p2->next=p1;
			p2=p1;
		}
		p1=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&p1->num);
	}
	free(p1);
	return head;
}
struct node *Linked_List2(int n)
{
	struct node *head;
	if(n<1)
	{
		return NULL;
	}
	head=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&head->num);
	head->next=Linked_List2(n-1);
	return head;
}
struct node *Linked_List3(void)
{
	struct node *head;
	int n;
	scanf("%d",&n);
	if(n==-1)
	{
		return NULL;
	}
	head=(struct node *)malloc(sizeof(struct node));
	head->num=n;
	head->next=Linked_List3();
	return head;
}
int main()
{
	struct node *head;
	head=Linked_List(3);
	Print(head);
}

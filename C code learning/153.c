#include<stdio.h>
#include<stdlib.h>
#include"Linked_List.h"
void Print1(struct node *head)
{
	for(int i=0;head;i++,printf("\n"))
	{
		for(int j=0;j<=i;j++)
		{
			printf("%3d",head->num);
			head=head->next;
		}
	}
}
struct node *Triangle(int n)
{
	struct node *h,*node,*k;
	int **a,**p,*q;
	h=NULL;
	a=(int **)malloc(sizeof(int *)*n);
	for(p=a;p<a+n;p++)
	{
		*p=(int *)malloc(sizeof(int)*(p-a+1));
	}
	for(p=a;p<a+n;p++)
	{
		for(q=*p;q<=*p+(p-a);q++)
		{
			if(q-*p==0||q-*p==p-a)
			{
				*q=1;
			}
			else
			{
				*q=*(*(p-1)+(q-*p))+*(*(p-1)+(q-*p-1));
			}
			node=(struct node *)malloc(sizeof(struct node));
			node->num=*q;
			if(h==NULL)
			{
				h=k=node;
			}
			else
			{
				k=k->next=node;
			}
		}
	}
	k->next=NULL;
	return h;
}
int main()
{
	int n;
	struct node *head;
	scanf("%d",&n);
	head=Triangle(n);
	Print1(head);
}

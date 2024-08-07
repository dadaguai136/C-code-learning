#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
};
struct node *Create()
{
	struct node *head;
	int x;
	scanf("%d",&x);
	if(x==-1)
	{
		return NULL;
	}
	head=(struct node *)malloc(sizeof(struct node));
	head->num=x;
	head->next=Create();
	return head;
}
void Print(struct node *head)
{
	while(head)
	{
		printf("%3d",head->num);
		head=head->next;
	}
}
void Write(struct node *head,FILE *fp)
{
	while(head)
	{
		fwrite(head,sizeof(struct node),1,fp);
		head=head->next;
	}
}
int Inspect(FILE *fp)
{
	long m,n;
	m=ftell(fp);
	fseek(fp,0,2);
	n=ftell(fp);
	fseek(fp,m,0);
	return m==n;
}
int Quantity(FILE *fp)
{
	struct node head;
	if(fp==NULL||Inspect(fp))
	{
		return 0;
	}
	fread(&head,sizeof(struct node),1,fp);
	return 1+Quantity(fp);
}
struct node *Read(FILE *fp)
{
	struct node *head=NULL;
	struct node *h,*p;
	int n;
	n=Quantity(fp);
	rewind(fp);
	for(int i=0;i<n;i++)
	{
		if(head==NULL)
		{
			head=h=(struct node *)malloc(sizeof(struct node));
			fread(head,sizeof(struct node),1,fp);
		}
		else
		{
			p=(struct node *)malloc(sizeof(struct node));
			fread(p,sizeof(struct node),1,fp);
			h=h->next=p;
		}
	}
	p->next=NULL;
	return head;
}
struct node *Read1(FILE *fp)
{
	struct node *head;
	if(fp==NULL||Inspect(fp))
	{
		return NULL;
	}
	head=(struct node*)malloc(sizeof(struct node));
	fread(head,sizeof(struct node),1,fp);
	head->next=Read1(fp);
	return head;
}
int main()
{
	struct node *head;
	FILE *fp;
	fp=fopen("E:\\abc.txt","rb+");
	//head=Create();
	//Write(head,fp);
	head=Read1(fp);
	Print(head);
	fclose(fp);
}

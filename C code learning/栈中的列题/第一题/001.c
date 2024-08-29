/*Problem Description
输入一个十进制数N，将它转换成R进制数输出。
 

Input
输入数据包含多个测试实例，每个测试实例包含两个整数N(32位整数)和R（2<=R<=16, R<>10）。
 

Output
为每个测试实例输出转换后的数，每个输出占一行。如果R大于10，则对应的数字规则参考16进制（比如，10用A表示，等等）。
 

Sample Input
7 2
23 12
-4 3
 

Sample Output
111
1B
-11*/
#include<stdio.h>
#include<stdlib.h>
#define eleType int
typedef struct Node
{
	eleType data;
	struct Node *next;
}Node;
typedef struct
{
	struct Node *head;
	size_t size;
}Stack;
void StackCreate(Stack *stk)
{
	stk->head=NULL;
	stk->size=0;
}
void StackDestroy(Stack *stk)
{
	while(stk->head)
	{
		Node *next=stk->head->next;
		free(stk->head);
		stk->head=next;
	}
	stk->size=0;
}
void StackPush(Stack *stk,eleType element)
{
	Node *newnode=(Node*)malloc(sizeof(Node));
	newnode->data=element;
	newnode->next=stk->head;
	stk->head=newnode;
	stk->size++;
}
eleType StackPop(Stack *stk)
{
	if(stk->size==0)
	{
		printf("Stack underflow!\n");
		exit(1);
	}
	eleType result=stk->head->data;
	Node *next=stk->head->next;
	free(stk->head);
	stk->head=next;
	stk->size--;
	return result;
}
eleType StackTop(Stack *stk)
{
	if(stk->size==0)
	{
		printf("Stack is empty!\n");
		exit(1);
	}
	return stk->head->data;
}
int StackSize(Stack *stk)
{
	return stk->size;
}
int main()
{
	int n,x;
	while(scanf("%d %d",&n,&x)!=EOF)
	{
		if(n==0)
		{
			printf("%d\n",0);
			continue;
		}
		if(n<0)
		{
			printf("-");
			n=-n;
		}
		Stack stk;
		StackCreate(&stk);
		while(n)
		{
			StackPush(&stk,n%x);
			n=n/x;
		}
		while(StackSize(&stk)>0)
		{
			int x=StackPop(&stk);
			if(x>10)
			{
				printf("%c",'A'+x-10);
			}
			else
			{
				printf("%d",x);
			}
		}
		printf("\n");
	}
}

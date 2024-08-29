/*Problem Description
Give you a number on base ten,you should output it on base two.(0 < n < 1000)
 

Input
For each case there is a postive number n on base ten, end of file.
 

Output
For each case output a number on base two.
 

Sample Input
1
2
3
 

Sample Output
1
10
11
 */
 #include<stdio.h>
 #include<stdlib.h>
 #define eleType int
 typedef struct 
 {
 	eleType *elements;
 	size_t size;
 	size_t capacity;
 }Stack;
 void StackCreate(Stack *stk)
 {
 	stk->elements=(eleType *)malloc(sizeof(eleType)*8);
 	stk->size=0;
 	stk->capacity=8;
 }
 void StackDestroy(Stack *stk)
 {
 	free(stk->elements);
 	stk->size=0;
 	stk->capacity=0;
 }
 void StackResize(Stack *stk)
 {
 	eleType *new_elements=(eleType *)realloc(stk->elements,sizeof(eleType)*stk->capacity*2);
 	stk->elements=new_elements;
 	stk->capacity*=2;
 }
 void StackPush(Stack *stk,eleType element)
 {
 	if(stk->size==stk->capacity)
 	{
 		StackResize(stk);
 	}
 	stk->elements[stk->size++]=element;
 }
 eleType StackPop(Stack *stk)
 {
 	if(stk->size==0)
 	{
 		printf("Stack underflow!\n");
 		exit(1);
 	}
 	return stk->elements[--stk->size];
 }
 eleType StackTop(Stack *stk)
 {
 	if(stk->size==0)
 	{
 		printf("Stack is empty!\n");
 		exit(1);
 	}
 	return stk->elements[stk->size-1];
 }
 int StackGetSize(Stack *stk)
 {
 	return stk->size;
 }
 int main()
 {
 	int n;
 	while(scanf("%d",&n)!=EOF)
 	{
 		Stack stk;
 		StackCreate(&stk);
 		while(n)
 		{
		 	StackPush(&stk,n%2);
		 	n=n/2;
		}
		while(StackGetSize(&stk)>0)
		{
			printf("%d",StackPop(&stk));
		}
		printf("\n");
	}
 }

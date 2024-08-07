#include<stdio.h>
#include<stdlib.h>
#define eleType int 
typedef struct
{
	eleType *elements;
	size_t front;
	size_t rear;
	size_t capacity;
}Queue;
void QueueCreate(Queue *q)
{
	q->elements=(eleType *)malloc(sizeof(eleType)*8);
	q->front=0;
	q->rear=0;
	q->capacity=8;
}
void QueueDestroy(Queue *q)
{
	free(q->elements);
	q->elements=NULL;
	q->front=0;
	q->rear=0;
	q->capacity=0;
}
void QueueResize(Queue *q)
{
	eleType *newElements=(eleType *)realloc(q->elements,sizeof(eleType)*q->capacity*2);
	if(newElements==NULL)
	{
		exit(1);
	}
	q->elements=newElements;
	q->capacity*=2;
}
void QueuePush(Queue *q,eleType element)
{
	if(q->rear==q->capacity)
	{
		QueueResize(q);
	}
	q->elements[q->rear++]=element;
}
eleType QueuePop(Queue *q)
{
	if(q->front==q->rear)
	{
		printf("Queue is empty!\n");
		exit(1);
	}
	return q->elements[q->front++];
}
eleType QueueFront(Queue *q)
{
	if(q->front==q->rear)
	{
		printf("Queue is empty!\n");
		exit(1);
	}
	return q->elements[q->front];
}
size_t QueueSize(Queue *q)
{
	return q->rear-q->front;
}
int main()
{
	Queue q;
	QueueCreate(&q);
	QueuePush(&q,10);
	QueuePush(&q,20);
	QueuePush(&q,30);
	printf("Queue Pop is %d\n",QueuePop(&q));
	printf("Queue Front is %d\n",QueueFront(&q));
	printf("Queue Size is %d\n",QueueSize(&q));
	QueueDestroy(&q);
}

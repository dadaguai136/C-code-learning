#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int *elements;
	size_t size;
	size_t capacity;
}SequentialList;
void SequentialListInit(SequentialList *list,int capacity)
{
	list->elements=(int *)malloc(sizeof(int)*capacity);
	list->size=0;
	list->capacity=capacity;
}
void SequentialListDestroy(SequentialList *list)
{
	if(list->elements)
	{
		free(list->elements);
		list->elements=NULL;
	}
}
size_t SequentialListSize(const SequentialList *list)
{
	return list->size;
}
void SequentialListInsert(SequentialList *list,int index,int element)
{
	if(index<0||index>list->size)
	{
		printf("Invalid index\n");
		return;
	}
	if(list->size==list->capacity)
	{
		int *newElements=(int *)realloc(list->elements,sizeof(int)*list->capacity*2);
		if(newElements==NULL)
		{
			printf("Failed to allocate memory\n");
		}
		list->elements=newElements;
		list->capacity*=2;
	}
	for(size_t i=list->size;i>index;i--)
	{
		list->elements[i]=list->elements[i-1];
	}
	list->elements[index]=element;
	list->size++;
}
void SequentialListDelete(SequentialList *list,int index)
{
	if(index<0||index>=list->size)
	{
		printf("Invalid index\n");
		return;
	}
	for(size_t i=index;i<list->size;i++)
	{
		list->elements[i]=list->elements[i+1];
	}
	list->size--;
}
size_t SequentialListFind(const SequentialList *list,int element)
{
	for(size_t i=0;i<list->size;i++)
	{
		if(list->elements[i]==element)
		{
			return i;
		}
	}
	return -1;
}
int SequentialListIndex(const SequentialList *list,int index)
{
	if(index<0||index>=list->size)
	{
		printf("Invalid index\n");
		return -1;
	}
	return list->elements[index];
}
void SequentialListSet(SequentialList *list,int index,int element)
{
	if(index<0||index>=list->size)
	{
		printf("Invalid index\n");
		return;
	}
	list->elements[index]=element;
}
int main()
{
	SequentialList list;
	SequentialListInit(&list,1);
	for(int i=0;i<10;i++)
	{
		SequentialListInsert(&list,i,i*10);
	}
	printf("Size: %d\n",SequentialListSize(&list));
	int elem=SequentialListIndex(&list,2);
	printf("%d %d\n",2,elem);
	int index=SequentialListFind(&list,15);
	printf("%d %d\n",index,15);
	SequentialListSet(&list,3,60);
	for(int i=0;i<SequentialListSize(&list);i++)
	{
		printf("%d %d\n",i,SequentialListIndex(&list,i));
	}
	SequentialListDestroy(&list);
}

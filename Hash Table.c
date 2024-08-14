#include<stdio.h>
#define maxHashSize 4
#define eleType int
#define empty -234123411
int HashArray[maxHashSize];
int HashFunc(eleType val)
{
	int x=val%maxHashSize;
	if(x<0)
	{
		x+=maxHashSize;
	}
	return x;
}
void HashInit()
{
	for(int i=0;i<maxHashSize;i++)
	{
		HashArray[i]=empty;
	}
}
int HashInsert(eleType val)
{
	int key=HashFunc(val);
	while(1)
	{
		if(HashArray[key]==empty)
		{
			HashArray[key]=val;
			return key;
		}
		else if(HashArray[key]==val)
		{
			return key;
		}
		key=key+1;
		if(key==maxHashSize)
		{
			key=0;
		}
	}
}
int HashDelete(eleType val)
{
	int key=HashFunc(val);
	while(1)
	{
		if(HashArray[key]==empty)
		{
			return 0;
		}
		else if(HashArray[key]==val)
		{
			HashArray[key]=empty;
			return 1;
		}
		key=key+1;
		if(key==maxHashSize)
		{
			key=0;
		}
	}
}
int HashFind(eleType val,int *isFind)
{
	int key=HashFunc(val);
	while(1)
	{
		if(HashArray[key]==empty)
		{
			*isFind=0;
			return key;
		}
		else if(HashArray[key]==val)
		{
			*isFind=1;
			return 1;
		}
		key=key+1;
		if(key==maxHashSize)
		{
			key=0;
		}
	}
}
int main()
{
	HashInit();
	int x1=HashInsert(23434);
	int x2=HashInsert(324324);
	int x3=HashInsert(43563453);
	int x4=HashInsert(-2323354);
	printf("%d %d %d %d\n",x1,x2,x3,x4);
	HashDelete(23434);
	HashInsert(23434);
	int isFind;
	HashFind(23434,&isFind);
	printf("%d\n",isFind);
	return 0;
}

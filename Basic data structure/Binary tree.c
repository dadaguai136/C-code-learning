#include<stdio.h>
#include<stdlib.h>
#define eleType char
typedef struct TreeNode
{
	eleType val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;
typedef struct Tree
{
	TreeNode *nodes;
	TreeNode *root;
	size_t nodeSize;
}Tree;
void TreeInit(Tree*t,int size)
{
	t->nodeSize=size;
	t->nodes=(TreeNode *)malloc(sizeof(TreeNode)*size);
	t->root=NULL;
}
void TreeDestroy(Tree *t)
{
	free(t->nodes);
	t->nodes=NULL;
	t->nodeSize=0;
	t->root=NULL;
}
TreeNode *TreeGetNode(Tree *t,int id)
{
	return &t->nodes[id];
}
void Visit(TreeNode *node)
{
	printf("%c",node->val);
}
TreeNode *CreateRecursively(Tree *t,eleType a[],int size,int nodeId,eleType nullNode)
{
	if(nodeId>=size||a[nodeId]==nullNode)
	{
		return NULL;
	}
	TreeNode *nowNode=TreeGetNode(t,nodeId);
	nowNode->val=a[nodeId];
	nowNode->left=CreateRecursively(t,a,size,nodeId*2,nullNode);
	nowNode->right=CreateRecursively(t,a,size,nodeId*2+1,nullNode);
	return nowNode;
}
void TreeCreate(Tree *t,eleType a[],int size,char nullNode)
{
	t->root=CreateRecursively(t,a,size,1,nullNode);
}
void PreOrder(Tree *t,TreeNode *node)
{
	if(node)
	{
		Visit(node);
		PreOrder(t,node->left);
		PreOrder(t,node->right);
	}
}
void TreePreOrderTraversal(Tree *t)
{
	PreOrder(t,t->root);
}
void InOrder(Tree *t,TreeNode *node)
{
	if(node)
	{
		InOrder(t,node->left);
		Visit(node);
		InOrder(t,node->right);
	}
}
void TreeInOrderTraversal(Tree *t)
{
	InOrder(t,t->root);
}
void PostOrder(Tree *t,TreeNode *node)
{
	if(node)
	{
		PostOrder(t,node->left);
		PostOrder(t,node->right);
		Visit(node);
	}
}
void TreePostOrderTraversal(Tree *t)
{
	PostOrder(t,t->root);
}
int main()
{
	const char nullNode='-';
	char a[15]={nullNode,'a','b','c','d',nullNode,'e','f','g','h',nullNode,nullNode,nullNode,nullNode,'i'};
	Tree T;
	TreeInit(&T,15);
	TreeCreate(&T,a,15,nullNode);
	TreePreOrderTraversal(&T);
	printf("\n");
	TreeInOrderTraversal(&T);
	printf("\n");
	TreePostOrderTraversal(&T);
	TreeDestroy(&T);
	return 0;
}

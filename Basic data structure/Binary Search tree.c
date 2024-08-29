#include<stdio.h>
#include<stdlib.h>
#define eleType int
#define bool int
typedef struct TreeNode
{
	eleType val;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode;
typedef struct BinarySearchTree
{
	TreeNode *root;
}BinarySearchTree;
void BSTCreate(BinarySearchTree *t)
{
	t->root=NULL;
}
void BSTRemove(BinarySearchTree *t,eleType value);
void BSTDestroy(BinarySearchTree *t)
{
	while(t->root)
	{
		BSTRemove(t,t->root->val);
	}
}
TreeNode *inserNode(BinarySearchTree *t,TreeNode *node,eleType value)
{
	if(node==NULL)
	{
		TreeNode *tn=(TreeNode *)malloc(sizeof(TreeNode));
		tn->val=value;
		tn->left=NULL;
		tn->right=NULL;
		return tn;
	}
	if(value<node->val)
	{
		node->left=inserNode(t,node->left,value);
	}
	else if(value>node->val)
	{
		node->right=inserNode(t,node->right,value);
	}
	return node;
}
void BSTInsert(BinarySearchTree *t,eleType value)
{
	t->root=inserNode(t,t->root,value);
}
TreeNode *removeNode(BinarySearchTree *t,TreeNode *node,eleType value)
{
	if(node==NULL)
	{
		return NULL;
	}
	if(value<node->val)
	{
		node->left=removeNode(t,node->left,value);
	}
	else if(value>node->val)
	{
		node->right=removeNode(t,node->right,value);
	}
	else
	{
		if(node->left==NULL&&node->right==NULL)
		{
			free(node);
			node=NULL;
			return NULL;
		}
		else if(node->left==NULL)
		{
			TreeNode *rightChild=node->right;
			free(node);
			node=rightChild;
			return node;
		}
		else if(node->right==NULL)
		{
			TreeNode *leftChild=node->left;
			free(node);
			node=leftChild;
			return node;
		}
		else
		{
			TreeNode *replacement=node->right;
			while(replacement->left)
			{
				replacement=replacement->left;
			}
			node->val=replacement->val;
			node->right=removeNode(t,node->right,replacement->val);
		}
	}
	return node;
}
void BSTRemove(BinarySearchTree *t,eleType value)
{
	t->root=removeNode(t,t->root,value);
}
bool searchNode(BinarySearchTree *t,TreeNode *node,eleType value)
{
	if(node==NULL)
	{
		return 0;
	}
	if(value<node->val)
	{
		return searchNode(t,node->left,value);
	}
	else if(value>node->val)
	{
		return searchNode(t,node->right,value);
	}
	return 1;
}
bool BSTSearch(BinarySearchTree *t,eleType value)
{
	return searchNode(t,t->root,value);
}
void inOrder(BinarySearchTree *t,TreeNode *node)
{
	if(node)
	{
		inOrder(t,node->left);
		printf("%d",node->val);
		inOrder(t,node->right);
	}
}
void BSTInOrderTraversal(BinarySearchTree *t)
{
	inOrder(t,t->root);
	printf("\n");
}
int main()
{
	BinarySearchTree bst;
	BSTCreate(&bst);
	BSTInsert(&bst,50);
	BSTInsert(&bst,30);
	BSTInsert(&bst,70);
	BSTInsert(&bst,40);
	BSTInsert(&bst,80);
	BSTInsert(&bst,100);
	BSTInOrderTraversal(&bst);
	printf("%d\n",BSTSearch(&bst,100));
	printf("%d\n",BSTSearch(&bst,110));
	BSTRemove(&bst,70);
	BSTInOrderTraversal(&bst);
	BSTInsert(&bst,50);
	BSTInOrderTraversal(&bst);
	return 0;
}

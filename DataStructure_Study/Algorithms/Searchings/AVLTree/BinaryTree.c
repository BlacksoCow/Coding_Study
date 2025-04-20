#include <stdlib.h>
#include "BinaryTree.h"
BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
Data GetData(BTreeNode* bt)
{
	return bt->data;
}
void SetData(BTreeNode* bt, Data data)
{
	bt->data = data;
	return;
}
BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}
void MakeLeftSubTree(BTreeNode* leaf, BTreeNode* sub)
{
	if(leaf->left != NULL)
		DestroyTree(leaf->left);
	leaf->left = sub;
	return;
}
void MakeRightSubTree(BTreeNode* leaf, BTreeNode* sub)
{
	if(leaf->right != NULL)
		DestroyTree(leaf->right);
	leaf->right = sub;
	return;
}
void ChangeLeftSubTree(BTreeNode* bt1, BTreeNode* bt2)
{
	bt1->left = bt2;
	return;
}
void ChangeRightSubTree(BTreeNode* bt1, BTreeNode* bt2)
{
	bt1->right = bt2;
	return;
}
BTreeNode* RemoveLeftSubTree(BTreeNode* bt)
{
	BTreeNode* rnode = bt->left;
	bt->left = NULL;
	return rnode;
}
BTreeNode* RemoveRightSubTree(BTreeNode* bt)
{
	BTreeNode* rnode = bt->right;
	bt->right = NULL;
	return rnode;
}
void InOrderTraverse(BTreeNode* bt, Action action)
{
	if(bt == NULL)
		return;
	InOrderTraverse(bt->left, action);
	action(bt);
	InOrderTraverse(bt->right, action);
	return;
}
void PreOrderTraverse(BTreeNode* bt, Action action)
{
	if(bt == NULL)
		return;
	action(bt);
	PreOrderTraverse(bt->left, action);
	PreOrderTraverse(bt->right, action);
	return;
}
void PostOrderTraverse(BTreeNode* bt, Action action)
{
	if(bt == NULL)
		return;
	PostOrderTraverse(bt->left, action);
	PostOrderTraverse(bt->right, action);
	action(bt);
	return;
}
void DestroyTree(BTreeNode* bt)
{
	if(bt == NULL)
		return;
	DestroyTree(bt->left);
	DestroyTree(bt->right);
	free(bt);
	return;
}
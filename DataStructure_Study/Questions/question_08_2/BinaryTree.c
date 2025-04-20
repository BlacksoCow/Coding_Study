#include <stdlib.h>
#include "BinaryTree.h"
BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
TData GetData(BTreeNode* bt)
{
	return bt->data;
}
void SetData(BTreeNode* bt, TData data)
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
void DestroyTree(BTreeNode* bt)
{
	if(bt == NULL)
		return;
	DestroyTree(bt->left);
	DestroyTree(bt->right);
	free(bt);
	return;
}
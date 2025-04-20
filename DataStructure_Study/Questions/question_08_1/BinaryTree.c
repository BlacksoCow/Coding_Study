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
void MakeLeftSubTree(BTreeNode* bt, BTreeNode* sub)
{
	if(bt->left != NULL)
		DeleteTree(bt->left);
	bt->left = sub;
	return;
}
void MakeRightSubTree(BTreeNode* bt, BTreeNode* sub)
{
	if(bt->right != NULL)
		DeleteTree(bt->right);
	bt->right = sub;
	return;
}
void DeleteTree(BTreeNode* bt)
{
	if(bt == NULL)
		return;
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	free(bt);
	return;
}
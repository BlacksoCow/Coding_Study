#include <stdio.h>
#include "BinaryTreeTraverse.h"
void InOrder(BTreeNode* bt, Action action)
{
	if(bt == NULL)
		return;
	InOrder(bt->left, action);
	action(bt);
	InOrder(bt->right, action);
	return;
}
void PreOrder(BTreeNode* bt, Action action)
{
	if(bt == NULL)
		return;
	action(bt);
	PreOrder(bt->left, action);
	PreOrder(bt->right, action);
	return;
}
void PostOrder(BTreeNode* bt, Action action)
{
	if(bt == NULL)
		return;
	PostOrder(bt->left, action);
	PostOrder(bt->right, action);
	action(bt);
	return;
}
void TraverseAction(BTreeNode* bt, TraverseFunc tf, Action action)
{
	tf(bt, action);
	return;
}
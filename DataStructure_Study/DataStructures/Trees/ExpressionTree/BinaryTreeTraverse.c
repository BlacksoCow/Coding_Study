#include <stdio.h>
#include "BinaryTreeTraverse.h"
void InOrder(BTreeNode* bt, Action action)
{
	if(bt == NULL)
		return;
	InOrder(GetLeftSubTree(bt), action);
	action(bt);
	InOrder(GetRightSubTree(bt), action);
	return;
}
void PreOrder(BTreeNode* bt, Action action)
{
	if(bt == NULL)
		return;
	action(bt);
	PreOrder(GetLeftSubTree(bt), action);
	PreOrder(GetRightSubTree(bt), action);
	return;
}
void PostOrder(BTreeNode* bt, Action action)
{
	if(bt == NULL)
		return;
	PostOrder(GetLeftSubTree(bt), action);
	PostOrder(GetRightSubTree(bt), action);
	action(bt);
	return;
}
void TraverseAction(BTreeNode* bt, TraverseFunc tf, Action action)
{
	tf(bt, action);
	return;
}
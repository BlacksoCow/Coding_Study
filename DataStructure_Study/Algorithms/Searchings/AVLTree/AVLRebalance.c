#include <stdio.h>
#include "AVLRebalance.h"
int GetHeight(BTreeNode* bt)
{
	if(bt == NULL)
		return 0;
	int left = GetHeight(GetLeftSubTree(bt));
	int right = GetHeight(GetRightSubTree(bt));
	return left > right ? (left + 1) : (right + 1);
}
int GetHeightDiff(BTreeNode* bt)
{
	int left = GetHeight(GetLeftSubTree(bt));
	int right = GetHeight(GetRightSubTree(bt));
	return left - right;
}
BTreeNode* RotateLL(BTreeNode* bt)
{
	BTreeNode* pnode = bt;
	BTreeNode* cnode = GetLeftSubTree(pnode);
	ChangeLeftSubTree(pnode, GetRightSubTree(cnode));
	ChangeRightSubTree(cnode, pnode);
	return cnode; // Returning the new root node
}
BTreeNode* RotateRR(BTreeNode* bt)
{
	BTreeNode* pnode = bt;
	BTreeNode* cnode = GetRightSubTree(pnode);
	ChangeRightSubTree(pnode, GetLeftSubTree(cnode));
	ChangeLeftSubTree(cnode, pnode);
	return cnode; // Returning the new root node
}
BTreeNode* RotateLR(BTreeNode* bt)
{
	BTreeNode* pnode = bt;
	BTreeNode* cnode = GetLeftSubTree(pnode);
	ChangeLeftSubTree(pnode, RotateRR(cnode));
	return RotateLL(pnode); // Returning the new root node
}
BTreeNode* RotateRL(BTreeNode* bt)
{
	BTreeNode* pnode = bt;
	BTreeNode* cnode = GetRightSubTree(pnode);
	ChangeRightSubTree(pnode, RotateLL(cnode));
	return RotateRR(pnode); // Returning the new root node
}
BTreeNode* Rebalance(BTreeNode* bt)
{
	if(bt == NULL)
		return NULL;
	BTreeNode* pNode = bt;
	int diff = GetHeightDiff(bt);
	if(diff >= 2)
	{ // Cases of LL and LR situation
		if(GetHeightDiff(GetLeftSubTree(pNode)) >= 0)
			return RotateLL(pNode); // LLrotation when subtree's diff is 0
		else if(GetHeightDiff(GetLeftSubTree(pNode)) < 0)
			return RotateLR(pNode);
	}
	else if(diff <= -2)
	{ // Cases of RR and RL situation
		if(GetHeightDiff(GetRightSubTree(pNode)) <= 0)
			return RotateRR(pNode); // RRrotation when subtree's diff is 0
		else if(GetHeightDiff(GetRightSubTree(pNode)) > 0)
			return RotateRL(pNode);
	}
	return pNode;
}
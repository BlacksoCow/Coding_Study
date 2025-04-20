#include <stdio.h>
#include <stdlib.h>
#include "AVLRebalance(old).h"
int GetHeight(BTreeNode* bt)
{
	if(bt == NULL)
		return 0;
	int LHeight = GetHeight(GetLeftSubTree(bt)) + 1;
	int RHeight = GetHeight(GetRightSubTree(bt)) + 1;
	return LHeight > RHeight ? LHeight : RHeight;
}
int GetHeightDiff(BTreeNode* bt)
{
	int left = GetHeight(GetLeftSubTree(bt));
	int right = GetHeight(GetRightSubTree(bt));
	return left - right;
}
void RotateLL(BTreeNode** pRoot)
{
	BTreeNode* pnode = *pRoot;
	BTreeNode* cnode = GetLeftSubTree(pnode);
	ChangeLeftSubTree(pnode, GetRightSubTree(cnode));
	ChangeRightSubTree(cnode, pnode);
	*pRoot = cnode; // Changing leaf node to cnode
	return;
}
void RotateRR(BTreeNode** pRoot)
{
	BTreeNode* pnode = *pRoot;
	BTreeNode* cnode = GetRightSubTree(pnode);
	ChangeRightSubTree(pnode, GetLeftSubTree(cnode));
	ChangeLeftSubTree(cnode, pnode);
	*pRoot = cnode; // Changing leaf node to cnode
	return;
}
void RotateLR(BTreeNode** pRoot)
{
	BTreeNode* pnode = *pRoot;
	BTreeNode* cnode = GetLeftSubTree(pnode);
	RotateRR(&cnode);
	ChangeLeftSubTree(pnode, cnode);
	RotateLL(&pnode);
	*pRoot = pnode;
	return;
}
void RotateRL(BTreeNode** pRoot)
{
	BTreeNode* pnode = *pRoot;
	BTreeNode* cnode = GetRightSubTree(pnode);
	RotateLL(&cnode);
	ChangeRightSubTree(pnode, cnode);
	RotateRR(&pnode);
	*pRoot = pnode;
	return;
}
void Rebalance(BTreeNode** pRoot)
{
	BTreeNode* pnode = *pRoot;
	int diff= GetHeightDiff(pnode);
	if(diff >= 2)
	{
		if(GetHeightDiff(GetLeftSubTree(pnode)) > 0)
			RotateLL(&pnode);
		else if(GetHeightDiff(GetLeftSubTree(pnode)) < 0)
			RotateLR(&pnode);
		else
		{
			puts("Severe error in tree");
			exit(-1);
		}
	}
	if(diff <= -2)
	{
		if(GetHeightDiff(GetRightSubTree(pnode)) < 0)
			RotateRR(&pnode);
		else if(GetHeightDiff(GetLeftSubTree(pnode)) > 0)
			RotateRL(&pnode);
		else
		{
			puts("Severe error in tree");
			exit(-1);
		}
	}
	*pRoot = pnode; // Synchronizing root node
	return;
}
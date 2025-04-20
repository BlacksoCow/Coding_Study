#ifndef __AVLREBALANCE_H__
#define __AVLREBALANCE_H__

#include "BinaryTree.h"

int GetHeight(BTreeNode* bt);
int GetHeightDiff(BTreeNode* bt);

BTreeNode* RotateLL(BTreeNode* bt);
BTreeNode* RotateRR(BTreeNode* bt);
BTreeNode* RotateLR(BTreeNode* bt);
BTreeNode* RotateRL(BTreeNode* bt);

BTreeNode* Rebalance(BTreeNode* bt);

#endif
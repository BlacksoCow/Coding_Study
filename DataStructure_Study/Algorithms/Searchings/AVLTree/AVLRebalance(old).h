#ifndef __AVLREBALANCE_H__
#define __AVLREBALANCE_H__

#include "BinaryTree.h"

int GetHeight(BTreeNode* bt);
int GetHeightDiff(BTreeNode* bt);

void RotateLL(BTreeNode** pRoot);
void RotateRR(BTreeNode** pRoot);
void RotateLR(BTreeNode** pRoot);
void RotateRL(BTreeNode** pRoot);

void Rebalance(BTreeNode** pRoot);

#endif
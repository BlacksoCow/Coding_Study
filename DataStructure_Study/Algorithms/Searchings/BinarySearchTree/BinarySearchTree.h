#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#include "BinaryTree.h"

typedef Data BSTData;

void BSTInit(BTreeNode** bt);
BSTData GetBSData(BTreeNode* bt);
BTreeNode* BSTSearch(BTreeNode* bt, BSTData data);
void BSTInsert(BTreeNode** bt, BSTData data);
BTreeNode* BSTRemove(BTreeNode** bt, BSTData data);
void BSTDestroy(BTreeNode* bt);

#endif
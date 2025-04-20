#ifndef __BINARYTREETRAVERSE_H__
#define __BINARYTREETRAVERSE_H__

#include "BinaryTree.h"

typedef void (*Action)(BTreeNode*);
typedef void (*TraverseFunc)(BTreeNode*, Action action);

void InOrder(BTreeNode* bt, Action action);
void PreOrder(BTreeNode* bt, Action action);
void PostOrder(BTreeNode* bt, Action action);
void TraverseAction(BTreeNode* bt, TraverseFunc tf, Action action);

#endif
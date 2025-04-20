#ifndef __EXPRESSIONTREE_H__
#define __EXPRESSIONTREE_H__

#include "BinaryTree.h"
#include "BinaryTreeTraverse.h"

BTreeNode* MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode* bt);
void ShowPrefixExp(BTreeNode* bt);
void ShowInfixExp(BTreeNode* bt);
void ShowPostfixExp(BTreeNode* bt);

#endif
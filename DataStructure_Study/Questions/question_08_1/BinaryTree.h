#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

typedef int Data;

typedef struct __treenode
{
	Data data;
	struct __treenode* left;
	struct __treenode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
Data GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, Data data);
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);
void MakeLeftSubTree(BTreeNode* leaf, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* leaf, BTreeNode* sub);
void DeleteTree(BTreeNode* bt);

#endif
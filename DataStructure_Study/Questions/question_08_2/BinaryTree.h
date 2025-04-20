#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

typedef int TData;

typedef struct __treenode
{
	TData data;
	struct __treenode* left;
	struct __treenode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
TData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, TData data);
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);
void MakeLeftSubTree(BTreeNode* leaf, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* leaf, BTreeNode* sub);
void DestroyTree(BTreeNode* bt);

#endif
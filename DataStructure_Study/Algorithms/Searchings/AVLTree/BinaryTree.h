#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

typedef int Data;

typedef struct __treenode
{
	Data data;
	struct __treenode* left;
	struct __treenode* right;
} BTreeNode;

typedef void (*Action)(BTreeNode*); // Action function for traverse

BTreeNode* MakeBTreeNode(void);

Data GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, Data data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* leaf, BTreeNode* sub); // Destroys every link
void MakeRightSubTree(BTreeNode* leaf, BTreeNode* sub);
void ChangeLeftSubTree(BTreeNode* bt1, BTreeNode* bt2); // Change bt1 left subtree to bt2
void ChangeRightSubTree(BTreeNode* bt1, BTreeNode* bt2);
BTreeNode* RemoveLeftSubTree(BTreeNode* bt); // Removes subtree without freeing
BTreeNode* RemoveRightSubTree(BTreeNode* bt); // and returns the removed tree's leaf

void InOrderTraverse(BTreeNode* bt, Action action);
void PreOrderTraverse(BTreeNode* bt, Action action);
void PostOrderTraverse(BTreeNode* bt, Action action);

void DestroyTree(BTreeNode* bt); // Destroys every node

#endif
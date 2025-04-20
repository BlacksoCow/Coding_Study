#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
void BSTInit(BTreeNode** bt)
{
	*bt = NULL;
	return;
}
BSTData GetBSData(BTreeNode* bt)
{
	return GetData(bt);
}
BTreeNode* BSTSearch(BTreeNode* bt, BSTData data)
{
	BTreeNode* cnode = bt;
	while(cnode != NULL)
	{
		if(data == GetData(cnode))
			return cnode;
		else if(data < GetData(cnode))
			cnode = GetLeftSubTree(cnode);
		else
			cnode = GetRightSubTree(cnode);
	}
	return NULL;
}
BTreeNode* BSTInsert(BTreeNode** bt, BSTData data)
{ // Returns the rebalanced root node after data is inserted
	if(*bt == NULL)
	{ // When inserting position is found
		*bt = MakeBTreeNode();
		SetData(*bt, data); // Initializing newNode
	}
	else if(data < GetData(*bt))
	{
		ChangeLeftSubTree(*bt, BSTInsert(&((*bt)->left), data));
		*bt = Rebalance(*bt);
	}
	else if(data > GetData(*bt))
	{
		ChangeRightSubTree(*bt, BSTInsert(&((*bt)->right), data));
		*bt = Rebalance(*bt);
	}
	return *bt; // Returns *bt when data already exists
}
BTreeNode* BSTRemove(BTreeNode** bt, BSTData target)
{ // Returns the rebalanced root node after target is removed
	if(*bt == NULL || BSTSearch(*bt, target) == NULL)
		return NULL; // When tree is empty or target doesn't exist
	if(target < GetData(*bt))
	{
		ChangeLeftSubTree(*bt, BSTRemove(&((*bt)->left), target));
		*bt = Rebalance(*bt);
	}
	else if(target > GetData(*bt))
	{
		ChangeRightSubTree(*bt, BSTRemove(&((*bt)->right), target));
		*bt = Rebalance(*bt);
	}
	else
	{ // When target matches the *bt's data
		BTreeNode* rnode;
		if(GetLeftSubTree(*bt) == NULL || GetRightSubTree(*bt) == NULL)
		{ // When target has one or no child node
			rnode = *bt; // Setting *bt to the node to get linked with parent node
			*bt = (GetLeftSubTree(*bt) ? GetLeftSubTree(*bt) : GetRightSubTree(*bt));
		}
		else
		{ // When target has two child nodes
			rnode = GetLeftSubTree(*bt);
			while(GetRightSubTree(rnode) != NULL)
				rnode = GetRightSubTree(rnode); // rnode has max value in left subtree
			SetData(*bt, GetData(rnode)); // Setting target's data to rnode's data
			ChangeLeftSubTree(*bt, BSTRemove(&((*bt)->left), GetData(rnode)));
		}
		*bt = Rebalance(*bt);
		free(rnode);
		return *bt;
	}
}
void BSTDestroy(BTreeNode* bt)
{
	DestroyTree(bt);
	return;
}
/*BTreeNode* BSToldRemove(BTreeNode** bt, BSTData target)
{
	BTreeNode* dummy = MakeBTreeNode();
	BTreeNode* pnode = dummy;
	BTreeNode* cnode = *bt;
	ChangeLeftSubTree(dummy, cnode); // Linking dummy node with cnode for corner case
	while(cnode != NULL && target != GetData(cnode))
	{ // Searching target to remove
		pnode = cnode;
		if(target < GetData(cnode))
			cnode = GetLeftSubTree(cnode);
		else if(target > GetData(cnode))
			cnode = GetRightSubTree(cnode);
		else
		{
			puts("Error in removing");
			exit(-1);
		}
	}
	if(cnode == NULL)
		return NULL; // Searching failed or tree is empty
	BTreeNode* dnode = cnode; // Node to actually delete
	if(GetLeftSubTree(dnode) == NULL && GetRightSubTree(dnode) == NULL)
	{ // When dnode has no child nodes
		if(dnode == GetLeftSubTree(pnode))
			ChangeLeftSubTree(pnode, NULL); // Removing left child node
		else if(dnode == GetRightSubTree(pnode))
			ChangeRightSubTree(pnode, NULL); // Removing right child node
		else
		{
			puts("Error in removing"); 
			exit(-1);
		}
	}
	else if(GetLeftSubTree(dnode) == NULL || GetRightSubTree(dnode) == NULL)
	{ // When dnode has one child node
		BTreeNode* dcnode;
		if(GetLeftSubTree(dnode) != NULL)
			dcnode = GetLeftSubTree(dnode);
		else if(GetRightSubTree(dnode) != NULL)
			dcnode = GetRightSubTree(dnode);
		else
		{
			puts("Error in removing");
			exit(-1);
		} // Initializing dcnode(child node of dnode)
		if(dnode == GetLeftSubTree(pnode))
			ChangeLeftSubTree(pnode, dcnode);
		else if(dnode == GetRightSubTree(pnode))
			ChangeRightSubTree(pnode, dcnode);
		else
		{
			puts("Error in removing");
			exit(-1);
		} // Removing dnode's link from tree
	}
	else if(GetLeftSubTree(dnode) != NULL && GetRightSubTree(dnode) != NULL)
	{ // When dnode has two child nodes
		BTreeNode* mpnode = dnode;
		BTreeNode* mnode = GetLeftSubTree(dnode);
		while(GetRightSubTree(mnode) != NULL)
		{
			mpnode = mnode;
			mnode = GetRightSubTree(mnode);
		} // Initializing mnode and mpnode(parent node of mnode)
		BSTData rdata = GetData(dnode); // Saving dnode's data
		SetData(dnode, GetData(mnode));
		if(mnode == GetLeftSubTree(mpnode)) // Only when mpnode is dnode
			ChangeLeftSubTree(mpnode, GetLeftSubTree(mnode));
		else if(mnode == GetRightSubTree(mpnode)) // Most of the cases
			ChangeRightSubTree(mpnode, GetLeftSubTree(mnode));
		else
		{ // Cannot occur unless tree ahs more than two branches
			puts("Severe problem in tree itself");
			exit(-1);
		}
		dnode = mnode;
		SetData(dnode, rdata);
	}
	else
	{ // Cannot occur unless tree has more than two branches
		puts("Error in tree itself");
		exit(-1);
	}
	if(*bt != GetLeftSubTree(dummy))
		*bt = GetLeftSubTree(dummy); // Corner case when dnode is first leaf node
	free(dummy);
	*bt = Rebalance(*bt);
	return dnode;
}*/
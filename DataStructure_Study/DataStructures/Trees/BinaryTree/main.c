#include <stdio.h>
#include "BinaryTree.h"
void ShowData(BTreeNode* bt)
{
	printf("%d\n", GetData(bt));
	return;
}
void ShowPlusOne(BTreeNode* bt)
{
	printf("%d\n", GetData(bt) + 1);
	return;
}
int main(int argc, char** argv)
{
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();
	BTreeNode* bt4 = MakeBTreeNode();
	BTreeNode* bt5 = MakeBTreeNode();
	BTreeNode* bt6 = MakeBTreeNode();
	
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);
	
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);
	
	InOrderTraverse(bt1, ShowData);
	printf("--------------\n");
	PreOrderTraverse(bt1, ShowPlusOne);
	printf("--------------\n");
	PostOrderTraverse(bt1, ShowData);
	printf("--------------\n");
	
	DestroyTree(bt1);
	InOrderTraverse(bt1, ShowData);
	return 0;
}
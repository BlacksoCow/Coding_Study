#include <stdio.h>
#include "BinarySearchTree.h"
void ShowData(BTreeNode* bt)
{
	printf("%d ", GetData(bt));
	return;
}
void ShowTree(BTreeNode* bt)
{
	PreOrderTraverse(bt, ShowData);
	printf("\n\n");
	return;
}
int main(int argc, char** argv)
{
	BTreeNode* avlRoot;
	BSTInit(&avlRoot);
	for(int i = 9; i >= 1; i--)
		BSTInsert(&avlRoot, i);
	PreOrderTraverse(avlRoot, ShowData);
	putchar('\n');
	puts("------------------------------");
	BSTRemove(&avlRoot, 5);
	ShowTree(avlRoot);
	
	BSTRemove(&avlRoot, 5);
	ShowTree(avlRoot); // Should show the same result
	
	BSTRemove(&avlRoot, 3);
	ShowTree(avlRoot);
	
	BSTInsert(&avlRoot, 15);
	ShowTree(avlRoot);
	
	BSTInsert(&avlRoot, 17);
	ShowTree(avlRoot);
	
	BSTRemove(&avlRoot, 7);
	ShowTree(avlRoot);
	
	BSTRemove(&avlRoot, 6);
	ShowTree(avlRoot);
	
	BSTRemove(&avlRoot, 17);
	ShowTree(avlRoot);
	
	BSTRemove(&avlRoot, 9);
	ShowTree(avlRoot);
	
	BSTRemove(&avlRoot, 8);
	ShowTree(avlRoot);
	
	BSTRemove(&avlRoot, 15);
	ShowTree(avlRoot);
	
	BSTRemove(&avlRoot, 3);
	ShowTree(avlRoot); // Nothing should happen
	return 0;
}
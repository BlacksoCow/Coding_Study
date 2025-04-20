#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"
void ShowData(BTreeNode* bt)
{
	printf("%d ", GetData(bt));
	return;
}
int main(int argc, char** argv)
{
	BTreeNode* bstRoot;
	BTreeNode* snode;
	BSTInit(&bstRoot);
	BSTInsert(&bstRoot, 5);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 4);
	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 7);
	
	InOrderTraverse(bstRoot, ShowData);
	putchar('\n');
	
	snode = BSTRemove(&bstRoot, 3);
	InOrderTraverse(bstRoot, ShowData);
	putchar('\n');
	free(snode);
	
	snode = BSTRemove(&bstRoot, 8);
	InOrderTraverse(bstRoot, ShowData);
	putchar('\n');
	free(snode);
	
	snode = BSTRemove(&bstRoot, 1);
	InOrderTraverse(bstRoot, ShowData);
	putchar('\n');
	free(snode);
	
	snode = BSTRemove(&bstRoot, 6);
	InOrderTraverse(bstRoot, ShowData);
	putchar('\n');
	free(snode);
	
	snode = BSTRemove(&bstRoot, 2);
	InOrderTraverse(bstRoot, ShowData);
	putchar('\n');
	free(snode);
	
	snode = BSTRemove(&bstRoot, 10);
	InOrderTraverse(bstRoot, ShowData);
	putchar('\n'); // Not in BSTree
	free(snode);
	
	snode = BSTRemove(&bstRoot, 5);
	InOrderTraverse(bstRoot, ShowData);
	putchar('\n');
	free(snode);
	
	snode = BSTRemove(&bstRoot, 7);
	InOrderTraverse(bstRoot, ShowData);
	putchar('\n');
	free(snode);
	
	snode = BSTRemove(&bstRoot, 4);
	InOrderTraverse(bstRoot, ShowData);
	putchar('\n');
	free(snode);
	
	snode = BSTRemove(&bstRoot, 9);
	InOrderTraverse(bstRoot, ShowData);
	putchar('\n');
	free(snode);
	
	BSTDestroy(bstRoot);
	return 0;
}